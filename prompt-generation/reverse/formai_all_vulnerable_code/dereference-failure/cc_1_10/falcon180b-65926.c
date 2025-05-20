//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_SIZE 1024
#define MAX_KEY_SIZE 32

void generate_key(char *key, int key_size) {
    int i;
    for (i = 0; i < key_size; i++) {
        key[i] = rand() % 26 + 'A';
    }
    key[key_size] = '\0';
}

void encrypt_file(FILE *input_file, FILE *output_file, char *key) {
    char line[MAX_LINE_SIZE];
    while (fgets(line, MAX_LINE_SIZE, input_file)!= NULL) {
        int i;
        for (i = 0; i < strlen(line); i++) {
            if (isalpha(line[i])) {
                line[i] = tolower(line[i]) - 'a' + 1;
            } else {
                line[i] = line[i];
            }
        }
        line[strlen(line)] = '\0';
        int key_index = 0;
        for (i = 0; i < strlen(line); i++) {
            if (isalpha(line[i])) {
                line[i] = line[i] + key[key_index] - 'a' - 1;
            }
            key_index++;
            if (key_index >= strlen(key)) {
                key_index = 0;
            }
        }
        fputs(line, output_file);
    }
}

int main(int argc, char *argv[]) {
    if (argc!= 4) {
        printf("Usage: %s input_file output_file key\n", argv[0]);
        return 1;
    }
    char input_file_name[MAX_LINE_SIZE];
    strcpy(input_file_name, argv[1]);
    char output_file_name[MAX_LINE_SIZE];
    strcpy(output_file_name, argv[2]);
    char key[MAX_KEY_SIZE];
    generate_key(key, strlen(argv[3]));
    FILE *input_file = fopen(input_file_name, "r");
    if (input_file == NULL) {
        printf("Error opening input file.\n");
        return 1;
    }
    FILE *output_file = fopen(output_file_name, "w");
    if (output_file == NULL) {
        printf("Error opening output file.\n");
        fclose(input_file);
        return 1;
    }
    encrypt_file(input_file, output_file, key);
    fclose(input_file);
    fclose(output_file);
    return 0;
}