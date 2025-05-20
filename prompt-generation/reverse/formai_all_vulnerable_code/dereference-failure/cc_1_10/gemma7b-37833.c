//Gemma-7B DATASET v1.0 Category: Building a CSV Reader ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINES 100

typedef struct CSV_Record {
  char **data;
  int num_fields;
} CSV_Record;

CSV_Record *read_csv(char *filename) {
  CSV_Record *record = malloc(sizeof(CSV_Record));
  record->data = NULL;
  record->num_fields = 0;

  FILE *fp = fopen(filename, "r");
  if (fp == NULL) {
    return NULL;
  }

  // Read the number of lines in the CSV file
  int num_lines = 0;
  char line[MAX_LINES];
  while (fgets(line, MAX_LINES, fp) != NULL) {
    num_lines++;
  }

  // Allocate memory for the data array
  record->data = malloc(num_lines * sizeof(char *));

  // Read the CSV file again and fill the data array
  rewind(fp);
  int i = 0;
  while (fgets(line, MAX_LINES, fp) != NULL) {
    record->data[i++] = strdup(line);
  }

  // Close the file
  fclose(fp);

  return record;
}

int main() {
  char *filename = "example.csv";
  CSV_Record *record = read_csv(filename);

  if (record) {
    // Print the data
    for (int i = 0; i < record->num_fields; i++) {
      printf("%s,", record->data[0][i]);
    }
    printf("\n");

    // Free the memory
    free(record->data);
    free(record);
  } else {
    printf("Error reading CSV file.\n");
  }

  return 0;
}