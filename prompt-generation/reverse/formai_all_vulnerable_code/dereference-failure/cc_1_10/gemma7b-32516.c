//Gemma-7B DATASET v1.0 Category: File Backup System ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_FILE_NAME_LENGTH 255

typedef struct FileEntry {
  char filename[MAX_FILE_NAME_LENGTH];
  time_t timestamp;
  struct FileEntry* next;
} FileEntry;

FileEntry* file_entry_insert(FileEntry* head, char* filename) {
  FileEntry* new_entry = malloc(sizeof(FileEntry));
  strcpy(new_entry->filename, filename);
  new_entry->timestamp = time(NULL);
  new_entry->next = NULL;

  if (head == NULL) {
    return new_entry;
  }

  head->next = new_entry;
  return head;
}

void file_entry_print(FileEntry* head) {
  FILE* file = fopen("backup.txt", "w");
  fprintf(file, "Files:\n");

  for (FileEntry* current = head; current; current = current->next) {
    fprintf(file, "%s - %s\n", current->filename, asctime(localtime(&current->timestamp)));
  }

  fclose(file);
}

int main() {
  FileEntry* head = NULL;

  // Insert some file entries
  file_entry_insert(head, "a.txt");
  file_entry_insert(head, "b.txt");
  file_entry_insert(head, "c.txt");

  // Print the file entries
  file_entry_print(head);

  return 0;
}