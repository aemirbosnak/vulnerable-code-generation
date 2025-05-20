//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_FILE_SIZE 1000000
#define KEY_SIZE 16

typedef struct {
    char* input_file;
    char* output_file;
    char* key;
} Config;

void generate_key(char* key) {
    for (int i = 0; i < KEY_SIZE; i++) {
        key[i] = rand() % 26 + 'a';
    }
    key[KEY_SIZE] = '\0';
}

void encrypt_file(Config config) {
    FILE* input_file = fopen(config.input_file, "rb");
    if (input_file == NULL) {
        printf("Error opening input file.\n");
        exit(1);
    }

    FILE* output_file = fopen(config.output_file, "wb");
    if (output_file == NULL) {
        printf("Error opening output file.\n");
        exit(1);
    }

    char buffer[1024];
    char key[KEY_SIZE + 1] = {0};
    generate_key(key);

    while (fread(buffer, 1, 1024, input_file) > 0) {
        for (int i = 0; i < strlen(buffer); i++) {
            char c = toupper(buffer[i]);
            if (isalpha(c)) {
                int index = (int)c - 65;
                buffer[i] = (char)((index + (int)key[index % KEY_SIZE]) % 26 + 65);
            }
        }
        fwrite(buffer, 1, strlen(buffer), output_file);
    }

    fclose(input_file);
    fclose(output_file);
}

int main(int argc, char* argv[]) {
    if (argc!= 5) {
        printf("Usage: %s input_file output_file key_size key\n", argv[0]);
        exit(1);
    }

    Config config = {
       .input_file = argv[1],
       .output_file = argv[2],
       .key = argv[4]
    };

    int key_size = atoi(argv[3]);
    if (key_size > KEY_SIZE) {
        printf("Error: Key size must be less than or equal to 16.\n");
        exit(1);
    }

    strncpy(config.key, argv[4], key_size);
    encrypt_file(config);

    return 0;
}