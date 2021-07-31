#include<stdlib.h>
#include<stdio.h>
#include<stdbool.h>
#include "linked_list.h"

struct NODE *head = NULL;
struct NODE *current = NULL;

int main(){
  insertFirst(1,10);
  insertFirst(2,20);
  insertFirst(3,30);
  insertFirst(4,1);
  insertFirst(5,40);
  insertFirst(6,56); 

  printf("Original List: "); 

  printList();

  while(!isEmpty()) {            
    struct NODE *temp = deleteFirst();
    printf("\nDeleted value:");
    printf("(%d,%d) ",temp->key,temp->data);
  }  

  printf("\nList after deleting all items: ");
  printList();
  insertFirst(1,10);
  insertFirst(2,20);
  insertFirst(3,30);
  insertFirst(4,1);
  insertFirst(5,40);
  insertFirst(6,56);
  
  printf("\nRestored List: ");
  printList();
  printf("\n");  

  struct NODE *foundLink = find(4);

  if(foundLink != NULL) {
    printf("Element found: ");
    printf("(%d,%d) ",foundLink->key,foundLink->data);
    printf("\n");  
  } else {
    printf("Element not found.");
  }

  delete(4);
  printf("List after deleting an item: ");
  printList();
  printf("\n");
  foundLink = find(4);

  if(foundLink != NULL) {
    printf("Element found: ");
    printf("(%d,%d) ",foundLink->key,foundLink->data);
    printf("\n");
  } else {
    printf("Element not found.");
  }

  printf("\n");
  sort();

  printf("List after sorting the data: ");
  printList();

  reverse(&head);
  printf("\nList after reversing the data: ");
  printList();
}

void printList() {
  struct NODE *ptr = head;
  printf("\n[");

  while(ptr != NULL) {
    printf("(%d,%d)",ptr->key,ptr->data);
    ptr = ptr->next;
  }

  printf("]");
}


void insertFirst(int key, int data){

  struct NODE *link = (struct NODE*) malloc(sizeof(struct NODE));

  link->key = key;
  link->data = data;

  link->next = head;

  head = link;
}

struct NODE* deleteFirst(){
  struct NODE *tempLink = head;

  head = head->next;

  return tempLink;
}

int isEmpty(){
  if(head == NULL) 
    return 1;
  else 
    return 0;
}

int length(){
  int length = 0;
  struct NODE *current;

  for (current = head; current != NULL; current = current->next){
    length++;
  }

  return length;
}

struct NODE* find(int key){
  struct NODE*  current = head;

  if(head == NULL)
    return NULL;
  
  while (current->key != key){

    if(current->next == NULL)
      return NULL;
    else
      current = current->next;
 
  }

  return current;
}

struct NODE* delete(int key){
  struct NODE* current = head;
  struct NODE* previous = NULL;

  if(head == NULL)
    return NULL;
  
  while (current->key != key){
    if(current->next == NULL) 
        return NULL;
    else { 
        previous = current;
        current = current->next;
    }
  }
  if(current == head)
    head = current->next;
  else
    previous->next = current->next;
  
  return current;
}

void sort(){
  int i, j, k, tempKey, tempData;

  struct NODE *current;
  struct NODE *next;

  int size = length();
  k = size;

  for ( i = 0; i < size - 1; i++, k-- ) {
    current = head;
    next = head->next;	
    for ( j = 1; j < k; j++ ) {   
      if ( current->data > next->data ) {
        tempData = current->data;
        current->data = next->data;
        next->data = tempData;

        tempKey = current->key;
        current->key = next->key;
        next->key = tempKey;
      }
  
      current = current->next;
      next = next->next;
    }
  }   


}

void reverse(struct NODE** head_ref) {
  struct NODE* prev   = NULL;
  struct NODE* current = *head_ref;
  struct NODE* next;

  while (current != NULL) {
    next  = current->next;
    current->next = prev;   
    prev = current;
    current = next;
  }

  *head_ref = prev;
}