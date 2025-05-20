//GEMINI-pro DATASET v1.0 Category: Text Summarizer ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * Reads a line from the standard input and returns it.
 *
 */
char *read_line(void) {
  char *line = malloc(1024);
  int len = 0;
  int ch;

  while ((ch = getchar()) != '\n' && ch != EOF) {
    line[len++] = ch;
  }

  line[len] = '\0';
  return line;
}

/*
 * Tokenizes a line into an array of strings.
 *
 */
char **tokenize(char *line) {
  char **tokens = malloc(1024 * sizeof(char *));
  int num_tokens = 0;
  char *token = strtok(line, " ");

  while (token != NULL) {
    tokens[num_tokens++] = token;
    token = strtok(NULL, " ");
  }

  tokens[num_tokens] = NULL;
  return tokens;
}

/*
 * Summarizes a text.
 *
 */
void summarize(char *text) {
  char **sentences = malloc(1024 * sizeof(char *));
  int num_sentences = 0;
  char *sentence = strtok(text, ".");

  while (sentence != NULL) {
    sentences[num_sentences++] = sentence;
    sentence = strtok(NULL, ".");
  }

  sentences[num_sentences] = NULL;

  for (int i = 0; i < num_sentences; i++) {
    char **tokens = tokenize(sentences[i]);
    int num_tokens = 0;
    char *token = tokens[num_tokens++];

    while (token != NULL) {
      printf("%s ", token);
      token = tokens[num_tokens++];
    }

    printf("\n");
  }
}

int main(void) {
  char *text = read_line();
  summarize(text);
  return 0;
}