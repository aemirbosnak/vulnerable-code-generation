//FormAI DATASET v1.0 Category: Syntax parsing ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STR_LEN 100
#define MAX_TOKENS 50

int tokenize(char *input_str, char delim, char** tokens){
    int i = 0, j = 0, token_len = 0, num_tokens = 0;

    while(input_str[i] != '\0'){
        if(input_str[i] == delim){
            tokens[num_tokens] = calloc(token_len + 1, sizeof(char));

            for(int k = 0; k < token_len; k++){
                tokens[num_tokens][k] = input_str[i-token_len+k];
            }

            tokens[num_tokens][token_len] = '\0';
            num_tokens++;
            token_len = 0;
        } else {
            token_len++;
        }

        i++;
    }

    tokens[num_tokens] = calloc(token_len + 1, sizeof(char));
    for(int k = 0; k < token_len; k++){
        tokens[num_tokens][k] = input_str[i-token_len+k];
    }
    tokens[num_tokens][token_len] = '\0';
    return num_tokens+1;
}

int main(int argc, char* argv[]){
    char input_str[MAX_STR_LEN];
    printf("Enter an expression: ");
    fgets(input_str, MAX_STR_LEN, stdin);

    char delim = ' ';
    char** tokens = calloc(MAX_TOKENS, sizeof(char*));
    int num_tokens = tokenize(input_str, delim, tokens);

    printf("Number of tokens: %d\n", num_tokens);

    for(int i=0; i<num_tokens; i++){
        printf("Token %d: %s\n", i, tokens[i]);
    }

    for(int i=0; i<num_tokens; i++){
        free(tokens[i]);
    }
    free(tokens);

    return 0;
}