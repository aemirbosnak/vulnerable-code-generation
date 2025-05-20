//GEMINI-pro DATASET v1.0 Category: Text Summarizer ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_TEXT_SIZE 10000

// Function to read text from a file
char *read_text(char *filename) {
  // Open the file
  FILE *fp = fopen(filename, "r");
  if (fp == NULL) {
    perror("Error opening file");
    return NULL;
  }

  // Determine the file size
  fseek(fp, 0, SEEK_END);
  long file_size = ftell(fp);
  rewind(fp);

  // Allocate memory for the text
  char *text = malloc(file_size + 1);
  if (text == NULL) {
    perror("Error allocating memory");
    fclose(fp);
    return NULL;
  }

  // Read the text from the file
  fread(text, file_size, 1, fp);
  fclose(fp);

  // Append a null terminator to the end of the string
  text[file_size] = '\0';

  // Return the text
  return text;
}

// Function to summarize text
char *summarize_text(char *text) {
  // Remove all punctuation from the text
  char *temp = malloc(strlen(text) + 1);
  int i = 0;
  int j = 0;
  while (text[i] != '\0') {
    if (text[i] != '.' && text[i] != ',' && text[i] != ';' && text[i] != ':' && text[i] != '!' && text[i] != '?') {
      temp[j++] = text[i];
    }
    i++;
  }
  temp[j] = '\0';
  free(text);
  text = temp;

  // Split the text into words
  char **words = malloc(sizeof(char *) * MAX_TEXT_SIZE);
  i = 0;
  j = 0;
  char *word = strtok(text, " ");
  while (word != NULL) {
    words[i++] = word;
    word = strtok(NULL, " ");
  }

  // Count the frequency of each word
  int *counts = malloc(sizeof(int) * MAX_TEXT_SIZE);
  for (i = 0; i < MAX_TEXT_SIZE; i++) {
    counts[i] = 0;
  }
  for (i = 0; i < j; i++) {
    for (int k = 0; k < j; k++) {
      if (strcmp(words[i], words[k]) == 0) {
        counts[i]++;
      }
    }
  }

  // Find the most frequent words
  int max_count = 0;
  int max_index = 0;
  for (i = 0; i < j; i++) {
    if (counts[i] > max_count) {
      max_count = counts[i];
      max_index = i;
    }
  }

  // Create a summary of the text
  char *summary = malloc(strlen(words[max_index]) + 1);
  strcpy(summary, words[max_index]);

  // Free the allocated memory
  free(words);
  free(counts);

  // Return the summary
  return summary;
}

// Main function
int main(int argc, char **argv) {
  // Check if the user provided a filename
  if (argc < 2) {
    printf("Error: No filename provided.\n");
    return 1;
  }

  // Read the text from the file
  char *text = read_text(argv[1]);
  if (text == NULL) {
    return 1;
  }

  // Summarize the text
  char *summary = summarize_text(text);
  if (summary == NULL) {
    free(text);
    return 1;
  }

  // Print the summary
  printf("%s\n", summary);

  // Free the allocated memory
  free(text);
  free(summary);

  return 0;
}