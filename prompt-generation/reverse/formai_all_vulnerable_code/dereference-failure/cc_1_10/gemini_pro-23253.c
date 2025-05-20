//GEMINI-pro DATASET v1.0 Category: Sentiment analysis tool ; Style: energetic
#include <stdio.h>
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

typedef struct {
  Sentence sentences[MAX_SENTENCES];
  int num_sentences;
} Document;

Dictionary dictionary;
Document document;

void load_dictionary() {
  FILE *fp = fopen("dictionary.txt", "r");
  if (fp == NULL) {
    perror("Error opening dictionary file");
    return;
  }

  while (!feof(fp)) {
    char line[1024];
    fgets(line, sizeof(line), fp);

    char *word = strtok(line, " ");
    char *sentiment = strtok(NULL, " ");

    if (word != NULL && sentiment != NULL) {
      dictionary.words[dictionary.num_words].word = strdup(word);
      dictionary.words[dictionary.num_words].sentiment = atoi(sentiment);
      dictionary.num_words++;
    }
  }

  fclose(fp);
}

void load_document() {
  FILE *fp = fopen("document.txt", "r");
  if (fp == NULL) {
    perror("Error opening document file");
    return;
  }

  while (!feof(fp)) {
    char line[1024];
    fgets(line, sizeof(line), fp);

    char *sentence = strtok(line, ".");

    if (sentence != NULL) {
      document.sentences[document.num_sentences].sentence = strdup(sentence);
      document.sentences[document.num_sentences].sentiment = 0;
      document.num_sentences++;
    }
  }

  fclose(fp);
}

void analyze_document() {
  for (int i = 0; i < document.num_sentences; i++) {
    char *sentence = document.sentences[i].sentence;

    char *word = strtok(sentence, " ");

    while (word != NULL) {
      for (int j = 0; j < dictionary.num_words; j++) {
        if (strcmp(word, dictionary.words[j].word) == 0) {
          document.sentences[i].sentiment += dictionary.words[j].sentiment;
        }
      }

      word = strtok(NULL, " ");
    }
  }
}

void print_results() {
  for (int i = 0; i < document.num_sentences; i++) {
    printf("Sentence: %s\n", document.sentences[i].sentence);
    printf("Sentiment: %d\n", document.sentences[i].sentiment);
    printf("\n");
  }
}

int main() {
  load_dictionary();
  load_document();
  analyze_document();
  print_results();

  return 0;
}