//Gemma-7B DATASET v1.0 Category: Text Summarizer ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1000

typedef struct TextSummary {
  char **words;
  int size;
} TextSummary;

TextSummary *createTextSummary(char *text) {
  TextSummary *summary = malloc(sizeof(TextSummary));
  summary->words = malloc(MAX_BUFFER_SIZE * sizeof(char *));
  summary->size = 0;

  char *words = NULL;
  char *buffer = malloc(MAX_BUFFER_SIZE);
  int i = 0;

  while (text[i] != '\0') {
    buffer[i] = text[i];
    i++;

    if (buffer[i - 1] == ' ' && words == NULL) {
      words = buffer;
    } else if (words != NULL) {
      summary->words[summary->size++] = words;
      words = NULL;
    }
  }

  free(buffer);

  return summary;
}

void printTextSummary(TextSummary *summary) {
  for (int i = 0; i < summary->size; i++) {
    printf("%s ", summary->words[i]);
  }
  printf("\n");
}

int main() {
  char *text = "This is a sample text. It has many words. Some words are repeated. The text is long. It has a lot of text.";

  TextSummary *summary = createTextSummary(text);

  printTextSummary(summary);

  free(summary->words);
  free(summary);

  return 0;
}