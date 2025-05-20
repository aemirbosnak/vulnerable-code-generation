//GEMINI-pro DATASET v1.0 Category: Typing Speed Test ; Style: surrealist
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main() {
  // Initialize the random number generator
  srand(time(NULL));

  // Create an array of 100 random words
  char *words[100];
  for (int i = 0; i < 100; i++) {
    // Generate a random word of length 5 to 10 characters
    int length = rand() % 6 + 5;
    words[i] = malloc(length + 1);
    for (int j = 0; j < length; j++) {
      words[i][j] = 'a' + rand() % 26;
    }
    words[i][length] = '\0';
  }

  // Print the instructions to the user
  printf("Welcome to the surrealist typing speed test!\n");
  printf("You will be given 100 random words to type.\n");
  printf("Try to type as quickly and accurately as possible.\n");
  printf("Your speed will be measured in words per minute.\n");

  // Start the timer
  clock_t start = clock();

  // Get the user's input
  char input[100];
  for (int i = 0; i < 100; i++) {
    printf("%s ", words[i]);
    scanf("%s", input);
  }

  // Stop the timer
  clock_t end = clock();

  // Calculate the user's speed
  double time_taken = (double)(end - start) / CLOCKS_PER_SEC;
  double speed = 100 / time_taken;

  // Print the user's speed
  printf("Your speed is %f words per minute.\n", speed);

  // Free the memory allocated for the words
  for (int i = 0; i < 100; i++) {
    free(words[i]);
  }

  return 0;
}