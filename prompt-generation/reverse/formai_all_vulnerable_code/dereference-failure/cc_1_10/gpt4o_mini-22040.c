//GPT-4o-mini DATASET v1.0 Category: File Encryptor ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024
#define KEY_SIZE 256

void display_menu();
void encrypt_file(const char *input_file, const char *output_file, const char *key);
void decrypt_file(const char *input_file, const char *output_file, const char *key);
void handle_error(const char *msg);

int main() {
    int choice;
    char input_file[BUFFER_SIZE];
    char output_file[BUFFER_SIZE];
    char key[KEY_SIZE];

    while(1) {
        display_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter the input filename: ");
                scanf("%s", input_file);
                printf("Enter the output filename: ");
                scanf("%s", output_file);
                printf("Enter the encryption key: ");
                scanf("%s", key);
                encrypt_file(input_file, output_file, key);
                printf("File encrypted successfully.\n");
                break;

            case 2:
                printf("Enter the input filename: ");
                scanf("%s", input_file);
                printf("Enter the output filename: ");
                scanf("%s", output_file);
                printf("Enter the decryption key: ");
                scanf("%s", key);
                decrypt_file(input_file, output_file, key);
                printf("File decrypted successfully.\n");
                break;

            case 3:
                printf("Exiting the program.\n");
                exit(0);

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

void display_menu() {
    printf("\n=============================\n");
    printf("         File Encryptor     \n");
    printf("=============================\n");
    printf("1. Encrypt a File\n");
    printf("2. Decrypt a File\n");
    printf("3. Exit\n");
    printf("=============================\n");
}

void encrypt_file(const char *input_file, const char *output_file, const char *key) {
    FILE *input = fopen(input_file, "rb");
    FILE *output = fopen(output_file, "wb");
    if(input == NULL || output == NULL) {
        handle_error("Error opening files for encryption.");
    }

    int key_len = strlen(key);
    unsigned char buffer[BUFFER_SIZE];
    size_t bytes_read;

    while((bytes_read = fread(buffer, 1, BUFFER_SIZE, input)) > 0) {
        for(size_t i = 0; i < bytes_read; i++) {
            buffer[i] ^= key[i % key_len];  // XOR encryption
        }
        fwrite(buffer, 1, bytes_read, output);
    }

    fclose(input);
    fclose(output);
}

void decrypt_file(const char *input_file, const char *output_file, const char *key) {
    FILE *input = fopen(input_file, "rb");
    FILE *output = fopen(output_file, "wb");
    if(input == NULL || output == NULL) {
        handle_error("Error opening files for decryption.");
    }

    int key_len = strlen(key);
    unsigned char buffer[BUFFER_SIZE];
    size_t bytes_read;

    while((bytes_read = fread(buffer, 1, BUFFER_SIZE, input)) > 0) {
        for(size_t i = 0; i < bytes_read; i++) {
            buffer[i] ^= key[i % key_len];  // XOR decryption (symmetric with encryption)
        }
        fwrite(buffer, 1, bytes_read, output);
    }

    fclose(input);
    fclose(output);
}

void handle_error(const char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}