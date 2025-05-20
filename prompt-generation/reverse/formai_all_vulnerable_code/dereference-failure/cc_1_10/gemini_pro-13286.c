//GEMINI-pro DATASET v1.0 Category: HTML beautifier ; Style: puzzling
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct
{
  char *input;
  int input_len;
  char *output;
  int output_len;
  int indent_level;
  int max_indent_level;
} html_beautifier_t;

void html_beautifier_init(html_beautifier_t *self, char *input, int input_len)
{
  self->input = input;
  self->input_len = input_len;
  self->output = malloc(input_len * 2);
  self->output_len = 0;
  self->indent_level = 0;
  self->max_indent_level = 4;
}

void html_beautifier_free(html_beautifier_t *self)
{
  free(self->output);
}

void html_beautifier_process_char(html_beautifier_t *self, char c)
{
  if (c == '<')
  {
    self->indent_level++;
    self->output[self->output_len++] = c;
  }
  else if (c == '>')
  {
    self->indent_level--;
    self->output[self->output_len++] = c;
  }
  else if (c == '\n')
  {
    self->output[self->output_len++] = '\n';
    for (int i = 0; i < self->indent_level; i++)
    {
      self->output[self->output_len++] = ' ';
    }
  }
  else
  {
    self->output[self->output_len++] = c;
  }
}

void html_beautifier_process_input(html_beautifier_t *self)
{
  for (int i = 0; i < self->input_len; i++)
  {
    html_beautifier_process_char(self, self->input[i]);
  }
}

int main(int argc, char **argv)
{
  if (argc != 2)
  {
    printf("Usage: %s <html_input>", argv[0]);
    return 1;
  }
  char *input = argv[1];
  int input_len = strlen(input);
  html_beautifier_t beautifier;
  html_beautifier_init(&beautifier, input, input_len);
  html_beautifier_process_input(&beautifier);
  html_beautifier_free(&beautifier);
  printf("%s", beautifier.output);
  return 0;
}