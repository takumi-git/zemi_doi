#include <stdio.h>

/* 値を入れ替える関数 */
void swap(int *x, int *y)
{
  int temp; // 値を一時保存する変数

  temp = *x;
  *x = *y;
  *y = temp;
}

/***
* pivotを決め、
* 全データをpivotを境目に振り分け、
* pivotの添え字を返す
***/
int partition(int array[], int left, int right)
{
  int i, j, pivot;
  i = left;
  j = right + 1;
  pivot = left; // 先頭要素をpivotとする

  do
  {
    do
    {
      i++;
    } while (array[i] < array[pivot]);
    do
    {
      j--;
    } while (array[pivot] < array[j]);
    // pivotより小さいものを左へ、大きいものを右へ
    if (i < j)
    {
      swap(&array[i], &array[j]);
    }
  } while (i < j);

  swap(&array[pivot], &array[j]); //pivotを更新

  return j;
}

/* クイックソート */
void quick_sort(int array[], int left, int right)
{
  int pivot;

  if (left < right)
  {
    pivot = partition(array, left, right);//配列の右左の区切り
    quick_sort(array, left, pivot - 1); // pivotを境に再帰的にクイックソート
    quick_sort(array, pivot + 1, right);
  }
}

int main(void)
{
  int array[10] = {6, 9, 12, 7, 15, 23, 2, 10, 4, 20};//1つ目の配列
  //int array[20] = {34, 64, 94, 73, 16, 33, 31, 68, 75, 89, 1, 78, 87, 76, 87, 59, 6, 5, 75, 65} 2つ目の配列
  int i;

  printf("Before sort: ");
  for (i = 0; i < 10; i++) //for(i =0;i<20; i++)
  {
    printf("%d ", array[i]);
  }
  printf("\n");

  quick_sort(array, 0, 9); //quick_sort(array,0,19);

  printf("After sort: ");
  for (i = 0; i < 10; i++) //for(i = 0;i<20;i++)
  {
    printf("%d ", array[i]);
  }
  printf("\n");

  return 0;
}