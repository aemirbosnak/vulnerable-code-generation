//GEMINI-pro DATASET v1.0 Category: Bucket Sort Implementation ; Style: portable
#include <stdlib.h>
#include <stdio.h>

// A linked list node
typedef struct node {
  int data;
  struct node *next;
} node_t;

// Create a new linked list node
node_t *create_node(int data) {
  node_t *node = malloc(sizeof(node_t));
  node->data = data;
  node->next = NULL;
  return node;
}

// Insert a new node into a linked list
void insert_node(node_t **head, int data) {
  node_t *new_node = create_node(data);
  if (*head == NULL) {
    *head = new_node;
  } else {
    node_t *current = *head;
    while (current->next != NULL) {
      current = current->next;
    }
    current->next = new_node;
  }
}

// Print a linked list
void print_list(node_t *head) {
  node_t *current = head;
  while (current != NULL) {
    printf("%d ", current->data);
    current = current->next;
  }
  printf("\n");
}

// Sort an array using bucket sort
void bucket_sort(int *arr, int n) {
  // Create an array of linked lists to store the elements of each bucket
  node_t **buckets = malloc(sizeof(node_t *) * n);
  for (int i = 0; i < n; i++) {
    buckets[i] = NULL;
  }

  // Insert each element of the array into its corresponding bucket
  for (int i = 0; i < n; i++) {
    int bucket_index = arr[i] / n;
    insert_node(&buckets[bucket_index], arr[i]);
  }

  // Sort each bucket using insertion sort
  for (int i = 0; i < n; i++) {
    node_t *head = buckets[i];
    while (head != NULL) {
      node_t *current = head;
      node_t *next = head->next;
      while (next != NULL) {
        if (next->data < current->data) {
          int temp = current->data;
          current->data = next->data;
          next->data = temp;
        }
        current = next;
        next = next->next;
      }
      head = head->next;
    }
  }

  // Concatenate the sorted buckets into a single linked list
  node_t *sorted_list = NULL;
  for (int i = 0; i < n; i++) {
    if (buckets[i] != NULL) {
      if (sorted_list == NULL) {
        sorted_list = buckets[i];
      } else {
        node_t *current = sorted_list;
        while (current->next != NULL) {
          current = current->next;
        }
        current->next = buckets[i];
      }
    }
  }

  // Copy the sorted elements back into the array
  int i = 0;
  node_t *current = sorted_list;
  while (current != NULL) {
    arr[i] = current->data;
    current = current->next;
    i++;
  }
}

int main() {
  int arr[] = {5, 3, 1, 7, 4, 1, 2, 8, 6};
  int n = sizeof(arr) / sizeof(arr[0]);

  printf("Unsorted array: ");
  print_list(NULL);

  bucket_sort(arr, n);

  printf("Sorted array: ");
  print_list(NULL);

  return 0;
}