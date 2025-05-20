//GPT-4o-mini DATASET v1.0 Category: Building a JSON Parser ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_BUFFER 1024

typedef enum { JSON_UNDEFINED, JSON_STRING, JSON_NUMBER, JSON_OBJECT, JSON_ARRAY } JsonType;

typedef struct JsonValue {
    JsonType type;
    char *key;
    char *value; // for simplicity, we store strings only
    struct JsonValue *next; // for linked list implementation
} JsonValue;

void trim_whitespace(char **json) {
    while (isspace((unsigned char) **json)) (*json)++;
}

char *parse_string(char **json) {
    char *start = ++(*json); // Skip the opening quote
    while (**json && **json != '"') {
        if (**json == '\\') (*json)++; // Skip the escaped character
        (*json)++;
    }
    if (**json != '"') {
        fprintf(stderr, "Error: Expected closing quote\n");
        exit(EXIT_FAILURE);
    }
    size_t length = *json - start;
    char *string = (char *)malloc(length + 1);
    strncpy(string, start, length);
    string[length] = '\0';
    (*json)++; // Skip the closing quote
    return string;
}

JsonValue *parse_json_object(char **json) {
    JsonValue *head = NULL;
    JsonValue **current = &head;

    if (**json == '{') {
        (*json)++; // Skip '{'
    } else {
        fprintf(stderr, "Error: Expected '{' at start of object\n");
        exit(EXIT_FAILURE);
    }

    while (1) {
        trim_whitespace(json);
        if (**json == '}') {
            (*json)++; // Skip '}'
            break;
        }

        char *key = parse_string(json);
        trim_whitespace(json);
        if (**json != ':') {
            fprintf(stderr, "Error: Expected ':' after key\n");
            exit(EXIT_FAILURE);
        }
        (*json)++; // Skip ':'
        trim_whitespace(json);
        char *value = parse_string(json);

        *current = (JsonValue *)malloc(sizeof(JsonValue));
        (*current)->type = JSON_STRING; // In this example, we only manage string values
        (*current)->key = key;
        (*current)->value = value;
        (*current)->next = NULL;

        current = &((*current)->next);

        trim_whitespace(json);
        if (**json == ',') {
            (*json)++; // Skip ',' for the next pair
        } else if (**json != '}') {
            fprintf(stderr, "Error: Expected ',' or '}' in object\n");
            exit(EXIT_FAILURE);
        }
    }
    return head;
}

void print_json(JsonValue *value) {
    while (value) {
        printf("\"%s\": \"%s\"\n", value->key, value->value);
        value = value->next;
    }
}

void free_json(JsonValue *value) {
    while (value) {
        JsonValue *to_free = value;
        value = value->next;
        free(to_free->key);
        free(to_free->value);
        free(to_free);
    }
}

int main() {
    FILE *file = fopen("data.json", "r");
    if (!file) {
        fprintf(stderr, "Error: Could not open file\n");
        return EXIT_FAILURE;
    }

    char buffer[MAX_BUFFER];
    fread(buffer, sizeof(char), MAX_BUFFER, file);
    fclose(file);

    char *json = buffer;
    JsonValue *root = parse_json_object(&json);
    
    print_json(root);
    free_json(root);

    return EXIT_SUCCESS;
}