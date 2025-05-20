//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#define MAX_FILE_NAME_LENGTH 256 // Maximum length of the file name
#define MAX_TEXT_LENGTH 1024 // Maximum length of the watermark text
#define LSB_MASK 0x01 // Lowest significant bit mask

void encode_watermark(char *in_file_name, char *out_file_name, char *watermark_text) {
    FILE *in_file, *out_file;
    in_file = fopen(in_file_name, "rb");
    out_file = fopen(out_file_name, "wb");
    if (!in_file || !out_file) {
        printf("Error opening files!\n");
        return;
    }
    uint8_t watermark[MAX_TEXT_LENGTH]; // Store the watermark text
    uint32_t wm_len = strlen(watermark_text); // Get the watermark text length
    memcpy(watermark, watermark_text, wm_len); // Copy the watermark text to the buffer
    fwrite(&wm_len, sizeof(uint32_t), 1, out_file); // Write the watermark length to output file
    fwrite(watermark, sizeof(uint8_t), wm_len, out_file); // Write the watermark text to output file
    uint8_t buffer;
    uint32_t count = 0;
    while (fread(&buffer, sizeof(uint8_t), 1, in_file) == 1) {
        if (count < wm_len) { // Only encode if possible
            uint8_t mask = LSB_MASK; // Start with the LSB mask
            uint8_t wm_byte = watermark[count];
            for (int i = 0; i < 8; i++) {
                if (wm_byte & 0x01) {
                    buffer |= mask; // Set the LSB to 1
                } else {
                    buffer &= ~mask; // Set the LSB to 0
                }
                mask <<= 1;
                wm_byte >>= 1;
            }
            count++;
        }
        fwrite(&buffer, sizeof(uint8_t), 1, out_file);
    }
    fclose(in_file);
    fclose(out_file);
}

void decode_watermark(char *in_file_name) {
    FILE *in_file;
    in_file = fopen(in_file_name, "rb");
    if (!in_file) {
        printf("Error opening file!\n");
        return;
    }
    uint32_t wm_len;
    fread(&wm_len, sizeof(uint32_t), 1, in_file); // Read the watermark length
    uint8_t watermark[MAX_TEXT_LENGTH];
    fread(watermark, sizeof(uint8_t), wm_len, in_file); // Read the watermark text
    uint8_t buffer;
    uint32_t count = 0;
    while (fread(&buffer, sizeof(uint8_t), 1, in_file) == 1) {
        if (count < wm_len) { // Only decode if possible
            uint8_t mask = LSB_MASK; // Start with the LSB mask
            uint8_t wm_byte = 0;
            for (int i = 0; i < 8; i++) {
                if (buffer & mask) {
                    wm_byte |= LSB_MASK; // Set the LSB to 1
                }
                mask <<= 1;
            }
            watermark[count] = wm_byte;
            count++;
        }
    }
    printf("Decoded watermark: %s\n", watermark);
    fclose(in_file);
}

int main() {
    char in_file_name[MAX_FILE_NAME_LENGTH] = "test_image.jpeg";
    char out_file_name[MAX_FILE_NAME_LENGTH] = "watermarked_image.jpeg";
    char watermark_text[MAX_TEXT_LENGTH] = "Hello, this is a test watermark!";
    encode_watermark(in_file_name, out_file_name, watermark_text);
    decode_watermark(out_file_name);
    return 0;
}