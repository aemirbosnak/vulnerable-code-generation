//MISTRAL-7B DATASET v1.0 Category: Data recovery tool ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024 * 1024

unsigned int calculate_checksum(const unsigned char *data, size_t size) {
    unsigned int sum = 0;
    for (size_t i = 0; i < size; ++i) {
        sum += data[i];
    }
    return sum;
}

void read_file(const char *path, unsigned char *buffer) {
    FILE *file = fopen(path, "rb");
    if (!file) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    size_t size = fread(buffer, 1, BUFFER_SIZE, file);
    if (size != BUFFER_SIZE) {
        fprintf(stderr, "Failed to read entire file into buffer\n");
        exit(EXIT_FAILURE);
    }

    fclose(file);
}

void data_recovery(unsigned char *buffer, size_t size) {
    unsigned int checksum_orig = calculate_checksum(buffer, size);
    unsigned char *data = malloc(size - sizeof(unsigned int));

    if (!data) {
        fprintf(stderr, "Failed to allocate memory for recovered data\n");
        exit(EXIT_FAILURE);
    }

    memcpy(data, buffer, size - sizeof(unsigned int));

    unsigned int checksum_calc = calculate_checksum(data, size - sizeof(unsigned int));

    free(data);

    if (checksum_calc != checksum_orig) {
        fprintf(stderr, "Checksum error: Data is corrupted\n");
        exit(EXIT_FAILURE);
    }

    printf("Data is valid\n");
}

void print_recovered_data(const unsigned char *buffer, size_t size) {
    printf("Recovered data:\n");
    fwrite(buffer, 1, size, stdout);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <file_path>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    unsigned char buffer[BUFFER_SIZE];
    read_file(argv[1], buffer);
    data_recovery(buffer, BUFFER_SIZE);
    print_recovered_data(buffer, BUFFER_SIZE - sizeof(unsigned int));

    return EXIT_SUCCESS;
}