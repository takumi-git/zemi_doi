#include <iostream>
#include <stdio.h>
using namespace std;
#define N 10

static int a[N] = {6, 9, 12, 7, 15, 23, 2, 10, 4, 20};

int main(){
 int i, j; //ループカウンター
 int temp;//交換用

 for (i = 0; i < N;i++)
  printf("%3d", a[i]);
 printf("\n");
 
//バブルソート処理
 for (i = 0; i < N - 1;i++){
  for (j = N - 1; j>i; j--)
  {
   if(a[j-1]>a[j]){
    temp = a[j];
    a[j] = a[j - 1];
    a[j - 1] = temp;
   }
  }
 
 //最終表示
 for (j = 0; j < N;j++){
   printf("%3d", a[j]);
  }
  printf("\n");
 }
 return 0;
}