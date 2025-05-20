//FormAI DATASET v1.0 Category: Data recovery tool ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BLOCK_SIZE 512

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: %s <file to recover>\n", argv[0]);
        return 1;
    }

    // Open the input file
    FILE *input = fopen(argv[1], "rb");
    if (input == NULL)
    {
        printf("Error: Could not open input file\n");
        return 1;
    }

    // Create the output file
    char outputFileName[50];
    strncpy(outputFileName, argv[1], strlen(argv[1]) - 3);
    strcat(outputFileName, "recovered");
    FILE *output = fopen(outputFileName, "wb");

    // Check if output file was created successfully
    if (output == NULL)
    {
        printf("Error: Could not create output file\n");
        return 1;
    }

    // Read blocks from input file and write to output file
    unsigned char buffer[BLOCK_SIZE];
    int bytesRead;
    int blockCount = 0;
    while ((bytesRead = fread(buffer, 1, BLOCK_SIZE, input)) > 0)
    {
        blockCount++;

        // Check if block is a JPEG header block
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            // Reset block count for next file
            blockCount = 1;

            // Write current block to output file
            fwrite(buffer, 1, bytesRead, output);
        }
        else if (blockCount > 1)
        {
            // Write current block to output file
            fwrite(buffer, 1, bytesRead, output);
        }
    }

    // Close files
    fclose(input);
    fclose(output);

    printf("File recovery successful\n");

    return 0;
}