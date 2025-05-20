//GPT-4o-mini DATASET v1.0 Category: Digital Watermarking ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WATERMARK "This is a digital watermark."
#define WM_LENGTH (sizeof(WATERMARK) - 1)
#define BUFFER_SIZE 1024

void embed_watermark(const char *input_file, const char *output_file) {
    FILE *input = fopen(input_file, "rb");
    FILE *output = fopen(output_file, "wb");
    
    if (!input || !output) {
        perror("File error");
        exit(EXIT_FAILURE);
    }

    char buffer[BUFFER_SIZE];
    size_t bytesRead;
    
    while ((bytesRead = fread(buffer, 1, BUFFER_SIZE, input)) > 0) {
        fwrite(buffer, 1, bytesRead, output);
    }

    // Embed the watermark at the end of the file
    fwrite(WATERMARK, 1, WM_LENGTH, output);
    
    fclose(input);
    fclose(output);
}

void extract_watermark(const char *file) {
    FILE *input = fopen(file, "rb");
    if (!input) {
        perror("File error");
        exit(EXIT_FAILURE);
    }

    // Move to the end to check watermark
    fseek(input, -WM_LENGTH, SEEK_END);
    char buffer[WM_LENGTH + 1];
    fread(buffer, 1, WM_LENGTH, input);
    buffer[WM_LENGTH] = '\0';

    if (strcmp(buffer, WATERMARK) == 0) {
        printf("Watermark found: '%s'\n", buffer);
    } else {
        printf("No watermark detected.\n");
    }

    fclose(input);
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        fprintf(stderr, "Usage: %s <embed/extract> <input_file> [output_file]\n", argv[0]);
        return EXIT_FAILURE;
    }

    if (strcmp(argv[1], "embed") == 0) {
        if (argc != 4) {
            fprintf(stderr, "Usage for embedding: %s embed <input_file> <output_file>\n", argv[0]);
            return EXIT_FAILURE;
        }
        embed_watermark(argv[2], argv[3]);
        printf("Watermark embedded successfully.\n");
    } 
    else if (strcmp(argv[1], "extract") == 0) {
        extract_watermark(argv[2]);
    } 
    else {
        fprintf(stderr, "Unknown command: %s. Use 'embed' or 'extract'.\n", argv[1]);
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}