//Falcon-180B DATASET v1.0 Category: Compression algorithms ; Style: funny
/* C Compression Algorithm */

/* This program compresses a given input file and saves the compressed data to an output file */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Function to read input file and return its contents as a string */
char* readFile(FILE* file) {
    fseek(file, 0, SEEK_END);
    long size = ftell(file);
    rewind(file);
    char* content = malloc(size * sizeof(char));
    fread(content, sizeof(char), size, file);
    fclose(file);
    return content;
}

/* Function to write compressed data to an output file */
void writeFile(char* content, FILE* file) {
    fwrite(content, sizeof(char), strlen(content), file);
    fclose(file);
}

/* Function to compress the input data */
char* compress(char* input) {
    char* output = malloc(strlen(input) * sizeof(char));
    int j = 0;
    for (int i = 0; i < strlen(input); i++) {
        if (input[i]!= input[i + 1]) {
            output[j++] = input[i];
        }
    }
    output[j] = '\0';
    return output;
}

int main() {
    char* inputFile = "input.txt";
    char* outputFile = "output.txt";

    /* Read input file and compress its contents */
    FILE* input = fopen(inputFile, "r");
    if (input == NULL) {
        printf("Error: Could not open input file.\n");
        exit(1);
    }
    char* content = readFile(input);
    char* compressedContent = compress(content);

    /* Write compressed data to output file */
    FILE* output = fopen(outputFile, "w");
    if (output == NULL) {
        printf("Error: Could not open output file.\n");
        exit(1);
    }
    writeFile(compressedContent, output);

    printf("Compression successful!\n");
    return 0;
}