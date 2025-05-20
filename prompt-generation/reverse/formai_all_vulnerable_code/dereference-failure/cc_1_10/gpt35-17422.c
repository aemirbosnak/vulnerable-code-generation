//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WATERMARK "MyWatermark"
#define WATERMARK_BIT_LENGTH (strlen(WATERMARK) * 8)

unsigned char* read_image_file(const char* filename, size_t* width, size_t* height);
void write_image_file(const char* filename, unsigned char* image_data, size_t width, size_t height);
void embed_watermark(unsigned char* image_data, size_t width, size_t height);

int main(int argc, char** argv)
{
    if(argc < 2)
    {
        printf("Usage: %s <image_filename>\n", argv[0]);
        return 1;
    }

    size_t width, height;
    unsigned char* image_data = read_image_file(argv[1], &width, &height);
    embed_watermark(image_data, width, height);
    write_image_file("watermarked.bmp", image_data, width, height);
    free(image_data);
    return 0;
}

void embed_watermark(unsigned char* image_data, size_t width, size_t height)
{
    // Convert watermark string to binary
    unsigned char watermark_binary[WATERMARK_BIT_LENGTH];
    memset(watermark_binary, 0, sizeof(watermark_binary));
    for(int i = 0; i < WATERMARK_BIT_LENGTH; i++)
    {
        if(WATERMARK[i/8] & (1 << (i % 8)))
        {
            watermark_binary[i] = 1;
        }
    }

    // Embed watermark in image
    int pixel_index = 0;
    for(int i = 0; i < WATERMARK_BIT_LENGTH; i++)
    {
        int bit_to_embed = watermark_binary[i];
        int current_pixel_bit = image_data[pixel_index] & 1;
        if(bit_to_embed != current_pixel_bit)
        {
            if(bit_to_embed == 1)
            {
                image_data[pixel_index] |= 1;
            }
            else
            {
                image_data[pixel_index] &= ~1;
            }
        }
        pixel_index++;
        if(pixel_index >= width * height * 3)
        {
            break;
        }
    }
}

unsigned char* read_image_file(const char* filename, size_t* width, size_t* height)
{
    FILE* file = fopen(filename, "rb");
    if(file == NULL)
    {
        printf("Could not open file %s\n", filename);
        exit(EXIT_FAILURE);
    }

    unsigned char header[54];
    fread(header, sizeof(unsigned char), 54, file);

    *width = *(int*)&header[18];
    *height = *(int*)&header[22];

    int image_size = (*width) * (*height) * 3;
    unsigned char* image_data = (unsigned char*)malloc(image_size);
    fread(image_data, sizeof(unsigned char), image_size, file);

    fclose(file);
    return image_data;
}

void write_image_file(const char* filename, unsigned char* image_data, size_t width, size_t height)
{
    FILE* file = fopen(filename, "wb");
    if(file == NULL)
    {
        printf("Could not create file %s\n", filename);
        exit(EXIT_FAILURE);
    }

    unsigned char header[54] = {
        'B','M', // Magic number
        0,0,0,0, // File size
        0,0,0,0, // Reserved
        54,0,0,0, // Offset to image data
        40,0,0,0, // DIB header size
        0,0,0,0, // Image width
        0,0,0,0, // Image height
        1,0,     // Number of color planes
        24,0,    // Bits per pixel
        0,0,0,0, // Compression method
        0,0,0,0, // Image size
        0,0,0,0, // Horizontal resolution
        0,0,0,0  // Vertical resolution
    };

    *(int*)&header[2] = 54 + width * height * 3;
    *(int*)&header[18] = width;
    *(int*)&header[22] = height;
    fwrite(header, sizeof(unsigned char), 54, file);
    fwrite(image_data, sizeof(unsigned char), width * height * 3, file);
    fclose(file);
}