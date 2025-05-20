//FormAI DATASET v1.0 Category: File Encyptor ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_NAME_LEN 50
#define MAX_KEY_LEN 20

void encrypt(FILE* file, char* key) {
    char c;
    int i = 0;
    int key_len = strlen(key);

    while ((c = fgetc(file)) != EOF) {
        fputc(c ^ key[i % key_len], file);
        i++;
    }
}

void decrypt(FILE* file, char* key) {
    encrypt(file, key); // XOR is its own inverse
}

int main() {
    char file_name[MAX_FILE_NAME_LEN];
    char key[MAX_KEY_LEN];

    printf("Enter the name of the file you want to encrypt/decrypt: ");
    fgets(file_name, MAX_FILE_NAME_LEN, stdin);
    file_name[strcspn(file_name, "\n")] = 0; // remove newline character from fgets

    printf("Enter the encryption/decryption key: ");
    fgets(key, MAX_KEY_LEN, stdin);
    key[strcspn(key, "\n")] = 0;

    FILE* file = fopen(file_name, "r+");
    
    if (file == NULL) {
        printf("Error: file '%s' not found.", file_name);
        return 1;
    }

    printf("Enter 'e' to encrypt or 'd' to decrypt: ");
    char choice = getchar();

    switch (choice) {
        case 'e':
            encrypt(file, key);
            printf("File successfully encrypted.\n");
            break;
        case 'd':
            decrypt(file, key);
            printf("File successfully decrypted.\n");
            break;
        default:
            printf("Invalid option. Please enter 'e' or 'd'.");
            break;
    }

    fclose(file);
    return 0;
}