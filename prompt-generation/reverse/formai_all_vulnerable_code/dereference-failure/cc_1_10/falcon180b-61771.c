//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define KEY "secret_key"

// Function to encrypt the file
void encrypt_file(FILE *input_file, FILE *output_file) {
    char ch;
    int key_index = 0;

    while ((ch = fgetc(input_file))!= EOF) {
        ch = toupper(ch);
        if (isalpha(ch)) {
            ch = ch + (KEY[key_index] - 'A');
            key_index = (key_index + 1) % strlen(KEY);
        }
        fputc(ch, output_file);
    }
}

// Function to decrypt the file
void decrypt_file(FILE *input_file, FILE *output_file) {
    char ch;
    int key_index = 0;

    while ((ch = fgetc(input_file))!= EOF) {
        ch = toupper(ch);
        if (isalpha(ch)) {
            ch = ch - (KEY[key_index] - 'A');
            key_index = (key_index + 1) % strlen(KEY);
        }
        fputc(ch, output_file);
    }
}

int main() {
    FILE *input_file, *output_file;
    char file_name[100];
    int choice;

    printf("Enter the name of the file to be encrypted/decrypted: ");
    scanf("%s", file_name);

    input_file = fopen(file_name, "rb");
    if (input_file == NULL) {
        printf("Error: File not found\n");
        exit(0);
    }

    output_file = fopen("encrypted_file.txt", "wb");
    if (output_file == NULL) {
        printf("Error: Unable to create output file\n");
        exit(0);
    }

    printf("Enter 1 to encrypt the file\nEnter 2 to decrypt the file: ");
    scanf("%d", &choice);

    if (choice == 1) {
        encrypt_file(input_file, output_file);
        printf("File encrypted successfully\n");
    } else if (choice == 2) {
        decrypt_file(input_file, output_file);
        printf("File decrypted successfully\n");
    } else {
        printf("Invalid choice\n");
    }

    fclose(input_file);
    fclose(output_file);

    return 0;
}