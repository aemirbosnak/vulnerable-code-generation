//GPT-4o-mini DATASET v1.0 Category: Building a JSON Parser ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef enum {
    JSON_NULL, JSON_TRUE, JSON_FALSE, JSON_NUMBER, JSON_STRING, JSON_OBJECT, JSON_ARRAY
} JsonType;

typedef struct JsonValue {
    JsonType type;
    union {
        double number;
        char *string;
        struct JsonObject *object;
        struct JsonArray *array;
    } value;
} JsonValue;

typedef struct JsonObject {
    char *key;
    JsonValue *value;
    struct JsonObject *next;
} JsonObject;

typedef struct JsonArray {
    JsonValue *value;
    struct JsonArray *next;
} JsonArray;

// Function declarations
JsonValue *parse_json(const char *json);
JsonValue *parse_value(const char **json);
JsonObject *parse_object(const char **json);
JsonArray *parse_array(const char **json);
char *parse_string(const char **json);
double parse_number(const char **json);
void skip_whitespace(const char **json);
void free_json(JsonValue *value);
void print_json(const JsonValue *value, int indent);

// Main function
int main() {
    const char *json = "{\"name\": \"Alice\", \"age\": 30, \"isStudent\": false, \"courses\": [\"Math\", \"Science\"]}";
    
    JsonValue *value = parse_json(json);
    print_json(value, 0);
    
    free_json(value);
    return 0;
}

// Parse JSON function
JsonValue *parse_json(const char *json) {
    skip_whitespace(&json);
    return parse_value(&json);
}

// Skip whitespace
void skip_whitespace(const char **json) {
    while (isspace(**json)) {
        (*json)++;
    }
}

// Parse value depending on the type
JsonValue *parse_value(const char **json) {
    if (**json == 'n') {
        *json += 4; // Skip "null"
        JsonValue *value = malloc(sizeof(JsonValue));
        value->type = JSON_NULL;
        return value;
    }
    if (**json == 't') {
        *json += 4; // Skip "true"
        JsonValue *value = malloc(sizeof(JsonValue));
        value->type = JSON_TRUE;
        return value;
    }
    if (**json == 'f') {
        *json += 5; // Skip "false"
        JsonValue *value = malloc(sizeof(JsonValue));
        value->type = JSON_FALSE;
        return value;
    }
    if (**json == '\"') {
        JsonValue *value = malloc(sizeof(JsonValue));
        value->type = JSON_STRING;
        value->value.string = parse_string(json);
        return value;
    }
    if (**json == '{') {
        JsonValue *value = malloc(sizeof(JsonValue));
        value->type = JSON_OBJECT;
        value->value.object = parse_object(json);
        return value;
    }
    if (**json == '[') {
        JsonValue *value = malloc(sizeof(JsonValue));
        value->type = JSON_ARRAY;
        value->value.array = parse_array(json);
        return value;
    }
    if (isdigit(**json) || **json == '-') {
        JsonValue *value = malloc(sizeof(JsonValue));
        value->type = JSON_NUMBER;
        value->value.number = parse_number(json);
        return value;
    }
    return NULL; // Unexpected character
}

// Parse object
JsonObject *parse_object(const char **json) {
    JsonObject *head = NULL;
    JsonObject *tail = NULL;

    (*json)++; // Skip '{'
    skip_whitespace(json);

    while (**json != '}') {
        JsonObject *obj = malloc(sizeof(JsonObject));
        obj->key = parse_string(json);
        
        skip_whitespace(json);
        (*json)++; // Skip ':'

        skip_whitespace(json);
        obj->value = parse_value(json);
        obj->next = NULL;

        if (tail) {
            tail->next = obj;
        } else {
            head = obj;
        }
        tail = obj;

        skip_whitespace(json);
        if (**json == ',') {
            (*json)++;
            skip_whitespace(json);
        }
    }

    (*json)++; // Skip '}'
    return head;
}

// Parse array
JsonArray *parse_array(const char **json) {
    JsonArray *head = NULL;
    JsonArray *tail = NULL;

    (*json)++; // Skip '['
    skip_whitespace(json);

    while (**json != ']') {
        JsonArray *element = malloc(sizeof(JsonArray));
        element->value = parse_value(json);
        element->next = NULL;

        if (tail) {
            tail->next = element;
        } else {
            head = element;
        }
        tail = element;

        skip_whitespace(json);
        if (**json == ',') {
            (*json)++;
            skip_whitespace(json);
        }
    }

    (*json)++; // Skip ']'
    return head;
}

// Parse string
char *parse_string(const char **json) {
    (*json)++; // Skip initial '"'
    const char *start = *json;

    while (**json && **json != '\"') {
        (*json)++;
    }
    
    size_t length = *json - start;
    char *result = malloc(length + 1);
    strncpy(result, start, length);
    result[length] = '\0';

    (*json)++; // Skip final '"'
    return result;
}

// Parse number
double parse_number(const char **json) {
    char *end;
    double result = strtod(*json, &end);
    *json = end; // Update pointer to end of number
    return result;
}

// Free JSON value
void free_json(JsonValue *value) {
    if (!value) return;

    if (value->type == JSON_STRING) {
        free(value->value.string);
    } else if (value->type == JSON_OBJECT) {
        JsonObject *obj = value->value.object;
        while (obj) {
            JsonObject *next = obj->next;
            free(obj->key);
            free_json(obj->value);
            free(obj);
            obj = next;
        }
    } else if (value->type == JSON_ARRAY) {
        JsonArray *arr = value->value.array;
        while (arr) {
            JsonArray *next = arr->next;
            free_json(arr->value);
            free(arr);
            arr = next;
        }
    }

    free(value);
}

// Print JSON value (for debugging)
void print_json(const JsonValue *value, int indent) {
    if (!value) return;

    for (int i = 0; i < indent; i++) printf("  ");
    switch (value->type) {
        case JSON_NULL: printf("null\n"); break;
        case JSON_TRUE: printf("true\n"); break;
        case JSON_FALSE: printf("false\n"); break;
        case JSON_NUMBER: printf("%lf\n", value->value.number); break;
        case JSON_STRING: printf("\"%s\"\n", value->value.string); break;
        case JSON_OBJECT: {
            printf("{\n");
            for (JsonObject *obj = value->value.object; obj; obj = obj->next) {
                for (int i = 0; i < indent + 1; i++) printf("  ");
                printf("\"%s\": ", obj->key);
                print_json(obj->value, indent + 1);
            }
            for (int i = 0; i < indent; i++) printf("  ");
            printf("}\n");
            break;
        }
        case JSON_ARRAY: {
            printf("[\n");
            for (JsonArray *arr = value->value.array; arr; arr = arr->next) {
                print_json(arr->value, indent + 1);
            }
            for (int i = 0; i < indent; i++) printf("  ");
            printf("]\n");
            break;
        }
    }
}