//Gemma-7B DATASET v1.0 Category: Disk space analyzer ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>

struct DirEntry {
  char name[256];
  long size;
  struct DirEntry* next;
};

void analyzeDir(char* dirPath) {
  DIR* dir = opendir(dirPath);
  struct DirEntry* head = NULL;
  struct DirEntry* tail = NULL;

  if (dir) {
    struct dirent* entry;
    while ((entry = readdir(dir)) != NULL) {
      struct stat statBuf;
      stat(entry->d_name, &statBuf);
      long size = statBuf.st_size;

      struct DirEntry* newEntry = malloc(sizeof(struct DirEntry));
      strcpy(newEntry->name, entry->d_name);
      newEntry->size = size;
      newEntry->next = NULL;

      if (head == NULL) {
        head = newEntry;
        tail = newEntry;
      } else {
        tail->next = newEntry;
        tail = newEntry;
      }
    }
    closedir(dir);
  }

  // Print directory analysis results
  tail = head;
  while (tail) {
    printf("%s: %ld bytes\n", tail->name, tail->size);
    tail = tail->next;
  }
}

int main() {
  analyzeDir("/path/to/directory");
  return 0;
}