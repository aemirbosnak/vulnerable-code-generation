//GEMINI-pro DATASET v1.0 Category: User Input Sanitizer ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Initialize a dictionary of funny phrases to use as error messages
char *error_messages[] = {
  "Oh no, you've made a boo-boo!",
  "Your input is as dry as a desert without a cactus!",
  "You're barking up the wrong tree with that input!",
  "Your input is more confusing than a Rubik's cube!",
  "You've got a case of the Monday blues with that input!",
  "Your input is like a lost puppy: it doesn't know where it's going!",
  "You're using more vowels than a drunken karaoke singer!",
  "Your input is as jumbled as a bag of marbles!",
  "You've got more typos than a blind typist!",
  "Your input is like a bad joke: it's not funny and it doesn't make sense!"
};

// Get a random error message from the dictionary
char *get_random_error_message() {
  int random_index = rand() % (sizeof(error_messages) / sizeof(char *));
  return error_messages[random_index];
}

// Sanitize user input by checking for invalid characters and replacing them with funny symbols
char *sanitize_input(char *input) {
  char *sanitized_input = malloc(strlen(input) + 1);
  strcpy(sanitized_input, input);

  for (int i = 0; i < strlen(sanitized_input); i++) {
    char current_char = sanitized_input[i];

    if (!isalnum(current_char)) {
      switch (current_char) {
        case ' ':
          sanitized_input[i] = '_';
          break;
        case ',':
          sanitized_input[i] = '*';
          break;
        case '.':
          sanitized_input[i] = '!';
          break;
        case '?':
          sanitized_input[i] = '~';
          break;
        case '!':
          sanitized_input[i] = '^';
          break;
        default:
          sanitized_input[i] = '#';
          break;
      }
    }
  }

  return sanitized_input;
}

int main() {
  // Set up a loop to continuously prompt the user for input
  while (1) {
    printf("Enter some funny input: ");

    // Get the user's input
    char input[100];
    fgets(input, sizeof(input), stdin);

    // Sanitize the user's input
    char *sanitized_input = sanitize_input(input);

    // Display the sanitized input with a funny error message
    if (strlen(sanitized_input) == 0) {
      printf("%s\n", get_random_error_message());
    } else {
      printf("Your funny sanitized input: %s\n", sanitized_input);
    }

    // Free the allocated memory for the sanitized input
    free(sanitized_input);
  }

  return 0;
}