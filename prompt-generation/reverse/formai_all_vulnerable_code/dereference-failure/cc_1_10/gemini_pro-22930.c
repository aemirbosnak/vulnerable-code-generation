//GEMINI-pro DATASET v1.0 Category: Tower of Hanoi Problem ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
struct Node {
  int data;
  struct Node *next;
};
typedef struct Node node;
node *create_node(int data) {
  node *temp = (node *)malloc(sizeof(node));
  temp->data = data;
  temp->next = NULL;
  return temp;
}
void push(node **head, int data) {
  node *temp = create_node(data);
  temp->next = *head;
  *head = temp;
}
int pop(node **head) {
  int top;
  node *temp = *head;
  if (*head == NULL) {
    printf("Stack is empty\n");
    return -1;
  }
  top = temp->data;
  *head = temp->next;
  free(temp);
  return top;
}
int peek(node *head) {
  if (head == NULL) {
    printf("Stack is empty\n");
    return -1;
  }
  return head->data;
}
void tower_of_hanoi(int n, node **source, node **destination, node **auxiliary) {
  if (n == 1) {
    push(destination, pop(source));
    return;
  }
  tower_of_hanoi(n - 1, source, auxiliary, destination);
  push(destination, pop(source));
  tower_of_hanoi(n - 1, auxiliary, destination, source);
}
void print_stack(node *head) {
  while (head != NULL) {
    printf("%d ", head->data);
    head = head->next;
  }
  printf("\n");
}
int main() {
  int n;
  node *source = NULL;
  node *destination = NULL;
  node *auxiliary = NULL;
  printf("Enter the number of disks: ");
  scanf("%d", &n);
  for (int i = n; i >= 1; i--) {
    push(&source, i);
  }
  printf("Source: ");
  print_stack(source);
  printf("Destination: ");
  print_stack(destination);
  printf("Auxiliary: ");
  print_stack(auxiliary);
  tower_of_hanoi(n, &source, &destination, &auxiliary);
  printf("Source: ");
  print_stack(source);
  printf("Destination: ");
  print_stack(destination);
  printf("Auxiliary: ");
  print_stack(auxiliary);
  return 0;
}