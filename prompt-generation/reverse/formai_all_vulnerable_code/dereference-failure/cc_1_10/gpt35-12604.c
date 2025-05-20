//FormAI DATASET v1.0 Category: Linked list operations ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define structure for our linked list node
struct node {
  char name[20];
  int age;
  struct node *next;
};

// Function to add a node at the end of the linked list
void addNode(struct node **head_ref, char *name, int age) {
  struct node *new_node = (struct node*) malloc(sizeof(struct node));
  struct node *last_node = *head_ref;

  strcpy(new_node->name, name);
  new_node->age = age;
  new_node->next = NULL;

  if (*head_ref == NULL) {
    *head_ref = new_node;
    return;
  }

  while (last_node->next != NULL) {
    last_node = last_node->next;
  }
  last_node->next = new_node;
}

// Function to display the linked list nodes
void displayList(struct node *node) {
  while (node != NULL) {
    printf("Name: %s, Age: %d\n", node->name, node->age);
    node = node->next;
  }
}

// Driver program
int main() {
  struct node *head = NULL;

  addNode(&head, "Juliet", 16);
  addNode(&head, "Romeo", 18);
  addNode(&head, "Mercutio", 20);

  printf("Original list of lovers:\n");
  displayList(head);

  printf("\n");

  printf("Oh, my sweet Juliet! Your fair face like a light,\n");
  printf("Shall never fade away, for thou art my delight.\n");
  printf("My love for thee, like a linked list, grows each day.\n");
  printf("Thus, I shall add more and more nodes like thy charms array.\n\n");

  addNode(&head, "Tybalt", 25);
  addNode(&head, "Benvolio", 22);

  printf("Updated list of lovers:\n");
  displayList(head);

  printf("\n");

  printf("My dearest Romeo, thou hast bewitched me with thy words,\n");
  printf("Like a node that points to the next, my heart now forwards.\n");
  printf("For in thy company, I find peace and joy,\n");
  printf("And like a doubly linked list, our love shall grow.\n");

  return 0;
}