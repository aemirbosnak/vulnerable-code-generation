//FormAI DATASET v1.0 Category: Linked list operations ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>

struct node {
  int data;
  struct node *next;
};

struct node *head = NULL;

void add(int data) {
  struct node *new_node = (struct node *) malloc(sizeof(struct node));
  new_node->data = data;
  new_node->next = head;
  head = new_node;
  printf("I have added %d to the beginning of the Linked List.\n", data);
}

void delete(int data) {
  struct node *current = head;
  struct node *previous = NULL;
  
  while (current != NULL && current->data != data) {
    previous = current;
    current = current->next;
  }
  
  if (current == NULL) {
    printf("I'm sorry, I couldn't find %d in the Linked List.\n", data);
  } else if (previous == NULL) {
    head = current->next;
    free(current);
    printf("I have deleted %d from the beginning of the Linked List.\n", data);
  } else {
    previous->next = current->next;
    free(current);
    printf("I have deleted %d from the Linked List.\n", data);
  }
}

int length() {
  int count = 0;
  struct node *current = head;
  
  while (current != NULL) {
    count++;
    current = current->next;
  }
  
  printf("The length of the Linked List is %d.\n", count);
  
  return count;
}

int main() {
  printf("Hello! I am the Surrealist Linked List Program.\n");
  
  printf("Let's start by adding some numbers to our Linked List.\n");
  
  add(1);
  add(2);
  add(3);
  add(4);
  add(5);
  
  length();
  
  printf("Now let's delete some numbers from the Linked List.\n");
  
  delete(1);
  delete(3);
  delete(5);
  
  length();
  
  printf("Thank you for playing with the Surrealist Linked List Program.\n");
  
  return 0;
}