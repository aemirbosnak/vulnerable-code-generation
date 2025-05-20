//GEMINI-pro DATASET v1.0 Category: File handling ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum length of a line in the file
#define MAX_LINE_LENGTH 1024

// Define the maximum number of lines in the file
#define MAX_NUM_LINES 1000

// Define the maximum length of a word in the file
#define MAX_WORD_LENGTH 256

// Define the structure of a word
typedef struct {
  char word[MAX_WORD_LENGTH];
  int count;
} Word;

// Define the structure of a line
typedef struct {
  char line[MAX_LINE_LENGTH];
  int num_words;
  Word words[MAX_NUM_LINES];
} Line;

// Define the structure of a file
typedef struct {
  char filename[256];
  int num_lines;
  Line lines[MAX_NUM_LINES];
} File;

// Function to read a file into a File structure
File* read_file(char* filename) {
  // Allocate memory for the file
  File* file = malloc(sizeof(File));

  // Open the file for reading
  FILE* fp = fopen(filename, "r");
  if (fp == NULL) {
    perror("Error opening file");
    return NULL;
  }

  // Read the file line by line
  int line_num = 0;
  while (fgets(file->lines[line_num].line, MAX_LINE_LENGTH, fp) != NULL) {
    // Increment the line number
    line_num++;
  }

  // Close the file
  fclose(fp);

  // Set the number of lines in the file
  file->num_lines = line_num;

  // Return the file
  return file;
}

// Function to print a File structure
void print_file(File* file) {
  // Print the file name
  printf("File: %s\n", file->filename);

  // Print the number of lines in the file
  printf("Number of lines: %d\n", file->num_lines);

  // Print each line in the file
  for (int i = 0; i < file->num_lines; i++) {
    printf("Line %d: %s\n", i + 1, file->lines[i].line);
  }
}

// Function to count the number of words in a file
int count_words(File* file) {
  // Initialize the word count to 0
  int word_count = 0;

  // Loop through each line in the file
  for (int i = 0; i < file->num_lines; i++) {
    // Split the line into words
    char* word = strtok(file->lines[i].line, " ");

    // Loop through each word in the line
    while (word != NULL) {
      // Increment the word count
      word_count++;

      // Get the next word in the line
      word = strtok(NULL, " ");
    }
  }

  // Return the word count
  return word_count;
}

// Function to find the most common word in a file
Word* find_most_common_word(File* file) {
  // Initialize the most common word to NULL
  Word* most_common_word = NULL;

  // Create a hash table to store the word counts
  int word_counts[MAX_NUM_LINES];
  for (int i = 0; i < MAX_NUM_LINES; i++) {
    word_counts[i] = 0;
  }

  // Loop through each line in the file
  for (int i = 0; i < file->num_lines; i++) {
    // Split the line into words
    char* word = strtok(file->lines[i].line, " ");

    // Loop through each word in the line
    while (word != NULL) {
      // Increment the count of the word
      word_counts[i]++;

      // Get the next word in the line
      word = strtok(NULL, " ");
    }
  }

  // Find the word with the highest count
  int max_count = 0;
  for (int i = 0; i < MAX_NUM_LINES; i++) {
    if (word_counts[i] > max_count) {
      max_count = word_counts[i];
      most_common_word = &file->lines[i].words[0];
    }
  }

  // Return the most common word
  return most_common_word;
}

// Main function
int main() {
  // Read the file into a File structure
  File* file = read_file("test.txt");

  // Print the file
  print_file(file);

  // Count the number of words in the file
  int word_count = count_words(file);

  // Find the most common word in the file
  Word* most_common_word = find_most_common_word(file);

  // Print the word count and the most common word
  printf("Word count: %d\n", word_count);
  printf("Most common word: %s\n", most_common_word->word);

  // Free the memory allocated for the file
  free(file);

  return 0;
}