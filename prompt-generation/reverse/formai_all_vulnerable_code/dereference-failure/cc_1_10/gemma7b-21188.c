//Gemma-7B DATASET v1.0 Category: Spam Detection System ; Style: interoperable
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 20

int main()
{
  char text[1024] = "This text contains some spam words, such as free, offer, and miracle. It also contains some not-so-spammy words, such as apple, banana, and orange.";
  char **words = NULL;
  int num_words = 0;

  // Tokenize the text into words
  words = tokenize(text, &num_words);

  // Check if each word is a spam word
  for (int i = 0; i < num_words; i++)
  {
    if (is_spam_word(words[i]))
    {
      printf("%s is a spam word.\n", words[i]);
    }
  }

  // Free the allocated memory
  free(words);

  return 0;
}

int tokenize(char *text, int *num_words)
{
  char **words = NULL;
  *num_words = 0;

  // Split the text into words
  char *word_ptr = strtok(text, " ");
  while (word_ptr)
  {
    words = realloc(words, (*num_words + 1) * sizeof(char *));
    words[*num_words] = strdup(word_ptr);
    (*num_words)++;
    word_ptr = strtok(NULL, " ");
  }

  return words;
}

int is_spam_word(char *word)
{
  char *spam_words[] = {"free", "offer", "miracle", "lottery", "prize"};
  int num_spam_words = sizeof(spam_words) / sizeof(char *);

  for (int i = 0; i < num_spam_words; i++)
  {
    if (strcmp(word, spam_words[i]) == 0)
    {
      return 1;
    }
  }

  return 0;
}