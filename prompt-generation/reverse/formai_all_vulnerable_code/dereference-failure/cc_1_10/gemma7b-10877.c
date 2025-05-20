//Gemma-7B DATASET v1.0 Category: Database Indexing System ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define HASH_SIZE 1024

#define LOCK_DIR "/tmp/lock"
#define DATA_DIR "/tmp/data"
#define INDEX_DIR "/tmp/index"

#define MAX_NAME_LEN 255

typedef struct Record {
  char name[MAX_NAME_LEN];
  struct Record* next;
} Record;

typedef struct IndexNode {
  char key[MAX_NAME_LEN];
  struct IndexNode* next;
} IndexNode;

Record* insertRecord(Record* head, char* name) {
  Record* newRecord = malloc(sizeof(Record));
  strcpy(newRecord->name, name);
  newRecord->next = NULL;

  if (head == NULL) {
    head = newRecord;
  } else {
    Record* current = head;
    while (current->next) {
      current = current->next;
    }
    current->next = newRecord;
  }

  return head;
}

IndexNode* insertIndexNode(IndexNode* head, char* key) {
  IndexNode* newNode = malloc(sizeof(IndexNode));
  strcpy(newNode->key, key);
  newNode->next = NULL;

  if (head == NULL) {
    head = newNode;
  } else {
    IndexNode* current = head;
    while (current->next) {
      current = current->next;
    }
    current->next = newNode;
  }

  return head;
}

int main() {
  Record* head = NULL;
  IndexNode* indexHead = NULL;

  // Lock the directories
  system("/bin/mkdir -p " LOCK_DIR " && rm -rf " LOCK_DIR "/*");
  system("/bin/mkdir -p " DATA_DIR " && rm -rf " DATA_DIR "/*");
  system("/bin/mkdir -p " INDEX_DIR " && rm -rf " INDEX_DIR "/*");

  // Insert some records
  insertRecord(head, "John Doe");
  insertRecord(head, "Jane Doe");
  insertRecord(head, "Bob Smith");

  // Insert some index nodes
  insertIndexNode(indexHead, "John Doe");
  insertIndexNode(indexHead, "Jane Doe");

  // Print the records
  Record* current = head;
  while (current) {
    printf("%s\n", current->name);
  }

  // Print the index nodes
  IndexNode* indexCurrent = indexHead;
  while (indexCurrent) {
    printf("%s\n", indexCurrent->key);
  }

  return 0;
}