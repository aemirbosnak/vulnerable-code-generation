//FormAI DATASET v1.0 Category: File Encyptor ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Encrypt function for encrypting the contents of the file */
void encrypt(char* path, char* key) {
    FILE *fp;
    fp = fopen(path, "rb");
    if (fp == NULL) {
        printf("Unable to open file.");
        return;
    }

    /* Get the length of the file */
    fseek(fp, 0, SEEK_END);
    int fileSize = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    /* Read the file contents into the buffer */
    char* buffer = (char*)malloc(fileSize + 1);
    if (buffer == NULL) {
        printf("Unable to allocate memory.");
        return;
    }
    fread(buffer, fileSize, 1, fp);
    buffer[fileSize] = '\0';

    /* Encrypt the contents of the buffer with the key */
    for (int i = 0, j = 0; i < fileSize; ++i, ++j) {
        if (j == strlen(key)) {
            j = 0;
        }
        buffer[i] ^= key[j];
    }

    /* Write the encrypted buffer back to the file */
    fclose(fp);
    fp = fopen(path, "wb");
    if (fp == NULL) {
        printf("Unable to open file.");
        return;
    }
    fwrite(buffer, fileSize, 1, fp);

    /* Close the file and free the buffer */
    fclose(fp);
    free(buffer);

    printf("Encryption successful!\n");
}

/* Decrypt function for decrypting the contents of the file */
void decrypt(char* path, char* key) {
    FILE *fp;
    fp = fopen(path, "rb");
    if (fp == NULL) {
        printf("Unable to open file.");
        return;
    }

    /* Get the length of the file */
    fseek(fp, 0, SEEK_END);
    int fileSize = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    /* Read the file contents into the buffer */
    char* buffer = (char*)malloc(fileSize + 1);
    if (buffer == NULL) {
        printf("Unable to allocate memory.");
        return;
    }
    fread(buffer, fileSize, 1, fp);
    buffer[fileSize] = '\0';

    /* Decrypt the contents of the buffer with the key */
    for (int i = 0, j = 0; i < fileSize; ++i, ++j) {
        if (j == strlen(key)) {
            j = 0;
        }
        buffer[i] ^= key[j];
    }

    /* Write the decrypted buffer back to the file */
    fclose(fp);
    fp = fopen(path, "wb");
    if (fp == NULL) {
        printf("Unable to open file.");
        return;
    }
    fwrite(buffer, fileSize, 1, fp);

    /* Close the file and free the buffer */
    fclose(fp);
    free(buffer);

    printf("Decryption successful!\n");
}

int main(int argc, char** argv) {
    char path[1000];
    char key[1000];

    /* Get the file path and key from the user */
    printf("Enter the path of the file: ");
    scanf("%s", path);
    printf("Enter the encryption/decryption key: ");
    scanf("%s", key);

    /* Prompt user for encryption or decryption */
    char choice;
    printf("Do you want to encrypt [E] or decrypt [D] the file: ");
    scanf(" %c", &choice);

    /* Call the appropriate function */
    if (choice == 'e' || choice == 'E') {
        encrypt(path, key);
    }
    else if (choice == 'd' || choice == 'D') {
        decrypt(path, key);
    }
    else {
        printf("Invalid option selected.");
    }

    return 0;
}