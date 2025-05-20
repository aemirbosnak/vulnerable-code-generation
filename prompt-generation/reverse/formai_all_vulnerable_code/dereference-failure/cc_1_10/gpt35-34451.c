//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the size of the data buffer
#define DATA_SIZE 1024

// Define the size of the watermark buffer
#define WATERMARK_SIZE 128

// This function takes a data buffer and watermark buffer as input and returns a new data buffer with the watermark embedded.
char* embed_watermark(char* data, char* watermark) {
    // Allocate memory for the new data buffer
    char* new_data = (char*) malloc(DATA_SIZE);

    // Copy the original data buffer to the new data buffer
    memcpy(new_data, data, DATA_SIZE);

    // Embed the watermark in the new data buffer
    memcpy(new_data + (DATA_SIZE - WATERMARK_SIZE), watermark, WATERMARK_SIZE);

    return new_data;
}

// This function takes a data buffer as input and returns the embedded watermark buffer
char* extract_watermark(char* data) {
    // Allocate memory for the watermark buffer
    char* watermark = (char*) malloc(WATERMARK_SIZE);

    // Extract the watermark from the data buffer
    memcpy(watermark, data + (DATA_SIZE - WATERMARK_SIZE), WATERMARK_SIZE);

    return watermark;
}

int main() {
    // Define the data and watermark buffers
    char data[DATA_SIZE];
    char watermark[WATERMARK_SIZE];

    // Read input data and watermark from user
    printf("Enter data (max %d characters):\n", DATA_SIZE - WATERMARK_SIZE);
    fgets(data, DATA_SIZE - WATERMARK_SIZE, stdin);

    printf("Enter watermark (max %d characters):\n", WATERMARK_SIZE);
    fgets(watermark, WATERMARK_SIZE, stdin);

    // Embed watermark in data
    char* new_data = embed_watermark(data, watermark);

    // Extract watermark from data
    char* extracted_watermark = extract_watermark(new_data);

    // Print original data, embedded data, and extracted watermark
    printf("Original data: %s\n", data);
    printf("Embedded data: %s\n", new_data);
    printf("Extracted watermark: %s\n", extracted_watermark);

    // Free memory
    free(new_data);
    free(extracted_watermark);

    return 0;
}