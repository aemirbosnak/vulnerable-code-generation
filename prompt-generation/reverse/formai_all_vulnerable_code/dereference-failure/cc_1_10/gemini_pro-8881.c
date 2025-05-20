//GEMINI-pro DATASET v1.0 Category: File system simulation ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

// File system structure
typedef struct {
  char name[20];
  int size;
  int blocks;
} File;

// Disk structure
typedef struct {
  int size;
  int num_blocks;
  File files[10];
} Disk;

// Create a new file system
Disk* create_filesystem(int size, int num_blocks) {
  Disk* disk = malloc(sizeof(Disk));
  disk->size = size;
  disk->num_blocks = num_blocks;
  for (int i = 0; i < 10; i++) {
    strcpy(disk->files[i].name, "");
    disk->files[i].size = 0;
    disk->files[i].blocks = 0;
  }
  return disk;
}

// Mount the file system
void mount_filesystem(Disk* disk) {
  printf("File system mounted successfully.\n");
}

// Unmount the file system
void unmount_filesystem(Disk* disk) {
  printf("File system unmounted successfully.\n");
}

// Create a new file
int create_file(Disk* disk, char* name, int size) {
  if (strlen(name) > 20) {
    printf("File name too long.\n");
    return -1;
  }
  if (size > disk->size) {
    printf("File too large.\n");
    return -1;
  }
  int num_blocks = size / disk->num_blocks;
  if (size % disk->num_blocks != 0) {
    num_blocks++;
  }
  for (int i = 0; i < 10; i++) {
    if (strcmp(disk->files[i].name, "") == 0) {
      strcpy(disk->files[i].name, name);
      disk->files[i].size = size;
      disk->files[i].blocks = num_blocks;
      return 0;
    }
  }
  printf("No more space available.\n");
  return -1;
}

// Delete a file
int delete_file(Disk* disk, char* name) {
  for (int i = 0; i < 10; i++) {
    if (strcmp(disk->files[i].name, name) == 0) {
      strcpy(disk->files[i].name, "");
      disk->files[i].size = 0;
      disk->files[i].blocks = 0;
      return 0;
    }
  }
  printf("File not found.\n");
  return -1;
}

// List all files
void list_files(Disk* disk) {
  printf("Files:\n");
  for (int i = 0; i < 10; i++) {
    if (strcmp(disk->files[i].name, "") != 0) {
      printf("  %s (%d bytes)\n", disk->files[i].name, disk->files[i].size);
    }
  }
}

// Main function
int main() {
  // Create a new file system
  Disk* disk = create_filesystem(1024, 10);

  // Mount the file system
  mount_filesystem(disk);

  // Create a new file
  create_file(disk, "file1.txt", 512);

  // List all files
  list_files(disk);

  // Delete the file
  delete_file(disk, "file1.txt");

  // Unmount the file system
  unmount_filesystem(disk);

  return 0;
}