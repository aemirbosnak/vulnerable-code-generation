//GEMINI-pro DATASET v1.0 Category: Text Summarizer ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SENTENCES 100
#define MAX_WORDS 100

typedef struct {
  char *word;
  int count;
} word_t;

typedef struct {
  char *sentence;
  int word_count;
  word_t *words;
} sentence_t;

typedef struct {
  int sentence_count;
  sentence_t *sentences;
} text_t;

text_t *new_text() {
  text_t *text = malloc(sizeof(text_t));
  text->sentence_count = 0;
  text->sentences = NULL;
  return text;
}

void free_text(text_t *text) {
  for (int i = 0; i < text->sentence_count; i++) {
    free(text->sentences[i].sentence);
    for (int j = 0; j < text->sentences[i].word_count; j++) {
      free(text->sentences[i].words[j].word);
    }
    free(text->sentences[i].words);
  }
  free(text->sentences);
  free(text);
}

sentence_t *new_sentence(char *sentence) {
  sentence_t *sent = malloc(sizeof(sentence_t));
  sent->sentence = strdup(sentence);
  sent->word_count = 0;
  sent->words = NULL;
  return sent;
}

void free_sentence(sentence_t *sent) {
  free(sent->sentence);
  for (int i = 0; i < sent->word_count; i++) {
    free(sent->words[i].word);
  }
  free(sent->words);
  free(sent);
}

word_t *new_word(char *word) {
  word_t *w = malloc(sizeof(word_t));
  w->word = strdup(word);
  w->count = 0;
  return w;
}

void free_word(word_t *w) {
  free(w->word);
  free(w);
}

void add_sentence(text_t *text, char *sentence) {
  text->sentences = realloc(text->sentences, sizeof(sentence_t) * (text->sentence_count + 1));
  text->sentences[text->sentence_count++] = *new_sentence(sentence);
}

void add_word(sentence_t *sent, char *word) {
  sent->words = realloc(sent->words, sizeof(word_t) * (sent->word_count + 1));
  sent->words[sent->word_count++] = *new_word(word);
}

void count_words(text_t *text) {
  for (int i = 0; i < text->sentence_count; i++) {
    char *sentence = text->sentences[i].sentence;
    char *word;
    while ((word = strtok(sentence, " ,.\"!?()[]:;"))) {
      int found = 0;
      for (int j = 0; j < text->sentences[i].word_count; j++) {
        if (strcmp(text->sentences[i].words[j].word, word) == 0) {
          text->sentences[i].words[j].count++;
          found = 1;
          break;
        }
      }
      if (!found) {
        add_word(&text->sentences[i], word);
      }
      sentence = NULL;
    }
  }
}

void sort_words(sentence_t *sent) {
  for (int i = 0; i < sent->word_count; i++) {
    for (int j = i + 1; j < sent->word_count; j++) {
      if (sent->words[i].count < sent->words[j].count) {
        word_t temp = sent->words[i];
        sent->words[i] = sent->words[j];
        sent->words[j] = temp;
      }
    }
  }
}

void print_summary(text_t *text) {
  for (int i = 0; i < text->sentence_count; i++) {
    sort_words(&text->sentences[i]);
    printf("%s", text->sentences[i].sentence);
  }
}

int main() {
  text_t *text = new_text();
  //TODO: Read the text from a file
  add_sentence(text, "This is a test of the text summarizer.");
  add_sentence(text, "The text summarizer is a program that takes a text as input and outputs a summary of the text.");
  add_sentence(text, "The summary is a shorter version of the text that contains the most important information.");
  count_words(text);
  print_summary(text);
  free_text(text);
  return 0;
}