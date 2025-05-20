//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 1024
#define MAX_COLS 1024
#define MAX_BUF_SIZE 4096

int main(int argc, char **argv) {
  if (argc != 2) {
    printf("Please provide a CSV filename.\n");
    return 1;
  }
  FILE *fp = fopen(argv[1], "r");
  if (!fp) {
    printf("Failed to open file: %s\n", argv[1]);
    return 1;
  }

  char line[MAX_BUF_SIZE];
  char *fields[MAX_COLS];
  int row_count = 0;
  int col_count = 0;
  int i, j;

  while (fgets(line, sizeof(line), fp)) {
    if (row_count == MAX_ROWS) {
      printf("Error: too many rows in CSV file.\n");
      return 1;
    }
    col_count = 0;
    fields[0] = strtok(line, ",");
    while (fields[col_count] != NULL) {
      col_count++;
      if (col_count >= MAX_COLS) {
        printf("Error: too many columns in CSV file.\n");
        return 1;
      }
      fields[col_count] = strtok(NULL, ",");
    }
    row_count++;
    for (i = 0; i < col_count; i++) {
      char *field = fields[i];
      // Remove quotes from field
      if (field[0] == '\"' && field[strlen(field) - 1] == '\"') {
        memmove(field, field + 1, strlen(field) - 1);
        field[strlen(field) - 2] = 0;
      }
      printf("%s,", field);
    }
    printf("\n");
  }

  fclose(fp);
  return 0;
}