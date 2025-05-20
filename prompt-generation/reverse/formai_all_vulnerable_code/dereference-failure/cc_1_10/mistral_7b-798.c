//MISTRAL-7B DATASET v1.0 Category: Data recovery tool ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILE_NAME "recover.bin"
#define BUFFER_SIZE 10
#define BYTES_PER_LINE 11

typedef struct {
    int checksum;
    char data[BUFFER_SIZE];
} row_t;

int checksum(const char *data, size_t size) {
    int sum = 0;
    for (size_t i = 0; i < size; ++i) {
        sum += *(const unsigned char *)data++;
    }
    return sum;
}

void data_recovery(void) {
    FILE *file = fopen(FILE_NAME, "rb");

    if (!file) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    row_t buffer[BUFFER_SIZE];

    if (fread(buffer, sizeof(row_t), BUFFER_SIZE, file) != BUFFER_SIZE) {
        perror("Error reading file");
        exit(EXIT_FAILURE);
    }

    for (size_t i = 0; i < BUFFER_SIZE; ++i) {
        if (buffer[i].checksum != checksum(buffer[i].data, sizeof(buffer[i].data))) {
            fprintf(stderr, "Invalid checksum for row %zu\n", i);
            exit(EXIT_FAILURE);
        }
    }

    printf("Recovered data:\n");
    for (size_t i = 0; i < BUFFER_SIZE; ++i) {
        printf("Row %zu: ", i);
        for (size_t j = 0; j < sizeof(buffer[i].data) / BYTES_PER_LINE; ++j) {
            size_t pos = j * BYTES_PER_LINE;
            printf("%c", buffer[i].data[pos]);
            if (pos % BYTES_PER_LINE == BYTES_PER_LINE - 1) {
                printf(" ");
            }
        }
        printf("\n");
    }

    fclose(file);
}

int main(void) {
    data_recovery();
    return EXIT_SUCCESS;
}