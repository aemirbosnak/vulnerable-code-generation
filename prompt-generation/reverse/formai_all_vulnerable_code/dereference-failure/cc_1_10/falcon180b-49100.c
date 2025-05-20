//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_KEY_SIZE 50
#define MAX_FILE_SIZE 1000000

void encrypt_file(FILE *input_file, FILE *output_file, char *key) {
    int ch;
    int key_index = 0;

    while ((ch = fgetc(input_file))!= EOF) {
        if (isalpha(ch)) {
            ch = (ch - 65 + key_index) % 26 + 65;
        } else {
            ch = ch;
        }

        fputc(ch, output_file);

        if (++key_index == MAX_KEY_SIZE) {
            key_index = 0;
        }
    }

    fclose(input_file);
    fclose(output_file);
}

void decrypt_file(FILE *input_file, FILE *output_file, char *key) {
    int ch;
    int key_index = 0;

    while ((ch = fgetc(input_file))!= EOF) {
        if (isalpha(ch)) {
            ch = (ch - 65 - key_index + 26) % 26 + 65;
        } else {
            ch = ch;
        }

        fputc(ch, output_file);

        if (++key_index == MAX_KEY_SIZE) {
            key_index = 0;
        }
    }

    fclose(input_file);
    fclose(output_file);
}

int main() {
    FILE *input_file, *output_file;
    char input_filename[MAX_FILE_SIZE], output_filename[MAX_FILE_SIZE];
    char key[MAX_KEY_SIZE];

    printf("Enter input file name: ");
    scanf("%s", input_filename);

    printf("Enter output file name: ");
    scanf("%s", output_filename);

    printf("Enter encryption key: ");
    scanf("%s", key);

    input_file = fopen(input_filename, "r");
    output_file = fopen(output_filename, "w");

    if (input_file == NULL || output_file == NULL) {
        printf("Error: could not open file.\n");
        exit(1);
    }

    if (strcmp(key, "encrypt") == 0) {
        encrypt_file(input_file, output_file, key);
        printf("File encrypted successfully.\n");
    } else if (strcmp(key, "decrypt") == 0) {
        decrypt_file(input_file, output_file, key);
        printf("File decrypted successfully.\n");
    } else {
        printf("Invalid encryption key.\n");
    }

    fclose(input_file);
    fclose(output_file);

    return 0;
}