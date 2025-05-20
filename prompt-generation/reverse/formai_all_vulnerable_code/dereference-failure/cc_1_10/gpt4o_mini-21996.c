//GPT-4o-mini DATASET v1.0 Category: Digital Watermarking ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#define MAX_SIZE 1024

void embed_watermark(const char *input_filename, const char *output_filename, const char *watermark) {
    FILE *input_file = fopen(input_filename, "rb");
    FILE *output_file = fopen(output_filename, "wb");
    
    if (!input_file || !output_file) {
        perror("File opening failed");
        return;
    }

    uint8_t buffer[MAX_SIZE];
    size_t bytes_read;
    size_t watermark_len = strlen(watermark);
    
    // Embed watermark in the least significant bits of the image
    while ((bytes_read = fread(buffer, sizeof(uint8_t), MAX_SIZE, input_file)) > 0) {
        for (size_t i = 0; i < bytes_read; i++) {
            // Modify the least significant bit with watermark bits
            if (i < watermark_len) {
                buffer[i] = (buffer[i] & 0xFE) | ((watermark[i] & 0x01) ? 1 : 0);
            }
        }
        fwrite(buffer, sizeof(uint8_t), bytes_read, output_file);
    }
    
    fclose(input_file);
    fclose(output_file);
}

void extract_watermark(const char *watermarked_filename, char *extracted_watermark, size_t watermark_length) {
    FILE *file = fopen(watermarked_filename, "rb");
    
    if (!file) {
        perror("File opening failed");
        return;
    }
    
    uint8_t buffer[MAX_SIZE];
    size_t bytes_read;
    
    // Extract watermark from the least significant bits of the image
    for (size_t i = 0; i < watermark_length; i++) {
        if ((bytes_read = fread(buffer, sizeof(uint8_t), MAX_SIZE, file)) == 0) {
            break;
        }
        // Get the watermark bit from the least significant bit
        extracted_watermark[i] = (buffer[i] & 0x01) ? 1 : 0;
    }
    
    fclose(file);
}

void display_extracted_watermark(const char *extracted_watermark, size_t length) {
    printf("The extracted watermark is: ");
    for (size_t i = 0; i < length; i++) {
        printf("%d", extracted_watermark[i]);
    }
    printf("\n");
}

int main(int argc, char *argv[]) {
    if (argc < 4) {
        printf("Usage: %s <input_file> <output_file> <watermark>\n", argv[0]);
        return EXIT_FAILURE;
    }
    
    const char *input_file = argv[1];
    const char *output_file = argv[2];
    const char *watermark = argv[3];
    size_t watermark_length = strlen(watermark) > MAX_SIZE ? MAX_SIZE : strlen(watermark);
    
    // Prepare to extract watermark
    char extracted_watermark[MAX_SIZE] = {0};

    // Embed watermark
    embed_watermark(input_file, output_file, watermark);
    
    // Extract watermark
    extract_watermark(output_file, extracted_watermark, watermark_length);
    
    // Display extracted watermark
    display_extracted_watermark(extracted_watermark, watermark_length);
    
    return EXIT_SUCCESS;
}