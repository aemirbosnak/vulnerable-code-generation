//GEMINI-pro DATASET v1.0 Category: Compression algorithms ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT_SIZE 1024
#define MAX_OUTPUT_SIZE 1024

unsigned char *input_buffer;
unsigned char *output_buffer;

int main(int argc, char **argv)
{
    int input_size;
    int output_size;

    if (argc != 2)
    {
        printf("Usage: %s input_file\n", argv[0]);
        return 1;
    }

    // Read the input file
    FILE *input_file = fopen(argv[1], "rb");
    if (input_file == NULL)
    {
        printf("Error: could not open input file %s\n", argv[1]);
        return 1;
    }

    input_size = fread(input_buffer, 1, MAX_INPUT_SIZE, input_file);
    fclose(input_file);

    // Compress the data
    output_size = compress(input_buffer, input_size, output_buffer);

    // Write the compressed data to a file
    FILE *output_file = fopen("output.bin", "wb");
    if (output_file == NULL)
    {
        printf("Error: could not open output file output.bin\n");
        return 1;
    }

    fwrite(output_buffer, 1, output_size, output_file);
    fclose(output_file);

    printf("Compressed %d bytes to %d bytes\n", input_size, output_size);

    return 0;
}

int compress(unsigned char *input_buffer, int input_size, unsigned char *output_buffer)
{
    int output_size = 0;
    int input_index = 0;
    int output_index = 0;

    // Iterate over the input buffer
    while (input_index < input_size)
    {
        // Get the current character
        unsigned char current_char = input_buffer[input_index];

        // Count the number of consecutive occurrences of the current character
        int count = 1;
        while (input_index + count < input_size && input_buffer[input_index + count] == current_char)
        {
            count++;
        }

        // If the count is greater than 1, write the count and the character to the output buffer
        if (count > 1)
        {
            output_buffer[output_index++] = count;
            output_buffer[output_index++] = current_char;
        }
        // Otherwise, just write the character to the output buffer
        else
        {
            output_buffer[output_index++] = current_char;
        }

        // Increment the input index by the count
        input_index += count;
    }

    return output_size;
}