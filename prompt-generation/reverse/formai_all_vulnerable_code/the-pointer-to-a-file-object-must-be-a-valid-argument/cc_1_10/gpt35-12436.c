//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  char *key;
  char *value;
} Metadata;

// a simple function to print a Metadata object
void print_metadata(Metadata *data) {
  printf("Key: %s\nValue: %s\n", data->key, data->value);
}

// a simple function to create a new Metadata object
Metadata* create_metadata(char *key, char *value) {
  Metadata *new_metadata = malloc(sizeof(Metadata));
  new_metadata->key = strdup(key);
  new_metadata->value = strdup(value);
  return new_metadata;
}

// a function to extract Metadata from a C source file
Metadata** extract_metadata(char *filename) {
  // open the file for reading
  FILE *file;
  file = fopen(filename, "r");

  // allocate space for an array of Metadata objects
  Metadata **metadata_list = malloc(sizeof(Metadata*) * 10);

  char line[100]; // assume each line is no longer than 100 characters
  char *key, *value;
  int num_metadata = 0;

  // read in each line of the file
  while(fgets(line, 100, file) != NULL) {
    // check if this line contains Metadata information
    if(strncmp(line, "// @", 4) == 0) {
      key = strtok(line+4, ":");
      value = strtok(NULL, "\n");

      // create a new Metadata object and add it to the array
      metadata_list[num_metadata] = create_metadata(key, value);
      num_metadata++;
    }
  }

  // close the file
  fclose(file);

  // make sure we terminate the array with a NULL pointer
  metadata_list[num_metadata] = NULL;

  return metadata_list;
}

int main(int argc, char *argv[]) {
  // check if the user provided a filename argument
  if(argc <= 1) {
    printf("Usage: ./metadata_extractor <filename>\n");
    exit(1);
  }

  // extract the metadata and print it out
  Metadata **metadata_list = extract_metadata(argv[1]);
  int i = 0;
  while(metadata_list[i] != NULL) {
    print_metadata(metadata_list[i]);
    i++;
  }

  // free the memory we allocated for the metadata objects
  i = 0;
  while(metadata_list[i] != NULL) {
    free(metadata_list[i]->key);
    free(metadata_list[i]->value);
    free(metadata_list[i]);
    i++;
  }
  free(metadata_list);

  return 0;
}