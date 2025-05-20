//GPT-4o-mini DATASET v1.0 Category: Building a JSON Parser ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef enum {
    JSON_NULL,
    JSON_TRUE,
    JSON_FALSE,
    JSON_NUMBER,
    JSON_STRING,
    JSON_ARRAY,
    JSON_OBJECT
} JsonType;

typedef struct JsonValue {
    JsonType type;
    union {
        double number;
        char *string;
        struct JsonValue *array;
        struct JsonValue *object;
    } value;
    struct JsonValue *next;
} JsonValue;

void skip_whitespace(const char **json) {
    while (**json && isspace(**json)) (*json)++;
}

JsonValue* parse_value(const char **json);

JsonValue* parse_number(const char **json) {
    JsonValue *value = (JsonValue *)malloc(sizeof(JsonValue));
    char *end;
    value->type = JSON_NUMBER;
    value->value.number = strtod(*json, &end);
    *json = end;
    return value;
}

JsonValue* parse_string(const char **json) {
    JsonValue *value = (JsonValue *)malloc(sizeof(JsonValue));
    const char *start = ++(*json); // Skip the starting quote
    while (**json && **json != '\"') {
        (*json)++;
    }
    value->type = JSON_STRING;
    value->value.string = strndup(start, *json - start);
    (*json)++; // Skip the ending quote
    return value;
}

JsonValue* parse_array(const char **json) {
    JsonValue *array = (JsonValue *)malloc(sizeof(JsonValue));
    array->type = JSON_ARRAY;
    array->next = NULL;
    JsonValue **current = &array->value.array;

    (*json)++; // Skip '['
    skip_whitespace(json);
    if (**json == ']') {
        (*json)++;
        return array;
    }

    while (1) {
        *current = parse_value(json);
        current = &(*current)->next;
        skip_whitespace(json);
        if (**json == ']') {
            (*json)++;
            break;
        }
        if (**json != ',') {
            fprintf(stderr, "Error: expected ',' or ']'\n");
            exit(EXIT_FAILURE);
        }
        (*json)++; // Skip ','
        skip_whitespace(json);
    }
    return array;
}

JsonValue* parse_object(const char **json) {
    JsonValue *object = (JsonValue *)malloc(sizeof(JsonValue));
    object->type = JSON_OBJECT;
    object->next = NULL;
    JsonValue **current = &object->value.object;

    (*json)++; // Skip '{'
    skip_whitespace(json);
    if (**json == '}') {
        (*json)++;
        return object;
    }

    while (1) {
        if (**json != '\"') {
            fprintf(stderr, "Error: expected '\"'\n");
            exit(EXIT_FAILURE);
        }
        
        JsonValue *key = parse_string(json);
        skip_whitespace(json);
        
        if (**json != ':') {
            fprintf(stderr, "Error: expected ':'\n");
            exit(EXIT_FAILURE);
        }
        (*json)++; // Skip ':'
        skip_whitespace(json);
        
        JsonValue *value = parse_value(json);
        value->next = NULL;
        key->next = value;

        *current = key;
        current = &(*current)->next;
        skip_whitespace(json);

        if (**json == '}') {
            (*json)++;
            break;
        }
        
        if (**json != ',') {
            fprintf(stderr, "Error: expected ',' or '}'\n");
            exit(EXIT_FAILURE);
        }
        (*json)++; // Skip ','
        skip_whitespace(json);
    }
    return object;
}

JsonValue* parse_value(const char **json) {
    skip_whitespace(json);
    
    switch (**json) {
        case 'n': 
            (*json) += 4; // Skip "null"
            JsonValue *null_val = (JsonValue *)malloc(sizeof(JsonValue));
            null_val->type = JSON_NULL;
            return null_val;

        case 't': 
            (*json) += 4; // Skip "true"
            JsonValue *true_val = (JsonValue *)malloc(sizeof(JsonValue));
            true_val->type = JSON_TRUE;
            return true_val;

        case 'f': 
            (*json) += 5; // Skip "false"
            JsonValue *false_val = (JsonValue *)malloc(sizeof(JsonValue));
            false_val->type = JSON_FALSE;
            return false_val;

        case '"':
            return parse_string(json);
        
        case '[': 
            return parse_array(json);

        case '{': 
            return parse_object(json);

        default:
            if (isdigit(**json) || **json == '-') {
                return parse_number(json);
            }
            fprintf(stderr, "Error: Invalid JSON input\n");
            exit(EXIT_FAILURE);
    }
    return NULL; // Should never be reached
}

void free_json(JsonValue *value) {
    if (!value) return;
    switch (value->type) {
        case JSON_STRING:
            free(value->value.string);
            break;
        case JSON_ARRAY:
            {
                JsonValue *temp = value->value.array;
                while (temp) {
                    JsonValue *next = temp->next;
                    free_json(temp);
                    temp = next;
                }
            }
            break;
        case JSON_OBJECT:
            {
                JsonValue *temp = value->value.object;
                while (temp) {
                    JsonValue *next = temp->next;
                    free_json(temp);
                    temp = next;
                }
            }
            break;
        default:
            break;
    }
    free(value);
}

void print_json(const JsonValue *value) {
    if (!value) return;
    
    switch (value->type) {
        case JSON_NULL:
            printf("null");
            break;
        case JSON_TRUE:
            printf("true");
            break;
        case JSON_FALSE:
            printf("false");
            break;
        case JSON_NUMBER:
            printf("%lf", value->value.number);
            break;
        case JSON_STRING:
            printf("\"%s\"", value->value.string);
            break;
        case JSON_ARRAY:
            printf("[");
            for (JsonValue *item = value->value.array; item; item = item->next) {
                print_json(item);
                if (item->next) printf(", ");
            }
            printf("]");
            break;
        case JSON_OBJECT:
            printf("{");
            for (JsonValue *item = value->value.object; item; item = item->next) {
                print_json(item);
                if (item->next) printf(", ");
            }
            printf("}");
            break;
    }
}

int main(void) {
    const char *json_input = "{\"name\": \"John\", \"age\": 30, \"city\": \"New York\", \"isStudent\": false, \"courses\": [\"Math\", \"Science\"]}";
    const char *ptr = json_input;
    JsonValue *json_value = parse_value(&ptr);
    print_json(json_value);
    printf("\n");
    free_json(json_value);
    return 0;
}