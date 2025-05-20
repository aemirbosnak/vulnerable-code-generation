//Falcon-180B DATASET v1.0 Category: Digital Watermarking ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define WIDTH 512
#define HEIGHT 512
#define MAX_VALUE 255

// Function to generate a random number within the given range
int rand_range(int min, int max) {
    return rand() % (max - min + 1) + min;
}

// Function to generate a random image
void generate_image(unsigned char *image, int width, int height) {
    for (int i = 0; i < width * height; i++) {
        image[i] = rand_range(0, MAX_VALUE);
    }
}

// Function to embed a watermark into an image
void embed_watermark(unsigned char *image, unsigned char *watermark, int width, int height) {
    for (int i = 0; i < width * height; i++) {
        image[i] = (image[i] + watermark[i % strlen(watermark)]) % MAX_VALUE;
    }
}

// Function to extract a watermark from an image
char *extract_watermark(unsigned char *image, int width, int height) {
    char *watermark = malloc(sizeof(char) * strlen(image) / width);
    for (int i = 0; i < strlen(image) / width; i++) {
        int sum = 0;
        for (int j = 0; j < width; j++) {
            sum += image[i * width + j];
        }
        watermark[i] = sum % MAX_VALUE;
    }
    return watermark;
}

int main() {
    // Generate a random image
    unsigned char *image = malloc(sizeof(unsigned char) * WIDTH * HEIGHT);
    generate_image(image, WIDTH, HEIGHT);

    // Embed a watermark into the image
    unsigned char *watermark = "Sherlock Holmes";
    embed_watermark(image, watermark, WIDTH, HEIGHT);

    // Save the watermarked image to a file
    FILE *fp = fopen("watermarked_image.bmp", "wb");
    fwrite(image, sizeof(unsigned char), WIDTH * HEIGHT, fp);
    fclose(fp);

    // Extract the watermark from the watermarked image
    char *extracted_watermark = extract_watermark(image, WIDTH, HEIGHT);
    printf("Extracted watermark: %s\n", extracted_watermark);

    // Free memory
    free(image);
    free(extracted_watermark);

    return 0;
}