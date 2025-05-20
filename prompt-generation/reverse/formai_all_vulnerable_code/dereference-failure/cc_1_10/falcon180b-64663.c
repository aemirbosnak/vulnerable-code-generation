//Falcon-180B DATASET v1.0 Category: Checksum Calculator ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1024

// Function to calculate checksum
unsigned char calculate_checksum(unsigned char *data, int size) {
    unsigned char checksum = 0;
    for (int i = 0; i < size; i++) {
        checksum += data[i];
    }
    return checksum;
}

// Function to read data from file
unsigned char *read_data_from_file(char *filename, int *size) {
    FILE *fp = fopen(filename, "rb");
    if (fp == NULL) {
        printf("Error opening file %s\n", filename);
        exit(1);
    }
    fseek(fp, 0, SEEK_END);
    *size = ftell(fp);
    rewind(fp);
    unsigned char *data = malloc(*size);
    if (data == NULL) {
        printf("Error allocating memory\n");
        exit(1);
    }
    if (fread(data, 1, *size, fp)!= *size) {
        printf("Error reading file\n");
        exit(1);
    }
    fclose(fp);
    return data;
}

// Function to write data to file
void write_data_to_file(char *filename, unsigned char *data, int size) {
    FILE *fp = fopen(filename, "wb");
    if (fp == NULL) {
        printf("Error opening file %s\n", filename);
        exit(1);
    }
    if (fwrite(data, 1, size, fp)!= size) {
        printf("Error writing file\n");
        exit(1);
    }
    fclose(fp);
}

// Function to print checksum as hexadecimal
void print_checksum(unsigned char checksum) {
    printf("Checksum: %02X\n", checksum);
}

// Main function
int main(int argc, char *argv[]) {
    if (argc!= 4) {
        printf("Usage: %s <file> <output_file> <size>\n", argv[0]);
        exit(1);
    }
    char *filename = argv[1];
    char *output_filename = argv[2];
    int size = atoi(argv[3]);

    unsigned char *data = read_data_from_file(filename, &size);
    if (size > MAX_SIZE) {
        printf("File size exceeds maximum limit of %d bytes\n", MAX_SIZE);
        exit(1);
    }

    unsigned char checksum = calculate_checksum(data, size);

    write_data_to_file(output_filename, data, size);

    print_checksum(checksum);

    return 0;
}