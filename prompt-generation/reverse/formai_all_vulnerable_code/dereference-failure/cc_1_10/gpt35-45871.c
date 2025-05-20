//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

#define MAX_METADATA_SIZE 10000

char* read_metadata_from_file(char* file_name);
bool metadata_contains_injectable_content(char* metadata);

int main(int argc, char* argv[]) {

   if(argc != 2) {
      printf("Error: Usage: ./metadata_extractor <file_name>\n");
      exit(1);
  }

  char* metadata = read_metadata_from_file(argv[1]);

  bool is_injectable = metadata_contains_injectable_content(metadata);

  if(is_injectable) {
    printf("WARNING: The metadata contains injectable content!\n");
  } else {
    printf("The metadata does not contain injectable content.\n");
  }

  free(metadata);
  
  return 0;
}

char* read_metadata_from_file(char* file_name) {
  FILE* f = fopen(file_name, "r");

  if(f == NULL) {
    printf("Error: Could not open file %s.\n", file_name);
    exit(1);
  }

  char* metadata = (char*)malloc(MAX_METADATA_SIZE * sizeof(char));
  char buffer[1000];

  while(fgets(buffer, sizeof(buffer), f)) {
    strcat(metadata, buffer);
    if(strlen(metadata) > MAX_METADATA_SIZE) {
      printf("Error: Metadata exceeds maximum size of %d.\n", MAX_METADATA_SIZE);
      exit(1);
    }
  }

  fclose(f);
  return metadata;
}

bool metadata_contains_injectable_content(char* metadata) {
  char* injectable_content[] = {"<script>", "alert", "prompt", "<iframe>", "onload", "onerror"};
  int num_injectable_content = sizeof(injectable_content)/sizeof(injectable_content[0]);

  bool contains_injectable_content = false;

  for(int i = 0; i < num_injectable_content; i++) {
    char* content = injectable_content[i];
    if(strstr(metadata, content) != NULL) {
      contains_injectable_content = true;
      break;
    }
  }

  return contains_injectable_content;
}