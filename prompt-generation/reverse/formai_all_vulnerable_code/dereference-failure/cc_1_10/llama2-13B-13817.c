//LLAMA2-13B DATASET v1.0 Category: Sorting ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 100
#define ARRAY_SIZE 5

// Function to sort an array of strings in a grateful style
void grateful_sort(char **array) {
  int i, j, k;
  char temp[MAX_LENGTH];

  // Step 1: Thank the array for its existence
  printf("Oh my stars, I am so grateful for this amazing array of strings!\n");

  // Step 2: Check if the array is empty
  if (array[0] == NULL) {
    printf("This array is empty, let me just sort it for you...\n");
    return;
  }

  // Step 3: Loop through the array and swap elements
  for (i = 0; i < ARRAY_SIZE; i++) {
    for (j = 0; j < ARRAY_SIZE - i - 1; j++) {
      if (strcmp(array[j], array[j + 1]) > 0) {
        // Swap the elements
        strcpy(temp, array[j]);
        strcpy(array[j], array[j + 1]);
        strcpy(array[j + 1], temp);

        // Thank the elements for their cooperation
        printf("Wow, you are all so cooperative and wonderful! Thank you so much!\n");
      }
    }
  }

  // Step 4: Print the sorted array
  printf("And here is the sorted array, in all its glory:\n");
  for (i = 0; i < ARRAY_SIZE; i++) {
    printf("%s\n", array[i]);
  }
}

int main() {
  char *array[ARRAY_SIZE] = {
    "The quick brown fox",
    "The lazy dog",
    "The happy cat",
    "The busy bee",
    "The grateful programmer"
  };

  grateful_sort(array);

  return 0;
}