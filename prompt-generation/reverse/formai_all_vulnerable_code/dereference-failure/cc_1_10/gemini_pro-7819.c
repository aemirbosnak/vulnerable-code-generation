//GEMINI-pro DATASET v1.0 Category: Text to ASCII art generator ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum width of the ASCII art
#define MAX_WIDTH 80

// Define the character used to represent the background
#define BACKGROUND_CHAR ' '

// Define the character used to represent the foreground
#define FOREGROUND_CHAR '*'

// Create a function to generate the ASCII art
void generate_ascii_art(char *text, int width) {
  // Calculate the height of the ASCII art
  int height = strlen(text);

  // Create a 2D array to store the ASCII art
  char **ascii_art = malloc(height * sizeof(char *));
  for (int i = 0; i < height; i++) {
    ascii_art[i] = malloc(width * sizeof(char));
  }

  // Fill the 2D array with the background character
  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      ascii_art[i][j] = BACKGROUND_CHAR;
    }
  }

  // Draw the text onto the 2D array
  for (int i = 0; i < height; i++) {
    for (int j = 0; j < strlen(text); j++) {
      ascii_art[i][j] = FOREGROUND_CHAR;
    }
  }

  // Print the ASCII art to the console
  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      printf("%c", ascii_art[i][j]);
    }
    printf("\n");
  }

  // Free the memory allocated for the 2D array
  for (int i = 0; i < height; i++) {
    free(ascii_art[i]);
  }
  free(ascii_art);
}

// Get the user input
char *get_user_input() {
  char *text = NULL;
  size_t len = 0;

  printf("Enter the text you want to convert to ASCII art: ");
  getline(&text, &len, stdin);

  return text;
}

// Get the user input for the width of the ASCII art
int get_user_input_width() {
  int width;

  printf("Enter the width of the ASCII art (max %d): ", MAX_WIDTH);
  scanf("%d", &width);

  return width;
}

// Main function
int main() {
  // Get the user input
  char *text = get_user_input();

  // Get the user input for the width of the ASCII art
  int width = get_user_input_width();

  // Generate the ASCII art
  generate_ascii_art(text, width);

  // Free the memory allocated for the text
  free(text);

  return 0;
}