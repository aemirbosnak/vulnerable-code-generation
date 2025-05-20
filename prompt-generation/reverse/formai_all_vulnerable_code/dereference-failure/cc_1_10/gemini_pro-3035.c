//GEMINI-pro DATASET v1.0 Category: Text Summarizer ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store a sentence
typedef struct sentence {
  char *text;
  int length;
} sentence;

// Structure to store a summary
typedef struct summary {
  char *text;
  int length;
} summary;

// Function to create a new sentence
sentence *new_sentence(char *text) {
  sentence *s = malloc(sizeof(sentence));
  s->text = strdup(text);
  s->length = strlen(text);
  return s;
}

// Function to create a new summary
summary *new_summary(char *text) {
  summary *s = malloc(sizeof(summary));
  s->text = strdup(text);
  s->length = strlen(text);
  return s;
}

// Function to free a sentence
void free_sentence(sentence *s) {
  free(s->text);
  free(s);
}

// Function to free a summary
void free_summary(summary *s) {
  free(s->text);
  free(s);
}

// Function to compare two sentences
int compare_sentences(const void *a, const void *b) {
  sentence *sa = (sentence *)a;
  sentence *sb = (sentence *)b;
  return sa->length - sb->length;
}

// Function to summarize a text
summary *summarize_text(char *text) {
  // Tokenize the text into sentences
  char *token = strtok(text, ".");
  int num_sentences = 0;
  sentence **sentences = NULL;
  while (token != NULL) {
    sentences = realloc(sentences, sizeof(sentence *) * (num_sentences + 1));
    sentences[num_sentences] = new_sentence(token);
    num_sentences++;
    token = strtok(NULL, ".");
  }

  // Sort the sentences by length
  qsort(sentences, num_sentences, sizeof(sentence *), compare_sentences);

  // Create a new summary
  summary *s = new_summary("");

  // Add the first sentence to the summary
  s->text = realloc(s->text, strlen(s->text) + strlen(sentences[0]->text) + 1);
  strcat(s->text, sentences[0]->text);
  s->length += sentences[0]->length;

  // Add the other sentences to the summary
  for (int i = 1; i < num_sentences; i++) {
    if (s->length + sentences[i]->length <= 140) {
      s->text = realloc(s->text, strlen(s->text) + strlen(sentences[i]->text) + 1);
      strcat(s->text, sentences[i]->text);
      s->length += sentences[i]->length;
    }
  }

  // Free the sentences
  for (int i = 0; i < num_sentences; i++) {
    free_sentence(sentences[i]);
  }
  free(sentences);

  // Return the summary
  return s;
}

// Function to print a summary
void print_summary(summary *s) {
  printf("%s\n", s->text);
}

// Main function
int main() {
  // Get the text from the user
  char *text = malloc(1000);
  printf("Enter the text to be summarized: ");
  fgets(text, 1000, stdin);

  // Summarize the text
  summary *s = summarize_text(text);

  // Print the summary
  print_summary(s);

  // Free the summary
  free_summary(s);

  // Free the text
  free(text);

  return 0;
}