//GPT-4o-mini DATASET v1.0 Category: Building a JSON Parser ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_BUFFER 1024
#define MAX_TOKENS 100

typedef enum {
    JSON_NULL, JSON_BOOLEAN, JSON_NUMBER, JSON_STRING, JSON_ARRAY, JSON_OBJECT
} json_type;

typedef struct json_value {
    json_type type;
    union {
        int boolean; // 0 for false, 1 for true
        double number;
        char *string;
        struct json_value **array;
        struct {
            char **keys;
            struct json_value **values;
        } object;
    } value;
} json_value;

void skip_whitespace(const char **json) {
    while (isspace(**json)) (*json)++;
}

char *parse_string(const char **json) {
    const char *start = ++(*json);
    while (**json && **json != '"') {
        if (**json == '\\') (*json)++; // Skip escaped character
        (*json)++;
    }
    size_t length = *json - start;
    char *result = (char *)malloc(length + 1);
    strncpy(result, start, length);
    result[length] = '\0';
    (*json)++; // Skip closing '"'
    return result;
}

json_value *parse_value(const char **json);

json_value *parse_array(const char **json) {
    json_value *result = malloc(sizeof(json_value));
    result->type = JSON_ARRAY;
    result->value.array = malloc(sizeof(json_value *) * MAX_TOKENS);
    size_t count = 0;

    skip_whitespace(json);
    if (**json == '[') {
        (*json)++;
        skip_whitespace(json);
        while (**json && **json != ']') {
            if (count >= MAX_TOKENS) {
                fprintf(stderr, "Error: too many items in array.\n");
                exit(EXIT_FAILURE);
            }
            result->value.array[count++] = parse_value(json);
            skip_whitespace(json);
            if (**json == ',') (*json)++;
            skip_whitespace(json);
        }
        if (**json == ']') {
            (*json)++;
        }
    }
    return result;
}

json_value *parse_object(const char **json) {
    json_value *result = malloc(sizeof(json_value));
    result->type = JSON_OBJECT;
    result->value.object.keys = malloc(sizeof(char *) * MAX_TOKENS);
    result->value.object.values = malloc(sizeof(json_value *) * MAX_TOKENS);
    size_t count = 0;

    skip_whitespace(json);
    if (**json == '{') {
        (*json)++;
        skip_whitespace(json);
        while (**json && **json != '}') {
            if (count >= MAX_TOKENS) {
                fprintf(stderr, "Error: too many items in object.\n");
                exit(EXIT_FAILURE);
            }
            result->value.object.keys[count] = parse_string(json);
            skip_whitespace(json);
            if (**json != ':') exit(EXIT_FAILURE);
            (*json)++; // Skip ':'
            skip_whitespace(json);
            result->value.object.values[count++] = parse_value(json);
            skip_whitespace(json);
            if (**json == ',') (*json)++;
            skip_whitespace(json);
        }
        if (**json == '}') {
            (*json)++;
        }
    }
    return result;
}

json_value *parse_value(const char **json) {
    skip_whitespace(json);
    json_value *value = malloc(sizeof(json_value));
    
    if (**json == '"') {
        value->type = JSON_STRING;
        value->value.string = parse_string(json);
    } else if (isdigit(**json) || **json == '-') {
        value->type = JSON_NUMBER;
        value->value.number = strtod(*json, (char **)json);
    } else if (strncmp(*json, "true", 4) == 0) {
        value->type = JSON_BOOLEAN;
        value->value.boolean = 1;
        *json += 4;
    } else if (strncmp(*json, "false", 5) == 0) {
        value->type = JSON_BOOLEAN;
        value->value.boolean = 0;
        *json += 5;
    } else if (strncmp(*json, "null", 4) == 0) {
        value->type = JSON_NULL;
        *json += 4;
    } else if (**json == '[') {
        value = parse_array(json);
    } else if (**json == '{') {
        value = parse_object(json);
    }
    return value;
}

void free_json_value(json_value *value) {
    if (!value) return;
    switch (value->type) {
        case JSON_STRING: free(value->value.string); break;
        case JSON_ARRAY: 
            for (size_t i = 0; value->value.array[i]; i++) {
                free_json_value(value->value.array[i]);
            }
            free(value->value.array); 
            break;
        case JSON_OBJECT:
            for (size_t i = 0; value->value.object.keys[i]; i++) {
                free(value->value.object.keys[i]);
                free_json_value(value->value.object.values[i]);
            }
            free(value->value.object.keys);
            free(value->value.object.values);
            break;
        default: break;
    }
    free(value);
}

int main() {
    const char *json_text = "{\"name\":\"John\\\"Doe\", \"age\":30, \"is_student\":false, \"courses\":[\"Math\", \"Science\"], \"address\":{\"city\":\"New York\", \"zip\":10001}}";
    const char *json_ptr = json_text;

    json_value *root = parse_object(&json_ptr);

    // (Example of extracting data from the parsed JSON)
    printf("Parsed JSON:\n");
    if (root->type == JSON_OBJECT) {
        for (size_t i = 0; root->value.object.keys[i]; i++) {
            printf("Key: %s\n", root->value.object.keys[i]);
            // We can add additional printing logic here for values
        }
    }

    free_json_value(root);
    return 0;
}