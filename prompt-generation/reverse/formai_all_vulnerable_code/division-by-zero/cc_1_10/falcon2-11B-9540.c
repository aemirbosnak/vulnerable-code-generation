//Falcon2-11B DATASET v1.0 Category: File Encyptor ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_NAME_LENGTH 100
#define MAX_PASSWORD_LENGTH 20
#define BUF_SIZE 256

int main() {
    char file_name[MAX_FILE_NAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
    char encrypted_file[BUF_SIZE];
    char key[BUF_SIZE];

    // Prompt user for file name
    printf("Enter file name: ");
    fgets(file_name, MAX_FILE_NAME_LENGTH, stdin);

    // Prompt user for password
    printf("Enter password: ");
    fgets(password, MAX_PASSWORD_LENGTH, stdin);

    // Read the file
    FILE* file = fopen(file_name, "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    // Read the file into a buffer
    int file_size = (int)ftell(file);
    fseek(file, 0, SEEK_SET);
    fread(encrypted_file, 1, file_size, file);
    fclose(file);

    // Encrypt the file using the password as the encryption key
    int encrypted_size = (int)strlen(encrypted_file);
    int i = 0;
    for (i = 0; i < encrypted_size; i++) {
        encrypted_file[i] = encrypted_file[i] ^ key[i % strlen(password)];
    }

    // Write the encrypted file
    file = fopen(file_name, "w");
    if (file == NULL) {
        printf("Error opening file for writing.\n");
        return 1;
    }
    fwrite(encrypted_file, 1, encrypted_size, file);
    fclose(file);

    // Prompt user for new password
    printf("Enter new password: ");
    fgets(key, BUF_SIZE, stdin);

    // Decrypt the file using the new password as the decryption key
    int decrypted_size = (int)strlen(encrypted_file);
    for (i = 0; i < decrypted_size; i++) {
        encrypted_file[i] = encrypted_file[i] ^ key[i % strlen(password)];
    }

    // Write the decrypted file
    file = fopen(file_name, "w");
    if (file == NULL) {
        printf("Error opening file for writing.\n");
        return 1;
    }
    fwrite(encrypted_file, 1, decrypted_size, file);
    fclose(file);

    printf("File encrypted and decrypted successfully.\n");
    return 0;
}