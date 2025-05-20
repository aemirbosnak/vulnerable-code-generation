//FormAI DATASET v1.0 Category: File Encyptor ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_INPUT_LENGTH 1024
#define MAX_KEY_LENGTH 256

void encrypt(char *input_file_path, char *output_file_path, char *key) {
    FILE *input_file = fopen(input_file_path, "r");
    FILE *output_file = fopen(output_file_path, "w");
    char ch;
    int i = 0, j = 0, key_length = strlen(key);
    srand(time(0));

    while ((ch = fgetc(input_file)) != EOF) {
        if (i == key_length) {
            j = rand() % key_length;
            key[j] = key[j] ^ rand();
            i = 0;
        }
        char encrypted_ch = ch ^ key[i++];
        fputc(encrypted_ch, output_file);
    }
    fclose(input_file);
    fclose(output_file);
}

void decrypt(char *input_file_path, char *output_file_path, char *key) {
    FILE *input_file = fopen(input_file_path, "r");
    FILE *output_file = fopen(output_file_path, "w");
    char ch;
    int i = 0, j = 0, key_length = strlen(key);
    srand(time(0));

    while ((ch = fgetc(input_file)) != EOF) {
        if (i == key_length) {
            j = rand() % key_length;
            key[j] = key[j] ^ rand();
            i = 0;
        }
        char decrypted_ch = ch ^ key[i++];
        fputc(decrypted_ch, output_file);
    }
    fclose(input_file);
    fclose(output_file);
}

int main(int argc, char **argv) {
    if (argc < 4) {
        printf("Usage: %s [OPTION] [INPUT FILE PATH] [OUTPUT FILE PATH]\n", argv[0]);
        printf("Options: -e for encrypt, -d for decrypt\n");
        return 1;
    }

    char *option = argv[1];
    char *input_file_path = argv[2];
    char *output_file_path = argv[3];

    if (strcmp(option, "-e") == 0) {
        char key[MAX_KEY_LENGTH];
        printf("Enter Encryption Key: ");
        fgets(key, MAX_KEY_LENGTH, stdin);
        encrypt(input_file_path, output_file_path, key);
        printf("Encryption Successful.\n");
    } else if (strcmp(option, "-d") == 0) {
        char key[MAX_KEY_LENGTH];
        printf("Enter Decryption Key: ");
        fgets(key, MAX_KEY_LENGTH, stdin);
        decrypt(input_file_path, output_file_path, key);
        printf("Decryption Successful.\n");
    } else {
        printf("Invalid Option: %s\n", option);
        return 1;
    }

    return 0;
}