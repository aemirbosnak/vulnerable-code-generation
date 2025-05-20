//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_KEY_LEN 100
#define MAX_FILE_LEN 1000000
#define ALPHABET_LEN 26

char alphabet[ALPHABET_LEN] = "abcdefghijklmnopqrstuvwxyz";

void generate_key(char key[], int key_len) {
    int i;
    for (i = 0; i < key_len; i++) {
        key[i] = alphabet[rand() % ALPHABET_LEN];
    }
}

void encrypt_file(FILE *input_file, FILE *output_file, char key[]) {
    int key_len = strlen(key);
    int ch;
    while ((ch = fgetc(input_file))!= EOF) {
        if (isalpha(ch)) {
            ch = toupper(ch) - 'A';
            ch = (ch + key_len) % key_len;
            ch = ch + 'A';
            fputc(ch, output_file);
        } else {
            fputc(ch, output_file);
        }
    }
}

void decrypt_file(FILE *input_file, FILE *output_file, char key[]) {
    int key_len = strlen(key);
    int ch;
    while ((ch = fgetc(input_file))!= EOF) {
        if (isalpha(ch)) {
            ch = toupper(ch) - 'A';
            ch = (ch - key_len + 26) % 26;
            ch = ch + 'A';
            fputc(ch, output_file);
        } else {
            fputc(ch, output_file);
        }
    }
}

int main() {
    char input_file_name[MAX_FILE_LEN], output_file_name[MAX_FILE_LEN], key[MAX_KEY_LEN];
    printf("Enter input file name: ");
    scanf("%s", input_file_name);
    printf("Enter output file name: ");
    scanf("%s", output_file_name);
    printf("Enter key: ");
    scanf("%s", key);

    FILE *input_file = fopen(input_file_name, "r");
    if (input_file == NULL) {
        printf("Error: Could not open input file.\n");
        exit(1);
    }
    FILE *output_file = fopen(output_file_name, "w");
    if (output_file == NULL) {
        printf("Error: Could not open output file.\n");
        exit(1);
    }

    encrypt_file(input_file, output_file, key);

    fclose(input_file);
    fclose(output_file);

    printf("Encryption complete.\n");

    return 0;
}