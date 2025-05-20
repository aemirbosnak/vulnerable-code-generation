//Gemma-7B DATASET v1.0 Category: Text Summarizer ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

typedef struct TextSummary {
  char **sentences;
  int sentence_count;
  int total_words;
} TextSummary;

TextSummary *summarize_text(char *text) {
  TextSummary *summary = malloc(sizeof(TextSummary));
  summary->sentences = malloc(sizeof(char *) * MAX_BUFFER_SIZE);
  summary->sentence_count = 0;
  summary->total_words = 0;

  char *buffer = malloc(MAX_BUFFER_SIZE);
  int i = 0;
  int sentence_start = 0;
  int word_count = 0;

  for (i = 0; text[i] != '\0'; i++) {
    if (text[i] == '.' || text[i] == '!' || text[i] == '?') {
      summary->sentences[summary->sentence_count++] = buffer;
      buffer = malloc(MAX_BUFFER_SIZE);
      sentence_start = i + 1;
      word_count = 0;
    } else {
      word_count++;
    }
  }

  summary->sentences[summary->sentence_count++] = buffer;
  summary->total_words = word_count;

  return summary;
}

int main() {
  char *text = "This is a sample text. It has many sentences. Some sentences are long. Others are short. The text also has some punctuation marks.";

  TextSummary *summary = summarize_text(text);

  printf("Total sentences: %d\n", summary->sentence_count);
  printf("Total words: %d\n", summary->total_words);

  for (int i = 0; i < summary->sentence_count; i++) {
    printf("Sentence %d: %s\n", i + 1, summary->sentences[i]);
  }

  free(summary->sentences);
  free(summary);

  return 0;
}