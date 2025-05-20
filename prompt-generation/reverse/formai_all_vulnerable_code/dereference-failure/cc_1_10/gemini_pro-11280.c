//GEMINI-pro DATASET v1.0 Category: Sentiment analysis tool ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1000
#define MAX_SENTENCES 100

typedef struct {
  char *word;
  int score;
} WordScore;

typedef struct {
  char *sentence;
  int score;
} SentenceScore;

WordScore words[MAX_WORDS];
SentenceScore sentences[MAX_SENTENCES];

int num_words = 0;
int num_sentences = 0;

void load_words(const char *filename) {
  FILE *fp = fopen(filename, "r");
  if (fp == NULL) {
    perror("fopen");
    exit(EXIT_FAILURE);
  }

  char line[1024];
  while (fgets(line, sizeof(line), fp)) {
    char *word = strtok(line, ",");
    char *score = strtok(NULL, ",");

    words[num_words].word = strdup(word);
    words[num_words].score = atoi(score);

    num_words++;
  }

  fclose(fp);
}

void load_sentences(const char *filename) {
  FILE *fp = fopen(filename, "r");
  if (fp == NULL) {
    perror("fopen");
    exit(EXIT_FAILURE);
  }

  char line[1024];
  while (fgets(line, sizeof(line), fp)) {
    sentences[num_sentences].sentence = strdup(line);
    sentences[num_sentences].score = 0;

    num_sentences++;
  }

  fclose(fp);
}

int score_sentence(const char *sentence) {
  int score = 0;

  char *word = strtok(sentence, " ");
  while (word) {
    for (int i = 0; i < num_words; i++) {
      if (strcmp(word, words[i].word) == 0) {
        score += words[i].score;
        break;
      }
    }

    word = strtok(NULL, " ");
  }

  return score;
}

void print_results() {
  for (int i = 0; i < num_sentences; i++) {
    printf("%s: %d\n", sentences[i].sentence, sentences[i].score);
  }
}

int main(int argc, char **argv) {
  if (argc != 3) {
    fprintf(stderr, "Usage: %s <words-file> <sentences-file>\n", argv[0]);
    exit(EXIT_FAILURE);
  }

  load_words(argv[1]);
  load_sentences(argv[2]);

  for (int i = 0; i < num_sentences; i++) {
    sentences[i].score = score_sentence(sentences[i].sentence);
  }

  print_results();

  return EXIT_SUCCESS;
}