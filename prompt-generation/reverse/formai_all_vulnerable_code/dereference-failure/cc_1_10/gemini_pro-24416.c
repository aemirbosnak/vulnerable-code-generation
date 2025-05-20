//GEMINI-pro DATASET v1.0 Category: Text to Morse code conversion ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the Morse code table
char *morse_code_table[] = {
  ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.",
  "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--..", ".----", "..---", "...--", "....-",
  ".....", "-....", "--...", "---..", "----.", "-----"
};

// Define the alphabet table
char *alphabet_table[] = {
  "A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O", "P", "Q", "R", "S", "T", "U",
  "V", "W", "X", "Y", "Z", "0", "1", "2", "3", "4", "5", "6", "7", "8", "9"
};

// Function to convert a character to Morse code
char *char_to_morse(char character) {
  int index = -1;

  // Find the index of the character in the alphabet table
  for (int i = 0; i < 26; i++) {
    if (character == alphabet_table[i][0]) {
      index = i;
      break;
    }
  }

  // If the character is not in the alphabet table, return an empty string
  if (index == -1) {
    return "";
  }

  // Return the Morse code for the character
  return morse_code_table[index];
}

// Function to convert a string to Morse code
char *string_to_morse(char *string) {
  char *morse_code = malloc(strlen(string) * 5);
  int index = 0;

  // Convert each character in the string to Morse code
  for (int i = 0; i < strlen(string); i++) {
    char *morse_code_character = char_to_morse(string[i]);
    strcat(morse_code, morse_code_character);
    index += strlen(morse_code_character) + 1;
  }

  // Return the Morse code for the string
  return morse_code;
}

// Function to convert Morse code to a character
char morse_to_char(char *morse_code) {
  int index = -1;

  // Find the index of the Morse code in the Morse code table
  for (int i = 0; i < 36; i++) {
    if (strcmp(morse_code, morse_code_table[i]) == 0) {
      index = i;
      break;
    }
  }

  // If the Morse code is not in the Morse code table, return a null character
  if (index == -1) {
    return '\0';
  }

  // Return the character for the Morse code
  return alphabet_table[index][0];
}

// Function to convert Morse code to a string
char *morse_to_string(char *morse_code) {
  char *string = malloc(strlen(morse_code) / 5);
  int index = 0;

  // Convert each character in the Morse code to a character
  for (int i = 0; i < strlen(morse_code); i += 5) {
    char *morse_code_character = strndup(morse_code + i, 5);
    char character = morse_to_char(morse_code_character);
    strncat(string, &character, 1);
    index++;
  }

  // Return the string for the Morse code
  return string;
}

// Main function
int main() {
  // Get the input string from the user
  char *input_string = malloc(100);
  printf("Enter a string to convert to Morse code: ");
  scanf("%s", input_string);

  // Convert the string to Morse code
  char *morse_code = string_to_morse(input_string);

  // Print the Morse code
  printf("Morse code: %s\n", morse_code);

  // Convert the Morse code to a string
  char *output_string = morse_to_string(morse_code);

  // Print the string
  printf("String: %s\n", output_string);

  // Free the allocated memory
  free(input_string);
  free(morse_code);
  free(output_string);

  return 0;
}