//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#define MARKER 0xCAFEBABE //The marker used to identify watermarked files

void print_header(uint8_t *header) {
    printf("Header: ");
    for (int i = 0; i < 16; i++) {
        printf("%02x ", header[i]);
    }
    printf("\n\n");
}

int main(int argc, char *argv[]) {
    // Check for proper usage
    if (argc != 3) {
        printf("Usage: %s infile outfile\n", argv[0]);
        return 1;
    }

    // Open input file
    FILE *infile = fopen(argv[1], "rb");
    if (!infile) {
        printf("Error: could not open %s\n", argv[1]);
        return 2;
    }

    // Read input file into memory
    fseek(infile, 0, SEEK_END);
    long fsize = ftell(infile);
    fseek(infile, 0, SEEK_SET);

    uint8_t *data = malloc(fsize + 16);
    fread(data, fsize, 1, infile);
    fclose(infile);

    // Set the marker in the header
    uint32_t marker = MARKER;
    memcpy(data, &marker, sizeof(marker));

    // Print the header for debugging purposes
    print_header(data);

    // Open output file
    FILE *outfile = fopen(argv[2], "wb");
    if (!outfile) {
        printf("Error: could not open %s\n", argv[2]);
        return 3;
    }

    // Write watermarked data to output file
    fwrite(data, fsize + 4, 1, outfile);
    fclose(outfile);

    // Free memory
    free(data);

    return 0;
}