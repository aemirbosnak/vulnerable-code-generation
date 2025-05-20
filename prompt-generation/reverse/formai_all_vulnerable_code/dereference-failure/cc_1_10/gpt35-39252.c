//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_JSON_LENGTH 1000

typedef enum {
    JSON_OBJECT,
    JSON_ARRAY,
    JSON_STRING,
    JSON_NUMBER,
    JSON_BOOLEAN,
    JSON_NULL
} json_type;

typedef struct {
    json_type type;
    union {
        char* string_value;
        double number_value;
        int boolean_value;
    } data;
} json_value;

json_value* parse_json(char* json_str)
{
    json_value* result = malloc(sizeof(json_value));
    char* remaining_str = json_str;

    // Skip whitespace
    while (*remaining_str == ' ' || *remaining_str == '\t' || *remaining_str == '\n' || *remaining_str == '\r') {
        remaining_str++;
    }

    // Parse object or array
    if (*remaining_str == '{') {
        result->type = JSON_OBJECT;
        // TODO: Implement object parsing
    } else if (*remaining_str == '[') {
        result->type = JSON_ARRAY;
        // TODO: Implement array parsing
    } else {
        // Parse string, number, boolean, or null value
        char* end_str;
        if (remaining_str[0] == '\"') {
            result->type = JSON_STRING;
            // Find end of string
            end_str = remaining_str + 1;
            while (*end_str != '\"') {
                // TODO: Handle escape characters
                end_str++;
            }
            size_t string_length = end_str - remaining_str - 1;
            result->data.string_value = malloc(string_length + 1);
            strncpy(result->data.string_value, remaining_str + 1, string_length);
            result->data.string_value[string_length] = '\0';
        } else if (strncmp(remaining_str, "true", 4) == 0) {
            result->type = JSON_BOOLEAN;
            result->data.boolean_value = 1;
        } else if (strncmp(remaining_str, "false", 5) == 0) {
            result->type = JSON_BOOLEAN;
            result->data.boolean_value = 0;
        } else if (strncmp(remaining_str, "null", 4) == 0) {
            result->type = JSON_NULL;
        } else {
            // Parse number value
            result->type = JSON_NUMBER;
            result->data.number_value = strtod(remaining_str, &end_str);
        }
        remaining_str = end_str;
    }

    return result;
}

int main()
{
    char json_str[MAX_JSON_LENGTH] = "{\"name\": \"John\", \"age\": 35, \"isMarried\": true, \"hobbies\": [\"reading\", \"swimming\"]}";
    json_value* value = parse_json(json_str);
    printf("Type: %d\n", value->type);
    if (value->type == JSON_OBJECT) {
        // TODO: Print object key/value pairs
    } else if (value->type == JSON_ARRAY) {
        // TODO: Print array values
    } else if (value->type == JSON_STRING) {
        printf("String value: %s\n", value->data.string_value);
    } else if (value->type == JSON_NUMBER) {
        printf("Number value: %f\n", value->data.number_value);
    } else if (value->type == JSON_BOOLEAN) {
        printf("Boolean value: %d\n", value->data.boolean_value);
    } else if (value->type == JSON_NULL) {
        printf("Null value\n");
    }
    return 0;
}