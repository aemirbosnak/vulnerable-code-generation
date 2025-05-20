//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the size of the input image in pixels
#define WIDTH 512
#define HEIGHT 512

// Define the size of the watermark text
#define TEXT_SIZE 256

// Define the maximum number of bits that can be used for watermarking
#define MAX_BITS ((WIDTH * HEIGHT) / 8)

// Define the file names
#define INPUT_FILE "input_image.raw"
#define OUTPUT_FILE "output_image.raw"
#define TEXT_FILE "watermark_text.txt"

// Function to read in the input image from a file
void read_input_image(unsigned char *input_image)
{
    FILE *fp;

    fp = fopen(INPUT_FILE, "rb");

    fread(input_image, sizeof(unsigned char), WIDTH * HEIGHT, fp);

    fclose(fp);
}

// Function to write the output image to a file
void write_output_image(unsigned char *output_image)
{
    FILE *fp;

    fp = fopen(OUTPUT_FILE, "wb");

    fwrite(output_image, sizeof(unsigned char), WIDTH * HEIGHT, fp);

    fclose(fp);
}

// Function to read in the watermark text from a file
void read_watermark_text(char *watermark_text)
{
    FILE *fp;

    fp = fopen(TEXT_FILE, "r");

    fgets(watermark_text, TEXT_SIZE, fp);

    fclose(fp);
}

// Function to create the digital watermark
void create_watermark(unsigned char *input_image, char *watermark_text, unsigned char *output_image)
{
    int i, j;

    // Copy the input image to the output image
    memcpy(output_image, input_image, WIDTH * HEIGHT);

    // Get the length of the watermark text
    int text_len = strlen(watermark_text);

    // Convert the watermark text to binary
    unsigned char binary_text[MAX_BITS];
    memset(binary_text, 0, MAX_BITS);

    for (i = 0; i < text_len; i++)
    {
        unsigned char c = watermark_text[i];

        for (j = 0; j < 8; j++)
        {
            if (c & (1 << j))
            {
                binary_text[(i * 8) + j] = 1;
            }
        }
    }

    // Create the watermark
    int text_index = 0;
    int bit_count = 0;

    for (i = 0; i < WIDTH; i++)
    {
        for (j = 0; j < HEIGHT; j++)
        {
            unsigned char pixel = input_image[(i * WIDTH) + j];

            // Check if we need to add a bit to the watermark
            if (text_index < MAX_BITS)
            {
                unsigned char bit = binary_text[text_index];

                if (bit)
                {
                    // Set the LSB of the pixel to 1
                    pixel |= 1;
                }
                else
                {
                    // Set the LSB of the pixel to 0
                    pixel &= ~1;
                }

                text_index++;
            }

            output_image[(i * WIDTH) + j] = pixel;
        }
    }
}

// Function to decode the digital watermark from an image
void decode_watermark(unsigned char *input_image, char *watermark_text)
{
    int i, j;

    // Get the length of the watermark text
    int text_len = strlen(watermark_text);

    // Convert the watermark text to binary
    unsigned char binary_text[MAX_BITS];
    memset(binary_text, 0, MAX_BITS);

    for (i = 0; i < text_len; i++)
    {
        unsigned char c = watermark_text[i];

        for (j = 0; j < 8; j++)
        {
            if (c & (1 << j))
            {
                binary_text[(i * 8) + j] = 1;
            }
        }
    }

    // Decode the watermark
    int text_index = 0;
    int bit_count = 0;

    for (i = 0; i < WIDTH; i++)
    {
        for (j = 0; j < HEIGHT; j++)
        {
            unsigned char pixel = input_image[(i * WIDTH) + j];

            // Check if there is a bit in the LSB of the pixel
            if (pixel & 1)
            {
                binary_text[text_index] = 1;
            }
            else
            {
                binary_text[text_index] = 0;
            }

            text_index++;

            // Check if we have decoded the entire watermark
            if (text_index >= MAX_BITS)
            {
                break;
            }
        }

        if (text_index >= MAX_BITS)
        {
            break;
        }
    }

    // Convert the binary watermark back to text
    memset(watermark_text, 0, TEXT_SIZE);

    for (i = 0; i < text_len; i++)
    {
        unsigned char c = 0;

        for (j = 0; j < 8; j++)
        {
            if (binary_text[(i * 8) + j])
            {
                c |= 1 << j;
            }
        }

        watermark_text[i] = c;
    }
}

int main()
{
    unsigned char input_image[WIDTH * HEIGHT];
    unsigned char output_image[WIDTH * HEIGHT];
    char watermark_text[TEXT_SIZE];

    // Read in the input image
    read_input_image(input_image);

    // Read in the watermark text
    read_watermark_text(watermark_text);

    // Create the digital watermark
    create_watermark(input_image, watermark_text, output_image);

    // Write the output image to a file
    write_output_image(output_image);

    // Decode the digital watermark
    decode_watermark(output_image, watermark_text);

    // Print the decoded watermark text
    printf("Decoded watermark: %s\n", watermark_text);

    return 0;
}