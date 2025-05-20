//Falcon-180B DATASET v1.0 Category: Checksum Calculator ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DATA_SIZE 1024 // Maximum data size in bytes

int checksum(char *data, int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += data[i];
    }
    return sum;
}

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        printf("Usage: %s <data file> <output checksum file>\n", argv[0]);
        exit(1);
    }

    FILE *data_file = fopen(argv[1], "rb");
    if (data_file == NULL) {
        printf("Error opening data file: %s\n", argv[1]);
        exit(1);
    }

    char *data = malloc(MAX_DATA_SIZE);
    if (data == NULL) {
        printf("Error allocating memory for data\n");
        exit(1);
    }

    int data_size = fread(data, 1, MAX_DATA_SIZE, data_file);
    if (ferror(data_file)) {
        printf("Error reading data from file: %s\n", argv[1]);
        exit(1);
    }

    int checksum_value = checksum(data, data_size);

    FILE *output_file = fopen(argv[2], "wb");
    if (output_file == NULL) {
        printf("Error opening output file: %s\n", argv[2]);
        exit(1);
    }

    fprintf(output_file, "%d\n", checksum_value);

    fclose(data_file);
    fclose(output_file);

    free(data);

    return 0;
}