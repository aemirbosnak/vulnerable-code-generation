//FormAI DATASET v1.0 Category: File Encyptor ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define KEY 0x1A

void encrypt(char* data, size_t len) {
    char* end = data + len;
    while (data < end) {
        *data ^= KEY;
        data++;
    }
}

void decrypt(char* data, size_t len) {
    encrypt(data, len);
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        exit(1);
    }

    char* filename = argv[1];
    FILE* file = fopen(filename, "rb");
    if (!file) {
        printf("Error opening file: %s\n", filename);
        exit(1);
    }

    // Get file size
    fseek(file, 0, SEEK_END);
    long fsize = ftell(file);
    fseek(file, 0, SEEK_SET);

    // Read file into memory
    char* buffer = (char*)malloc(fsize + 1);
    fread(buffer, fsize, 1, file);
    fclose(file);
    buffer[fsize] = '\0';

    // Encrypt buffer
    encrypt(buffer, fsize);

    // Write encrypted buffer back to file
    file = fopen(filename, "wb");
    fwrite(buffer, fsize, 1, file);
    fclose(file);

    free(buffer);
    return 0;
}