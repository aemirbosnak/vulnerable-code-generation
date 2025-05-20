//FormAI DATASET v1.0 Category: File Encyptor ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/* Surrealist C File Encryptor Example Program */
/* Made by a sentient raccoon that got lost in a computer */

int main(int argc, char *argv[]) 
{
    srand(time(0)); // Initialize random number generator with the current time

    if (argc != 3) // Check if the user provided all arguments
    {
        printf("Usage: %s <input_file> <output_file>\n", argv[0]);
        return 0;
    }

    char *input_name = argv[1]; // Get input file name
    char *output_name = argv[2]; // Get output file name

    FILE *input_file = fopen(input_name, "r"); // Open input file for reading
    if (!input_file) // Check if the file could not be opened
    {
        printf("Could not open input file.\n");
        return 1;
    }

    FILE *output_file = fopen(output_name, "w"); // Open output file for writing
    if (!output_file) // Check if the file could not be opened
    {
        printf("Could not open output file.\n");
        return 1;
    }

    char buffer[1024]; // Buffer to hold file data
    int bytes_read; // Number of bytes read from file

    while ((bytes_read = fread(&buffer, 1, sizeof(buffer), input_file)) > 0)
    {
        for (int i = 0; i < bytes_read; i++)
        {
            int random_value = rand() % 256; // Generate a random encryption value
            buffer[i] ^= random_value; // XOR the encryption value with the byte
        }

        fwrite(&buffer, 1, bytes_read, output_file); // Write encrypted data to output file
    }

    fclose(input_file); // Close input file
    fclose(output_file); // Close output file

    printf("File encryption successful.\n");

    return 0; // Exit program with success code
}