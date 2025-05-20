//GEMINI-pro DATASET v1.0 Category: File Encyptor ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef unsigned char byte;

byte key[] = {'M', 'i', 's', 's', 'i', 'o', 'n', 'I', 's', 'F', 'u', 'n'};

void encrypt(byte* data, size_t len) {
    for (size_t i = 0; i < len; i++) {
        data[i] ^= key[i % sizeof(key)];
    }
}

int main(int argc, char** argv) {
    if (argc < 3) {
        fprintf(stderr, "Usage: %s file.txt output.txt\n", argv[0]);
        return 1;
    }

    FILE* input = fopen(argv[1], "rb");
    if (!input) {
        fprintf(stderr, "Error: could not open input file\n");
        return 1;
    }

    fseek(input, 0, SEEK_END);
    size_t size = ftell(input);
    rewind(input);

    byte* data = malloc(size);
    if (!data) {
        fprintf(stderr, "Error: could not allocate memory\n");
        return 1;
    }

    fread(data, 1, size, input);
    fclose(input);

    encrypt(data, size);

    FILE* output = fopen(argv[2], "wb");
    if (!output) {
        fprintf(stderr, "Error: could not open output file\n");
        return 1;
    }

    fwrite(data, 1, size, output);
    fclose(output);

    printf("File encrypted successfully!\n");
    return 0;
}