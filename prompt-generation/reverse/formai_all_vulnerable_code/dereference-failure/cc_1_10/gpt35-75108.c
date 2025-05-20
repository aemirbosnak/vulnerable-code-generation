//FormAI DATASET v1.0 Category: Syntax parsing ; Style: shocked
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* read_file(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        fprintf(stderr, "Error: Cannot open file %s\n", filename);
        exit(EXIT_FAILURE);
    }

    fseek(file, 0, SEEK_END);
    long size = ftell(file);
    rewind(file);

    char* buffer = malloc(size + 1);
    if (!buffer) {
        fprintf(stderr, "Error: Cannot allocate memory");
        exit(EXIT_FAILURE);
    }

    fread(buffer, 1, size, file);
    fclose(file);

    buffer[size] = '\0';

    return buffer;
}

void parse(const char* filename) {
    char* code = read_file(filename);
    char* token = strtok(code, " \t\n\r");

    while (token != NULL) {
        if (strcmp(token, "int") == 0) {
            printf("Variable declaration: int\n");
        } else if (strcmp(token, "char") == 0) {
            printf("Variable declaration: char\n");
        } else if (strcmp(token, "float") == 0) {
            printf("Variable declaration: float\n");
        } else if (strcmp(token, "for") == 0) {
            printf("For loop statement\n");
        } else if (strcmp(token, "if") == 0) {
            printf("If statement\n");
        }

        token = strtok(NULL, " \t\n\r");
    }

    free(code);
}

int main(int argc, char** argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: ./parser <filename>\n");
        exit(EXIT_FAILURE);
    }

    parse(argv[1]);

    return 0;
}