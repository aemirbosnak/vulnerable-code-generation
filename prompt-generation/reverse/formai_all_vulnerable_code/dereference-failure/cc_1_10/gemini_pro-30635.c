//GEMINI-pro DATASET v1.0 Category: Building a CSV Reader ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int ColumnCount(char *line) {
  int count = 0;
  while (*line != '\0') {
    if (*line == ',') {
      count++;
    }
    line++;
  }
  if (*line == '\0') {
    count++;
  }
  return count;
}

int **ReadCSV(char *filename, int *rowCount, int *columnCount) {
  FILE *fp = fopen(filename, "r");
  if (fp == NULL) {
    return NULL;
  }
  char line[1024];
  int row_count = 0;
  while (fgets(line, 1024, fp) != NULL) {
    row_count++;
  }
  fclose(fp);
  fp = fopen(filename, "r");
  int col_count = ColumnCount(line);
  int **data = malloc(sizeof(int *) * row_count);
  for (int i = 0; i < row_count; i++) {
    data[i] = malloc(sizeof(int) * col_count);
  }
  int row = 0;
  while (fgets(line, 1024, fp) != NULL) {
    char *token = strtok(line, ",");
    int col = 0;
    while (token != NULL) {
      data[row][col] = atoi(token);
      token = strtok(NULL, ",");
      col++;
    }
    row++;
  }
  fclose(fp);
  *rowCount = row_count;
  *columnCount = col_count;
  return data;
}

void PrintCSV(int **data, int rowCount, int columnCount) {
  for (int i = 0; i < rowCount; i++) {
    for (int j = 0; j < columnCount; j++) {
      if (j == 0) {
        printf("%d", data[i][j]);
      } else {
        printf(",%d", data[i][j]);
      }
    }
    printf("\n");
  }
}

void FreeCSV(int **data, int rowCount) {
  for (int i = 0; i < rowCount; i++) {
    free(data[i]);
  }
  free(data);
}

int main() {
  int rowCount;
  int columnCount;
  int **data = ReadCSV("data.csv", &rowCount, &columnCount);
  PrintCSV(data, rowCount, columnCount);
  FreeCSV(data, rowCount);
  return 0;
}