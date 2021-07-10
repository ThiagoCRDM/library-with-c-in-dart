#include <stdlib.h>
#include <stdio.h>
#include "queue.h"

int items[SIZE], front = -1, rear = -1;



int main(){

  //enQueue 5 elements
  enQueue(1);
  enQueue(2);
  enQueue(3);
  enQueue(4);
  enQueue(5);
 
  display();

  return 0;
}

void enQueue(int value){
  if(rear == SIZE -1)
    printf("\nQueue is full!");
  else{
    if(front == -1)
      front = 0;
    
    rear++;
    items[rear] = value;
    printf("\nInserted -> %d", value);
  } 
}

void deQueue(){
  if(front == -1)
    printf("\nQueue is empty!");
  else{
    printf("\nDeleted: %d", items[front]);
    front++;
    if (front > rear)
      front = rear = -1;
  }
}

void display(){
  if(rear == -1)
    printf("\nQueue is empty!");
  else{
    int i;
    printf("\nQueue elements are:\n");
    for (i = 0; i <= rear; i++){
      printf("%d ", items[i]);
    }
  }
  printf("\n");
}
