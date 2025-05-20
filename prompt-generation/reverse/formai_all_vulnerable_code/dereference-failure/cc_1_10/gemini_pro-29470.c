//GEMINI-pro DATASET v1.0 Category: Linked list operations ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>

// Declare the node structure
struct node {
  int data;
  struct node *next;
};

// Declare the linked list structure
struct linked_list {
  struct node *head;
  struct node *tail;
  int size;
};

// Create a new linked list
struct linked_list *create_list() {
  struct linked_list *list = (struct linked_list *)malloc(sizeof(struct linked_list));
  list->head = NULL;
  list->tail = NULL;
  list->size = 0;
  return list;
}

// Insert a node at the beginning of the linked list
void insert_at_beginning(struct linked_list *list, int data) {
  struct node *new_node = (struct node *)malloc(sizeof(struct node));
  new_node->data = data;
  new_node->next = list->head;
  list->head = new_node;
  if (list->tail == NULL) {
    list->tail = new_node;
  }
  list->size++;
}

// Insert a node at the end of the linked list
void insert_at_end(struct linked_list *list, int data) {
  struct node *new_node = (struct node *)malloc(sizeof(struct node));
  new_node->data = data;
  new_node->next = NULL;
  if (list->tail == NULL) {
    list->head = new_node;
    list->tail = new_node;
  } else {
    list->tail->next = new_node;
    list->tail = new_node;
  }
  list->size++;
}

// Insert a node at a given position in the linked list
void insert_at_position(struct linked_list *list, int data, int position) {
  if (position == 0) {
    insert_at_beginning(list, data);
  } else if (position == list->size) {
    insert_at_end(list, data);
  } else {
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = data;
    struct node *current_node = list->head;
    for (int i = 0; i < position - 1; i++) {
      current_node = current_node->next;
    }
    new_node->next = current_node->next;
    current_node->next = new_node;
    list->size++;
  }
}

// Delete a node from the beginning of the linked list
void delete_from_beginning(struct linked_list *list) {
  if (list->head == NULL) {
    return;
  }
  struct node *current_node = list->head;
  list->head = current_node->next;
  if (list->head == NULL) {
    list->tail = NULL;
  }
  free(current_node);
  list->size--;
}

// Delete a node from the end of the linked list
void delete_from_end(struct linked_list *list) {
  if (list->tail == NULL) {
    return;
  }
  struct node *current_node = list->head;
  struct node *previous_node = NULL;
  while (current_node->next != NULL) {
    previous_node = current_node;
    current_node = current_node->next;
  }
  if (previous_node == NULL) {
    list->head = NULL;
    list->tail = NULL;
  } else {
    previous_node->next = NULL;
    list->tail = previous_node;
  }
  free(current_node);
  list->size--;
}

// Delete a node from a given position in the linked list
void delete_from_position(struct linked_list *list, int position) {
  if (position == 0) {
    delete_from_beginning(list);
  } else if (position == list->size - 1) {
    delete_from_end(list);
  } else {
    struct node *current_node = list->head;
    struct node *previous_node = NULL;
    for (int i = 0; i < position; i++) {
      previous_node = current_node;
      current_node = current_node->next;
    }
    previous_node->next = current_node->next;
    if (current_node == list->tail) {
      list->tail = previous_node;
    }
    free(current_node);
    list->size--;
  }
}

// Search for a node in the linked list
int search_node(struct linked_list *list, int data) {
  struct node *current_node = list->head;
  int index = 0;
  while (current_node != NULL) {
    if (current_node->data == data) {
      return index;
    }
    current_node = current_node->next;
    index++;
  }
  return -1;
}

// Print the linked list
void print_list(struct linked_list *list) {
  struct node *current_node = list->head;
  while (current_node != NULL) {
    printf("%d ", current_node->data);
    current_node = current_node->next;
  }
  printf("\n");
}

// Free the linked list
void free_list(struct linked_list *list) {
  struct node *current_node = list->head;
  while (current_node != NULL) {
    struct node *next_node = current_node->next;
    free(current_node);
    current_node = next_node;
  }
  free(list);
}

// Main function
int main() {
  struct linked_list *list = create_list();

  // Insert some nodes into the linked list
  insert_at_beginning(list, 1);
  insert_at_end(list, 2);
  insert_at_position(list, 3, 1);

  // Print the linked list
  printf("Linked list: ");
  print_list(list);

  // Search for a node in the linked list
  int search_result = search_node(list, 3);
  if (search_result == -1) {
    printf("Node not found\n");
  } else {
    printf("Node found at position %d\n", search_result);
  }

  // Delete a node from the beginning of the linked list
  delete_from_beginning(list);

  // Delete a node from the end of the linked list
  delete_from_end(list);

  // Delete a node from a given position in the linked list
  delete_from_position(list, 1);

  // Print the linked list
  printf("Linked list after deletions: ");
  print_list(list);

  // Free the linked list
  free_list(list);

  return 0;
}