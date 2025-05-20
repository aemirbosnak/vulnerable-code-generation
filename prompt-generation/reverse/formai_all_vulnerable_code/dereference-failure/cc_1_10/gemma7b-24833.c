//Gemma-7B DATASET v1.0 Category: Digital Watermarking ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WATERMARK_SIZE 256

typedef struct Watermark
{
    char* data;
    int size;
    int capacity;
} Watermark;

Watermark* watermark_create(int size)
{
    Watermark* watermark = (Watermark*)malloc(sizeof(Watermark));
    watermark->data = (char*)malloc(size);
    watermark->size = 0;
    watermark->capacity = size;
    return watermark;
}

void watermark_add(Watermark* watermark, char* data, int data_size)
{
    if (watermark->size + data_size > watermark->capacity)
    {
        return;
    }

    memcpy(watermark->data + watermark->size, data, data_size);
    watermark->size += data_size;
}

void watermark_print(Watermark* watermark)
{
    for (int i = 0; i < watermark->size; i++)
    {
        printf("%c ", watermark->data[i]);
    }
    printf("\n");
}

int main()
{
    Watermark* watermark = watermark_create(MAX_WATERMARK_SIZE);

    char* data = "This is a sample message to be watermarked.";
    int data_size = strlen(data) + 1;

    watermark_add(watermark, data, data_size);

     watermark_print(watermark);

    return 0;
}