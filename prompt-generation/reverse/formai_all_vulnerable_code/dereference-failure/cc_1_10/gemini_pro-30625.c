//GEMINI-pro DATASET v1.0 Category: Text to Morse code conversion ; Style: immersive
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Morse code lookup table
char* morse_table[] = {
  [0] = ".-",   [1] = "-...",  [2] = "-.-.",  [3] = "-..",
  [4] = ".",    [5] = "..-.",  [6] = "--.",   [7] = "....",
  [8] = "..",   [9] = ".---",  [10] = "-.-",   [11] = ".-..",
  [12] = "--",   [13] = "-.",   [14] = "---",   [15] = ".--.",
  [16] = "--.-", [17] = ".-.",   [18] = "...",   [19] = "-",
  [20] = "..-",  [21] = "...-",  [22] = ".--",   [23] = "-..-",
  [24] = "-.--", [25] = "--..",  [26] = "..--",  [27] = ".-.-",
  [28] = "---.", [29] = "----",  [30] = "-----",  [31] = "  "
};

// Convert a character to Morse code
char* char_to_morse(char ch) {
  if (ch >= 'A' && ch <= 'Z') return morse_table[ch - 'A'];
  if (ch >= 'a' && ch <= 'z') return morse_table[ch - 'a' + 26];
  if (ch >= '0' && ch <= '9') return morse_table[ch - '0' + 52];
  if (ch == ' ') return "  ";  // Space
  return "";
}

// Convert a string to Morse code
char* string_to_morse(char* str) {
  int len = strlen(str);
  int i;
  char* morse_str = malloc(len * 6);  // Allocate buffer for Morse code
  strcpy(morse_str, "");
  for (i = 0; i < len; i++) {
    strcat(morse_str, char_to_morse(str[i]));
  }
  return morse_str;
}

// Play Morse code as beeps
void play_morse(char* morse_str) {
  int i;
  int dot_duration = 100;  // Duration of a dot (in milliseconds)
  for (i = 0; i < strlen(morse_str); i++) {
    if (morse_str[i] == '.') {
      // Beep for a dot
      printf(".*");
    } else if (morse_str[i] == '-') {
      // Beep for a dash
      printf("-*");
    } else {
      // Space
      //printf(" ");
    }
    // Delay between characters
    usleep(dot_duration);
  }
  printf("\n");
}

int main() {
  char* text;
  char* morse_str;

  // Get text from user
  printf("Enter your message: ");
  scanf("%s", text);

  // Convert text to Morse code
  morse_str = string_to_morse(text);

  // Print Morse code
  printf("Morse code: %s\n", morse_str);

  // Play Morse code
  play_morse(morse_str);

  return 0;
}