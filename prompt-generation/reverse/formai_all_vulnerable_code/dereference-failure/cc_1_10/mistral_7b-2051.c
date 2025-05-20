//MISTRAL-7B DATASET v1.0 Category: Modern Encryption ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define KEY_SIZE 25
#define DATA_SIZE 50
#define BLOCK_SIZE 5

void generate_key(char key[KEY_SIZE]);
void print_matrix(char matrix[KEY_SIZE][KEY_SIZE]);
void encrypt(char data[DATA_SIZE], char key[KEY_SIZE]);
void decrypt(char data[DATA_SIZE], char key[KEY_SIZE]);

int main(void) {
    char data[DATA_SIZE] = "Welcome to my unique encryption program!";
    char key[KEY_SIZE];
    generate_key(key);

    printf("\nOriginal data: %s\n", data);

    encrypt(data, key);
    printf("\nEncrypted data: %s\n", data);

    decrypt(data, key);
    printf("\nDecrypted data: %s\n", data);

    return 0;
}

void generate_key(char key[KEY_SIZE]) {
    int i, j;
    for (i = 0; i < KEY_SIZE; i++) {
        key[i] = 'A' + (rand() % 26);
    }
}

void print_matrix(char matrix[KEY_SIZE][KEY_SIZE]) {
    int i, j;
    for (i = 0; i < KEY_SIZE; i++) {
        for (j = 0; j < KEY_SIZE; j++) {
            printf("%c ", matrix[i][j]);
        }
        printf("\n");
    }
}

void encrypt(char data[DATA_SIZE], char key[KEY_SIZE]) {
    char matrix[KEY_SIZE][KEY_SIZE];
    int i, j, data_i = 0, data_j = 0;

    for (i = 0; i < KEY_SIZE; i++) {
        for (j = 0; j < KEY_SIZE; j++) {
            matrix[i][j] = key[i * BLOCK_SIZE + j / BLOCK_SIZE] ^ data[data_i];
            data_i++;
            if (data_i >= DATA_SIZE) break;
        }
    }

    print_matrix(matrix);

    for (i = 0; i < KEY_SIZE; i++) {
        for (j = 0; j < KEY_SIZE; j++) {
            data[i * KEY_SIZE + j] = matrix[i][j];
        }
    }
}

void decrypt(char data[DATA_SIZE], char key[KEY_SIZE]) {
    char matrix[KEY_SIZE][KEY_SIZE];
    int i, j, data_i = 0, data_j = 0;

    for (i = 0; i < KEY_SIZE; i++) {
        for (j = 0; j < KEY_SIZE; j++) {
            matrix[i][j] = key[i * BLOCK_SIZE + j / BLOCK_SIZE];
        }
    }

    for (i = 0; i < KEY_SIZE; i++) {
        for (j = 0; j < KEY_SIZE; j++) {
            data[data_j] = data[data_j] ^ matrix[i][j];
            data_j++;
            if (data_j >= DATA_SIZE) break;
        }
    }
}