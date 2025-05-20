//GEMINI-pro DATASET v1.0 Category: Text to ASCII art generator ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// function to convert a character to ASCII art
char* char_to_ascii(char c) {
  char *art[] = {
    " _   _   _   _   _  ",
    "| | | | | | | | | | |",
    "| | | | | | | | | | |",
    "| | | | | | | | | | |",
    "|_| |_| |_| |_| |_|",
    "                    ",
    " _____  _      _ _    ",
    "|  __ \| |    | | |  ",
    "| |__) | |    | | |  ",
    "|  ___/| |    | | |  ",
    "| |    | |____| | |__",
    "|_|     \______|_|__|",
    "  _____  _ _            ",
    " |  __ \| | |          ",
    " | |__) | | | __ _ _ __",
    " |  ___/| | |/ _` | '__|",
    " | |    | | | (_| | |   ",
    " |_|    |_|_|\__,_|_|   ",
    "  __  __           _     ",
    " |  \/  |         | |    ",
    " | \  / | ___  _ __| | ___",
    " | |\/| |/ _ \| '__| |/ _ \\",
    " | |  | | (_) | |  | |  __/",
    " |_|  |_|\___/|_|  |_|\___|"
  };

  return art[toupper(c) - 'A'];
}

// function to convert a string to ASCII art
char* string_to_ascii(char *str) {
  int len = strlen(str);
  char *art = malloc(len * 5 + 1);
  for (int i = 0; i < len; i++) {
    strcat(art, char_to_ascii(str[i]));
  }
  return art;
}

int main() {
  // your code goes here
  char *str = "Sherlock Holmes";
  char *art = string_to_ascii(str);

  printf("%s\n", art);

  return 0;
}