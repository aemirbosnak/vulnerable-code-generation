//GPT-4o-mini DATASET v1.0 Category: File Encryptor ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SHIFT 3
#define MAX_FILENAME 100
#define BUFFER_SIZE 1024

void encryptText(const char *inputFile, const char *outputFile) {
    FILE *fin = fopen(inputFile, "r");
    FILE *fout = fopen(outputFile, "w");
    
    if (fin == NULL || fout == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    char buffer[BUFFER_SIZE];
    
    while (fgets(buffer, BUFFER_SIZE, fin) != NULL) {
        for (int i = 0; buffer[i] != '\0'; i++) {
            char c = buffer[i];
            if ('a' <= c && c <= 'z') {
                buffer[i] = (c - 'a' + SHIFT) % 26 + 'a';
            } else if ('A' <= c && c <= 'Z') {
                buffer[i] = (c - 'A' + SHIFT) % 26 + 'A';
            }
        }
        fprintf(fout, "%s", buffer);
    }

    fclose(fin);
    fclose(fout);
    printf("File encrypted successfully: %s\n", outputFile);
}

void decryptText(const char *inputFile, const char *outputFile) {
    FILE *fin = fopen(inputFile, "r");
    FILE *fout = fopen(outputFile, "w");

    if (fin == NULL || fout == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    char buffer[BUFFER_SIZE];
    
    while (fgets(buffer, BUFFER_SIZE, fin) != NULL) {
        for (int i = 0; buffer[i] != '\0'; i++) {
            char c = buffer[i];
            if ('a' <= c && c <= 'z') {
                buffer[i] = (c - 'a' - SHIFT + 26) % 26 + 'a';
            } else if ('A' <= c && c <= 'Z') {
                buffer[i] = (c - 'A' - SHIFT + 26) % 26 + 'A';
            }
        }
        fprintf(fout, "%s", buffer);
    }

    fclose(fin);
    fclose(fout);
    printf("File decrypted successfully: %s\n", outputFile);
}

int main(int argc, char *argv[]) {
    if (argc < 4) {
        fprintf(stderr, "Usage: %s <encrypt/decrypt> <inputfile> <outputfile>\n", argv[0]);
        return EXIT_FAILURE;
    }

    if (strcmp(argv[1], "encrypt") == 0) {
        encryptText(argv[2], argv[3]);
    } else if (strcmp(argv[1], "decrypt") == 0) {
        decryptText(argv[2], argv[3]);
    } else {
        fprintf(stderr, "Invalid operation. Use 'encrypt' or 'decrypt'.\n");
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}