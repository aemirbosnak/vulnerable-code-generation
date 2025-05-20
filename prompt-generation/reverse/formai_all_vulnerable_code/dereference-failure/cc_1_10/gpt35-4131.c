//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    FILE *fptr_src, *fptr_wm, *fptr_out;
    unsigned char src_pixel, watermark_pixel, out_pixel;
    unsigned char src_bit, wm_bit, out_bit;
    int i, j;
    long int src_size, wm_size;

    // Open source image file
    fptr_src = fopen("source_image.bmp", "rb");
    if (fptr_src == NULL)
    {
        printf("Error opening source image file.");
        exit(0);
    }
    // Open watermark image file
    fptr_wm = fopen("watermark_image.bmp", "rb");
    if (fptr_src == NULL)
    {
        printf("Error opening watermark image file.");
        exit(0);
    }
    // Open output image file
    fptr_out = fopen("output_image.bmp", "wb");
    if (fptr_out == NULL)
    {
        printf("Error creating output image file.");
        exit(0);
    }

    // Get size of source image file
    fseek(fptr_src, 0L, SEEK_END);
    src_size = ftell(fptr_src);
    rewind(fptr_src);

    // Get size of watermark image file
    fseek(fptr_wm, 0L, SEEK_END);
    wm_size = ftell(fptr_wm);
    rewind(fptr_wm);

    // Check if the watermark image size is less than or equal to the source image size
    if (wm_size > src_size)
    {
        printf("Watermark image is too large for the source image.");
        exit(0);
    }

    // Read and write image headers
    unsigned char header[54];
    fread(header, sizeof(unsigned char), 54, fptr_src);
    fwrite(header, sizeof(unsigned char), 54, fptr_out);

    // Retrieve and embed each bit of the watermark into the least significant bit of the source pixel
    for (i = 0; i < src_size - 54; i++)
    {
        fread(&src_pixel, sizeof(unsigned char), 1, fptr_src);
        fread(&watermark_pixel, sizeof(unsigned char), 1, fptr_wm);
        out_pixel = src_pixel;

        for (j = 0; j < 8; j++)
        {
            src_bit = (src_pixel >> (7 - j)) & 0x01;
            wm_bit = (watermark_pixel >> (7 - j)) & 0x01;
            out_bit = src_bit;

            if (i * 8 + j < wm_size * 8)
            {
                out_bit = ((src_bit & 0xFE) | wm_bit);
            }
            out_pixel = (out_pixel & ~(0x01 << (7 - j))) | (out_bit << (7 - j));
        }
        fwrite(&out_pixel, sizeof(unsigned char), 1, fptr_out);
    }

    // Write out remaining source image data
    unsigned char out_byte;
    while (!feof(fptr_src))
    {
        fread(&out_byte, sizeof(unsigned char), 1, fptr_src);
        fwrite(&out_byte, sizeof(unsigned char), 1, fptr_out);
    }

    fclose(fptr_src);
    fclose(fptr_wm);
    fclose(fptr_out);

    printf("Watermarking complete.");
    return 0;
}