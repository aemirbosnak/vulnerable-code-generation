//Gemma-7B DATASET v1.0 Category: Digital Watermarking ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1024

void watermark(char *image, char *waterMark)
{
    int i, j, k, l, w, h;
    FILE *fp;
    unsigned char *imgBuf, *wmBuf;

    fp = fopen(image, "rb");
    if (fp == NULL)
    {
        return;
    }

    imgBuf = (unsigned char *)malloc(MAX);
    wmBuf = (unsigned char *)malloc(MAX);

    w = fread(imgBuf, 1, MAX, fp);
    fclose(fp);

    l = strlen(waterMark);
    for (k = 0; k < l; k++)
    {
        wmBuf[k] = waterMark[k];
    }

    h = w / 8;
    for (i = 0; i < h; i++)
    {
        for (j = 0; j < w; j++)
        {
            if (imgBuf[i * w + j] == 0)
            {
                imgBuf[i * w + j] = wmBuf[k];
                k++;
            }
        }
    }

    fp = fopen(image, "wb");
    fwrite(imgBuf, 1, w, fp);
    fclose(fp);

    free(imgBuf);
    free(wmBuf);
}

int main()
{
    char *image = "image.jpg";
    char *waterMark = "This is a watermark";

    watermark(image, waterMark);

    return 0;
}