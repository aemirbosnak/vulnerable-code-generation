//FormAI DATASET v1.0 Category: File Encyptor ; Style: scientific
// C File Encryptor 
// This program generates a new encrypted file by XORing the contents of the original file with a secret key.
// The encrypted file can be decrypted only using the same secret key.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFSIZE 1024

// Function to encrypt the file using a secret key
void encrypt_file(FILE* fin, char* key, FILE* fout) {
    int i = 0;
    char buf[BUFSIZE];

    while (fgets(buf, BUFSIZE, fin)) {
        for (i = 0; i < strlen(buf); i++) {
            // XOR each character of the line with the secret key
            buf[i] = buf[i] ^ key[i % strlen(key)];
        }
        fputs(buf, fout);
    }
}

// Function to decrypt the file using a secret key
void decrypt_file(FILE* fin, char* key, FILE* fout) {
    int i = 0;
    char buf[BUFSIZE];

    while (fgets(buf, BUFSIZE, fin)) {
        for (i = 0; i < strlen(buf); i++) {
            // XOR each character of the line with the secret key
            buf[i] = buf[i] ^ key[i % strlen(key)];
        }
        fputs(buf, fout);
    }
}

int main(int argc, char* argv[]) {
    FILE* fin;
    FILE* fout;
    char key[BUFSIZE];
    char input_file[BUFSIZE];
    char output_file[BUFSIZE];

    // Check for the correct usage of the program
    if (argc != 4) {
        printf("Usage: %s [encrypt/decrypt] [input_file] [output_file]\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Open the input file in read mode
    strcpy(input_file, argv[2]);
    fin = fopen(input_file, "r");
    if (!fin) {
        printf("Error opening input file: %s\n", input_file);
        exit(EXIT_FAILURE);
    }

    // Open the output file in write mode
    strcpy(output_file, argv[3]);
    fout = fopen(output_file, "w");
    if (!fout) {
        printf("Error opening output file: %s\n", output_file);
        exit(EXIT_FAILURE);
    }

    // Get the secret key from the user
    printf("Enter the secret key: ");
    scanf("%s", key);

    // Encrypt or Decrypt the file based on user input
    if (strcmp(argv[1], "encrypt") == 0) {
        encrypt_file(fin, key, fout);
        printf("File encryption successful!\n");
    } else if (strcmp(argv[1], "decrypt") == 0) {
        decrypt_file(fin, key, fout);
        printf("File decryption successful!\n");
    } else {
        printf("Invalid option! Use encrypt/decrypt\n");
        exit(EXIT_FAILURE);
    }

    // Close the input and output files
    fclose(fin);
    fclose(fout);

    return 0;
}