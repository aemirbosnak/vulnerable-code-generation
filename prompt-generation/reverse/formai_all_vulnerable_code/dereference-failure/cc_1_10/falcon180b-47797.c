//Falcon-180B DATASET v1.0 Category: Digital Watermarking ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define WIDTH 512
#define HEIGHT 512
#define MAX_VALUE 255
#define THRESHOLD 10

// Function to generate a random number between 0 and 1
double rand_double() {
    return rand() / (double)RAND_MAX;
}

// Function to generate a random image
void generate_image(unsigned char* image_data) {
    for (int i = 0; i < WIDTH * HEIGHT; i++) {
        image_data[i] = rand() % MAX_VALUE;
    }
}

// Function to embed the watermark into the image
void embed_watermark(unsigned char* image_data, unsigned char* watermark) {
    for (int i = 0; i < WIDTH * HEIGHT; i++) {
        image_data[i] = image_data[i] + watermark[i % 8] - '0';
    }
}

// Function to extract the watermark from the image
unsigned char* extract_watermark(unsigned char* image_data) {
    unsigned char* watermark = (unsigned char*)malloc(WIDTH * HEIGHT * sizeof(unsigned char));
    for (int i = 0; i < WIDTH * HEIGHT; i++) {
        watermark[i] = image_data[i] % 10 + '0';
    }
    return watermark;
}

// Function to display the image
void display_image(unsigned char* image_data) {
    for (int i = 0; i < WIDTH * HEIGHT; i++) {
        printf("%c", image_data[i]);
    }
}

int main() {
    // Generate the random image
    unsigned char* image_data = (unsigned char*)malloc(WIDTH * HEIGHT * sizeof(unsigned char));
    generate_image(image_data);

    // Embed the watermark
    unsigned char* watermark = "FUTURE";
    embed_watermark(image_data, watermark);

    // Display the watermarked image
    printf("Watermarked Image:\n");
    display_image(image_data);

    // Extract the watermark
    unsigned char* extracted_watermark = extract_watermark(image_data);

    // Display the extracted watermark
    printf("\nExtracted Watermark:\n");
    for (int i = 0; i < WIDTH * HEIGHT; i++) {
        printf("%c", extracted_watermark[i]);
    }

    free(image_data);
    free(extracted_watermark);

    return 0;
}