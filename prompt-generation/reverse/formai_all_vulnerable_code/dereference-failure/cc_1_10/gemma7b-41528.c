//Gemma-7B DATASET v1.0 Category: Database Indexing System ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INDEX_SIZE 1024

typedef struct IndexNode {
  char *key;
  struct IndexNode *next;
} IndexNode;

struct IndexTable {
  IndexNode **buckets;
  int size;
  int capacity;
  int (*compare)(char *, char *);
  void (*insert)(char *);
  void (*delete)(char *);
};

void insert(struct IndexTable *table, char *key)
{
  int hash = table->compare(key, table->buckets);
  IndexNode *newNode = malloc(sizeof(IndexNode));
  newNode->key = strdup(key);
  newNode->next = NULL;

  if (table->buckets[hash] == NULL)
  {
    table->buckets[hash] = newNode;
  }
  else
  {
    IndexNode *ptr = table->buckets[hash];
    while (ptr->next)
    {
      ptr = ptr->next;
    }
    ptr->next = newNode;
  }

  table->size++;
}

void delete(struct IndexTable *table, char *key)
{
  int hash = table->compare(key, table->buckets);
  IndexNode *ptr = table->buckets[hash];

  if (ptr == NULL)
  {
    return;
  }

  if (ptr->key == key)
  {
    table->buckets[hash] = ptr->next;
    free(ptr);
    table->size--;
  }
  else
  {
    IndexNode *prev = ptr;
    ptr = ptr->next;
    while (ptr)
    {
      if (ptr->key == key)
      {
        prev->next = ptr->next;
        free(ptr);
        table->size--;
        return;
      }
      prev = ptr;
      ptr = ptr->next;
    }
  }
}

int main()
{
  struct IndexTable *table = malloc(sizeof(struct IndexTable));
  table->buckets = malloc(MAX_INDEX_SIZE * sizeof(IndexNode *));
  table->size = 0;
  table->capacity = MAX_INDEX_SIZE;
  table->compare = strcmp;
  table->insert = insert;
  table->delete = delete;

  insert(table, "John");
  insert(table, "Mary");
  insert(table, "Bob");
  insert(table, "Alice");

  delete(table, "Mary");

  for (int i = 0; i < table->size; i++)
  {
    printf("%s ", table->buckets[i]->key);
  }

  printf("\n");

  return 0;
}