//FormAI DATASET v1.0 Category: Compression algorithms ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void compress(char *input_filename, char *output_filename)
{
    // Open input file for reading
    FILE *input_file = fopen(input_filename, "rb");

    // Get the file size
    fseek(input_file, 0L, SEEK_END);
    int size = ftell(input_file);
    fseek(input_file, 0L, SEEK_SET);

    // Allocate memory for input buffer
    char *input_buffer = malloc(size);
    fread(input_buffer, 1, size, input_file);

    // Initialize output buffer
    char *output_buffer = malloc(size);

    // Compression algorithm
    int index = 0;
    int count = 1;
    char current = input_buffer[0];

    for (int i = 1; i < size; i++)
    {
        if (input_buffer[i] == current)
        {
            count++;
        }
        else
        {
            output_buffer[index] = current;
            output_buffer[index+1] = count+'0';
            index += 2;

            current = input_buffer[i];
            count = 1;
        }
    }

    // Add last character and count to output buffer
    output_buffer[index] = current;
    output_buffer[index+1] = count+'0';

    // Write to output file
    FILE *output_file = fopen(output_filename, "wb");
    fwrite(output_buffer, 1, index+2, output_file);

    // Cleanup
    free(input_buffer);
    free(output_buffer);
    fclose(input_file);
    fclose(output_file);
}

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        printf("Usage: compress input_file output_file");
        return 1;
    }

    char *input_filename = argv[1];
    char *output_filename = argv[2];

    compress(input_filename, output_filename);
    printf("Successfully compressed %s to %s", input_filename, output_filename);

    return 0;
}