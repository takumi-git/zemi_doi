#include <stdio.h>

#define N 10 // 配列の要素を定義 単純選択法の処理時にも適用される

static int a[N] = {6, 9, 12, 7, 15, 23, 2, 10, 4, 20};

int main()
{
    int i, j;//forループカウンター
    int k;//最小値の要素番号
    int temp;//数値入れ替え用
    //変換の配列の表示
    for (i = 0; i < N;i ++)
        printf("%3d", a[i]);
    printf("\n");
    //単純選択法
    for (i = 0; i < N - 1; i++)
    {
                   k = i;
                   for (j = i + 1; j < N; j++){
                                  if (a[k]>a[j])
                                             k = j;
                   }
                   temp = a[i];
                   a[i] = a[k];
                   a[k] = temp;
                   for (j = 0; j < N; j++)
                                  printf("%3d", a[j]);
                   printf("\n");
    }
    return 0;
}