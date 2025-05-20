//Falcon-180B DATASET v1.0 Category: Digital Watermarking ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WATERMARK_SIZE 64
#define WATERMARK_VALUE "This is a secret watermark"

// Function to embed the watermark into the image
void embed_watermark(char* image_path, char* output_path) {
    FILE* image_file = fopen(image_path, "rb");
    if (image_file == NULL) {
        printf("Error: Could not open image file.\n");
        exit(1);
    }

    FILE* output_file = fopen(output_path, "wb");
    if (output_file == NULL) {
        printf("Error: Could not open output file.\n");
        fclose(image_file);
        exit(1);
    }

    fseek(image_file, 0, SEEK_END);
    long image_size = ftell(image_file);
    fseek(image_file, 0, SEEK_SET);

    char* image_data = malloc(image_size);
    fread(image_data, 1, image_size, image_file);
    fclose(image_file);

    int watermark_size = strlen(WATERMARK_VALUE);
    int watermark_offset = image_size - watermark_size;

    memcpy(image_data + watermark_offset, WATERMARK_VALUE, watermark_size);

    fwrite(image_data, 1, image_size, output_file);
    fclose(output_file);

    free(image_data);
}

// Function to detect the watermark in the image
int detect_watermark(char* image_path) {
    FILE* image_file = fopen(image_path, "rb");
    if (image_file == NULL) {
        printf("Error: Could not open image file.\n");
        exit(1);
    }

    fseek(image_file, 0, SEEK_END);
    long image_size = ftell(image_file);
    fseek(image_file, 0, SEEK_SET);

    char* image_data = malloc(image_size);
    fread(image_data, 1, image_size, image_file);
    fclose(image_file);

    int watermark_size = strlen(WATERMARK_VALUE);
    int watermark_offset = image_size - watermark_size;

    char* watermark_data = malloc(watermark_size);
    memcpy(watermark_data, image_data + watermark_offset, watermark_size);

    if (strcmp(watermark_data, WATERMARK_VALUE) == 0) {
        printf("Watermark detected!\n");
        return 1;
    } else {
        printf("Watermark not detected.\n");
        return 0;
    }
}

int main() {
    char* image_path = "example.jpg";
    char* output_path = "watermarked_image.jpg";

    embed_watermark(image_path, output_path);

    printf("Watermark embedded into image.\n");

    int watermark_detected = detect_watermark(output_path);

    if (watermark_detected) {
        printf("Watermark detected in image.\n");
    } else {
        printf("Watermark not detected in image.\n");
    }

    return 0;
}