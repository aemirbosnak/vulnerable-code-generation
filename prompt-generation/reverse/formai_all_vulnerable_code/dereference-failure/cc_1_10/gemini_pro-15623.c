//GEMINI-pro DATASET v1.0 Category: Text Summarizer ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Reads the input text from the user.
char *read_input_text() {
  char *input_text = NULL;
  size_t input_text_size = 0;
  getline(&input_text, &input_text_size, stdin);
  return input_text;
}

// Tokenizes the input text into words.
char **tokenize_input_text(char *input_text) {
  char **words = NULL;
  int num_words = 0;
  char *word = strtok(input_text, " ");
  while (word != NULL) {
    words = realloc(words, (num_words + 1) * sizeof(char *));
    words[num_words] = word;
    num_words++;
    word = strtok(NULL, " ");
  }
  return words;
}

// Computes the frequency of each word in the input text.
int *compute_word_frequencies(char **words, int num_words) {
  int *word_frequencies = calloc(num_words, sizeof(int));
  for (int i = 0; i < num_words; i++) {
    for (int j = 0; j < num_words; j++) {
      if (strcmp(words[i], words[j]) == 0) {
        word_frequencies[i]++;
      }
    }
  }
  return word_frequencies;
}

// Sorts the words by their frequency in descending order.
void sort_words_by_frequency(char **words, int *word_frequencies, int num_words) {
  for (int i = 0; i < num_words; i++) {
    for (int j = i + 1; j < num_words; j++) {
      if (word_frequencies[i] < word_frequencies[j]) {
        int temp = word_frequencies[i];
        word_frequencies[i] = word_frequencies[j];
        word_frequencies[j] = temp;

        char *temp_word = words[i];
        words[i] = words[j];
        words[j] = temp_word;
      }
    }
  }
}

// Prints the summary of the input text.
void print_summary(char **words, int *word_frequencies, int num_words) {
  printf("Summary:\n");
  for (int i = 0; i < num_words; i++) {
    printf("%s: %d\n", words[i], word_frequencies[i]);
  }
}

// Frees the allocated memory.
void free_memory(char **words, int *word_frequencies) {
  free(words);
  free(word_frequencies);
}

int main() {
  char *input_text = read_input_text();
  char **words = tokenize_input_text(input_text);
  int num_words = 0;
  while (words[num_words] != NULL) {
    num_words++;
  }
  int *word_frequencies = compute_word_frequencies(words, num_words);
  sort_words_by_frequency(words, word_frequencies, num_words);
  print_summary(words, word_frequencies, num_words);
  free_memory(words, word_frequencies);
  return 0;
}