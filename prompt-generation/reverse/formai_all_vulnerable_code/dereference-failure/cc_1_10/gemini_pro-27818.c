//GEMINI-pro DATASET v1.0 Category: Bucket Sort Implementation ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

// Create a bucket
struct bucket {
  int value;
  struct bucket *next;
};

// Create an array of buckets
struct bucket *buckets[MAX_SIZE];

// Insert a value into a bucket
void insert_value(int value) {
  // Get the index of the bucket
  int index = value / MAX_SIZE;

  // Create a new bucket if it doesn't exist
  if (buckets[index] == NULL) {
    buckets[index] = malloc(sizeof(struct bucket));
    buckets[index]->value = value;
    buckets[index]->next = NULL;
  } else {
    // Insert the value into the bucket
    struct bucket *current = buckets[index];
    while (current->next != NULL) {
      current = current->next;
    }
    current->next = malloc(sizeof(struct bucket));
    current->next->value = value;
    current->next->next = NULL;
  }
}

// Sort the values in the buckets
void sort_values() {
  for (int i = 0; i < MAX_SIZE; i++) {
    // Get the current bucket
    struct bucket *current = buckets[i];

    // Sort the values in the bucket
    while (current != NULL) {
      struct bucket *next = current->next;
      while (next != NULL) {
        if (current->value > next->value) {
          // Swap the values
          int temp = current->value;
          current->value = next->value;
          next->value = temp;
        }
        next = next->next;
      }
      current = current->next;
    }
  }
}

// Print the values in the buckets
void print_values() {
  for (int i = 0; i < MAX_SIZE; i++) {
    // Get the current bucket
    struct bucket *current = buckets[i];

    // Print the values in the bucket
    while (current != NULL) {
      printf("%d ", current->value);
      current = current->next;
    }
  }
  printf("\n");
}

// Free the memory allocated for the buckets
void free_buckets() {
  for (int i = 0; i < MAX_SIZE; i++) {
    // Get the current bucket
    struct bucket *current = buckets[i];

    // Free the memory allocated for the bucket
    while (current != NULL) {
      struct bucket *next = current->next;
      free(current);
      current = next;
    }
  }
}

int main() {
  // Insert some values into the buckets
  insert_value(10);
  insert_value(20);
  insert_value(30);
  insert_value(40);
  insert_value(50);
  insert_value(60);
  insert_value(70);
  insert_value(80);
  insert_value(90);
  insert_value(100);

  // Sort the values in the buckets
  sort_values();

  // Print the values in the buckets
  print_values();

  // Free the memory allocated for the buckets
  free_buckets();

  return 0;
}