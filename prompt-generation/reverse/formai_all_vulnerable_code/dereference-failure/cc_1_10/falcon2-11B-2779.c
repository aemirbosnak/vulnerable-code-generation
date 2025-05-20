//Falcon2-11B DATASET v1.0 Category: File Encyptor ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_NAME_SIZE 100

int main() {
    char file_name[MAX_FILE_NAME_SIZE];
    char key[MAX_FILE_NAME_SIZE];
    char encrypted_file_name[MAX_FILE_NAME_SIZE];

    printf("Enter the name of the file to encrypt: ");
    fgets(file_name, MAX_FILE_NAME_SIZE, stdin);
    file_name[strcspn(file_name, "\n")] = '\0';

    printf("Enter the encryption key: ");
    fgets(key, MAX_FILE_NAME_SIZE, stdin);
    key[strcspn(key, "\n")] = '\0';

    printf("Enter the name of the encrypted file (excluding the extension): ");
    fgets(encrypted_file_name, MAX_FILE_NAME_SIZE, stdin);
    encrypted_file_name[strcspn(encrypted_file_name, "\n")] = '\0';

    char* decrypt_file_name = (char*)malloc(strlen(encrypted_file_name) + 2);
    strcpy(decrypt_file_name, encrypted_file_name);
    decrypt_file_name[strlen(encrypted_file_name)] = '.';
    decrypt_file_name[strlen(encrypted_file_name) + 1] = '\0';

    FILE* file = fopen(file_name, "rb");
    if (!file) {
        printf("Failed to open the file for reading!\n");
        return 1;
    }

    FILE* encrypted_file = fopen(encrypted_file_name, "wb");
    if (!encrypted_file) {
        printf("Failed to create the encrypted file!\n");
        fclose(file);
        return 1;
    }

    char buffer[1024];
    while (fread(buffer, 1, sizeof(buffer), file) > 0) {
        for (int i = 0; i < strlen(buffer); i++) {
            buffer[i] = buffer[i] ^ key[i % strlen(key)];
        }
        fwrite(buffer, 1, strlen(buffer), encrypted_file);
    }

    fclose(file);
    fclose(encrypted_file);

    printf("Encryption successful!\n");
    return 0;
}