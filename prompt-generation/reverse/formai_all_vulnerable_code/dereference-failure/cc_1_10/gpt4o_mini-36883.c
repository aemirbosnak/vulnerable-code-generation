//GPT-4o-mini DATASET v1.0 Category: Image Steganography ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <jpeglib.h>

#define MAX_MESSAGE_SIZE 1024

void embed_message(const char *image_path, const char *message, const char *output_path) {
    struct jpeg_decompress_struct cinfo;
    struct jpeg_error_mgr jerr;
    FILE *input_file = fopen(image_path, "rb");
    if (!input_file) {
        fprintf(stderr, "Error opening JPEG file\n");
        exit(1);
    }

    cinfo.err = jpeg_std_error(&jerr);
    jpeg_create_decompress(&cinfo);
    jpeg_stdio_src(&cinfo, input_file);
    jpeg_read_header(&cinfo, TRUE);
    jpeg_start_decompress(&cinfo);

    int width = cinfo.output_width;
    int height = cinfo.output_height;
    int pixel_size = cinfo.output_components;
    
    unsigned char *image_buffer = malloc(width * height * pixel_size);
    unsigned char *p = image_buffer;
    while (cinfo.output_scanline < height) {
        p += jpeg_read_scanlines(&cinfo, &p, 1);
    }
    
    // Embed message into the least significant bit of the pixel values
    size_t message_length = strlen(message);
    if (message_length > MAX_MESSAGE_SIZE) {
        fprintf(stderr, "Message too long to embed\n");
        free(image_buffer);
        jpeg_destroy_decompress(&cinfo);
        fclose(input_file);
        exit(1);
    }

    for (size_t i = 0; i < message_length; i++) {
        for (int j = 0; j < 8; j++) {
            int bit = (message[i] >> (7 - j)) & 1;
            image_buffer[(i * 8 + j) * pixel_size] &= 0xFE; // Clear LSB
            image_buffer[(i * 8 + j) * pixel_size] |= bit;  // Set LSB
        }
    }

    // Write new JPEG file
    FILE *output_file = fopen(output_path, "wb");
    if (!output_file) {
        fprintf(stderr, "Error opening output JPEG file\n");
        free(image_buffer);
        jpeg_destroy_decompress(&cinfo);
        fclose(input_file);
        exit(1);
    }

    struct jpeg_compress_struct ccomp;
    struct jpeg_error_mgr jerr_comp;
    ccomp.err = jpeg_std_error(&jerr_comp);
    jpeg_create_compress(&ccomp);
    jpeg_stdio_dest(&ccomp, output_file);
    
    ccomp.image_width = width;
    ccomp.image_height = height;
    ccomp.input_components = pixel_size;
    ccomp.in_color_space = cinfo.jpeg_color_space;
    
    jpeg_set_defaults(&ccomp);
    jpeg_start_compress(&ccomp, TRUE);

    unsigned char *row_pointer[1];
    while (ccomp.next_scanline < ccomp.image_height) {
        row_pointer[0] = &image_buffer[ccomp.next_scanline * width * pixel_size];
        jpeg_write_scanlines(&ccomp, row_pointer, 1);
    }

    // Cleanup
    jpeg_finish_compress(&ccomp);
    jpeg_destroy_compress(&ccomp);
    free(image_buffer);
    fclose(output_file);
    jpeg_finish_decompress(&cinfo);
    jpeg_destroy_decompress(&cinfo);
    fclose(input_file);
    
    printf("Message embedded successfully into %s\n", output_path);
}

void extract_message(const char *image_path) {
    struct jpeg_decompress_struct cinfo;
    struct jpeg_error_mgr jerr;
    FILE *input_file = fopen(image_path, "rb");
    
    if (!input_file) {
        fprintf(stderr, "Error opening JPEG file\n");
        exit(1);
    }

    cinfo.err = jpeg_std_error(&jerr);
    jpeg_create_decompress(&cinfo);
    jpeg_stdio_src(&cinfo, input_file);
    jpeg_read_header(&cinfo, TRUE);
    jpeg_start_decompress(&cinfo);

    int width = cinfo.output_width;
    int height = cinfo.output_height;
    int pixel_size = cinfo.output_components;

    unsigned char *image_buffer = malloc(width * height * pixel_size);
    unsigned char *p = image_buffer;
    while (cinfo.output_scanline < height) {
        p += jpeg_read_scanlines(&cinfo, &p, 1);
    }

    char message[MAX_MESSAGE_SIZE + 1];
    size_t message_length = 0;

    // Extract the message from the least significant bit of the pixel values
    for (size_t i = 0; message_length < MAX_MESSAGE_SIZE; i++) {
        char character = 0;
        for (int j = 0; j < 8; j++) {
            if (i * 8 + j < width * height) {
                character |= (image_buffer[(i * 8 + j) * pixel_size] & 1) << (7 - j);
            }
        }
        if (character == '\0') break;  // End of message
        message[message_length++] = character;
    }
    message[message_length] = '\0';

    // Cleanup
    free(image_buffer);
    jpeg_finish_decompress(&cinfo);
    jpeg_destroy_decompress(&cinfo);
    fclose(input_file);
    
    printf("Extracted message: %s\n", message);
}

int main(int argc, char *argv[]) {
    if (argc < 5) {
        fprintf(stderr, "Usage: %s <embed/extract> <image_path> <message/output_path>\n", argv[0]);
        return 1;
    }

    if (strcmp(argv[1], "embed") == 0) {
        embed_message(argv[2], argv[3], argv[4]);
    } else if (strcmp(argv[1], "extract") == 0) {
        extract_message(argv[2]);
    } else {
        fprintf(stderr, "Invalid operation. Use 'embed' or 'extract'\n");
        return 1;
    }

    return 0;
}