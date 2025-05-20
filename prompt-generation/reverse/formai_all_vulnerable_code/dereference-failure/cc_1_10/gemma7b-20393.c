//Gemma-7B DATASET v1.0 Category: Typing Speed Test ; Style: romantic
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main()
{
  time_t start, end;
  int words_per_minute, characters_per_minute;

  char text[] = "A tale of two cities, a tale of love, a tale of tragedy. The clock strikes twelve, and the clock strikes again.";

  start = time(NULL);
  printf("%s", text);
  end = time(NULL);

  words_per_minute = (words_per_minute_calc(text, start, end) * 60) / 1000;
  characters_per_minute = (characters_per_minute_calc(text, start, end) * 60) / 1000;

  printf("\nWords per minute: %d", words_per_minute);
  printf("\nCharacters per minute: %d", characters_per_minute);

  return 0;
}

int words_per_minute_calc(char *text, time_t start, time_t end)
{
  int words = count_words(text);
  int time_spent = end - start;
  return words * 60 / time_spent;
}

int characters_per_minute_calc(char *text, time_t start, time_t end)
{
  int characters = count_characters(text);
  int time_spent = end - start;
  return characters * 60 / time_spent;
}

int count_words(char *text)
{
  int words = 0;
  char *p = text;

  while (p)
  {
    if (isspace(*p))
    {
      words++;
    }
    p++;
  }

  return words;
}

int count_characters(char *text)
{
  int characters = 0;
  char *p = text;

  while (p)
  {
    characters++;
    p++;
  }

  return characters;
}