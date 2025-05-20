//GEMINI-pro DATASET v1.0 Category: Text Summarizer ; Style: calm
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SENTENCES 100
#define MAX_WORDS_PER_SENTENCE 100
#define MAX_WORD_LENGTH 100

typedef struct {
  char **sentences;
  int num_sentences;
  int num_words;
} Summary;

Summary *create_summary(char *text) {
  Summary *summary = malloc(sizeof(Summary));
  summary->sentences = malloc(MAX_SENTENCES * sizeof(char *));
  summary->num_sentences = 0;
  summary->num_words = 0;

  char *token = strtok(text, ".");
  while (token != NULL) {
    summary->sentences[summary->num_sentences] = malloc(MAX_WORDS_PER_SENTENCE * sizeof(char *));
    summary->num_sentences++;

    char *word = strtok(token, " ");
    while (word != NULL) {
      summary->sentences[summary->num_sentences - 1][summary->num_words] = malloc(MAX_WORD_LENGTH * sizeof(char));
      strcpy(summary->sentences[summary->num_sentences - 1][summary->num_words], word);
      summary->num_words++;

      word = strtok(NULL, " ");
    }

    token = strtok(NULL, ".");
  }

  return summary;
}

void free_summary(Summary *summary) {
  for (int i = 0; i < summary->num_sentences; i++) {
    for (int j = 0; j < summary->num_words; j++) {
      free(summary->sentences[i][j]);
    }
    free(summary->sentences[i]);
  }
  free(summary->sentences);
  free(summary);
}

char *summarize(Summary *summary, double percentage) {
  int num_sentences_to_summarize = (int)(summary->num_sentences * percentage);
  char *summary_text = malloc(MAX_WORD_LENGTH * sizeof(char));
  strcpy(summary_text, "");

  for (int i = 0; i < num_sentences_to_summarize; i++) {
    for (int j = 0; j < summary->num_words; j++) {
      strcat(summary_text, summary->sentences[i][j]);
      strcat(summary_text, " ");
    }
    strcat(summary_text, ". ");
  }

  return summary_text;
}

int main() {
  char *text = "This is a sample text to summarize. This text is about summarizing text. Summarizing text is a task that involves reducing a longer text into a shorter, more concise version. The goal of summarization is to capture the main points of the original text while omitting unnecessary details. Summarizing text can be done manually or automatically. Automatic text summarization is a challenging task that requires a deep understanding of natural language processing. However, there are a number of different automatic text summarization techniques that can be used to produce high-quality summaries. These techniques can be classified into two main categories: extraction-based techniques and abstraction-based techniques. Extraction-based techniques extract the most important sentences from the original text, while abstraction-based techniques generate new sentences that summarize the main points of the text.";

  Summary *summary = create_summary(text);
  char *summarized_text = summarize(summary, 0.5);

  printf("%s", summarized_text);

  free_summary(summary);
  free(summarized_text);

  return 0;
}