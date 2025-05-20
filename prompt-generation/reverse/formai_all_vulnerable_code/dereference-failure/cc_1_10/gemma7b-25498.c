//Gemma-7B DATASET v1.0 Category: Image Steganography ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DATA_SIZE 1024

void encrypt_data(char *data, int data_size)
{
    int i;
    for (i = 0; i < data_size; i++)
    {
        data[i] ^= 0x1B;
    }
}

void hide_data(char *cover_image, char *secret_data, int data_size)
{
    int i, j;
    int cover_size = strlen(cover_image);
    int secret_size = data_size;

    if (cover_size < secret_size)
    {
        printf("Error: Cover image is too small for secret data.\n");
        return;
    }

    for (i = 0; i < secret_size; i++)
    {
        for (j = 0; j < cover_size; j++)
        {
            if ((cover_image[j] & 0x80) == 0)
            {
                cover_image[j] ^= secret_data[i] & 0x1F;
            }
        }
    }
}

int main()
{
    char *cover_image = "image.jpg";
    char *secret_data = "This is my secret message.";
    int data_size = strlen(secret_data);

    encrypt_data(secret_data, data_size);
    hide_data(cover_image, secret_data, data_size);

    printf("Secret data hidden successfully.\n");

    return 0;
}