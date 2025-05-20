//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

typedef enum { 
    JSON_OBJECT, 
    JSON_ARRAY, 
    JSON_NUMBER, 
    JSON_STRING, 
    JSON_TRUE, 
    JSON_FALSE, 
    JSON_NULL 
} json_type;

typedef struct {
    json_type type;
    union {
        char *string_val;
        double number_val;
        struct json_object *object_val;
        struct json_array *array_val;
    };
} json_value;

typedef struct json_object {
    char *key;
    json_value value;
    struct json_object *next;
} json_object;

typedef struct json_array {
    json_value value;
    struct json_array *next;
} json_array;

// Function declarations
json_value parse_value(char **);
json_object *parse_object(char **);
json_array *parse_array(char **);
char *parse_string(char **);
double parse_number(char **);

// Error handling function
void error(char *msg) {
    fprintf(stderr, "%s\n", msg);
    exit(1);
}

// Parse a value from a JSON string
json_value parse_value(char **str) {
    char c = **str;
    switch (c) {
        case '{':
            return (json_value) {JSON_OBJECT, .object_val = parse_object(str)};
        case '[':
            return (json_value) {JSON_ARRAY, .array_val = parse_array(str)};
        case '"':
            return (json_value) {JSON_STRING, .string_val = parse_string(str)};
        case 't':
            if (strncmp(*str, "true", 4) == 0) {
                *str += 4;
                return (json_value) {JSON_TRUE};
            }
            break;
        case 'f':
            if (strncmp(*str, "false", 5) == 0) {
                *str += 5;
                return (json_value) {JSON_FALSE};
            }
            break;
        case 'n':
            if (strncmp(*str, "null", 4) == 0) {
                *str += 4;
                return (json_value) {JSON_NULL};
            }
            break;
        default:
            if (isdigit(c) || c == '-') {
                return (json_value) {JSON_NUMBER, .number_val = parse_number(str)};
            }
    }
    error("Invalid JSON value");
}

// Parse an object from a JSON string
json_object *parse_object(char **str) {
    json_object *head = NULL;
    json_object **tail = &head;
    char c;
    if (**str != '{') 
        error("Expecting '{' to start JSON object");
    (*str)++;
    while ((c = **str) && c != '}') {
        if (c != ',') {
            *tail = malloc(sizeof(json_object));
            (*tail)->next = NULL;
            (*tail)->key = parse_string(str);
            if (**str != ':')
                error("Expecting ':' after JSON object key");
            (*str)++;
            (*tail)->value = parse_value(str);
            tail = &(*tail)->next;
        }
        (*str)++;
    }
    if (c == '\0')
        error("Unterminated JSON object");
    (*str)++;
    return head;
}

// Parse an array from a JSON string
json_array *parse_array(char **str) {
    json_array *head = NULL;
    json_array **tail = &head;
    char c;
    if (**str != '[')
        error("Expecting '[' to start JSON array");
    (*str)++;
    while ((c = **str) && c != ']') {
        if (c != ',') {
            *tail = malloc(sizeof(json_array));
            (*tail)->next = NULL;
            (*tail)->value = parse_value(str);
            tail = &(*tail)->next;
        }
        (*str)++;
    }
    if (c == '\0')
        error("Unterminated JSON array");
    (*str)++;
    return head;
}

// Parse a string from a JSON string
char *parse_string(char **str) {
    char c;
    char *result = NULL;
    if (**str != '\"')
        error("Expecting '\"' to start JSON string");
    (*str)++;
    while ((c = **str) && c != '\"') {
        if (c == '\\') {
            (*str)++;
            c = **str;
            switch (c) {
                case '\"':
                case '\\':
                case '/':
                    result = realloc(result, strlen(result) + 2);
                    result[strlen(result) + 1] = '\0';
                    result[strlen(result)] = c;
                    break;
                case 'b':
                    result = realloc(result, strlen(result) + 2);
                    result[strlen(result) + 1] = '\0';
                    result[strlen(result)] = '\b';
                    break;
                case 'f':
                    result = realloc(result, strlen(result) + 2);
                    result[strlen(result) + 1] = '\0';
                    result[strlen(result)] = '\f';
                    break;
                case 'n':
                    result = realloc(result, strlen(result) + 2);
                    result[strlen(result) + 1] = '\0';
                    result[strlen(result)] = '\n';
                    break;
                case 'r':
                    result = realloc(result, strlen(result) + 2);
                    result[strlen(result) + 1] = '\0';
                    result[strlen(result)] = '\r';
                    break;
                case 't':
                    result = realloc(result, strlen(result) + 2);
                    result[strlen(result) + 1] = '\0';
                    result[strlen(result)] = '\t';
                    break;
                default:
                    error("Invalid escape sequence in JSON string");
            }
        } else {
            result = realloc(result, strlen(result) + 2);
            result[strlen(result) + 1] = '\0';
            result[strlen(result)] = c;
        }
        (*str)++;
    }
    if (c == '\0')
        error("Unterminated JSON string");
    (*str)++;
    return result;
}

// Parse a number from a JSON string
double parse_number(char **str) {
    char *endptr;
    double val = strtod(*str, &endptr);
    if (endptr == *str)
        error("Invalid JSON number");
    *str = endptr;
    return val;
}

int main() {
    char *json_str = "{\"name\": \"John\", \"age\": 30, \"hobbies\": [\"reading\", \"swimming\"], \"isMarried\": false}";
    json_object *obj = parse_object(&json_str);
    // Do something with the parsed object
    printf("JSON object parsed successfully!\n");
    return 0;
}