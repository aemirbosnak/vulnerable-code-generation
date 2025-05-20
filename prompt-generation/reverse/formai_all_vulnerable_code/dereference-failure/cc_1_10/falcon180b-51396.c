//Falcon-180B DATASET v1.0 Category: Checksum Calculator ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CHECKSUM_LENGTH 8

void calculate_checksum(char *data, size_t length, char *checksum) {
    int sum = 0;
    for (size_t i = 0; i < length; i++) {
        sum += (int)data[i];
    }
    sprintf(checksum, "%02X", sum & 0xFF);
}

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "rb");
    if (file == NULL) {
        printf("Error: Could not open file %s\n", argv[1]);
        return 1;
    }

    fseek(file, 0, SEEK_END);
    size_t file_size = ftell(file);
    fseek(file, 0, SEEK_SET);

    char *data = malloc(file_size + 1);
    if (data == NULL) {
        printf("Error: Could not allocate memory for file data\n");
        fclose(file);
        return 1;
    }

    size_t bytes_read = fread(data, 1, file_size, file);
    if (bytes_read!= file_size) {
        printf("Error: Could not read entire file\n");
        free(data);
        fclose(file);
        return 1;
    }

    data[file_size] = '\0';

    char checksum[CHECKSUM_LENGTH + 1] = { 0 };
    calculate_checksum(data, file_size, checksum);

    printf("File checksum: %s\n", checksum);

    free(data);
    fclose(file);

    return 0;
}