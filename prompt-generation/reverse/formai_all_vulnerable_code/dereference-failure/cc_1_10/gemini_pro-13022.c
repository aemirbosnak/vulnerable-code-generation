//GEMINI-pro DATASET v1.0 Category: RAM usage monitor ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <sys/resource.h>
#include <time.h>

void trackMemoryUsage()  {
  struct rusage usage;
  getrusage(RUSAGE_SELF, &usage);
  printf("Resident Set Size: %.2f MB\n", usage.ru_maxrss / 1024.0);
  printf("Integral Shared Memory Size: %.2f MB\n", usage.ru_ixrss / 1024.0);
}

int main()  {
  printf("\nWelcome to the RAM Monitor! Let's watch your memory dance!\n");
  
  // Allocate a large array to munch on some RAM
  long int arraySize = 10000000;
  int* myArray = (int*) malloc(arraySize * sizeof(int));

  // Show the initial memory usage
  printf("\n[Initial]\n");
  trackMemoryUsage();

  // Populate the array with some random numbers
  srand(time(NULL));
  for (long int i = 0; i < arraySize; i++) {
    myArray[i] = rand();
  }

  // Check the memory usage after populating the array
  printf("\n[After Populating Array]\n");
  trackMemoryUsage();

  // Let's play a memory-hungry game!
  int rounds = 10;
  for (int i = 0; i < rounds; i++) {
    printf("\n[Round %d]\n", i + 1);

    // Allocate a new array in each round
    long int newSize = arraySize + (rand() % 1000000);
    int* newArray = (int*) malloc(newSize * sizeof(int));

    // Copy elements from the old array to the new one
    for (long int j = 0; j < arraySize; j++) {
      newArray[j] = myArray[j];
    }

    // Free the old array
    free(myArray);

    // Reassign the pointer to the new array
    myArray = newArray;

    // Update the array size
    arraySize = newSize;

    // Show the memory usage after each round
    printf("\n[End of Round]\n");
    trackMemoryUsage();
  }

  // Free the final array
  free(myArray);

  printf("\nThanks for playing! Your RAM has had a workout!\n");
  return 0;
}