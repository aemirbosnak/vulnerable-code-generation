//FormAI DATASET v1.0 Category: Data recovery tool ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BLOCK_SIZE 512

typedef unsigned char BYTE;

int main(int argc, char *argv[])
{
    // Ensure correct usage
    if (argc != 2)
    {
        fprintf(stderr, "Usage: ./recover image\n");
        return 1;
    }

    // Open input file
    FILE *input_file = fopen(argv[1], "r");

    // Check that input file can be opened
    if (input_file == NULL)
    {
        fprintf(stderr, "Could not open %s.\n", argv[1]);
        return 2;
    }

    // Create output file buffer
    BYTE buffer[BLOCK_SIZE];

    // Create output file pointer
    FILE *output_file;

    // Create boolean to see if a jpeg is currently being written
    int jpeg_found = 0;

    // Create counter for numbered files
    int file_number = 0;

    // Create filename array for sprintf to use
    char filename[8];

    // Loop through input file
    while (fread(buffer, BLOCK_SIZE, 1, input_file) == 1)
    {
        // Check for jpeg signature
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            if (jpeg_found == 1)
            {
                fclose(output_file);
            }
            else
            {
                jpeg_found = 1;
            }

            sprintf(filename, "%03i.jpg", file_number++);
            output_file = fopen(filename, "w");
        }

        if (jpeg_found == 1)
        {
            fwrite(buffer, BLOCK_SIZE, 1, output_file);
        }
    }

    fclose(input_file);
    fclose(output_file);

    return 0;
}