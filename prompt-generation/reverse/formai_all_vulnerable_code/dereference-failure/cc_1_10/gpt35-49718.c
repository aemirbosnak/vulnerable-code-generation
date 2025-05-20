//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_SIZE 1024
#define MAX_NUM_COLUMNS 10

struct csv_row {
  int num_columns;
  char **columns;
};

struct csv_table {
  int num_rows;
  struct csv_row *rows;
};

/**
 * @brief Read a single CSV row from a file stream.
 *
 * @param in   File stream to read from.
 * @param row  Pointer to struct to store row data.
 *
 * @return     0 if end-of-file is reached or error occurs,
 *             1 if row is successfully read.
 */
int read_csv_row(FILE *in, struct csv_row *row) {
  char line[MAX_LINE_SIZE];
  if (fgets(line, MAX_LINE_SIZE, in) == NULL) {
    return 0; // end-of-file or error
  }

  // Allocate memory for columns array
  row->columns = malloc(MAX_NUM_COLUMNS * sizeof(char *));
  memset(row->columns, 0, MAX_NUM_COLUMNS * sizeof(char *));
  
  // Parse line into columns
  char *p = strtok(line, ",");
  int i = 0;
  while (p && i < MAX_NUM_COLUMNS) {
    size_t len = strlen(p);
    if (p[len-1] == '\n') {
      p[len-1] = '\0'; // remove newline character
    }
    row->columns[i] = malloc(len+1);
    strcpy(row->columns[i], p);
    p = strtok(NULL, ",");
    i++;
  }
  row->num_columns = i;

  return 1;
}

/**
 * @brief Read an entire CSV table from a file stream.
 *
 * @param in    File stream to read from.
 * @param table Pointer to struct to store table data.
 *
 * @return      0 if end-of-file is reached or error occurs,
 *              1 if table is successfully read.
 */
int read_csv_table(FILE *in, struct csv_table *table) {
  // Allocate memory for rows array
  table->rows = malloc(MAX_LINE_SIZE * sizeof(struct csv_row));
  memset(table->rows, 0, MAX_LINE_SIZE * sizeof(struct csv_row));
  
  int i = 0;
  while (read_csv_row(in, &table->rows[i])) {
    i++;
    if (i == MAX_LINE_SIZE) {
      break; // maximum table size reached
    }
  }
  table->num_rows = i;

  return (i > 0) ? 1 : 0;
}

int main(void) {
  printf("Welcome to the CSV Reader program!\n");
  printf("Enter the filename to read (including extension): ");

  // Read filename from user input
  char filename[MAX_LINE_SIZE];
  fgets(filename, MAX_LINE_SIZE, stdin);
  filename[strcspn(filename, "\n")] = '\0'; // remove newline character

  // Open file for reading
  FILE *infile = fopen(filename, "r");
  if (infile == NULL) {
    printf("Error: cannot open file %s\n", filename);
    exit(EXIT_FAILURE);
  }

  // Read CSV table from file
  struct csv_table table;
  if (!read_csv_table(infile, &table)) {
    printf("Error: could not read CSV table from file\n");
    exit(EXIT_FAILURE);
  }
  
  // Print table to console
  printf("\nTable contents:\n");
  for (int i = 0; i < table.num_rows; i++) {
    printf("Row %d: ", i+1);
    for (int j = 0; j < table.rows[i].num_columns; j++) {
      printf("%s", table.rows[i].columns[j]);
      if (j < table.rows[i].num_columns-1) {
        printf(", ");
      }
    }
    printf("\n");
  }

  // Free memory
  for (int i = 0; i < table.num_rows; i++) {
    for (int j = 0; j < table.rows[i].num_columns; j++) {
      free(table.rows[i].columns[j]);
    }
    free(table.rows[i].columns);
  }
  free(table.rows);
  fclose(infile);

  printf("\nThank you for using the CSV Reader program!\n");
  return 0;
}