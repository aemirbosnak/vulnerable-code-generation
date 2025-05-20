//FormAI DATASET v1.0 Category: File Encyptor ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void encrypt(char *path, char *key) {

    FILE *fp = fopen(path, "r+");
    if (fp == NULL) {
        printf("\n Error: Could not open file.\n");
        return;
    }

    char buffer[512];
    int i = 0;
    char ch;

    while((ch = fgetc(fp)) != EOF) {
        buffer[i++] = ch;
    }
    buffer[i] = '\0';

    char encrypted[512];
    strcpy(encrypted, buffer);

    for (int j = 0; j < strlen(buffer); j++) {
        encrypted[j] ^= key[j % strlen(key)];
    }
    fseek(fp, 0, SEEK_SET);
    fwrite(encrypted, sizeof(char), strlen(encrypted), fp);
    fclose(fp);
}

void decrypt(char *path, char *key) {
    
    FILE *fp = fopen(path, "r");
    if (fp == NULL) {
        printf("\n Error: Could not open file.\n");
        return;
    }

    char buffer[512];
    int i = 0;
    char ch;

    while((ch = fgetc(fp)) != EOF) {
        buffer[i++] = ch;
    }
    buffer[i] = '\0';

    char decrypted[512];
    strcpy(decrypted, buffer);

    for (int j = 0; j < strlen(buffer); j++) {
        decrypted[j] ^= key[j % strlen(key)];
    }
    printf("\nDecrypted data: %s\n", decrypted);

    fclose(fp);
}

int main(int argc, char *argv[]) {
    printf("C File Encryptor\n");

    if (argc == 4) {
        if (strcmp(argv[1], "-e") == 0) {
            encrypt(argv[2], argv[3]);
            printf("\nFile %s encrypted with key %s successfully.\n", argv[2], argv[3]);
        }
        else if (strcmp(argv[1], "-d") == 0) {
            decrypt(argv[2], argv[3]);
        }
        else {
            printf("\nError: Invalid argument\n");
        }
    }
    else {
        printf("\nUsage: fileencryptor -e [inputfile] [key] to encrypt a file or\n");
        printf("\tfileencryptor -d [inputfile] [key] to decrypt the file\n");
    }

    return 0;
}