//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LEN 256
#define MAX_KEY_LEN 256

void encrypt_file(FILE* input_file, FILE* output_file, char* key) {
    char input_buffer[MAX_LINE_LEN];
    char output_buffer[MAX_LINE_LEN];
    int key_index = 0;

    while (fgets(input_buffer, MAX_LINE_LEN, input_file)!= NULL) {
        int i = 0;
        for (i = 0; i < strlen(input_buffer); i++) {
            if (isalpha(input_buffer[i])) {
                int char_code = tolower(input_buffer[i]) - 'a';
                char_code = (char_code + key_index) % 26;
                if (isupper(input_buffer[i])) {
                    output_buffer[i] = (char) (char_code + 'A');
                } else {
                    output_buffer[i] = (char) (char_code + 'a');
                }
            } else {
                output_buffer[i] = input_buffer[i];
            }
        }
        key_index = (key_index + 1) % strlen(key);
        fputs(output_buffer, output_file);
    }
}

int main(int argc, char** argv) {
    if (argc!= 4) {
        printf("Usage: %s input_file output_file key\n", argv[0]);
        return 1;
    }

    FILE* input_file = fopen(argv[1], "r");
    if (input_file == NULL) {
        printf("Error: could not open input file\n");
        return 1;
    }

    FILE* output_file = fopen(argv[2], "w");
    if (output_file == NULL) {
        printf("Error: could not open output file\n");
        return 1;
    }

    char* key = argv[3];
    encrypt_file(input_file, output_file, key);

    fclose(input_file);
    fclose(output_file);

    return 0;
}