//FormAI DATASET v1.0 Category: Database Indexing System ; Style: brave
#include <stdio.h>
#include <stdlib.h>

struct Node {
   int key;
   char *value;
   struct Node *next;
};

struct Index {
   int size;
   struct Node **table;
};

struct Index *createIndex(int size) {
   struct Index *index = malloc(sizeof(struct Index));
   index->size = size;
   index->table = malloc(sizeof(struct Node*) * size);
   int i;
   for (i = 0; i < size; i++) {
      index->table[i] = NULL;
   }
   return index;
}

void insert(struct Index *index, int key, char *value) {
   int hash = key % index->size;
   struct Node *head = index->table[hash];
   struct Node *node = head;
   while (node != NULL) {
      if (node->key == key) {
         node->value = value;
         return;
      }
      node = node->next;
   }
   struct Node *newNode = malloc(sizeof(struct Node));
   newNode->key = key;
   newNode->value = value;
   newNode->next = head;
   index->table[hash] = newNode;
}

char *get(struct Index *index, int key) {
   int hash = key % index->size;
   struct Node *node = index->table[hash];
   while (node != NULL) {
      if (node->key == key) {
         return node->value;
      }
      node = node->next;
   }
   return NULL;
}

int main() {
   struct Index *index = createIndex(10);
   insert(index, 1, "one");
   insert(index, 2, "two");
   insert(index, 3, "three");
   insert(index, 4, "four");
   insert(index, 5, "five");
   printf("%s\n", get(index, 1));
   printf("%s\n", get(index, 2));
   printf("%s\n", get(index, 3));
   printf("%s\n", get(index, 4));
   printf("%s\n", get(index, 5));
   return 0;
}