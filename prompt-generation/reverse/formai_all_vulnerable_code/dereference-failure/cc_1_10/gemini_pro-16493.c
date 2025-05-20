//GEMINI-pro DATASET v1.0 Category: Text Summarizer ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SENTENCES 100
#define MAX_WORDS_PER_SENTENCE 100
#define MAX_WORD_LENGTH 100

// Structure to represent a sentence
typedef struct sentence {
  char words[MAX_WORDS_PER_SENTENCE][MAX_WORD_LENGTH];
  int num_words;
} sentence;

// Structure to represent a summary
typedef struct summary {
  sentence sentences[MAX_SENTENCES];
  int num_sentences;
} summary;

// Function to read a text file into a string
char *read_text_file(char *filename) {
  FILE *fp = fopen(filename, "r");
  if (fp == NULL) {
    perror("Error opening file");
    return NULL;
  }

  fseek(fp, 0, SEEK_END);
  long fsize = ftell(fp);
  rewind(fp);

  char *text = malloc(fsize + 1);
  if (text == NULL) {
    perror("Error allocating memory");
    fclose(fp);
    return NULL;
  }

  fread(text, fsize, 1, fp);
  fclose(fp);

  text[fsize] = '\0';

  return text;
}

// Function to tokenize a string into sentences
sentence *tokenize_sentences(char *text, int *num_sentences) {
  sentence *sentences = malloc(MAX_SENTENCES * sizeof(sentence));
  if (sentences == NULL) {
    perror("Error allocating memory");
    return NULL;
  }

  int sentence_index = 0;
  int word_index = 0;
  int char_index = 0;

  while (text[char_index] != '\0') {
    // Skip leading whitespace
    while (isspace(text[char_index])) {
      char_index++;
    }

    // If we have reached the end of the text, break out of the loop
    if (text[char_index] == '\0') {
      break;
    }

    // Read the next word
    while (!isspace(text[char_index]) && text[char_index] != '\0') {
      sentences[sentence_index].words[word_index][char_index - sentences[sentence_index].words[word_index][0]] = text[char_index];
      char_index++;
    }
    sentences[sentence_index].words[word_index][char_index - sentences[sentence_index].words[word_index][0]] = '\0';
    word_index++;

    // If we have reached the end of a sentence, increment the sentence index and reset the word index
    if (text[char_index] == '.' || text[char_index] == '!' || text[char_index] == '?') {
      sentences[sentence_index].num_words = word_index;
      sentence_index++;
      word_index = 0;
    }

    // Increment the character index
    char_index++;
  }

  *num_sentences = sentence_index;

  return sentences;
}

// Function to summarize a text
summary summarize_text(sentence *sentences, int num_sentences) {
  summary summary;

  // Initialize the summary
  summary.num_sentences = 0;

  // Iterate over the sentences and add the most important sentences to the summary
  for (int i = 0; i < num_sentences; i++) {
    // Calculate the importance score of the sentence
    int importance_score = 0;
    for (int j = 0; j < sentences[i].num_words; j++) {
      if (strcmp(sentences[i].words[j], "important") == 0) {
        importance_score++;
      }
    }

    // Add the sentence to the summary if its importance score is high enough
    if (importance_score > 0) {
      summary.sentences[summary.num_sentences] = sentences[i];
      summary.num_sentences++;
    }
  }

  return summary;
}

// Function to print a summary
void print_summary(summary summary) {
  for (int i = 0; i < summary.num_sentences; i++) {
    for (int j = 0; j < summary.sentences[i].num_words; j++) {
      printf("%s ", summary.sentences[i].words[j]);
    }
    printf("\n");
  }
}

int main() {
  // Read the text file
  char *text = read_text_file("text.txt");
  if (text == NULL) {
    return EXIT_FAILURE;
  }

  // Tokenize the text into sentences
  int num_sentences;
  sentence *sentences = tokenize_sentences(text, &num_sentences);
  if (sentences == NULL) {
    free(text);
    return EXIT_FAILURE;
  }

  // Summarize the text
  summary summary = summarize_text(sentences, num_sentences);
  if (sentences == NULL) {
    free(text);
    free(sentences);
    return EXIT_FAILURE;
  }

  // Print the summary
  print_summary(summary);

  // Free the allocated memory
  free(text);
  free(sentences);
  free(summary.sentences);

  return EXIT_SUCCESS;
}