//FormAI DATASET v1.0 Category: File Encyptor ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void encrypt(char* file_name, char* key);

int main(int argc, char *argv[]) {
    char* file_name;
    char* key;

    // Check if file name and key are provided
    if (argc == 3) {
        file_name = argv[1];
        key = argv[2];
    } else {
        printf("Please provide file name and key\n");
        return 1;
    }

    encrypt(file_name, key);

    return 0;
}

void encrypt(char* file_name, char* key) {
    FILE *input_file, *output_file;
    char ch;
    int key_index = 0;

    input_file = fopen(file_name, "r");
    output_file = fopen("encrypted.txt", "w");

    if (input_file == NULL) {
        printf("Error opening file\n");
        exit(1);
    }

    if (output_file == NULL) {
        printf("Error creating encrypted file\n");
        exit(1);
    }

    while ((ch = fgetc(input_file)) != EOF) {
        // XOR operation with key character
        ch = ch ^ key[key_index];
        fputc(ch, output_file);

        // Update key index
        key_index++;
        if (key[key_index] == '\0') {
            key_index = 0;
        }
    }

    fclose(input_file);
    fclose(output_file);

    printf("Encryption Successful!\n");
}