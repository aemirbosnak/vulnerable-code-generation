//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_JSON_SIZE 1024

typedef enum {
    JSON_OBJECT,
    JSON_ARRAY,
    JSON_STRING,
    JSON_NUMBER,
    JSON_BOOLEAN,
    JSON_NULL
} json_type_t;

typedef struct json_value_t {
    json_type_t type;
    union {
        char *str_value;
        double num_value;
        int bool_value;
        struct json_node_t *jsonData;
    } data;
} json_value_t;

typedef struct json_node_t {
    char *key;
    json_value_t val;
    struct json_node_t *next;
} json_node_t;

typedef struct json_t {
    json_node_t *root;
} json_t;

json_t* parse_json(char *str);

static char peek_char(char** str) {
    return **str;
}

static char next_char(char** str) {
    return *(*str)++;
}

static void skip_spaces(char **str) {
    while (**str == ' ' || **str == '\t' || **str == '\n' || **str == '\r') {
        (*str)++;
    }
}

static void skip_whitespace(char **str) {
    skip_spaces(str);
    while (*(*str) == '/' && *(*str + 1) == '/') { // Ignore single line comments
        while (**str != '\n') (*str)++;
        (*str)++;
        skip_spaces(str);
    }
    while ((*(*str) == '/' && *(*str + 1) == '*')) { // Ignore multi-line comments
        *str += 2;
        while (*(*str) != '*' || *(*str + 1) != '/') {
            (*str)++;
        }
        *str += 2;
        skip_spaces(str);
    }
}

static char* parse_string(char **str) {
    char *result = NULL;
    if (peek_char(str) == '"') {
        (*str)++;
        char *start = *str;
        while (**str && **str != '"') {
            (*str)++;
        }
        if (**str == '"') {
            int size = *str - start;
            result = malloc(sizeof(char) * (size + 1));
            memcpy(result, start, size);
            result[size] = '\0';
            (*str)++;
        }
    }
    return result;
}

static double parse_number(char **str) {
    char *end;
    double val = strtod(*str, &end);
    if (end != *str) {
        *str = end;
    }
    return val;
}

static json_value_t* parse_value(char **str) {
    skip_whitespace(str);
    json_value_t *result = malloc(sizeof(json_value_t));
    switch (peek_char(str)) {
        case 'n': // null
            *str += 4;
            result->type = JSON_NULL;
            break;
        case 't': // true
            *str += 4;
            result->type = JSON_BOOLEAN;
            result->data.bool_value = 1;
            break;
        case 'f': // false
            *str += 5;
            result->type = JSON_BOOLEAN;
            result->data.bool_value = 0;
            break;
        case '"': // string
            result->type = JSON_STRING;
            result->data.str_value = parse_string(str);
            break;
        case '-': // number
        case '0' ... '9':
            result->type = JSON_NUMBER;
            result->data.num_value = parse_number(str);
            break;
        case '{': // object
            result->type = JSON_OBJECT;
            result->data.jsonData = malloc(sizeof(json_node_t));
            result->data.jsonData->key = NULL;
            result->data.jsonData->next = NULL;
            json_node_t *current = result->data.jsonData;
            (*str)++;
            while (peek_char(str) != '}') {
                skip_whitespace(str);
                if (peek_char(str) == '"') {
                    current->key = parse_string(str);
                }
                skip_whitespace(str);
                if (peek_char(str) == ':') {
                    (*str)++;
                }
                current->val = *parse_value(str);
                skip_whitespace(str);
                if (peek_char(str) == ',') {
                    json_node_t *next = malloc(sizeof(json_node_t));
                    next->key = NULL;
                    next->next = NULL;
                    current->next = next;
                    current = next;
                    (*str)++;
                }
            }
            (*str)++;
            break;
        case '[': // array
            result->type = JSON_ARRAY;
            json_node_t *arrayData = malloc(sizeof(json_node_t));
            arrayData->next = NULL;
            arrayData->key = NULL;
            result->data.jsonData = arrayData;
            current = arrayData;
            (*str)++;
            while (peek_char(str) != ']') {
                current->val = *parse_value(str);
                if (peek_char(str) == ',') {
                    json_node_t *next = malloc(sizeof(json_node_t));
                    next->key = NULL;
                    next->next = NULL;
                    current->next = next;
                    current = next;
                    (*str)++;
                }
            }
            (*str)++;
            break;
        default:
            free(result);
            return NULL;
    }
    return result;
}

json_t* parse_json(char *str) {
    json_t *result = malloc(sizeof(json_t));
    result->root = NULL;
    char *current = str;
    if (*current == '{') { // Parse object
        result->root = malloc(sizeof(json_node_t));
        result->root->key = NULL;
        result->root->next = NULL;
        (*current)++;
        json_node_t *currentNode = result->root;
        while (*current != '}') {
            skip_whitespace(&current);
            if (*current == '"') {
                currentNode->key = parse_string(&current);
            }
            skip_whitespace(&current);
            if (*current == ':') {
                current++;
            }
            currentNode->val = *parse_value(&current);
            skip_whitespace(&current);
            if (*current == ',') {
                json_node_t *nextNode = malloc(sizeof(json_node_t));
                nextNode->key = NULL;
                nextNode->next = NULL;
                currentNode->next = nextNode;
                currentNode = nextNode;
                current++;
            }
        }
    }
    return result;
}

int main() {
    char json[MAX_JSON_SIZE] = "{ \"name\": \"John\", \"age\": 30, \"city\": \"New York\" }";
    json_t *parsed = parse_json(json);
    json_node_t *current = parsed->root;
    while (current != NULL) {
        printf("%s = ", current->key);
        switch(current->val.type) {
            case JSON_STRING:
                printf("'%s'", current->val.data.str_value);
                break;
            case JSON_NUMBER:
                printf("%f", current->val.data.num_value);
                break;
            case JSON_BOOLEAN:
                printf("%s", current->val.data.bool_value ? "true" : "false");
                break;
            case JSON_NULL:
                printf("null");
                break;
            case JSON_ARRAY:
            case JSON_OBJECT:
                printf("TODO");
                break;
        }
        printf("\n");
        current = current->next;
    }
    return 0;
}