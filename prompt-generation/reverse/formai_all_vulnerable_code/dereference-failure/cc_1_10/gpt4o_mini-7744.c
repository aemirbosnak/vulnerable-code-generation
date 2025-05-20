//GPT-4o-mini DATASET v1.0 Category: Image Steganography ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <jpeglib.h>

#define MAX_MESSAGE_LENGTH 1024

// Function to encode a message into an image
void encode(const char *image_path, const char *output_path, const char *message) {
    struct jpeg_decompress_struct cinfo;
    struct jpeg_error_mgr jerr;

    FILE *infile = fopen(image_path, "rb");
    if (!infile) {
        fprintf(stderr, "Error: Cannot open %s\n", image_path);
        return;
    }

    cinfo.err = jpeg_std_error(&jerr);
    jpeg_create_decompress(&cinfo);
    jpeg_stdio_src(&cinfo, infile);
    jpeg_read_header(&cinfo, TRUE);
    jpeg_start_decompress(&cinfo);
    
    int width = cinfo.output_width;
    int height = cinfo.output_height;
    int channels = cinfo.output_components;

    unsigned char *image_buffer = (unsigned char *)malloc(width * height * channels);
    unsigned char *messageBuffer = (unsigned char *)malloc(MAX_MESSAGE_LENGTH);
    strcpy(messageBuffer, message);

    // Store message length in the first byte of the image
    int message_length = strlen(messageBuffer);
    if (message_length > MAX_MESSAGE_LENGTH) {
        fprintf(stderr, "Error: Message is too long for steganography.\n");
        free(image_buffer);
        free(messageBuffer);
        jpeg_destroy_decompress(&cinfo);
        fclose(infile);
        return;
    }

    // Read pixel data
    for (int row = 0; row < height; row++) {
        unsigned char *ptr = image_buffer + row * width * channels;
        jpeg_read_scanlines(&cinfo, &ptr, 1);
    }

    // Encode the message into the image
    for (int i = 0; i < message_length; i++) {
        image_buffer[i * channels] = (image_buffer[i * channels] & 0xFE) | ((messageBuffer[i] >> 7) & 0x01); // Embed MSB
        image_buffer[i * channels + 1] = (image_buffer[i * channels + 1] & 0xFE) | ((messageBuffer[i] >> 6) & 0x01);
        image_buffer[i * channels + 2] = (image_buffer[i * channels + 2] & 0xFE) | ((messageBuffer[i] >> 5) & 0x01);
    }
    
    // Finish reading the JPEG
    jpeg_finish_decompress(&cinfo);
    fclose(infile);

    // Write the output JPEG
    struct jpeg_compress_struct ccompress;
    struct jpeg_error_mgr jcompress_err;

    FILE *outfile = fopen(output_path, "wb");
    if (!outfile) {
        fprintf(stderr, "Error: Cannot open %s for output\n", output_path);
        free(image_buffer);
        free(messageBuffer);
        return;
    }

    ccompress.err = jpeg_std_error(&jcompress_err);
    jpeg_create_compress(&ccompress);
    jpeg_stdio_dest(&ccompress, outfile);

    ccompress.image_width = width;
    ccompress.image_height = height;
    ccompress.input_components = channels;
    ccompress.in_color_space = JCS_RGB;
    jpeg_set_defaults(&ccompress);
    jpeg_start_compress(&ccompress, TRUE);

    // Write pixel data
    for (int row = 0; row < height; row++) {
        unsigned char *ptr = image_buffer + row * width * channels;
        jpeg_write_scanlines(&ccompress, &ptr, 1);
    }

    jpeg_finish_compress(&ccompress);
    fclose(outfile);
    free(image_buffer);
    free(messageBuffer);
    jpeg_destroy_decompress(&cinfo);
    jpeg_destroy_compress(&ccompress);
}

// Function to decode a message from an image
void decode(const char *image_path) {
    struct jpeg_decompress_struct cinfo;
    struct jpeg_error_mgr jerr;

    FILE *infile = fopen(image_path, "rb");
    if (!infile) {
        fprintf(stderr, "Error: Cannot open %s\n", image_path);
        return;
    }

    cinfo.err = jpeg_std_error(&jerr);
    jpeg_create_decompress(&cinfo);
    jpeg_stdio_src(&cinfo, infile);
    jpeg_read_header(&cinfo, TRUE);
    jpeg_start_decompress(&cinfo);

    int width = cinfo.output_width;
    int height = cinfo.output_height;
    int channels = cinfo.output_components;
    
    unsigned char *image_buffer = (unsigned char *)malloc(width * height * channels);
    
    // Read pixel data
    for (int row = 0; row < height; row++) {
        unsigned char *ptr = image_buffer + row * width * channels;
        jpeg_read_scanlines(&cinfo, &ptr, 1);
    }

    // Decode the message
    char message[MAX_MESSAGE_LENGTH];
    for (int i = 0; i < MAX_MESSAGE_LENGTH; i++) {
        message[i] = 0;
        if (image_buffer[i * channels] & 0x01) message[i] |= (1 << 7);
        if (image_buffer[i * channels + 1] & 0x01) message[i] |= (1 << 6);
        if (image_buffer[i * channels + 2] & 0x01) message[i] |= (1 << 5);
    }

    message[MAX_MESSAGE_LENGTH - 1] = '\0'; // Ensure null termination
    printf("Decoded message: %s\n", message);

    jpeg_finish_decompress(&cinfo);
    fclose(infile);
    free(image_buffer);
    jpeg_destroy_decompress(&cinfo);
}

// Main function for the futuristic steganography program
int main(int argc, char **argv) {
    if (argc < 4) {
        fprintf(stderr, "Usage: %s <encode/decode> <image_path> <output_path/message>\n", argv[0]);
        return EXIT_FAILURE;
    }

    if (strcmp(argv[1], "encode") == 0) {
        encode(argv[2], argv[3], argv[4]);
    } else if (strcmp(argv[1], "decode") == 0) {
        decode(argv[2]);
    } else {
        fprintf(stderr, "Invalid option. Use 'encode' or 'decode'.\n");
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}