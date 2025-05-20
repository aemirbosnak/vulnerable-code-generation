//FormAI DATASET v1.0 Category: HTML beautifier ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Declarations
typedef struct {
    int tag;
    char* value;
}Token;

char* readFile(char* filename);
void tokenize(char* input, Token* tokens, int* count);
void beautify(Token* tokens, int count);

// Main
int main(int argc, char** argv) {
    if(argc <= 1) {
        printf("Usage: ./beautify <filename>\n");
        exit(1);
    }

    char* input = readFile(argv[1]);

    Token tokens[100];
    int count = 0;

    tokenize(input, tokens, &count);

    beautify(tokens, count);

    return 0;
}

// Definitions
char* readFile(char* filename) {
    FILE* file = fopen(filename, "r");
    if(file == NULL) {
        printf("Error: File not found: %s\n", filename);
        exit(1);
    }
    fseek(file, 0L, SEEK_END);
    int size = ftell(file);
    rewind(file);
    char* buffer = (char*) malloc(sizeof(char) * size + 1);
    fread(buffer, 1, size, file);
    fclose(file);
    buffer[size] = '\0';

    return buffer;
}

void tokenize(char* input, Token* tokens, int* count) {
    int pos = 0;
    while(input[pos] != '\0') {
        if(input[pos] == '<') {
            Token token;
            token.tag = 0;
            token.value = "";

            int size = 0;
            while(input[pos + size] != '>') {
                ++size;
            }
            ++size;

            token.value = (char*) malloc(sizeof(char) * size);
            token.value[size - 1] = '\0';

            int i;
            for(i = 0 ; i < size - 1 ; ++i) {
                token.value[i] = input[pos + i];
            }

            tokens[*count] = token;
            ++(*count);

            pos += size;
        }
        else if(input[pos] == '/') {
            pos += 2;
        }
        else {
            Token token;
            token.tag = 1;
            token.value = "";

            int size = 0;
            while(input[pos + size] != '<') {
                ++size;
            }

            token.value = (char*) malloc(sizeof(char) * size + 1);
            token.value[size] = '\0';

            int i;
            for(i = 0 ; i < size ; ++i) {
                token.value[i] = input[pos + i];
            }

            tokens[*count] = token;
            ++(*count);

            pos += size;
        }
    }
}

void beautify(Token* tokens, int count) {
    bool indent = false;
    int indent_level = 0;

    int i;
    for(i = 0 ; i < count ; ++i) {
        if(tokens[i].tag == 0) {
            if(tokens[i].value[1] == '/') {
                --indent_level;
            }

            if(indent) {
                int j;
                for(j = 0 ; j < indent_level ; ++j) {
                    printf("    ");
                }
            }

            printf("%s\n", tokens[i].value);

            if(tokens[i].value[1] != '/') {
                ++indent_level;
            }
            indent = true;
        }
        else {
            if(indent) {
                int j;
                for(j = 0 ; j < indent_level ; ++j) {
                    printf("    ");
                }
            }

            printf("%s\n", tokens[i].value);

            indent = false;
        }
    }
}