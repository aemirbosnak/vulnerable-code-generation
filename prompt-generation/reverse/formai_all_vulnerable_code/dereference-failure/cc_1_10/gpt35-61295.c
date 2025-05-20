//FormAI DATASET v1.0 Category: File Encyptor ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define KEY 'H'

void encrypt(char *file_name);
void decrypt(char *file_name);

int main(int argc, char *argv[]) {
    char *file_name = argv[1];
    char *action = argv[2];

    if (argc != 3) {
        printf("Usage: %s filename [encrypt|decrypt]\n", argv[0]);
        exit(1);
    }

    if (strcmp(action, "encrypt") == 0) {
        encrypt(file_name);
        printf("File %s encrypted successfully.\n", file_name);
    } else if (strcmp(action, "decrypt") == 0) {
        decrypt(file_name);
        printf("File %s decrypted successfully.\n", file_name);
    } else {
        printf("Unknown action %s. Use 'encrypt' or 'decrypt'.\n", action);
        exit(2);
    }

    return 0;
}

void encrypt(char *file_name) {
    FILE *file = fopen(file_name, "r+b");
    if (file == NULL) {
        printf("Error opening file %s.\n", file_name);
        exit(3);
    }

    int ch;
    while ((ch = fgetc(file)) != EOF) {
        ch ^= KEY; // XOR encryption
        fseek(file, -1, SEEK_CUR);
        fputc(ch, file);
    }

    fclose(file);
}

void decrypt(char *file_name) {
    FILE *file = fopen(file_name, "r+b");
    if (file == NULL) {
        printf("Error opening file %s.\n", file_name);
        exit(3);
    }

    int ch;
    while ((ch = fgetc(file)) != EOF) {
        ch ^= KEY; // XOR decryption
        fseek(file, -1, SEEK_CUR);
        fputc(ch, file);
    }

    fclose(file);
}