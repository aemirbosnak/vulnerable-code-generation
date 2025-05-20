//GEMINI-pro DATASET v1.0 Category: Text Summarizer ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SENTENCES 100
#define MAX_WORDS 100

typedef struct {
  char *word;
  int count;
} Word;

typedef struct {
  char *sentence;
  int word_count;
  Word *words;
} Sentence;

typedef struct {
  int sentence_count;
  Sentence *sentences;
} Text;

Text *create_text(char *input) {
  Text *text = malloc(sizeof(Text));
  text->sentence_count = 0;
  text->sentences = NULL;

  char *sentence = strtok(input, ".");
  while (sentence != NULL) {
    Sentence *new_sentence = malloc(sizeof(Sentence));
    new_sentence->sentence = sentence;
    new_sentence->word_count = 0;
    new_sentence->words = NULL;

    char *word = strtok(sentence, " ");
    while (word != NULL) {
      Word *new_word = malloc(sizeof(Word));
      new_word->word = word;
      new_word->count = 1;

      new_sentence->words = realloc(new_sentence->words, (new_sentence->word_count + 1) * sizeof(Word));
      new_sentence->words[new_sentence->word_count] = *new_word;
      new_sentence->word_count++;

      word = strtok(NULL, " ");
    }

    text->sentences = realloc(text->sentences, (text->sentence_count + 1) * sizeof(Sentence));
    text->sentences[text->sentence_count] = *new_sentence;
    text->sentence_count++;

    sentence = strtok(NULL, ".");
  }

  return text;
}

void free_text(Text *text) {
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

int main() {
  char *input = "This is a sample text. This text is about text summarization. Text summarization is the process of reducing a text to a shorter version while retaining the key points. This can be done manually or automatically. Automatic text summarization is a challenging task, but it has many applications. For example, it can be used to create summaries of news articles, scientific papers, and other long documents.";

  Text *text = create_text(input);

  // Find the most frequent words in the text.
  Word *most_frequent_words[MAX_WORDS];
  for (int i = 0; i < MAX_WORDS; i++) {
    most_frequent_words[i] = NULL;
  }

  for (int i = 0; i < text->sentence_count; i++) {
    for (int j = 0; j < text->sentences[i].word_count; j++) {
      int found = 0;
      for (int k = 0; k < MAX_WORDS; k++) {
        if (most_frequent_words[k] != NULL && strcmp(most_frequent_words[k]->word, text->sentences[i].words[j].word) == 0) {
          most_frequent_words[k]->count++;
          found = 1;
          break;
        }
      }
      if (!found) {
        for (int k = 0; k < MAX_WORDS; k++) {
          if (most_frequent_words[k] == NULL) {
            most_frequent_words[k] = malloc(sizeof(Word));
            most_frequent_words[k]->word = text->sentences[i].words[j].word;
            most_frequent_words[k]->count = 1;
            break;
          }
        }
      }
    }
  }

  // Sort the most frequent words by their count.
  for (int i = 0; i < MAX_WORDS - 1; i++) {
    for (int j = i + 1; j < MAX_WORDS; j++) {
      if (most_frequent_words[i] != NULL && most_frequent_words[j] != NULL && most_frequent_words[i]->count < most_frequent_words[j]->count) {
        Word *temp = most_frequent_words[i];
        most_frequent_words[i] = most_frequent_words[j];
        most_frequent_words[j] = temp;
      }
    }
  }

  // Generate the summary.
  char *summary = malloc(1000);
  int summary_length = 0;
  for (int i = 0; i < MAX_WORDS; i++) {
    if (most_frequent_words[i] != NULL) {
      summary_length += strlen(most_frequent_words[i]->word) + 1;
      if (summary_length < 1000) {
        strcat(summary, most_frequent_words[i]->word);
        strcat(summary, " ");
      }
    }
  }

  // Print the summary.
  printf("%s", summary);

  // Free the memory.
  free_text(text);
  for (int i = 0; i < MAX_WORDS; i++) {
    if (most_frequent_words[i] != NULL) {
      free(most_frequent_words[i]->word);
      free(most_frequent_words[i]);
    }
  }
  free(summary);

  return 0;
}