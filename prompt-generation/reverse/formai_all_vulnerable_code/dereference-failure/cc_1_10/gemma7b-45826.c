//Gemma-7B DATASET v1.0 Category: RAM usage monitor ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define RAM_SIZE 1024

typedef struct Node {
  int data;
  struct Node* next;
} Node;

Node* head = NULL;

void insert(int data) {
  Node* newNode = malloc(sizeof(Node));
  newNode->data = data;
  newNode->next = NULL;

  if (head == NULL) {
    head = newNode;
  } else {
    head->next = newNode;
    head = newNode;
  }
}

void monitor() {
  printf("RAM Usage: ");
  int used = 0;
  for (Node* current = head; current; current = current->next) {
    used++;
  }
  printf("%d/%d (%.2f%%)\n", used, RAM_SIZE, (float)used / RAM_SIZE * 100);
}

int main() {
  insert(10);
  insert(20);
  insert(30);
  insert(40);
  insert(50);

  monitor();

  sleep(5);

  insert(60);
  insert(70);
  insert(80);

  monitor();

  return 0;
}