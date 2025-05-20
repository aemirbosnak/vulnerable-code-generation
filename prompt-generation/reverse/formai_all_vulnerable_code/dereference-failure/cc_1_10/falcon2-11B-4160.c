//Falcon2-11B DATASET v1.0 Category: File Encyptor ; Style: realistic
#include <stdio.h>
#include <string.h>

// Encrypts the given string using a Caesar cipher
char* encrypt(char* str, int shift) {
    char* encrypted = (char*)malloc(strlen(str) * sizeof(char));
    int i;
    for (i = 0; i < strlen(str); i++) {
        if (str[i] >= 'a' && str[i] <= 'z') {
            encrypted[i] = (char)(str[i] + shift - 'a');
        } else if (str[i] >= 'A' && str[i] <= 'Z') {
            encrypted[i] = (char)(str[i] + shift - 'A');
        } else {
            encrypted[i] = str[i];
        }
    }
    encrypted[i] = '\0';
    return encrypted;
}

// Main function
int main() {
    char* fileName = "input.txt";
    char* encryptedFileName = "encrypted.txt";
    char* plainText = NULL;
    char* encryptedText = NULL;

    FILE* fp = fopen(fileName, "r");
    if (fp == NULL) {
        printf("Failed to open file.\n");
        return 1;
    }
    fseek(fp, 0, SEEK_END);
    long fileSize = ftell(fp);
    fseek(fp, 0, SEEK_SET);
    plainText = (char*)malloc(fileSize * sizeof(char));
    if (plainText == NULL) {
        printf("Failed to allocate memory for plain text.\n");
        fclose(fp);
        return 1;
    }
    fread(plainText, 1, fileSize, fp);
    fclose(fp);

    int shift = 3;
    encryptedText = encrypt(plainText, shift);

    FILE* fw = fopen(encryptedFileName, "w");
    if (fw == NULL) {
        printf("Failed to open file for writing.\n");
        free(plainText);
        free(encryptedText);
        return 1;
    }
    fwrite(encryptedText, 1, strlen(encryptedText), fw);
    fclose(fw);

    free(plainText);
    free(encryptedText);

    printf("Encryption complete.\n");
    return 0;
}