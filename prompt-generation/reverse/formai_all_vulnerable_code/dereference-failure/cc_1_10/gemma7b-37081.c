//Gemma-7B DATASET v1.0 Category: Digital Watermarking ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WATERMARK_SIZE 256

typedef struct watermark_data {
    char data[MAX_WATERMARK_SIZE];
    int size;
} watermark_data_t;

 watermark_data_t* watermark_data_create(int size)
{
    watermark_data_t* data = (watermark_data_t*)malloc(sizeof(watermark_data_t));
    data->size = size;
    memset(data->data, 0, MAX_WATERMARK_SIZE);
    return data;
}

void watermark_data_add(watermark_data_t* data, char* watermark)
{
    int i = 0;
    for (i = 0; i < data->size && watermark[i] != '\0'; i++)
    {
        data->data[i] = watermark[i];
    }
    data->size = i;
}

int watermark_data_compare(watermark_data_t* data, char* watermark)
{
    int i = 0;
    for (i = 0; i < data->size && watermark[i] != '\0'; i++)
    {
        if (data->data[i] != watermark[i])
        {
            return 0;
        }
    }
    return 1;
}

int main()
{
    char* watermark = "This is a secret watermark";
    watermark_data_t* data = watermark_data_create(strlen(watermark));
    watermark_data_add(data, watermark);

    char* test_watermark = "This is a different watermark";
    if (watermark_data_compare(data, test_watermark))
    {
        printf("The watermark is present.\n");
    }
    else
    {
        printf("The watermark is not present.\n");
    }

    return 0;
}