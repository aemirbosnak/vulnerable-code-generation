//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum {
    JSON_NULL,
    JSON_BOOLEAN,
    JSON_NUMBER,
    JSON_STRING,
    JSON_OBJECT,
    JSON_ARRAY
} json_type;

typedef struct json_value json_value;
typedef struct json_object json_object;
typedef struct json_array json_array;

struct json_value {
    json_type type;
    union {
        int boolean;
        double number;
        char* string;
        json_object* object;
        json_array* array;
    } data;
};

struct json_object {
    int size;
    char** keys;
    json_value** values;
};

struct json_array {
    int size;
    json_value** values;
};

void skip_spaces(char** cursor) {
    while (**cursor == ' ' || **cursor == '\t' || **cursor == '\n' || **cursor == '\r') {
        *cursor += 1;
    }
}

int parse_object(char** cursor, json_value** result);

int parse_number(char** cursor, json_value** result) {
    char* end;
    double number = strtod(*cursor, &end);
    if (cursor == end) {
        printf("Invalid number.\n");
        return 0;
    }
    *cursor = end;
    *result = malloc(sizeof(json_value));
    (*result)->type = JSON_NUMBER;
    (*result)->data.number = number;
    return 1;
}

int parse_string(char** cursor, json_value** result) {
    char* start = *cursor + 1;
    char* end = start + 1;
    while (*end != '\"') {
        if (*end == '\0') {
            printf("Unterminated string.\n");
            return 0;
        }
        if (*end == '\\') {
            end += 1;
        }
        end += 1;
    }
    *result = malloc(sizeof(json_value));
    (*result)->type = JSON_STRING;
    (*result)->data.string = malloc(end - start + 1);
    strncpy((*result)->data.string, start, end - start);
    (*result)->data.string[end - start] = '\0';
    *cursor = end + 1;
    return 1;
}

int parse_value(char** cursor, json_value** result) {
    skip_spaces(cursor);
    switch (**cursor) {
        case 'n':
            if (strncmp(*cursor, "null", 4) == 0) {
                *cursor += 4;
                *result = malloc(sizeof(json_value));
                (*result)->type = JSON_NULL;
                return 1;
            }
            break;
        case 't':
            if (strncmp(*cursor, "true", 4) == 0) {
                *cursor += 4;
                *result = malloc(sizeof(json_value));
                (*result)->type = JSON_BOOLEAN;
                (*result)->data.boolean = 1;
                return 1;
            }
            break;
        case 'f':
            if (strncmp(*cursor, "false", 5) == 0) {
                *cursor += 5;
                *result = malloc(sizeof(json_value));
                (*result)->type = JSON_BOOLEAN;
                (*result)->data.boolean = 0;
                return 1;
            }
            break;
        case '\"':
            return parse_string(cursor, result);
        case '{':
            return parse_object(cursor, result);
        case '[':
            break;
        default:
            if (**cursor == '-' || (**cursor >= '0' && **cursor <= '9')) {
                return parse_number(cursor, result);
            }
            break;
    }
    printf("Invalid value.\n");
    return 0;
}

int parse_pair(char** cursor, char** key, json_value** value) {
    if (!parse_string(cursor, key)) {
        return 0;
    }
    skip_spaces(cursor);
    if (*((*cursor)++) != ':') {
        printf("Expected ':' after key.\n");
        return 0;
    }
    skip_spaces(cursor);
    if (!parse_value(cursor, value)) {
        return 0;
    }
    return 1;
}

int parse_object(char** cursor, json_value** result) {
    json_object* object = malloc(sizeof(json_object));
    object->size = 0;
    object->keys = NULL;
    object->values = NULL;
    *cursor += 1;
    skip_spaces(cursor);
    if (**cursor == '}') {
        *result = malloc(sizeof(json_value));
        (*result)->type = JSON_OBJECT;
        (*result)->data.object = object;
        return 1;
    }
    while (1) {
        char* key;
        json_value* value;
        if (!parse_pair(cursor, &key, &value)) {
            printf("Invalid pair.\n");
            return 0;
        }
        object->size += 1;
        object->keys = realloc(object->keys, object->size * sizeof(char*));
        object->values = realloc(object->values, object->size * sizeof(json_value*));
        object->keys[object->size - 1] = key;
        object->values[object->size - 1] = value;
        skip_spaces(cursor);
        if (**cursor == '}') {
            break;
        }
        if (*((*cursor)++) != ',') {
            printf("Expected ',' after pair.\n");
            return 0;
        }
        skip_spaces(cursor);
    }
    *cursor += 1;
    *result = malloc(sizeof(json_value));
    (*result)->type = JSON_OBJECT;
    (*result)->data.object = object;
    return 1;
}

int main() {
    char* json = "{\"firstName\": \"John\",\"lastName\": \"Smith\",\"age\": 25,\"address\": {\"streetAddress\": \"21 2nd Street\",\"city\": \"New York\"},\"phoneNumbers\": [{\"type\": \"home\",\"number\": \"212 555-1234\"},{\"type\": \"mobile\",\"number\": \"646 555-4567\"}]}";
    json_value* value;
    if (!parse_object(&json, &value)) {
        printf("Invalid JSON string.\n");
        return 1;
    }
    printf("Parsed JSON object:\n");
    printf("Type: %d\n", value->type);
    printf("First name: %s\n", value->data.object->values[0]->data.string);
    printf("Last name: %s\n", value->data.object->values[1]->data.string);
    printf("Age: %g\n", value->data.object->values[2]->data.number);
    printf("Street address: %s\n", value->data.object->values[3]->data.object->values[0]->data.string);
    printf("City: %s\n", value->data.object->values[3]->data.object->values[1]->data.string);
    printf("Home phone number: %s\n", value->data.object->values[4]->data.array->values[0]->data.object->values[1]->data.string);
    printf("Mobile phone number: %s\n", value->data.object->values[4]->data.array->values[1]->data.object->values[1]->data.string);
    return 0;
}