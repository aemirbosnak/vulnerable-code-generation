//FormAI DATASET v1.0 Category: File Encyptor ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void encryptFile(char *filename);
int checkKey(char *key);

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <filename> <encryption key>\n", argv[0]);
        return 1;
    }
    
    char *filename = argv[1];
    char *key = argv[2];
    
    if (checkKey(key) == 0) {
        printf("Invalid key. Encryption key must be 8 characters long and contain only digits.\n");
        return 1;
    }
    
    encryptFile(filename);
    
    printf("Successfully encrypted file %s.\n", filename);
    
    return 0;
}

void encryptFile(char *filename) {
    FILE *file = fopen(filename, "r+");
    if (file == NULL) {
        printf("Error opening file: %s.", filename);
        return;
    }
    
    char c;
    int i = 0;
    while ((c = fgetc(file)) != EOF) {
        if (i == 8) {
            i = 0;
        }
        c = (char)((int)c + (int)(i + '0'));
        fseek(file, -1, SEEK_CUR);
        fputc(c, file);
        i++;
    }
    
    fclose(file);
}

int checkKey(char *key) {
    if (strlen(key) != 8) {
        return 0;
    }
    for (int i = 0; i < 8; i++) {
        if (key[i] < '0' || key[i] > '9') {
            return 0;
        }
    }
    return 1;
}