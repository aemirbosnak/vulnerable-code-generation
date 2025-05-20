//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_KEY_LENGTH 50
#define MAX_FILE_SIZE 1000000

typedef struct {
    char *filename;
    char *key;
    char *encrypted_filename;
} File;

void generate_random_key(char *key, int length) {
    srand(time(NULL));
    for (int i = 0; i < length; i++) {
        key[i] = rand() % 26 + 'a';
    }
    key[length] = '\0';
}

void encrypt_file(File *file) {
    FILE *input_file, *output_file;
    char buffer[500];
    int key_index = 0;

    input_file = fopen(file->filename, "r");
    if (input_file == NULL) {
        printf("Error: Could not open input file.\n");
        exit(1);
    }

    output_file = fopen(file->encrypted_filename, "w");
    if (output_file == NULL) {
        printf("Error: Could not open output file.\n");
        exit(1);
    }

    while (fgets(buffer, 500, input_file)!= NULL) {
        for (int i = 0; i < strlen(buffer); i++) {
            char letter = toupper(buffer[i]);
            if (isalpha(letter)) {
                int letter_index = letter - 'A';
                char encrypted_letter = ((letter_index + key_index) % 26) + 'A';
                fprintf(output_file, "%c", encrypted_letter);
            } else {
                fprintf(output_file, "%c", letter);
            }
        }
        fprintf(output_file, "\n");
    }

    fclose(input_file);
    fclose(output_file);
}

int main(int argc, char *argv[]) {
    if (argc!= 5) {
        printf("Usage: %s <filename> <key> <encrypted_filename> <encrypt/decrypt>\n", argv[0]);
        exit(1);
    }

    File file;
    strcpy(file.filename, argv[1]);
    strcpy(file.key, argv[2]);
    strcpy(file.encrypted_filename, argv[3]);

    if (strcmp(argv[4], "encrypt") == 0) {
        generate_random_key(file.key, MAX_KEY_LENGTH);
        encrypt_file(&file);
        printf("File encrypted successfully.\n");
    } else if (strcmp(argv[4], "decrypt") == 0) {
        printf("Decryption not implemented.\n");
        exit(1);
    } else {
        printf("Invalid option.\n");
        exit(1);
    }

    return 0;
}