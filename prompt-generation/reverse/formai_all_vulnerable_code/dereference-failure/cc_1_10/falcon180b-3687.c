//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define KEY "mysecretkey"
#define KEY_LENGTH 12

// Function to encrypt the file
void encrypt_file(FILE *fp) {
    char ch;
    while ((ch = fgetc(fp))!= EOF) {
        ch = ch ^ KEY[fgetc(stdin) % KEY_LENGTH];
        fputc(ch, fp);
    }
}

// Function to decrypt the file
void decrypt_file(FILE *fp) {
    char ch;
    while ((ch = fgetc(fp))!= EOF) {
        ch = ch ^ KEY[fgetc(stdin) % KEY_LENGTH];
        fputc(ch, stdout);
    }
}

int main() {
    FILE *input_file, *output_file;
    char filename[50];

    // Get the name of the input file
    printf("Enter the name of the input file: ");
    scanf("%s", filename);

    // Open the input file
    input_file = fopen(filename, "rb");
    if (input_file == NULL) {
        printf("Error opening input file.\n");
        exit(1);
    }

    // Create the output file
    output_file = fopen("encrypted_file.txt", "wb");
    if (output_file == NULL) {
        printf("Error creating output file.\n");
        exit(1);
    }

    // Encrypt the file
    encrypt_file(input_file);

    // Close the input and output files
    fclose(input_file);
    fclose(output_file);

    // Get the name of the output file
    printf("Enter the name of the output file: ");
    scanf("%s", filename);

    // Open the encrypted file for reading
    input_file = fopen("encrypted_file.txt", "rb");
    if (input_file == NULL) {
        printf("Error opening input file.\n");
        exit(1);
    }

    // Create the decrypted file
    output_file = fopen(filename, "wb");
    if (output_file == NULL) {
        printf("Error creating output file.\n");
        exit(1);
    }

    // Decrypt the file
    decrypt_file(input_file);

    // Close the input and output files
    fclose(input_file);
    fclose(output_file);

    printf("File encryption and decryption complete.\n");
    return 0;
}