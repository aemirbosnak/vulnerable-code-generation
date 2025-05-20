//FormAI DATASET v1.0 Category: File Encyptor ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Function to perform file encryption */
void encrypt_file(char *filename, char *key) {
    FILE *fp = fopen(filename, "r+");
    int ch, i = 0;
    int key_length = strlen(key);
    /* Loop through file char by char */
    while ((ch = fgetc(fp)) != EOF) {
        ch = ch ^ key[i % key_length];
        /* Write back the encrypted char to file*/
        fseek(fp, -1, SEEK_CUR);
        fputc(ch, fp);
        i++;
    }
    fclose(fp);
    printf("File encryption successful!\n");
}

/* Function to perform file decryption */
void decrypt_file(char *filename, char *key) {
    FILE *fp = fopen(filename, "r+");
    int ch, i = 0;
    int key_length = strlen(key);
    /* Loop through file char by char */
    while ((ch = fgetc(fp)) != EOF) {
        ch = ch ^ key[i % key_length];
        /* Write back the decrypted char to file */
        fseek(fp, -1, SEEK_CUR);
        fputc(ch, fp);
        i++;
    }
    fclose(fp);
    printf("File decryption successful!\n");
}

int main() {
    char filename[100];
    char option;
    char key[100];
    printf("Enter the filename to encrypt or decrypt:\n");
    scanf("%s", filename);
    printf("Enter the encryption/decryption key:\n");
    scanf("%s", key);
    printf("Do you want to encrypt or decrypt?(E/D)\n");
    scanf(" %c", &option);
    switch(option) {
        case 'E':
            encrypt_file(filename, key);
            break;
        case 'D':
            decrypt_file(filename, key);
            break;
        default:
            printf("Invalid option selected!\n");
            break;
    }
    return 0;
}