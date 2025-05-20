//MISTRAL-7B DATASET v1.0 Category: Arithmetic ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <ctype.h>

#define MAX_INPUT_SIZE 256
#define SECRET_KEY "mysecretkey123"
#define BUFFER_SIZE 128
#define OUTPUT_FILE "output.txt"

void encrypt_data(char *input_data, char *secret_key) {
    int i, j;
    char encrypted_data[MAX_INPUT_SIZE];

    for (i = 0; i < strlen(input_data); i++) {
        for (j = 0; j < strlen(secret_key); j++) {
            input_data[i] = input_data[i] ^ secret_key[j];
        }
    }
}

int main(int argc, char **argv) {
    char input_data[MAX_INPUT_SIZE];
    char secret_key[strlen(SECRET_KEY) + 1];
    char encrypted_data[MAX_INPUT_SIZE];
    int fd, rc;

    if (argc != 2) {
        printf("Usage: %s <data to encrypt>\n", argv[0]);
        return 1;
    }

    strcpy(input_data, argv[1]);
    strcpy(secret_key, SECRET_KEY);

    encrypt_data(input_data, secret_key);

    fd = open(OUTPUT_FILE, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);

    if (fd < 0) {
        perror("Error opening output file");
        return 1;
    }

    rc = write(fd, encrypted_data, strlen(encrypted_data));

    if (rc < 0) {
        perror("Error writing to output file");
        return 1;
    }

    close(fd);

    printf("Data encrypted and written to %s\n", OUTPUT_FILE);

    return 0;
}