//GEMINI-pro DATASET v1.0 Category: Text processing ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum length of a word
#define MAX_WORD_LENGTH 100

// Create a function to read a file into a string
char *read_file(char *filename) {
  // Open the file
  FILE *file = fopen(filename, "r");
  if (file == NULL) {
    perror("Error opening file");
    return NULL;
  }

  // Get the file size
  fseek(file, 0, SEEK_END);
  long file_size = ftell(file);
  fseek(file, 0, SEEK_SET);

  // Allocate memory for the string
  char *string = malloc(file_size + 1);
  if (string == NULL) {
    perror("Error allocating memory");
    fclose(file);
    return NULL;
  }

  // Read the file into the string
  fread(string, file_size, 1, file);
  fclose(file);

  // Add a null terminator to the end of the string
  string[file_size] = '\0';

  // Return the string
  return string;
}

// Create a function to count the number of words in a string
int count_words(char *string) {
  // Initialize the word count to 0
  int word_count = 0;

  // Iterate over the string
  for (int i = 0; i < strlen(string); i++) {
    // If the current character is a space, tab, or newline, then we have reached the end of a word
    if (string[i] == ' ' || string[i] == '\t' || string[i] == '\n') {
      // Increment the word count
      word_count++;
    }
  }

  // Return the word count
  return word_count;
}

// Create a function to find the longest word in a string
char *find_longest_word(char *string) {
  // Initialize the longest word to the empty string
  char *longest_word = "";

  // Iterate over the string
  for (int i = 0; i < strlen(string); i++) {
    // If the current character is a space, tab, or newline, then we have reached the end of a word
    if (string[i] == ' ' || string[i] == '\t' || string[i] == '\n') {
      // Check if the current word is longer than the longest word we have found so far
      if (strlen(string + i) > strlen(longest_word)) {
        // If it is, then update the longest word
        longest_word = string + i;
      }
    }
  }

  // Return the longest word
  return longest_word;
}

// Create a function to print the top 10 longest words in a string
void print_top_10_longest_words(char *string) {
  // Create an array to store the top 10 longest words
  char *top_10_longest_words[10];

  // Initialize the array to the empty string
  for (int i = 0; i < 10; i++) {
    top_10_longest_words[i] = "";
  }

  // Iterate over the string
  for (int i = 0; i < strlen(string); i++) {
    // If the current character is a space, tab, or newline, then we have reached the end of a word
    if (string[i] == ' ' || string[i] == '\t' || string[i] == '\n') {
      // Check if the current word is longer than the shortest word in the top 10 list
      if (strlen(string + i) > strlen(top_10_longest_words[9])) {
        // If it is, then find the index of the shortest word in the top 10 list
        int shortest_word_index = 0;
        for (int j = 1; j < 10; j++) {
          if (strlen(top_10_longest_words[j]) < strlen(top_10_longest_words[shortest_word_index])) {
            shortest_word_index = j;
          }
        }

        // Update the shortest word in the top 10 list with the current word
        top_10_longest_words[shortest_word_index] = string + i;
      }
    }
  }

  // Print the top 10 longest words
  for (int i = 0; i < 10; i++) {
    printf("%d. %s\n", i + 1, top_10_longest_words[i]);
  }
}

// Create a function to main
int main() {
  // Read the file into a string
  char *string = read_file("file.txt");
  if (string == NULL) {
    return 1;
  }

  // Count the number of words in the string
  int word_count = count_words(string);

  // Find the longest word in the string
  char *longest_word = find_longest_word(string);

  // Print the number of words in the string
  printf("The number of words in the string is: %d\n", word_count);

  // Print the longest word in the string
  printf("The longest word in the string is: %s\n", longest_word);

  // Print the top 10 longest words in the string
  printf("The top 10 longest words in the string are:\n");
  print_top_10_longest_words(string);

  // Free the memory allocated for the string
  free(string);

  // Return 0 to indicate success
  return 0;
}