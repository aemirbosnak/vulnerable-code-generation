//MISTRAL-7B DATASET v1.0 Category: File Encyptor ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define KEY_LENGTH 25
#define BUFFER_SIZE 1024
#define ROTATION_MAX 26

typedef struct {
    char key[KEY_LENGTH];
    int rotation;
} Encryptor;

void generate_key(Encryptor* encryptor) {
    int i, j;
    char key[KEY_LENGTH];

    for (i = 0; i < KEY_LENGTH; i++) {
        key[i] = 'A' + (rand() % ROTATION_MAX);
    }

    encryptor->rotation = rand() % ROTATION_MAX;
    strcpy(encryptor->key, key);
}

void encrypt_file(FILE* input, FILE* output, Encryptor encryptor) {
    char buffer[BUFFER_SIZE];
    int i;

    for (i = 0; !feof(input); i++) {
        fread(buffer, sizeof(char), BUFFER_SIZE, input);

        for (int j = 0; j < BUFFER_SIZE; j++) {
            if (buffer[j] >= 'A' && buffer[j] <= 'Z') {
                buffer[j] = (char) (((buffer[j] - 'A' + encryptor.rotation) % 26) + 'A');
            }
            if (buffer[j] >= 'a' && buffer[j] <= 'z') {
                buffer[j] = (char) (((buffer[j] - 'a' + encryptor.rotation) % 26) + 'a');
            }
        }

        fwrite(buffer, sizeof(char), BUFFER_SIZE, output);
    }
}

int main(int argc, char* argv[]) {
    srand(time(NULL));
    Encryptor encryptor;
    FILE* input_file = fopen(argv[1], "rb");
    FILE* output_file = fopen(argv[2], "wb");

    if (input_file == NULL || output_file == NULL) {
        fprintf(stderr, "Error opening files\n");
        exit(1);
    }

    generate_key(&encryptor);

    encrypt_file(input_file, output_file, encryptor);

    fclose(input_file);
    fclose(output_file);

    printf("Encryption complete. New file: %s\n", argv[2]);

    return 0;
}