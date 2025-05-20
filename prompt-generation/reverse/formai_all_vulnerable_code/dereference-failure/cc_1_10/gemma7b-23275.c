//Gemma-7B DATASET v1.0 Category: Compression algorithms ; Style: immersive
#include <stdio.h>
#include <string.h>

#define MAX 1024

int main()
{
    char str[MAX];
    printf("Enter a string: ");
    fgets(str, MAX, stdin);

    // Convert the string into a binary array
    int len = strlen(str);
    unsigned char arr[len];
    memcpy(arr, str, len);

    // Compress the array
    unsigned char compressed[MAX];
    int compressed_len = compress(arr, len, compressed);

    // Print the compressed string
    printf("Compressed string: ");
    for (int i = 0; i < compressed_len; i++)
    {
        printf("%c ", compressed[i]);
    }

    printf("\n");

    return 0;
}

int compress(unsigned char *arr, int len, unsigned char *compressed)
{
    int i = 0;
    int compressed_len = 0;

    // Count the number of repeated characters
    for (int j = 0; j < len - 1; j++)
    {
        int count = 1;
        for (int k = j + 1; k < len && arr[k] == arr[j]; k++)
        {
            count++;
        }

        // Write the character and its count
        compressed[i++] = arr[j];
        compressed[i++] = count;
        compressed_len++;
    }

    // Write the remaining character
    compressed[i++] = arr[len - 1];
    compressed_len++;

    return compressed_len;
}