//FormAI DATASET v1.0 Category: File Encyptor ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define KEY "mysecretkey"

void encryptFile(char *fileName) {
    FILE *file;
    file = fopen(fileName, "r+");
    if (file == NULL) {
        printf("Error: Unable to open file!\n");
        exit(1);
    }

    char ch, temp;
    int i = 0, j = 0, keyLength = strlen(KEY);
    fseek(file, 0, SEEK_END);
    int fileSize = ftell(file);
    fseek(file, 0, SEEK_SET);

    while (i < fileSize) {
        ch = fgetc(file);
        temp = ch ^ KEY[j];
        fseek(file, i, SEEK_SET);
        fputc(temp, file);
        fseek(file, 0, SEEK_CUR);
        i++;
        j++;
        if (j == keyLength) {
            j = 0;
        }
    }

    fclose(file);
}

void decryptFile(char *fileName) {
    FILE *file;
    file = fopen(fileName, "r+");
    if (file == NULL) {
        printf("Error: Unable to open file!\n");
        exit(1);
    }

    char ch, temp;
    int i = 0, j = 0, keyLength = strlen(KEY);
    fseek(file, 0, SEEK_END);
    int fileSize = ftell(file);
    fseek(file, 0, SEEK_SET);

    while (i < fileSize) {
        ch = fgetc(file);
        temp = ch ^ KEY[j];
        fseek(file, i, SEEK_SET);
        fputc(temp, file);
        fseek(file, 0, SEEK_CUR);
        i++;
        j++;
        if (j == keyLength) {
            j = 0;
        }
    }

    fclose(file);
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: fileEncryptor <option> <file>\n");
        printf("<option>: 1 - Encrypt File; 2 - Decrypt File;\n");
        exit(1);
    }

    int option = atoi(argv[1]);

    if (option == 1) {
        encryptFile(argv[2]);
        printf("File %s encrypted successfully!\n", argv[2]);
    } else if (option == 2) {
        decryptFile(argv[2]);
        printf("File %s decrypted successfully!\n", argv[2]);
    } else {
        printf("Invalid Option!\n");
        printf("Usage: fileEncryptor <option> <file>\n");
        printf("<option>: 1 - Encrypt File; 2 - Decrypt File;\n");
        exit(1);
    }

    return 0;
}