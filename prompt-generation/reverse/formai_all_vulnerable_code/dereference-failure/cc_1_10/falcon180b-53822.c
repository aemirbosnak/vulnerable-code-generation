//Falcon-180B DATASET v1.0 Category: Text to ASCII art generator ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 80
#define CHAR_SET_SIZE 94
#define CHAR_SET "!\"#$%&'()*+,-./:;<=>?@[\\]^_`{|}~"

int main(int argc, char *argv[]) {
  if (argc!= 2) {
    printf("Usage: %s <input_file>\n", argv[0]);
    return 1;
  }

  FILE *input_file = fopen(argv[1], "r");
  if (input_file == NULL) {
    printf("Error opening input file.\n");
    return 1;
  }

  char *input_buffer = NULL;
  size_t input_buffer_size = 0;
  ssize_t read_size;

  while ((read_size = getline(&input_buffer, &input_buffer_size, input_file))!= -1) {
    char *line = input_buffer;
    int line_length = strlen(line);
    int ascii_art_length = (int) (line_length * 2.5 + 0.5);

    char *ascii_art = malloc(ascii_art_length + 1);
    if (ascii_art == NULL) {
      printf("Error allocating memory for ASCII art.\n");
      free(input_buffer);
      fclose(input_file);
      return 1;
    }

    int ascii_art_index = 0;
    int char_set_index = 0;

    while (line_length--) {
      char c = tolower(*line);
      if (isalpha(c)) {
        ascii_art[ascii_art_index++] = CHAR_SET[char_set_index];
        char_set_index = (char_set_index + 1) % CHAR_SET_SIZE;
      } else {
        ascii_art[ascii_art_index++] = c;
      }
    }

    ascii_art[ascii_art_index] = '\0';

    printf("%s\n", ascii_art);

    free(input_buffer);
    free(ascii_art);
  }

  fclose(input_file);
  return 0;
}