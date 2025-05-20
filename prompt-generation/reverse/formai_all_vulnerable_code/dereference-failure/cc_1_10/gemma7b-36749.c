//Gemma-7B DATASET v1.0 Category: Digital Watermarking ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_SIZE 1024

void embed(int **img, int w, int h, int msg_len, char *msg)
{
    for (int i = 0; i < msg_len; i++)
    {
        for (int r = 0; r < h; r++)
        {
            for (int c = 0; c < w; c++)
            {
                int pixel = img[r][c] & 0xFF;
                pixel += msg[i] * 2;
                img[r][c] = pixel & 0xFF;
            }
        }
    }
}

int main()
{
    int w, h, img_size, msg_len;
    char *msg;
    int **img;

    w = h = 32;
    img_size = w * h;
    msg_len = 10;
    msg = "HELLO WORLD!";

    img = (int **)malloc(sizeof(int *) * h);
    for (int i = 0; i < h; i++)
    {
        img[i] = (int *)malloc(sizeof(int) * w);
    }

    for (int i = 0; i < img_size; i++)
    {
        img[i] = 0;
    }

    embed(img, w, h, msg_len, msg);

    for (int r = 0; r < h; r++)
    {
        for (int c = 0; c < w; c++)
        {
            printf("%d ", img[r][c]);
        }
        printf("\n");
    }

    return 0;
}