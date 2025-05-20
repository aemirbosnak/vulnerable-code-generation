//FormAI DATASET v1.0 Category: Data recovery tool ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Define the type for our file pointer */
typedef struct {
  FILE *file;
  char *filename;
} dataFile;

/* Define the type for our recovered data */
typedef struct {
  char *data;
  size_t size;
} recoveredData;

/*
  Open a file and return a pointer to the dataFile struct.
  Returns NULL if the file cannot be opened.
*/
dataFile *openFile(char *filename) {
  dataFile *df = malloc(sizeof(dataFile));
  df->filename = filename;
  df->file = fopen(filename, "rb");
  if (df->file == NULL) {
    free(df);
    return NULL;
  }
  return df;
}

/*
  Close a file and free the associated dataFile struct.
*/
void closeFile(dataFile *df) {
  fclose(df->file);
  free(df->filename);
  free(df);
}

/*
  Read the entire contents of the file into memory and return a pointer to a recoveredData struct.
  Returns NULL if the file cannot be read.
*/
recoveredData *recoverData(dataFile *df) {
  fseek(df->file, 0, SEEK_END);
  size_t size = ftell(df->file);
  fseek(df->file, 0, SEEK_SET);

  char *data = malloc(size);
  if (fread(data, 1, size, df->file) != size) {
    free(data);
    return NULL;
  }

  recoveredData *rd = malloc(sizeof(recoveredData));
  rd->data = data;
  rd->size = size;
  return rd;
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s filename\n", argv[0]);
    return 1;
  }

  dataFile *df = openFile(argv[1]);
  if (df == NULL) {
    printf("Could not open file: %s\n", argv[1]);
    return 1;
  }

  recoveredData *rd = recoverData(df);
  if (rd == NULL) {
    printf("Could not recover data from file: %s\n", argv[1]);
  } else {
    printf("Successfully recovered %zu bytes from file: %s\n", rd->size, argv[1]);
    /* Do something with rd->data */
    free(rd->data);
    free(rd);
  }

  closeFile(df);
  return 0;
}