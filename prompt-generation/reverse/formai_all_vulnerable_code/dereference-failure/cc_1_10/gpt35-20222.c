//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_SIZE 256 // maximum size of a line in the CSV file
#define MAX_FIELD_SIZE 32 // maximum size of a field in the CSV file

typedef struct {
  char **fields; // array of strings representing each field 
  int num_fields; // number of fields in the row
} csv_row_t;

int read_csv(const char *filename, csv_row_t **rows, int *num_rows) {
  FILE *fp = fopen(filename, "r"); // open file for reading
  if (!fp) { // check if file opened successfully
    return -1;
  }

  char line[MAX_LINE_SIZE]; // buffer to hold each line
  int num_rows_read = 0; // number of rows successfully read
  int num_rows_allocated = 1; // number of rows currently allocated
  *rows = (csv_row_t *)malloc(sizeof(csv_row_t) * num_rows_allocated); // allocate initial array of rows

  while (fgets(line, MAX_LINE_SIZE, fp)) { // read each line until end of file
    int num_fields = 1; // start with one field (even if there are no commas)
    for (int i=0; i<strlen(line); i++) { // count number of commas to get number of fields
      if (line[i] == ',') {
        num_fields++;
      }
    }

    if (num_fields <= 0 || num_fields > 64) { // sanity check on number of fields
      continue;
    }

    if (num_rows_read >= num_rows_allocated) { // check if need to allocate more rows
      num_rows_allocated *= 2;
      *rows = (csv_row_t *)realloc(*rows, sizeof(csv_row_t) * num_rows_allocated);
    }

    csv_row_t *row = *rows + num_rows_read; // get pointer to current row
    row->num_fields = num_fields;
    row->fields = (char **)malloc(sizeof(char *) * num_fields); // allocate array of strings for fields

    char *token = strtok(line, ",\n"); // tokenize each field
    int field_num = 0;
    while (token) {
      int field_len = strlen(token);
      if (field_len > MAX_FIELD_SIZE) { // sanity check on field length
        continue;
      }

      row->fields[field_num] = (char *)malloc(field_len + 1); // allocate string for field
      strcpy(row->fields[field_num], token);
      field_num++;
      token = strtok(NULL, ",\n");
    }

    num_rows_read++;
  }

  fclose(fp); // close file
  *num_rows = num_rows_read; // return number of rows read
  return 0;
}

int main() {
  csv_row_t *rows; // pointer to array of rows
  int num_rows; // number of rows in the file
  int result = read_csv("example.csv", &rows, &num_rows); // read the csv file

  if (result != 0) { // check if there was an error
    printf("Error reading CSV file!\n");
    return -1;
  }

  // print out each row
  for (int i=0; i<num_rows; i++) {
    for (int j=0; j<rows[i].num_fields; j++) {
      printf("%s\t", rows[i].fields[j]);
    }
    printf("\n");
  }

  // free memory used by each row
  for (int i=0; i<num_rows; i++) {
    for (int j=0; j<rows[i].num_fields; j++) {
      free(rows[i].fields[j]);
    }
    free(rows[i].fields);
  }

  // free memory used by array of rows
  free(rows);

  return 0;
}