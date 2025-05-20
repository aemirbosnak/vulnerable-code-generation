//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1000

void encrypt(char* input_file, char* output_file, char* key) {
    FILE* input = fopen(input_file, "r");
    if (input == NULL) {
        printf("Error: could not open input file.\n");
        exit(1);
    }

    FILE* output = fopen(output_file, "w");
    if (output == NULL) {
        printf("Error: could not open output file.\n");
        exit(1);
    }

    char line[MAX_LINE_LENGTH];
    char key_char;
    int key_index = 0;

    while (fgets(line, MAX_LINE_LENGTH, input)!= NULL) {
        key_char = toupper(key[key_index]);
        for (int i = 0; i < strlen(line); i++) {
            if (isalpha(line[i])) {
                line[i] = (line[i] + key_char - 65) % 26 + 65;
            }
        }
        fprintf(output, "%s", line);
        key_index++;
        if (key_index >= strlen(key)) {
            key_index = 0;
        }
    }

    fclose(input);
    fclose(output);
}

int main(int argc, char* argv[]) {
    if (argc!= 4) {
        printf("Usage: %s input_file output_file key\n", argv[0]);
        return 1;
    }

    char* input_file = argv[1];
    char* output_file = argv[2];
    char* key = argv[3];

    encrypt(input_file, output_file, key);

    return 0;
}