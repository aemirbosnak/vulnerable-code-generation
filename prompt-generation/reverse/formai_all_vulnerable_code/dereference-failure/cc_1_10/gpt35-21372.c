//FormAI DATASET v1.0 Category: File Encyptor ; Style: standalone
#include <stdio.h>
#include <stdlib.h>

void encryptFile(char* fileName) {
    FILE* file = fopen(fileName, "r+");
    if (file == NULL) {
        printf("Unable to open file\n");
        return;
    }
    char c;
    while ((c = fgetc(file)) != EOF) {
        if (c != '\n' && c != ' ' && c != '\t') {
            // encrypt character
            fputc(++c, file);
        } else {
            // do not encrypt space, tab or newline characters
            fputc(c, file);
        }
    }
    fclose(file);
}

void decryptFile(char* fileName) {
    FILE* file = fopen(fileName, "r+");
    if (file == NULL) {
        printf("Unable to open file\n");
        return;
    }
    char c;
    while ((c = fgetc(file)) != EOF) {
        if (c != '\n' && c != ' ' && c != '\t') {
            // decrypt character
            fputc(--c, file);
        } else {
            // do not decrypt space, tab or newline characters
            fputc(c, file);
        }
    }
    fclose(file);
}

int main(int argc, char** argv) {
    if (argc != 3) {
        printf("Usage: %s <encrypt/decrypt> <filename>\n", argv[0]);
        return 1;
    }

    char* fileName = argv[2];
    if (strcmp(argv[1], "encrypt") == 0) {
        encryptFile(fileName);
        printf("File encrypted successfully\n");
    } else if (strcmp(argv[1], "decrypt") == 0) {
        decryptFile(fileName);
        printf("File decrypted successfully\n");
    } else {
        printf("Invalid command\n");
        return 1;
    }
    return 0;
}