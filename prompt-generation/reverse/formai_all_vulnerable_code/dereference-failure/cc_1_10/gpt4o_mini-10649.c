//GPT-4o-mini DATASET v1.0 Category: Building a JSON Parser ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

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
        char *string_value;
        double number_value;
        int boolean_value;
        struct JsonValue *array_value;
        struct JsonKeyValuePair *object_value;
    } value;
    struct JsonValue *next;
} JsonValue;

typedef struct JsonKeyValuePair {
    char *key;
    JsonValue *value;
    struct JsonKeyValuePair *next;
} JsonKeyValuePair;

JsonValue *parse_json(const char *json);
void skip_whitespace(const char **json);
JsonValue *parse_value(const char **json);
JsonValue *parse_object(const char **json);
JsonValue *parse_array(const char **json);
JsonValue *parse_string(const char **json);
JsonValue *parse_number(const char **json);
JsonValue *parse_boolean(const char **json);
JsonValue *parse_null(const char **json);
void free_json(JsonValue *value);
void print_json(const JsonValue *value, int indent);

int main() {
    const char *json_text = "{\"name\": \"John\", \"age\": 30, \"is_student\": false, \"courses\": [\"Math\", \"Science\"], \"address\": null}";
    JsonValue *parsed_json = parse_json(json_text);
    
    if (parsed_json) {
        print_json(parsed_json, 0);
        free_json(parsed_json);
    } else {
        printf("Failed to parse JSON.\n");
    }
    
    return 0;
}

JsonValue *parse_json(const char *json) {
    skip_whitespace(&json);
    return parse_value(&json);
}

void skip_whitespace(const char **json) {
    while (isspace(**json)) {
        (*json)++;
    }
}

JsonValue *parse_value(const char **json) {
    skip_whitespace(json);
    JsonValue *value = NULL;

    if (**json == '{') {
        value = parse_object(json);
    } else if (**json == '[') {
        value = parse_array(json);
    } else if (**json == '"') {
        value = parse_string(json);
    } else if (isdigit(**json) || **json == '-') {
        value = parse_number(json);
    } else if (strncmp(*json, "true", 4) == 0 || strncmp(*json, "false", 5) == 0) {
        value = parse_boolean(json);
    } else if (strncmp(*json, "null", 4) == 0) {
        value = parse_null(json);
    }

    return value;
}

JsonValue *parse_object(const char **json) {
    JsonValue *object = malloc(sizeof(JsonValue));
    object->type = JSON_OBJECT;
    object->value.object_value = NULL;
    JsonKeyValuePair **current = &object->value.object_value;

    (*json)++; // skip '{'
    skip_whitespace(json);

    while (**json != '}') {
        JsonKeyValuePair *pair = malloc(sizeof(JsonKeyValuePair));
        skip_whitespace(json);
        pair->key = parse_string(json)->value.string_value;

        skip_whitespace(json);
        (*json)++; // skip ':'
        
        skip_whitespace(json);
        pair->value = parse_value(json);
        
        skip_whitespace(json);
        pair->next = NULL;
        *current = pair;
        current = &pair->next;

        if (**json == ',') {
            (*json)++;
            skip_whitespace(json);
        }
    }

    (*json)++; // skip '}'
    return object;
}

JsonValue *parse_array(const char **json) {
    JsonValue *array = malloc(sizeof(JsonValue));
    array->type = JSON_ARRAY;
    array->value.array_value = NULL;
    JsonValue **current = &array->value.array_value;

    (*json)++; // skip '['
    skip_whitespace(json);

    while (**json != ']') {
        JsonValue *item = parse_value(json);
        *current = item;

        current = &item->next;

        skip_whitespace(json);
        if (**json == ',') {
            (*json)++;
            skip_whitespace(json);
        }
    }

    (*json)++; // skip ']'
    return array;
}

JsonValue *parse_string(const char **json) {
    JsonValue *value = malloc(sizeof(JsonValue));
    value->type = JSON_STRING;
    
    (*json)++; // skip '"'
    const char *start = *json;

    while (**json != '"') {
        if (**json == '\0') {
            fprintf(stderr, "Unexpected end of string\n");
            free(value);
            return NULL;
        }
        (*json)++;
    }

    value->value.string_value = strndup(start, *json - start);
    (*json)++; // skip '"'
    return value;
}

JsonValue *parse_number(const char **json) {
    JsonValue *value = malloc(sizeof(JsonValue));
    value->type = JSON_NUMBER;
    
    char *end;
    value->value.number_value = strtod(*json, &end);
    *json = end;

    return value;
}

JsonValue *parse_boolean(const char **json) {
    JsonValue *value = malloc(sizeof(JsonValue));
    value->type = JSON_BOOL;

    if (strncmp(*json, "true", 4) == 0) {
        value->value.boolean_value = 1;
        *json += 4; // move past "true"
    } else {
        value->value.boolean_value = 0;
        *json += 5; // move past "false"
    }

    return value;
}

JsonValue *parse_null(const char **json) {
    JsonValue *value = malloc(sizeof(JsonValue));
    value->type = JSON_NULL;
    
    *json += 4; // move past "null"
    return value;
}

void free_json(JsonValue *value) {
    if (!value) return;

    switch (value->type) {
        case JSON_STRING:
            free(value->value.string_value);
            break;
        case JSON_ARRAY:
            {
                JsonValue *array_item = value->value.array_value;
                while (array_item) {
                    JsonValue *next_item = array_item->next;
                    free_json(array_item);
                    array_item = next_item;
                }
            }
            break;
        case JSON_OBJECT:
            {
                JsonKeyValuePair *pair = value->value.object_value;
                while (pair) {
                    JsonKeyValuePair *next_pair = pair->next;
                    free(pair->key);
                    free_json(pair->value);
                    free(pair);
                    pair = next_pair;
                }
            }
            break;
        default:
            break;
    }

    free(value);
}

void print_json(const JsonValue *value, int indent) {
    if (!value) return;

    for (int i = 0; i < indent; i++) putchar(' ');

    switch (value->type) {
        case JSON_OBJECT:
            printf("{\n");
            for (JsonKeyValuePair *pair = value->value.object_value; pair; pair = pair->next) {
                for (int i = 0; i < indent + 2; i++) putchar(' ');
                printf("\"%s\": ", pair->key);
                print_json(pair->value, indent + 2);
                if (pair->next) printf(",\n");
                else printf("\n");
            }
            for (int i = 0; i < indent; i++) putchar(' ');
            printf("}");
            break;
        case JSON_ARRAY:
            printf("[\n");
            for (JsonValue *item = value->value.array_value; item; item = item->next) {
                print_json(item, indent + 2);
                if (item->next) printf(",\n");
                else printf("\n");
            }
            for (int i = 0; i < indent; i++) putchar(' ');
            printf("]");
            break;
        case JSON_STRING:
            printf("\"%s\"", value->value.string_value);
            break;
        case JSON_NUMBER:
            printf("%f", value->value.number_value);
            break;
        case JSON_BOOL:
            printf(value->value.boolean_value ? "true" : "false");
            break;
        case JSON_NULL:
            printf("null");
            break;
    }
}