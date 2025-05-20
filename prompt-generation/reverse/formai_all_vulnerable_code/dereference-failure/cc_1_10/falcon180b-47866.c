//Falcon-180B DATASET v1.0 Category: Checksum Calculator ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1024

unsigned char checksum(unsigned char *data, int size) {
    unsigned char sum = 0;
    for (int i = 0; i < size; i++) {
        sum += data[i];
    }
    return sum;
}

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        printf("Usage: %s <input_file> <output_file>\n", argv[0]);
        return 1;
    }

    char input_file[MAX_SIZE];
    char output_file[MAX_SIZE];

    strcpy(input_file, argv[1]);
    strcpy(output_file, argv[2]);

    FILE *input = fopen(input_file, "rb");
    if (input == NULL) {
        printf("Error opening input file: %s\n", input_file);
        return 1;
    }

    FILE *output = fopen(output_file, "wb");
    if (output == NULL) {
        printf("Error opening output file: %s\n", output_file);
        fclose(input);
        return 1;
    }

    char buffer[MAX_SIZE];
    int bytes_read;

    while ((bytes_read = fread(buffer, 1, MAX_SIZE, input)) > 0) {
        unsigned char checksum_value = checksum(buffer, bytes_read);
        fprintf(output, "%c%c%c%c", 0x7E, 0x00, 0x00, checksum_value);
        fwrite(buffer, 1, bytes_read, output);
    }

    fclose(input);
    fclose(output);

    return 0;
}