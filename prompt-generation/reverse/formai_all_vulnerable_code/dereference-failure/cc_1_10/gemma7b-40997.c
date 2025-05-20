//Gemma-7B DATASET v1.0 Category: Image Steganography ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void hide_msg(char *img_path, char *msg)
{
    FILE *fp = fopen(img_path, "rb");
    if (fp == NULL)
    {
        perror("Error opening image file");
        return;
    }

    unsigned char *img_data = (unsigned char *)malloc(100000);
    if (img_data == NULL)
    {
        perror("Error allocating memory");
        return;
    }

    fread(img_data, 1, 100000, fp);
    fclose(fp);

    int img_size = 100000;
    int msg_len = strlen(msg);

    for (int i = 0; i < msg_len; i++)
    {
        int idx = rand() % img_size;
        img_data[idx] ^= msg[i];
    }

    fp = fopen(img_path, "wb");
    if (fp == NULL)
    {
        perror("Error opening image file");
        return;
    }

    fwrite(img_data, 1, img_size, fp);
    fclose(fp);

    free(img_data);
}

int main()
{
    char *img_path = "image.jpg";
    char *msg = "Secret message";

    hide_msg(img_path, msg);

    printf("Image file modified successfully!\n");

    return 0;
}