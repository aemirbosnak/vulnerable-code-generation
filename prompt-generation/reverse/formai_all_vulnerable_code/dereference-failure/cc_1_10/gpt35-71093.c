//FormAI DATASET v1.0 Category: File Encyptor ; Style: genious
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#define KEY_SIZE 16
#define BUFFER_SIZE 1024

char* generate_key(void);
void encrypt_file(char* key, char* filename);
void decrypt_file(char* key, char* filename);

int main() {
    char key[KEY_SIZE];

    printf("Welcome to the Genius File Encryptor!\n");
    printf("------------------------------------\n\n");

    printf("Would you like to encrypt or decrypt a file?\n");
    printf("[1] Encrypt\n[2] Decrypt\n");

    int choice;
    scanf("%d", &choice);

    if (choice == 1) {
        printf("\nGenerating encryption key...\n");
        strcpy(key, generate_key());
        printf("Encryption key: %s\n", key);

        printf("\nEnter the name of the file you want to encrypt: ");
        char filename[100];
        scanf("%s", filename);

        encrypt_file(key, filename);

        printf("\nThe file has been successfully encrypted!\n");
    } else if (choice == 2) {
        printf("\nEnter the encryption key: ");
        scanf("%s", key);

        printf("\nEnter the name of the file you want to decrypt: ");
        char filename[100];
        scanf("%s", filename);

        decrypt_file(key, filename);

        printf("\nThe file has been successfully decrypted!\n");
    }

    return 0;
}

char* generate_key(void) {
    char charset[] = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ!@#$%^&*()_+-=[]{}|;':\",./<>?";
    char* key = malloc(sizeof(char) * KEY_SIZE);
    for (int i = 0; i < KEY_SIZE - 1; i++) {
        key[i] = charset[rand() % (sizeof(charset) - 1)];
    }
    key[KEY_SIZE - 1] = '\0';
    return key;
}

void encrypt_file(char* key, char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: could not open file.\n");
        exit(1);
    }

    char encrypted_filename[100];
    sprintf(encrypted_filename, "%s.enc", filename);
    FILE* encrypted_file = fopen(encrypted_filename, "w");

    char buffer[BUFFER_SIZE];
    while (fgets(buffer, BUFFER_SIZE, file)) {
        for (int i = 0; i < strlen(buffer); i++) {
            buffer[i] = buffer[i] ^ key[i % KEY_SIZE];
        }
        fprintf(encrypted_file, "%s", buffer);
    }

    fclose(file);
    fclose(encrypted_file);
}

void decrypt_file(char* key, char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: could not open file.\n");
        exit(1);
    }

    char decrypted_filename[100];
    sprintf(decrypted_filename, "%s.dec", filename);
    FILE* decrypted_file = fopen(decrypted_filename, "w");

    char buffer[BUFFER_SIZE];
    while (fgets(buffer, BUFFER_SIZE, file)) {
        for (int i = 0; i < strlen(buffer); i++) {
            buffer[i] = buffer[i] ^ key[i % KEY_SIZE];
        }
        fprintf(decrypted_file, "%s", buffer);
    }

    fclose(file);
    fclose(decrypted_file);
}