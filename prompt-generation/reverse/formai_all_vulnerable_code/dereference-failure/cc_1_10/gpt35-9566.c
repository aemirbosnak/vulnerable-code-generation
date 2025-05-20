//FormAI DATASET v1.0 Category: File Encyptor ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define KEY 0x42 //The encryption key

void encrypt_file(char* filename);
void decrypt_file(char* filename);

int main(int argc, char** argv) {
    if (argc != 3) {
        printf("Usage: %s <file_name> <operation: e/d>\n", argv[0]);
        exit(1);
    }
    if (strcmp(argv[2], "e") == 0) {
        encrypt_file(argv[1]);
        printf("File encrypted successfully.\n");
    } else if (strcmp(argv[2], "d") == 0) {
        decrypt_file(argv[1]);
        printf("File decrypted successfully.\n");
    } else {
        printf("Invalid operation.\n");
        exit(1);
    }
    return 0;
}

void encrypt_file(char* filename) {
    char new_filename[256];
    strcpy(new_filename, filename);
    strcat(new_filename, ".enc");
    FILE *fp = fopen(filename, "rb");
    if (!fp) {
        printf("File not found.\n");
        exit(1);
    }
    FILE *fp_enc = fopen(new_filename, "wb");
    if (!fp_enc) {
        printf("Error creating encrypted file.\n");
        exit(1);
    }
    int ch;
    while ((ch = fgetc(fp)) != EOF) {
        fputc(ch ^ KEY, fp_enc);
    }
    fclose(fp);
    fclose(fp_enc);
    remove(filename);
}

void decrypt_file(char* filename) {
    char new_filename[256];
    strcpy(new_filename, filename);
    strcat(new_filename, ".dec");
    FILE *fp = fopen(filename, "rb");
    if (!fp) {
        printf("File not found.\n");
        exit(1);
    }
    FILE *fp_dec = fopen(new_filename, "wb");
    if (!fp_dec) {
        printf("Error creating decrypted file.\n");
        exit(1);
    }
    int ch;
    while ((ch = fgetc(fp)) != EOF) {
        fputc(ch ^ KEY, fp_dec);
    }
    fclose(fp);
    fclose(fp_dec);
    remove(filename);
}