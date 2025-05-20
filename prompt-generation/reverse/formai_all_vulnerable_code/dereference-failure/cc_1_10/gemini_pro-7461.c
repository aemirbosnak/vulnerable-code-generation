//GEMINI-pro DATASET v1.0 Category: Building a JSON Parser ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define JSON_MAX_TOKENS 1024
#define JSON_MAX_TOKEN_LENGTH 1024

typedef enum {
    JSON_TYPE_NULL,
    JSON_TYPE_BOOL,
    JSON_TYPE_NUMBER,
    JSON_TYPE_STRING,
    JSON_TYPE_ARRAY,
    JSON_TYPE_OBJECT
} JSON_Type;

typedef struct {
    JSON_Type type;
    union {
        int boolean;
        double number;
        char *string;
        struct {
            int size;
            void **elements;
        } array;
        struct {
            int size;
            char **keys;
            void **values;
        } object;
    };
} JSON_Value;

typedef struct {
    int size;
    char **tokens;
} JSON_Tokens;

JSON_Tokens *tokenize(char *json) {
    JSON_Tokens *tokens = malloc(sizeof(JSON_Tokens));
    tokens->size = 0;
    tokens->tokens = malloc(JSON_MAX_TOKENS * sizeof(char *));

    char *token = strtok(json, " ,[]{}:\"");
    while (token != NULL) {
        tokens->tokens[tokens->size++] = strdup(token);
        token = strtok(NULL, " ,[]{}:\"");
    }

    return tokens;
}

JSON_Value *parse_value(JSON_Tokens *tokens, int *index) {
    JSON_Value *value = malloc(sizeof(JSON_Value));

    char *token = tokens->tokens[*index];

    if (strcmp(token, "null") == 0) {
        value->type = JSON_TYPE_NULL;
    } else if (strcmp(token, "true") == 0) {
        value->type = JSON_TYPE_BOOL;
        value->boolean = 1;
    } else if (strcmp(token, "false") == 0) {
        value->type = JSON_TYPE_BOOL;
        value->boolean = 0;
    } else if (token[0] == '-' || (token[0] >= '0' && token[0] <= '9')) {
        value->type = JSON_TYPE_NUMBER;
        value->number = atof(token);
    } else if (token[0] == '"') {
        value->type = JSON_TYPE_STRING;
        value->string = strdup(token + 1);
        value->string[strlen(value->string) - 1] = '\0';
    } else if (token[0] == '[') {
        value->type = JSON_TYPE_ARRAY;
        value->array.size = 0;
        value->array.elements = malloc(JSON_MAX_TOKENS * sizeof(void *));

        (*index)++;
        while (tokens->tokens[*index] != "]") {
            value->array.elements[value->array.size++] = parse_value(tokens, index);
            if (tokens->tokens[*index] == ",") {
                (*index)++;
            }
        }
    } else if (token[0] == '{') {
        value->type = JSON_TYPE_OBJECT;
        value->object.size = 0;
        value->object.keys = malloc(JSON_MAX_TOKENS * sizeof(char *));
        value->object.values = malloc(JSON_MAX_TOKENS * sizeof(void *));

        (*index)++;
        while (tokens->tokens[*index] != "}") {
            char *key = tokens->tokens[*index++];
            if (tokens->tokens[*index] != ":") {
                fprintf(stderr, "Invalid JSON: expected ':' after key\n");
                exit(1);
            }
            (*index)++;
            value->object.keys[value->object.size] = strdup(key);
            value->object.values[value->object.size++] = parse_value(tokens, index);
            if (tokens->tokens[*index] == ",") {
                (*index)++;
            }
        }
    } else {
        fprintf(stderr, "Invalid JSON: unexpected token '%s'\n", token);
        exit(1);
    }

    return value;
}

JSON_Value *parse(char *json) {
    JSON_Tokens *tokens = tokenize(json);
    JSON_Value *value = parse_value(tokens, &tokens->size);
    return value;
}

void print_value(JSON_Value *value, int indent) {
    for (int i = 0; i < indent; i++) {
        printf("    ");
    }

    switch (value->type) {
        case JSON_TYPE_NULL:
            printf("null");
            break;
        case JSON_TYPE_BOOL:
            printf(value->boolean ? "true" : "false");
            break;
        case JSON_TYPE_NUMBER:
            printf("%f", value->number);
            break;
        case JSON_TYPE_STRING:
            printf("\"%s\"", value->string);
            break;
        case JSON_TYPE_ARRAY:
            printf("[\n");
            for (int i = 0; i < value->array.size; i++) {
                print_value(value->array.elements[i], indent + 1);
                if (i < value->array.size - 1) {
                    printf(",\n");
                }
            }
            for (int i = 0; i < indent; i++) {
                printf("    ");
            }
            printf("]");
            break;
        case JSON_TYPE_OBJECT:
            printf("{\n");
            for (int i = 0; i < value->object.size; i++) {
                for (int j = 0; j < indent + 1; j++) {
                    printf("    ");
                }
                printf("\"%s\": ", value->object.keys[i]);
                print_value(value->object.values[i], indent + 1);
                if (i < value->object.size - 1) {
                    printf(",\n");
                }
            }
            for (int i = 0; i < indent; i++) {
                printf("    ");
            }
            printf("}");
            break;
    }

    printf("\n");
}

int main() {
    char *json = "{\"name\": \"John Doe\", \"age\": 30, \"occupation\": \"Software Engineer\"}";

    JSON_Value *value = parse(json);

    print_value(value, 0);

    return 0;
}