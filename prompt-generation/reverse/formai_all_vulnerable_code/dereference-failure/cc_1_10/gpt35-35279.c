//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_JSON_SIZE 2048
#define MAX_TOKEN_COUNT 1024

typedef enum {
    JSON_INVALID,
    JSON_OBJECT,
    JSON_ARRAY,
    JSON_STRING,
    JSON_NUMBER,
    JSON_TRUE,
    JSON_FALSE,
    JSON_NULL,
} json_type_t;

typedef struct {
    json_type_t type;
    char value[MAX_JSON_SIZE];
} json_token_t;

int tokenize(char *json, json_token_t *tokens) {
    int token_index = 0;
    char *token;
    char *rest = json;
    
    while ((token = strtok_r(rest, " \t\n:", &rest))) {
        json_token_t *tok = &tokens[token_index++];
        
        if (!strcmp(token, "{")) {
            tok->type = JSON_OBJECT;
            strcpy(tok->value, "{");
        } else if (!strcmp(token, "}")) {
            tok->type = JSON_OBJECT;
            strcpy(tok->value, "}");
        } else if (!strcmp(token, "[")) {
            tok->type = JSON_ARRAY;
            strcpy(tok->value, "[");
        } else if (!strcmp(token, "]")) {
            tok->type = JSON_ARRAY;
            strcpy(tok->value, "]");
        } else if (!strcmp(token, "true")) {
            tok->type = JSON_TRUE;
            strcpy(tok->value, "true");
        } else if (!strcmp(token, "false")) {
            tok->type = JSON_FALSE;
            strcpy(tok->value, "false");
        } else if (!strcmp(token, "null")) {
            tok->type = JSON_NULL;
            strcpy(tok->value, "null");
        } else if (token[0] == '\"' && token[strlen(token)-1] == '\"') {
            tok->type = JSON_STRING;
            strncpy(tok->value, token+1, strlen(token)-2);
        } else {
            tok->type = JSON_NUMBER;
            strcpy(tok->value, token);
        }
    }
    
    return token_index;
}

int main() {
    char json_str[MAX_JSON_SIZE] = "{\"name\":\"John Doe\",\"age\":30,\"married\":false,\"children\":[\"Jane\",\"Mark\",\"Sam\"]}";
    json_token_t tokens[MAX_TOKEN_COUNT];
    
    int num_tokens = tokenize(json_str, tokens);
    
    for (int i = 0; i < num_tokens; i++) {
        json_token_t *tok = &tokens[i];
        switch (tok->type) {
            case JSON_OBJECT:
                printf("Object: %s\n", tok->value);
                break;
            case JSON_ARRAY:
                printf("Array: %s\n", tok->value);
                break;
            case JSON_TRUE:
                printf("Boolean True\n");
                break;
            case JSON_FALSE:
                printf("Boolean False\n");
                break;
            case JSON_NULL:
                printf("Null\n");
                break;
            case JSON_STRING:
                printf("String: %s\n", tok->value);
                break;
            case JSON_NUMBER:
                printf("Number: %s\n", tok->value);
                break;
            default:
                printf("Invalid Token\n");
                break;
        }
    }
    
    return 0;
}