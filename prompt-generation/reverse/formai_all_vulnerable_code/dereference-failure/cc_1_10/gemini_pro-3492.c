//GEMINI-pro DATASET v1.0 Category: Sentiment analysis tool ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1000
#define MAX_SENTENCES 100

typedef struct {
  char *word;
  int polarity;
} Word;

typedef struct {
  char *sentence;
  int polarity;
} Sentence;

Word words[MAX_WORDS];
Sentence sentences[MAX_SENTENCES];

int num_words = 0;
int num_sentences = 0;

void load_words() {
  FILE *fp = fopen("words.txt", "r");
  if (fp == NULL) {
    fprintf(stderr, "Error opening words file\n");
    exit(1);
  }

  char line[1024];
  while (fgets(line, sizeof(line), fp)) {
    char *word = strtok(line, "\t");
    int polarity = atoi(strtok(NULL, "\t"));

    words[num_words].word = strdup(word);
    words[num_words].polarity = polarity;

    num_words++;
  }

  fclose(fp);
}

void load_sentences() {
  FILE *fp = fopen("sentences.txt", "r");
  if (fp == NULL) {
    fprintf(stderr, "Error opening sentences file\n");
    exit(1);
  }

  char line[1024];
  while (fgets(line, sizeof(line), fp)) {
    char *sentence = strtok(line, "\t");
    int polarity = atoi(strtok(NULL, "\t"));

    sentences[num_sentences].sentence = strdup(sentence);
    sentences[num_sentences].polarity = polarity;

    num_sentences++;
  }

  fclose(fp);
}

int analyze_sentence(char *sentence) {
  int polarity = 0;

  char *token = strtok(sentence, " ");
  while (token != NULL) {
    int i;
    for (i = 0; i < num_words; i++) {
      if (strcmp(token, words[i].word) == 0) {
        polarity += words[i].polarity;
        break;
      }
    }

    token = strtok(NULL, " ");
  }

  return polarity;
}

int main() {
  load_words();
  load_sentences();

  char input[1024];
  while (1) {
    printf("Enter a sentence to analyze (or type 'quit' to quit): ");
    fgets(input, sizeof(input), stdin);

    if (strcmp(input, "quit\n") == 0) {
      break;
    }

    int polarity = analyze_sentence(input);

    if (polarity > 0) {
      printf("Positive sentiment\n");
    } else if (polarity < 0) {
      printf("Negative sentiment\n");
    } else {
      printf("Neutral sentiment\n");
    }
  }

  return 0;
}