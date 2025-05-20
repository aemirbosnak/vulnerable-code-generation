//GEMINI-pro DATASET v1.0 Category: Sentiment analysis tool ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 100
#define MAX_SENTENCES 10

struct word {
  char *str;
  int weight;
};

struct sentence {
  struct word *words[MAX_WORDS];
  int num_words;
  int total_weight;
};

int compare_words(const void *a, const void *b) {
  struct word *wa = (struct word *)a;
  struct word *wb = (struct word *)b;
  return strcmp(wa->str, wb->str);
}

int main() {
  // Define a list of words and their weights.
  struct word words[] = {
    {"good", 1},
    {"bad", -1},
    {"excellent", 2},
    {"terrible", -2},
    {"amazing", 3},
    {"awful", -3},
  };

  // Create an array of sentences.
  struct sentence sentences[MAX_SENTENCES];

  // Read the sentences from the user.
  int num_sentences = 0;
  while (num_sentences < MAX_SENTENCES) {
    printf("Enter a sentence: ");
    char input[100];
    fgets(input, 100, stdin);

    // Tokenize the sentence into words.
    char *token = strtok(input, " ");
    int num_words = 0;
    while (token != NULL && num_words < MAX_WORDS) {
      sentences[num_sentences].words[num_words] = malloc(strlen(token) + 1);
      strcpy(sentences[num_sentences].words[num_words], token);
      num_words++;
      token = strtok(NULL, " ");
    }

    // Calculate the total weight of the sentence.
    sentences[num_sentences].num_words = num_words;
    sentences[num_sentences].total_weight = 0;
    for (int i = 0; i < num_words; i++) {
      struct word *word = bsearch(sentences[num_sentences].words[i], words, sizeof(words) / sizeof(words[0]), sizeof(struct word), compare_words);
      if (word != NULL) {
        sentences[num_sentences].total_weight += word->weight;
      }
    }

    num_sentences++;
  }

  // Print the sentiment of each sentence.
  for (int i = 0; i < num_sentences; i++) {
    printf("Sentence %d: %s", i + 1, sentences[i].words[0]);
    for (int j = 1; j < sentences[i].num_words; j++) {
      printf(" %s", sentences[i].words[j]);
    }
    printf("\n");
    if (sentences[i].total_weight > 0) {
      printf("Sentiment: positive\n");
    } else if (sentences[i].total_weight < 0) {
      printf("Sentiment: negative\n");
    } else {
      printf("Sentiment: neutral\n");
    }
  }

  // Free the memory that was allocated for the words and sentences.
  for (int i = 0; i < num_sentences; i++) {
    for (int j = 0; j < sentences[i].num_words; j++) {
      free(sentences[i].words[j]);
    }
  }

  return 0;
}