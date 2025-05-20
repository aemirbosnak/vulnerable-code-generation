//Gemma-7B DATASET v1.0 Category: System administration ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

typedef struct Node {
  char data[MAX_BUFFER_SIZE];
  struct Node* next;
} Node;

typedef struct System {
  Node* head;
  int capacity;
} System;

System* create_system(int capacity) {
  System* system = malloc(sizeof(System));
  system->head = NULL;
  system->capacity = capacity;
  return system;
}

void add_data(System* system, char* data) {
  Node* newNode = malloc(sizeof(Node));
  strcpy(newNode->data, data);
  newNode->next = system->head;
  system->head = newNode;
}

char* get_data(System* system) {
  if (system->head == NULL) {
    return NULL;
  }
  return system->head->data;
}

int main() {
  System* system = create_system(5);
  add_data(system, "Hello, world!");
  add_data(system, "This is a futuristic C system.");
  add_data(system, "It is powerful and efficient.");

  char* data = get_data(system);
  if (data) {
    printf("%s", data);
  } else {
    printf("No data available");
  }

  return 0;
}