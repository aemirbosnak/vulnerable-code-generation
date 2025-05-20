//GEMINI-pro DATASET v1.0 Category: Digital Watermarking ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the watermark data structure
typedef struct {
    char *data;
    int length;
} Watermark;

// Load the watermark data from a file
Watermark *load_watermark(const char *filename) {
    FILE *fp = fopen(filename, "rb");
    if (fp == NULL) {
        fprintf(stderr, "Error opening watermark file: %s\n", filename);
        return NULL;
    }

    // Determine the size of the watermark file
    fseek(fp, 0, SEEK_END);
    int size = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    // Allocate memory for the watermark data
    Watermark *watermark = malloc(sizeof(Watermark));
    if (watermark == NULL) {
        fprintf(stderr, "Error allocating memory for watermark data\n");
        fclose(fp);
        return NULL;
    }

    // Read the watermark data from the file
    watermark->data = malloc(size);
    if (watermark->data == NULL) {
        fprintf(stderr, "Error allocating memory for watermark data\n");
        free(watermark);
        fclose(fp);
        return NULL;
    }
    fread(watermark->data, 1, size, fp);
    fclose(fp);

    // Set the watermark length
    watermark->length = size;

    return watermark;
}

// Embed the watermark data into an image
int embed_watermark(const char *image_filename, const char *watermark_filename, const char *output_filename) {
    // Load the image data
    FILE *fp = fopen(image_filename, "rb");
    if (fp == NULL) {
        fprintf(stderr, "Error opening image file: %s\n", image_filename);
        return -1;
    }

    // Determine the size of the image file
    fseek(fp, 0, SEEK_END);
    int image_size = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    // Load the watermark data
    Watermark *watermark = load_watermark(watermark_filename);
    if (watermark == NULL) {
        fprintf(stderr, "Error loading watermark data\n");
        fclose(fp);
        return -1;
    }

    // Check if the watermark data is too large to embed in the image
    if (watermark->length > image_size) {
        fprintf(stderr, "Error: watermark data is too large to embed in image\n");
        fclose(fp);
        free(watermark);
        return -1;
    }

    // Allocate memory for the output image data
    unsigned char *output_data = malloc(image_size);
    if (output_data == NULL) {
        fprintf(stderr, "Error allocating memory for output image data\n");
        fclose(fp);
        free(watermark);
        return -1;
    }

    // Read the image data into the output buffer
    fread(output_data, 1, image_size, fp);
    fclose(fp);

    // Embed the watermark data into the output image data
    for (int i = 0; i < watermark->length; i++) {
        output_data[i] = output_data[i] ^ watermark->data[i];
    }

    // Save the output image data to a file
    fp = fopen(output_filename, "wb");
    if (fp == NULL) {
        fprintf(stderr, "Error opening output image file: %s\n", output_filename);
        free(output_data);
        free(watermark);
        return -1;
    }
    fwrite(output_data, 1, image_size, fp);
    fclose(fp);

    // Free the allocated memory
    free(output_data);
    free(watermark);

    return 0;
}

// Extract the watermark data from an image
int extract_watermark(const char *image_filename, const char *watermark_filename) {
    // Load the image data
    FILE *fp = fopen(image_filename, "rb");
    if (fp == NULL) {
        fprintf(stderr, "Error opening image file: %s\n", image_filename);
        return -1;
    }

    // Determine the size of the image file
    fseek(fp, 0, SEEK_END);
    int image_size = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    // Load the watermark data
    Watermark *watermark = load_watermark(watermark_filename);
    if (watermark == NULL) {
        fprintf(stderr, "Error loading watermark data\n");
        fclose(fp);
        return -1;
    }

    // Allocate memory for the extracted watermark data
    unsigned char *extracted_data = malloc(watermark->length);
    if (extracted_data == NULL) {
        fprintf(stderr, "Error allocating memory for extracted watermark data\n");
        fclose(fp);
        free(watermark);
        return -1;
    }

    // Read the image data into the output buffer
    unsigned char *image_data = malloc(image_size);
    if (image_data == NULL) {
        fprintf(stderr, "Error allocating memory for image data\n");
        fclose(fp);
        free(watermark);
        free(extracted_data);
        return -1;
    }
    fread(image_data, 1, image_size, fp);
    fclose(fp);

    // Extract the watermark data from the image data
    for (int i = 0; i < watermark->length; i++) {
        extracted_data[i] = image_data[i] ^ watermark->data[i];
    }
    free(image_data);

    // Save the extracted watermark data to a file
    fp = fopen(watermark_filename, "wb");
    if (fp == NULL) {
        fprintf(stderr, "Error opening extracted watermark file: %s\n", watermark_filename);
        free(extracted_data);
        free(watermark);
        return -1;
    }
    fwrite(extracted_data, 1, watermark->length, fp);
    fclose(fp);

    // Free the allocated memory
    free(extracted_data);
    free(watermark);

    return 0;
}

int main(int argc, char *argv[]) {
    if (argc < 5) {
        fprintf(stderr, "Usage: %s <image_file> <watermark_file> <output_file> <embed/extract>\n", argv[0]);
        return -1;
    }

    const char *image_filename = argv[1];
    const char *watermark_filename = argv[2];
    const char *output_filename = argv[3];
    const char *operation = argv[4];

    if (strcmp(operation, "embed") == 0) {
        return embed_watermark(image_filename, watermark_filename, output_filename);
    } else if (strcmp(operation, "extract") == 0) {
        return extract_watermark(image_filename, watermark_filename);
    } else {
        fprintf(stderr, "Invalid operation: %s\n", operation);
        return -1;
    }

    return 0;
}