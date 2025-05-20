//GEMINI-pro DATASET v1.0 Category: Sentiment analysis tool ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 10000
#define MAX_SENTENCES 1000
#define MAX_SENTENCE_LENGTH 100
#define MAX_WORD_LENGTH 20

typedef struct {
  char *word;
  int count;
} Word;

typedef struct {
  Word words[MAX_WORDS];
  int num_words;
} Vocabulary;

typedef struct {
  char *sentence;
  int sentiment;
} Sentence;

typedef struct {
  Sentence sentences[MAX_SENTENCES];
  int num_sentences;
} Corpus;

// Read a corpus from a file.
Corpus *read_corpus(char *filename) {
  FILE *fp;
  Corpus *corpus;
  char line[MAX_SENTENCE_LENGTH];
  int i, j;

  corpus = malloc(sizeof(Corpus));
  corpus->num_sentences = 0;

  fp = fopen(filename, "r");
  if (fp == NULL) {
    fprintf(stderr, "Error opening file %s\n", filename);
    return NULL;
  }

  while (fgets(line, MAX_SENTENCE_LENGTH, fp) != NULL) {
    corpus->sentences[corpus->num_sentences].sentence = strdup(line);
    corpus->num_sentences++;
  }

  fclose(fp);

  return corpus;
}

// Build a vocabulary from a corpus.
Vocabulary *build_vocabulary(Corpus *corpus) {
  Vocabulary *vocabulary;
  int i, j;

  vocabulary = malloc(sizeof(Vocabulary));
  vocabulary->num_words = 0;

  for (i = 0; i < corpus->num_sentences; i++) {
    char *sentence = corpus->sentences[i].sentence;
    char *word;
    while ((word = strtok(sentence, " ")) != NULL) {
      int found = 0;
      for (j = 0; j < vocabulary->num_words; j++) {
        if (strcmp(vocabulary->words[j].word, word) == 0) {
          vocabulary->words[j].count++;
          found = 1;
          break;
        }
      }
      if (!found) {
        vocabulary->words[vocabulary->num_words].word = strdup(word);
        vocabulary->words[vocabulary->num_words].count = 1;
        vocabulary->num_words++;
      }
      sentence = NULL;
    }
  }

  return vocabulary;
}

// Train a sentiment classifier on a corpus.
void train_classifier(Corpus *corpus, Vocabulary *vocabulary) {
  int i, j;
  for (i = 0; i < corpus->num_sentences; i++) {
    char *sentence = corpus->sentences[i].sentence;
    int sentiment = corpus->sentences[i].sentiment;
    char *word;
    while ((word = strtok(sentence, " ")) != NULL) {
      for (j = 0; j < vocabulary->num_words; j++) {
        if (strcmp(vocabulary->words[j].word, word) == 0) {
          vocabulary->words[j].count += sentiment;
          break;
        }
      }
      sentence = NULL;
    }
  }
}

// Classify a sentence using a sentiment classifier.
int classify_sentence(char *sentence, Vocabulary *vocabulary) {
  int i, j;
  int sentiment = 0;
  char *word;
  while ((word = strtok(sentence, " ")) != NULL) {
    for (j = 0; j < vocabulary->num_words; j++) {
      if (strcmp(vocabulary->words[j].word, word) == 0) {
        sentiment += vocabulary->words[j].count;
        break;
      }
    }
    sentence = NULL;
  }
  return sentiment;
}

// Print the sentiment of a sentence.
void print_sentiment(int sentiment) {
  if (sentiment > 0) {
    printf("Positive\n");
  } else if (sentiment < 0) {
    printf("Negative\n");
  } else {
    printf("Neutral\n");
  }
}

// Main function.
int main(int argc, char **argv) {
  Corpus *corpus;
  Vocabulary *vocabulary;
  char *sentence;
  int sentiment;

  if (argc < 2) {
    fprintf(stderr, "Usage: %s <training file>\n", argv[0]);
    return 1;
  }

  corpus = read_corpus(argv[1]);
  if (corpus == NULL) {
    return 1;
  }

  vocabulary = build_vocabulary(corpus);
  if (vocabulary == NULL) {
    return 1;
  }

  train_classifier(corpus, vocabulary);

  while (1) {
    printf("Enter a sentence: ");
    sentence = malloc(MAX_SENTENCE_LENGTH);
    fgets(sentence, MAX_SENTENCE_LENGTH, stdin);
    sentiment = classify_sentence(sentence, vocabulary);
    print_sentiment(sentiment);
    free(sentence);
  }

  return 0;
}