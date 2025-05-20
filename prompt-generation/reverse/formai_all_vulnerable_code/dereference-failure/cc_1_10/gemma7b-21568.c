//Gemma-7B DATASET v1.0 Category: System boot optimizer ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <string.h>

#define MAX_FILE_SIZE 1024

typedef struct FILE_HEADER {
  char filename[256];
  int size;
  struct FILE_HEADER* next;
} FILE_HEADER;

FILE_HEADER* file_header_create(char* filename, int size) {
  FILE_HEADER* header = malloc(sizeof(FILE_HEADER));
  strcpy(header->filename, filename);
  header->size = size;
  header->next = NULL;
  return header;
}

void file_header_add(FILE_HEADER* header, char* filename, int size) {
  FILE_HEADER* new_header = file_header_create(filename, size);
  if (header) {
    header->next = new_header;
  } else {
    header = new_header;
  }
  return;
}

int main() {
  FILE_HEADER* file_headers = NULL;
  char filename[256];
  int size;

  printf("Enter filename: ");
  scanf("%s", filename);

  printf("Enter file size: ");
  scanf("%d", &size);

  file_header_add(file_headers, filename, size);

  printf("File header added.\n");

  FILE_HEADER* current_header = file_headers;
  while (current_header) {
    printf("Filename: %s\n", current_header->filename);
    printf("Size: %d\n", current_header->size);
    current_header = current_header->next;
  }

  return 0;
}