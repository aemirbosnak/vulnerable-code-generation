//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_KEY_SIZE 100
#define MAX_FILE_SIZE 1000000

typedef struct {
    char key[MAX_KEY_SIZE];
    int key_length;
    int num_rounds;
} encryption_params;

void generate_random_key(char* key, int key_length) {
    srand(time(NULL));
    for (int i = 0; i < key_length; i++) {
        key[i] = rand() % 26 + 'A';
    }
    key[key_length] = '\0';
}

void encrypt_file(FILE* input_file, FILE* output_file, encryption_params* params) {
    char buffer[MAX_FILE_SIZE];
    char key[MAX_KEY_SIZE];
    int key_length = params->key_length;
    int num_rounds = params->num_rounds;

    for (int i = 0; i < key_length; i++) {
        key[i] = params->key[i];
    }
    key[key_length] = '\0';

    while (fread(buffer, sizeof(char), MAX_FILE_SIZE, input_file)!= 0) {
        for (int i = 0; i < strlen(buffer); i++) {
            if (isalpha(buffer[i])) {
                int ascii_value = buffer[i] + 65;
                int key_index = ascii_value % key_length;
                int encrypted_ascii_value = (ascii_value + key[key_index] - 65) % 26 + 65;
                buffer[i] = encrypted_ascii_value;
            }
        }
        fwrite(buffer, sizeof(char), strlen(buffer), output_file);
    }
}

int main(int argc, char* argv[]) {
    if (argc!= 5) {
        printf("Usage: %s input_file output_file key_length num_rounds\n", argv[0]);
        return 1;
    }

    FILE* input_file = fopen(argv[1], "rb");
    if (input_file == NULL) {
        printf("Error: Could not open input file.\n");
        return 1;
    }

    FILE* output_file = fopen(argv[2], "wb");
    if (output_file == NULL) {
        printf("Error: Could not open output file.\n");
        fclose(input_file);
        return 1;
    }

    int key_length = atoi(argv[3]);
    if (key_length <= 0 || key_length > MAX_KEY_SIZE) {
        printf("Error: Invalid key length.\n");
        fclose(input_file);
        fclose(output_file);
        return 1;
    }

    int num_rounds = atoi(argv[4]);
    if (num_rounds <= 0) {
        printf("Error: Invalid number of rounds.\n");
        fclose(input_file);
        fclose(output_file);
        return 1;
    }

    encryption_params params;
    params.key_length = key_length;
    params.num_rounds = num_rounds;
    generate_random_key(params.key, key_length);

    encrypt_file(input_file, output_file, &params);

    fclose(input_file);
    fclose(output_file);

    return 0;
}