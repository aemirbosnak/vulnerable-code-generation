//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

/* Node struct for linked list */
typedef struct Node {
  int value;
  struct Node *next;
} Node;

/* Linked List struct */
typedef struct LinkedList {
  Node *head;
  pthread_mutex_t lock; // mutex lock for thread safety
} LinkedList;

/* Function to add a value to the linked list */
void add_value(LinkedList *list, int value) {
  Node *new_node = malloc(sizeof(Node));
  new_node->value = value;
  new_node->next = NULL;
  
  pthread_mutex_lock(&list->lock); // lock the list
  
  Node *current = list->head;
  if (current == NULL) {
    list->head = new_node;
  } else {
    while (current->next != NULL) {
      current = current->next;
    }
    current->next = new_node;
  }
  
  pthread_mutex_unlock(&list->lock); // unlock the list
}

/* Function to print the values in the linked list */
void print_list(LinkedList *list) {
  pthread_mutex_lock(&list->lock); // lock the list
  
  Node *current = list->head;
  printf("List Values: ");
  while (current != NULL) {
    printf("%d ", current->value);
    current = current->next;
  }
  printf("\n");
  
  pthread_mutex_unlock(&list->lock); // unlock the list
}

/* Main function */
int main() {
  LinkedList list = {NULL, PTHREAD_MUTEX_INITIALIZER}; // initialize the list and lock
  pthread_t threads[10]; // array of threads for adding values to the list
  
  for (int i = 0; i < 10; i++) {
    pthread_create(&threads[i], NULL, (void *)add_value, &list); // create threads to add values to the list
  }

  for (int i = 0; i < 10; i++) {
    pthread_join(threads[i], NULL); // wait for threads to complete
  }

  print_list(&list); // print the final list
  
  return 0;
}