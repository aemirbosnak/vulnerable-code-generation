//GEMINI-pro DATASET v1.0 Category: Typing Speed Test ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define BUFFER_SIZE 1024
#define TEST_TIME 60

// Function to get a random string from a file
char *get_random_string(FILE *file) {
  // Get the file size
  fseek(file, 0, SEEK_END);
  long file_size = ftell(file);
  rewind(file);

  // Generate a random number within the file size
  long random_offset = rand() % file_size;

  // Seek to the random position in the file
  fseek(file, random_offset, SEEK_SET);

  // Read the line from the file
  char *line = malloc(BUFFER_SIZE);
  fgets(line, BUFFER_SIZE, file);

  // Remove the newline character from the end of the line
  line[strcspn(line, "\n")] = '\0';

  // Return the line
  return line;
}

// Function to run the typing speed test
void run_test() {
  // Open the file containing the test strings
  FILE *file = fopen("test_strings.txt", "r");
  if (file == NULL) {
    fprintf(stderr, "Error opening file\n");
    exit(EXIT_FAILURE);
  }

  // Get a random string from the file
  char *string = get_random_string(file);

  // Print the string to the console
  printf("%s\n", string);

  // Start the timer
  time_t start_time = time(NULL);

  // Get the user's input
  char *input = malloc(BUFFER_SIZE);
  fgets(input, BUFFER_SIZE, stdin);

  // Stop the timer
  time_t end_time = time(NULL);

  // Calculate the time taken to type the string
  double time_taken = difftime(end_time, start_time);

  // Calculate the typing speed
  int typing_speed = (int)((strlen(string) / time_taken) * 60);

  // Print the typing speed to the console
  printf("Your typing speed is %d words per minute\n", typing_speed);

  // Free the allocated memory
  free(string);
  free(input);
  fclose(file);
}

// Main function
int main() {
  // Seed the random number generator
  srand(time(NULL));

  // Run the typing speed test
  run_test();

  return 0;
}