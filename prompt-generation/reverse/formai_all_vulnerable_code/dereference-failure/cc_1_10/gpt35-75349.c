//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

typedef struct {
  char *key;
  char *value;
} Metadata;

int main(int argc, char *argv[]) {
  if(argc != 2) {
    printf("USAGE: metadata_extractor <file_path>\n");
    exit(EXIT_FAILURE);
  }

  FILE *fp;
  char *line = NULL, *key = NULL, *value = NULL;
  size_t len = 0;
  ssize_t nread;
  int line_number = 0, meta_count = 0;
  Metadata *metadata = NULL;
  const char meta_indicator[] = "#META:";

  fp = fopen(argv[1], "r");
  if(fp == NULL) {
    printf("Error opening file: %s\n", strerror(errno));
    exit(EXIT_FAILURE);
  }

  while((nread = getline(&line, &len, fp)) != -1) {
    line_number++;
    if(strncmp(line, meta_indicator, strlen(meta_indicator)) == 0) {
      key = strtok(line+strlen(meta_indicator), ":");
      value = strtok(NULL, "\n");

      if(key != NULL && value != NULL) {
        meta_count++;
        metadata = realloc(metadata, sizeof(Metadata)*meta_count);

        metadata[meta_count-1].key = (char*) malloc(sizeof(char) * (strlen(key)+1));
        strcpy(metadata[meta_count-1].key, key);

        metadata[meta_count-1].value = (char*) malloc(sizeof(char) * (strlen(value)+1));
        strcpy(metadata[meta_count-1].value, value);
      }
    }
  }

  printf("Found %d metadata entries in file %s\n", meta_count, argv[1]);
  for(int i=0; i<meta_count; i++) {
    printf("%s: %s\n", metadata[i].key, metadata[i].value);
    free(metadata[i].key);
    free(metadata[i].value);
  }
  free(metadata);

  fclose(fp);
  if(line)
    free(line);

  return 0;
}