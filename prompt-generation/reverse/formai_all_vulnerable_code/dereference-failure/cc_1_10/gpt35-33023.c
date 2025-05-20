//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>

#define MAX_JSON_STRING 1024

typedef enum {
    JSON_OBJECT,
    JSON_ARRAY,
    JSON_STRING,
    JSON_NUMBER,
    JSON_BOOL,
    JSON_NULL
} json_type;

typedef struct {
    json_type type;
    union {
        char* string_value;
        double number_value;
        bool bool_value;
        void* object_value;
    } value;
} json_element;

char* current;
char* json_string;

char* parse_string() {
    char* start = ++current;
    char* end;

    while (*current != '\"') {
        if (*current == '\\') {
            current++;
        }

        current++;
    }

    end = current++;

    int length = end - start;

    char* result = malloc(length + 1);
    strncpy(result, start, length);
    result[length] = '\0';

    return result;
}

double parse_number() {
    char* start = current;

    while (isdigit(*current) || *current == '.' || *current == '-') {
        current++;
    }

    char* end = current;
    int length = end - start;

    char* buffer = malloc(length + 1);
    strncpy(buffer, start, length);
    buffer[length] = '\0';

    double result = strtod(buffer, NULL);

    free(buffer);

    return result;
}

bool parse_bool() {
    if (strncmp(current, "true", 4) == 0) {
        current += 4;
        return true;
    } else if (strncmp(current, "false", 5) == 0) {
        current += 5;
        return false;
    }

    return false;
}

void parse_null() {
    if (strncmp(current, "null", 4) == 0) {
        current += 4;
    }
}

json_element* parse_json();

json_element* parse_array() {
    json_element* elements = NULL;
    int count = 0;

    current++;

    while (*current != ']') {
        if (*current == ',') {
            current++;
        }

        json_element* element = parse_json();
        count++;

        elements = realloc(elements, sizeof(json_element) * count);
        elements[count - 1] = *element;
    }

    current++;

    json_element* result = malloc(sizeof(json_element));
    result->type = JSON_ARRAY;
    result->value.object_value = elements;

    return result;
}

json_element* parse_object() {
    current++;

    json_element* result = malloc(sizeof(json_element));
    result->type = JSON_OBJECT;
    result->value.object_value = NULL;

    return result;
}

json_element* parse_json() {
    json_element* element = malloc(sizeof(json_element));

    if (*current == '{') {
        element = parse_object();
    } else if (*current == '[') {
        element = parse_array();
    } else if (*current == '\"') {
        element->type = JSON_STRING;
        element->value.string_value = parse_string();
    } else if (isdigit(*current) || *current == '-') {
        element->type = JSON_NUMBER;
        element->value.number_value = parse_number();
    } else if (strncmp(current, "true", 4) == 0 || strncmp(current, "false", 5) == 0) {
        element->type = JSON_BOOL;
        element->value.bool_value = parse_bool();
    } else if (strncmp(current, "null", 4) == 0) {
        element->type = JSON_NULL;
        parse_null();
    }

    return element;
}

json_element* parse(char* string) {
    json_string = string;
    current = string;

    return parse_json();
}

int main(void) {
    char json_str[MAX_JSON_STRING] = "{\"name\": \"John\", \"age\": 30, \"cars\": [\"Ford\", \"BMW\", \"Fiat\"]}";

    json_element* root = parse(json_str);

    if (root->type == JSON_OBJECT) {
        printf("JSON object:\n");

        void** object = root->value.object_value;

        for (int i = 0; object[i]; i += 2) {
            char* key = (char*)object[i];
            json_element* value = (json_element*)object[i + 1];

            printf("%s: ", key);

            switch (value->type) {
                case JSON_STRING:
                    printf("%s\n", value->value.string_value);
                    break;
                case JSON_NUMBER:
                    printf("%f\n", value->value.number_value);
                    break;
                case JSON_BOOL:
                    printf("%s\n", value->value.bool_value ? "true" : "false");
                    break;
                case JSON_ARRAY:
                    printf("array not implemented yet\n");
                    break;
                case JSON_OBJECT:
                    printf("object not implemented yet\n");
                    break;
                case JSON_NULL:
                    printf("null\n");
                    break;
            }
        }
    } else {
        printf("Not a JSON object!\n");
    }

    return 0;
}