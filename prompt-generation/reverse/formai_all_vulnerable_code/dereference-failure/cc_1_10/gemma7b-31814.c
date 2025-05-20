//Gemma-7B DATASET v1.0 Category: Data mining ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a macro to read a line from the input
#define READ_LINE(str) getline(str, NULL, 1024)

// Function to compare two strings
int compare(char *a, char *b) {
  return strcmp(a, b);
}

int main() {
  // Create a linked list of strings
  struct node {
    char *data;
    struct node *next;
  } *head = NULL;

  // Read the first line of input
  char line[1024];
  READ_LINE(line);

  // Create a new node and store the line in it
  struct node *newNode = malloc(sizeof(struct node));
  newNode->data = strdup(line);
  newNode->next = NULL;

  // If the list is not empty, add the new node to the end
  if (head) {
    struct node *temp = head;
    while (temp->next) {
      temp = temp->next;
    }
    temp->next = newNode;
  } else {
    head = newNode;
  }

  // Read the remaining lines of input
  while (READ_LINE(line) != -1) {
    // Create a new node and store the line in it
    newNode = malloc(sizeof(struct node));
    newNode->data = strdup(line);
    newNode->next = NULL;

    // Add the new node to the end of the list
    if (head) {
      struct node *temp = head;
      while (temp->next) {
        temp = temp->next;
      }
      temp->next = newNode;
    } else {
      head = newNode;
    }
  }

  // Print the list of strings
  struct node *temp = head;
  while (temp) {
    printf("%s\n", temp->data);
    temp = temp->next;
  }

  return 0;
}