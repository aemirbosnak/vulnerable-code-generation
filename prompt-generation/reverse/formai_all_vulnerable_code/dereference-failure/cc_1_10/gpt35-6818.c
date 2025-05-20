//FormAI DATASET v1.0 Category: Image Steganography ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_SIZE 500000

typedef struct
{
    unsigned int width;
    unsigned int height;
    unsigned char* data;
} Image;

void encode(Image* img, char* message)
{
    int idx = 0;
    int len = strlen(message);

    for (int i = 0; i < img->height; i++)
    {
        for (int j = 0; j < img->width; j++)
        {
            if (idx < len)
            {
                unsigned char* pixel = &img->data[(i * img->width + j) * 3];

                if (pixel[0] % 2 == 0)
                {
                    pixel[0] = (pixel[0] & 0xfe) | (message[idx++] & 0x01);
                }
                else if (pixel[1] % 2 == 0)
                {
                    pixel[1] = (pixel[1] & 0xfe) | (message[idx++] & 0x01);
                }
                else if (pixel[2] % 2 == 0)
                {
                    pixel[2] = (pixel[2] & 0xfe) | (message[idx++] & 0x01);
                }
                else
                {
                    break;
                }
            }
            else
            {
                break;
            }
        }

        if (idx >= len)
        {
            break;
        }
    }
}

char* decode(Image* img)
{
    int idx = 0;
    char* message = (char*)malloc(MAX_FILE_SIZE);

    for (int i = 0; i < img->height; i++)
    {
        for (int j = 0; j < img->width; j++)
        {
            unsigned char* pixel = &img->data[(i * img->width + j) * 3];

            if (pixel[0] % 2 == 1)
            {
                message[idx++] = pixel[0] & 0x01;
            }
            else if (pixel[1] % 2 == 1)
            {
                message[idx++] = pixel[1] & 0x01;
            }
            else if (pixel[2] % 2 == 1)
            {
                message[idx++] = pixel[2] & 0x01;
            }
            else
            {
                break;
            }
        }

        if (idx == 8 && message[idx - 1] == '\0')
        {
            break;
        }
    }

    return message;
}

int main(int argc, char* argv[])
{
    if (argc < 4)
    {
        printf("Usage: %s <input_image> <output_image> <message>", argv[0]);
        return 1;
    }

    char* input_filename = argv[1];
    char* output_filename = argv[2];
    char* message = argv[3];

    FILE* fin = fopen(input_filename, "rb");
    if (fin == NULL)
    {
        printf("Failed to open input file %s", input_filename);
        return 1;
    }

    fseek(fin, 0, SEEK_END);
    int file_size = ftell(fin);
    fseek(fin, 0, SEEK_SET);

    Image img;
    img.width = file_size / 3;
    img.height = 1;
    img.data = (unsigned char*)malloc(file_size * sizeof(unsigned char));
    fread(img.data, sizeof(unsigned char), file_size, fin);

    fclose(fin);

    encode(&img, message);

    FILE* fout = fopen(output_filename, "wb");
    if (fout == NULL)
    {
        printf("Failed to open output file %s", output_filename);
        return 1;
    }

    fwrite(img.data, sizeof(unsigned char), file_size, fout);

    fclose(fout);

    Image img2;
    img2.width = img.width;
    img2.height = img.height;

    memcpy(img2.data, img.data, file_size);

    char* decoded_message = decode(&img2);

    printf("%s\n", decoded_message);

    free(img.data);
    free(decoded_message);

    return 0;
}