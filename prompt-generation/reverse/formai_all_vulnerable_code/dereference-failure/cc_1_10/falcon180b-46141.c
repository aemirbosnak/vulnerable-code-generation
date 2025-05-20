//Falcon-180B DATASET v1.0 Category: Checksum Calculator ; Style: single-threaded
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define CHECKSUM_LENGTH 16
#define CHUNK_SIZE 512

void generate_checksum(char* data, int data_length, char* checksum) {
    unsigned long long checksum_value = 0;
    int i;

    for (i = 0; i < data_length; i++) {
        checksum_value += data[i];
    }

    sprintf(checksum, "%016llX", checksum_value);
}

int main() {
    FILE* file;
    char* file_data = NULL;
    long file_size;
    char checksum[CHECKSUM_LENGTH];

    // Open the file
    file = fopen("example.txt", "rb");
    if (file == NULL) {
        printf("Error opening file\n");
        exit(1);
    }

    // Get the size of the file
    fseek(file, 0, SEEK_END);
    file_size = ftell(file);
    rewind(file);

    // Read the entire file into memory
    file_data = malloc(file_size);
    if (file_data == NULL) {
        printf("Error allocating memory\n");
        exit(1);
    }

    fread(file_data, file_size, 1, file);

    // Generate the checksum
    generate_checksum(file_data, file_size, checksum);

    // Print the checksum
    printf("Checksum: %s\n", checksum);

    // Free memory and close the file
    free(file_data);
    fclose(file);

    return 0;
}