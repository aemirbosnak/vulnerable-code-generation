//Falcon-180B DATASET v1.0 Category: Checksum Calculator ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1024
#define CHECKSUM_VALUE 0xDEADBEEF

int get_checksum(char* data, int size) {
    int checksum = 0;
    for (int i = 0; i < size; i++) {
        checksum += data[i];
    }
    return checksum % CHECKSUM_VALUE;
}

void print_checksum(int checksum) {
    printf("Checksum: %X\n", checksum);
}

int main() {
    char input_file[MAX_SIZE];
    printf("Enter input file name: ");
    scanf("%s", input_file);

    FILE* input_fp = fopen(input_file, "rb");
    if (input_fp == NULL) {
        printf("Error: could not open input file.\n");
        return 1;
    }

    int file_size = 0;
    fseek(input_fp, 0, SEEK_END);
    file_size = ftell(input_fp);
    fseek(input_fp, 0, SEEK_SET);

    char* file_data = malloc(file_size);
    if (file_data == NULL) {
        printf("Error: could not allocate memory for file data.\n");
        return 2;
    }

    int bytes_read = fread(file_data, 1, file_size, input_fp);
    if (bytes_read!= file_size) {
        printf("Error: could not read entire input file.\n");
        return 3;
    }

    int checksum = get_checksum(file_data, file_size);
    print_checksum(checksum);

    free(file_data);
    fclose(input_fp);

    return 0;
}