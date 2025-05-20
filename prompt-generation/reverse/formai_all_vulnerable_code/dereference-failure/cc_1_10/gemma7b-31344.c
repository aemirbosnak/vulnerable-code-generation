//Gemma-7B DATASET v1.0 Category: Spell checking ; Style: paranoid
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>

#define MAX_WORDS 100
#define MAX_WORD_LENGTH 25

int main()
{
  char **words = NULL;
  char word[MAX_WORD_LENGTH];
  int i = 0, j = 0, k = 0, fd = 0, err = 0;
  struct stat sb;

  words = malloc(MAX_WORDS * sizeof(char *));

  for (i = 0; i < MAX_WORDS; i++)
  {
    words[i] = malloc(MAX_WORD_LENGTH * sizeof(char));
  }

  // Read the word from the user
  printf("Enter a word: ");
  scanf("%s", word);

  // Check if the word is already in the dictionary
  for (i = 0; i < k; i++)
  {
    if (strcmp(word, words[i]) == 0)
    {
      err = 1;
      break;
    }
  }

  // If the word is not in the dictionary, add it to the dictionary
  if (err == 0)
  {
    words[k] = strdup(word);
    k++;
  }

  // Close the file
  close(fd);

  // Free the memory
  for (i = 0; i < MAX_WORDS; i++)
  {
    free(words[i]);
  }

  free(words);

  return 0;
}