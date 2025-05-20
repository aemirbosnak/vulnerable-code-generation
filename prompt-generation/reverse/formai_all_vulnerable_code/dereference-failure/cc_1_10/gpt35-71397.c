//FormAI DATASET v1.0 Category: File handling ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 256

void encode(char* input, char* output);
void decode(char* input, char* output);

int main(int argc, char** argv) {
    if (argc != 4) {
        printf("Usage: %s [encode/decode] [input file] [output file]\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    FILE* in = fopen(argv[2], "r");
    if (in == NULL) {
        printf("Error: could not open input file '%s'\n", argv[2]);
        exit(EXIT_FAILURE);
    }

    FILE* out = fopen(argv[3], "w");
    if (out == NULL) {
        printf("Error: could not open output file '%s'\n", argv[3]);
        fclose(in);
        exit(EXIT_FAILURE);
    }

    char buffer[MAX_LEN];

    if (strcmp(argv[1], "encode") == 0) {
        while (fgets(buffer, MAX_LEN, in)) {
            encode(buffer, buffer);
            fputs(buffer, out);
        }
    } else if (strcmp(argv[1], "decode") == 0) {
        while (fgets(buffer, MAX_LEN, in)) {
            decode(buffer, buffer);
            fputs(buffer, out);
        }
    } else {
        printf("Error: invalid mode '%s'\n", argv[1]);
        fclose(in);
        fclose(out);
        exit(EXIT_FAILURE);
    }

    fclose(in);
    fclose(out);

    return EXIT_SUCCESS;
}

void encode(char* input, char* output) {
    int len = strlen(input);
    for (int i = 0; i < len; i++) {
        output[i] = input[i] ^ 0xFF;
    }
}

void decode(char* input, char* output) {
    encode(input, output);
}