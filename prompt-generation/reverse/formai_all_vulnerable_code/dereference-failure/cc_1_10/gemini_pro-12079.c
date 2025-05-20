//GEMINI-pro DATASET v1.0 Category: Building a CSV Reader ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_NUM_FIELDS 10

typedef struct {
  char *line;
  int num_fields;
  char *fields[MAX_NUM_FIELDS];
} csv_record;

csv_record *csv_record_new(char *line) {
  csv_record *record = malloc(sizeof(csv_record));
  record->line = line;
  record->num_fields = 0;
  for (int i = 0; i < MAX_NUM_FIELDS; i++) {
    record->fields[i] = NULL;
  }
  return record;
}

void csv_record_free(csv_record *record) {
  free(record->line);
  for (int i = 0; i < record->num_fields; i++) {
    free(record->fields[i]);
  }
  free(record);
}

int csv_record_parse(csv_record *record) {
  char *line = record->line;
  char *field = strtok(line, ",");
  while (field != NULL) {
    record->fields[record->num_fields++] = field;
    field = strtok(NULL, ",");
  }
  return record->num_fields;
}

int main() {
  FILE *fp = fopen("data.csv", "r");
  if (fp == NULL) {
    perror("Error opening file");
    return EXIT_FAILURE;
  }

  char line[MAX_LINE_LENGTH];
  while (fgets(line, MAX_LINE_LENGTH, fp) != NULL) {
    csv_record *record = csv_record_new(line);
    csv_record_parse(record);
    for (int i = 0; i < record->num_fields; i++) {
      printf("%s\n", record->fields[i]);
    }
    csv_record_free(record);
  }

  fclose(fp);

  return EXIT_SUCCESS;
}