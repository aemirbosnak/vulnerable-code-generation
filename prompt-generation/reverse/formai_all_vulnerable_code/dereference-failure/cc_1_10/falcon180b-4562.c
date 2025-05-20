//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define KEY_LENGTH 16
#define BLOCK_SIZE 64

int encrypt(char* input_file, char* output_file, char* key);
int decrypt(char* input_file, char* output_file, char* key);

int main() {
    char input_file[100];
    char output_file[100];
    char key[KEY_LENGTH + 1];

    printf("Enter the input file name: ");
    scanf("%s", input_file);

    printf("Enter the output file name: ");
    scanf("%s", output_file);

    printf("Enter the encryption key: ");
    scanf("%s", key);

    int choice;

    printf("\nDo you want to (E)ncrypt or (D)ecrypt? ");
    scanf("%d", &choice);

    if (choice == 'E' || choice == 'e') {
        encrypt(input_file, output_file, key);
    } else if (choice == 'D' || choice == 'd') {
        decrypt(input_file, output_file, key);
    } else {
        printf("Invalid choice.\n");
        return 1;
    }

    return 0;
}

int encrypt(char* input_file, char* output_file, char* key) {
    FILE* input = fopen(input_file, "rb");
    FILE* output = fopen(output_file, "wb");

    if (input == NULL || output == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    char buffer[BLOCK_SIZE];
    char iv[BLOCK_SIZE];

    fseek(input, 0, SEEK_END);
    long file_size = ftell(input);
    rewind(input);

    fread(iv, BLOCK_SIZE, 1, input);

    for (int i = 0; i < file_size; i += BLOCK_SIZE) {
        fseek(input, i, SEEK_SET);
        fread(buffer, BLOCK_SIZE, 1, input);

        for (int j = 0; j < BLOCK_SIZE; j++) {
            buffer[j] ^= key[j % KEY_LENGTH];
        }

        fwrite(buffer, BLOCK_SIZE, 1, output);
    }

    fclose(input);
    fclose(output);

    return 0;
}

int decrypt(char* input_file, char* output_file, char* key) {
    FILE* input = fopen(input_file, "rb");
    FILE* output = fopen(output_file, "wb");

    if (input == NULL || output == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    char buffer[BLOCK_SIZE];
    char iv[BLOCK_SIZE];

    fseek(input, 0, SEEK_END);
    long file_size = ftell(input);
    rewind(input);

    fread(iv, BLOCK_SIZE, 1, input);

    for (int i = 0; i < file_size; i += BLOCK_SIZE) {
        fseek(input, i, SEEK_SET);
        fread(buffer, BLOCK_SIZE, 1, input);

        for (int j = 0; j < BLOCK_SIZE; j++) {
            buffer[j] ^= key[j % KEY_LENGTH];
        }

        fwrite(buffer, BLOCK_SIZE, 1, output);
    }

    fclose(input);
    fclose(output);

    return 0;
}