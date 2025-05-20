//FormAI DATASET v1.0 Category: Data mining ; Style: introspective
#include <stdio.h>
#include <stdlib.h>

// A linked list node to store the data
struct Node {
  int data;
  struct Node* next;
};

// The function to perform data mining on the linked list
void data_mining(struct Node* head) {
  int max = head->data; // Initialize max as the first element
  int min = head->data; // Initialize min as the first element
  int sum = 0; // Initialize sum as 0
  int count = 0; // Initialize the count as 0

  struct Node* current = head;

  // Find the maximum, minimum, sum and count of nodes in the list
  while(current != NULL) {
    if(current->data > max)
      max = current->data;
    if(current->data < min)
      min = current->data;

    sum += current->data;
    count++;

    current = current->next;
  }

  // Compute the average of the elements in the list
  double average = (double)sum / count;

  // Print the results
  printf("Max: %d\n", max);
  printf("Min: %d\n", min);
  printf("Sum: %d\n", sum);
  printf("Count: %d\n", count);
  printf("Average: %.2f\n", average);
}

int main(void) {
  // Create a linked list with 5 nodes
  struct Node* head = NULL;
  struct Node* second = NULL;
  struct Node* third = NULL;
  struct Node* fourth = NULL;
  struct Node* fifth = NULL;

  head = (struct Node*)malloc(sizeof(struct Node));
  second = (struct Node*)malloc(sizeof(struct Node));
  third = (struct Node*)malloc(sizeof(struct Node));
  fourth = (struct Node*)malloc(sizeof(struct Node));
  fifth = (struct Node*)malloc(sizeof(struct Node));

  head->data = 10;
  head->next = second;

  second->data = 20;
  second->next = third;

  third->data = 30;
  third->next = fourth;

  fourth->data = 40;
  fourth->next = fifth;

  fifth->data = 50;
  fifth->next = NULL;

  // Call the data mining function on the linked list
  data_mining(head);

  // Free memory
  free(head);
  free(second);
  free(third);
  free(fourth);
  free(fifth);

  return 0;
}