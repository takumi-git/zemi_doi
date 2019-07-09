#include <iostream>
#include <stdio.h>
#define N 10

static int a[N] = {6, 9, 12, 7, 15, 23, 2, 10, 4, 20};
int main(){
 int i, j;
 int temp;
 int p =5;

 /*for (i = 0; i < N;i++){
  printf("%3d", a[i]);
 }
 printf("\n");*/

 while(i>j){
  for (i = 0;a[i]>=a[p];i++){
   for (j = N - 1; a[j] <= a[p];j--){
    if(i<j && a[i] != a[j]){
     temp = a[i];
     a[i] = a[j];
     a[j] = temp;
     i++;
     j--;
    }else if(i==j|| a[i] == a[j]){
     i++;
     j--;
    }
  }
 }
 //最終表示
 for (j = 0; j < N; j++)
 {
   printf("%3d", a[j]);
 }
 printf("\n");
}
return 0;
}