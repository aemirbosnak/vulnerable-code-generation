//GPT-4o-mini DATASET v1.0 Category: Building a JSON Parser ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_JSON_LENGTH 4096
#define MAX_KEY_LENGTH 256
#define MAX_VALUE_LENGTH 256

typedef enum {
    JSON_OBJECT,
    JSON_ARRAY,
    JSON_STRING,
    JSON_NUMBER,
    JSON_BOOL,
    JSON_NULL
} JsonType;

typedef struct JsonNode {
    JsonType type;
    char key[MAX_KEY_LENGTH];
    char value[MAX_VALUE_LENGTH];
    struct JsonNode *next;
    struct JsonNode *child;
} JsonNode;

void skip_whitespace(char **json) {
    while (**json && isspace(**json)) (*json)++;
}

JsonNode *create_json_node() {
    JsonNode *node = (JsonNode *)malloc(sizeof(JsonNode));
    node->next = NULL;
    node->child = NULL;
    return node;
}

void parse_string(char **json, char *buffer) {
    (*json)++; // skip the opening quote
    char *ptr = buffer;
    while (**json && **json != '\"') {
        if (**json == '\\') (*json)++; // skip escape character
        *ptr++ = **json; // copy the character
        (*json)++;
    }
    *ptr = '\0'; // null-terminate the string
    (*json)++; // skip the closing quote
}

double parse_number(char **json) {
    char *end;
    double value = strtod(*json, &end);
    *json = end; // move the pointer
    return value;
}

void parse_key_value_pair(char **json, JsonNode *node) {
    char key[MAX_KEY_LENGTH];
    char value[MAX_VALUE_LENGTH];

    skip_whitespace(json);
    parse_string(json, key);

    skip_whitespace(json);
    (*json)++; // skip the colon

    skip_whitespace(json);
    if (**json == '\"') {
        parse_string(json, value);
        node->type = JSON_STRING;
    } else if (isdigit(**json) || **json == '-' || **json == '.') {
        sprintf(value, "%lf", parse_number(json));
        node->type = JSON_NUMBER;
    } else if (strncmp(*json, "true", 4) == 0) {
        strcpy(value, "true");
        node->type = JSON_BOOL;
        *json += 4;
    } else if (strncmp(*json, "false", 5) == 0) {
        strcpy(value, "false");
        node->type = JSON_BOOL;
        *json += 5;
    } else if (strncmp(*json, "null", 4) == 0) {
        strcpy(value, "null");
        node->type = JSON_NULL;
        *json += 4;
    } else {
        return; // Error handling can be placed here
    }
    strcpy(node->key, key);
    strcpy(node->value, value);
}

JsonNode *parse_json(char **json) {
    JsonNode *root = create_json_node();
    JsonNode *current = root;

    skip_whitespace(json);
    if (**json == '{') {
        (*json)++; // skip the opening brace
        while (**json && **json != '}') {
            JsonNode *new_node = create_json_node();
            parse_key_value_pair(json, new_node);

            if (current->child == NULL) {
                current->child = new_node;
            } else {
                current->next = new_node;
            }
            current = new_node;

            skip_whitespace(json);
            if (**json == ',') {
                (*json)++; // skip the comma
            }
        }
        (*json)++; // skip the closing brace
    }
    return root;
}

void print_json(JsonNode *node, int level) {
    while (node) {
        for (int i = 0; i < level; i++) printf("  ");
        printf("\"%s\": ", node->key);
        printf("%s\n", node->value);
        print_json(node->child, level + 1);
        node = node->next;
    }
}

void free_json(JsonNode *node) {
    while (node) {
        free_json(node->child);
        JsonNode *next = node->next;
        free(node);
        node = next;
    }
}

int main() {
    char json_string[MAX_JSON_LENGTH] = "{\"name\":\"John\", \"age\":30, \"is_student\":false, \"courses\":[\"Math\",\"Science\"]}";
    char *json = json_string;

    JsonNode *json_tree = parse_json(&json);
    printf("Parsed JSON:\n");
    print_json(json_tree, 0);

    free_json(json_tree);
    return 0;
}