//FormAI DATASET v1.0 Category: HTML beautifier ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

bool is_whitespace(char c) {
  return c == ' ' || c == '\t' || c == '\n' || c == '\r';
}

void beautify_html(char* filename) {
  FILE* fp = fopen(filename, "r");
  if (fp == NULL) {
    printf("Error: file %s does not exist.\n", filename);
    return;
  }

  // Get the length of the file
  fseek(fp, 0L, SEEK_END);
  long length = ftell(fp);
  fseek(fp, 0L, SEEK_SET);

  char* buffer = (char*) malloc(length);
  fread(buffer, length, 1, fp);

  int indent_level = 0;
  bool inside_tag = false;
  char* current_pos = buffer;
  char* tag_start_pos = NULL;
  char* tag_end_pos = NULL;

  while (*current_pos) {
    if (!inside_tag) {
      if (*current_pos == '<') {
        if (*(current_pos + 1) == '/') indent_level--;
        for (int i = 0; i < indent_level; i++) printf("  ");
        printf("%c", *current_pos);
        if (*(current_pos + 1) != '/') indent_level++;
        inside_tag = true;
        tag_start_pos = current_pos;
      }
      else {
        printf("%c", *current_pos);
      }
    }
    else {
      if (*current_pos == '>') {
        printf("%c\n", *current_pos);
        inside_tag = false;
        tag_end_pos = current_pos;
        if (*(tag_start_pos + 1) != '/') printf("\n");
        if (tag_end_pos - tag_start_pos <= 1) continue;
        if (*(tag_start_pos + 1) == '/') indent_level--;
      }
      else {
        if (is_whitespace(*current_pos) && is_whitespace(*(current_pos - 1))) continue;
        printf("%c", *current_pos);
      }
    }
    current_pos++;
  }

  fclose(fp);
  free(buffer);
}

int main(int argc, char* argv[]) {
  if (argc < 2) {
    printf("Usage: beautify-html <filename>\n");
    return 1;
  }
  beautify_html(argv[1]);
  return 0;
}