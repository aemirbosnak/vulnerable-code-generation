//Gemma-7B DATASET v1.0 Category: Text Summarizer ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

typedef struct TextSummarizer {
  char *buffer;
  int size;
  int position;
  char **lines;
  int numLines;
} TextSummarizer;

TextSummarizer *createTextSummarizer() {
  TextSummarizer *summarizer = malloc(sizeof(TextSummarizer));
  summarizer->buffer = malloc(MAX_BUFFER_SIZE);
  summarizer->size = MAX_BUFFER_SIZE;
  summarizer->position = 0;
  summarizer->lines = NULL;
  summarizer->numLines = 0;
  return summarizer;
}

void addTextToSummarizer(TextSummarizer *summarizer, char *text) {
  int textLength = strlen(text);
  if (summarizer->position + textLength >= summarizer->size) {
    summarizer->buffer = realloc(summarizer->buffer, summarizer->size * 2);
    summarizer->size *= 2;
  }
  memcpy(summarizer->buffer + summarizer->position, text, textLength);
  summarizer->position += textLength;
  summarizer->numLines++;
}

char **getTextLinesFromSummarizer(TextSummarizer *summarizer) {
  char **lines = malloc(summarizer->numLines * sizeof(char *));
  for (int i = 0; i < summarizer->numLines; i++) {
    lines[i] = strdup(summarizer->buffer + summarizer->position - (summarizer->numLines - i) * MAX_BUFFER_SIZE);
  }
  return lines;
}

int main() {
  TextSummarizer *summarizer = createTextSummarizer();
  addTextToSummarizer(summarizer, "This is a sample text.");
  addTextToSummarizer(summarizer, "It has multiple lines.");
  addTextToSummarizer(summarizer, "Each line is stored separately.");

  char **lines = getTextLinesFromSummarizer(summarizer);
  for (int i = 0; lines[i] != NULL; i++) {
    printf("%s\n", lines[i]);
  }

  free(lines);
  free(summarizer);

  return 0;
}