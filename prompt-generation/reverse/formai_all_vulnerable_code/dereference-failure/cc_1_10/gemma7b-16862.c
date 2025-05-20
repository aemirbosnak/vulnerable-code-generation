//Gemma-7B DATASET v1.0 Category: Sentiment analysis tool ; Style: Cyberpunk
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX_WORDS 1024

int main()
{
  system("clear");
  char text[MAX_WORDS];
  printf("Enter text: ");
  fgets(text, MAX_WORDS, stdin);

  char *words[MAX_WORDS];
  int num_words = tokenize(text, words);

  int sentiment_score = calculate_sentiment(words);

  printf("Sentiment score: %d\n", sentiment_score);

  if (sentiment_score > 0)
  {
    printf("Text is positive.\n");
  }
  else if (sentiment_score == 0)
  {
    printf("Text is neutral.\n");
  }
  else
  {
    printf("Text is negative.\n");
  }

  return 0;
}

int tokenize(char *text, char **words)
{
  char *ptr = text;
  int num_words = 0;

  while (ptr)
  {
    char *word = strsep(ptr, " ,.;:");
    if (word)
    {
      words[num_words++] = strdup(word);
    }

    ptr = word ? NULL : ptr;
  }

  return num_words;
}

int calculate_sentiment(char **words)
{
  int sentiment_score = 0;
  for (int i = 0; words[i] != NULL; i++)
  {
    if (is_positive_word(words[i]))
    {
      sentiment_score++;
    }
    else if (is_negative_word(words[i]))
    {
      sentiment_score--;
    }
  }

  return sentiment_score;
}

int is_positive_word(char *word)
{
  return strstr(word, "happy") || strstr(word, "good") || strstr(word, "great") || strstr(word, "excellent");
}

int is_negative_word(char *word)
{
  return strstr(word, "sad") || strstr(word, "bad") || strstr(word, "terrible") || strstr(word, "awful");
}