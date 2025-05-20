//Gemma-7B DATASET v1.0 Category: Word Frequency Counter ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to count the frequency of a word
int word_frequency(char *word, char **word_list, int *word_list_size)
{
  int i = 0;
  for (i = 0; i < *word_list_size; i++)
  {
    if (strcmp(word, word_list[i]) == 0)
    {
      return 1;
    }
  }

  return 0;
}

int main()
{
  char **word_list = NULL;
  int word_list_size = 0;

  char *sentence = "The quick brown fox jumps over the lazy dog. The quick brown fox jumps over the lazy dog.";

  // Split the sentence into words
  char *word = strtok(sentence, " ");

  // Create a list of words
  while (word)
  {
    word_list = realloc(word_list, (word_list_size + 1) * sizeof(char *));
    word_list[word_list_size++] = strdup(word);
    word = strtok(NULL, " ");
  }

  // Count the frequency of each word
  int word_frequency_count = 0;
  for (int i = 0; i < word_list_size; i++)
  {
    word_frequency_count++;
    word_frequency(word_list[i], word_list, &word_list_size);
  }

  // Print the word frequencies
  for (int i = 0; i < word_list_size; i++)
  {
    printf("%s: %d\n", word_list[i], word_frequency(word_list[i], word_list, &word_list_size));
  }

  // Free the memory allocated for the word list
  free(word_list);

  return 0;
}