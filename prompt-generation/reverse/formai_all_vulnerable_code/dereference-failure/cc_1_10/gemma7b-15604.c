//Gemma-7B DATASET v1.0 Category: Database querying ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_QUERY_SIZE 1024

typedef struct Query {
  char **conditions;
  int num_conditions;
  char **joins;
  int num_joins;
  struct Query *next;
} Query;

void insert_query(Query **head, char **conditions, int num_conditions, char **joins, int num_joins);

int main() {
  Query *head = NULL;
  char **conditions1 = malloc(MAX_QUERY_SIZE);
  conditions1[0] = "age > 18";
  conditions1[1] = "gender = 'male'";

  char **joins1 = malloc(MAX_QUERY_SIZE);
  joins1[0] = "friends";

  insert_query(&head, conditions1, 2, joins1, 1);

  char **conditions2 = malloc(MAX_QUERY_SIZE);
  conditions2[0] = "name = 'John Doe'";

  char **joins2 = malloc(MAX_QUERY_SIZE);
  joins2[0] = "family";

  insert_query(&head, conditions2, 1, joins2, 1);

  // Print all queries
  for (Query *query = head; query; query = query->next) {
    printf("Conditions:");
    for (int i = 0; i < query->num_conditions; i++) {
      printf(" %s", query->conditions[i]);
    }

    printf(" Joins:");
    for (int i = 0; i < query->num_joins; i++) {
      printf(" %s", query->joins[i]);
    }

    printf("\n");
  }

  return 0;
}

void insert_query(Query **head, char **conditions, int num_conditions, char **joins, int num_joins) {
  Query *new_query = malloc(sizeof(Query));

  new_query->conditions = malloc(MAX_QUERY_SIZE);
  new_query->num_conditions = num_conditions;
  for (int i = 0; i < num_conditions; i++) {
    new_query->conditions[i] = strdup(conditions[i]);
  }

  new_query->joins = malloc(MAX_QUERY_SIZE);
  new_query->num_joins = num_joins;
  for (int i = 0; i < num_joins; i++) {
    new_query->joins[i] = strdup(joins[i]);
  }

  new_query->next = NULL;

  if (*head == NULL) {
    *head = new_query;
  } else {
    (*head)->next = new_query;
  }
}