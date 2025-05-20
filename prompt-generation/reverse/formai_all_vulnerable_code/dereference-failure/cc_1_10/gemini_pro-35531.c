//GEMINI-pro DATASET v1.0 Category: Memory management ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>

// Define the maximum number of elements in the array
#define MAX_SIZE 100

// Define the structure of a node in the linked list
typedef struct node {
  int data;
  struct node *next;
} node_t;

// Create a new node with the given data
node_t *create_node(int data) {
  node_t *new_node = (node_t *)malloc(sizeof(node_t));
  new_node->data = data;
  new_node->next = NULL;
  return new_node;
}

// Insert a new node at the beginning of the linked list
node_t *insert_at_beginning(node_t *head, int data) {
  node_t *new_node = create_node(data);
  new_node->next = head;
  return new_node;
}

// Insert a new node at the end of the linked list
node_t *insert_at_end(node_t *head, int data) {
  node_t *new_node = create_node(data);
  if (head == NULL) {
    return new_node;
  }
  node_t *current = head;
  while (current->next != NULL) {
    current = current->next;
  }
  current->next = new_node;
  return head;
}

// Insert a new node at the given position in the linked list
node_t *insert_at_position(node_t *head, int data, int position) {
  if (position == 0) {
    return insert_at_beginning(head, data);
  }
  node_t *new_node = create_node(data);
  node_t *current = head;
  int count = 0;
  while (current != NULL && count < position - 1) {
    current = current->next;
    count++;
  }
  if (current == NULL) {
    return head;
  }
  new_node->next = current->next;
  current->next = new_node;
  return head;
}

// Delete the node at the beginning of the linked list
node_t *delete_at_beginning(node_t *head) {
  if (head == NULL) {
    return NULL;
  }
  node_t *temp = head;
  head = head->next;
  free(temp);
  return head;
}

// Delete the node at the end of the linked list
node_t *delete_at_end(node_t *head) {
  if (head == NULL) {
    return NULL;
  }
  if (head->next == NULL) {
    free(head);
    return NULL;
  }
  node_t *current = head;
  while (current->next->next != NULL) {
    current = current->next;
  }
  free(current->next);
  current->next = NULL;
  return head;
}

// Delete the node at the given position in the linked list
node_t *delete_at_position(node_t *head, int position) {
  if (position == 0) {
    return delete_at_beginning(head);
  }
  node_t *current = head;
  int count = 0;
  while (current != NULL && count < position - 1) {
    current = current->next;
    count++;
  }
  if (current == NULL || current->next == NULL) {
    return head;
  }
  node_t *temp = current->next;
  current->next = temp->next;
  free(temp);
  return head;
}

// Print the linked list
void print_linked_list(node_t *head) {
  node_t *current = head;
  while (current != NULL) {
    printf("%d ", current->data);
    current = current->next;
  }
  printf("\n");
}

// Get the size of the linked list
int get_size(node_t *head) {
  int size = 0;
  node_t *current = head;
  while (current != NULL) {
    size++;
    current = current->next;
  }
  return size;
}

// Reverse the linked list
node_t *reverse_linked_list(node_t *head) {
  node_t *prev = NULL;
  node_t *current = head;
  node_t *next;
  while (current != NULL) {
    next = current->next;
    current->next = prev;
    prev = current;
    current = next;
  }
  return prev;
}

// Create a new array with the given size
int *create_array(int size) {
  int *array = (int *)malloc(sizeof(int) * size);
  return array;
}

// Get the element at the given index in the array
int get_element(int *array, int index) {
  return array[index];
}

// Set the element at the given index in the array to the given value
void set_element(int *array, int index, int value) {
  array[index] = value;
}

// Print the array
void print_array(int *array, int size) {
  for (int i = 0; i < size; i++) {
    printf("%d ", array[i]);
  }
  printf("\n");
}

// Get the size of the array
int get_array_size(int *array) {
  return MAX_SIZE;
}

// Reverse the array
void reverse_array(int *array, int size) {
  for (int i = 0; i < size / 2; i++) {
    int temp = array[i];
    array[i] = array[size - i - 1];
    array[size - i - 1] = temp;
  }
}

// Main function
int main() {
  // Create a linked list
  node_t *head = NULL;
  head = insert_at_beginning(head, 1);
  head = insert_at_end(head, 2);
  head = insert_at_position(head, 3, 1);

  // Print the linked list
  printf("Linked list: ");
  print_linked_list(head);

  // Get the size of the linked list
  int size = get_size(head);
  printf("Size of the linked list: %d\n", size);

  // Reverse the linked list
  head = reverse_linked_list(head);

  // Print the reversed linked list
  printf("Reversed linked list: ");
  print_linked_list(head);

  // Create an array
  int *array = create_array(MAX_SIZE);

  // Set the elements in the array
  for (int i = 0; i < MAX_SIZE; i++) {
    set_element(array, i, i + 1);
  }

  // Print the array
  printf("Array: ");
  print_array(array, MAX_SIZE);

  // Get the size of the array
  size = get_array_size(array);
  printf("Size of the array: %d\n", size);

  // Reverse the array
  reverse_array(array, MAX_SIZE);

  // Print the reversed array
  printf("Reversed array: ");
  print_array(array, MAX_SIZE);

  // Free the memory allocated to the linked list
  while (head != NULL) {
    head = delete_at_beginning(head);
  }

  // Free the memory allocated to the array
  free(array);

  return 0;
}