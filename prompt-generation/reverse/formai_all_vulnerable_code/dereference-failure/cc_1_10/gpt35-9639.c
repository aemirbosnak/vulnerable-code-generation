//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct {
    int type;
    char* value;
} Token;

char* read_file(char* filename);
Token* tokenize(char* input);
char* parse_json(Token* tokens);

int main(int argc, char** argv) {
    if (argc != 2) {
        printf("Usage: json_parser filename.json\n");
        return 1;
    }

    char* input = read_file(argv[1]);
    Token* tokens = tokenize(input);

    char* output = parse_json(tokens);
    printf("%s", output);

    free(input);
    free(output);
    free(tokens);
    return 0;
}

char* read_file(char* filename) {
    FILE* fp = fopen(filename, "r");
    if (!fp) {
        printf("Error: could not open file %s.\n", filename);
        exit(1);
    }

    fseek(fp, 0, SEEK_END);
    long size = ftell(fp);
    rewind(fp);

    char* buffer = malloc(size + 1);
    fread(buffer, size, sizeof(char), fp);
    buffer[size] = '\0';

    fclose(fp);
    return buffer;
}

Token* tokenize(char* input) {
    Token* tokens = malloc(sizeof(Token));
    int size = 1;

    char* start = input;
    while (*start != '\0') {
        if (*start == '{') {
            tokens[size-1].type = 1;
            tokens[size-1].value = malloc(2);
            strcpy(tokens[size-1].value, "{");
            size++;
            tokens = realloc(tokens, size * sizeof(Token));
        } else if (*start == '}') {
            tokens[size-1].type = 2;
            tokens[size-1].value = malloc(2);
            strcpy(tokens[size-1].value, "}");
            size++;
            tokens = realloc(tokens, size * sizeof(Token));
        } else if (*start == '"') {
            char* end = start+1;
            while (*end != '"') {
                end++;
            }
            int len = end - start + 2;
            tokens[size-1].type = 3;
            tokens[size-1].value = malloc(len);
            strncpy(tokens[size-1].value, start, len);
            size++;
            tokens = realloc(tokens, size * sizeof(Token));
            start = end+1;
        } else if (isdigit(*start)) {
            char* end = start+1;
            while (isdigit(*end) || *end == '.') {
                end++;
            }
            int len = end - start + 1;
            tokens[size-1].type = 4;
            tokens[size-1].value = malloc(len);
            strncpy(tokens[size-1].value, start, len);
            size++;
            tokens = realloc(tokens, size * sizeof(Token));
            start = end;
        } else {
            start++;
        }
    }

    tokens[size-1].type = 0;
    tokens[size-1].value = malloc(1);
    strcpy(tokens[size-1].value, "");
    return tokens;
}

char* parse_json(Token* tokens) {
    int i = 0;
    char* output = malloc(1024);
    strcpy(output, "{\n");
    while (tokens[i].type != 0) {
        if (tokens[i].type == 1) {
            strcat(output, "{\n");
        } else if (tokens[i].type == 2) {
            strcat(output, "}\n");
        } else if (tokens[i].type == 3) {
            strcat(output, "\t\"");
            strcat(output, tokens[i].value+1);
            strcat(output, "\": ");
        } else if (tokens[i].type == 4) {
            strcat(output, tokens[i].value);
            strcat(output, ",\n");
        }
        i++;
    }
    strcat(output, "}\n");
    return output;
}