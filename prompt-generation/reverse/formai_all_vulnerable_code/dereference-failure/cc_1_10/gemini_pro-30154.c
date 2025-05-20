//GEMINI-pro DATASET v1.0 Category: File Encyptor ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to encrypt a file
void encrypt(FILE *fin, FILE *fout, int key) {
    int ch;
    while ((ch = fgetc(fin)) != EOF) {
        fputc(ch ^ key, fout);
    }
}

// Function to decrypt a file
void decrypt(FILE *fin, FILE *fout, int key) {
    int ch;
    while ((ch = fgetc(fin)) != EOF) {
        fputc(ch ^ key, fout);
    }
}

int main(int argc, char *argv[]) {
    if (argc != 5) {
        fprintf(stderr, "Usage: %s encrypt|decrypt input_file output_file key\n", argv[0]);
        return 1;
    }

    FILE *fin, *fout;
    int key = atoi(argv[4]);

    if (strcmp(argv[1], "encrypt") == 0) {
        if ((fin = fopen(argv[2], "rb")) == NULL) {
            perror("Error opening input file");
            return 1;
        }
        if ((fout = fopen(argv[3], "wb")) == NULL) {
            perror("Error opening output file");
            return 1;
        }
        encrypt(fin, fout, key);
        fclose(fin);
        fclose(fout);
        printf("File encrypted successfully.\n");
    } else if (strcmp(argv[1], "decrypt") == 0) {
        if ((fin = fopen(argv[2], "rb")) == NULL) {
            perror("Error opening input file");
            return 1;
        }
        if ((fout = fopen(argv[3], "wb")) == NULL) {
            perror("Error opening output file");
            return 1;
        }
        decrypt(fin, fout, key);
        fclose(fin);
        fclose(fout);
        printf("File decrypted successfully.\n");
    } else {
        fprintf(stderr, "Invalid operation: %s\n", argv[1]);
        return 1;
    }

    return 0;
}