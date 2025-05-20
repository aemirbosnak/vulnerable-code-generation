//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_KEY_SIZE 32

// Function to generate a random key
void generate_key(char *key) {
    int i;
    for (i = 0; i < MAX_KEY_SIZE; i++) {
        key[i] = rand() % 26 + 'a';
    }
    key[MAX_KEY_SIZE - 1] = '\0';
}

// Function to encrypt a file
void encrypt_file(FILE *input_file, FILE *output_file, char *key) {
    int ch;
    while ((ch = fgetc(input_file))!= EOF) {
        ch = toupper(ch);
        if (isalpha(ch)) {
            ch = (ch - 'A' + 13) % 26 + 'A';
        }
        fputc(ch, output_file);
    }
}

// Function to decrypt a file
void decrypt_file(FILE *input_file, FILE *output_file, char *key) {
    int ch;
    while ((ch = fgetc(input_file))!= EOF) {
        ch = toupper(ch);
        if (isalpha(ch)) {
            ch = (ch - 'A' - 13 + 26) % 26 + 'A';
        }
        fputc(ch, output_file);
    }
}

int main(int argc, char *argv[]) {
    if (argc!= 4) {
        printf("Usage: %s <mode> <input_file> <output_file>\n", argv[0]);
        return 1;
    }

    char mode = argv[1][0];
    FILE *input_file = fopen(argv[2], "rb");
    FILE *output_file = fopen(argv[3], "wb");

    if (input_file == NULL || output_file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    char key[MAX_KEY_SIZE];
    generate_key(key);

    if (mode == 'e') {
        encrypt_file(input_file, output_file, key);
        printf("File encrypted successfully.\n");
    } else if (mode == 'd') {
        decrypt_file(input_file, output_file, key);
        printf("File decrypted successfully.\n");
    } else {
        printf("Invalid mode.\n");
        return 1;
    }

    fclose(input_file);
    fclose(output_file);
    return 0;
}