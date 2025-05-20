//FormAI DATASET v1.0 Category: Database Indexing System ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
   int id;
   char name[50];
   char email[50];
} Record;

Record database[1000];
int currentIndex = 0;

typedef struct IndexNode {
   int key;
   int location;
   struct IndexNode *leftChild, *rightChild;
} IndexNode;

IndexNode *root = NULL;

void insert(int key, int location) {
   IndexNode *node = (IndexNode*) malloc(sizeof(IndexNode));
   node->key = key;
   node->location = location;
   node->leftChild = NULL;
   node->rightChild = NULL;

   if (root == NULL) {
      root = node;
   } else {
      IndexNode *current = root;
      IndexNode *parent = NULL;

      while (1) {
         parent = current;

         if (key < parent->key) {
            current = current->leftChild;

            if (current == NULL) {
               parent->leftChild = node;
               return;
            }
         } else {
            current = current->rightChild;

            if (current == NULL) {
               parent->rightChild = node;
               return;
            }
         }
      }
   }
}

int search(int key) {
   IndexNode *current = root;

   while (current->key != key) {
      if (key < current->key) {
         current = current->leftChild;
      } else {
         current = current->rightChild;
      }

      if (current == NULL) {
         printf("Record not found\n");
         return -1;
      }
   }

   return current->location;
}

void saveToDatabase(char *line) {
   char *token = strtok(line, ",");
   Record newRecord;

   newRecord.id = atoi(token);
   token = strtok(NULL, ",");
   strcpy(newRecord.name, token);
   token = strtok(NULL, ",");
   strcpy(newRecord.email, token);

   database[currentIndex++] = newRecord;
   insert(newRecord.id, currentIndex - 1);
}

int main() {
   FILE *file = fopen("data.csv", "r");
   char line[100];

   if (file) {
      while (fgets(line, 100, file)) {
         saveToDatabase(line);
      }
   } else {
      printf("Error: Cannot open file");
   }

   int idToFind = 10;
   int location = search(idToFind);

   if (location != -1) {
      printf("Record found at location %d\n", location);
      printf("ID: %d\tName: %s\tEmail: %s\n", database[location].id, database[location].name, database[location].email);
   }
   
   fclose(file);
   return 0;
}