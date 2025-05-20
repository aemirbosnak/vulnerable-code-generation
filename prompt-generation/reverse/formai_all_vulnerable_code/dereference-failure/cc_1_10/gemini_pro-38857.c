//GEMINI-pro DATASET v1.0 Category: Text to Morse code conversion ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct {
  char *letter;
  char *morse;
} morse_code;

// Create an array of morse code pairs
morse_code morse_table[] = {
  {"A", ".-"},
  {"B", "-..."},
  {"C", "-.-."},
  {"D", "-.."},
  {"E", "."},
  {"F", "..-."},
  {"G", "--."},
  {"H", "...."},
  {"I", ".."},
  {"J", ".---"},
  {"K", "-.-"},
  {"L", ".-.."},
  {"M", "--"},
  {"N", "-."},
  {"O", "---"},
  {"P", ".--."},
  {"Q", "--.-"},
  {"R", ".-."},
  {"S", "..."},
  {"T", "-"},
  {"U", "..-"},
  {"V", "...-"},
  {"W", ".--"},
  {"X", "-..-"},
  {"Y", "-.--"},
  {"Z", "--.."},
  {"1", ".----"},
  {"2", "..---"},
  {"3", "...--"},
  {"4", "....-"},
  {"5", "....."},
  {"6", "-...."},
  {"7", "--..."},
  {"8", "---.."},
  {"9", "----."},
  {"0", "-----"},
  {" ", " "}  // Space is represented by a single space character
};

// Convert a character to Morse code
char *char_to_morse(char c) {
  // Convert the character to uppercase
  c = toupper(c);

  // Find the corresponding Morse code pair in the table
  for (int i = 0; i < sizeof(morse_table) / sizeof(morse_code); i++) {
    if (morse_table[i].letter[0] == c) {
      return morse_table[i].morse;
    }
  }

  // Not found
  return NULL;
}

// Convert a string to Morse code
char *string_to_morse(char *str) {
  // Allocate memory for the Morse code string
  char *morse = malloc(strlen(str) * 4 + 1);  // 4 characters per letter plus 1 for the null terminator

  // Convert each character to Morse code and append it to the Morse code string
  int pos = 0;
  for (int i = 0; i < strlen(str); i++) {
    char *morse_code = char_to_morse(str[i]);
    if (morse_code != NULL) {
      strcat(morse, morse_code);
      pos += strlen(morse_code);
      morse[pos++] = ' ';  // Add a space between characters
    }
  }

  // Add a null terminator to the end of the string
  morse[pos] = '\0';

  // Return the Morse code string
  return morse;
}

int main() {
  // Get the text from the user
  char text[100];
  printf("Enter text to convert to Morse code: ");
  gets(text);

  // Convert the text to Morse code
  char *morse_code = string_to_morse(text);

  // Print the Morse code
  printf("Morse code: %s\n", morse_code);

  // Free the memory allocated for the Morse code string
  free(morse_code);

  return 0;
}