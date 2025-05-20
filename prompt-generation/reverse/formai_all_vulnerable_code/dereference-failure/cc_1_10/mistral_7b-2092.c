//MISTRAL-7B DATASET v1.0 Category: Binary Converter ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdint.h>

void print_binary(uint8_t num) {
    for (int i = 7; i >= 0; --i)
        putchar(num & 1 ? '1' : '0');
    putchar('\n');
}

void binary_to_decimal(uint8_t binary[8]) {
    int decimal = 0;
    for (int i = 0; i < 8; ++i) {
        decimal += (binary[i] & 1) << (7 - i);
    }
    printf("Decimal: %d\n", decimal);
}

void decimal_to_binary(uint8_t decimal) {
    uint8_t binary[8];
    for (int i = 0; i < 8; ++i) {
        binary[i] = (decimal >> (7 - i)) & 1;
    }
    print_binary(binary[0]);
}

void convert_file(const char *filename) {
    int fd = open(filename, O_RDONLY);
    if (fd < 0) {
        perror("Error opening file");
        return;
    }

    struct stat file_info;
    fstat(fd, &file_info);

    uint8_t *buffer = (uint8_t *) malloc(file_info.st_size);
    if (!buffer) {
        perror("Error allocating memory");
        close(fd);
        return;
    }

    ssize_t bytes_read = read(fd, buffer, file_info.st_size);
    if (bytes_read != file_info.st_size) {
        perror("Error reading file");
        free(buffer);
        close(fd);
        return;
    }

    printf("Converted binary data from %s:\n", filename);
    for (int i = 0; i < file_info.st_size; i += sizeof(uint8_t)) {
        print_binary(buffer[i]);
    }

    printf("\nDecimal equivalent:\n");
    for (int i = 0; i < file_info.st_size; i += sizeof(uint8_t)) {
        binary_to_decimal((uint8_t *)&buffer[i]);
    }

    free(buffer);
    close(fd);
}

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    convert_file(argv[1]);

    return 0;
}