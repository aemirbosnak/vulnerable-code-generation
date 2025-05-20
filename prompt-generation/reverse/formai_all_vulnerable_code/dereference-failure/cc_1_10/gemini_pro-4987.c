//GEMINI-pro DATASET v1.0 Category: Text to Morse code conversion ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the Morse code table
char *morse_code_table[] = {
  ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---",
  "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-",
  "..-", "...-", ".--", "-..-", "-.--", "--..", "-....", "--...", "---..",
  "----.", "-----", ".-.-.-", "--..--", "...-..-", "....-.", ".....-",
  "-....-", "-..-.", "-.--.", "-....-", "-.--.-", ".-.-.-"
};

// Convert a character to Morse code
char *char_to_morse(char c) {
  if (c >= 'a' && c <= 'z') {
    c = c - 'a' + 'A';
  }
  if (c >= 'A' && c <= 'Z') {
    return morse_code_table[c - 'A'];
  }
  if (c >= '0' && c <= '9') {
    return morse_code_table[c - '0' + 26];
  }
  if (c == ' ') {
    return " ";
  }
  return NULL;
}

// Convert a string to Morse code
char *str_to_morse(char *str) {
  int len = strlen(str);
  char *morse_code = malloc(len * 5 + 1);
  int i;
  int j;
  char *c;
  for (i = 0; i < len; i++) {
    c = char_to_morse(str[i]);
    if (c == NULL) {
      morse_code[0] = '\0';
      return morse_code;
    }
    for (j = 0; j < strlen(c); j++) {
      morse_code[i * 5 + j] = c[j];
    }
    morse_code[i * 5 + j] = ' ';
  }
  morse_code[len * 5] = '\0';
  return morse_code;
}

// Print the Morse code for a string
void print_morse_code(char *morse_code) {
  printf("%s\n", morse_code);
}

// Main function
int main() {
  char *str = "HELLO WORLD";
  char *morse_code = str_to_morse(str);
  print_morse_code(morse_code);
  free(morse_code);
  return 0;
}