//FormAI DATASET v1.0 Category: Data recovery tool ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

// Define sector size
#define SECTOR_SIZE 512

// Define error messages
const char* ERR_OPEN_DISK = "Error: Could not open disk image.";
const char* ERR_SEEK = "Error: Could not seek to sector.";
const char* ERR_READ = "Error: Could not read sector.";

// Function to read sector from disk
int read_sector(FILE* fp, uint32_t sector, void* buffer)
{
    // Calculate byte offset for sector
    uint64_t byteOffset = (uint64_t)sector * SECTOR_SIZE;

    // Seek to sector
    if (fseek(fp, byteOffset, SEEK_SET) != 0)
    {
        printf("%s\n", ERR_SEEK);
        return 1;
    }

    // Read sector
    if (fread(buffer, SECTOR_SIZE, 1, fp) != 1)
    {
        printf("%s\n", ERR_READ);
        return 1;
    }

    return 0;
}

// Function to check if sector is empty
int sector_is_empty(void* sector)
{
    for (int i = 0; i < SECTOR_SIZE; i++)
    {
        if (((char*)sector)[i] != 0)
        {
            return 0;
        }
    }

    return 1;
}

int main(int argc, char** argv)
{
    // Check number of arguments
    if (argc != 3)
    {
        printf("Usage: datarecovery <diskimage> <outputfile>\n");
        return 1;
    }

    // Open disk image file for reading
    FILE* disk = fopen(argv[1], "rb");
    if (!disk)
    {
        printf("%s\n", ERR_OPEN_DISK);
        return 1;
    }

    // Create output file for recovered data
    FILE* output = fopen(argv[2], "wb");
    if (!output)
    {
        printf("Error: Could not create output file.\n");
        fclose(disk);
        return 1;
    }

    // Define buffer for sector data
    void* sectorBuffer = malloc(SECTOR_SIZE);

    // Loop through disk sectors
    for (uint32_t sector = 0; ; sector++)
    {
        // Read sector from disk
        if (read_sector(disk, sector, sectorBuffer) != 0)
        {
            break;
        }

        // Check if sector is empty
        if (!sector_is_empty(sectorBuffer))
        {
            // Write non-empty sector to output file
            fwrite(sectorBuffer, SECTOR_SIZE, 1, output);
        }
    }

    // Free sector buffer
    free(sectorBuffer);

    // Close files
    fclose(disk);
    fclose(output);

    // Print success message
    printf("Data recovery successful!\n");

    return 0;
}