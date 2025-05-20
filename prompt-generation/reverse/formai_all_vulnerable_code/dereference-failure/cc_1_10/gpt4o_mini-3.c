//GPT-4o-mini DATASET v1.0 Category: Image Steganography ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <jpeglib.h>

#define MAX_MESSAGE_SIZE 255

typedef struct {
    uint8_t r, g, b;
} Pixel;

unsigned char* load_image(const char *filename, int *width, int *height);
void save_image(const char *filename, unsigned char *image, int width, int height);
void embed_message(unsigned char *image, const char *message, int width, int height);
char* extract_message(unsigned char *image, int width, int height);
void display_image_stats(int width, int height);

int main(int argc, char *argv[]) {
    if (argc < 4) {
        fprintf(stderr, "Usage: %s <image> <message> <output_image>\n", argv[0]);
        return 1;
    }

    const char *image_filename = argv[1];
    const char *message = argv[2];
    const char *output_filename = argv[3];

    if (strlen(message) > MAX_MESSAGE_SIZE) {
        fprintf(stderr, "Message is too long, max length is %d characters.\n", MAX_MESSAGE_SIZE);
        return 1;
    }

    int width, height;
    unsigned char *image = load_image(image_filename, &width, &height);
    
    if (!image) {
        fprintf(stderr, "Failed to load image!\n");
        return 1;
    }

    display_image_stats(width, height);
    
    embed_message(image, message, width, height);
    save_image(output_filename, image, width, height);

    char *extracted_message = extract_message(image, width, height);
    printf("Extracted Message: %s\n", extracted_message);
    
    free(image);
    free(extracted_message);

    return 0;
}

unsigned char* load_image(const char *filename, int *width, int *height) {
    // Load a JPEG image using libjpeg
    struct jpeg_decompress_struct cinfo;
    struct jpeg_error_mgr jerr;

    FILE *infile = fopen(filename, "rb");
    if (!infile) {
        fprintf(stderr, "Error opening file %s\n", filename);
        return NULL;
    }

    cinfo.err = jpeg_std_error(&jerr);
    jpeg_create_decompress(&cinfo);
    jpeg_stdio_src(&cinfo, infile);
    jpeg_read_header(&cinfo, TRUE);
    jpeg_start_decompress(&cinfo);

    *width = cinfo.output_width;
    *height = cinfo.output_height;
    int channels = cinfo.output_components;
    
    unsigned char *image = malloc(*width * *height * channels);
    unsigned char *row_pointer[1];

    while (cinfo.output_scanline < cinfo.output_height) {
        row_pointer[0] = &image[cinfo.output_scanline * *width * channels];
        jpeg_read_scanlines(&cinfo, row_pointer, 1);
    }

    jpeg_finish_decompress(&cinfo);
    fclose(infile);

    return image;
}

void save_image(const char *filename, unsigned char *image, int width, int height) {
    // Save the modified image back to JPEG format
    struct jpeg_compress_struct cinfo;
    struct jpeg_error_mgr jerr;

    FILE *outfile = fopen(filename, "wb");
    if (!outfile) {
        fprintf(stderr, "Error opening file %s\n", filename);
        return;
    }

    cinfo.err = jpeg_std_error(&jerr);
    jpeg_create_compress(&cinfo);
    jpeg_stdio_dest(&cinfo, outfile);
    
    cinfo.image_width = width;
    cinfo.image_height = height;
    cinfo.input_components = 3;
    cinfo.in_color_space = JCS_RGB;

    jpeg_set_defaults(&cinfo);
    jpeg_start_compress(&cinfo, TRUE);

    unsigned char *row_pointer[1];
    while (cinfo.next_scanline < cinfo.image_height) {
        row_pointer[0] = &image[cinfo.next_scanline * width * 3];
        jpeg_write_scanlines(&cinfo, row_pointer, 1);
    }

    jpeg_finish_compress(&cinfo);
    fclose(outfile);
}

void embed_message(unsigned char *image, const char *message, int width, int height) {
    size_t msg_len = strlen(message);
    // Embed message length first
    image[0] = (uint8_t)msg_len;

    for (size_t i = 0; i < msg_len; i++) {
        image[i + 1] = message[i];
    }
}

char* extract_message(unsigned char *image, int width, int height) {
    size_t msg_len = (size_t)image[0];
    char *message = (char *)malloc(msg_len + 1);
    
    for (size_t i = 0; i < msg_len; i++) {
        message[i] = image[i + 1];
    }
    message[msg_len] = '\0'; // Null-terminate the string

    return message;
}

void display_image_stats(int width, int height) {
    printf("Image dimensions: %dx%d\n", width, height);
}