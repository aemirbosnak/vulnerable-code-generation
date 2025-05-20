//GEMINI-pro DATASET v1.0 Category: Memory management ; Style: modular
#include <stdio.h>
#include <stdlib.h>

// Module 1: Memory allocation and deallocation
void *allocate_memory(size_t size) {
  void *ptr = malloc(size);
  if (ptr == NULL) {
    fprintf(stderr, "Error: malloc() failed\n");
    exit(EXIT_FAILURE);
  }
  return ptr;
}

void deallocate_memory(void *ptr) {
  if (ptr != NULL) {
    free(ptr);
  }
}

// Module 2: Dynamic array
typedef struct {
  int *data;
  size_t size;
  size_t capacity;
} dynamic_array;

dynamic_array *create_dynamic_array(size_t initial_capacity) {
  dynamic_array *array = allocate_memory(sizeof(dynamic_array));
  array->data = allocate_memory(initial_capacity * sizeof(int));
  array->size = 0;
  array->capacity = initial_capacity;
  return array;
}

void destroy_dynamic_array(dynamic_array *array) {
  deallocate_memory(array->data);
  deallocate_memory(array);
}

void push_back(dynamic_array *array, int value) {
  if (array->size == array->capacity) {
    array->capacity *= 2;
    array->data = realloc(array->data, array->capacity * sizeof(int));
  }
  array->data[array->size++] = value;
}

int pop_back(dynamic_array *array) {
  if (array->size == 0) {
    return 0;
  }
  return array->data[--array->size];
}

// Module 3: Linked list
typedef struct node {
  int data;
  struct node *next;
} node;

node *create_linked_list(int data) {
  node *head = allocate_memory(sizeof(node));
  head->data = data;
  head->next = NULL;
  return head;
}

void insert_node(node **head, int data) {
  node *new_node = create_linked_list(data);
  new_node->next = *head;
  *head = new_node;
}

void delete_node(node **head, int data) {
  node *current = *head;
  node *previous = NULL;
  while (current != NULL) {
    if (current->data == data) {
      if (previous == NULL) {
        *head = current->next;
      } else {
        previous->next = current->next;
      }
      deallocate_memory(current);
      return;
    }
    previous = current;
    current = current->next;
  }
}

void print_linked_list(node *head) {
  while (head != NULL) {
    printf("%d ", head->data);
    head = head->next;
  }
  printf("\n");
}

int main() {
  // Example usage of the memory management modules

  // Allocate memory for a dynamic array
  dynamic_array *array = create_dynamic_array(10);

  // Push some values into the array
  for (int i = 0; i < 10; i++) {
    push_back(array, i);
  }

  // Print the array
  printf("Dynamic array: ");
  for (int i = 0; i < array->size; i++) {
    printf("%d ", array->data[i]);
  }
  printf("\n");

  // Pop a value from the array
  int popped_value = pop_back(array);
  printf("Popped value: %d\n", popped_value);

  // Deallocate the array
  destroy_dynamic_array(array);

  // Create a linked list
  node *head = create_linked_list(10);
  insert_node(&head, 20);
  insert_node(&head, 30);

  // Print the linked list
  printf("Linked list: ");
  print_linked_list(head);

  // Delete a node from the linked list
  delete_node(&head, 20);

  // Print the linked list again
  printf("Linked list after deleting node: ");
  print_linked_list(head);

  // Deallocate the linked list
  while (head != NULL) {
    node *next = head->next;
    deallocate_memory(head);
    head = next;
  }

  return 0;
}