//GPT-4o-mini DATASET v1.0 Category: File Encryptor ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void encrypt_decrypt(const char *input_file, const char *output_file, char key) {
    FILE *input = fopen(input_file, "rb");
    FILE *output = fopen(output_file, "wb");
    if (!input || !output) {
        perror("Error opening files");
        exit(EXIT_FAILURE);
    }

    int ch;
    while ((ch = fgetc(input)) != EOF) {
        fputc(ch ^ key, output); // XOR operation
    }

    fclose(input);
    fclose(output);
}

void display_menu() {
    printf("********************************\n");
    printf("*  Retro File Encryptor v1.0   *\n");
    printf("********************************\n");
    printf("1. Encrypt a file\n");
    printf("2. Decrypt a file\n");
    printf("3. Exit\n");
    printf("********************************\n");
}

int main() {
    int choice;
    char key = 'K'; // A simple key for XOR operations
    char input_file[256], output_file[256];

    while (1) {
        display_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the name of the file to encrypt: ");
                scanf("%s", input_file);
                snprintf(output_file, sizeof(output_file), "%s.encrypted", input_file);
                encrypt_decrypt(input_file, output_file, key);
                printf("File encrypted successfully as %s\n", output_file);
                break;

            case 2:
                printf("Enter the name of the file to decrypt: ");
                scanf("%s", input_file);
                snprintf(output_file, sizeof(output_file), "%s.decrypted", input_file);
                encrypt_decrypt(input_file, output_file, key);
                printf("File decrypted successfully as %s\n", output_file);
                break;

            case 3:
                printf("Exiting the program. Thank you!\n");
                exit(EXIT_SUCCESS);

            default:
                printf("Invalid choice! Please choose again.\n");
        }
        printf("\n");
    }

    return 0;
}