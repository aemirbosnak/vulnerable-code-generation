//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_LEN 256

// Structure to represent a pixel
struct Pixel {
    unsigned char red;
    unsigned char green;
    unsigned char blue;
};

// Function to read the pixel values from an image file
void read_image(const char* filename, struct Pixel** pixels, int* width, int* height) {
    FILE* file = fopen(filename, "rb"); // Open the file in binary mode
    if (file == NULL) {
        printf("Error: Could not open file %s\n", filename);
        exit(EXIT_FAILURE);
    }

    // Read the image dimensions from the header
    unsigned char header[54];
    fread(header, sizeof(unsigned char), 54, file);
    *width = *(int*)(header + 18);
    *height = *(int*)(header + 22);

    // Allocate memory for the pixel array
    *pixels = (struct Pixel*) malloc((*width) * (*height) * sizeof(struct Pixel));

    // Read the pixel values from the file
    int padding = (4 - ((*width) * sizeof(struct Pixel)) % 4) % 4; // Padding for each row to make it a multiple of 4
    int pos = 0;
    for (int y = 0; y < *height; y++) {
        for (int x = 0; x < *width; x++) {
            struct Pixel pixel;
            fread(&pixel.blue, sizeof(unsigned char), 1, file);
            fread(&pixel.green, sizeof(unsigned char), 1, file);
            fread(&pixel.red, sizeof(unsigned char), 1, file);
            (*pixels)[pos++] = pixel;
        }
        fseek(file, padding, SEEK_CUR); // Skip the padding bytes
    }

    fclose(file);
}

// Function to write the pixel values to an image file
void write_image(const char* filename, const struct Pixel* pixels, int width, int height) {
    FILE* file = fopen(filename, "wb"); // Open the file in binary mode
    if (file == NULL) {
        printf("Error: Could not open file %s\n", filename);
        exit(EXIT_FAILURE);
    }

    // Write the header for a BMP image
    unsigned char header[54] = {
        // Bitmap file header
        'B', 'M', 0, 0, 0, 0, 0, 0, 0, 0, 54, 0, 0, 0,
        // DIB header
        40, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 24, 0
    };
    *(int*)(header + 18) = width;
    *(int*)(header + 22) = height;
    int padding = (4 - (width * sizeof(struct Pixel)) % 4) % 4; // Padding for each row to make it a multiple of 4
    *(int*)(header + 2) = sizeof(header) + (width * height * sizeof(struct Pixel)) + (height * padding);
    fwrite(header, sizeof(unsigned char), 54, file);

    // Write the pixel values to the file
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            fwrite(&pixels[y * width + x].blue, sizeof(unsigned char), 1, file);
            fwrite(&pixels[y * width + x].green, sizeof(unsigned char), 1, file);
            fwrite(&pixels[y * width + x].red, sizeof(unsigned char), 1, file);
        }
        unsigned char pad = 0;
        fwrite(&pad, sizeof(unsigned char), padding, file); // Write the padding bytes
    }

    fclose(file);
}

// Function to embed a digital watermark in an image
void embed_watermark(const char* input_filename, const char* output_filename, const char* watermark) {
    struct Pixel* pixels;
    int width, height;
    read_image(input_filename, &pixels, &width, &height);

    int watermark_len = strlen(watermark);
    if (watermark_len > width * height) {
        printf("Error: Watermark is too long for the image\n");
        free(pixels);
        exit(EXIT_FAILURE);
    }

    // Convert the watermark to binary
    unsigned char* binary = (unsigned char*) malloc(watermark_len * sizeof(unsigned char) * 8);
    for (int i = 0; i < watermark_len; i++) {
        for (int j = 0; j < 8; j++) {
            binary[i * 8 + j] = (watermark[i] >> (7 - j)) & 1;
        }
    }

    // Embed the binary watermark in the LSB of each color channel of each pixel
    for (int i = 0; i < watermark_len * 8; i++) {
        int pixel_index = i / 3;
        int channel_index = i % 3;
        if (channel_index == 0) {
            pixels[pixel_index].blue = (pixels[pixel_index].blue & ~1) | binary[i];
        } else if (channel_index == 1) {
            pixels[pixel_index].green = (pixels[pixel_index].green & ~1) | binary[i];
        } else {
            pixels[pixel_index].red = (pixels[pixel_index].red & ~1) | binary[i];
        }
    }

    free(binary);

    write_image(output_filename, pixels, width, height);

    free(pixels);

    printf("Digital watermarking complete for image %s with watermark \"%s\"\n", input_filename, watermark);
}

// Function to extract a digital watermark from an image
void extract_watermark(const char* filename) {
    struct Pixel* pixels;
    int width, height;
    read_image(filename, &pixels, &width, &height);

    // Extract the binary watermark from the LSB of each color channel of each pixel
    unsigned char* binary = (unsigned char*) malloc(width * height * sizeof(unsigned char) * 8);
    for (int i = 0; i < width * height * 8; i++) {
        int pixel_index = i / 3;
        int channel_index = i % 3;
        if (channel_index == 0) {
            binary[i] = pixels[pixel_index].blue & 1;
        } else if (channel_index == 1) {
            binary[i] = pixels[pixel_index].green & 1;
        } else {
            binary[i] = pixels[pixel_index].red & 1;
        }
    }

    // Convert the binary watermark to a null-terminated string
    char* watermark = (char*) malloc(width * height * sizeof(char));
    for (int i = 0; i < width * height * 8; i += 8) {
        char c = 0;
        for (int j = 0; j < 8; j++) {
            c |= binary[i + j] << (7 - j);
        }
        watermark[i / 8] = c;
    }
    watermark[width * height] = '\0';

    free(binary);
    free(pixels);

    printf("Extracted digital watermark from image %s: \"%s\"\n", filename, watermark);

    free(watermark);
}

int main() {
    printf("Enter a command:\n");
    printf("  1. Embed watermark\n");
    printf("  2. Extract watermark\n");

    int command;
    do {
        printf("> ");
        scanf("%d", &command);
    } while (command < 1 || command > 2);

    char input_filename[MAX_FILENAME_LEN];
    char output_filename[MAX_FILENAME_LEN];
    char watermark[MAX_FILENAME_LEN];
    switch (command) {
        case 1:
            printf("Enter the input image file name:\n");
            printf("> ");
            scanf("%s", input_filename);

            printf("Enter the output image file name:\n");
            printf("> ");
            scanf("%s", output_filename);

            printf("Enter the watermark to embed:\n");
            printf("> ");
            scanf("%s", watermark);

            embed_watermark(input_filename, output_filename, watermark);
            break;
        case 2:
            printf("Enter the image file name:\n");
            printf("> ");
            scanf("%s", input_filename);

            extract_watermark(input_filename);
            break;
    }

    return 0;
}