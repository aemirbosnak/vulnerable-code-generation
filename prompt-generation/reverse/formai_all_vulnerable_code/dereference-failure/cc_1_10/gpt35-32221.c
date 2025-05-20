//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 100
#define MAX_COLS 10
#define MAX_FIELD_LEN 50

int read_csv(char *filename, char *data[][MAX_COLS]);
void print_csv(char *data[][MAX_COLS], int rows, int cols);

int main(void) {
  char *data[MAX_ROWS][MAX_COLS];
  int rows = read_csv("example.csv", data);
  print_csv(data, rows, 3);
  return EXIT_SUCCESS;
}

int read_csv(char *filename, char *data[][MAX_COLS]) {
  char buffer[MAX_FIELD_LEN * MAX_COLS];
  FILE *file = fopen(filename, "r");
  if (file == NULL) {
    perror("Error in opening file");
    exit(EXIT_FAILURE);
  }

  int rows = 0;
  while (fgets(buffer, sizeof(buffer), file) != NULL) {
    char *token;
    char *field;
    int cols = 0;
    token = strtok(buffer, ",");
    while (token != NULL && cols < MAX_COLS) {
      field = malloc(MAX_FIELD_LEN);
      strncpy(field, token, MAX_FIELD_LEN);
      data[rows][cols++] = field;
      token = strtok(NULL, ",");
    }
    rows++;
  }
  fclose(file);
  return rows;
}

void print_csv(char *data[][MAX_COLS], int rows, int cols) {
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      printf("%s ", data[i][j]);
    }
    printf("\n");
  }
}