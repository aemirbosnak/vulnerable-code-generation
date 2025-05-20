//Gemma-7B DATASET v1.0 Category: Database Indexing System ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORD_SIZE 1024

typedef struct Record {
  char name[MAX_RECORD_SIZE];
  int age;
  struct Record* next;
} Record;

typedef struct IndexNode {
  char key[MAX_RECORD_SIZE];
  struct IndexNode* next;
} IndexNode;

IndexNode* insertIndexNode(IndexNode* head, char* key)
{
  IndexNode* newNode = malloc(sizeof(IndexNode));
  strcpy(newNode->key, key);
  newNode->next = NULL;

  if (head == NULL)
  {
    head = newNode;
  }
  else
  {
    IndexNode* current = head;
    IndexNode* previous = NULL;

    while (current)
    {
      if (strcmp(newNode->key, current->key) < 0)
      {
        previous = current;
        current = current->next;
      }
      else
      {
        break;
      }
    }

    if (previous)
    {
      previous->next = newNode;
    }
    else
    {
      head = newNode;
    }
  }

  return head;
}

Record* insertRecord(Record* head, char* name, int age)
{
  Record* newNode = malloc(sizeof(Record));
  strcpy(newNode->name, name);
  newNode->age = age;
  newNode->next = NULL;

  if (head == NULL)
  {
    head = newNode;
  }
  else
  {
    Record* current = head;
    Record* previous = NULL;

    while (current)
    {
      if (strcmp(newNode->name, current->name) < 0)
      {
        previous = current;
        current = current->next;
      }
      else
      {
        break;
      }
    }

    if (previous)
    {
      previous->next = newNode;
    }
    else
    {
      head = newNode;
    }
  }

  return head;
}

void searchRecord(IndexNode* head, char* name)
{
  IndexNode* current = head;

  while (current)
  {
    if (strcmp(current->key, name) == 0)
    {
      Record* record = insertRecord(NULL, current->key, 0);
      printf("Name: %s, Age: %d\n", record->name, record->age);
    }
    current = current->next;
  }
}

int main()
{
  Record* head = insertRecord(NULL, "John Doe", 25);
  insertRecord(head, "Jane Doe", 30);
  insertRecord(head, "Peter Pan", 12);

  IndexNode* headIndex = insertIndexNode(NULL, "John Doe");
  insertIndexNode(headIndex, "Jane Doe");
  insertIndexNode(headIndex, "Peter Pan");

  searchRecord(headIndex, "John Doe");

  return 0;
}