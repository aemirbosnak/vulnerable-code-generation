//FormAI DATASET v1.0 Category: Database Indexing System ; Style: accurate
#include <stdio.h>
#include <stdlib.h>

struct node {
   int data;
   struct node* next;
};

struct index {
   struct node* start;
   struct node* end;
};

void addValue(struct index* idx, int val) {
   struct node* newNode = (struct node*) malloc(sizeof(struct node));

   newNode->data = val;
   newNode->next = NULL;

   if(idx->start==NULL) {
      idx->start = newNode;
      idx->end = newNode;
   } else {
      idx->end->next = newNode;
      idx->end = newNode;
   }
}

struct index* createIndex() {
   struct index* idx = (struct index*) malloc(sizeof(struct index));

   idx->start = NULL;
   idx->end = NULL;

   return idx;
}

void printIndex(struct index* idx) {
   struct node* currentNode = idx->start;

   printf("Index values: ");

   while(currentNode!=NULL) {
      printf("%d ", currentNode->data);
      currentNode = currentNode->next;
   }
}

int main() {
   struct index* idx = createIndex();

   addValue(idx, 1);
   addValue(idx, 4);
   addValue(idx, 3);
   addValue(idx, 7);

   printIndex(idx);

   return 0;
}