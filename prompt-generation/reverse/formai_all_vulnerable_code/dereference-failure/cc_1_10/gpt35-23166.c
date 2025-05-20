//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_TEXT_SIZE 100

/* Function to convert an integer to a binary string */
char* int_to_binary(int n, int num_bits) {
    char* binary_string = (char*) malloc(sizeof(char) * (num_bits + 1));

    for (int i = num_bits - 1; i >= 0; i--) {
        binary_string[i] = (n & 1) + '0';    // add the rightmost bit to the string
        n >>= 1;    // shift the number to the right by one
    }
    binary_string[num_bits] = '\0';    // add the null terminator at the end
    return binary_string;
}

/* Function to convert a binary string to an integer */
int binary_to_int(char* binary_string) {
    int n = 0;
    for (int i = 0; i < strlen(binary_string); i++) {
        n = n << 1;    // shift the number to the left by one
        if (binary_string[i] == '1') {
            n += 1;    // add a 1 to the rightmost bit if it's a '1'
        }
    }
    return n;
}

/* Function to add the watermark to the image */
void add_watermark(int** image, char* watermark, int watermark_size) {
    int width = sizeof(image[0]) / sizeof(int);
    int height = sizeof(image) / sizeof(image[0]);

    // Set seed for srand()
    srand(time(0));

    // Randomly select a pixel to start the watermark
    int x = rand() % width;
    int y = rand() % height;

    int bit_index = 0;    // keeps track of which bit of the watermark we're currently on

    // Loop through the image until we've added all the bits of the watermark
    while (bit_index < watermark_size) {
        // Get the next bit of the watermark
        int bit = (watermark[bit_index / 8] >> (bit_index % 8)) & 1;

        // If the pixel already contains the watermark bit, skip it
        if ((image[y][x] & 1) == bit) {
            x = (x + 1) % width;
            if (x == 0) {
                y = (y + 1) % height;
            }
            continue;
        }

        // Use the LSB of each channel to store the watermark bits
        image[y][x] = (image[y][x] & ~1) | bit;

        // Move to the next pixel
        x = (x + 1) % width;
        if (x == 0) {
            y = (y + 1) % height;
        }

        // Increment the bit_index
        bit_index++;
    }

    printf("Watermark added!\n");
}

/* Function to extract the watermark from the image */
void extract_watermark(int** image, char* watermark, int watermark_size) {
    int width = sizeof(image[0]) / sizeof(int);
    int height = sizeof(image) / sizeof(image[0]);

    // Set seed for srand()
    srand(time(0));

    // Randomly select a pixel to start extracting the watermark
    int x = rand() % width;
    int y = rand() % height;

    int bit_index = 0;    // keeps track of which bit of the watermark we're currently on

    // Loop through the image until we've extracted all the bits of the watermark
    while (bit_index < watermark_size) {
        // Get the LSB of each channel to extract the watermark bit
        int bit = image[y][x] & 1;

        // Add the bit to the watermark message
        watermark[bit_index / 8] |= bit << (bit_index % 8);

        // Move to the next pixel
        x = (x + 1) % width;
        if (x == 0) {
            y = (y + 1) % height;
        }

        // Increment the bit_index
        bit_index++;
    }

    printf("Extracted watermark: %s\n", watermark);
}

int main() {
    // Lets create a sample image of size 2x2
    int image[2][2] = {
        { 0b00110011, 0b11001100 },
        { 0b01010101, 0b10101010 }
    };

    // Lets add a sample watermark message
    char* message = "This is a test message";
    int watermark_size = strlen(message) * 8;    // watermark size in bits
    char* watermark = (char*) calloc((watermark_size / 8) + 1, sizeof(char));
    strcpy(watermark, message);

    add_watermark((int**) image, watermark, watermark_size);
    extract_watermark((int**) image, watermark, watermark_size);

    free(watermark);

    return 0;
}