#include<stdio.h>
#include <stdlib.h>
#include<math.h>

struct list{
 double data;
 struct list *next;
};

struct list *alloc_list(double data);
int add_list(double data, struct list *head);
void show_list(struct list *p);
void free_list(struct list *p);
void sum_list(struct list *p);

int main(void)
{
 double data;
 FILE *fp;
 char *fname = "data.txt";
 struct list *head; //リストのhead(先頭)の作成

 head = alloc_list(0);
 fp = fopen(fname, "r");
 
 if (fp ==NULL)
 {
  printf("Not found such a file\n");
  return -1;
 }
 while (fscanf(fp,"%lf",&data) !=EOF)
 {
  data = data;
  add_list(data, head);
 }
 show_list(head);
 sum_list(head);
 free_list(head);
 return 0;
}
struct list *alloc_list(double data){
 struct list *new = NULL;
 new = (struct list *)malloc(sizeof(struct list)); //malloc関数 →　指定バイト分、メモリ領域を確保する
 //size of → 変数や、型のメモリサイズを調べるための演算子
 if(new==NULL){
  printf("malloc error\n");//メモリ取得エラーの出力
  return NULL;//何も値が入っていないまま処理の終了
 }
 new->next = NULL;//new からNULLが入ったnextへアクセス
 new->data = data; //new からdataが入ったdataへアクセス

 return new;//返り値としてnewを返す
}

int add_list(double data, struct list *head)
{
 struct list *next = NULL;//構造体listのnextポインタの中はNULLを指す
 struct list *prev = head;//構造体listのprevポインタの中はhead指す

 next = alloc_list(data);
 if(next==NULL)
  return -1;//if文終了の返り値
 while(prev->next != NULL)
  prev = prev->next;//nextにアクセスのprevを代入
 prev->next = next; //nextにアクセスのprevにnextを代入して処理を終了
 return 0;
}

void show_list(struct list *p)
{
 while(p != NULL)//pの中身がある状態ならデータの表示
 {
  printf("%f\n", p->data);
  p = p->next;//次のpを代入
 }
}

void sum_list(struct list *p)
{
 double sum = 0;
 while(p != NULL){
  sum += p->data;
  p = p->next;
 }
 printf("sum_listを表示");
 printf("%lf\n", sum);
}
void free_list(struct list *p)
{
 struct list *p2;
 while(p != NULL)
 {
  p2 = p->next;//p2にnextにアクセスしたpを代入
  free(p);//メモリ解放
  p = p2;
 }
}


