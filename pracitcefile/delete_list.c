#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct list
{
 double data;
 int n;
 struct list *next;
} List;

List *alloc_list(double data);
int add_list(double data, List *head);
void show_list(List *p);
void free_list(List *p);
void sum_list(List *p);
int insert_list(double data, List *head);
void delete_list(List *start,List *target);

List *alloc_list(double data)
{
 List *new = NULL;
 new = (List *)malloc(sizeof(List)); //malloc関数 →　指定バイト分、メモリ領域を確保する
 //size of → 変数や、型のメモリサイズを調べるための演算子
 if (new == NULL)
 {
  printf("malloc error\n"); //メモリ取得エラーの出力
  return NULL;              //何も値が入っていないまま処理の終了
 }
 new->next = NULL; //new からNULLが入ったnextへアクセス
 new->data = data; //new からdataが入ったdataへアクセス

 return new; //返り値としてnewを返す
}

int add_list(double data, List *head)
{
 List *next = NULL; //構造体listのnextポインタの中はNULLを指す
 List *prev = head; //構造体listのprevポインタの中はhead指す

 next = alloc_list(data);
 if (next == NULL)
  return -1; //if文終了の返り値
 while (prev->next != NULL)
  prev = prev->next; //nextにアクセスのprevを代入
 prev->next = next;  //nextにアクセスのprevにnextを代入して処理を終了
 return 0;
}

void show_list(List *p)
{
 while (p != NULL) //pの中身がある状態ならデータの表示
 {
  printf("pの中身を表示\n");
  printf("%f\n", p->data);
  p = p->next; //次のpを代入
 }
}

void sum_list(List *p)
{
 double sum = 0;
 while (p != NULL)
 {
  sum += p->data;
  p = p->next;
 }
 printf("sum_listを表示\n");
 printf("%lf\n", sum);
}
void free_list(List *p)
{
 List *p2;
 while (p != NULL)
 {
  p2 = p->next; //p2にnextにアクセスしたpを代入
  free(p);      //メモリ解放
  p = p2;
 }
}

void bubble_sort(List *p)
{
 List *head; //headをさすポインタ
 List *back; //back(配列の最後を指す)ポインタ
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

int insert_list(double data, List *head)
{
 List *new_list = NULL;
 List *prev = head;
 int roop = 0;//roop カウンター

 new_list = alloc_list(data); //リスト作成
 if (new_list == NULL)        //メモリが取れない＝アロックリストをみるとNULL
  return -1;

 while (prev->next != NULL) //リストの最後まで探索
 {
  if (roop == 3)
  {
   new_list->next = prev->next; //新しいリストのnextにもともとのnextをコピー
   prev->next = new_list;       //元のnextに新しいリストを指すアドレス
   roop++;
  }
  else
  {
   prev = prev->next;
   roop++;
  }
 }
 return 0;
}

void delete_list (List *head,List *target)
{
 List *p = head; //リストの先頭をさすポインター

 //消去用のtargetまで探索
 while (p->next !=target){
  p = p->next;//pをtargetまで動かす
 }
 p->next = p->next->next;//targetの１つ前のオブジェクトのnextをひとつ飛ばしのオブジェクトへと入れ替え
 free(target);//targetのオブジェクトの消去
}

/*メイン関数ここでファイルを読み込んで
 *上記で書いたプログラムの実行をする
 *
*/
int main(void)
{
 double data;
 FILE *fp;
 char *fname = "data.txt";//データは自分で指定しなければならない
 List *head; //リストのhead(先頭)の作成

 head = alloc_list(0);
 fp = fopen(fname, "r");

 if (fp == NULL)
 {
  printf("Not found such a file\n");
  return -1;
 }
 while (fscanf(fp, "%lf", &data) != EOF) //ファイル最後まで数値の読み込み
 {
  add_list(data, head);
 }
 //add_list(6, head);
 insert_list(8, head);
 insert_list(2, head);
 bubble_sort(head);
 show_list(head);
 delete_list(head, head->next);//0
 delete_list(head, head->next->next);//2
 delete_list(head, head->next->next->next);//4
 delete_list(head, head->next->next->next->next);//6
 delete_list(head, head->next->next->next->next->next);//8
 puts("\n");//比較表示結果
 puts("リスト消去後の結果を表示");
 show_list(head); //delete後のリスト表示
 //sum_list(head);
 free_list(head);
 return 0;
}
