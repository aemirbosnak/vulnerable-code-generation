//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LEN 1024
#define MAX_FIELDS 10

struct csvrecord {
  int nfields;
  char *fields[MAX_FIELDS];
};

typedef struct csvrecord CSVRecord;

CSVRecord* read_csv_record(char *s, char delim) {
  char *tok, *tmp;
  CSVRecord *rec = malloc(sizeof(CSVRecord));
  memset(rec, 0, sizeof(CSVRecord));
  tmp = strdup(s);
  rec->nfields = 0;
  tok = strtok(tmp, &delim);
  while(tok != NULL && rec->nfields < MAX_FIELDS) {
    rec->fields[rec->nfields++] = strdup(tok);
    tok = strtok(NULL, &delim);
  }
  free(tmp);
  return rec;
}

CSVRecord** read_csv_file(char *filename, char delim) {
  FILE *fp;
  char line[MAX_LINE_LEN];
  CSVRecord **records = NULL;
  int nrecords = 0;

  fp = fopen(filename, "r");
  if(!fp) {
    fprintf(stderr, "error opening file %s\n", filename);
    exit(1);
  }

  while(fgets(line, MAX_LINE_LEN, fp)) {
    CSVRecord *rec = read_csv_record(line, delim);
    records = realloc(records, sizeof(CSVRecord*) * (nrecords+1));
    records[nrecords++] = rec;
  }

  fclose(fp);
  return records;
}

void free_csv_record(CSVRecord *rec) {
  int i;
  for(i=0; i<rec->nfields; i++) {
    free(rec->fields[i]);
  }
  free(rec);
}

void free_csv_file(CSVRecord **records, int nrecords) {
  int i;
  for(i=0; i<nrecords; i++) {
    free_csv_record(records[i]);
  }
  free(records);
}

int main(int argc, char **argv) {
  char *filename = "example.csv";
  CSVRecord **records;
  int i, nrecords;

  records = read_csv_file(filename, ',');
  nrecords = sizeof(records) / sizeof(CSVRecord*);

  for(i=0; i<nrecords; i++) {
    CSVRecord *rec = records[i];
    int j;
    for(j=0; j<rec->nfields; j++) {
      printf("%s ", rec->fields[j]);
    }
    printf("\n");
  }

  return 0;
}