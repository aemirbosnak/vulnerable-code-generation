//Falcon-180B DATASET v1.0 Category: Checksum Calculator ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1024

void calculate_checksum(char *data, size_t size) {
    unsigned int checksum = 0;
    for (int i = 0; i < size; i++) {
        checksum += data[i];
    }
    printf("Checksum: %08X\n", checksum);
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: %s <filename> <size>\n", argv[0]);
        return 1;
    }

    char *filename = argv[1];
    size_t size = atoi(argv[2]);

    FILE *fp = fopen(filename, "rb");
    if (fp == NULL) {
        printf("Error: Could not open file.\n");
        return 1;
    }

    char *data = (char *)malloc(size);
    if (data == NULL) {
        printf("Error: Could not allocate memory.\n");
        fclose(fp);
        return 1;
    }

    size_t bytes_read = fread(data, 1, size, fp);
    if (bytes_read!= size) {
        printf("Error: Could not read file.\n");
        free(data);
        fclose(fp);
        return 1;
    }

    calculate_checksum(data, size);

    free(data);
    fclose(fp);

    return 0;
}