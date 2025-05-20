//GPT-4o-mini DATASET v1.0 Category: Digital Watermarking ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_SIZE 1048576  // 1 MB limit for demonstration
#define WATERMARK "WATERMARK"   // Sample watermark text

void embed_watermark(const char *input_file, const char *output_file, const char *watermark) {
    FILE *input = fopen(input_file, "r");
    if (!input) {
        perror("Failed to open input file");
        return;
    }
    
    FILE *output = fopen(output_file, "w");
    if (!output) {
        perror("Failed to open output file");
        fclose(input);
        return;
    }

    char buffer[MAX_FILE_SIZE];
    size_t bytes_read = fread(buffer, 1, sizeof(buffer) - 1, input);
    buffer[bytes_read] = '\0'; // Null-terminate the buffer

    // Append the watermark to the buffer
    strcat(buffer, "\n");
    strcat(buffer, watermark);

    // Write buffer to output file
    fwrite(buffer, 1, strlen(buffer), output);

    fclose(input);
    fclose(output);
    printf("Watermark embedded successfully.\n");
}

void extract_watermark(const char *file_path) {
    FILE *file = fopen(file_path, "r");
    if (!file) {
        perror("Failed to open the file");
        return;
    }

    char buffer[MAX_FILE_SIZE];
    size_t bytes_read = fread(buffer, 1, sizeof(buffer), file);
    buffer[bytes_read] = '\0'; // Null-terminate the buffer

    // Finding watermark in the file
    char *watermark_position = strrchr(buffer, '\n');
    if (watermark_position != NULL) {
        printf("Extracted Watermark: %s", watermark_position + 1);
    } else {
        printf("No watermark found.\n");
    }

    fclose(file);
}

int main(int argc, char *argv[]) {
    if (argc < 4) {
        printf("Usage: %s <embed/extract> <input_file> <output_file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *action = argv[1];
    const char *input_file = argv[2];
    const char *output_file = argv[3];

    if (strcmp(action, "embed") == 0) {
        embed_watermark(input_file, output_file, WATERMARK);
    } else if (strcmp(action, "extract") == 0) {
        extract_watermark(input_file);
    } else {
        printf("Invalid action. Use 'embed' or 'extract'.\n");
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}