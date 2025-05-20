//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_LEN 256
#define MAX_WATERMARK_LEN 256
#define MAX_BUF_SIZE 1024

/**
 * Function to embed a digital watermark in a given file.
 */
void embedWatermark(char* filename, char* watermark) {
    // Open input file in binary mode.
    FILE* fptr = fopen(filename, "rb");
    if (fptr == NULL) {
        printf("Error: Could not open file %s", filename);
        return;
    }

    // Open output file in binary mode.
    char outfilename[MAX_FILENAME_LEN];
    sprintf(outfilename, "%s.watermarked", filename);
    FILE* outptr = fopen(outfilename, "wb");
    if (outptr == NULL) {
        printf("Error: Could not open file %s", outfilename);
        return;
    }

    // Copy the watermark into a buffer and write it to the output file.
    int watermark_len = strlen(watermark);
    fwrite(&watermark_len, sizeof(int), 1, outptr);
    fwrite(watermark, sizeof(char), watermark_len, outptr);

    // Embed the watermark in the input file and write to the output file.
    char buf[MAX_BUF_SIZE];
    while (!feof(fptr)) {
        int num_bytes = fread(&buf, sizeof(char), MAX_BUF_SIZE, fptr);
        fwrite(&buf, sizeof(char), num_bytes, outptr);
    }

    // Close the files.
    fclose(fptr);
    fclose(outptr);

    printf("Watermark embedded successfully!\n");
}

/**
 * Function to extract a digital watermark from a given file.
 */
void extractWatermark(char* filename) {
    // Open input file in binary mode.
    FILE* fptr = fopen(filename, "rb");
    if (fptr == NULL) {
        printf("Error: Could not open file %s", filename);
        return;
    }

    // Read the watermark length from the input file.
    int watermark_len;
    fread(&watermark_len, sizeof(int), 1, fptr);

    // Read the watermark from the input file.
    char watermark[MAX_WATERMARK_LEN];
    fread(&watermark, sizeof(char), watermark_len, fptr);

    // Print the extracted watermark.
    printf("Extracted watermark: %s\n", watermark);

    // Close the file.
    fclose(fptr);
}

/**
 * Entry point of the program.
 */
int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("Usage: %s <filename> [<watermark>]\n", argv[0]);
        return 0;
    }

    char* filename = argv[1];
    if (argc == 2) {
        // Extract the watermark from the file.
        extractWatermark(filename);
    } else {
        // Embed the watermark in the file.
        char* watermark = argv[2];
        embedWatermark(filename, watermark);
    }

    return 0;
}