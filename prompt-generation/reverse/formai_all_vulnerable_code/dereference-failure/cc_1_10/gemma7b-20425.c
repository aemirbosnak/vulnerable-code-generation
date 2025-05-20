//Gemma-7B DATASET v1.0 Category: Data mining ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

int main()
{
  char **arr = (char **)malloc(MAX * sizeof(char *));
  int n = 0;

  FILE *fp = fopen("love.txt", "r");
  if (fp == NULL)
  {
    return 1;
  }

  // Reading the file line by line
  char line[100];
  while (fgets(line, 100, fp) != NULL)
  {
    // Allocating memory for each line
    arr[n] = (char *)malloc(MAX * sizeof(char));
    strcpy(arr[n], line);
    n++;
  }

  // Closing the file
  fclose(fp);

  // Analyzing the lines
  for (int i = 0; i < n; i++)
  {
    // Finding the words in each line
    char **words = (char **)malloc(MAX * sizeof(char *));
    int m = 0;
    char word[20];
    char *p = arr[i];

    // Iterating over the line to find words
    while (p)
    {
      word[0] = '\0';
      p = strsep(p, " ");
      if (p)
      {
        strcpy(word, p);
        words[m++] = word;
      }
    }

    // Analyzing the words
    for (int j = 0; j < m; j++)
    {
      // Counting the occurrences of each word
      int count = 0;
      for (int k = 0; k < n; k++)
      {
        if (strcmp(words[j], arr[k]) == 0)
        {
          count++;
        }
      }

      // Printing the word and its occurrences
      printf("%s occurred %d times.\n", words[j], count);
    }
  }

  return 0;
}