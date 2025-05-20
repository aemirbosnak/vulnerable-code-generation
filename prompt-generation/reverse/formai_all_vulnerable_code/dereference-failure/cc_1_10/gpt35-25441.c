//FormAI DATASET v1.0 Category: HTML beautifier ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void beautify(char *filename) {
  char *temp_filename = "temp.txt";
  FILE *input_file, *output_file;
  int c, i, indent = 0;

  input_file = fopen(filename, "r");
  if (input_file == NULL) {
    printf("Could not open %s\n", filename);
    return;
  }

  output_file = fopen(temp_filename, "w");
  if (output_file == NULL) {
    printf("Could not open %s\n", temp_filename);
    return;
  }

  while ((c = fgetc(input_file)) != EOF) {
    if (c == '<') {
      fputc(c, output_file);
      c = fgetc(input_file);
      if (c == '/') {
        indent -= 2;
        fputc('\n', output_file);
        for (i = 0; i < indent; i++) {
          fputc(' ', output_file);
        }
        fputc(c, output_file);
      } else {
        fputc('\n', output_file);
        for (i = 0; i <= indent; i++) {
          fputc(' ', output_file);
        }
        indent += 2;
        fputc(c, output_file);
      }
    } else if (c == '>') {
      fputc(c, output_file);
      fputc('\n', output_file);
      for (i = 0; i < indent; i++) {
        fputc(' ', output_file);
      }
    } else {
      fputc(c, output_file);
    }
  }

  fclose(input_file);
  fclose(output_file);

  remove(filename);
  rename(temp_filename, filename);
}

int main() {
  char filename[100];
  printf("Enter the HTML filename: ");
  scanf("%s", filename);
  beautify(filename);
  printf("Beautification complete!\n");
  return 0;
}