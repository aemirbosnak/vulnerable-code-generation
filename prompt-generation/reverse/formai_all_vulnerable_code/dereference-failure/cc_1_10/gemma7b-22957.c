//Gemma-7B DATASET v1.0 Category: Image Steganography ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1024

void encrypt(char **img, int w, int h, char **key)
{
    for (int r = 0; r < h; r++)
    {
        for (int c = 0; c < w; c++)
        {
            int pixel = (*img)[r * w + c];
            int k = (*key)[r * w + c];
            (*img)[r * w + c] = pixel ^ k;
        }
    }
}

int main()
{
    char **img = (char **)malloc(MAX * sizeof(char *));
    for (int i = 0; i < MAX; i++)
    {
        img[i] = (char *)malloc(MAX * sizeof(char));
    }

    char **key = (char **)malloc(MAX * sizeof(char *));
    for (int i = 0; i < MAX; i++)
    {
        key[i] = (char *)malloc(MAX * sizeof(char));
    }

    // Generate random key
    for (int r = 0; r < MAX; r++)
    {
        for (int c = 0; c < MAX; c++)
        {
            key[r][c] = rand() % 256;
        }
    }

    // Encrypt image
    encrypt(img, 256, 256, key);

    // Free memory
    for (int i = 0; i < MAX; i++)
    {
        free(img[i]);
        free(key[i]);
    }

    free(img);
    free(key);

    return 0;
}