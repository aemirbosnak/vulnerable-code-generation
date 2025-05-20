//GPT-4o-mini DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <jpeglib.h>
#include <string.h>

// Structure to hold the image data
typedef struct {
    int width;
    int height;
    unsigned char *data;
} Image;

// Function declarations
Image* load_image(const char *filename);
void save_image(const char *filename, Image *img);
void flip_image(Image *img);
void adjust_brightness(Image *img, int value);
void adjust_contrast(Image *img, float factor);
void free_image(Image *img);

int main(int argc, char **argv) {
    if (argc < 5) {
        printf("Usage: %s <input_file> <output_file> <operation> <value>\n", argv[0]);
        printf("Operations: flip, brightness, contrast\n");
        return 1;
    }

    const char *input_file = argv[1];
    const char *output_file = argv[2];
    const char *operation = argv[3];
    int value = atoi(argv[4]);

    // Load the image
    Image *img = load_image(input_file);
    if (!img) {
        fprintf(stderr, "Error loading image: %s\n", input_file);
        return 1;
    }

    // Perform specified operation
    if (strcmp(operation, "flip") == 0) {
        flip_image(img);
    } else if (strcmp(operation, "brightness") == 0) {
        adjust_brightness(img, value);
    } else if (strcmp(operation, "contrast") == 0) {
        adjust_contrast(img, (float)value);
    } else {
        fprintf(stderr, "Unknown operation: %s\n", operation);
        free_image(img);
        return 1;
    }

    // Save the modified image
    save_image(output_file, img);
    free_image(img);
    return 0;
}

// Load an image from a JPEG file
Image* load_image(const char *filename) {
    struct jpeg_decompress_struct cinfo;
    struct jpeg_error_mgr jerr;
    FILE *infile;

    if ((infile = fopen(filename, "rb")) == NULL) {
        fprintf(stderr, "Cannot open %s\n", filename);
        return NULL;
    }

    cinfo.err = jpeg_std_error(&jerr);
    jpeg_create_decompress(&cinfo);
    jpeg_stdio_src(&cinfo, infile);
    jpeg_read_header(&cinfo, TRUE);
    jpeg_start_decompress(&cinfo);

    Image *img = (Image *)malloc(sizeof(Image));
    img->width = cinfo.output_width;
    img->height = cinfo.output_height;
    img->data = (unsigned char *)malloc(cinfo.output_width * cinfo.output_height * 3);

    unsigned char *row_pointer[1];
    while (cinfo.output_scanline < cinfo.output_height) {
        row_pointer[0] = img->data + (cinfo.output_scanline) * cinfo.output_width * 3;
        jpeg_read_scanlines(&cinfo, row_pointer, 1);
    }

    jpeg_finish_decompress(&cinfo);
    fclose(infile);
    return img;
}

// Save an image to a JPEG file
void save_image(const char *filename, Image *img) {
    struct jpeg_compress_struct cinfo;
    struct jpeg_error_mgr jerr;
    FILE *outfile;

    if ((outfile = fopen(filename, "wb")) == NULL) {
        fprintf(stderr, "Cannot open %s\n", filename);
        return;
    }

    cinfo.err = jpeg_std_error(&jerr);
    jpeg_create_compress(&cinfo);
    jpeg_stdio_dest(&cinfo, outfile);

    cinfo.image_width = img->width;
    cinfo.image_height = img->height;
    cinfo.input_components = 3;
    cinfo.in_color_space = JCS_RGB;

    jpeg_set_defaults(&cinfo);
    jpeg_start_compress(&cinfo, TRUE);

    unsigned char *row_pointer[1];
    while (cinfo.next_scanline < cinfo.image_height) {
        row_pointer[0] = img->data + (cinfo.next_scanline) * img->width * 3;
        jpeg_write_scanlines(&cinfo, row_pointer, 1);
    }

    jpeg_finish_compress(&cinfo);
    fclose(outfile);
}

// Flip the image vertically
void flip_image(Image *img) {
    int row_size = img->width * 3;
    unsigned char *temp = (unsigned char *)malloc(row_size);

    for (int i = 0; i < img->height / 2; i++) {
        memcpy(temp, img->data + i * row_size, row_size);
        memcpy(img->data + i * row_size, img->data + (img->height - i - 1) * row_size, row_size);
        memcpy(img->data + (img->height - i - 1) * row_size, temp, row_size);
    }

    free(temp);
}

// Adjust the brightness of the image
void adjust_brightness(Image *img, int value) {
    for (int i = 0; i < img->width * img->height * 3; i++) {
        int new_value = img->data[i] + value;
        img->data[i] = (new_value < 0) ? 0 : (new_value > 255) ? 255 : new_value;
    }
}

// Adjust the contrast of the image
void adjust_contrast(Image *img, float factor) {
    for (int i = 0; i < img->width * img->height * 3; i++) {
        int new_value = (int)((factor - 1) * 128 + factor * img->data[i]);
        img->data[i] = (new_value < 0) ? 0 : (new_value > 255) ? 255 : new_value;
    }
}

// Free the image data
void free_image(Image *img) {
    if (img) {
        free(img->data);
        free(img);
    }
}