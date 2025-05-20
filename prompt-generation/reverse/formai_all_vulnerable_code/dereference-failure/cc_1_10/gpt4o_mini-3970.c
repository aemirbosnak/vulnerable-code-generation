//GPT-4o-mini DATASET v1.0 Category: Digital Watermarking ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#define MAX_LEN 256
#define WATERMARK "WATERMARKED"
#define WATERMARK_LEN (sizeof(WATERMARK)-1)

void embed_watermark(const char *input_file, const char *output_file) {
    FILE *input = fopen(input_file, "rb");
    FILE *output = fopen(output_file, "wb");
    if (!input || !output) {
        fprintf(stderr, "Error opening files.\n");
        exit(EXIT_FAILURE);
    }
    
    fseek(input, 0, SEEK_END);
    long input_size = ftell(input);
    fseek(input, 0, SEEK_SET);

    uint8_t *buffer = (uint8_t *)malloc(input_size + WATERMARK_LEN);
    if (!buffer) {
        fclose(input);
        fclose(output);
        fprintf(stderr, "Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }
    
    fread(buffer, 1, input_size, input);
    fclose(input);
    memcpy(buffer + input_size, WATERMARK, WATERMARK_LEN);
    
    fwrite(buffer, 1, input_size + WATERMARK_LEN, output);
    fclose(output);
    free(buffer);
    printf("Watermark embedded successfully.\n");
}

int verify_watermark(const char *output_file) {
    FILE *output = fopen(output_file, "rb");
    if (!output) {
        fprintf(stderr, "Error opening file for verification.\n");
        return -1;
    }
    
    fseek(output, 0, SEEK_END);
    long output_size = ftell(output);
    fseek(output, output_size - WATERMARK_LEN, SEEK_SET);

    char buffer[MAX_LEN];
    fread(buffer, 1, WATERMARK_LEN, output);
    fclose(output);
    
    if (memcmp(buffer, WATERMARK, WATERMARK_LEN) == 0) {
        printf("Watermark verified successfully.\n");
        return 0;
    } else {
        printf("Watermark verification failed.\n");
        return -1;
    }
}

void usage(const char *prog_name) {
    fprintf(stderr, "Usage: %s <embed|verify> <input_file> <output_file>\n", prog_name);
    fprintf(stderr, "Example to embed: %s embed image.png watermarked_image.png\n", prog_name);
    fprintf(stderr, "Example to verify: %s verify watermarked_image.png\n", prog_name);
    exit(EXIT_FAILURE);
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        usage(argv[0]);
    }
    
    if (strcmp(argv[1], "embed") == 0) {
        embed_watermark(argv[2], argv[3]);
    } else if (strcmp(argv[1], "verify") == 0) {
        int result = verify_watermark(argv[2]);
        return result;
    } else {
        usage(argv[0]);
    }
    
    return 0;
}