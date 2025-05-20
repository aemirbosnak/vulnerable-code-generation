//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: invasive
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<time.h>

#define KEY "mysecretkey"
#define KEY_SIZE 16
#define BUFFER_SIZE 10000

void encrypt(char* buffer, int size, char* key) {
    for(int i=0; i<size; i++) {
        if(isalpha(buffer[i])) {
            buffer[i] = toupper(buffer[i]) ^ key[i%KEY_SIZE];
        }
    }
}

void decrypt(char* buffer, int size, char* key) {
    for(int i=0; i<size; i++) {
        if(isalpha(buffer[i])) {
            buffer[i] = toupper(buffer[i]) ^ key[i%KEY_SIZE];
        }
    }
}

int main() {
    FILE* inputFile = fopen("input.txt", "rb+");
    if(inputFile == NULL) {
        printf("Error opening file\n");
        return 1;
    }

    fseek(inputFile, 0, SEEK_END);
    long fileSize = ftell(inputFile);
    rewind(inputFile);

    char* buffer = malloc(fileSize + 1);
    fread(buffer, fileSize, 1, inputFile);
    buffer[fileSize] = '\0';

    encrypt(buffer, strlen(buffer), KEY);

    fseek(inputFile, 0, SEEK_SET);
    fwrite(buffer, fileSize, 1, inputFile);

    free(buffer);
    fclose(inputFile);

    printf("File encrypted successfully!\n");

    return 0;
}