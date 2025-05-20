//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define KEY_LENGTH 16

void encrypt(char* input_file, char* output_file, char* key) {
    FILE* input = fopen(input_file, "rb");
    if (input == NULL) {
        printf("Error: Could not open input file.\n");
        exit(1);
    }

    FILE* output = fopen(output_file, "wb");
    if (output == NULL) {
        printf("Error: Could not open output file.\n");
        exit(1);
    }

    char key_buffer[KEY_LENGTH];
    memset(key_buffer, 0, KEY_LENGTH);
    strncpy(key_buffer, key, KEY_LENGTH - 1);

    int key_index = 0;
    int buffer_index = 0;
    char buffer[1024];

    while (fread(buffer, 1, 1024, input) > 0) {
        for (int i = 0; i < 1024; i++) {
            char c = buffer[i];
            if (c >= 'A' && c <= 'Z') {
                c = c + (key_buffer[key_index] - 'A');
                if (c > 'Z') {
                    c = c - 26;
                }
            } else if (c >= 'a' && c <= 'z') {
                c = c + (key_buffer[key_index] - 'a');
                if (c > 'z') {
                    c = c - 26;
                }
            } else {
                c = c;
            }

            if (key_index == KEY_LENGTH - 1) {
                key_index = 0;
            } else {
                key_index++;
            }

            buffer[i] = c;
        }

        fwrite(buffer, 1, buffer_index, output);
        buffer_index = 0;
    }

    fclose(input);
    fclose(output);
}

int main() {
    char* input_file;
    char* output_file;
    char* key;

    printf("Enter input file name: ");
    scanf("%s", input_file);

    printf("Enter output file name: ");
    scanf("%s", output_file);

    printf("Enter encryption key: ");
    scanf("%s", key);

    encrypt(input_file, output_file, key);

    printf("Encryption completed successfully.\n");

    return 0;
}