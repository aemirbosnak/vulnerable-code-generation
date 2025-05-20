//GEMINI-pro DATASET v1.0 Category: Spam Detection System ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_WORDS 1000
#define MAX_DOCS 1000
#define MAX_FEATURES 100

typedef struct {
  char *word;
  int count;
} Word;

typedef struct {
  int doc_id;
  int word_id;
  int count;
} Feature;

typedef struct {
  int num_words;
  int num_docs;
  int num_features;
  Word words[MAX_WORDS];
  Feature features[MAX_FEATURES];
} Dataset;

Dataset dataset;

void load_dataset(char *filename) {
  FILE *fp = fopen(filename, "r");
  if (fp == NULL) {
    perror("Error opening file");
    exit(1);
  }

  char line[1024];
  while (fgets(line, sizeof(line), fp)) {
    char *doc_id_str = strtok(line, " ");
    int doc_id = atoi(doc_id_str);

    char *word_str = strtok(NULL, " ");
    int word_id = -1;
    for (int i = 0; i < dataset.num_words; i++) {
      if (strcmp(dataset.words[i].word, word_str) == 0) {
        word_id = i;
        break;
      }
    }
    if (word_id == -1) {
      word_id = dataset.num_words;
      dataset.words[word_id].word = strdup(word_str);
      dataset.words[word_id].count = 0;
      dataset.num_words++;
    }

    int count = atoi(strtok(NULL, " "));

    Feature feature;
    feature.doc_id = doc_id;
    feature.word_id = word_id;
    feature.count = count;
    dataset.features[dataset.num_features++] = feature;

    dataset.words[word_id].count += count;
  }

  fclose(fp);
}

void train_model() {
  // Calculate the prior probability of each word
  for (int i = 0; i < dataset.num_words; i++) {
    dataset.words[i].count /= dataset.num_features;
  }

  // Calculate the conditional probability of each feature
  for (int i = 0; i < dataset.num_features; i++) {
    Feature feature = dataset.features[i];
    dataset.features[i].count /= dataset.words[feature.word_id].count;
  }
}

double spam_score(int doc_id) {
  double score = 0.0;

  for (int i = 0; i < dataset.num_features; i++) {
    Feature feature = dataset.features[i];
    if (feature.doc_id == doc_id) {
      score += log(feature.count / dataset.words[feature.word_id].count);
    }
  }

  return score;
}

int main(int argc, char *argv[]) {
  if (argc != 3) {
    fprintf(stderr, "Usage: %s <training_file> <test_file>\n", argv[0]);
    exit(1);
  }

  load_dataset(argv[1]);
  train_model();

  FILE *fp = fopen(argv[2], "r");
  if (fp == NULL) {
    perror("Error opening file");
    exit(1);
  }

  char line[1024];
  while (fgets(line, sizeof(line), fp)) {
    int doc_id = atoi(strtok(line, " "));
    double score = spam_score(doc_id);

    printf("%d %f\n", doc_id, score);
  }

  fclose(fp);

  return 0;
}