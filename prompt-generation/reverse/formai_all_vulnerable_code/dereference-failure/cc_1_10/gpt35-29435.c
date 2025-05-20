//FormAI DATASET v1.0 Category: File Encyptor ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 100

void encrypt(char *input, char *output, char *key);
void decrypt(char *input, char *output, char *key);

int main() {
    char input_file[MAX_LEN], output_file[MAX_LEN], key[MAX_LEN];
    int choice;
    printf("Welcome to File Encryptor!\n");
    printf("Choose an option:\n1. Encrypt a file\n2. Decrypt a file\n");
    scanf("%d", &choice);
    printf("Enter the name of the input file: \n");
    scanf("%s", input_file);
    printf("Enter the name of the output file: \n");
    scanf("%s", output_file);
    printf("Enter the encryption/decryption key: \n");
    scanf("%s", key);
    if (choice == 1) {
        encrypt(input_file, output_file, key);
        printf("Encryption complete! \n");
    } else if (choice == 2) {
        decrypt(input_file, output_file, key);
        printf("Decryption complete! \n");
    } else {
        printf("Invalid option selected. Please try again.\n");
    }
    return 0;
}

void encrypt(char *input, char *output, char *key) {
    FILE *input_file = fopen(input, "r");
    FILE *output_file = fopen(output, "w");
    if (input_file == NULL) {
        printf("Error: Cannot open input file.\n");
        exit(1);
    }
    if (output_file == NULL) {
        printf("Error: Cannot open output file.\n");
        exit(1);
    }
    char c;
    int i = 0;
    while((c = getc(input_file)) != EOF) {
        c = c ^ key[i];
        putc(c, output_file);
        i++;
        if (i == strlen(key)) {
            i = 0;
        }
    }
    fclose(input_file);
    fclose(output_file);
}

void decrypt(char *input, char *output, char *key) {
    FILE *input_file = fopen(input, "r");
    FILE *output_file = fopen(output, "w");
    if (input_file == NULL) {
        printf("Error: Cannot open input file.\n");
        exit(1);
    }
    if (output_file == NULL) {
        printf("Error: Cannot open output file.\n");
        exit(1);
    }
    char c;
    int i = 0;
    while((c = getc(input_file)) != EOF) {
        c = c ^ key[i];
        putc(c, output_file);
        i++;
        if (i == strlen(key)) {
            i = 0;
        }
    }
    fclose(input_file);
    fclose(output_file);
}