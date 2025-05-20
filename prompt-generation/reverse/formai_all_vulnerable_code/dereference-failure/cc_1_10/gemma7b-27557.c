//Gemma-7B DATASET v1.0 Category: Text Summarizer ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

typedef struct TextSummarizer {
  char *buffer;
  int size;
  int position;
} TextSummarizer;

TextSummarizer *createTextSummarizer() {
  TextSummarizer *summarizer = malloc(sizeof(TextSummarizer));
  summarizer->buffer = malloc(MAX_BUFFER_SIZE);
  summarizer->size = MAX_BUFFER_SIZE;
  summarizer->position = 0;
  return summarizer;
}

void addToTextSummarizer(TextSummarizer *summarizer, char *text) {
  int textLength = strlen(text);
  if (textLength + summarizer->position >= summarizer->size) {
    summarizer->buffer = realloc(summarizer->buffer, summarizer->size * 2);
    summarizer->size *= 2;
  }
  memcpy(summarizer->buffer + summarizer->position, text, textLength);
  summarizer->position += textLength;
}

char *getTextSummarizer(TextSummarizer *summarizer) {
  int summaryLength = summarizer->position;
  char *summary = malloc(summaryLength);
  memcpy(summary, summarizer->buffer, summaryLength);
  return summary;
}

int main() {
  TextSummarizer *summarizer = createTextSummarizer();
  addToTextSummarizer(summarizer, "This is a sample text.");
  addToTextSummarizer(summarizer, "It is a long text.");
  addToTextSummarizer(summarizer, "The text summarizer is working.");

  char *summary = getTextSummarizer(summarizer);
  printf("%s", summary);

  free(summary);
  free(summarizer->buffer);
  free(summarizer);

  return 0;
}