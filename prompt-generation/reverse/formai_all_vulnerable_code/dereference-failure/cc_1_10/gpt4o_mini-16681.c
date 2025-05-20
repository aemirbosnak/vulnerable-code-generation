//GPT-4o-mini DATASET v1.0 Category: Image Steganography ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure to represent the BMP file header
#pragma pack(push, 1)
typedef struct {
    unsigned short type;
    unsigned int size;
    unsigned short reserved1;
    unsigned short reserved2;
    unsigned int offset_data;
} BMPHeader;

typedef struct {
    unsigned int size;
    int width;
    int height;
    unsigned short planes;
    unsigned short bits_per_pixel;
    unsigned int compression;
    unsigned int size_image;
    int x_pixels_per_meter;
    int y_pixels_per_meter;
    unsigned int colors_used;
    unsigned int colors_important;
} BMPInfoHeader;
#pragma pack(pop)

// Function to hide a message in the image
void encode_message(const char *input_image, const char *message, const char *output_image) {
    FILE *fp_in = fopen(input_image, "rb");
    if (!fp_in) {
        perror("Error opening input image");
        exit(EXIT_FAILURE);
    }

    BMPHeader bmp_header;
    BMPInfoHeader bmp_info_header;

    fread(&bmp_header, sizeof(BMPHeader), 1, fp_in);
    fread(&bmp_info_header, sizeof(BMPInfoHeader), 1, fp_in);

    if (bmp_header.type != 0x4D42) { // Check for BMP identifier
        fclose(fp_in);
        fprintf(stderr, "Not a BMP file\n");
        exit(EXIT_FAILURE);
    }

    // Determine message length and prepare the message for encoding
    int msg_length = strlen(message);
    unsigned char *msg_with_end = (unsigned char *)malloc(msg_length + 1);
    strcpy((char *)msg_with_end, message);
    msg_with_end[msg_length] = '\0'; // Null-terminate the message

    // Read the image data
    int padding = (4 - (bmp_info_header.width * 3) % 4) % 4;
    int image_size = bmp_info_header.height * (bmp_info_header.width * 3 + padding);
    unsigned char *image_data = (unsigned char *)malloc(image_size);
    fread(image_data, sizeof(unsigned char), image_size, fp_in);
    fclose(fp_in);

    // Encode the message into the image
    int index;
    for (index = 0; index < msg_length; index++) {
        for (int bit = 0; bit < 8; bit++) {
            int pixel_index = (index * 8 + bit) * 3;
            unsigned char bit_to_encode = (msg_with_end[index] >> (7 - bit)) & 1;
            image_data[pixel_index] = (image_data[pixel_index] & 0xFE) | bit_to_encode; // Modify LSB
        }
    }

    // Save the modified image
    FILE *fp_out = fopen(output_image, "wb");
    if (!fp_out) {
        perror("Error creating output image");
        free(image_data);
        free(msg_with_end);
        exit(EXIT_FAILURE);
    }

    fwrite(&bmp_header, sizeof(BMPHeader), 1, fp_out);
    fwrite(&bmp_info_header, sizeof(BMPInfoHeader), 1, fp_out);
    fwrite(image_data, sizeof(unsigned char), image_size, fp_out);

    // Clean up
    fclose(fp_out);
    free(image_data);
    free(msg_with_end);

    printf("Message encoded successfully in '%s'\n", output_image);
}

// Function to extract a message from the image
void decode_message(const char *input_image) {
    FILE *fp_in = fopen(input_image, "rb");
    if (!fp_in) {
        perror("Error opening input image");
        exit(EXIT_FAILURE);
    }

    BMPHeader bmp_header;
    BMPInfoHeader bmp_info_header;

    fread(&bmp_header, sizeof(BMPHeader), 1, fp_in);
    fread(&bmp_info_header, sizeof(BMPInfoHeader), 1, fp_in);

    if (bmp_header.type != 0x4D42) {
        fclose(fp_in);
        fprintf(stderr, "Not a BMP file\n");
        exit(EXIT_FAILURE);
    }

    int padding = (4 - (bmp_info_header.width * 3) % 4) % 4;
    int image_size = bmp_info_header.height * (bmp_info_header.width * 3 + padding);
    unsigned char *image_data = (unsigned char *)malloc(image_size);
    fread(image_data, sizeof(unsigned char), image_size, fp_in);
    fclose(fp_in);

    // Extract the message from the image
    char extracted_message[256] = {0};
    int index;
    for (index = 0; index < 256; index++) {
        char current_char = 0;
        for (int bit = 0; bit < 8; bit++) {
            int pixel_index = (index * 8 + bit) * 3;
            current_char |= (image_data[pixel_index] & 1) << (7 - bit); // Extract LSB
        }
        if (current_char == '\0') break; // Stop if null character is found
        extracted_message[index] = current_char;
    }

    // Print the extracted message
    printf("Extracted message: \"%s\"\n", extracted_message);
    free(image_data);
}

// Main function to demonstrate the steganography
int main(int argc, char *argv[]) {
    if (argc < 4) {
        fprintf(stderr, "Usage: %s <encode|decode> <input_image> <output_image/message>\n", argv[0]);
        return 1;
    }

    if (strcmp(argv[1], "encode") == 0) {
        encode_message(argv[2], argv[3], "output.bmp");
    } else if (strcmp(argv[1], "decode") == 0) {
        decode_message(argv[2]);
    } else {
        fprintf(stderr, "Invalid action. Use 'encode' or 'decode'.\n");
        return 1;
    }

    return 0;
}