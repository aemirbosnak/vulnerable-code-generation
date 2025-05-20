//Gemma-7B DATASET v1.0 Category: Database querying ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_QUERY_LENGTH 1024

typedef struct Query {
  char *query_text;
  int query_length;
  struct Query *next;
} Query;

int main() {
  Query *head = NULL;

  // Allocate memory for the first query
  head = malloc(sizeof(Query));
  head->query_text = malloc(MAX_QUERY_LENGTH);
  head->query_length = 0;
  head->next = NULL;

  // Get the query text from the user
  printf("Enter your query: ");
  fgets(head->query_text, MAX_QUERY_LENGTH, stdin);

  // Calculate the length of the query
  head->query_length = strlen(head->query_text);

  // Add the query to the head of the list
  head->next = NULL;

  // Allocate memory for the second query
  Query *second = malloc(sizeof(Query));
  second->query_text = malloc(MAX_QUERY_LENGTH);
  second->query_length = 0;
  second->next = NULL;

  // Get the query text from the user
  printf("Enter your query: ");
  fgets(second->query_text, MAX_QUERY_LENGTH, stdin);

  // Calculate the length of the query
  second->query_length = strlen(second->query_text);

  // Add the query to the tail of the list
  head->next = second;

  // Print the queries
  printf("Your queries are:\n");
  for (Query *current = head; current; current = current->next) {
    printf("  %s\n", current->query_text);
  }

  return 0;
}