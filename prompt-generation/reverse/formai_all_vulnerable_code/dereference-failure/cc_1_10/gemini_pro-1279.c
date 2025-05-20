//GEMINI-pro DATASET v1.0 Category: Linked list operations ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int data;
  struct node *next;
} node;

node *head = NULL;

void insert_at_beginning(int data) {
  node *new_node = (node *) malloc(sizeof(node));
  new_node->data = data;
  new_node->next = head;
  head = new_node;
}

void insert_at_end(int data) {
  node *new_node = (node *) malloc(sizeof(node));
  new_node->data = data;
  new_node->next = NULL;

  if (head == NULL) {
    head = new_node;
    return;
  }

  node *temp = head;
  while (temp->next != NULL) {
    temp = temp->next;
  }
  temp->next = new_node;
}

void insert_at_position(int position, int data) {
  if (position == 0) {
    insert_at_beginning(data);
    return;
  }

  node *new_node = (node *) malloc(sizeof(node));
  new_node->data = data;
  new_node->next = NULL;

  node *temp = head;
  for (int i = 0; i < position - 1; i++) {
    if (temp->next == NULL) {
      printf("Invalid position\n");
      return;
    }
    temp = temp->next;
  }
  new_node->next = temp->next;
  temp->next = new_node;
}

void delete_at_beginning() {
  if (head == NULL) {
    printf("List is empty\n");
    return;
  }

  node *temp = head;
  head = head->next;
  free(temp);
}

void delete_at_end() {
  if (head == NULL) {
    printf("List is empty\n");
    return;
  }

  node *temp = head;
  node *prev = NULL;
  while (temp->next != NULL) {
    prev = temp;
    temp = temp->next;
  }
  prev->next = NULL;
  free(temp);
}

void delete_at_position(int position) {
  if (head == NULL) {
    printf("List is empty\n");
    return;
  }

  if (position == 0) {
    delete_at_beginning();
    return;
  }

  node *temp = head;
  node *prev = NULL;
  for (int i = 0; i < position; i++) {
    if (temp->next == NULL) {
      printf("Invalid position\n");
      return;
    }
    prev = temp;
    temp = temp->next;
  }
  prev->next = temp->next;
  free(temp);
}

void print_list() {
  node *temp = head;
  while (temp != NULL) {
    printf("%d ", temp->data);
    temp = temp->next;
  }
  printf("\n");
}

int main() {
  // Romeo and Juliet story
  // Romeo and Juliet meet
  insert_at_end(1);  // Romeo
  insert_at_end(2);  // Juliet

  // They fall in love
  insert_at_position(1, 3);  // Love

  // But their families forbid their love
  insert_at_end(4);  // Capulet
  insert_at_end(5);  // Montague

  // Romeo is banished
  delete_at_position(1);

  // Juliet thinks Romeo is dead and takes a potion to sleep
  delete_at_position(2);

  // Romeo returns and finds Juliet sleeping
  insert_at_position(2, 2);

  // Romeo thinks Juliet is dead and kills himself
  delete_at_beginning();

  // Juliet wakes up and finds Romeo dead
  delete_at_position(2);

  // Juliet kills herself
  delete_at_end();

  // The two families reconcile
  delete_at_end();
  delete_at_end();

  // The story ends with a tragedy
  printf("The tragedy of Romeo and Juliet:\n");
  print_list();

  return 0;
}