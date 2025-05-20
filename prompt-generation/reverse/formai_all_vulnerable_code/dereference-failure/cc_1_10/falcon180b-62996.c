//Falcon-180B DATASET v1.0 Category: Metadata Extractor ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_TOKENS 100
#define MAX_KEY_LEN 50
#define MAX_VAL_LEN 200

struct token {
    char key[MAX_KEY_LEN];
    char val[MAX_VAL_LEN];
};

struct token tokens[MAX_TOKENS];
int num_tokens = 0;

void add_token(char *key, char *val) {
    if (num_tokens >= MAX_TOKENS) {
        printf("Error: Maximum number of tokens reached\n");
        exit(1);
    }
    strncpy(tokens[num_tokens].key, key, MAX_KEY_LEN);
    strncpy(tokens[num_tokens].val, val, MAX_VAL_LEN);
    num_tokens++;
}

void print_tokens() {
    printf("Tokens:\n");
    for (int i = 0; i < num_tokens; i++) {
        printf("Key: %s\nValue: %s\n", tokens[i].key, tokens[i].val);
    }
}

void parse_line(char *line) {
    char *key = strtok(line, ":");
    char *val = strtok(NULL, ":");

    if (key == NULL || val == NULL) {
        printf("Error: Invalid line format\n");
        exit(1);
    }

    add_token(key, val);
}

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        printf("Usage: %s <input_file> <output_file>\n", argv[0]);
        exit(1);
    }

    FILE *input_file = fopen(argv[1], "r");
    if (input_file == NULL) {
        printf("Error: Could not open input file\n");
        exit(1);
    }

    FILE *output_file = fopen(argv[2], "w");
    if (output_file == NULL) {
        printf("Error: Could not open output file\n");
        exit(1);
    }

    char line[MAX_KEY_LEN + MAX_VAL_LEN + 3]; // 3 for ": "
    while (fgets(line, sizeof(line), input_file)!= NULL) {
        parse_line(line);
    }

    print_tokens();

    fprintf(output_file, "Tokens:\n");
    for (int i = 0; i < num_tokens; i++) {
        fprintf(output_file, "Key: %s\nValue: %s\n", tokens[i].key, tokens[i].val);
    }

    fclose(input_file);
    fclose(output_file);
    return 0;
}