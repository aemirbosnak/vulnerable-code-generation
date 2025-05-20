//GEMINI-pro DATASET v1.0 Category: Text to Morse code conversion ; Style: innovative
#include <stdio.h>
#include <string.h>

// Morse code character map
char *morse_map[] = {
  ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---",
  "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-",
  "..-", "...-", ".--", "-..-", "-.--", "--..", "---.", "----", ".-.-.-",
  "..--..", "---...", "...--", "....-", ".....", "-....", "--...", "---..",
  "----.", "-----"
};

// Convert a character to Morse code
char *to_morse(char c) {
  if (c >= 'a' && c <= 'z') {
    return morse_map[c - 'a'];
  } else if (c >= 'A' && c <= 'Z') {
    return morse_map[c - 'A'];
  } else if (c >= '0' && c <= '9') {
    return morse_map[c - '0' + 26];
  } else {
    return "";
  }
}

// Convert a string to Morse code
char *to_morse_str(char *str) {
  int len = strlen(str);
  char *morse_str = malloc(len * 5 + 1);
  int i, j;
  for (i = 0, j = 0; i < len; i++) {
    char *morse_char = to_morse(str[i]);
    strcpy(morse_str + j, morse_char);
    j += strlen(morse_char);
    morse_str[j++] = ' ';
  }
  morse_str[j] = '\0';
  return morse_str;
}

// Print a string in Morse code
void print_morse(char *str) {
  int len = strlen(str);
  int i;
  for (i = 0; i < len; i++) {
    if (str[i] == '.') {
      printf("·");
    } else if (str[i] == '-') {
      printf("—");
    } else {
      printf(" ");
    }
  }
  printf("\n");
}

int main() {
  char str[] = "Hello World";
  char *morse_str = to_morse_str(str);
  print_morse(morse_str);
  free(morse_str);
  return 0;
}