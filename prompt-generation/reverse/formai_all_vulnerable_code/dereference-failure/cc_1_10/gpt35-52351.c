//FormAI DATASET v1.0 Category: Image Steganography ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BYTES_PER_PIXEL 3 // assuming input image is in RGB format
#define BITS_PER_BYTE 8
#define MAX_FILENAME_LENGTH 200

// retrieves the number of bytes in the input image
long get_file_size(FILE *input_image)
{
    fseek(input_image, 0L, SEEK_END);
    long file_size = ftell(input_image);
    fseek(input_image, 0L, SEEK_SET);
    return file_size;
}

// encodes the hidden data into the Least Significant Bits (LSBs) of the image
void encode_data_into_image(unsigned char *image_data, long image_size, char *hidden_data)
{
    int hidden_data_length = strlen(hidden_data);
    int bit_index = 0;
    int byte_index = 0;

    for (int i = 0; i < hidden_data_length; i++)
    {
        char current_char = hidden_data[i];

        for (int j = 0; j < BITS_PER_BYTE; j++)
        {
            int bit = (current_char >> (7 - j)) & 1; // get the jth bit from the current char
            int pixel_byte_value = image_data[byte_index];

            if (bit == 1)
            {
                // set LSB to 1
                image_data[byte_index] = (pixel_byte_value | 1);
            }
            else
            {
                // set LSB to 0
                image_data[byte_index] = (pixel_byte_value & ~1);
            }

            byte_index++;

            if (byte_index >= image_size)
            {
                return; // finished encoding
            }
        }
    }
}

// decodes the hidden data from the Least Significant Bits (LSBs) of the image
void decode_data_from_image(unsigned char *image_data, long image_size)
{
    char hidden_data[MAX_FILENAME_LENGTH] = {0};
    int bit_index = 0;
    int byte_index = 0;
    int hidden_data_index = 0;

    while (1)
    {
        int pixel_byte_value = image_data[byte_index];
        int bit = (pixel_byte_value >> bit_index) & 1; // get the LSB

        hidden_data[hidden_data_index] |= (bit << (7 - bit_index)); // set the corresponding bit in the hidden data

        bit_index++;

        if (bit_index == BITS_PER_BYTE)
        {
            bit_index = 0;
            hidden_data_index++;

            if (hidden_data_index >= MAX_FILENAME_LENGTH)
            {
                printf("Error: Maximum filename length exceeded.");
                return;
            }
        }

        byte_index++;

        if (byte_index >= image_size)
        {
            printf("Hidden data: %s\n", hidden_data);
            return; // finished decoding
        }
    }
}

int main(int argc, char *argv[])
{
    if (argc < 3)
    {
        printf("Insufficient arguments.\nUsage: %s [input_image] [output_image] [hidden_data]\n", argv[0]);
        return 1;
    }

    char *input_filename = argv[1];
    char *output_filename = argv[2];
    char *hidden_data = argv[3];

    FILE *input_image = fopen(input_filename, "rb");

    if (input_image == NULL)
    {
        printf("Error: Could not open input image %s\n", input_filename);
        return 1;
    }

    FILE *output_image = fopen(output_filename, "wb");

    if (output_image == NULL)
    {
        printf("Error: Could not create output image %s\n", output_filename);
        return 1;
    }

    long image_size = get_file_size(input_image);
    unsigned char *image_data = malloc(image_size * sizeof(unsigned char));

    if (fread(image_data, sizeof(unsigned char), image_size, input_image) != image_size)
    {
        printf("Error: Failed to read input image %s\n", input_filename);
        return 1;
    }

    encode_data_into_image(image_data, image_size, hidden_data);
    fwrite(image_data, sizeof(unsigned char), image_size, output_image);

    fclose(input_image);
    fclose(output_image);
    free(image_data);

    FILE *encoded_image = fopen(output_filename, "rb");

    if (encoded_image == NULL)
    {
        printf("Error: Could not open encoded image %s\n", output_filename);
        return 1;
    }

    image_size = get_file_size(encoded_image);
    image_data = malloc(image_size * sizeof(unsigned char));

    if (fread(image_data, sizeof(unsigned char), image_size, encoded_image) != image_size)
    {
        printf("Error: Failed to read encoded image %s\n", output_filename);
        return 1;
    }

    decode_data_from_image(image_data, image_size);

    fclose(encoded_image);
    free(image_data);

    return 0;
}