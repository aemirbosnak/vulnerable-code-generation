//GEMINI-pro DATASET v1.0 Category: Text to Morse code conversion ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

// Morse code characters
char* morse_code[] = {
  ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---",
  "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-",
  "..-", "...-", ".--", "-..-", "-.--", "--..", ".----", "..---", "...--",
  "....-", ".....", "-....", "--...", "---..", "----.", "-----", "|", " "
};

// Morse code character lengths
int morse_code_lengths[] = {
  2, 3, 4, 4, 1, 4, 3, 4, 2, 4,
  3, 4, 2, 2, 3, 4, 4, 3, 3, 1,
  3, 3, 3, 4, 4, 4, 5, 5, 5,
  5, 5, 5, 5, 5, 6, 6, 1, 1
};

// Convert a character to Morse code
char* char_to_morse(char c) {
  if (c >= 'a' && c <= 'z') {
    c = c - 'a' + 'A';
  }
  if (c >= 'A' && c <= 'Z') {
    return morse_code[c - 'A'];
  }
  if (c >= '0' && c <= '9') {
    return morse_code[c - '0' + 26];
  }
  if (c == ' ') {
    return morse_code[36];
  }
  return "";
}

// Convert a string to Morse code
char* string_to_morse(char* str) {
  int len = strlen(str);
  char* morse = malloc(len * 5); // Allocate enough space for the worst case
  int i, j, k;
  for (i = 0, j = 0, k = 0; i < len; i++) {
    char* code = char_to_morse(str[i]);
    int code_len = morse_code_lengths[str[i] - 'A'];
    memcpy(morse + j, code, code_len);
    j += code_len;
    morse[j++] = ' ';
  }
  morse[j] = '\0';
  return morse;
}

// Print the Morse code for a string
void print_morse(char* str) {
  char* morse = string_to_morse(str);
  printf("%s\n", morse);
  free(morse);
}

// Main function
int main(int argc, char** argv) {
  if (argc < 2) {
    printf("Usage: %s <string>\n", argv[0]);
    return 1;
  }

  char* str = argv[1];
  int len = strlen(str);
  if (len > MAX_LINE_LENGTH) {
    printf("Error: String too long (max %d characters)\n", MAX_LINE_LENGTH);
    return 1;
  }

  print_morse(str);

  return 0;
}