//GEMINI-pro DATASET v1.0 Category: File Backup System ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define VERSION "1.0"

struct FileMetadata {
  char* name;
  size_t size;
  time_t timestamp;
};

struct FileBackupSystem {
  char* name;
  char* path;
  size_t capacity;
  size_t num_files;
  struct FileMetadata* files;
};

void init_file_backup_system(struct FileBackupSystem* system, char* name, char* path, size_t capacity) {
  system->name = name;
  system->path = path;
  system->capacity = capacity;
  system->num_files = 0;
  system->files = malloc(sizeof(struct FileMetadata) * capacity);
}

void add_file_to_backup_system(struct FileBackupSystem* system, char* name, size_t size) {
  if (system->num_files == system->capacity) {
    printf("Error: The file backup system is full.\n");
    return;
  }

  struct FileMetadata* file = &system->files[system->num_files++];
  file->name = name;
  file->size = size;
  file->timestamp = time(NULL);
}

void print_file_backup_system(struct FileBackupSystem* system) {
  printf("File Backup System: %s\n", system->name);
  printf("Path: %s\n", system->path);
  printf("Capacity: %zu\n", system->capacity);
  printf("Number of files: %zu\n", system->num_files);

  for (size_t i = 0; i < system->num_files; i++) {
    struct FileMetadata* file = &system->files[i];
    printf("File: %s, Size: %zu, Timestamp: %s\n", file->name, file->size, ctime(&file->timestamp));
  }
}

int main(int argc, char** argv) {
  if (argc != 4) {
    printf("Usage: %s <name> <path> <capacity>\n", argv[0]);
    return 1;
  }

  char* name = argv[1];
  char* path = argv[2];
  size_t capacity = atoi(argv[3]);

  struct FileBackupSystem system;
  init_file_backup_system(&system, name, path, capacity);

  add_file_to_backup_system(&system, "file1.txt", 100);
  add_file_to_backup_system(&system, "file2.txt", 200);
  add_file_to_backup_system(&system, "file3.txt", 300);

  print_file_backup_system(&system);

  return 0;
}