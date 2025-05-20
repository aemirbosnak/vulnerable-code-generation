//GPT-4o-mini DATASET v1.0 Category: Building a JSON Parser ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_BUFFER 1024
#define MAX_KEY_LENGTH 256

typedef enum {
    JSON_OBJECT,
    JSON_ARRAY,
    JSON_STRING,
    JSON_NUMBER,
    JSON_BOOL,
    JSON_NULL
} JsonType;

typedef struct JsonValue {
    JsonType type;
    union {
        char *stringValue;
        double numberValue;
        int boolValue;
        struct JsonValue *arrayValue;
        struct JsonValue *objectValue;
    } value;
    struct JsonValue *next; // For linked-list structure
} JsonValue;

void skip_whitespace(const char **p) {
    while (isspace(**p)) (*p)++;
}

char *parse_string(const char **p) {
    (*p)++; // skip opening quote
    const char *start = *p;
    while (**p != '"' && **p != '\0') {
        if (**p == '\\') (*p)++; // skip escape character
        (*p)++;
    }
    size_t length = *p - start;
    char *result = malloc(length + 1);
    strncpy(result, start, length);
    result[length] = '\0';
    (*p)++; // skip closing quote
    return result;
}

double parse_number(const char **p) {
    char *end;
    double number = strtod(*p, &end);
    *p = end;
    return number;
}

JsonValue *parse_value(const char **p);

JsonValue *parse_object(const char **p) {
    JsonValue *object = malloc(sizeof(JsonValue));
    object->type = JSON_OBJECT;
    object->next = NULL;

    (*p)++; // skip '{'
    skip_whitespace(p);

    if (**p == '}') {
        (*p)++; // empty object
        return object;
    }

    while (1) {
        JsonValue *keyValue = malloc(sizeof(JsonValue));
        keyValue->type = JSON_STRING;
        keyValue->value.stringValue = parse_string(p);
        skip_whitespace(p);
        if (**p != ':') {
            fprintf(stderr, "Expected ':' after key\n");
            exit(EXIT_FAILURE);
        }
        (*p)++; // skip ':'
        skip_whitespace(p);
        
        keyValue->next = parse_value(p);
        
        keyValue->next->next = object->next; // insert at front
        object->next = keyValue; 

        skip_whitespace(p);
        if (**p == '}') {
            (*p)++;
            break;
        } else if (**p != ',') {
            fprintf(stderr, "Expected ',' or '}'\n");
            exit(EXIT_FAILURE);
        }
        (*p)++; // skip ','
        skip_whitespace(p);
    }
    return object;
}

JsonValue *parse_array(const char **p) {
    JsonValue *array = malloc(sizeof(JsonValue));
    array->type = JSON_ARRAY;
    array->next = NULL;

    (*p)++; // skip '['
    skip_whitespace(p);

    if (**p == ']') {
        (*p)++; // empty array
        return array;
    }

    while (1) {
        JsonValue *value = parse_value(p);
        value->next = array->next; // insert at front
        array->next = value;

        skip_whitespace(p);
        if (**p == ']') {
            (*p)++;
            break;
        } else if (**p != ',') {
            fprintf(stderr, "Expected ',' or ']'\n");
            exit(EXIT_FAILURE);
        }
        (*p)++; // skip ','
        skip_whitespace(p);
    }
    return array;
}

JsonValue *parse_value(const char **p) {
    skip_whitespace(p);
    JsonValue *value = malloc(sizeof(JsonValue));

    if (**p == '"') {
        value->type = JSON_STRING;
        value->value.stringValue = parse_string(p);
    } else if (isdigit(**p) || **p == '-') {
        value->type = JSON_NUMBER;
        value->value.numberValue = parse_number(p);
    } else if (strncmp(*p, "true", 4) == 0) {
        value->type = JSON_BOOL;
        value->value.boolValue = 1; // true
        *p += 4;
    } else if (strncmp(*p, "false", 5) == 0) {
        value->type = JSON_BOOL;
        value->value.boolValue = 0; // false
        *p += 5;
    } else if (strncmp(*p, "null", 4) == 0) {
        value->type = JSON_NULL;
        *p += 4;
    } else if (**p == '{') {
        value = parse_object(p);
    } else if (**p == '[') {
        value = parse_array(p);
    } else {
        fprintf(stderr, "Unexpected character: %c\n", **p);
        exit(EXIT_FAILURE);
    }
    return value;
}

void free_json(JsonValue *value) {
    if (value == NULL) return;
    if (value->type == JSON_STRING) {
        free(value->value.stringValue);
    } else if (value->type == JSON_OBJECT || value->type == JSON_ARRAY) {
        JsonValue *current = value->next;
        while (current) {
            JsonValue *next = current->next;
            free_json(current);
            current = next;
        }
    }
    free(value);
}

void print_json(JsonValue *value) {
    if (!value) return;
    switch (value->type) {
        case JSON_STRING:
            printf("\"%s\"", value->value.stringValue);
            break;
        case JSON_NUMBER:
            printf("%.2f", value->value.numberValue);
            break;
        case JSON_BOOL:
            printf(value->value.boolValue ? "true" : "false");
            break;
        case JSON_NULL:
            printf("null");
            break;
        case JSON_ARRAY:
            printf("[");
            for (JsonValue *current = value->next; current; current = current->next) {
                print_json(current);
                if (current->next) printf(", ");
            }
            printf("]");
            break;
        case JSON_OBJECT:
            printf("{");
            for (JsonValue *current = value->next; current; current = current->next) {
                print_json(current);
                if (current->next) printf(", ");
            }
            printf("}");
            break;
    }
}

int main() {
    const char *json_sample = "{\"name\":\"John\", \"age\":30, \"isStudent\":false, \"courses\":[\"Math\", \"Science\"], \"address\":{\"city\":\"New York\", \"zip\":\"10001\"}}";
    const char *p = json_sample;
    
    JsonValue *parsedJson = parse_value(&p);
    print_json(parsedJson);
    printf("\n");
    
    free_json(parsedJson);
    return 0;
}