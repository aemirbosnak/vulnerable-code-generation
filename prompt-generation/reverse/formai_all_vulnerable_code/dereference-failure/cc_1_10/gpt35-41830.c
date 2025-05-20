//FormAI DATASET v1.0 Category: Modern Encryption ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define KEY "mysecretpassword"

void encrypt(char *input_file, char *output_file);
void decrypt(char *input_file, char *output_file);

int main(int argc, char *argv[]) {
    if (argc < 3 || argc > 4) {
        printf("Usage: %s [-e|-d] input_file output_file\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    if (strcmp(argv[1], "-e") == 0) {
        encrypt(argv[2], argv[3]);
    } else if (strcmp(argv[1], "-d") == 0) {
        decrypt(argv[2], argv[3]);
    } else {
        printf("Error: Invalid option %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    return 0;
}

void encrypt(char *input_file, char *output_file) {
    FILE *input_fp, *output_fp;
    int key_len;
    char *key;
    unsigned long long int curr_pos = 0;
    char ch;

    input_fp = fopen(input_file, "r");
    if (!input_fp) {
        printf("Error: Cannot open file %s\n", input_file);
        exit(EXIT_FAILURE);
    }

    output_fp = fopen(output_file, "w+");
    if (!output_fp) {
        printf("Error: Cannot open file %s\n", output_file);
        exit(EXIT_FAILURE);
    }

    key_len = strlen(KEY);
    key = (char *)malloc(key_len + 1);
    strncpy(key, KEY, key_len);

    fseek(input_fp, 0L, SEEK_END);
    unsigned long long int file_size = ftell(input_fp);
    rewind(input_fp);

    while (curr_pos < file_size) {
        ch = fgetc(input_fp);
        ch = (ch + key[curr_pos % key_len]) % 256;
        fputc(ch, output_fp);
        curr_pos++;
    }

    free(key);
    fclose(input_fp);
    fclose(output_fp);

    printf("Encryption successful. Output file: %s\n", output_file);
}

void decrypt(char *input_file, char *output_file) {
    FILE *input_fp, *output_fp;
    int key_len;
    char *key;
    unsigned long long int curr_pos = 0;
    char ch;

    input_fp = fopen(input_file, "r");
    if (!input_fp) {
        printf("Error: Cannot open file %s\n", input_file);
        exit(EXIT_FAILURE);
    }

    output_fp = fopen(output_file, "w+");
    if (!output_fp) {
        printf("Error: Cannot open file %s\n", output_file);
        exit(EXIT_FAILURE);
    }

    key_len = strlen(KEY);
    key = (char *)malloc(key_len + 1);
    strncpy(key, KEY, key_len);

    fseek(input_fp, 0L, SEEK_END);
    unsigned long long int file_size = ftell(input_fp);
    rewind(input_fp);

    while (curr_pos < file_size) {
        ch = fgetc(input_fp);
        ch = (ch - key[curr_pos % key_len] + 256) % 256;
        fputc(ch, output_fp);
        curr_pos++;
    }

    free(key);
    fclose(input_fp);
    fclose(output_fp);

    printf("Decryption successful. Output file: %s\n", output_file);
}