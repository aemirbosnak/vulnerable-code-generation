//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_KEY_LENGTH 100
#define MAX_FILE_NAME_LENGTH 1000
#define MAX_ENCRYPTED_FILE_NAME_LENGTH (MAX_FILE_NAME_LENGTH + 5)

void generate_key(char *key) {
    int i;
    for (i = 0; i < MAX_KEY_LENGTH; i++) {
        key[i] = rand() % 26 + 'a';
    }
    key[MAX_KEY_LENGTH - 1] = '\0';
}

void encrypt_file(char *input_file_name, char *output_file_name, char *key) {
    FILE *input_file, *output_file;
    char c;

    input_file = fopen(input_file_name, "rb");
    if (input_file == NULL) {
        printf("Error opening input file: %s\n", input_file_name);
        exit(1);
    }

    output_file = fopen(output_file_name, "wb");
    if (output_file == NULL) {
        printf("Error opening output file: %s\n", output_file_name);
        fclose(input_file);
        exit(1);
    }

    while ((c = fgetc(input_file))!= EOF) {
        if (isalpha(c)) {
            c = (char) ((c - 'a' + key[0]) % 26 + 'a');
        } else if (islower(c)) {
            c = (char) ((c - 'a' + key[0]) % 26 + 'a');
        }

        fputc(c, output_file);
    }

    fclose(input_file);
    fclose(output_file);
}

int main(int argc, char *argv[]) {
    char input_file_name[MAX_FILE_NAME_LENGTH], output_file_name[MAX_ENCRYPTED_FILE_NAME_LENGTH], key[MAX_KEY_LENGTH];

    if (argc!= 3) {
        printf("Usage: %s <input_file_name> <output_file_name>\n", argv[0]);
        exit(1);
    }

    strncpy(input_file_name, argv[1], MAX_FILE_NAME_LENGTH);
    strncpy(output_file_name, argv[2], MAX_ENCRYPTED_FILE_NAME_LENGTH);

    generate_key(key);

    encrypt_file(input_file_name, output_file_name, key);

    printf("File encrypted successfully.\n");

    return 0;
}