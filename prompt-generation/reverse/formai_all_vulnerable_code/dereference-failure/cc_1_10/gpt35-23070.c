//FormAI DATASET v1.0 Category: Compression algorithms ; Style: calm
/* 
 * This is a unique C Compression Algorithm that uses run-length encoding to compress the given input data.
 * The algorithm works by grouping identical consecutive characters together, and storing their count.
 * The idea is that repeated characters will occur more frequently than non-repeated characters, and therefore, compressing
 * these runs of characters will result in a smaller output data size.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to compress the input data using Run-Length Encoding
char* compress(char* uncompressed_data)
{
    // Initialize variables
    int uncompressed_data_len = strlen(uncompressed_data);
    char* compressed_data = (char*)malloc(uncompressed_data_len * 2 * sizeof(char));
    int count = 1;
    int j = 0;

    // Iterate over the uncompressed data, and compress the runs of consecutive characters
    for (int i = 0; i < uncompressed_data_len; i++)
    {
        // If the current character is the same as the next one, increase the count
        if (uncompressed_data[i] == uncompressed_data[i + 1])
        {
            count++;
        }
        // Otherwise, write the character and its count to the compressed data
        else
        {
            compressed_data[j++] = uncompressed_data[i];
            snprintf(&compressed_data[j], 2, "%d", count);
            j += strlen(&compressed_data[j]);
            count = 1;
        }
    }

    // Add a null character at the end of the compressed data, and return it
    compressed_data[j] = '\0';
    return compressed_data;
}

int main()
{
    // Example usage
    char input_data[] = "aaabbcccddddeeeefff";
    char* compressed_data = compress(input_data);

    printf("Original data: %s, compressed data: %s\n", input_data, compressed_data);

    free(compressed_data);

    return 0;
}