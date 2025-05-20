//Falcon-180B DATASET v1.0 Category: Digital Watermarking ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define WATERMARK_SIZE 64
#define IMAGE_SIZE 512

unsigned char watermark[WATERMARK_SIZE];
unsigned char image[IMAGE_SIZE];

void generate_watermark(void)
{
    int i;
    for(i=0;i<WATERMARK_SIZE;i++)
    {
        watermark[i] = rand()%256;
    }
}

void embed_watermark(unsigned char *image, unsigned char *watermark)
{
    int i,j,k;
    for(i=0;i<IMAGE_SIZE;i++)
    {
        if(i%WATERMARK_SIZE==0)
        {
            j = rand()%(IMAGE_SIZE-WATERMARK_SIZE);
            k = 0;
            while(k<WATERMARK_SIZE && j+k<IMAGE_SIZE)
            {
                image[j+k] = image[j+k] ^ watermark[k];
                k++;
            }
        }
    }
}

void extract_watermark(unsigned char *image, unsigned char *watermark)
{
    int i,j,k;
    for(i=0;i<IMAGE_SIZE;i++)
    {
        if(i%WATERMARK_SIZE==0)
        {
            j = rand()%(IMAGE_SIZE-WATERMARK_SIZE);
            k = 0;
            while(k<WATERMARK_SIZE && j+k<IMAGE_SIZE)
            {
                watermark[k] = watermark[k] ^ image[j+k];
                k++;
            }
        }
    }
}

int main(int argc, char **argv)
{
    srand(time(0));
    generate_watermark();
    printf("Watermark: ");
    for(int i=0;i<WATERMARK_SIZE;i++)
    {
        printf("%02X ",watermark[i]);
    }
    printf("\n");

    unsigned char *image_data = (unsigned char*)malloc(IMAGE_SIZE);
    memset(image_data,0,IMAGE_SIZE);

    embed_watermark(image_data,watermark);

    printf("Embedded Image: ");
    for(int i=0;i<IMAGE_SIZE;i++)
    {
        printf("%02X ",image_data[i]);
    }
    printf("\n");

    unsigned char extracted_watermark[WATERMARK_SIZE];
    extract_watermark(image_data,extracted_watermark);

    printf("Extracted Watermark: ");
    for(int i=0;i<WATERMARK_SIZE;i++)
    {
        printf("%02X ",extracted_watermark[i]);
    }
    printf("\n");

    free(image_data);
    return 0;
}