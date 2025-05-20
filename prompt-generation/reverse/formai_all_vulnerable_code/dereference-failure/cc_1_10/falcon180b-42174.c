//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

#define MAX_KEY_LENGTH 100
#define MAX_FILE_NAME_LENGTH 100
#define MAX_FILE_SIZE 1000000

typedef struct {
    char key[MAX_KEY_LENGTH];
    char file_name[MAX_FILE_NAME_LENGTH];
    char encrypted_file_name[MAX_FILE_NAME_LENGTH];
    FILE *file;
    FILE *encrypted_file;
} Encryptor;

void generate_key(Encryptor *encryptor) {
    char key[MAX_KEY_LENGTH];
    int i;

    srand(time(NULL));
    for (i = 0; i < MAX_KEY_LENGTH; i++) {
        key[i] = rand() % 26 + 'a';
    }
    key[MAX_KEY_LENGTH - 1] = '\0';

    strcpy(encryptor->key, key);
}

void encrypt_file(Encryptor *encryptor) {
    char ch;

    encryptor->file = fopen(encryptor->file_name, "r");
    if (encryptor->file == NULL) {
        printf("Error: could not open file %s\n", encryptor->file_name);
        exit(1);
    }

    encryptor->encrypted_file = fopen(encryptor->encrypted_file_name, "w");
    if (encryptor->encrypted_file == NULL) {
        printf("Error: could not create encrypted file %s\n", encryptor->encrypted_file_name);
        exit(1);
    }

    while ((ch = fgetc(encryptor->file))!= EOF) {
        if (isalpha(ch)) {
            ch = toupper(ch);
            ch = (ch - 'A' + encryptor->key[0]) % 26 + 'A';
        }
        fputc(ch, encryptor->encrypted_file);
    }

    fclose(encryptor->file);
    fclose(encryptor->encrypted_file);
}

int main(int argc, char *argv[]) {
    Encryptor encryptor;

    if (argc!= 5) {
        printf("Usage: %s <key> <input_file> <output_file> <encrypted_output_file>\n", argv[0]);
        exit(1);
    }

    strcpy(encryptor.key, argv[1]);
    strcpy(encryptor.file_name, argv[2]);
    strcpy(encryptor.encrypted_file_name, argv[3]);

    generate_key(&encryptor);
    encrypt_file(&encryptor);

    printf("File encrypted successfully!\n");

    return 0;
}