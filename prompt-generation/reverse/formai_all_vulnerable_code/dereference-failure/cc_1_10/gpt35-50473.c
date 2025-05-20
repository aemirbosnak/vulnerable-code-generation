//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Function to hide the watermark in the image
void hideWatermark(unsigned char* image, int imageSize, unsigned char* watermark, int watermarkSize, int startIndex) {
    int index = startIndex; 
    for(int i = 0; i < watermarkSize; i++) {
        image[index] = (image[index] & 0xFE) | ((watermark[i] & 0x01) ^ ((image[index] & 0x01) ^ 0x01));
        index++;
        if(index >= imageSize) {
            break;
        }
    }
}

// Function to find the watermark in the image
unsigned char* findWatermark(unsigned char* image, int messageLength, int startIndex) {
    int index = startIndex;
    unsigned char* watermark = malloc(sizeof(unsigned char) * messageLength);
    memset(watermark, 0, messageLength);
    for(int i = 0; i < messageLength; i++) {
        watermark[i] = (image[index] & 0x01);
        index++;
        if(index >= messageLength) {
            break;
        }
    }
    return watermark;
}

int main() {
    // Example image (64x64 pixels) and watermark (4 byte message)
    unsigned char image[4096];
    unsigned char watermark[4] = {'W', 'A', 'T', 'R'};

    // Set the seed for the random number generator
    srand(time(NULL));

    // Generate a random start index for hiding the watermark
    int startIndex = rand() % 2000;
    printf("Start index: %d\n", startIndex);

    // Hide the watermark in the image
    hideWatermark(image, 4096, watermark, 4, startIndex);

    // Find the watermark in the image
    unsigned char* foundWatermark = findWatermark(image, 4, startIndex);
    printf("Found watermark: %c%c%c%c\n", foundWatermark[0], foundWatermark[1], foundWatermark[2], foundWatermark[3]);

    free(foundWatermark);

    return 0;
}