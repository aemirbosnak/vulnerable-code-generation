//Gemma-7B DATASET v1.0 Category: File Backup System ; Style: curious
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_FILES 10
#define MAX_FILE_SIZE 1024

struct FileEntry {
  char *filename;
  int size;
  struct FileEntry *next;
};

typedef struct FileEntry FileEntry;

int main() {
  FileEntry *head = NULL;
  char filename[MAX_FILES][MAX_FILE_SIZE];
  int file_size[MAX_FILES];
  int i = 0;

  // Allocate memory for the first file entry
  head = malloc(sizeof(FileEntry));
  head->filename = malloc(MAX_FILE_SIZE);
  head->size = 0;
  head->next = NULL;

  // Loop to get file information
  while (i < MAX_FILES) {
    printf("Enter filename: ");
    scanf("%s", filename[i]);

    printf("Enter file size: ");
    scanf("%d", &file_size[i]);

    // Allocate memory for the file entry
    FileEntry *new_entry = malloc(sizeof(FileEntry));
    new_entry->filename = malloc(MAX_FILE_SIZE);
    new_entry->size = file_size[i];
    new_entry->next = NULL;

    // Insert the new file entry into the linked list
    if (head->next != NULL) {
      head->next->next = new_entry;
    } else {
      head->next = new_entry;
    }

    i++;
  }

  // Print the file entries
  printf("File entries:**\n");
  for (i = 0; i < MAX_FILES; i++) {
    printf("Filename: %s\n", filename[i]);
    printf("Size: %d\n", file_size[i]);
  }

  return 0;
}