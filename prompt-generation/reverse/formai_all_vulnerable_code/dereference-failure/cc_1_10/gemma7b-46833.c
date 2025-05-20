//Gemma-7B DATASET v1.0 Category: Database querying ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_QUERY_LENGTH 255

typedef struct Query {
  char query[MAX_QUERY_LENGTH];
  struct Query* next;
} Query;

void query_add(Query** head, char* query) {
  Query* new_query = malloc(sizeof(Query));
  strcpy(new_query->query, query);
  new_query->next = NULL;

  if (*head == NULL) {
    *head = new_query;
  } else {
    (*head)->next = new_query;
  }
}

int query_match(Query* head, char* query) {
  while (head) {
    if (strcmp(head->query, query) == 0) {
      return 1;
    }
    head = head->next;
  }

  return 0;
}

int main() {
  time_t t = time(NULL);
  srand(t);

  Query* head = NULL;
  query_add(&head, "The quick brown fox jumps over the lazy dog.");
  query_add(&head, "The cat sat on the mat.");
  query_add(&head, "The clock strikes twelve.");
  query_add(&head, "The river flows on.");

  char* query = "The clock strikes eight.";

  if (query_match(head, query) == 1) {
    printf("The query matches the list.\n");
  } else {
    printf("The query does not match the list.\n");
  }

  return 0;
}