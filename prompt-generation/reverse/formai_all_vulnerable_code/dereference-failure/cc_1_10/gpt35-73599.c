//FormAI DATASET v1.0 Category: QR code reader ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <stdint.h>

#define SUCCESS 0
#define FAILURE -1
#define MAX_CODE_SIZE 256

uint8_t qr_code[MAX_CODE_SIZE];
uint8_t code_size;

char *decode_qr_code(uint8_t* code, uint8_t size) {
    char *decoded_string = (char *) malloc(sizeof(char) * (size + 1));
    for(int i = 0; i < size; i++) {
        decoded_string[i] = (char) ('0' + code[i]);
    }
    decoded_string[size] = '\0';
    return decoded_string;
}

int read_qr_code(char* filename) {
    int fd = open(filename, O_RDONLY);
    if (fd == -1) {
        printf("Error opening file: %s\n", strerror(errno));
        return FAILURE;
    }
    int bytes_read = read(fd, qr_code, sizeof(qr_code));
    if (bytes_read == -1) {
        printf("Error reading from file: %s\n", strerror(errno));
        return FAILURE;
    }
    code_size = bytes_read;
    close(fd);
    return SUCCESS;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s filename\n", argv[0]);
        return FAILURE;
    }
    if (read_qr_code(argv[1]) == FAILURE) {
        return FAILURE;
    }
    char *decoded_code = decode_qr_code(qr_code, code_size);
    printf("Decoded QR code: %s\n", decoded_code);
    free(decoded_code);
    return SUCCESS;
}