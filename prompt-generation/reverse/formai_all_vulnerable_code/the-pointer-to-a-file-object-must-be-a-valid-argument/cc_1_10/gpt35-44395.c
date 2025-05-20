//FormAI DATASET v1.0 Category: Text Summarizer ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SENTENCES 100
#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 50
#define MAX_STOPWORDS 50

char stopwords[MAX_STOPWORDS][MAX_WORD_LENGTH];
char sentences[MAX_SENTENCES][MAX_WORDS][MAX_WORD_LENGTH];
int freq[MAX_SENTENCES][MAX_WORDS];
int score[MAX_SENTENCES];
int n_sentences;
int n_stopwords;

// Function to read stop words from a file
void read_stopwords(char *filename) {
  FILE *fp = fopen(filename, "r");
  char word[MAX_WORD_LENGTH];
  n_stopwords = 0;

  while (fscanf(fp, "%s", word) != EOF) {
    strcpy(stopwords[n_stopwords], word);
    n_stopwords++;
  }

  fclose(fp);
}

// Function to check if a word is a stop word
int is_stopword(char *word) {
  int i;

  for (i = 0; i < n_stopwords; i++) {
    if (strcmp(stopwords[i], word) == 0) {
      return 1;
    }
  }

  return 0;
}

// Function to tokenize a sentence by space
void tokenize(char *sentence, char (*tokens)[MAX_WORD_LENGTH], int *n_tokens) {
  char word[MAX_WORD_LENGTH];
  int i, j;

  *n_tokens = 0;

  for (i = 0, j = 0; sentence[i] != '\0'; i++) {
    if (sentence[i] == ' ') {
      word[j] = '\0';

      if (!is_stopword(word)) {
        strcpy(tokens[*n_tokens], word);
        (*n_tokens)++;
      }

      j = 0;
    } else {
      word[j] = sentence[i];
      j++;
    }
  }

  word[j] = '\0';

  if (!is_stopword(word)) {
    strcpy(tokens[*n_tokens], word);
    (*n_tokens)++;
  }
}

// Function to compute the frequency of words in each sentence
void compute_frequency() {
  int i, j, k;

  for (i = 0; i < n_sentences; i++) {
    for (j = 0; j < MAX_WORDS; j++) {
      freq[i][j] = 0;
    }

    char (*tokens)[MAX_WORD_LENGTH] = sentences[i];
    int n_tokens = 0;
    tokenize(sentences[i], tokens, &n_tokens);

    for (j = 0; j < n_tokens; j++) {
      for (k = 0; k < n_tokens; k++) {
        if (strcmp(tokens[j], tokens[k]) == 0) {
          freq[i][j]++;
        }
      }
    }
  }
}

// Function to calculate the score of each sentence
void compute_score() {
  int i, j;

  for (i = 0; i < n_sentences; i++) {
    score[i] = 0;

    for (j = 0; j < MAX_WORDS; j++) {
      score[i] += freq[i][j];
    }
  }
}

// Function to print the summary with top-scoring sentences
void print_summary(int n_summary) {
  int i, j;
  int summary[MAX_SENTENCES];

  for (i = 0; i < n_sentences; i++) {
    summary[i] = i;
  }

  for (i = 0; i < n_summary; i++) {
    int max_score = score[summary[i]];
    int max_index = i;

    for (j = i + 1; j < n_sentences; j++) {
      if (score[summary[j]] > max_score) {
        max_score = score[summary[j]];
        max_index = j;
      }
    }

    int temp = summary[i];
    summary[i] = summary[max_index];
    summary[max_index] = temp;
  }

  printf("Summary:\n");

  for (i = 0; i < n_summary; i++) {
    printf("%s\n", sentences[summary[i]]);
  }
}

int main() {
  char filename[MAX_WORD_LENGTH];
  char sentence[MAX_WORDS];
  printf("Enter the input filename: ");
  scanf("%s", filename);
  printf("Enter the number of sentences to include in the summary: ");
  int n_summary;
  scanf("%d", &n_summary);

  FILE *fp = fopen(filename, "r");
  n_sentences = 0;

  // Read input file and store sentences
  while (fgets(sentence, MAX_WORDS, fp) != NULL && n_sentences < MAX_SENTENCES) {
    sentence[strcspn(sentence, "\n")] = '\0';
    strcpy(sentences[n_sentences], sentence);
    n_sentences++;
  }

  fclose(fp);

  // Read stop words from file
  read_stopwords("stopwords.txt");

  // Compute word frequency and score
  compute_frequency();
  compute_score();

  // Print summary
  print_summary(n_summary);

  return 0;
}