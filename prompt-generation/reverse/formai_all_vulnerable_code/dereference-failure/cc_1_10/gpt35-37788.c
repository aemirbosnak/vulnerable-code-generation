//FormAI DATASET v1.0 Category: Compression algorithms ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* This function compresses the input string using a simple RLE algorithm */
unsigned char* rle_compress(const unsigned char *input, int input_length, int *output_length)
{
    unsigned char *output = NULL;
    unsigned char current_char = *input;
    int count = 1;
    int i;

    /* Allocate enough memory for worst-case scenario */
    output = (unsigned char*)malloc(sizeof(unsigned char) * input_length * 2);

    if (output == NULL)
    {
        printf("Failed to allocate memory for the output buffer.\n");
        *output_length = 0;
        return NULL;
    }

    /* Start by writing the first character to the output buffer */
    *output = current_char;
    output++;
    for (i = 1; i < input_length; i++)
    {
        if (input[i] == current_char)
        {
            /* Increment the count if the current character matches the previous one */
            count++;
        }
        else
        {
            /* Write the count to the output buffer and reset the count */
            *output = count;
            output++;
            /* Write the new character to the output buffer */
            *output = input[i];
            output++;
            /* Set the new current character and reset the count */
            current_char = input[i];
            count = 1;
        }
    }

    /* Write the final count to the output buffer */
    *output = count;
    output++;
    *output_length = output - (unsigned char*)output;

    return (unsigned char*)realloc(output, *output_length);
}

int main()
{
    const char *input = "aabbbbcccc";
    unsigned char *output = NULL;
    int length = strlen(input);
    int new_length;
    int i;

    printf("Input: %s\n", input);

    /* Compress the input string using the RLE algorithm */
    output = rle_compress((unsigned char*)input, length, &new_length);

    /* Print out the compressed string */
    printf("Compressed: ");
    for (i = 0; i < new_length; i++)
    {
        printf("%d%c", output[i], (i == new_length - 1) ? '\n' : ',');
    }

    return 0;
}