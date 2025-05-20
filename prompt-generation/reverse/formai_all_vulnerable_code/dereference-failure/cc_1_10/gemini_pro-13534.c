//GEMINI-pro DATASET v1.0 Category: Text to ASCII art generator ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum width and height of the ASCII art
#define MAX_WIDTH 100
#define MAX_HEIGHT 100

// Define the characters used to create the ASCII art
char characters[] = " .,-~:;=!*#$%@";

// Function to convert a text string to ASCII art
void text_to_ascii(char* text, int width, int height) {
  // Allocate memory for the ASCII art
  char* ascii_art = malloc(width * height * sizeof(char));

  // Initialize the ASCII art with spaces
  memset(ascii_art, ' ', width * height);

  // Loop through each character in the text
  int i = 0;
  int x = 0;
  int y = 0;
  while (text[i] != '\0') {
    // Get the ASCII value of the character
    int ascii_value = (int)text[i];

    // Calculate the index of the character in the characters array
    int index = (ascii_value - 32) / 8;

    // Set the character in the ASCII art
    ascii_art[y * width + x] = characters[index];

    // Increment the x and y coordinates
    x++;
    if (x >= width) {
      x = 0;
      y++;
    }

    // Increment the character index
    i++;
  }

  // Print the ASCII art
  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      printf("%c", ascii_art[i * width + j]);
    }
    printf("\n");
  }

  // Free the memory allocated for the ASCII art
  free(ascii_art);
}

// Main function
int main() {
  // Get the text to convert to ASCII art
  char* text = "Peace";

  // Get the width and height of the ASCII art
  int width = strlen(text);
  int height = 10;

  // Convert the text to ASCII art
  text_to_ascii(text, width, height);

  return 0;
}