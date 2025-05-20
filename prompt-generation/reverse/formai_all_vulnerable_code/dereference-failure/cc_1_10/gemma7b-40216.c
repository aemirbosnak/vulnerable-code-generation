//Gemma-7B DATASET v1.0 Category: Image Steganography ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1024

int main()
{
    char **arr = (char **)malloc(MAX * sizeof(char *));
    for(int i = 0; i < MAX; i++)
    {
        arr[i] = (char *)malloc(MAX * sizeof(char));
    }

    // Fill the 2D array with random data
    for(int i = 0; i < MAX; i++)
    {
        for(int j = 0; j < MAX; j++)
        {
            arr[i][j] = rand() % 256;
        }
    }

    // Hide the secret message in the LSB of the pixels
    char secret_msg[] = "Hello, world!";
    int msg_len = strlen(secret_msg);
    for(int i = 0; i < msg_len; i++)
    {
        int pixel_offset = secret_msg[i] * 4;
        arr[pixel_offset][pixel_offset] ^= 0x1;
    }

    // Print the 2D array to the console
    for(int i = 0; i < MAX; i++)
    {
        for(int j = 0; j < MAX; j++)
        {
            printf("%x ", arr[i][j]);
        }
        printf("\n");
    }

    // Free the memory
    for(int i = 0; i < MAX; i++)
    {
        for(int j = 0; j < MAX; j++)
        {
            free(arr[i][j]);
        }
        free(arr[i]);
    }
    free(arr);

    return 0;
}