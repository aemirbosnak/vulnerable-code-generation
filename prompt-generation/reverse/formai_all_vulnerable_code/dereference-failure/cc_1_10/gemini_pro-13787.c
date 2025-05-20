//GEMINI-pro DATASET v1.0 Category: Typing Speed Test ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define TEXT_LENGTH 1000

// Function to generate random text
char *generate_text(int length) {
  char *text = malloc(length + 1);
  for (int i = 0; i < length; i++) {
    text[i] = 'a' + rand() % 26;
  }
  text[length] = '\0';
  return text;
}

// Function to get the accuracy of the user's input
int get_accuracy(char *input, char *text) {
  int length = strlen(text);
  int correct_count = 0;
  for (int i = 0; i < length; i++) {
    if (input[i] == text[i]) {
      correct_count++;
    }
  }
  return (correct_count * 100) / length;
}

// Function to get the speed of the user's input
int get_speed(char *input, char *text) {
  int length = strlen(text);
  time_t start_time = time(NULL);
  while (*input != '\0') {
    input++;
  }
  time_t end_time = time(NULL);
  return (length * 60) / (end_time - start_time);
}

// Function to print the results of the typing test
void print_results(int accuracy, int speed) {
  printf("\nYour typing speed is %d words per minute with %d%% accuracy.\n", speed, accuracy);
}

// Main function
int main() {
  // Generate random text
  char *text = generate_text(TEXT_LENGTH);

  // Get the user's input
  char input[TEXT_LENGTH + 1];
  printf("Start typing the following text:\n%s\n", text);
  scanf("%s", input);

  // Calculate the accuracy and speed of the user's input
  int accuracy = get_accuracy(input, text);
  int speed = get_speed(input, text);

  // Print the results of the typing test
  print_results(accuracy, speed);

  // Free the allocated memory
  free(text);

  return 0;
}