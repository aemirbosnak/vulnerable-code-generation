//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define BLOCK_SIZE 16
#define WATERMARK "MYWATERMARK"

int main() 
{
    FILE *input_file, *output_file;
    unsigned char input_buffer[BLOCK_SIZE], output_buffer[BLOCK_SIZE];
    long input_filesize, num_blocks, watermark_size = strlen(WATERMARK), input_position = 0, output_position = 0, i;
    int watermark_block_num = (int) ceil(watermark_size / BLOCK_SIZE);

    input_file = fopen("original_image.bmp", "rb");
    output_file = fopen("watermarked_image.bmp", "wb");

    if (!input_file || !output_file) 
    {
        printf("Error opening files\n");
        return 0;
    }

    // Get input file size and number of blocks 
    fseek(input_file, 0, SEEK_END);
    input_filesize = ftell(input_file);
    num_blocks = (long) ceil(input_filesize / BLOCK_SIZE);

    // Write the watermark into the image
    for (i=0, input_position=0; i<watermark_block_num; i++) 
    {
        fread(input_buffer, sizeof(char), BLOCK_SIZE, input_file);
        memcpy(output_buffer, input_buffer, BLOCK_SIZE);

        // Add the watermark to the LSB of the pixel values
        for (int j=0; j<BLOCK_SIZE; j++) 
        {
            if (input_position < watermark_size) 
            {
                // Convert the char to binary and place the bits in the last 8 bits of the color channel
                char character = WATERMARK[input_position];
                for (int k=0; k<8; k++) 
                {
                    output_buffer[j] = (output_buffer[j] & 0xFE) | ((character >> k) & 0x01);
                }
                input_position++;
            }
        }

        fwrite(output_buffer, sizeof(char), BLOCK_SIZE, output_file);
        output_position += BLOCK_SIZE;
    }

    // Copy the rest of the blocks from the original file
    for (i=watermark_block_num, input_position=0; i<num_blocks; i++) 
    {
        fread(input_buffer, sizeof(char), BLOCK_SIZE, input_file);
        fwrite(input_buffer, sizeof(char), BLOCK_SIZE, output_file);
        output_position += BLOCK_SIZE;
    }

    fclose(input_file);
    fclose(output_file);

    return 0;
}