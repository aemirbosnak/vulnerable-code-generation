//GEMINI-pro DATASET v1.0 Category: Data recovery tool ; Style: lively
// Welcome to the C Data Recovery Tool!

// Let's start by including the necessary headers and defining some constants.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_SIZE 1024*1024  // Maximum size of a file we can recover
#define SECTOR_SIZE 512           // Typical sector size on most hard drives

// Now, let's define some handy structures and functions.
struct FileHeader {
    char filename[256];  // Filename (up to 255 characters)
    int size;           // File size in bytes
};

int readSector(FILE *disk, int sector, char *buffer) {
    // Seek to the specified sector and read it into the buffer.
    if (fseek(disk, sector * SECTOR_SIZE, SEEK_SET) != 0) {
        return -1;  // Error seeking to sector
    }
    if (fread(buffer, SECTOR_SIZE, 1, disk) != 1) {
        return -2;  // Error reading sector
    }
    return 0;  // Success
}

int writeSector(FILE *disk, int sector, char *buffer) {
    // Seek to the specified sector and write the buffer to it.
    if (fseek(disk, sector * SECTOR_SIZE, SEEK_SET) != 0) {
        return -1;  // Error seeking to sector
    }
    if (fwrite(buffer, SECTOR_SIZE, 1, disk) != 1) {
        return -2;  // Error writing sector
    }
    return 0;  // Success
}

// And now, the main event: file recovery!
int main(int argc, char **argv) {
    // Check if the user provided the correct number of arguments.
    if (argc != 3) {
        printf("Usage: %s <disk image> <output file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Open the disk image and output files.
    FILE *disk = fopen(argv[1], "rb");
    if (disk == NULL) {
        perror("Error opening disk image");
        return EXIT_FAILURE;
    }
    FILE *output = fopen(argv[2], "wb");
    if (output == NULL) {
        perror("Error opening output file");
        return EXIT_FAILURE;
    }

    // Read the boot sector and check if it's valid.
    char bootSector[SECTOR_SIZE];
    if (readSector(disk, 0, bootSector) != 0) {
        perror("Error reading boot sector");
        return EXIT_FAILURE;
    }
    if (bootSector[510] != 0x55 || bootSector[511] != 0xaa) {
        printf("Invalid boot sector");
        return EXIT_FAILURE;
    }

    // Get the location of the FAT and root directory.
    int fatSector = *(unsigned short *)&bootSector[16];
    int rootSector = *(unsigned short *)&bootSector[488];

    // Read the FAT table and locate the first free sector.
    char fat[SECTOR_SIZE * 16];  // FAT table can be up to 16 sectors long
    int freeSector = 0;
    for (int i = 0; i < 16; i++) {
        if (readSector(disk, fatSector + i, fat + i * SECTOR_SIZE) != 0) {
            perror("Error reading FAT table");
            return EXIT_FAILURE;
        }
        for (int j = 0; j < SECTOR_SIZE; j++) {
            if (fat[i * SECTOR_SIZE + j] == 0x00) {
                freeSector = i * SECTOR_SIZE + j;
                break;
            }
        }
    }

    // Walk through the root directory and search for deleted files.
    char rootDirectory[SECTOR_SIZE * 16];  // Root directory can be up to 16 sectors long
    if (readSector(disk, rootSector, rootDirectory) != 0) {
        perror("Error reading root directory");
        return EXIT_FAILURE;
    }
    for (int i = 0; i < 16; i++) {
        for (int j = 0; j < SECTOR_SIZE; j += sizeof(struct FileHeader)) {
            struct FileHeader *fileHeader = (struct FileHeader *)(rootDirectory + i * SECTOR_SIZE + j);
            if (fileHeader->filename[0] == 0x00) {  // End of directory reached
                break;
            }
            if (fileHeader->filename[0] == 0xe5) {  // Deleted file
                // Recover the file by copying it to the first free sector.
                writeSector(disk, freeSector, fileHeader->filename + 1);
                freeSector++;
                // Keep recovering sectors until we reach the end of the file.
                while (fat[freeSector] != 0x00) {
                    writeSector(disk, freeSector, rootDirectory + fat[freeSector] * SECTOR_SIZE);
                    freeSector++;
                }
            }
        }
    }

    // Close the disk image and output files.
    fclose(disk);
    fclose(output);

    // Success!
    printf("File recovery complete.\n");
    return EXIT_SUCCESS;
}