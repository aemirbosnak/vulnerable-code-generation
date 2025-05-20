//GPT-4o-mini DATASET v1.0 Category: Building a JSON Parser ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef enum {
    JSON_NONE,
    JSON_OBJECT,
    JSON_ARRAY,
    JSON_STRING,
    JSON_NUMBER,
    JSON_TRUE,
    JSON_FALSE,
    JSON_NULL
} json_type;

typedef struct json_value {
    json_type type;
    union {
        char *string;
        double number;
        struct json_value *child;
    } u;
    struct json_value *next;
} json_value;

void skip_whitespace(const char **p) {
    while (isspace(**p)) (*p)++;
}

json_value *parse_value(const char **p);
json_value *parse_string(const char **p);
json_value *parse_number(const char **p);
json_value *parse_array(const char **p);
json_value *parse_object(const char **p);
void free_json_value(json_value *value);
void print_json_value(json_value *value, int indent);

json_value *parse_json(const char *json) {
    const char *p = json;
    skip_whitespace(&p);
    json_value *value = parse_value(&p);
    if (value) {
        skip_whitespace(&p);
        if (*p != '\0') {
            free_json_value(value);
            return NULL; // not valid JSON
        }
    }
    return value;
}

json_value *parse_value(const char **p) {
    skip_whitespace(p);
    
    if (**p == '"') return parse_string(p);
    if (**p == '{') return parse_object(p);
    if (**p == '[') return parse_array(p);
    if (isdigit(**p) || **p == '-') return parse_number(p);
    if (strncmp(*p, "true", 4) == 0) {
        *p += 4;
        json_value *value = malloc(sizeof(json_value));
        value->type = JSON_TRUE;
        return value;
    }
    if (strncmp(*p, "false", 5) == 0) {
        *p += 5;
        json_value *value = malloc(sizeof(json_value));
        value->type = JSON_FALSE;
        return value;
    }
    if (strncmp(*p, "null", 4) == 0) {
        *p += 4;
        json_value *value = malloc(sizeof(json_value));
        value->type = JSON_NULL;
        return value;
    }
    return NULL; // invalid JSON
}

json_value *parse_string(const char **p) {
    (*p)++; // skip the opening quote
    const char *start = *p;
    while (**p != '"' && **p != '\0') {
        if (**p == '\\') (*p)++; // skip escape
        (*p)++;
    }
    if (**p == '\0') return NULL; // unterminated string
    size_t length = *p - start;
    json_value *value = malloc(sizeof(json_value));
    value->type = JSON_STRING;
    value->u.string = malloc(length + 1);
    memcpy(value->u.string, start, length);
    value->u.string[length] = '\0';
    (*p)++; // skip the closing quote
    return value;
}

json_value *parse_number(const char **p) {
    char *end;
    json_value *value = malloc(sizeof(json_value));
    value->type = JSON_NUMBER;
    value->u.number = strtod(*p, &end);
    *p = end;
    return value;
}

json_value *parse_array(const char **p) {
    (*p)++; // skip the opening bracket
    json_value *array = malloc(sizeof(json_value));
    array->type = JSON_ARRAY;
    array->next = NULL;
    json_value **current = &array->u.child;

    skip_whitespace(p);
    if (**p == ']') {
        (*p)++; // empty array
        return array;
    }

    while (1) {
        json_value *value = parse_value(p);
        if (!value) {
            free_json_value(array);
            return NULL; // invalid JSON
        }
        *current = value;
        current = &value->next;

        skip_whitespace(p);
        if (**p == ',') {
            (*p)++;
            skip_whitespace(p);
        } else if (**p == ']') {
            (*p)++;
            break;
        } else {
            free_json_value(array);
            return NULL; // invalid JSON
        }
    }
    return array;
}

json_value *parse_object(const char **p) {
    (*p)++; // skip the opening brace
    json_value *object = malloc(sizeof(json_value));
    object->type = JSON_OBJECT;
    object->next = NULL;
    json_value **current = &object->u.child;

    skip_whitespace(p);
    if (**p == '}') {
        (*p)++; // empty object
        return object;
    }

    while (1) {
        json_value *key_value = parse_string(p);
        if (!key_value) {
            free_json_value(object);
            return NULL; // invalid JSON
        }
        
        skip_whitespace(p);
        if (**p != ':') {
            free_json_value(key_value);
            free_json_value(object);
            return NULL; // invalid JSON
        }
        (*p)++;  // skip the colon

        json_value *value = parse_value(p);
        if (!value) {
            free_json_value(key_value);
            free_json_value(object);
            return NULL; // invalid JSON
        }

        // Create a linked list node for the key-value pair
        json_value *pair = malloc(sizeof(json_value));
        pair->type = JSON_OBJECT;
        pair->u.child = key_value;
        key_value->next = value;

        *current = pair;
        current = &pair->next;

        skip_whitespace(p);
        if (**p == ',') {
            (*p)++;
            skip_whitespace(p);
        } else if (**p == '}') {
            (*p)++;
            break;
        } else {
            free_json_value(object);
            return NULL; // invalid JSON
        }
    }

    return object;
}

void free_json_value(json_value *value) {
    if (!value) return;
    if (value->type == JSON_STRING) {
        free(value->u.string);
    } else if (value->type == JSON_OBJECT || value->type == JSON_ARRAY) {
        json_value *child = value->u.child;
        while (child) {
            json_value *next = child->next;
            free_json_value(child);
            child = next;
        }
    }
    free(value);
}

void print_json_value(json_value *value, int indent) {
    if (!value) return;
    for (int i = 0; i < indent; i++) printf("  ");
    switch (value->type) {
        case JSON_STRING:
            printf("\"%s\"\n", value->u.string);
            break;
        case JSON_NUMBER:
            printf("%f\n", value->u.number);
            break;
        case JSON_OBJECT: {
            printf("{\n");
            json_value *child = value->u.child;
            while (child) {
                print_json_value(child, indent + 1);
                child = child->next;
            }
            for (int i = 0; i < indent; i++) printf("  ");
            printf("}\n");
            break;
        }
        case JSON_ARRAY: {
            printf("[\n");
            json_value *child = value->u.child;
            while (child) {
                print_json_value(child, indent + 1);
                child = child->next;
            }
            for (int i = 0; i < indent; i++) printf("  ");
            printf("]\n");
            break;
        }
        case JSON_TRUE:
            printf("true\n");
            break;
        case JSON_FALSE:
            printf("false\n");
            break;
        case JSON_NULL:
            printf("null\n");
            break;
        default:
            break;
    }
}

int main() {
    const char *json_string = "{\"name\": \"John\", \"age\": 30, \"city\": \"New York\", \"isStudent\": false, \"courses\": [\"Math\", \"Science\"], \"address\": null}";
    
    json_value *parsed_json = parse_json(json_string);
    if (parsed_json) {
        printf("Parsed JSON:\n");
        print_json_value(parsed_json, 0);
        free_json_value(parsed_json);
    } else {
        printf("Failed to parse JSON.\n");
    }
    
    return 0;
}