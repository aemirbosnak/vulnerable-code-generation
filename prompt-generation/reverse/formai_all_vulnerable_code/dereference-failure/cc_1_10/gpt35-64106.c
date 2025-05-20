//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COLS 20
#define MAX_COLUMN_LENGTH 100

void readCSV(char *filename, int fields)
{
  FILE *file;
  char line[MAX_COLS * MAX_COLUMN_LENGTH];
  char *token, *last_token;
  char **columns = (char **)malloc(sizeof(char *) * fields);
  int col = 0, row = 0;

  file = fopen(filename, "r");
  if (file == NULL)
  {
    printf("Could not open file: %s\n", filename);
    exit(EXIT_FAILURE);
  }

  while (fgets(line, sizeof(line), file))
  {
    col = 0;
    last_token = NULL;

    token = strtok(line, ",");
    columns[col] = (char *)malloc(sizeof(char) * strlen(token) + 1);
    strcpy(columns[col], token);

    while (token != NULL && col < fields)
    {
      if (last_token && !strcmp(last_token, ""))
      {
        col++;
        columns[col] = (char *)malloc(sizeof(char) * strlen(token) + 1);
        strcpy(columns[col], token);
      }
      else
      {
        strcat(columns[col], token);
      }

      last_token = token;
      token = strtok(NULL, ",");
    }

    row++;

    for (int i = 0; i < fields; i++)
    {
      printf("%s ", columns[i]);
      free(columns[i]);
    }
    putchar('\n');
  }

  free(columns);
  fclose(file);
}

int main()
{
  readCSV("example.csv", 3);
  return 0;
}