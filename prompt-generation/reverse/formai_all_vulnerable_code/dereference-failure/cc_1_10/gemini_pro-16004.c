//GEMINI-pro DATASET v1.0 Category: Linked list operations ; Style: scientific
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>

// A simple linked list node
struct node {
  int data;
  struct node *next;
};

// Insert a node at the beginning of the list
struct node *insert_at_beginning(struct node *head, int data) {
  struct node *new_node = malloc(sizeof(struct node));
  new_node->data = data;
  new_node->next = head;
  return new_node;
}

// Insert a node at the end of the list
struct node *insert_at_end(struct node *head, int data) {
  struct node *new_node = malloc(sizeof(struct node));
  new_node->data = data;
  new_node->next = NULL;
  if (head == NULL) {
    return new_node;
  } else {
    struct node *current = head;
    while (current->next != NULL) {
      current = current->next;
    }
    current->next = new_node;
    return head;
  }
}

// Insert a node at a specific position in the list
struct node *insert_at_position(struct node *head, int data, int position) {
  struct node *new_node = malloc(sizeof(struct node));
  new_node->data = data;
  if (position == 0) {
    return insert_at_beginning(head, data);
  } else {
    struct node *current = head;
    while (position > 1 && current != NULL) {
      current = current->next;
      position--;
    }
    if (current == NULL) {
      return head;
    } else {
      new_node->next = current->next;
      current->next = new_node;
      return head;
    }
  }
}

// Delete a node from the beginning of the list
struct node *delete_from_beginning(struct node *head) {
  if (head == NULL) {
    return NULL;
  } else {
    struct node *new_head = head->next;
    free(head);
    return new_head;
  }
}

// Delete a node from the end of the list
struct node *delete_from_end(struct node *head) {
  if (head == NULL) {
    return NULL;
  } else if (head->next == NULL) {
    free(head);
    return NULL;
  } else {
    struct node *current = head;
    while (current->next->next != NULL) {
      current = current->next;
    }
    free(current->next);
    current->next = NULL;
    return head;
  }
}

// Delete a node from a specific position in the list
struct node *delete_from_position(struct node *head, int position) {
  if (position == 0) {
    return delete_from_beginning(head);
  } else {
    struct node *current = head;
    while (position > 1 && current != NULL) {
      current = current->next;
      position--;
    }
    if (current == NULL || current->next == NULL) {
      return head;
    } else {
      struct node *temp = current->next;
      current->next = temp->next;
      free(temp);
      return head;
    }
  }
}

// Print the list
void print_list(struct node *head) {
  struct node *current = head;
  while (current != NULL) {
    printf("%d ", current->data);
    current = current->next;
  }
  printf("\n");
}

// Get the length of the list
int get_length(struct node *head) {
  int length = 0;
  struct node *current = head;
  while (current != NULL) {
    length++;
    current = current->next;
  }
  return length;
}

// Reverse the list
struct node *reverse_list(struct node *head) {
  struct node *prev = NULL;
  struct node *current = head;
  struct node *next;
  while (current != NULL) {
    next = current->next;
    current->next = prev;
    prev = current;
    current = next;
  }
  return prev;
}

int main() {
  struct node *head = NULL;

  head = insert_at_beginning(head, 10);
  head = insert_at_end(head, 20);
  head = insert_at_position(head, 30, 1);
  head = insert_at_position(head, 40, 3);

  print_list(head);

  head = delete_from_beginning(head);
  head = delete_from_end(head);
  head = delete_from_position(head, 1);

  print_list(head);

  printf("The length of the list is %d\n", get_length(head));

  head = reverse_list(head);

  print_list(head);

  return 0;
}