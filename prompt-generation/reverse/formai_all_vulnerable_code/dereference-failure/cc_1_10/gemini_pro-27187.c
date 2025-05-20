//GEMINI-pro DATASET v1.0 Category: Log analysis ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to remove all spaces from a string
char *remove_spaces(char *str)
{
  char *new_str = malloc(strlen(str) + 1);
  int i, j;
  for (i = 0, j = 0; str[i] != '\0'; i++)
    if (str[i] != ' ')
      new_str[j++] = str[i];
  new_str[j] = '\0';
  return new_str;
}

// Function to count the number of occurrences of a substring in a string
int count_substrings(char *str, char *substr)
{
  int count = 0;
  char *p = str;
  while ((p = strstr(p, substr)) != NULL)
  {
    count++;
    p++;
  }
  return count;
}

// Function to analyze a log file
void analyze_log_file(char *filename)
{
  FILE *fp = fopen(filename, "r");
  if (fp == NULL)
  {
    perror("Error opening file");
    exit(EXIT_FAILURE);
  }

  char line[1024];
  int total_lines = 0;
  int total_errors = 0;
  int total_warnings = 0;
  int total_infos = 0;

  while (fgets(line, sizeof(line), fp))
  {
    total_lines++;
    char *trimmed_line = remove_spaces(line);
    if (strstr(trimmed_line, "[ERROR]") != NULL)
      total_errors++;
    else if (strstr(trimmed_line, "[WARNING]") != NULL)
      total_warnings++;
    else if (strstr(trimmed_line, "[INFO]") != NULL)
      total_infos++;
  }

  fclose(fp);

  printf("Total lines: %d\n", total_lines);
  printf("Total errors: %d\n", total_errors);
  printf("Total warnings: %d\n", total_warnings);
  printf("Total infos: %d\n", total_infos);
}

int main(int argc, char *argv[])
{
  if (argc != 2)
  {
    printf("Usage: %s <log_file>\n", argv[0]);
    exit(EXIT_FAILURE);
  }

  analyze_log_file(argv[1]);

  return 0;
}