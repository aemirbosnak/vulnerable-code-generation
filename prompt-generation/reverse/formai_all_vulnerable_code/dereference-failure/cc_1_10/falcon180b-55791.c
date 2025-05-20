//Falcon-180B DATASET v1.0 Category: Checksum Calculator ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_SIZE 1000000 // Maximum file size in bytes

unsigned char checksum(unsigned char *data, int size) {
    unsigned char sum = 0;
    for (int i = 0; i < size; i++) {
        sum += data[i];
    }
    return sum;
}

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        printf("Usage: %s <filename> <output_filename>\n", argv[0]);
        return 1;
    }

    FILE *input_file = fopen(argv[1], "rb");
    if (input_file == NULL) {
        printf("Error opening input file: %s\n", argv[1]);
        return 1;
    }

    FILE *output_file = fopen(argv[2], "wb");
    if (output_file == NULL) {
        printf("Error opening output file: %s\n", argv[2]);
        fclose(input_file);
        return 1;
    }

    char buffer[MAX_FILE_SIZE];
    int bytes_read = 0;
    while ((bytes_read = fread(buffer, 1, MAX_FILE_SIZE, input_file)) > 0) {
        unsigned char checksum_value = checksum(buffer, bytes_read);
        fwrite(&checksum_value, 1, 1, output_file);
    }

    if (ferror(input_file)) {
        printf("Error reading input file: %s\n", argv[1]);
        fclose(input_file);
        fclose(output_file);
        return 1;
    }

    if (fclose(input_file)!= 0 || fclose(output_file)!= 0) {
        printf("Error closing files\n");
        return 1;
    }

    printf("Checksum calculated and saved to %s\n", argv[2]);
    return 0;
}