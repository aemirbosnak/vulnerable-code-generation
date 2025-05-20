//GEMINI-pro DATASET v1.0 Category: Resume Parsing System ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the surrealist resume parsing function
int parse_resume(char *filename) {
  // Open the resume file
  FILE *file = fopen(filename, "r");
  if (file == NULL) {
    printf("Error opening file %s\n", filename);
    return -1;
  }

  // Read the resume into a string
  char *resume = malloc(10000);
  fread(resume, 1, 10000, file);

  // Close the resume file
  fclose(file);

  // Tokenize the resume into words
  char *words[1000];
  int num_words = 0;
  char *token = strtok(resume, " ");
  while (token != NULL) {
    words[num_words++] = token;
    token = strtok(NULL, " ");
  }

  // Create a linked list of the words
  struct word_node {
    char *word;
    struct word_node *next;
  };
  struct word_node *head = NULL;
  for (int i = 0; i < num_words; i++) {
    struct word_node *new_node = malloc(sizeof(struct word_node));
    new_node->word = words[i];
    new_node->next = head;
    head = new_node;
  }

  // Print the linked list of words
  struct word_node *current = head;
  while (current != NULL) {
    printf("%s\n", current->word);
    current = current->next;
  }

  // Free the linked list of words
  current = head;
  while (current != NULL) {
    struct word_node *next = current->next;
    free(current);
    current = next;
  }

  // Free the resume string
  free(resume);

  // Return 0 to indicate success
  return 0;
}

// Define the main function
int main(int argc, char *argv[]) {
  // Check if the user has provided a filename
  if (argc < 2) {
    printf("Usage: %s <filename>\n", argv[0]);
    return -1;
  }

  // Parse the resume file
  int result = parse_resume(argv[1]);

  // Return the result
  return result;
}