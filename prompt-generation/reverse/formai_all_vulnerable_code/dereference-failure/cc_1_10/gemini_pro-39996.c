//GEMINI-pro DATASET v1.0 Category: File Encyptor ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// The Great Cipher Key - Encrypting the Secrets of Baker Street
const char *key = "ELEMENTARY";

// The Art of Obfuscation - Encodes the File Contents
void encode(FILE *fin, FILE *fout) {
    char ch;

    while ((ch = fgetc(fin)) != EOF) {
        int offset = ch % strlen(key);
        fputc((ch + key[offset]) % 128, fout);
    }
}

// The Deductive Decryption - Decodes the Encrypted File
void decode(FILE *fin, FILE *fout) {
    char ch;

    while ((ch = fgetc(fin)) != EOF) {
        int offset = ch % strlen(key);
        fputc((ch - key[offset] - strlen(key)) % 128, fout);
    }
}

// A Keen Eye for Details - Reveals the File Operation
void usage(char *prog) {
    printf("Usage:\n");
    printf("%s -e <input file> <output file> - Encrypt a file\n", prog);
    printf("%s -d <input file> <output file> - Decrypt a file\n", prog);
    exit(EXIT_FAILURE);
}

int main(int argc, char *argv[]) {
    if (argc < 5) usage(argv[0]);

    FILE *fin, *fout;

    if ((fin = fopen(argv[2], "rb")) == NULL) {
        printf("Elementary, my dear Watson. The input file \"%s\" is missing.\n", argv[2]);
        exit(EXIT_FAILURE);
    }

    if ((fout = fopen(argv[4], "wb")) == NULL) {
        printf("Come now, Watson. The output file \"%s\" is unreachable.\n", argv[4]);
        exit(EXIT_FAILURE);
    }

    if (!strcmp(argv[1], "-e")) encode(fin, fout);
    else if (!strcmp(argv[1], "-d")) decode(fin, fout);
    else usage(argv[0]);

    fclose(fin);
    fclose(fout);

    printf("Watson, it is done. The file \"%s\" has been %s.\n", argv[4], argv[1][1] == 'e' ? "encrypted" : "decrypted");
    return EXIT_SUCCESS;
}