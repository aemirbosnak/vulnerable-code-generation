//Falcon2-11B DATASET v1.0 Category: File Encyptor ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_NAME_LENGTH 100

void encryptFile(const char *fileName, const char *key) {
    FILE *fp = fopen(fileName, "rb");
    if (fp == NULL) {
        printf("Error opening file %s\n", fileName);
        return;
    }

    int keySize = strlen(key);
    int bufferSize = 1024;
    char *buffer = malloc(bufferSize);
    if (buffer == NULL) {
        printf("Error allocating memory\n");
        return;
    }

    while (fread(buffer, 1, bufferSize, fp) > 0) {
        int i;
        for (i = 0; i < strlen(buffer); i++) {
            if (buffer[i] >= 'a' && buffer[i] <= 'z') {
                buffer[i] -= 'a' - 'A';
            } else if (buffer[i] >= 'A' && buffer[i] <= 'Z') {
                buffer[i] += 'A' - 'a';
            }
        }

        for (i = 0; i < strlen(buffer); i += keySize) {
            char *keyBuffer = key;
            while (keyBuffer[0]!= '\0') {
                if (strncmp(keyBuffer, buffer + i, keySize) == 0) {
                    memmove(buffer + i, buffer + i + keySize, strlen(buffer) - i);
                    break;
                }
                keyBuffer++;
            }
        }

        fwrite(buffer, 1, strlen(buffer), stdout);
    }

    fclose(fp);
    free(buffer);
}

int main() {
    char fileName[MAX_FILE_NAME_LENGTH];
    printf("Enter file name: ");
    fgets(fileName, sizeof(fileName), stdin);

    char key[MAX_FILE_NAME_LENGTH];
    printf("Enter encryption key: ");
    fgets(key, sizeof(key), stdin);

    encryptFile(fileName, key);

    printf("File encrypted successfully.\n");
    return 0;
}