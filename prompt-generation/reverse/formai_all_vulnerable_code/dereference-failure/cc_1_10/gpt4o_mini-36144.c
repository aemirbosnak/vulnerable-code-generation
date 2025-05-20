//GPT-4o-mini DATASET v1.0 Category: Digital Watermarking ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WATERMARK "WATERMARK"
#define BUFFER_SIZE 1024

// Function to embed watermark in a data file
void embed_watermark(const char *input_file, const char *output_file) {
    FILE *in_file = fopen(input_file, "r");
    FILE *out_file = fopen(output_file, "w");

    if (!in_file || !out_file) {
        fprintf(stderr, "Error opening file.\n");
        exit(EXIT_FAILURE);
    }

    char buffer[BUFFER_SIZE];
    while (fgets(buffer, BUFFER_SIZE, in_file)) {
        // Embed watermark at the end of the file
        fprintf(out_file, "%s", buffer);
    }
    
    // Append the watermark
    fprintf(out_file, "\n%s\n", WATERMARK);

    fclose(in_file);
    fclose(out_file);
}

// Function to retrieve watermark from a data file
int retrieve_watermark(const char *file_name) {
    FILE *file = fopen(file_name, "r");

    if (!file) {
        fprintf(stderr, "Error opening file.\n");
        exit(EXIT_FAILURE);
    }

    char buffer[BUFFER_SIZE];
    int found = 0;

    while (fgets(buffer, BUFFER_SIZE, file)) {
        if (strstr(buffer, WATERMARK)) {
            found = 1;
            break;
        }
    }

    fclose(file);
    return found;
}

// Simulate a distributed system with multiple workers
void distributed_watermarking(const char *input_file, const char *output_file) {
    printf("Worker Process: Embedding watermark...\n");
    embed_watermark(input_file, output_file);

    printf("Worker Process: Retrieving watermark...\n");
    int ret_val = retrieve_watermark(output_file);
    
    if (ret_val) {
        printf("Watermark found in the output file: %s\n", output_file);
    } else {
        printf("Watermark NOT found in the output file: %s\n", output_file);
    }
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <input_file> <output_file>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    const char *input_file = argv[1];
    const char *output_file = argv[2];

    distributed_watermarking(input_file, output_file);

    return 0;
}