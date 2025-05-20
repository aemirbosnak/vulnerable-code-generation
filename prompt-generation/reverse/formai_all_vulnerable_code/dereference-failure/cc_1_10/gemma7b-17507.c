//Gemma-7B DATASET v1.0 Category: File Backup System ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>

#define MAX_FILES 10
#define BUFFER_SIZE 4096

typedef struct file_entry {
  char name[256];
  int size;
  struct file_entry* next;
} file_entry;

file_entry* head = NULL;

void add_file(char* name, int size) {
  file_entry* new_entry = malloc(sizeof(file_entry));
  strcpy(new_entry->name, name);
  new_entry->size = size;
  new_entry->next = head;
  head = new_entry;
}

void backup_files() {
  FILE* backup_file = fopen("backup.dat", "w");
  file_entry* current_entry = head;
  while (current_entry) {
    fprintf(backup_file, "%s\n", current_entry->name);
    fprintf(backup_file, "%d\n", current_entry->size);
    current_entry = current_entry->next;
  }
  fclose(backup_file);
}

void restore_files() {
  FILE* backup_file = fopen("backup.dat", "r");
  char name[256];
  int size;
  while (fscanf(backup_file, "%s\n", name) != EOF) {
    fscanf(backup_file, "%d\n", &size);
    add_file(name, size);
  }
  fclose(backup_file);
}

int main() {
  add_file("test.txt", 100);
  add_file("image.jpg", 500);
  backup_files();
  restore_files();
  file_entry* current_entry = head;
  while (current_entry) {
    printf("%s\n", current_entry->name);
    printf("%d\n", current_entry->size);
    current_entry = current_entry->next;
  }
  return 0;
}