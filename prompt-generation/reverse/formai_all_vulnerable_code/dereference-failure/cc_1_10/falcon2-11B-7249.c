//Falcon2-11B DATASET v1.0 Category: Digital Watermarking ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to add watermark to the image
void watermarkImage(char* image, char* watermark, int* watermarkSize) {
    int watermarkLength = strlen(watermark);
    int imageLength = strlen(image);

    // If the watermark is longer than the image, truncate it
    if (watermarkLength > imageLength) {
        watermarkLength = imageLength;
    }

    // Place the watermark at the end of the image
    memcpy(image + imageLength - watermarkLength, watermark, watermarkLength);
}

// Function to recursively find all occurrences of a substring within a string
void findSubstring(char* str, char* subStr, int* subStrSize) {
    int subStrLength = strlen(subStr);
    int strLength = strlen(str);

    // If the substring is longer than the string, return
    if (subStrLength > strLength) {
        return;
    }

    // Check if the substring is at the beginning of the string
    if (strncmp(str, subStr, subStrLength) == 0) {
        printf("%s\n", str);
        return;
    }

    // Recursively search the rest of the string
    findSubstring(str + subStrLength, subStr, subStrSize);
}

// Main function
int main() {
    char* image = "Lorem ipsum dolor sit amet, consectetur adipiscing elit.";
    char* watermark = "watermark";
    int watermarkSize = strlen(watermark);

    watermarkImage(image, watermark, &watermarkSize);

    // Find all occurrences of the watermark in the image
    findSubstring(image, watermark, &watermarkSize);

    return 0;
}