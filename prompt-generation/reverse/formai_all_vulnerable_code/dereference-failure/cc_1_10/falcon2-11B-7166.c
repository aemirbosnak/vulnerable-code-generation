//Falcon2-11B DATASET v1.0 Category: File Encyptor ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define KEY_SIZE 16

char *encrypt(const char *input, const char *key) {
    int i;
    char *output = (char*) malloc(strlen(input) + 1);

    for (i = 0; i < strlen(input); i++) {
        output[i] = input[i] ^ key[i % KEY_SIZE];
    }

    return output;
}

char *decrypt(const char *input, const char *key) {
    int i;
    char *output = (char*) malloc(strlen(input) + 1);

    for (i = 0; i < strlen(input); i++) {
        output[i] = input[i] ^ key[i % KEY_SIZE];
    }

    return output;
}

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        fprintf(stderr, "Usage: %s <input_file> <output_file>\n", argv[0]);
        return 1;
    }

    char *input_file = argv[1];
    char *output_file = argv[2];

    FILE *in = fopen(input_file, "rb");
    FILE *out = fopen(output_file, "wb");
    if (!in ||!out) {
        fprintf(stderr, "Could not open input or output file.\n");
        return 1;
    }

    int c;
    while ((c = fgetc(in))!= EOF) {
        fputc(c, out);
    }

    fclose(in);
    fclose(out);

    return 0;
}