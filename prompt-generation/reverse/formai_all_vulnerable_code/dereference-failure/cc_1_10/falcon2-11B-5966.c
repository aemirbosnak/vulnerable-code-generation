//Falcon2-11B DATASET v1.0 Category: Compression algorithms ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRING_SIZE 1000

int main()
{
    char* string = (char*) malloc(MAX_STRING_SIZE);
    char* compressed_string = (char*) malloc(MAX_STRING_SIZE);
    char* uncompressed_string = (char*) malloc(MAX_STRING_SIZE);

    char* input_string = "Hello, world!";
    char* output_string = "HELLO, WORLD!";

    printf("Input string: %s\n", input_string);
    printf("Output string: %s\n", output_string);

    int string_size = strlen(input_string);
    int compressed_size = 0;
    int uncompressed_size = 0;

    for(int i = 0; i < string_size; i++)
    {
        if(input_string[i]!= output_string[i])
        {
            uncompressed_size++;
        }
        else
        {
            compressed_size++;
        }
    }

    compressed_string[0] = '\0';
    uncompressed_string[0] = '\0';

    for(int i = 0; i < string_size; i++)
    {
        if(input_string[i]!= output_string[i])
        {
            uncompressed_string[uncompressed_size++] = input_string[i];
            compressed_string[compressed_size++] = output_string[i];
        }
    }

    printf("Compressed string: %s\n", compressed_string);
    printf("Uncompressed string: %s\n", uncompressed_string);

    free(string);
    free(compressed_string);
    free(uncompressed_string);

    return 0;
}