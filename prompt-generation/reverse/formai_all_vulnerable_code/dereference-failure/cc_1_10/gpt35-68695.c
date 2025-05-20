//FormAI DATASET v1.0 Category: File Encyptor ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILENAME_LENGTH 50
#define KEY_LENGTH 16

void encryptFile(char *filename, char *key);
void decryptFile(char *filename, char *key);

int main() {
    char filename[FILENAME_LENGTH];
    char key[KEY_LENGTH];

    printf("Enter the filename: ");
    fgets(filename, FILENAME_LENGTH, stdin);
    filename[strcspn(filename, "\n")] = 0; // Removing newline character from filename

    printf("Enter the key (16 characters only): ");
    fgets(key, KEY_LENGTH, stdin);
    key[strcspn(key, "\n")] = 0; // Removing newline character from key

    printf("Encrypting file...\n");
    encryptFile(filename, key);

    printf("Decrypting file...\n");
    decryptFile(filename, key);

    printf("File encrypted and decrypted successfully.\n");

    return 0;
}

void encryptFile(char *filename, char *key) {
    FILE *fp;
    fp = fopen(filename, "rb");

    if (fp == NULL) {
        printf("Unable to open file for encryption.");
        exit(1);
    }

    char outputFilename[FILENAME_LENGTH] = "encrypted_";
    strcat(outputFilename, filename);

    FILE *outputFP;
    outputFP = fopen(outputFilename, "wb");

    if (outputFP == NULL) {
        printf("Unable to open file for output.");
        exit(1);
    }

    char ch;
    int i = 0;
    while ((ch = fgetc(fp)) != EOF) {
        ch = ch ^ key[i % KEY_LENGTH];
        fwrite(&ch, sizeof(char), 1, outputFP);
        i++;
    }

    fclose(fp);
    fclose(outputFP);
}

void decryptFile(char *filename, char *key) {
    FILE *fp;
    char decryptedFilename[FILENAME_LENGTH] = "decrypted_";
    strcat(decryptedFilename, filename);

    fp = fopen(decryptedFilename, "wb");

    if (fp == NULL) {
        printf("Unable to open file for decryption.");
        exit(1);
    }

    char ch;
    int i = 0;
    while ((ch = fgetc(fopen(filename, "rb"))) != EOF) {
        ch = ch ^ key[i % KEY_LENGTH];
        fwrite(&ch, sizeof(char), 1, fp);
        i++;
    }

    fclose(fp);
}