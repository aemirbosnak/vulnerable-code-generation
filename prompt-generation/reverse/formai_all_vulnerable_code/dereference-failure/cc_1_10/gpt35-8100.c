//FormAI DATASET v1.0 Category: Syntax parsing ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

//Define struct for token and token list
typedef struct {
    char* type;
    char* value;
} token;

typedef struct {
    token* tokens;
    int size;
    int capacity;
} token_list;

//Initialize token list with default capacity
void init_token_list(token_list* tl) {
    tl->tokens = malloc(sizeof(token) * 10);
    tl->size = 0;
    tl->capacity = 10;
}

//Add new token to token list
void add_token(token_list* tl, token t) {
    if (tl->size == tl->capacity) {
        tl->capacity *= 2;
        tl->tokens = realloc(tl->tokens, sizeof(token) * tl->capacity);
    }
    tl->tokens[tl->size] = t;
    tl->size++;
}

//Parse input string and generate token list
token_list* parse_input(char* input) {
    token_list* tl = malloc(sizeof(token_list));
    init_token_list(tl);
    char* curr_token_value = malloc(sizeof(char) * 10);
    int token_value_size = 0;
    int input_length = strlen(input);
    bool in_string = false;
    for (int i = 0; i < input_length; i++) {
        if (input[i] == '\"') {
            in_string = !in_string;
        }
        if (in_string) {
            curr_token_value[token_value_size] = input[i];
            token_value_size++;
            continue;
        }
        if (input[i] == ' ') {
            if (token_value_size == 0) {
                continue;
            }
            token t = {"STRING", curr_token_value};
            add_token(tl, t);
            curr_token_value = malloc(sizeof(char) * 10);
            token_value_size = 0;
        }
        else {
            curr_token_value[token_value_size] = input[i];
            token_value_size++;
        }
    }
    if (token_value_size > 0) {
        token t = {"STRING", curr_token_value};
        add_token(tl, t);
    }
    return tl;
}

//Print token list
void print_token_list(token_list* tl) {
    printf("[");
    for (int i = 0; i < tl->size; i++) {
        printf("(%s, %s)", tl->tokens[i].type, tl->tokens[i].value);
        if (i != tl->size - 1) {
            printf(", ");
        }
    }
    printf("]\n");
}

int main() {
    char* input_string = "print \"Hello World\"";
    token_list* tl = parse_input(input_string);
    print_token_list(tl);
    free(tl->tokens);
    free(tl);
    return 0;
}