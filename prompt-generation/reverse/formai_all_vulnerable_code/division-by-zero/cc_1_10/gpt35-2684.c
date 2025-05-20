//FormAI DATASET v1.0 Category: File Encyptor ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void encrypt(char *filePath, char *key);
void decrypt(char *filePath, char *key);

int main() {
    char *filePath;
    char *key;
    int choice;

    printf("Enter file path: ");
    scanf("%s", filePath);

    printf("Enter a key: ");
    scanf("%s", key);

    printf("Select an option:\n");
    printf("1. Encrypt\n");
    printf("2. Decrypt\n");

    scanf("%d", &choice);

    if (choice == 1) {
        encrypt(filePath, key);
    } else {
        decrypt(filePath, key);
    }

    return 0;
}

void encrypt(char *filePath, char *key) {
    FILE *fp;
    fp = fopen(filePath, "r+");

    if (fp == NULL) {
        printf("Error opening file!");
        exit(1);
    }

    char ch;
    int keyLength = strlen(key);
    int i = 0;

    fseek(fp, 0L, SEEK_END);
    int fileSize = ftell(fp);

    fseek(fp, 0L, SEEK_SET);

    while (i < fileSize) {
        ch = fgetc(fp);
        ch = ch ^ key[i % keyLength];
        fseek(fp, -1L, SEEK_CUR);
        fputc(ch, fp);
        i++;
    }

    fclose(fp);
    printf("File encrypted successfully!\n");
}

void decrypt(char *filePath, char *key) {
    FILE *fp;
    fp = fopen(filePath, "r+");

    if (fp == NULL) {
        printf("Error opening file!");
        exit(1);
    }

    char ch;
    int keyLength = strlen(key);
    int i = 0;

    fseek(fp, 0L, SEEK_END);
    int fileSize = ftell(fp);

    fseek(fp, 0L, SEEK_SET);

    while (i < fileSize) {
        ch = fgetc(fp);
        ch = ch ^ key[i % keyLength];
        fseek(fp, -1L, SEEK_CUR);
        fputc(ch, fp);
        i++;
    }

    fclose(fp);
    printf("File decrypted successfully!\n");
}