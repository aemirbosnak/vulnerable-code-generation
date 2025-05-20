//FormAI DATASET v1.0 Category: File Encyptor ; Style: paranoid
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void encrypt(char *filename, char *key) {
    // open the input and output files
    FILE *input = fopen(filename, "rb");
    char output_filename[strlen(filename) + 5];
    strcpy(output_filename, filename);
    strcat(output_filename, ".enc");
    FILE *output = fopen(output_filename, "wb");

    // get the key length
    int key_length = strlen(key);

    // init the random number generator with the key
    srand(key_length);

    // encrypt each byte in the file
    int byte;
    while ((byte = fgetc(input)) != EOF) {
        int random_byte = rand() % 256;
        int encrypted_byte = byte ^ random_byte;
        fputc(encrypted_byte, output);
    }

    // close the files
    fclose(input);
    fclose(output);

    // delete the original file
    remove(filename);

    printf("Encryption complete.\n");
}

void decrypt(char *filename, char *key) {
    // open the input and output files
    FILE *input = fopen(filename, "rb");
    char output_filename[strlen(filename) + 5];
    strcpy(output_filename, filename);
    strcat(output_filename, ".dec");
    FILE *output = fopen(output_filename, "wb");

    // get the key length
    int key_length = strlen(key);

    // init the random number generator with the key
    srand(key_length);

    // decrypt each byte in the file
    int byte;
    while ((byte = fgetc(input)) != EOF) {
        int random_byte = rand() % 256;
        int decrypted_byte = byte ^ random_byte;
        fputc(decrypted_byte, output);
    }

    // close the files
    fclose(input);
    fclose(output);

    // delete the encrypted file
    remove(filename);

    printf("Decryption complete.\n");
}

int main(int argc, char *argv[]) {
    // check if the user provided the correct number of arguments
    if (argc != 4) {
        printf("Usage: %s [encrypt/decrypt] [filename] [key]\n", argv[0]);
        exit(1);
    }

    // get the command, filename, and key
    char *command = argv[1];
    char *filename = argv[2];
    char *key = argv[3];

    // encrypt or decrypt the file based on the command
    if (strcmp(command, "encrypt") == 0) {
        encrypt(filename, key);
    } else if (strcmp(command, "decrypt") == 0) {
        decrypt(filename, key);
    } else {
        printf("Invalid command.\n");
        exit(1);
    }

    return 0;
}