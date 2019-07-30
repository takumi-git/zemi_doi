#include <stdio.h>
#include<stdlib.h>
#include<math.h>

typedef struct cell{
  double data;
  int value;
  struct cell *next;
} cell;

cell *alloc_list(double data);
int add_list(double data, cell *head);
void show_list(cell *p);
void free_list(cell *p);
void sum_list(cell *p);


cell *alloc_list(double data)
{
  cell *new = NULL;
  new = (cell *)malloc(sizeof(cell));
  if(new==NULL)
    puts("malloc error\n");
  return NULL;
  new->next = NULL;
  new->data = data;

  return new;
}

int add_list(double data, cell *head)
{
  cell *next =NULL;
  cell *prev = head;

  next = alloc_list(data);
  if(next==NULL)
    return -1;
  while(prev->next!=NULL)//一番最後のリストまで移動
    prev = prev->next;
  prev->next = next;
  return 0;
}

void show_list(cell *p)
{
  while(p !=NULL)
  {
    printf("pの中身を表示\n");
    printf("%f\n", p->data);
    p = p->next;
  }
}

void sum_list(cell *p)
{
  double sum = 0;
  while(p != NULL)
  {
    sum +=p->data;
    p = p->next;
  }
  puts("sum_listを表示\n");
  printf("%lf\n", sum);
}

void free_list(cell *p)
{
  cell *p2;
  while(p != NULL)
  {
    p2 = p->next;
    free(p);
    p = p2;
  }
}

void bubble_sort(cell *p)
{
  cell *head; //headをさすポインタ
  cell *back; //back(配列の最後を指す)ポインタ
  double temp = 0;
  int i, j, k;        //ループカウンタ
  int data_count = 0; //配列の中身のカウント0番目から〜

  head = p; //headにlistポインタpを代入
  //データ数をカウント
  while (p != NULL)
  {
    data_count++;
    p = p->next;
  }
  for (i = 0; i < data_count - 1; i++)
  { //データカウント数-1までiを増加
    for (j = data_count - 1; j > i; j--)
    { //データカウント数-1からiよりiまでjを減少
      p = head;
      for (k = 0, p = head; k < j - 1; k++)
      {
        p = p->next;
      }
      back = p;
      p = p->next;

      if (fabs(p->data) < fabs(back->data))
      {
        temp = p->data;
        p->data = back->data;
        back->data = temp;
      }
    }
  }
}

/* void insert_list(cell **pointer, int new_value)
{
  cell *new_list = NULL;
  new_list = (cell *)malloc(sizeof(cell));
  new_list->value = new_value;
  new_list->next = *pointer;
  *pointer = new_list;
}*/

int main(void)
{
 double data;
 FILE *fp;
 char *fname = "data.txt";
  cell *head,**p; //リストのhead(先頭)の作成

 head = alloc_list(0);
 fp = fopen(fname, "r");
 if (fp == NULL)
 {
  printf("Not found such a file\n");
  return -1;
 }
 while (fscanf(fp,"%lf",&data) !=EOF)//ファイル最後まで数値の読み込み
 {
   data = data;
   add_list(data, head);
   //insert_list(p, data);
   //p = &((*p)->next);
 }
 
 bubble_sort(head);
 show_list(head);
 sum_list(head);
 free_list(head);
 return 0;
}
