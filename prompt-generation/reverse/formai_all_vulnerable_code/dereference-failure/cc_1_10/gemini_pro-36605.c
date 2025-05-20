//GEMINI-pro DATASET v1.0 Category: Data recovery tool ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <ctype.h>
#include <string.h>

#define SECTOR_SIZE 512

// Function to read a sector from the disk
int read_sector(int drive, int sector, uint8_t *buffer) {
  // Open the disk
  FILE *disk = fopen("disk.img", "rb");
  if (disk == NULL) {
    return -1;
  }

  // Seek to the sector
  if (fseek(disk, sector * SECTOR_SIZE, SEEK_SET) != 0) {
    return -1;
  }

  // Read the sector
  if (fread(buffer, SECTOR_SIZE, 1, disk) != 1) {
    return -1;
  }

  // Close the disk
  fclose(disk);

  return 0;
}

// Function to write a sector to the disk
int write_sector(int drive, int sector, uint8_t *buffer) {
  // Open the disk
  FILE *disk = fopen("disk.img", "wb");
  if (disk == NULL) {
    return -1;
  }

  // Seek to the sector
  if (fseek(disk, sector * SECTOR_SIZE, SEEK_SET) != 0) {
    return -1;
  }

  // Write the sector
  if (fwrite(buffer, SECTOR_SIZE, 1, disk) != 1) {
    return -1;
  }

  // Close the disk
  fclose(disk);

  return 0;
}

// Function to search for a file on the disk
int search_file(char *filename, int *sector) {
  // Read the boot sector
  uint8_t boot_sector[SECTOR_SIZE];
  if (read_sector(0, 0, boot_sector) != 0) {
    return -1;
  }

  // Get the number of sectors per FAT entry
  int sectors_per_fat = (boot_sector[11] + (boot_sector[12] << 8)) / boot_sector[16];

  // Get the number of sectors in the FAT
  int fat_size = boot_sector[22] + (boot_sector[23] << 8);

  // Get the number of sectors in the root directory
  int root_size = (boot_sector[17] + (boot_sector[18] << 8)) * boot_sector[19];

  // Get the first sector of the root directory
  int root_sector = sectors_per_fat * fat_size;

  // Search the root directory for the file
  for (int i = 0; i < root_size; i++) {
    // Read the directory entry
    uint8_t directory_entry[32];
    if (read_sector(root_sector + (i / 16), i % 16, directory_entry) != 0) {
      return -1;
    }

    // Check if the file name matches
    if (strncmp((char *)directory_entry + 0, filename, 11) == 0) {
      // Get the starting sector of the file
      *sector = (directory_entry[26] + (directory_entry[27] << 8)) + ((directory_entry[20] + (directory_entry[21] << 8)) << 16);

      return 0;
    }
  }

  return -1;
}

// Function to recover a file from the disk
int recover_file(char *filename) {
  // Find the file on the disk
  int sector;
  if (search_file(filename, &sector) != 0) {
    return -1;
  }

  // Open the output file
  FILE *output = fopen(filename, "wb");
  if (output == NULL) {
    return -1;
  }

  // Read the file sectors
  while (sector != 0xFFFFFFFF) {
    // Read the sector
    uint8_t sector_buffer[SECTOR_SIZE];
    if (read_sector(sector, 0, sector_buffer) != 0) {
      return -1;
    }

    // Write the sector to the output file
    if (fwrite(sector_buffer, SECTOR_SIZE, 1, output) != 1) {
      return -1;
    }

    // Get the next sector
    sector = (sector_buffer[27] + (sector_buffer[28] << 8)) + ((sector_buffer[25] + (sector_buffer[26] << 8)) << 16);
  }

  // Close the output file
  fclose(output);

  return 0;
}

int main(int argc, char **argv) {
  if (argc != 3) {
    printf("Usage: %s <filename> <sector>\n", argv[0]);
    return 1;
  }

  // Recover the file
  if (recover_file(argv[1]) != 0) {
    printf("Error recovering file.\n");
    return 1;
  }

  return 0;
}