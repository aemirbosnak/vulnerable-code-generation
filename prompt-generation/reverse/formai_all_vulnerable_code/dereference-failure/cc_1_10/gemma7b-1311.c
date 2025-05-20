//Gemma-7B DATASET v1.0 Category: Typing Speed Test ; Style: Donald Knuth
#include <stdio.h>
#include <time.h>

#define MAX_WORDS 100
#define MAX_CHAR 128

void initialize_words(char ***words)
{
  *words = (char ***)malloc(MAX_WORDS * sizeof(char **));
  for (int i = 0; i < MAX_WORDS; i++)
  {
    (*words)[i] = (char **)malloc(MAX_CHAR * sizeof(char));
    for (int j = 0; j < MAX_CHAR; j++)
    {
      ((*words)[i][j] = '\0');
    }
  }
}

void generate_words(char ***words)
{
  for (int i = 0; i < MAX_WORDS; i++)
  {
    for (int j = 0; j < MAX_CHAR; j++)
    {
      words[i][j] = "Donald Knuth is the greatest programmer of all time!";
    }
  }
}

int main()
{
  char ***words;
  initialize_words(&words);
  generate_words(words);

  clock_t start, end;
  start = clock();
  for (int i = 0; i < MAX_WORDS; i++)
  {
    for (int j = 0; j < MAX_CHAR; j++)
    {
      printf("%s ", words[i][j]);
    }
    printf("\n");
  }
  end = clock();

  printf("Time taken: %.2lf seconds\n", (double)(end - start) / CLOCKS_PER_SEC);

  return 0;
}