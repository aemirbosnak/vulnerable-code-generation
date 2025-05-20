//GPT-4o-mini DATASET v1.0 Category: Image Editor ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <jpeglib.h>
#include <string.h>

typedef struct {
    unsigned char *image_buffer;
    int width;
    int height;
} ImageData;

void *convert_to_grayscale(void *arg) {
    ImageData *img_data = (ImageData *)arg;
    unsigned char *buffer = img_data->image_buffer;
    int width = img_data->width;
    int height = img_data->height;

    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            int idx = (y * width + x) * 3; // RGB
            unsigned char r = buffer[idx];
            unsigned char g = buffer[idx + 1];
            unsigned char b = buffer[idx + 2];
            
            // Convert to grayscale using luminosity method
            unsigned char gray = (unsigned char)(0.21 * r + 0.72 * g + 0.07 * b);
            buffer[idx] = buffer[idx + 1] = buffer[idx + 2] = gray; // Set R, G, B to gray
        }
    }
    return NULL;
}

void load_jpeg(const char *filename, unsigned char **image_buffer, int *width, int *height) {
    FILE *infile = fopen(filename, "rb");
    if (!infile) {
        fprintf(stderr, "Unable to open JPEG file %s\n", filename);
        exit(1);
    }

    struct jpeg_decompress_struct cinfo;
    struct jpeg_error_mgr jerr;
    cinfo.err = jpeg_std_error(&jerr);
    jpeg_create_decompress(&cinfo);
    jpeg_stdio_src(&cinfo, infile);
    jpeg_read_header(&cinfo, TRUE);
    jpeg_start_decompress(&cinfo);

    *width = cinfo.output_width;
    *height = cinfo.output_height;
    int row_stride = cinfo.output_width * cinfo.output_components;
    *image_buffer = (unsigned char *)malloc(row_stride * cinfo.output_height);

    while (cinfo.output_scanline < cinfo.output_height) {
        unsigned char *buffer_array[1];
        buffer_array[0] = *image_buffer + (cinfo.output_scanline) * row_stride;
        jpeg_read_scanlines(&cinfo, buffer_array, 1);
    }

    jpeg_finish_decompress(&cinfo);
    fclose(infile);
}

void save_jpeg(const char *filename, unsigned char *image_buffer, int width, int height) {
    FILE *outfile = fopen(filename, "wb");
    if (!outfile) {
        fprintf(stderr, "Unable to open output JPEG file %s\n", filename);
        exit(1);
    }

    struct jpeg_compress_struct cinfo;
    struct jpeg_error_mgr jerr;
    cinfo.err = jpeg_std_error(&jerr);
    jpeg_create_compress(&cinfo);
    jpeg_stdio_dest(&cinfo, outfile);

    cinfo.image_width = width;
    cinfo.image_height = height;
    cinfo.input_components = 3; // RGB
    cinfo.in_color_space = JCS_RGB;

    jpeg_set_defaults(&cinfo);
    jpeg_start_compress(&cinfo, TRUE);

    int row_stride = width * 3;
    while (cinfo.next_scanline < cinfo.image_height) {
        unsigned char *row_pointer[1];
        row_pointer[0] = image_buffer + cinfo.next_scanline * row_stride;
        jpeg_write_scanlines(&cinfo, row_pointer, 1);
    }

    jpeg_finish_compress(&cinfo);
    fclose(outfile);
}

int main(int argc, char **argv) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <input_jpeg> <output_jpeg>\n", argv[0]);
        return 1;
    }

    unsigned char *image_buffer;
    int width, height;
    
    // Load JPEG image
    load_jpeg(argv[1], &image_buffer, &width, &height);
    ImageData img_data = {image_buffer, width, height};

    pthread_t thread;
    // Create thread to convert image to grayscale
    pthread_create(&thread, NULL, convert_to_grayscale, (void *)&img_data);
    pthread_join(thread, NULL); // Wait for the thread to finish

    // Save the modified image
    save_jpeg(argv[2], image_buffer, width, height);

    // Cleanup
    free(image_buffer);
    return 0;
}