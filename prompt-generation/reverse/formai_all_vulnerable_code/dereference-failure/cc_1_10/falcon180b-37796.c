//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_KEY_LEN 32
#define MAX_FILE_LEN 1000

void encrypt(char* key, char* input_file, char* output_file) {
    FILE* input = fopen(input_file, "r");
    FILE* output = fopen(output_file, "w");

    if (input == NULL || output == NULL) {
        printf("Error: could not open file(s)\n");
        exit(1);
    }

    int key_len = strlen(key);
    int file_len = 0;

    char file_buffer[MAX_FILE_LEN];
    char key_buffer[MAX_KEY_LEN];

    while (fgets(file_buffer, MAX_FILE_LEN, input)!= NULL) {
        file_len += strlen(file_buffer);
    }

    rewind(input);

    int i = 0;
    char encrypted_buffer[MAX_FILE_LEN];

    while (fgets(file_buffer, MAX_FILE_LEN, input)!= NULL) {
        for (int j = 0; j < strlen(file_buffer); j++) {
            if (isalpha(file_buffer[j])) {
                file_buffer[j] = toupper(file_buffer[j]);
            }
        }

        for (int j = 0; j < strlen(file_buffer); j++) {
            char c = file_buffer[j];

            if (isalpha(c)) {
                c = (c + key_buffer[i] - 65) % 26 + 65;
            }

            encrypted_buffer[j] = c;
        }

        encrypted_buffer[strlen(file_buffer)] = '\n';
        fputs(encrypted_buffer, output);

        i = (i + 1) % key_len;
    }

    fclose(input);
    fclose(output);
}

int main(int argc, char* argv[]) {
    if (argc!= 5) {
        printf("Usage: %s <key> <input_file> <output_file>\n", argv[0]);
        exit(1);
    }

    char* key = argv[1];
    char* input_file = argv[2];
    char* output_file = argv[3];

    encrypt(key, input_file, output_file);

    printf("File encrypted successfully\n");
    return 0;
}