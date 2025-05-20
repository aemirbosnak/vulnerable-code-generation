//GEMINI-pro DATASET v1.0 Category: Building a CSV Reader ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_NUM_FIELDS 10
#define DELIMITER ","

// Function to read a line from a file
char *readLine(FILE *fp) {
  char *line = NULL;
  size_t len = 0;
  getline(&line, &len, fp);
  return line;
}

// Function to split a line into fields
char **splitLine(char *line) {
  char **fields = malloc(MAX_NUM_FIELDS * sizeof(char *));
  int numFields = 0;
  char *field = strtok(line, DELIMITER);
  while (field != NULL) {
    fields[numFields++] = field;
    field = strtok(NULL, DELIMITER);
  }
  return fields;
}

// Function to read a CSV file
char ***readCSV(FILE *fp) {
  char ***data = malloc(MAX_LINE_LENGTH * sizeof(char **));
  int numLines = 0;
  char *line = readLine(fp);
  while (line != NULL) {
    data[numLines++] = splitLine(line);
    free(line);
    line = readLine(fp);
  }
  return data;
}

// Function to print a CSV file
void printCSV(char ***data, int numLines) {
  for (int i = 0; i < numLines; i++) {
    for (int j = 0; data[i][j] != NULL; j++) {
      printf("%s", data[i][j]);
      if (data[i][j + 1] != NULL) {
        printf("%s", DELIMITER);
      }
    }
    printf("\n");
  }
}

// Function to free the memory allocated for a CSV file
void freeCSV(char ***data, int numLines) {
  for (int i = 0; i < numLines; i++) {
    for (int j = 0; data[i][j] != NULL; j++) {
      free(data[i][j]);
    }
    free(data[i]);
  }
  free(data);
}

int main() {
  FILE *fp = fopen("data.csv", "r");
  if (fp == NULL) {
    perror("Error opening file");
    return EXIT_FAILURE;
  }

  char ***data = readCSV(fp);
  fclose(fp);

  printCSV(data, 10);

  freeCSV(data, 10);

  return EXIT_SUCCESS;
}