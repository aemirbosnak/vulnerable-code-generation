//Falcon2-11B DATASET v1.0 Category: File Encyptor ; Style: artistic
#include <stdio.h>
#include <string.h>

// Function to encrypt the file
void encryptFile(const char* filename, const char* key) {
    FILE* f = fopen(filename, "rb");
    if (f == NULL) {
        printf("Error opening file\n");
        return;
    }

    char buffer[256];
    int bytesRead = fread(buffer, 1, sizeof(buffer), f);
    fclose(f);

    int keyLength = strlen(key);
    char encryptedKey[keyLength + 1];
    strcpy(encryptedKey, key);

    int i = 0;
    for (int j = 0; j < keyLength; j++) {
        encryptedKey[j] = (char)(((int)encryptedKey[j] + i) % 26);
        i = (i + 1) % 26;
    }

    encryptedKey[keyLength] = '\0';

    FILE* g = fopen(filename, "wb");
    if (g == NULL) {
        printf("Error opening file\n");
        return;
    }

    fseek(g, 0, SEEK_END);
    long fileSize = ftell(g);
    fseek(g, 0, SEEK_SET);

    char* encrypted = (char*)malloc(fileSize + 1);
    memset(encrypted, 0, fileSize + 1);

    fseek(f, 0, SEEK_SET);
    while (bytesRead > 0) {
        memcpy(encrypted + bytesRead, buffer, bytesRead);
        bytesRead = fread(buffer, 1, sizeof(buffer), f);
    }

    for (int j = 0; j < keyLength; j++) {
        encrypted[bytesRead] = encryptedKey[j];
        bytesRead++;
    }

    encrypted[fileSize] = '\0';
    fwrite(encrypted, 1, fileSize, g);
    free(encrypted);

    fclose(g);
}

int main() {
    char* filename = "test.txt";
    char* key = "secret";
    encryptFile(filename, key);
    printf("File encrypted successfully\n");
    return 0;
}