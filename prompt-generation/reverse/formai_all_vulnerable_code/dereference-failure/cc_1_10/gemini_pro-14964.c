//GEMINI-pro DATASET v1.0 Category: Data recovery tool ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum size of the file to be recovered.
#define MAX_FILE_SIZE 100000

// Define the maximum number of files to be recovered.
#define MAX_FILES 10

// Define the structure of a file.
typedef struct {
  char name[50];
  char data[MAX_FILE_SIZE];
  int size;
} File;

// Define the structure of a sector.
typedef struct {
  char data[512];
} Sector;

// Define the structure of a disk.
typedef struct {
  char name[50];
  Sector sectors[1000];
  int num_sectors;
} Disk;

// Create a new file.
File *new_file(char *name) {
  File *file = malloc(sizeof(File));
  strcpy(file->name, name);
  file->size = 0;
  return file;
}

// Add data to a file.
void add_data_to_file(File *file, char *data, int size) {
  memcpy(file->data + file->size, data, size);
  file->size += size;
}

// Create a new sector.
Sector *new_sector(char *data) {
  Sector *sector = malloc(sizeof(Sector));
  memcpy(sector->data, data, 512);
  return sector;
}

// Add a sector to a disk.
void add_sector_to_disk(Disk *disk, Sector *sector) {
  disk->sectors[disk->num_sectors++] = *sector;
}

// Create a new disk.
Disk *new_disk(char *name) {
  Disk *disk = malloc(sizeof(Disk));
  strcpy(disk->name, name);
  disk->num_sectors = 0;
  return disk;
}

// Read a file from a disk.
File *read_file_from_disk(Disk *disk, char *name) {
  for (int i = 0; i < disk->num_sectors; i++) {
    Sector *sector = &disk->sectors[i];
    if (strncmp(sector->data, name, strlen(name)) == 0) {
      File *file = new_file(name);
      add_data_to_file(file, sector->data + strlen(name), 512 - strlen(name));
      for (int j = i + 1; j < disk->num_sectors; j++) {
        sector = &disk->sectors[j];
        add_data_to_file(file, sector->data, 512);
      }
      return file;
    }
  }
  return NULL;
}

// Write a file to a disk.
void write_file_to_disk(Disk *disk, File *file) {
  int num_sectors = (file->size + 511) / 512;
  for (int i = 0; i < num_sectors; i++) {
    Sector *sector = new_sector(file->data + i * 512);
    add_sector_to_disk(disk, sector);
  }
}

// Recover files from a disk.
void recover_files_from_disk(Disk *disk) {
  for (int i = 0; i < disk->num_sectors; i++) {
    Sector *sector = &disk->sectors[i];
    if (strncmp(sector->data, "FILE", 4) == 0) {
      char *name = sector->data + 4;
      File *file = new_file(name);
      add_data_to_file(file, sector->data + strlen(name) + 1, 512 - strlen(name) - 1);
      for (int j = i + 1; j < disk->num_sectors; j++) {
        sector = &disk->sectors[j];
        add_data_to_file(file, sector->data, 512);
      }
      write_file_to_disk(disk, file);
    }
  }
}

// Main function.
int main() {
  // Create a new disk.
  Disk *disk = new_disk("disk.img");

  // Read a file from the disk.
  File *file = read_file_from_disk(disk, "file1.txt");

  // Print the contents of the file.
  printf("%s\n", file->data);

  // Recover files from the disk.
  recover_files_from_disk(disk);

  return 0;
}