#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct cell{ //セル
 int value;  //セルの値
 struct cell *next;//次のセルへのポインタ
};

void insrt_cell(struct cell **pointer,int new_value){
 new_cell = (struct cell *)malloc(sizeof(struct cell));

 new_cell->next = *pointer;
 *pointer = new_cell;
 new_cell->value = new_value;

 return new_cell;
}

void *insert_cell_tail(struct **pointer,int new_value){
 struct *new_cell;
 struct *ptr;

 if(*new_cell==NULL){
  new_cell = insert_cell(pointer, new_value);
 }else{
  ptr = *pointer;
  while(ptr ->next !=NULL){
   ptr = ptr->next;
  }
  new_cell = malloc(sizeof(struct cell));
  new_cell->next = NULL;
  new_cell->data = new_value;
  ptr->next = new_cell;
 }
 return new_cell;
}