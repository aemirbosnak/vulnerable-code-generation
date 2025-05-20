//Gemma-7B DATASET v1.0 Category: Digital Watermarking ; Style: Sherlock Holmes
// The Sign of Four Watermark

#include <stdio.h>
#include <stdlib.h>

#define MAX_WATERMARK_LEN 256

typedef struct Watermark
{
    char *data;
    int length;
} Watermark;

Watermark *createWatermark(int length)
{
    Watermark *wm = malloc(sizeof(Watermark));
    wm->data = malloc(length * sizeof(char));
    wm->length = length;
    return wm;
}

int watermark_add(Watermark *wm, char *data, int data_length)
{
    int i, j;
    for (i = 0; i < data_length && i < wm->length; i++)
    {
        for (j = 0; j < wm->length && j < data_length; j++)
        {
            if (data[j] == wm->data[i])
            {
                wm->data[i] ^= 0x1B;
            }
        }
    }
    return 0;
}

int main()
{
    Watermark *wm = createWatermark(MAX_WATERMARK_LEN);
    wm->data[0] = 'H';
    wm->data[1] = 'o';
    wm->data[2] = 'm';
    wm->data[3] = 'S';

    char message[] = "The Sign of Four";
    watermark_add(wm, message, strlen(message));

    printf("Original message: %s\n", message);
    printf("Watermarked message: %s\n", wm->data);

    return 0;
}