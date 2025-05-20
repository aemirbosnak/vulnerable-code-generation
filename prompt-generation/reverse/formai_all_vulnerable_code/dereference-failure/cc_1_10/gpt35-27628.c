//FormAI DATASET v1.0 Category: File Encyptor ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define KEY 17

void encrypt(char *input_file, char *output_file);
void decrypt(char *input_file, char *output_file);

int main(int argc, char *argv[]) {
    if (argc != 4) {
        printf("Usage: %s [option] [input_file] [output_file]\n", argv[0]);
        printf("Options:\n");
        printf("\t-e : encrypt input_file and store as output_file\n");
        printf("\t-d : decrypt input_file and store as output_file\n");
        return -1;
    }

    if (strcmp(argv[1], "-e") == 0) {
        encrypt(argv[2], argv[3]);
    } else if (strcmp(argv[1], "-d") == 0) {
        decrypt(argv[2], argv[3]);
    } else {
        printf("Unknown option: %s. Use -e or -d.\n", argv[1]);
        return -1;
    }

    printf("Done.\n");

    return 0;
}

void encrypt(char *input_file, char *output_file) {
    FILE *ifp, *ofp;
    char *buffer;
    int i, size;

    ifp = fopen(input_file, "rb");
    if (ifp == NULL) {
        printf("Failed to open input file %s\n", input_file);
        exit(EXIT_FAILURE);
    }

    ofp = fopen(output_file, "wb");
    if (ofp == NULL) {
        printf("Failed to open output file %s\n", output_file);
        exit(EXIT_FAILURE);
    }

    fseek(ifp, 0, SEEK_END);
    size = ftell(ifp);
    rewind(ifp);

    buffer = (char *)malloc(sizeof(char) * size);
    if (buffer == NULL) {
        printf("Failed to allocate memory\n");
        exit(EXIT_FAILURE);
    }

    fread(buffer, 1, size, ifp);

    for (i = 0; i < size; i++) {
        buffer[i] ^= KEY;
    }

    fwrite(buffer, 1, size, ofp);

    fclose(ifp);
    fclose(ofp);
    free(buffer);
}

void decrypt(char *input_file, char *output_file) {
    encrypt(input_file, output_file); // encryption is the same as decryption
}