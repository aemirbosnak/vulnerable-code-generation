//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_KEY_SIZE 100
#define MAX_FILE_SIZE 1000000000

void generate_key(char *key) {
    time_t now = time(NULL);
    struct tm *t = localtime(&now);
    strftime(key, MAX_KEY_SIZE, "%Y%m%d%H%M%S", t);
}

void encrypt_file(char *input_file, char *output_file, char *key) {
    FILE *input = fopen(input_file, "rb");
    FILE *output = fopen(output_file, "wb");

    if (input == NULL || output == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    char buffer[MAX_FILE_SIZE];
    int buffer_len = 0;

    while (fread(buffer + buffer_len, 1, MAX_FILE_SIZE - buffer_len, input) > 0) {
        buffer_len += fread(buffer + buffer_len, 1, MAX_FILE_SIZE - buffer_len, input);
    }

    fclose(input);
    fclose(output);

    for (int i = 0; i < buffer_len; i++) {
        char c = buffer[i];
        if (isalpha(c)) {
            c = (c - 'a' + ((int)key[i % strlen(key)] - 'a')) % 26 + 'a';
        }
        fwrite(&c, 1, 1, output);
    }

    fclose(output);
}

int main(int argc, char *argv[]) {
    if (argc!= 4) {
        printf("Usage: %s input_file output_file key\n", argv[0]);
        return 1;
    }

    char input_file[MAX_FILE_SIZE];
    char output_file[MAX_FILE_SIZE];
    char key[MAX_KEY_SIZE];

    strcpy(input_file, argv[1]);
    strcpy(output_file, argv[2]);
    strcpy(key, argv[3]);

    generate_key(key);
    encrypt_file(input_file, output_file, key);

    printf("File encrypted successfully.\n");
    return 0;
}