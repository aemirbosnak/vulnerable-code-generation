//GEMINI-pro DATASET v1.0 Category: Typing Speed Test ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the maximum length of the input string
#define MAX_INPUT_LENGTH 100

// Define the minimum number of characters required for a valid test
#define MIN_CHARACTERS_REQUIRED 10

// Function to generate a random string of characters
char *generate_random_string(int length) {
  char *string = malloc(sizeof(char) * (length + 1));
  for (int i = 0; i < length; i++) {
    string[i] = 'a' + rand() % 26;
  }
  string[length] = '\0';
  return string;
}

// Function to get the user's input
char *get_user_input() {
  char *input = malloc(sizeof(char) * MAX_INPUT_LENGTH);
  printf("Enter the displayed text: ");
  scanf("%s", input);
  return input;
}

// Function to compare the user's input to the generated string
int compare_strings(char *input, char *generated_string) {
  int errors = 0;
  for (int i = 0; i < strlen(generated_string); i++) {
    if (input[i] != generated_string[i]) {
      errors++;
    }
  }
  return errors;
}

// Function to calculate the user's typing speed
int calculate_typing_speed(int characters_typed, int time_taken) {
  return characters_typed / time_taken * 60;
}

// Function to print the results of the test
void print_results(int typing_speed, int errors) {
  printf("Your typing speed is %d words per minute with %d errors.\n", typing_speed, errors);
}

// Main function
int main() {
  // Initialize the random number generator
  srand(time(NULL));

  // Generate a random string of characters
  char *generated_string = generate_random_string(50);

  // Display the generated string to the user
  printf("Type the following text as quickly and accurately as possible:\n");
  printf("%s\n", generated_string);

  // Start the timer
  clock_t start_time = clock();

  // Get the user's input
  char *input = get_user_input();

  // Stop the timer
  clock_t end_time = clock();

  // Calculate the time taken to complete the test
  int time_taken = (end_time - start_time) / CLOCKS_PER_SEC;

  // Calculate the number of characters typed
  int characters_typed = strlen(input);

  // Compare the user's input to the generated string
  int errors = compare_strings(input, generated_string);

  // Calculate the user's typing speed
  int typing_speed = calculate_typing_speed(characters_typed, time_taken);

  // Print the results of the test
  print_results(typing_speed, errors);

  // Free the allocated memory
  free(generated_string);
  free(input);

  return 0;
}