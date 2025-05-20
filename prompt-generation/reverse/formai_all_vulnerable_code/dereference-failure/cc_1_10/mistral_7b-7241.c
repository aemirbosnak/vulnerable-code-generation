//MISTRAL-7B DATASET v1.0 Category: File Encyptor ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define KEY 0xDEADBEEF

void die(const char *msg) {
    perror(msg);
    exit(1);
}

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        exit(1);
    }

    FILE *input = fopen(argv[1], "rb");
    if (!input) die("Could not open input file.");

    fseek(input, 0, SEEK_END);
    size_t size = ftell(input);
    rewind(input);

    char *buffer = malloc(size);
    if (!buffer) die("Could not allocate memory.");

    size_t bytes_read = fread(buffer, 1, size, input);
    if (bytes_read != size) die("Error reading file.");

    fclose(input);

    printf("Encrypting %s...\n", argv[1]);

    for (size_t i = 0; i < size; i++) {
        buffer[i] ^= KEY;
    }

    FILE *output = fopen(strcat(argv[1], ".enc"), "wb");
    if (!output) die("Could not open output file.");

    size_t bytes_written = fwrite(buffer, 1, size, output);
    if (bytes_written != size) die("Error writing to file.");

    fclose(output);

    free(buffer);

    printf("%s encrypted successfully!\n", argv[1]);

    return 0;
}