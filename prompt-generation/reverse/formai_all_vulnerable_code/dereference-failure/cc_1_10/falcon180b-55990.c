//Falcon-180B DATASET v1.0 Category: Digital Watermarking ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>
#include <stdbool.h>

#define WATERMARK_SIZE 100
#define WATERMARK_VALUE "My watermark"

int main(int argc, char *argv[]) {
    if(argc!= 4) {
        printf("Usage: %s <input_file> <output_file> <watermark_value>\n", argv[0]);
        return 1;
    }

    // Read input file
    FILE *input_file = fopen(argv[1], "rb");
    if(input_file == NULL) {
        printf("Error: Failed to open input file.\n");
        return 1;
    }

    // Read watermark value
    char watermark[strlen(argv[3])];
    strcpy(watermark, argv[3]);

    // Read input file into memory
    char *input_buffer = NULL;
    long input_size = 0;
    fseek(input_file, 0, SEEK_END);
    input_size = ftell(input_file);
    fseek(input_file, 0, SEEK_SET);
    input_buffer = malloc(input_size);
    if(input_buffer == NULL) {
        printf("Error: Failed to allocate memory.\n");
        fclose(input_file);
        return 1;
    }
    fread(input_buffer, input_size, 1, input_file);
    fclose(input_file);

    // Embed watermark in the input buffer
    char *output_buffer = malloc(input_size + strlen(watermark));
    if(output_buffer == NULL) {
        printf("Error: Failed to allocate memory.\n");
        free(input_buffer);
        return 1;
    }
    memcpy(output_buffer, input_buffer, input_size);
    memcpy(output_buffer + input_size, watermark, strlen(watermark));
    free(input_buffer);

    // Write output file
    FILE *output_file = fopen(argv[2], "wb");
    if(output_file == NULL) {
        printf("Error: Failed to open output file.\n");
        free(output_buffer);
        return 1;
    }
    fwrite(output_buffer, input_size + strlen(watermark), 1, output_file);
    fclose(output_file);

    // Free memory
    free(output_buffer);

    printf("Watermarking completed successfully.\n");

    return 0;
}