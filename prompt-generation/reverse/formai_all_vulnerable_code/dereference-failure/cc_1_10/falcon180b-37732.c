//Falcon-180B DATASET v1.0 Category: Checksum Calculator ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

int main() {
    char input_file[1024];
    char output_file[1024];
    char buffer[BUFFER_SIZE];
    FILE *input_fp, *output_fp;
    unsigned int checksum = 0;
    int bytes_read;

    // Get input file name from user
    printf("Enter input file name: ");
    scanf("%s", input_file);

    // Open input file
    input_fp = fopen(input_file, "rb");
    if (input_fp == NULL) {
        printf("Error: Could not open input file.\n");
        exit(1);
    }

    // Get output file name from user
    printf("Enter output file name: ");
    scanf("%s", output_file);

    // Open output file
    output_fp = fopen(output_file, "wb");
    if (output_fp == NULL) {
        printf("Error: Could not open output file.\n");
        exit(1);
    }

    // Calculate checksum
    while ((bytes_read = fread(buffer, 1, BUFFER_SIZE, input_fp)) > 0) {
        for (int i = 0; i < bytes_read; i++) {
            checksum += buffer[i];
        }
    }

    // Write checksum to output file
    fprintf(output_fp, "Checksum: %08X\n", checksum);

    // Close files
    fclose(input_fp);
    fclose(output_fp);

    return 0;
}