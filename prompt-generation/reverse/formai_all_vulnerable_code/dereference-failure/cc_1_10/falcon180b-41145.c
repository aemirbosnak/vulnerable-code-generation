//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_KEY_LENGTH 100
#define MAX_FILE_SIZE 1000000

void encrypt_file(FILE *input_file, FILE *output_file, char *key) {
    char buffer[MAX_FILE_SIZE];
    int key_length = strlen(key);
    int buffer_index = 0;

    while (fgets(buffer, MAX_FILE_SIZE, input_file)!= NULL) {
        for (int i = 0; i < strlen(buffer); i++) {
            char c = toupper(buffer[i]);
            if (isalpha(c)) {
                c = (c + key[i % key_length] - 65) % 26 + 65;
            }
            buffer[i] = c;
        }
        fputs(buffer, output_file);
    }
}

void decrypt_file(FILE *input_file, FILE *output_file, char *key) {
    char buffer[MAX_FILE_SIZE];
    int key_length = strlen(key);
    int buffer_index = 0;

    while (fgets(buffer, MAX_FILE_SIZE, input_file)!= NULL) {
        for (int i = 0; i < strlen(buffer); i++) {
            char c = toupper(buffer[i]);
            if (isalpha(c)) {
                c = (c - key[i % key_length] + 26) % 26 + 65;
            }
            buffer[i] = c;
        }
        fputs(buffer, output_file);
    }
}

int main(int argc, char *argv[]) {
    if (argc!= 5) {
        printf("Usage: %s <input_file> <output_file> <encrypt/decrypt> <key>\n", argv[0]);
        return 1;
    }

    char *input_file = argv[1];
    char *output_file = argv[2];
    char *mode = argv[3];
    char *key = argv[4];

    FILE *input = fopen(input_file, "r");
    if (input == NULL) {
        printf("Error: Unable to open input file.\n");
        return 1;
    }

    FILE *output = fopen(output_file, "w");
    if (output == NULL) {
        printf("Error: Unable to open output file.\n");
        fclose(input);
        return 1;
    }

    if (strcmp(mode, "encrypt") == 0) {
        encrypt_file(input, output, key);
    } else if (strcmp(mode, "decrypt") == 0) {
        decrypt_file(input, output, key);
    } else {
        printf("Error: Invalid mode specified.\n");
        fclose(input);
        fclose(output);
        return 1;
    }

    fclose(input);
    fclose(output);
    return 0;
}