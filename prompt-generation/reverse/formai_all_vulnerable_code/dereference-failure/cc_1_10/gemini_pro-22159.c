//GEMINI-pro DATASET v1.0 Category: Linked list operations ; Style: brave
#include <stdio.h>
#include <stdlib.h>

struct Node {
  int data;
  struct Node *next;
};

struct Node *head = NULL;

void insert_at_beginning(int data) {
  struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
  new_node->data = data;
  new_node->next = head;
  head = new_node;
}

void insert_at_end(int data) {
  struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
  new_node->data = data;
  new_node->next = NULL;
  if (head == NULL) {
    head = new_node;
    return;
  }
  struct Node *temp = head;
  while (temp->next != NULL) {
    temp = temp->next;
  }
  temp->next = new_node;
}

void insert_at_position(int data, int position) {
  if (position == 1) {
    insert_at_beginning(data);
    return;
  }
  struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
  new_node->data = data;
  struct Node *temp = head;
  for (int i = 1; i < position - 1; i++) {
    temp = temp->next;
  }
  new_node->next = temp->next;
  temp->next = new_node;
}

void delete_at_beginning() {
  if (head == NULL) {
    return;
  }
  struct Node *temp = head;
  head = head->next;
  free(temp);
}

void delete_at_end() {
  if (head == NULL) {
    return;
  }
  struct Node *temp = head;
  if (head->next == NULL) {
    head = NULL;
    free(temp);
    return;
  }
  while (temp->next->next != NULL) {
    temp = temp->next;
  }
  free(temp->next);
  temp->next = NULL;
}

void delete_at_position(int position) {
  if (position == 1) {
    delete_at_beginning();
    return;
  }
  struct Node *temp = head;
  for (int i = 1; i < position - 1; i++) {
    temp = temp->next;
  }
  struct Node *to_delete = temp->next;
  temp->next = temp->next->next;
  free(to_delete);
}

void print_list() {
  struct Node *temp = head;
  while (temp != NULL) {
    printf("%d ", temp->data);
    temp = temp->next;
  }
  printf("\n");
}

int main() {
  insert_at_end(1);
  insert_at_end(2);
  insert_at_end(3);
  insert_at_end(4);
  insert_at_end(5);
  print_list();
  insert_at_beginning(0);
  print_list();
  insert_at_position(6, 3);
  print_list();
  delete_at_beginning();
  print_list();
  delete_at_end();
  print_list();
  delete_at_position(3);
  print_list();
  return 0;
}