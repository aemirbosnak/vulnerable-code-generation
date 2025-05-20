//FormAI DATASET v1.0 Category: Modern Encryption ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
 
/* Function prototypes */
void encrypt(char*, int);
void decrypt(char*, int);
int validateInput(char*);
 
/* Main function */
int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: ./encryption <input_file> <output_file> <key>\n");
        exit(EXIT_FAILURE);
    }
    char *input_file = argv[1];
    char *output_file = argv[2];
    char *key = argv[3];
 
    /* Validate key */
    if (!validateInput(key)) {
        fprintf(stderr, "Invalid key!\n");
        exit(EXIT_FAILURE);
    }
 
    /* Read input file */
    FILE *input = fopen(input_file, "rb");
    if (!input) {
        fprintf(stderr, "Could not open input file!\n");
        exit(EXIT_FAILURE);
    }
    fseek(input, 0, SEEK_END);
    long file_size = ftell(input);
    fseek(input, 0, SEEK_SET);
    char *input_text = malloc(file_size + 1);
    if (!input_text) {
        fprintf(stderr, "Could not allocate memory!\n");
        fclose(input);
        exit(EXIT_FAILURE);
    }
    fread(input_text, 1, file_size, input);
    fclose(input);
    input_text[file_size] = '\0';
 
    /* Encrypt input text */
    encrypt(input_text, atoi(key));
 
    /* Write output file */
    FILE *output = fopen(output_file, "wb");
    if (!output) {
        fprintf(stderr, "Could not open output file!\n");
        free(input_text);
        exit(EXIT_FAILURE);
    }
    fwrite(input_text, 1, file_size, output);
    fclose(output);
    free(input_text);
 
    return 0;
}
 
/* Encryption function */
void encrypt(char *text, int key) {
    int length = strlen(text);
    int rows = (int)ceil(length / (double)key);
    char grid[rows][key];
    int i, j, index = 0;
    for (i = 0; i < rows; i++) {
        for (j = 0; j < key; j++) {
            if (index < length) {
                grid[i][j] = text[index++];
            } else {
                grid[i][j] = ' ';
            }
        }
    }
    index = 0;
    for (j = 0; j < key; j++) {
        for (i = 0; i < rows; i++) {
            text[index++] = grid[i][j];
        }
    }
}
 
/* Decryption function */
void decrypt(char *text, int key) {
    int length = strlen(text);
    int rows = (int)ceil(length / (double)key);
    char grid[rows][key];
    int i, j, index = 0;
    for (j = 0; j < key; j++) {
        for (i = 0; i < rows; i++) {
            grid[i][j] = text[index++];
        }
    }
    index = 0;
    for (i = 0; i < rows; i++) {
        for (j = 0; j < key; j++) {
            if (grid[i][j] != ' ') {
                text[index++] = grid[i][j];
            }
        }
    }
    text[index] = '\0';
}
 
/* Validate input function */
int validateInput(char *input) {
    int length = strlen(input);
    int i;
    for (i = 0; i < length; i++) {
        if (input[i] < '0' || input[i] > '9') {
            return 0;
        }
    }
    return 1;
}