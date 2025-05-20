//Falcon2-11B DATASET v1.0 Category: File Encyptor ; Style: decentralized
#include<stdio.h>
#include<string.h>

#define KEY "secretkey"

void encrypt(char* file_name) {
    FILE *file = fopen(file_name, "r+");
    if (!file) {
        printf("Error opening file.\n");
        return;
    }

    int len = strlen(file_name);
    char key[len];
    strncpy(key, file_name, len);
    key[len] = '\0';

    char buf[1024];
    int count = 0;
    while (fread(buf, sizeof(char), sizeof(buf), file) > 0) {
        for (int i = 0; i < strlen(buf); i++) {
            buf[i] ^= key[i % strlen(key)];
        }
        fwrite(buf, sizeof(char), strlen(buf), file);
        count++;
    }
    printf("File encrypted successfully.\n");
    fclose(file);
}

void decrypt(char* file_name) {
    FILE *file = fopen(file_name, "r+");
    if (!file) {
        printf("Error opening file.\n");
        return;
    }

    int len = strlen(file_name);
    char key[len];
    strncpy(key, file_name, len);
    key[len] = '\0';

    char buf[1024];
    int count = 0;
    while (fread(buf, sizeof(char), sizeof(buf), file) > 0) {
        for (int i = 0; i < strlen(buf); i++) {
            buf[i] ^= key[i % strlen(key)];
        }
        fwrite(buf, sizeof(char), strlen(buf), file);
        count++;
    }
    printf("File decrypted successfully.\n");
    fclose(file);
}

int main() {
    encrypt("test.txt");
    decrypt("encrypted_test.txt");
    return 0;
}