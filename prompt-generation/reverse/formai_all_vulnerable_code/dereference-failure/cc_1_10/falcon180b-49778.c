//Falcon-180B DATASET v1.0 Category: Checksum Calculator ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100000

int main() {
    char input_file[MAX_SIZE];
    char output_file[MAX_SIZE];
    FILE *fp_in, *fp_out;
    unsigned char buffer[MAX_SIZE];
    int file_size = 0;
    unsigned int checksum = 0;

    // Get input and output file names from user
    printf("Enter input file name: ");
    scanf("%s", input_file);
    printf("Enter output file name: ");
    scanf("%s", output_file);

    // Open input file
    fp_in = fopen(input_file, "rb");
    if (fp_in == NULL) {
        printf("Error: Could not open input file\n");
        exit(1);
    }

    // Read input file into buffer
    while (fread(buffer, 1, MAX_SIZE, fp_in) > 0) {
        file_size += fread(buffer, 1, MAX_SIZE, fp_in);
    }

    // Calculate checksum
    for (int i = 0; i < file_size; i++) {
        checksum += buffer[i];
    }

    // Open output file
    fp_out = fopen(output_file, "wb");
    if (fp_out == NULL) {
        printf("Error: Could not open output file\n");
        exit(1);
    }

    // Write checksum to output file
    fwrite(&checksum, 1, sizeof(checksum), fp_out);

    // Close input and output files
    fclose(fp_in);
    fclose(fp_out);

    printf("Checksum written to %s\n", output_file);

    return 0;
}