//Gemma-7B DATASET v1.0 Category: Cat Language Translator ; Style: multiplayer
#include <stdio.h>
#include <string.h>

#define MAX_WORDS 10

int main()
{
  char **words = (char **)malloc(MAX_WORDS * sizeof(char *));
  for (int i = 0; i < MAX_WORDS; i++)
  {
    words[i] = (char *)malloc(20 * sizeof(char));
  }

  int numPlayers = 2;
  for (int i = 0; i < numPlayers; i++)
  {
    printf("Player %d, enter a word: ", i + 1);
    scanf("%s", words[i]);
  }

  int translatorIndex = 0;
  for (int i = 0; i < numPlayers; i++)
  {
    for (int j = 0; j < numPlayers; j++)
    {
      if (i != j)
      {
        int similarity = compareWords(words[i], words[j]);
        printf("Player %d, the similarity between your word and Player %d's word is %d%%.\n", i + 1, j + 1, similarity);
      }
    }
  }

  for (int i = 0; i < MAX_WORDS; i++)
  {
    free(words[i]);
  }
  free(words);

  return 0;
}

int compareWords(char *word1, char *word2)
{
  int length1 = strlen(word1);
  int length2 = strlen(word2);

  if (length1 != length2)
  {
    return 0;
  }

  for (int i = 0; i < length1; i++)
  {
    if (word1[i] != word2[i])
    {
      return 0;
    }
  }

  return 100;
}