//GEMINI-pro DATASET v1.0 Category: Data recovery tool ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SECTOR_SIZE 512

typedef struct {
  char filename[50];
  unsigned int starting_sector;
  unsigned int sector_count;
} file_entry;

int main() {
  // Open the disk image file
  FILE *disk_image = fopen("disk.img", "rb");
  if (disk_image == NULL) {
    fprintf(stderr, "Error opening disk image file\n");
    return 1;
  }

  // Read the boot sector
  char boot_sector[SECTOR_SIZE];
  fread(boot_sector, SECTOR_SIZE, 1, disk_image);

  // Check if the boot sector is valid
  if (boot_sector[0] != 0xEB || boot_sector[1] != 0x3C || boot_sector[2] != 0x90) {
    fprintf(stderr, "Error: Invalid boot sector\n");
    return 1;
  }

  // Get the number of sectors per cluster
  unsigned int sectors_per_cluster = boot_sector[11];

  // Get the number of sectors on the disk
  unsigned int total_sectors = *(unsigned int *)&boot_sector[19];

  // Read the FAT
  unsigned char *fat = malloc(total_sectors * sizeof(unsigned char));
  fread(fat, sizeof(unsigned char), total_sectors, disk_image);

  // Read the root directory
  file_entry root_directory[512];
  fread(root_directory, sizeof(file_entry), 512, disk_image);

  // Print the files in the root directory
  for (int i = 0; i < 512; i++) {
    if (root_directory[i].filename[0] != 0x00) {
      printf("%s  %u  %u\n", root_directory[i].filename,
             root_directory[i].starting_sector, root_directory[i].sector_count);
    }
  }

  // Close the disk image file
  fclose(disk_image);

  return 0;
}