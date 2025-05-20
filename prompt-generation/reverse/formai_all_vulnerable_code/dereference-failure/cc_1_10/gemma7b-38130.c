//Gemma-7B DATASET v1.0 Category: Data mining ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORD_SIZE 1024

typedef struct Record {
  char **data;
  int record_size;
} Record;

Record **load_records(char *filename, int *num_records) {
  FILE *fp = fopen(filename, "r");
  if (fp == NULL) {
    return NULL;
  }

  int num_records_read = 0;
  Record **records = NULL;
  char line[MAX_RECORD_SIZE];

  while (fgets(line, MAX_RECORD_SIZE, fp) != NULL) {
    Record *record = malloc(sizeof(Record));
    record->data = malloc(MAX_RECORD_SIZE);
    record->record_size = 0;

    char *p = line;
    while (*p) {
      record->data[record->record_size++] = *p++;
    }

    records = realloc(records, (num_records_read + 1) * sizeof(Record));
    records[num_records_read++] = record;
  }

  fclose(fp);
  *num_records = num_records_read;
  return records;
}

int main() {
  int num_records;
  Record **records = load_records("data.txt", &num_records);

  for (int i = 0; i < num_records; i++) {
    for (int j = 0; records[i]->data[j] != NULL; j++) {
      printf("%c ", records[i]->data[j]);
    }
    printf("\n");
  }

  return 0;
}