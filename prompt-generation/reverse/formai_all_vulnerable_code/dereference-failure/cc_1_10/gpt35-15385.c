//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int main() {
  printf("Welcome to the C Internet Speed Test Application!\n\n");
  
  // Ask user for input
  char input[20];
  printf("Please enter the size of the test data in MB (e.g. 50): ");
  fgets(input, 20, stdin);
  int testSize = atoi(input);

  // Check for valid input
  if (testSize <= 0) {
    printf("Invalid test size. Please enter a positive integer.\n");
    return 1;
  }

  // Generate test data
  char* testData = (char*) malloc(sizeof(char) * 1024 * 1024 * testSize);
  
  // Start timer
  clock_t start = clock();

  // Perform test
  for (int i = 0; i < 1024 * 1024 * testSize; i++) {
    testData[i] = 'a';
  }

  // Stop timer
  clock_t end = clock();

  // Calculate results
  double totalTime = (double)(end - start) / CLOCKS_PER_SEC;
  double speed = (double) testSize / totalTime;

  // Display results
  printf("\nTest complete!\n");
  printf("Data size: %d MB\n", testSize);
  printf("Time taken: %.2lf seconds\n", totalTime);
  printf("Internet speed: %.2lf megabytes per second\n", speed);

  // Free memory
  free(testData);

  return 0;
}