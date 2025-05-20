//FormAI DATASET v1.0 Category: File Encyptor ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define KEY "secret_key"

void encrypt(FILE* in, FILE* out, const char* key) {
    size_t key_len = strlen(key);
    size_t i;
    char buffer[1024];
    size_t read_len;

    while ((read_len = fread(buffer, 1, sizeof(buffer), in)) != 0) {
        for (i = 0; i < read_len; ++i) {
            buffer[i] ^= key[i % key_len];
        }
        fwrite(buffer, 1, read_len, out);
    }
}

int main(int argc, char* argv[]) {
    FILE* in;
    FILE* out;
    const char* key = KEY;

    if (argc < 3) {
        fprintf(stderr, "Usage: %s <input_file> <output_file> [<key>]\n", argv[0]);
        return 1;
    }

    if (argc > 3) {
        key = argv[3];
    }

    in = fopen(argv[1], "rb");
    if (!in) {
        fprintf(stderr, "Failed to open input file %s\n", argv[1]);
        return 1;
    }

    out = fopen(argv[2], "wb");
    if (!out) {
        fprintf(stderr, "Failed to create output file %s\n", argv[2]);
        fclose(in);
        return 1;
    }

    encrypt(in, out, key);

    fclose(out);
    fclose(in);

    printf("Encryption completed successfully\n");

    return 0;
}