//GEMINI-pro DATASET v1.0 Category: File system simulation ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

#define SECTOR_SIZE 512

typedef struct {
  char *data;
  int size;
} Sector;

typedef struct {
  Sector *sectors;
  int num_sectors;
  int size;
} Disk;

typedef struct {
  Disk *disk;
  int current_sector;
} File;

Disk *create_disk(int num_sectors) {
  Disk *disk = malloc(sizeof(Disk));
  disk->sectors = malloc(sizeof(Sector) * num_sectors);
  disk->num_sectors = num_sectors;
  disk->size = num_sectors * SECTOR_SIZE;
  for (int i = 0; i < num_sectors; i++) {
    disk->sectors[i].data = malloc(SECTOR_SIZE);
    disk->sectors[i].size = SECTOR_SIZE;
  }
  return disk;
}

void destroy_disk(Disk *disk) {
  for (int i = 0; i < disk->num_sectors; i++) {
    free(disk->sectors[i].data);
  }
  free(disk->sectors);
  free(disk);
}

File *create_file(Disk *disk) {
  File *file = malloc(sizeof(File));
  file->disk = disk;
  file->current_sector = 0;
  return file;
}

void destroy_file(File *file) {
  free(file);
}

int write_sector(File *file, void *data, int size) {
  if (file->current_sector >= file->disk->num_sectors) {
    return -ENOSPC;
  }
  if (size > file->disk->sectors[file->current_sector].size) {
    return -EINVAL;
  }
  memcpy(file->disk->sectors[file->current_sector].data, data, size);
  file->disk->sectors[file->current_sector].size = size;
  file->current_sector++;
  return size;
}

int read_sector(File *file, void *data, int size) {
  if (file->current_sector >= file->disk->num_sectors) {
    return -ENOSPC;
  }
  if (size > file->disk->sectors[file->current_sector].size) {
    return -EINVAL;
  }
  memcpy(data, file->disk->sectors[file->current_sector].data, size);
  file->current_sector++;
  return size;
}

int main() {
  Disk *disk = create_disk(10);
  File *file = create_file(disk);

  char *data = "Hello, world!";
  int size = strlen(data);

  int ret = write_sector(file, data, size);
  if (ret < 0) {
    perror("write_sector");
    return EXIT_FAILURE;
  }

  char buffer[size];
  ret = read_sector(file, buffer, size);
  if (ret < 0) {
    perror("read_sector");
    return EXIT_FAILURE;
  }

  printf("%s\n", buffer);

  destroy_file(file);
  destroy_disk(disk);

  return EXIT_SUCCESS;
}