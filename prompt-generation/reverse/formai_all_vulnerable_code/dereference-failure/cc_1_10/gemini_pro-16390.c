//GEMINI-pro DATASET v1.0 Category: Typing Speed Test ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// Define the maximum length of the input string
#define MAX_LENGTH 100

// Define the number of words in the test
#define NUM_WORDS 10

// Define the minimum and maximum typing speeds (in words per minute)
#define MIN_SPEED 20
#define MAX_SPEED 120

// Declare the function to generate a random string
char *generate_string(int length);

// Declare the function to calculate the typing speed
int calculate_speed(int length, int time);

// Declare the function to print the results
void print_results(int speed);

int main() {
  // Seed the random number generator
  srand(time(NULL));

  // Generate a random string
  char *string = generate_string(MAX_LENGTH);

  // Get the current time
  time_t start_time = time(NULL);

  // Get the user's input
  char input[MAX_LENGTH];
  printf("Type the following string as fast as you can:\n%s\n", string);
  scanf("%s", input);

  // Get the current time
  time_t end_time = time(NULL);

  // Calculate the typing speed
  int speed = calculate_speed(strlen(string), end_time - start_time);

  // Print the results
  print_results(speed);

  // Free the allocated memory
  free(string);

  return 0;
}

// Define the function to generate a random string
char *generate_string(int length) {
  // Allocate memory for the string
  char *string = malloc(length + 1);

  // Generate a random string
  for (int i = 0; i < length; i++) {
    string[i] = 'a' + rand() % 26;
  }

  // Add the null terminator
  string[length] = '\0';

  // Return the string
  return string;
}

// Define the function to calculate the typing speed
int calculate_speed(int length, int time) {
  // Calculate the number of words typed per minute
  int speed = (length / 5) * 60 / time;

  // Return the speed
  return speed;
}

// Define the function to print the results
void print_results(int speed) {
  // Print the typing speed
  printf("Your typing speed is %d words per minute.\n", speed);

  // Print a message based on the typing speed
  if (speed < MIN_SPEED) {
    printf("You need to practice more!");
  } else if (speed >= MIN_SPEED && speed < MAX_SPEED) {
    printf("Good job!");
  } else {
    printf("You're a typing machine!");
  }
}