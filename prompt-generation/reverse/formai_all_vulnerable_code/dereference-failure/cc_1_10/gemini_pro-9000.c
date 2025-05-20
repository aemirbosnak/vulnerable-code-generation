//GEMINI-pro DATASET v1.0 Category: Hexadecimal Converter ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>

// Linus Torvalds style, baby!

// Oh, and by the way, I know what you're thinking.
// You're thinking, "Linus Torvalds would never use a function called 'convert_hex_to_dec()'."
// And you're right. He wouldn't. But I'm not Linus Torvalds. I'm just a humble programmer trying to make my way in the world.
// So, if you don't like the name of my function, tough cookies.

int convert_hex_to_dec(char *hex_string) {
  int dec_value = 0;
  int len = strlen(hex_string);

  for (int i = 0; i < len; i++) {
    char c = hex_string[i];
    int value;

    if (c >= '0' && c <= '9') {
      value = c - '0';
    } else if (c >= 'a' && c <= 'f') {
      value = c - 'a' + 10;
    } else if (c >= 'A' && c <= 'F') {
      value = c - 'A' + 10;
    } else {
      printf("Invalid hexadecimal character: %c\n", c);
      return -1;
    }

    dec_value = dec_value * 16 + value;
  }

  return dec_value;
}

int main(int argc, char **argv) {
  if (argc != 2) {
    printf("Usage: %s <hexadecimal string>\n", argv[0]);
    return 1;
  }

  char *hex_string = argv[1];
  int dec_value = convert_hex_to_dec(hex_string);

  if (dec_value == -1) {
    return 1;
  }

  printf("%s (hex) = %d (dec)\n", hex_string, dec_value);

  return 0;
}