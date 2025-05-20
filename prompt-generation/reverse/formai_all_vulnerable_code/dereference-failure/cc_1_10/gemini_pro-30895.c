//GEMINI-pro DATASET v1.0 Category: Sentiment analysis tool ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 100
#define MAX_SENTENCES 10

typedef struct {
  char *word;
  int sentiment;
} Word;

typedef struct {
  Word words[MAX_WORDS];
  int num_words;
} Dictionary;

typedef struct {
  char *sentence;
  int sentiment;
} Sentence;

Dictionary dictionary;
Sentence sentences[MAX_SENTENCES];

void load_dictionary() {
  FILE *fp = fopen("dictionary.txt", "r");
  if (fp == NULL) {
    perror("Error opening dictionary file");
    exit(EXIT_FAILURE);
  }

  char line[1024];
  while (fgets(line, sizeof(line), fp) != NULL) {
    char *word = strtok(line, "\t");
    int sentiment = atoi(strtok(NULL, "\n"));

    Word new_word;
    new_word.word = malloc(strlen(word) + 1);
    strcpy(new_word.word, word);
    new_word.sentiment = sentiment;

    dictionary.words[dictionary.num_words++] = new_word;
  }

  fclose(fp);
}

void load_sentences() {
  FILE *fp = fopen("sentences.txt", "r");
  if (fp == NULL) {
    perror("Error opening sentences file");
    exit(EXIT_FAILURE);
  }

  char line[1024];
  int i = 0;
  while (fgets(line, sizeof(line), fp) != NULL) {
    char *sentence = malloc(strlen(line) + 1);
    strcpy(sentence, line);

    Sentence new_sentence;
    new_sentence.sentence = sentence;
    new_sentence.sentiment = 0;

    sentences[i++] = new_sentence;
  }

  fclose(fp);
}

int analyze_sentence(char *sentence) {
  int sentiment = 0;

  char *word = strtok(sentence, " ");
  while (word != NULL) {
    for (int i = 0; i < dictionary.num_words; i++) {
      if (strcmp(word, dictionary.words[i].word) == 0) {
        sentiment += dictionary.words[i].sentiment;
        break;
      }
    }

    word = strtok(NULL, " ");
  }

  return sentiment;
}

void print_sentences() {
  for (int i = 0; i < MAX_SENTENCES; i++) {
    printf("%s\t%d\n", sentences[i].sentence, sentences[i].sentiment);
  }
}

int main() {
  load_dictionary();
  load_sentences();

  for (int i = 0; i < MAX_SENTENCES; i++) {
    sentences[i].sentiment = analyze_sentence(sentences[i].sentence);
  }

  print_sentences();

  return 0;
}