//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: surrealist
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

// Defining Structure For Digital Watermarking
struct digital_watermark
{
    char data[1000];
    char image[100];
    int key;
};

int main()
{
    // Initializing Data Of The Structure And Accepting User Input
    struct digital_watermark dw;
    printf("Enter The Data For Watermarking: ");
    fgets(dw.data, 1000, stdin);
    printf("Enter The Image File Name(e.g. image.bmp): ");
    fgets(dw.image, 100, stdin);
    printf("Enter The Encryption Key: ");
    scanf("%d", &dw.key);

    // Encoding The Data Using The Encryption Key And Rounding Off To Integer
    int encoded_data = (int)(atof(dw.data) * dw.key + 0.5);

    // Reading The Image File As Binary Data
    FILE *image_file = fopen(dw.image, "rb");
    fseek(image_file, 0, SEEK_END);
    int image_size = ftell(image_file);
    rewind(image_file);
    char *image_buffer = (char*)malloc(sizeof(char) * image_size);
    fread(image_buffer, 1, image_size, image_file);

    // Watermarking The Image By Changing The Least Significant Bit Of Each Byte
    for(int i=0; i<image_size; i++)
    {
        image_buffer[i] = (image_buffer[i] & 254) | (encoded_data & 1);
        encoded_data >>= 1;
    }

    // Writing The Watermarked Image As A New File
    char watermarked_image[100];
    strcpy(watermarked_image, "watermarked_");
    strcat(watermarked_image, dw.image);
    FILE *watermarked_file = fopen(watermarked_image, "wb");
    fwrite(image_buffer, 1, image_size, watermarked_file);
    fclose(watermarked_file);
    printf("Successfully Watermarked The Image!\n");

    return 0;
}