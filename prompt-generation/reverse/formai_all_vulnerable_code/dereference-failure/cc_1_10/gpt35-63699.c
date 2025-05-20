//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_KEY_LEN 256
#define MAX_VAL_LEN 256

typedef enum {
    JSON_OBJECT,
    JSON_ARRAY,
    JSON_STRING,
    JSON_NUMBER,
    JSON_BOOLEAN,
    JSON_NULL
} json_type;

typedef struct json_value {
    json_type type;
    union {
        char *str_val;
        double num_val;
        bool bool_val;
        struct json_value *child;
    };
    struct json_value *next;
} json_value;

void skip_whitespace(char **str) {
    while (isspace(**str)) {
        (*str)++;
    }
}

char* parse_string(char **str) {
    skip_whitespace(str);
    char *ret = *str;
    (*str)++;
    while (**str != '\"') {
        (*str)++;
    }
    **str = '\0';
    (*str)++;
    return ret;
}

double parse_number(char **str) {
    skip_whitespace(str);
    char *endptr;
    double ret = strtod(*str, &endptr);
    *str = endptr;
    return ret;
}

bool parse_boolean(char **str) {
    skip_whitespace(str);
    if (**str == 't') {
        *str += 4;
        return true;
    } else {
        *str += 5;
        return false;
    }
}

void parse_value(char **str, json_value *value) {
    skip_whitespace(str);
    switch (**str) {
        case '\"':
            value->type = JSON_STRING;
            value->str_val = parse_string(str);
            break;
        case '-':
        case '0'...'9':
            value->type = JSON_NUMBER;
            value->num_val = parse_number(str);
            break;
        case 't':
        case 'f':
            value->type = JSON_BOOLEAN;
            value->bool_val = parse_boolean(str);
            break;
        case 'n':
            value->type = JSON_NULL;
            *str += 4;
            break;
        case '[':
            value->type = JSON_ARRAY;
            *str += 1;
            value->child = (json_value*)malloc(sizeof(json_value));
            parse_value(str, value->child);
            value->next = (json_value*)malloc(sizeof(json_value));
            parse_value(str, value->next);
            break;
        case '{':
            value->type = JSON_OBJECT;
            *str += 1;
            value->child = (json_value*)malloc(sizeof(json_value));
            char *key = parse_string(str);
            value->child->type = JSON_STRING;
            value->child->str_val = key;
            parse_value(str, value->child->next);
            json_value *cur = value->child->next;
            while (**str != '}') {
                cur->next = (json_value*)malloc(sizeof(json_value));
                cur = cur->next;
                char *key = parse_string(str);
                cur->type = JSON_STRING;
                cur->str_val = key;
                parse_value(str, cur->next);
            }
            *str += 1;
            break;
    }
}

json_value* parse_json(char *str) {
    json_value *root = (json_value*)malloc(sizeof(json_value));
    parse_value(&str, root);
    return root;
}

int main() {
    char *json_str = "{\"name\":\"John\",\"age\":30,\"city\":\"New York\",\"pets\":[{\"name\":\"Fluffy\",\"type\":\"cat\"},{\"name\":\"Fido\",\"type\":\"dog\"}]}";
    json_value *root = parse_json(json_str);
    printf("Name: %s\n", root->child->str_val);
    printf("Age: %.0lf\n", root->child->next->num_val);
    printf("City: %s\n", root->child->next->next->str_val);
    printf("Pets:\n");
    json_value *pets = root->child->next->next->next;
    while (pets) {
        printf("  - %s the %s\n", pets->child->str_val, pets->child->next->str_val);
        pets = pets->next;
    }
    free(root);
    return 0;
}