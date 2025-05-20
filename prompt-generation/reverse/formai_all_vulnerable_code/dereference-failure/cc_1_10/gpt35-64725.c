//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: medieval
#include <stdio.h>

// Function to create digital watermark
void createWatermark(char *input_file, char *watermark_file, char *output_file) {
    FILE *input_ptr, *mark_ptr, *output_ptr;
    input_ptr = fopen(input_file, "rb");
    mark_ptr = fopen(watermark_file, "rb");
    output_ptr = fopen(output_file, "wb");

    // Check if files are opened correctly 
    if (input_ptr == NULL || mark_ptr == NULL || output_ptr == NULL) {
        printf("Error opening files");
        exit(1); // Terminate the program
    }

    // Read input file and watermark file
    char input_data[10000], mark_data[10000];
    int input_size = fread(input_data, sizeof(char), sizeof(input_data), input_ptr);
    int mark_size = fread(mark_data, sizeof(char), sizeof(mark_data), mark_ptr);

    // Set watermark marker at 100th byte of input file
    int watermark_marker = 100; 

    // Embed the watermark in input file
    for (int i = watermark_marker; i < input_size && i - watermark_marker < mark_size; i++) {
        input_data[i] = mark_data[i - watermark_marker];
    }

    // Write the modified input file to output file 
    fwrite(input_data, sizeof(char), input_size, output_ptr);

    // Close all files
    fclose(input_ptr);
    fclose(mark_ptr);
    fclose(output_ptr);
}

// Function to verify the digital watermark
int verifyWatermark(char *output_file, char *watermark_file) {
    FILE *output_ptr, *mark_ptr;
    output_ptr = fopen(output_file, "rb");
    mark_ptr = fopen(watermark_file, "rb");

    // Check if files are opened correctly
    if (output_ptr == NULL || mark_ptr == NULL) {
        printf("Error opening files");
        exit(1); // Terminate the program
    }

    // Read output file and watermark file
    char output_data[10000], mark_data[10000];
    int output_size = fread(output_data, sizeof(char), sizeof(output_data), output_ptr);
    int mark_size = fread(mark_data, sizeof(char), sizeof(mark_data), mark_ptr);

    // Set watermark marker at 100th byte of output file
    int watermark_marker = 100; 

    // Check if watermark is present in output file
    int i;
    for (i = watermark_marker; i < output_size && i - watermark_marker < mark_size; i++) {
        if (output_data[i] != mark_data[i - watermark_marker]) {
            return 0; // Watermark not present
        }
    }
    if (i - watermark_marker == mark_size) {
        return 1; // Watermark present
    }

    // Close all files
    fclose(output_ptr);
    fclose(mark_ptr);
}

int main() {
    char *input_file = "input.txt";
    char *watermark_file = "watermark.txt";
    char *output_file = "output.txt";

    // Create digital watermark
    createWatermark(input_file, watermark_file, output_file);
    printf("Digital watermark created successfully!\n");

    // Verify digital watermark
    if (verifyWatermark(output_file, watermark_file)) {
        printf("Digital watermark verified successfully!\n");
    } else {
        printf("Digital watermark not present!\n");
    }

    return 0;
}