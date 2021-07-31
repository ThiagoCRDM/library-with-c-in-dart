#include<stdbool.h>

struct  NODE {
  int data;
  int key;
  struct NODE *next;
};

void printList();

void insertFirst(int key, int data);

struct NODE* deleteFirst();

int isEmpty();

int length();

struct NODE* find(int key);

struct NODE* delete(int key);

void sort();

void reverse(struct NODE** head_ref);