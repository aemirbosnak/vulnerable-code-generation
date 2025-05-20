//GEMINI-pro DATASET v1.0 Category: Sorting ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include "assert.h"

/* This is the data structure we'll be sorting. */
struct node {
  int data;
  struct node *next;
};

/* Insert a node into a sorted linked list. */
void insert_node(struct node **head, struct node *new_node)
{
  struct node *curr;

  /* If the list is empty, or if the new node's data is less than the
     head's data, then insert the new node at the beginning of the list. */
  if (*head == NULL || (*head)->data > new_node->data) {
    new_node->next = *head;
    *head = new_node;
  } else {
    /* Otherwise, find the place to insert the new node. */
    curr = *head;
    while (curr->next != NULL && curr->next->data < new_node->data)
      curr = curr->next;

    /* Insert the new node after the current node. */
    new_node->next = curr->next;
    curr->next = new_node;
  }
}

/* Print a linked list. */
void print_list(struct node *head)
{
  struct node *curr;

  for (curr = head; curr != NULL; curr = curr->next) {
    printf("%d ", curr->data);
  }
  printf("\n");
}

/* Sort a linked list using the insertion sort algorithm. */
void insertion_sort(struct node **head)
{
  struct node *new_node, *curr;

  /* If the list is empty, then there's nothing to sort. */
  if (*head == NULL)
    return;

  /* Create a new node to hold the first element of the list. */
  new_node = (struct node *)malloc(sizeof(struct node));
  assert(new_node != NULL);
  new_node->data = (*head)->data;
  new_node->next = NULL;

  /* Remove the first element from the list. */
  *head = (*head)->next;

  /* Sort the rest of the list. */
  while (*head != NULL) {
    /* Create a new node to hold the current element of the list. */
    curr = (struct node *)malloc(sizeof(struct node));
    assert(curr != NULL);
    curr->data = (*head)->data;
    curr->next = NULL;

    /* Remove the current element from the list. */
    *head = (*head)->next;

    /* Insert the current element into the sorted list. */
    insert_node(&new_node, curr);
  }

  /* The sorted list is now in the new_node list. */
  *head = new_node;
}

int main(void)
{
  struct node *head, *new_node;
  int i;

  /* Create a linked list of unsorted data. */
  head = NULL;
  for (i = 0; i < 10; i++) {
    new_node = (struct node *)malloc(sizeof(struct node));
    assert(new_node != NULL);
    new_node->data = rand() % 100;
    new_node->next = NULL;
    insert_node(&head, new_node);
  }

  /* Print the unsorted list. */
  printf("Unsorted list:\n");
  print_list(head);

  /* Sort the linked list. */
  insertion_sort(&head);

  /* Print the sorted list. */
  printf("Sorted list:\n");
  print_list(head);

  return 0;
}