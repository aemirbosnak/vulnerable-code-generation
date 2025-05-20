//GPT-4o-mini DATASET v1.0 Category: Image Editor ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <jpeglib.h>

void error_exit(const char *msg) {
    fprintf(stderr, "Error: %s\n", msg);
    exit(EXIT_FAILURE);
}

void read_jpeg(const char *filename, unsigned char **image_data, int *width, int *height) {
    FILE *file = fopen(filename, "rb");
    if (!file) error_exit("Could not open JPEG file");

    struct jpeg_decompress_struct cinfo;
    struct jpeg_error_mgr jerr;
    cinfo.err = jpeg_std_error(&jerr);
    jpeg_create_decompress(&cinfo);
    jpeg_stdio_src(&cinfo, file);
    jpeg_read_header(&cinfo, TRUE);
    jpeg_start_decompress(&cinfo);

    *width = cinfo.output_width;
    *height = cinfo.output_height;
    int pixel_size = cinfo.output_components;

    *image_data = (unsigned char *)malloc((*width) * (*height) * pixel_size);
    if (!(*image_data)) error_exit("Could not allocate memory for image data");

    unsigned char *rowptr[1];
    while (cinfo.output_scanline < cinfo.output_height) {
        rowptr[0] = *image_data + cinfo.output_scanline * (*width) * pixel_size;
        jpeg_read_scanlines(&cinfo, rowptr, 1);
    }

    jpeg_finish_decompress(&cinfo);
    fclose(file);
}

void write_jpeg(const char *filename, unsigned char *image_data, int width, int height) {
    FILE *file = fopen(filename, "wb");
    if (!file) error_exit("Could not open JPEG file for writing");

    struct jpeg_compress_struct cinfo;
    struct jpeg_error_mgr jerr;
    cinfo.err = jpeg_std_error(&jerr);
    jpeg_create_compress(&cinfo);
    jpeg_stdio_dest(&cinfo, file);

    cinfo.image_width = width;
    cinfo.image_height = height;
    cinfo.input_components = 3; // assume RGB
    cinfo.in_color_space = JCS_RGB;

    jpeg_set_defaults(&cinfo);
    jpeg_start_compress(&cinfo, TRUE);

    unsigned char *rowptr[1];
    while (cinfo.next_scanline < cinfo.image_height) {
        rowptr[0] = image_data + cinfo.next_scanline * width * 3; // Assuming 3 components for RGB
        jpeg_write_scanlines(&cinfo, rowptr, 1);
    }

    jpeg_finish_compress(&cinfo);
    fclose(file);
}

void invert_colors(unsigned char *image_data, int width, int height) {
    for (int i = 0; i < width * height * 3; i++) {
        image_data[i] = 255 - image_data[i]; // Invert each color component
    }
}

void print_menu() {
    printf("\n=== Welcome to the Simple JPEG Image Editor ===\n");
    printf("1. Invert Colors\n");
    printf("2. Save Image\n");
    printf("3. Exit\n");
    printf("Please choose an option (1-3): ");
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <input_jpeg_file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    unsigned char *image_data;
    int width, height;

    read_jpeg(argv[1], &image_data, &width, &height);
    printf("Loaded image: %s (%dx%d)\n", argv[1], width, height);

    int choice;
    while (1) {
        print_menu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                invert_colors(image_data, width, height);
                printf("Colors inverted!\n");
                break;
            case 2: {
                char output_filename[256];
                printf("Enter output JPEG filename: ");
                scanf("%s", output_filename);
                write_jpeg(output_filename, image_data, width, height);
                printf("Image saved as: %s\n", output_filename);
                break;
            }
            case 3:
                free(image_data);
                printf("Thank you for using the Simple JPEG Image Editor! Goodbye!\n");
                return EXIT_SUCCESS;
            default:
                printf("Invalid option. Please select again.\n");
        }
    }

    free(image_data);
    return EXIT_SUCCESS;
}