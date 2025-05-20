//GEMINI-pro DATASET v1.0 Category: Spam Detection System ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SPAM_THRESHOLD 0.5
#define SPAM_WORDS_FILE "spam_words.txt"

// Function to read a file into a string
char* read_file(const char* filename) {
  FILE* file = fopen(filename, "r");
  if (file == NULL) {
    return NULL;
  }

  fseek(file, 0, SEEK_END);
  size_t size = ftell(file);
  rewind(file);

  char* buffer = malloc(size + 1);
  if (buffer == NULL) {
    return NULL;
  }

  fread(buffer, size, 1, file);
  buffer[size] = '\0';

  fclose(file);

  return buffer;
}

// Function to split a string into an array of strings
char** split_string(const char* string, const char* delimiter) {
  size_t num_tokens = 0;

  // Count the number of tokens
  char* copy = strdup(string);
  char* token = strtok(copy, delimiter);
  while (token != NULL) {
    num_tokens++;
    token = strtok(NULL, delimiter);
  }
  free(copy);

  // Allocate memory for the array of strings
  char** tokens = malloc(sizeof(char*) * (num_tokens + 1));
  if (tokens == NULL) {
    return NULL;
  }

  // Split the string into tokens
  size_t i = 0;
  token = strtok(string, delimiter);
  while (token != NULL) {
    tokens[i] = strdup(token);
    i++;
    token = strtok(NULL, delimiter);
  }
  tokens[i] = NULL;

  return tokens;
}

// Function to calculate the spam score of a string
double calculate_spam_score(const char* string, const char* spam_words) {
  char** words = split_string(string, " ");
  if (words == NULL) {
    return -1;
  }

  double spam_score = 0;
  size_t num_words = 0;

  char** spam_words_list = split_string(spam_words, ",");
  if (spam_words_list == NULL) {
    return -1;
  }

  while (*words != NULL) {
    num_words++;

    for (size_t i = 0; spam_words_list[i] != NULL; i++) {
      if (strcmp(*words, spam_words_list[i]) == 0) {
        spam_score += 1;
      }
    }

    words++;
  }

  free(words);
  free(spam_words_list);

  return spam_score / num_words;
}

int main() {
  // Read the spam words from the file
  char* spam_words = read_file(SPAM_WORDS_FILE);
  if (spam_words == NULL) {
    printf("Error reading spam words file.\n");
    return 1;
  }

  // Get the input string from the user
  char* input_string = malloc(1024);
  if (input_string == NULL) {
    printf("Error allocating memory for input string.\n");
    return 1;
  }

  printf("Enter the string to check for spam: ");
  fgets(input_string, 1024, stdin);

  // Calculate the spam score
  double spam_score = calculate_spam_score(input_string, spam_words);
  if (spam_score < 0) {
    printf("Error calculating spam score.\n");
    return 1;
  }

  // Print the spam score
  printf("Spam score: %.2f\n", spam_score);

  // Free the allocated memory
  free(spam_words);
  free(input_string);

  return 0;
}