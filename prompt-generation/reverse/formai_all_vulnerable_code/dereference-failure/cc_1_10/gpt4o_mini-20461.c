//GPT-4o-mini DATASET v1.0 Category: Digital Watermarking ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1024
#define WATERMARK_SIZE 128

// Function to embed watermark into the data
void embed_watermark(const char *data, const char *watermark, char *output) {
    int data_len = strlen(data);
    int watermark_len = strlen(watermark);
    
    for (int i = 0; i < data_len; i++) {
        // Embedding the watermark in every 8th byte of the data
        if (i % 8 == 0 && (i / 8) < watermark_len) {
            output[i] = (data[i] & 0xFE) | (watermark[i / 8] & 0x01); // Modifying the LSB
        } else {
            output[i] = data[i];
        }
    }
    output[data_len] = '\0'; // Null-terminate the output string
}

// Function to extract watermark from the data
void extract_watermark(const char *data, char *watermark) {
    int watermark_len = WATERMARK_SIZE;
    
    for (int i = 0; i < watermark_len; i++) {
        watermark[i] = 0; // Initialize the watermark
        // Extracting the watermark from every 8th byte of the data
        watermark[i] = (data[i * 8] & 0x01); 
    }
    watermark[watermark_len] = '\0'; // Null-terminate the extracted watermark
}

// Function to print the result
void print_result(const char *message, const char *data) {
    printf("%s: %s\n", message, data);
}

int main() {
    // The world has fallen into ruin. The memories must be preserved.
    char original_data[MAX_SIZE] = "This is a post-apocalyptic narrative where every byte counts.";
    char watermark[WATERMARK_SIZE] = "W@R#N555!";
    char watermarked_data[MAX_SIZE];
    char extracted_watermark[WATERMARK_SIZE];

    // Embedding the watermark into the original data
    embed_watermark(original_data, watermark, watermarked_data);

    // Output the original and watermarked data
    print_result("Original Data", original_data);
    print_result("Watermarked Data", watermarked_data);

    // Extracting watermark from the watermarked data
    extract_watermark(watermarked_data, extracted_watermark);

    // Convert extracted bits to characters for readable output
    char readable_extracted[WATERMARK_SIZE + 1] = {0};
    
    for (int i = 0; i < WATERMARK_SIZE; i++) {
        readable_extracted[i] = (extracted_watermark[i] == 1) ? '1' : '0';
    }
    
    print_result("Extracted Watermark (binary)", readable_extracted);
    
    // Verifying the effectiveness of the watermark
    if (strcmp(watermark, readable_extracted) == 0) {
        printf("The watermark has been successfully retrieved and verified!\n");
    } else {
        printf("Watermark retrieval failed! The data may have been manipulated!\n");
    }

    return 0;
}