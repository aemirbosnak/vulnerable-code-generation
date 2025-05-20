//GPT-4o-mini DATASET v1.0 Category: Image to ASCII art converter ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <jpeglib.h>
#include <unistd.h>

#define ASCII_CHARS "@%#*+=-:. " // Characters from dark to light
#define ASCII_CHARS_LENGTH 10
#define IMAGE_WIDTH 80 // Width of ASCII output
#define IMAGE_HEIGHT 40 // Height of ASCII output

typedef struct {
    const char *filename;
    int width;
    int height;
    char **ascii_image;
} ImageData;

void *convert_to_ascii(void *arg) {
    ImageData *data = (ImageData *)arg;

    struct jpeg_decompress_struct cinfo;
    struct jpeg_error_mgr jerr;

    FILE *infile = fopen(data->filename, "rb");
    if (!infile) {
        fprintf(stderr, "Error opening JPEG file: %s\n", data->filename);
        return NULL;
    }

    cinfo.err = jpeg_std_error(&jerr);
    jpeg_create_decompress(&cinfo);
    jpeg_stdio_src(&cinfo, infile);
    jpeg_read_header(&cinfo, TRUE);
    jpeg_start_decompress(&cinfo);

    if (cinfo.output_width < data->width || cinfo.output_height < data->height) {
        fprintf(stderr, "Image is too small for the specified dimensions.\n");
        jpeg_destroy_decompress(&cinfo);
        fclose(infile);
        return NULL;
    }

    unsigned char *buffer = (unsigned char *)malloc(cinfo.output_width * cinfo.output_components);
    int pixel_row = 0;

    while (cinfo.output_scanline < cinfo.output_height) {
        jpeg_read_scanlines(&cinfo, &buffer, 1);
        
        // Resize and convert to ASCII
        if (pixel_row % (cinfo.output_height / data->height) == 0) {
            for (int i = 0; i < data->width; i++) {
                int idx = (pixel_row * cinfo.output_width / data->height) * cinfo.output_components + (i * cinfo.output_width / data->width) * cinfo.output_components;
                int grayscale = (buffer[idx] + buffer[idx + 1] + buffer[idx + 2]) / 3;
                int ascii_index = (int)((float)grayscale / 255 * (ASCII_CHARS_LENGTH - 1));

                data->ascii_image[pixel_row / (cinfo.output_height / data->height)][i] = ASCII_CHARS[ascii_index];
            }
            pixel_row++;
        }
    }

    free(buffer);
    jpeg_finish_decompress(&cinfo);
    jpeg_destroy_decompress(&cinfo);
    fclose(infile);

    return NULL;
}

void display_ascii_image(char **ascii_image, int height, int width) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            putchar(ascii_image[i][j]);
        }
        putchar('\n');
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <image_file.jpg>\n", argv[0]);
        return EXIT_FAILURE;
    }

    pthread_t thread_id;
    ImageData data;
    data.filename = argv[1];
    data.width = IMAGE_WIDTH;
    data.height = IMAGE_HEIGHT;

    // Allocate memory for the ASCII image array
    data.ascii_image = (char **)malloc(data.height * sizeof(char *));
    for (int i = 0; i < data.height; i++) {
        data.ascii_image[i] = (char *)malloc(data.width + 1); // +1 for null terminator
        memset(data.ascii_image[i], ' ', data.width); // Fill with spaces
        data.ascii_image[i][data.width] = '\0'; // Null-terminate the string
    }

    // Create the thread to convert the image to ASCII
    if (pthread_create(&thread_id, NULL, convert_to_ascii, (void *)&data) != 0) {
        fprintf(stderr, "Error creating thread\n");
        return EXIT_FAILURE;
    }

    pthread_join(thread_id, NULL);

    // Display the ASCII art
    display_ascii_image(data.ascii_image, data.height, data.width);

    // Free allocated memory
    for (int i = 0; i < data.height; i++) {
        free(data.ascii_image[i]);
    }
    free(data.ascii_image);

    return EXIT_SUCCESS;
}