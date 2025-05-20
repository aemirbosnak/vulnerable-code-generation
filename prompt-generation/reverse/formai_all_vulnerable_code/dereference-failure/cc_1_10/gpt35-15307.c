//FormAI DATASET v1.0 Category: File Encyptor ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_LENGTH 100
#define ENCRYPTION_KEY 31

void encryptFile(char* filename);
void decryptFile(char* filename);

int main(int argc, char* argv[]) {
    char filename[MAX_FILENAME_LENGTH];

    printf("Enter filename: ");
    scanf("%s", filename);

    encryptFile(filename);
    printf("File encrypted successfully!\n");

    decryptFile(filename);
    printf("File decrypted successfully!\n");

    return 0;
}

void encryptFile(char* filename) {
    FILE* file = fopen(filename, "rb+");
    if (file == NULL) {
        printf("Error opening file!");
        exit(1);
    }

    fseek(file, 0, SEEK_END);
    long int fileSize = ftell(file);
    fseek(file, 0, SEEK_SET);

    char* buffer = (char*) malloc(fileSize * sizeof(char));
    fread(buffer, fileSize, 1, file);

    for (int i = 0; i < fileSize; i++) {
        buffer[i] = buffer[i] ^ ENCRYPTION_KEY;
    }

    fseek(file, 0, SEEK_SET);
    fwrite(buffer, fileSize, 1, file);

    free(buffer);
    fclose(file);
}

void decryptFile(char* filename) {
    encryptFile(filename);
}