//Gemma-7B DATASET v1.0 Category: Image Steganography ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SECRET_LEN 1024

void embed_secret(char *image_path, char *secret)
{
    FILE *fp = fopen(image_path, "rb");
    if (fp == NULL)
    {
        perror("Error opening image file");
        exit(1);
    }

    char buffer[MAX_SECRET_LEN];
    size_t secret_len = strlen(secret);
    size_t image_size = fread(buffer, 1, MAX_SECRET_LEN, fp);

    if (image_size < secret_len)
    {
        fprintf(stderr, "Secret message too long for image");
        exit(1);
    }

    for (size_t i = 0; i < secret_len; i++)
    {
        buffer[image_size - secret_len + i] = (secret[i] & 0x3) | (buffer[image_size - secret_len + i] & 0xFC);
    }

    fclose(fp);

    fp = fopen(image_path, "wb");
    if (fp == NULL)
    {
        perror("Error writing image file");
        exit(1);
    }

    fwrite(buffer, 1, image_size, fp);
    fclose(fp);
}

int main()
{
    char image_path[] = "secret.jpg";
    char secret[] = "This is a secret message";

    embed_secret(image_path, secret);

    return 0;
}