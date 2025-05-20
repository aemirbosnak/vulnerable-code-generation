//GEMINI-pro DATASET v1.0 Category: Data recovery tool ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define SECTOR_SIZE 512

// Function to read a sector from the disk
bool read_sector(FILE *disk, unsigned int sector, unsigned char *buf)
{
    // Seek to the start of the sector
    if (fseek(disk, sector * SECTOR_SIZE, SEEK_SET) != 0)
    {
        return false;
    }

    // Read the sector into the buffer
    if (fread(buf, SECTOR_SIZE, 1, disk) != 1)
    {
        return false;
    }

    return true;
}

// Function to write a sector to the disk
bool write_sector(FILE *disk, unsigned int sector, unsigned char *buf)
{
    // Seek to the start of the sector
    if (fseek(disk, sector * SECTOR_SIZE, SEEK_SET) != 0)
    {
        return false;
    }

    // Write the sector from the buffer
    if (fwrite(buf, SECTOR_SIZE, 1, disk) != 1)
    {
        return false;
    }

    return true;
}

// Function to recover a file from the disk
bool recover_file(FILE *disk, unsigned int start_sector, const char *filename)
{
    // Allocate a buffer to store the file data
    unsigned char *buf = malloc(SECTOR_SIZE);
    if (buf == NULL)
    {
        return false;
    }

    // Open the file for writing
    FILE *file = fopen(filename, "wb");
    if (file == NULL)
    {
        free(buf);
        return false;
    }

    // Read the sectors from the disk and write them to the file
    unsigned int sector = start_sector;
    while (read_sector(disk, sector, buf))
    {
        fwrite(buf, SECTOR_SIZE, 1, file);
        sector++;
    }

    // Close the file
    fclose(file);

    // Free the buffer
    free(buf);

    return true;
}

// Main function
int main(int argc, char **argv)
{
    // Check if the command line arguments are valid
    if (argc != 4)
    {
        printf("Usage: %s <disk image> <start sector> <filename>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Open the disk image file
    FILE *disk = fopen(argv[1], "rb+");
    if (disk == NULL)
    {
        perror("Error opening disk image file");
        return EXIT_FAILURE;
    }

    // Get the start sector
    unsigned int start_sector = atoi(argv[2]);

    // Get the filename
    const char *filename = argv[3];

    // Recover the file
    if (!recover_file(disk, start_sector, filename))
    {
        perror("Error recovering file");
        fclose(disk);
        return EXIT_FAILURE;
    }

    // Close the disk image file
    fclose(disk);

    return EXIT_SUCCESS;
}