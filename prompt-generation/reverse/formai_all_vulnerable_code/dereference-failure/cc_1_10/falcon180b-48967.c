//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_KEY_LENGTH 20
#define MAX_FILE_LENGTH 1000000

void encrypt(char* key, char* input_file, char* output_file) {
    FILE* input = fopen(input_file, "r");
    if (input == NULL) {
        printf("Error opening input file\n");
        exit(1);
    }

    FILE* output = fopen(output_file, "w");
    if (output == NULL) {
        printf("Error opening output file\n");
        exit(1);
    }

    char key_table[MAX_KEY_LENGTH];
    memset(key_table, 0, MAX_KEY_LENGTH);
    int key_length = strlen(key);
    if (key_length > MAX_KEY_LENGTH) {
        printf("Error: Key is too long\n");
        exit(1);
    }

    for (int i = 0; i < key_length; i++) {
        key_table[(int)key[i]] = i;
    }

    char buffer[MAX_FILE_LENGTH];
    int buffer_length = 0;

    while (fgets(buffer + buffer_length, MAX_FILE_LENGTH - buffer_length, input)!= NULL) {
        buffer_length += strlen(buffer + buffer_length);
    }

    rewind(input);

    while (fgets(buffer, MAX_FILE_LENGTH, input)!= NULL) {
        int buffer_index = 0;
        for (int i = 0; i < buffer_length; i++) {
            char c = buffer[i];

            if (isalpha(c)) {
                c = (c - 'a' + key_table[(int)buffer[i]]) % 26 + 'a';
            }

            buffer[buffer_index++] = c;
        }

        fputs(buffer, output);
    }

    fclose(input);
    fclose(output);
}

int main() {
    char key[MAX_KEY_LENGTH];
    char input_file[MAX_FILE_LENGTH];
    char output_file[MAX_FILE_LENGTH];

    printf("Enter the key: ");
    scanf("%s", key);

    printf("Enter the input file name: ");
    scanf("%s", input_file);

    printf("Enter the output file name: ");
    scanf("%s", output_file);

    encrypt(key, input_file, output_file);

    printf("File encrypted successfully\n");

    return 0;
}