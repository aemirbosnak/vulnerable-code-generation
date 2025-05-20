//Gemma-7B DATASET v1.0 Category: Sentiment analysis tool ; Style: interoperable
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <locale.h>

#define MAX_WORDS 100

int main()
{
  setlocale(LC_ALL, "");

  char text[MAX_WORDS];
  printf("Enter text: ");
  fgets(text, MAX_WORDS, stdin);

  char *words[MAX_WORDS];
  int num_words = tokenize(text, words);

  int sentiment = analyze_sentiment(words);

  switch (sentiment)
  {
    case 0:
      printf("Neutral\n");
      break;
    case 1:
      printf("Positive\n");
      break;
    case -1:
      printf("Negative\n");
      break;
  }

  return 0;
}

int tokenize(char *text, char **words)
{
  int num_words = 0;
  char *word = strtok(text, " ");

  while (word)
  {
    words[num_words++] = word;
    word = strtok(NULL, " ");
  }

  return num_words;
}

int analyze_sentiment(char **words)
{
  int sentiment = 0;
  for (int i = 0; words[i] != NULL; i++)
  {
    if (words[i][0] == 'p' || words[i][0] == 'P')
    {
      sentiment++;
    }
    else if (words[i][0] == 'n' || words[i][0] == 'N')
    {
      sentiment--;
    }
  }

  return sentiment;
}