//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: Cryptic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<time.h>

#define MAX_KEY_LENGTH 50

// Function to encrypt the file
void encrypt_file(FILE* input_file, FILE* output_file, char* key) {
    char ch;
    int key_index = 0;
    while ((ch = fgetc(input_file))!= EOF) {
        ch = toupper(ch);
        if (isalpha(ch)) {
            ch = (char) ((ch - 65 + key_index) % 26 + 65);
        }
        fputc(ch, output_file);
        key_index = (key_index + 1) % strlen(key);
    }
}

// Function to decrypt the file
void decrypt_file(FILE* input_file, FILE* output_file, char* key) {
    char ch;
    int key_index = 0;
    while ((ch = fgetc(input_file))!= EOF) {
        ch = toupper(ch);
        if (isalpha(ch)) {
            ch = (char) ((ch - 65 - key_index + 26) % 26 + 65);
        }
        fputc(ch, output_file);
        key_index = (key_index + 1) % strlen(key);
    }
}

// Function to generate a random key
void generate_key(char* key) {
    srand(time(NULL));
    for (int i = 0; i < MAX_KEY_LENGTH; i++) {
        key[i] = rand() % 26 + 65;
    }
    key[MAX_KEY_LENGTH - 1] = '\0';
}

int main() {
    char input_file[100], output_file[100], key[MAX_KEY_LENGTH];
    printf("Enter the name of the input file: ");
    scanf("%s", input_file);
    printf("Enter the name of the output file: ");
    scanf("%s", output_file);
    printf("Enter the encryption key: ");
    scanf("%s", key);
    FILE* input = fopen(input_file, "rb");
    FILE* output = fopen(output_file, "wb");
    if (input == NULL || output == NULL) {
        printf("Error opening file.\n");
        return 1;
    }
    if (strcmp(key, "default") == 0) {
        generate_key(key);
        printf("Generated key: %s\n", key);
    }
    encrypt_file(input, output, key);
    fclose(input);
    fclose(output);
    printf("File encrypted successfully.\n");
    return 0;
}