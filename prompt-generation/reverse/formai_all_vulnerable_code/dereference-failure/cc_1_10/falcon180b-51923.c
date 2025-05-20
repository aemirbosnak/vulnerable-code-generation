//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_KEY_SIZE 16

// Function to encrypt a file using a key
void encrypt_file(FILE *input_file, FILE *output_file, char *key) {
    int key_index = 0;
    int ch;
    while ((ch = fgetc(input_file))!= EOF) {
        // Shift the character by the key value
        ch = (ch + key[key_index] - 'a') % 26 + 'a';
        // Increment the key index
        key_index = (key_index + 1) % strlen(key);
        fputc(ch, output_file);
    }
}

// Function to decrypt an encrypted file using a key
void decrypt_file(FILE *input_file, FILE *output_file, char *key) {
    int key_index = 0;
    int ch;
    while ((ch = fgetc(input_file))!= EOF) {
        // Shift the character back by the key value
        ch = (ch - key[key_index] + 26) % 26 + 'a';
        // Increment the key index
        key_index = (key_index + 1) % strlen(key);
        fputc(ch, output_file);
    }
}

int main() {
    char input_filename[100], output_filename[100];
    char key[MAX_KEY_SIZE];
    printf("Enter the name of the input file: ");
    scanf("%s", input_filename);
    printf("Enter the name of the output file: ");
    scanf("%s", output_filename);
    printf("Enter the encryption key (up to %d characters): ", MAX_KEY_SIZE - 1);
    scanf("%s", key);

    // Open the input and output files
    FILE *input_file = fopen(input_filename, "r");
    FILE *output_file = fopen(output_filename, "w");

    if (input_file == NULL || output_file == NULL) {
        printf("Error: Could not open file.\n");
        return 1;
    }

    // Encrypt the input file
    encrypt_file(input_file, output_file, key);

    // Close the files
    fclose(input_file);
    fclose(output_file);

    printf("File encrypted successfully.\n");
    return 0;
}