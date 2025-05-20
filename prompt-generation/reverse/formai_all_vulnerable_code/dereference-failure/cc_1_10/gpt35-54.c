//FormAI DATASET v1.0 Category: Compression algorithms ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 256

// Paranoid Compression Algorithm
int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        printf("Usage: paranoid-compress <input_file> <output_file>\n");
        exit(EXIT_FAILURE);
    }

    FILE *input_file = fopen(argv[1], "rb");
    if (input_file == NULL)
    {
        printf("Error: Cannot open input file %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    FILE *output_file = fopen(argv[2], "wb");
    if (output_file == NULL)
    {
        printf("Error: Cannot open output file %s\n", argv[2]);
        exit(EXIT_FAILURE);
    }

    unsigned char buffer[MAX_SIZE];
    int count = 1;

    while (!feof(input_file))
    {
        int bytes_read = fread(buffer, sizeof(unsigned char), MAX_SIZE, input_file);
        if (bytes_read == 0)
        {
            break;
        }

        // Paranoid Encoding
        for (int i = 0; i < bytes_read; i++)
        {
            if (buffer[i] == 0x00)
            {
                fwrite(&count, sizeof(int), 1, output_file);
                fwrite(&buffer[i], sizeof(unsigned char), 1, output_file);
                count = 1;
            }
            else
            {
                fwrite(&buffer[i], sizeof(unsigned char), 1, output_file);
                count++;
            }

            if (count == MAX_SIZE)
            {
                fwrite(&count, sizeof(int), 1, output_file);
                fwrite("\x00", sizeof(unsigned char), 1, output_file);
                count = 1;
            }
        }
    }

    if (count > 1)
    {
        fwrite(&count, sizeof(int), 1, output_file);
        fwrite("\x00", sizeof(unsigned char), 1, output_file); // End of File Marker
    }

    fclose(input_file);
    fclose(output_file);

    printf("File compression successful.\n");

    return 0;
}