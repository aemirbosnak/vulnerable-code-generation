//Gemma-7B DATASET v1.0 Category: URL Sanitizer ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define HASH_SIZE 101
#define MAX_URL_LEN 255

typedef struct Node {
  char **data;
  struct Node* next;
} Node;

void insert(Node** head, char** url) {
  Node* newNode = malloc(sizeof(Node));
  newNode->data = malloc(MAX_URL_LEN);
  strcpy(newNode->data, url);
  newNode->next = NULL;

  if (*head == NULL) {
    *head = newNode;
  } else {
    (*head)->next = newNode;
  }
}

void sanitize(Node* head) {
  for (Node* current = head; current; current = current->next) {
    char* url = current->data;
    // Remove invalid characters
    char* cleanUrl = strcspn(url, "<>()[]|\\^$%^&*");
    // Replace relative URLs with absolute ones
    if (cleanUrl == url) {
      cleanUrl = malloc(MAX_URL_LEN);
      sprintf(cleanUrl, "localhost:%d/%s", 8080, url);
    }
    // Update the URL
    free(current->data);
    current->data = cleanUrl;
  }
}

int main() {
  Node* head = NULL;
  insert(&head, "example.com");
  insert(&head, "foo.bar/baz.html");
  insert(&head, "evil(script)@example.com");

  sanitize(head);

  for (Node* current = head; current; current = current->next) {
    printf("%s\n", current->data);
  }

  return 0;
}