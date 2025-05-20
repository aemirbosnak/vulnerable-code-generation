//FormAI DATASET v1.0 Category: File Encyptor ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_NAME_LENGTH 256
#define MAX_PASSWORD_LENGTH 32

void encrypt_file(char* file_name, char* password);
void decrypt_file(char* file_name, char* password);

int main() {
    printf("Welcome to File Encryptor!\n\n");

    char file_name[MAX_FILE_NAME_LENGTH];
    printf("Enter the name of the file to be encrypted/decrypted (with extension): ");
    fgets(file_name, MAX_FILE_NAME_LENGTH, stdin);
    strtok(file_name, "\n");

    char password[MAX_PASSWORD_LENGTH];
    printf("Enter the password to be used for encryption/decryption: ");
    fgets(password, MAX_PASSWORD_LENGTH, stdin);
    strtok(password, "\n");

    int choice;
    printf("\nWhat would you like to do?\n");
    printf("1. Encrypt the file\n");
    printf("2. Decrypt the file\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            encrypt_file(file_name, password);
            printf("File encryption successful!\n");
            break;
        case 2:
            decrypt_file(file_name, password);
            printf("File decryption successful!\n");
            break;
        default:
            printf("Invalid choice!\n");
    }

    return 0;
}

void encrypt_file(char* file_name, char* password) {
    FILE* fp = fopen(file_name, "rb");
    if (fp == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }

    // Get file size
    fseek(fp, 0L, SEEK_END);
    long file_size = ftell(fp);
    fseek(fp, 0L, SEEK_SET);

    // Allocate memory to read file contents
    char* file_contents = malloc(file_size + 1);
    if (file_contents == NULL) {
        printf("Error allocating memory!\n");
        exit(1);
    }

    // Read file contents and close file
    fread(file_contents, file_size, 1, fp);
    fclose(fp);

    // XOR each byte of file with corresponding byte of password
    int password_len = strlen(password);
    for (long i = 0; i < file_size; i++) {
        file_contents[i] = file_contents[i] ^ password[i % password_len];
    }

    // Write encrypted contents to file
    fp = fopen(file_name, "wb");
    if (fp == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }

    fwrite(file_contents, file_size, 1, fp);
    fclose(fp);

    free(file_contents);    
}

void decrypt_file(char* file_name, char* password) {
    FILE* fp = fopen(file_name, "rb");
    if (fp == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }

    // Get file size
    fseek(fp, 0L, SEEK_END);
    long file_size = ftell(fp);
    fseek(fp, 0L, SEEK_SET);

    // Allocate memory to read file contents
    char* file_contents = malloc(file_size + 1);
    if (file_contents == NULL) {
        printf("Error allocating memory!\n");
        exit(1);
    }

    // Read file contents and close file
    fread(file_contents, file_size, 1, fp);
    fclose(fp);

    // XOR each byte of file with corresponding byte of password
    int password_len = strlen(password);
    for (long i = 0; i < file_size; i++) {
        file_contents[i] = file_contents[i] ^ password[i % password_len];
    }

    // Write decrypted contents to file
    fp = fopen(file_name, "wb");
    if (fp == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }

    fwrite(file_contents, file_size, 1, fp);
    fclose(fp);

    free(file_contents);
}