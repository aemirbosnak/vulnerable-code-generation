//GPT-4o-mini DATASET v1.0 Category: File Encryptor ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

void encrypt(char *data, const char *key) {
    size_t data_len = strlen(data);
    size_t key_len = strlen(key);
    for (size_t i = 0; i < data_len; i++) {
        data[i] ^= key[i % key_len];
    }
}

void decrypt(char *data, const char *key) {
    // Decryption is the same as encryption
    encrypt(data, key);
}

void read_file(const char *filename, char **buffer, size_t *size) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        perror("Could not open file");
        exit(EXIT_FAILURE);
    }

    fseek(file, 0, SEEK_END);
    *size = ftell(file);
    fseek(file, 0, SEEK_SET);
    
    *buffer = malloc(*size);
    if (!*buffer) {
        perror("Could not allocate memory");
        fclose(file);
        exit(EXIT_FAILURE);
    }

    fread(*buffer, 1, *size, file);
    fclose(file);
}

void write_file(const char *filename, const char *data, size_t size) {
    FILE *file = fopen(filename, "wb");
    if (!file) {
        perror("Could not open file to write");
        exit(EXIT_FAILURE);
    }

    fwrite(data, 1, size, file);
    fclose(file);
}

void show_menu() {
    printf("****************************************\n");
    printf("     C File Encryptor - EXTREME EDITION  \n");
    printf("****************************************\n");
    printf("1. Encrypt a file\n");
    printf("2. Decrypt a file\n");
    printf("3. Exit\n");
    printf("****************************************\n");
    printf("Choose an option (1-3): ");
}

void process_choice(int choice) {
    char filename[256];
    char key[256];
    char *data = NULL;
    size_t size = 0;

    switch (choice) {
        case 1:
            printf("Enter the filename to encrypt: ");
            scanf("%255s", filename);
            printf("Enter the encryption key: ");
            scanf("%255s", key);

            read_file(filename, &data, &size);
            encrypt(data, key);
            write_file("encrypted_file.dat", data, size);
            printf("File encrypted successfully as 'encrypted_file.dat'\n");
            break;

        case 2:
            printf("Enter the filename to decrypt: ");
            scanf("%255s", filename);
            printf("Enter the decryption key: ");
            scanf("%255s", key);

            read_file(filename, &data, &size);
            decrypt(data, key);
            write_file("decrypted_file.dat", data, size);
            printf("File decrypted successfully as 'decrypted_file.dat'\n");
            break;

        case 3:
            printf("Exiting the program. Goodbye!\n");
            free(data);
            exit(EXIT_SUCCESS);
            break;

        default:
            printf("Invalid choice! Please try again.\n");
            break;
    }

    free(data);
}

int main() {
    int choice;

    while (1) {
        show_menu();
        scanf("%d", &choice);
        process_choice(choice);
    }

    return 0;
}