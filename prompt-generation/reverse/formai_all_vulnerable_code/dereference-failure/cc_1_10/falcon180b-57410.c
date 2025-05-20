//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_LINE_LENGTH 1000

void generate_key(char *key) {
    int i;
    for (i = 0; i < strlen(key); i++) {
        key[i] = tolower(key[i]);
    }
}

void encrypt_file(FILE *input_file, FILE *output_file, char *key) {
    char input_buffer[MAX_LINE_LENGTH];
    char output_buffer[MAX_LINE_LENGTH];
    int i, j;

    for (i = 0; i < strlen(key); i++) {
        key[i] = tolower(key[i]);
    }

    while (fgets(input_buffer, MAX_LINE_LENGTH, input_file)!= NULL) {
        int input_buffer_length = strlen(input_buffer);
        for (i = 0; i < input_buffer_length; i++) {
            if (isalpha(input_buffer[i])) {
                input_buffer[i] = tolower(input_buffer[i]);
            }
        }

        for (i = 0, j = 0; i < input_buffer_length; i++) {
            if (isalpha(input_buffer[i])) {
                output_buffer[j++] = input_buffer[i] ^ key[i % strlen(key)];
            } else {
                output_buffer[j++] = input_buffer[i];
            }
        }
        output_buffer[j] = '\0';

        fputs(output_buffer, output_file);
    }
}

int main(int argc, char *argv[]) {
    if (argc!= 4) {
        printf("Usage: %s input_file output_file key\n", argv[0]);
        return 1;
    }

    FILE *input_file = fopen(argv[1], "r");
    if (input_file == NULL) {
        printf("Error: could not open input file.\n");
        return 1;
    }

    FILE *output_file = fopen(argv[2], "w");
    if (output_file == NULL) {
        printf("Error: could not open output file.\n");
        fclose(input_file);
        return 1;
    }

    char *key = argv[3];
    generate_key(key);

    encrypt_file(input_file, output_file, key);

    fclose(input_file);
    fclose(output_file);

    printf("File encryption complete.\n");

    return 0;
}