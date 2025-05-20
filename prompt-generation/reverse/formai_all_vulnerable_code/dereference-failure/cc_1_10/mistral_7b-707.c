//MISTRAL-7B DATASET v1.0 Category: Binary Converter ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#define BINARY_FILE "bin_num.bin"
#define MAX_SIZE 1024
#define BITS_PER_BYTE 8

typedef struct {
    char name[20];
    char binary[MAX_SIZE];
    int decimal;
} binary_data;

void print_usage(void) {
    printf("Usage: %s <binary_number>\n", __FILE__);
    exit(EXIT_FAILURE);
}

int atoi_binary(char *binary) {
    int decimal = 0;
    int power = 0;
    for (int i = strlen(binary) - 1; i >= 0; i--) {
        if (binary[i] < '0' || binary[i] > '1') {
            print_usage();
        }
        decimal += (binary[i] - '0') << power;
        power++;
    }
    return decimal;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        print_usage();
    }

    binary_data binary_num;
    strcpy(binary_num.name, argv[1]);
    strcpy(binary_num.binary, argv[1]);

    int binary_length = strlen(argv[1]);
    if (binary_length % BITS_PER_BYTE != 0) {
        int padding_size = BITS_PER_BYTE - (binary_length % BITS_PER_BYTE);
        binary_num.binary[binary_length] = '\0';
        memset(binary_num.binary + binary_length, '0', padding_size);
        binary_length += padding_size;
    }

    int fd = open(BINARY_FILE, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
    if (fd < 0) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    write(fd, binary_num.binary, binary_length);
    close(fd);

    binary_num.decimal = atoi_binary(binary_num.binary);
    printf("%s is %d in decimal.\n", binary_num.name, binary_num.decimal);

    return EXIT_SUCCESS;
}