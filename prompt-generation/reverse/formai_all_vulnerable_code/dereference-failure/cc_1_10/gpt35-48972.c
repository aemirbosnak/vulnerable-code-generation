//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to add a digital watermark to a given image
void add_digital_watermark(char *image_path, char *watermark) {
    FILE *image_file = fopen(image_path, "r+b");

    if (image_file == NULL) {
        perror("Error opening image file");
        exit(1);
    }

    // Write the watermark to the end of the image file
    fseek(image_file, 0, SEEK_END);
    fwrite(watermark, sizeof(char), strlen(watermark), image_file);
    fclose(image_file);
}

// Function to extract a digital watermark from a given image
char* extract_digital_watermark(char *image_path, int len) {
    FILE *image_file = fopen(image_path, "rb");

    if (image_file == NULL) {
        perror("Error opening image file");
        exit(1);
    }

    // Seek to the end of the image file
    fseek(image_file, 0, SEEK_END);
    long size = ftell(image_file);

    // Seek to the start of the watermark
    fseek(image_file, size - len, SEEK_SET);

    // Allocate memory for the watermark string
    char *watermark = (char*)malloc(len * sizeof(char));

    // Read the watermark into the string
    fread(watermark, sizeof(char), len, image_file);

    // Close the image file
    fclose(image_file);

    return watermark;
}

int main() {
    char *image_path = "example_image.jpg";
    char *watermark = "This is a digital watermark!";

    // Add the watermark to the image
    add_digital_watermark(image_path, watermark);
    printf("Digital watermark added to image\n");

    // Extract the watermark from the image and print it
    char *extracted_watermark = extract_digital_watermark(image_path, strlen(watermark));
    printf("Extracted watermark: %s\n", extracted_watermark);

    // Free memory
    free(extracted_watermark);

    return 0;
}