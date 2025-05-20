//FormAI DATASET v1.0 Category: File Encyptor ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

void encrypt(char* file_name, char* key) {
    FILE* input_file = fopen(file_name, "r");
    if (input_file == NULL) {
        printf("Error: Unable to open file '%s'\n", file_name);
        exit(1);
    }

    // Create output file with _encrypted suffix
    char* output_file_name = malloc(strlen(file_name) + strlen("_encrypted") + 1);
    strcpy(output_file_name, file_name);
    strcat(output_file_name, "_encrypted");
    FILE* output_file = fopen(output_file_name, "w");
    if (output_file == NULL) {
        printf("Error: Unable to create output file '%s'\n", output_file_name);
        exit(1);
    }

    // Loop through input file and encrypt each character
    char buffer[BUFFER_SIZE];
    int i = 0;
    char key_character = '\0';
    while (fgets(buffer, BUFFER_SIZE, input_file) != NULL) {
        for (i = 0; i < BUFFER_SIZE; i++) {
            if (buffer[i] == '\0') {
                break;
            }
            if (key_character == '\0') {
                key_character = key[strlen(key) % strlen(key)];
            }
            buffer[i] ^= key_character;
            key_character = key[(i + strlen(key)) % strlen(key)];
        }
        fputs(buffer, output_file);
    }

    // Close input and output files and free memory
    fclose(input_file);
    fclose(output_file);
    free(output_file_name);

    printf("Encrypted file '%s' with key '%s'\n", file_name, key);
}

void decrypt(char* file_name, char* key) {
    // Create input file with _decrypted suffix
    char* input_file_name = malloc(strlen(file_name) + strlen("_encrypted") + 1);
    strcpy(input_file_name, file_name);
    strcat(input_file_name, "_encrypted");
    FILE* input_file = fopen(input_file_name, "r");
    if (input_file == NULL) {
        printf("Error: Unable to open file '%s'\n", input_file_name);
        exit(1);
    }

    // Create output file with _decrypted suffix
    char* output_file_name = malloc(strlen(file_name) + strlen("_decrypted") + 1);
    strcpy(output_file_name, file_name);
    strcat(output_file_name, "_decrypted");
    FILE* output_file = fopen(output_file_name, "w");
    if (output_file == NULL) {
        printf("Error: Unable to create output file '%s'\n", output_file_name);
        exit(1);
    }

    // Loop through input file and decrypt each character
    char buffer[BUFFER_SIZE];
    int i = 0;
    char key_character = '\0';
    while (fgets(buffer, BUFFER_SIZE, input_file) != NULL) {
        for (i = 0; i < BUFFER_SIZE; i++) {
            if (buffer[i] == '\0') {
                break;
            }
            if (key_character == '\0') {
                key_character = key[strlen(key) % strlen(key)];
            }
            buffer[i] ^= key_character;
            key_character = key[(i + strlen(key)) % strlen(key)];
        }
        fputs(buffer, output_file);
    }

    // Close input and output files and free memory
    fclose(input_file);
    fclose(output_file);
    free(input_file_name);
    free(output_file_name);

    printf("Decrypted file '%s' with key '%s'\n", file_name, key);
}

int main(int argc, char* argv[]) {
    if (argc < 4 || argc > 4) {
        printf("Usage: %s <encrypt|decrypt> <file name> <encryption key>\n", argv[0]);
        exit(1);
    }

    if (strcmp(argv[1], "encrypt") == 0) {
        encrypt(argv[2], argv[3]);
    } else if (strcmp(argv[1], "decrypt") == 0) {
        decrypt(argv[2], argv[3]);
    } else {
        printf("Invalid command '%s'. Must be either 'encrypt' or 'decrypt'.\n", argv[1]);
        exit(1);
    }

    return 0;
}