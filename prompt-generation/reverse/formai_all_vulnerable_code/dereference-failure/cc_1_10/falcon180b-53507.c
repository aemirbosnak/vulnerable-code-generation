//Falcon-180B DATASET v1.0 Category: Database simulation ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 100
#define MAX_COLS 100
#define MAX_DATA_SIZE 100

typedef struct {
  char *data;
  int rows;
  int cols;
} Data;

int main() {
  Data *db = NULL;
  int rows, cols, i, j;
  char *filename;
  FILE *fp;

  printf("Enter the name of the database file: ");
  scanf("%s", filename);

  fp = fopen(filename, "r");
  if (fp == NULL) {
    printf("Error opening file.\n");
    exit(1);
  }

  fscanf(fp, "%d %d", &rows, &cols);
  db = (Data *)malloc(sizeof(Data));
  db->rows = rows;
  db->cols = cols;
  db->data = (char *)malloc(rows * cols * MAX_DATA_SIZE);

  for (i = 0; i < rows; i++) {
    for (j = 0; j < cols; j++) {
      fscanf(fp, "%s", db->data + i * MAX_DATA_SIZE + j * MAX_DATA_SIZE);
    }
  }

  fclose(fp);

  printf("Enter the row and column to retrieve data from:\n");
  scanf("%d %d", &i, &j);

  printf("Data at row %d, column %d: %s\n", i, j, db->data + i * MAX_DATA_SIZE + j * MAX_DATA_SIZE);

  free(db->data);
  free(db);

  return 0;
}