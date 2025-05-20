//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1024
#define MAX_KEY_LENGTH 32
#define MAX_FILE_NAME_LENGTH 256
#define MAX_ENCRYPTED_LINE_LENGTH (MAX_LINE_LENGTH + 1)

typedef struct {
    char *key;
    FILE *input_file;
    FILE *output_file;
} Encryptor;

void encrypt_line(char *line, char *key) {
    int i, j;
    for (i = 0, j = 0; line[i]!= '\0'; i++) {
        if (isalpha(line[i])) {
            line[j] = tolower(line[i]) + key[i % strlen(key)];
            j++;
        }
    }
    line[j] = '\0';
}

void encrypt_file(Encryptor *encryptor) {
    char input_line[MAX_LINE_LENGTH];
    char encrypted_line[MAX_ENCRYPTED_LINE_LENGTH];
    while (fgets(input_line, MAX_LINE_LENGTH, encryptor->input_file)!= NULL) {
        encrypt_line(input_line, encryptor->key);
        strcpy(encrypted_line, input_line);
        fputs(encrypted_line, encryptor->output_file);
    }
}

int main(int argc, char *argv[]) {
    if (argc!= 6) {
        printf("Usage: %s input_file output_file key input_file_name output_file_name\n", argv[0]);
        return 1;
    }
    char *input_file_name = argv[3];
    char *output_file_name = argv[4];
    Encryptor encryptor;
    encryptor.key = argv[2];
    encryptor.input_file = fopen(input_file_name, "r");
    if (encryptor.input_file == NULL) {
        printf("Error: Could not open input file '%s'.\n", input_file_name);
        return 1;
    }
    encryptor.output_file = fopen(output_file_name, "w");
    if (encryptor.output_file == NULL) {
        printf("Error: Could not open output file '%s'.\n", output_file_name);
        fclose(encryptor.input_file);
        return 1;
    }
    encrypt_file(&encryptor);
    fclose(encryptor.input_file);
    fclose(encryptor.output_file);
    return 0;
}