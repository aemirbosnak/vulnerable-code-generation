//GEMINI-pro DATASET v1.0 Category: Typing Speed Test ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random string of a given length
char *generate_random_string(int length) {
  char *random_string = malloc(sizeof(char) * (length + 1));
  
  for (int i = 0; i < length; i++) {
    random_string[i] = 'a' + rand() % 26;
  }
  
  random_string[length] = '\0';
  return random_string;
}

// Function to test the user's typing speed
void typing_speed_test() {
  // Generate a random string of length 100
  char *random_string = generate_random_string(100);
  
  // Start the timer
  clock_t start_time = clock();
  
  // Prompt the user to start typing
  printf("Start typing the following string:\n%s\n", random_string);
  
  // Get the user's input
  char input[101];
  scanf("%s", input);
  
  // Stop the timer
  clock_t end_time = clock();
  
  // Calculate the time taken in seconds
  double time_taken = (double)(end_time - start_time) / CLOCKS_PER_SEC;
  
  // Calculate the typing speed in words per minute
  int words_per_minute = (int)((100 / 5) / time_taken * 60);
  
  // Print the typing speed
  printf("Your typing speed is %d words per minute.\n", words_per_minute);
  
  // Free the allocated memory
  free(random_string);
}

int main() {
  // Set the random seed
  srand(time(NULL));
  
  // Start the typing speed test
  typing_speed_test();
  
  return 0;
}