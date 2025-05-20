//Gemma-7B DATASET v1.0 Category: Compression algorithms ; Style: imaginative
#include <stdio.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

int main()
{
    char buffer[MAX_BUFFER_SIZE];
    int i, j, k, l, n, original_size, compressed_size;
    char *ptr, *compressed_ptr;

    printf("Enter the original text: ");
    fgets(buffer, MAX_BUFFER_SIZE, stdin);

    original_size = strlen(buffer) + 1;
    compressed_size = 0;

    ptr = buffer;
    compressed_ptr = NULL;

    // Loop over the original text and compress consecutive characters
    for (i = 0; i < original_size - 1; i++)
    {
        int count = 1;
        for (j = i + 1; j < original_size && buffer[i] == buffer[j]; j++)
        {
            count++;
        }

        if (count > 1)
        {
            compressed_ptr = realloc(compressed_ptr, compressed_size + 2);
            compressed_ptr[compressed_size++] = buffer[i];
            compressed_ptr[compressed_size++] = count - 1;
        }
        else
        {
            compressed_ptr = realloc(compressed_ptr, compressed_size + 1);
            compressed_ptr[compressed_size++] = buffer[i];
        }
    }

    // Print the compressed text
    printf("Compressed text: ");
    for (k = 0; k < compressed_size; k++)
    {
        printf("%c", compressed_ptr[k]);
    }

    printf("\n");

    return 0;
}