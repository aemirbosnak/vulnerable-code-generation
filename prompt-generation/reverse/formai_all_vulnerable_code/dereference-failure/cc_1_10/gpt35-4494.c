//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum json_type {
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
        struct json_object* object_value;
        struct json_array* array_value;
        char* string_value;
        double number_value;
        int bool_value;
    };
} json_value;

typedef struct json_element {
    char* key;
    json_value* value;
    struct json_element* next;
} json_element;

typedef struct json_object {
    json_element* elements;
} json_object;

typedef struct json_array {
    json_value** items;
    int size;
} json_array;

// Function to parse JSON string
json_value* parse_json(const char* json_str);

// Function to parse an object from JSON
json_object* parse_json_object(const char** json_str);

// Function to parse an array from JSON
json_array* parse_json_array(const char** json_str);

// Function to parse a string from JSON
char* parse_json_string(const char** json_str);

// Function to parse a number from JSON
double parse_json_number(const char** json_str);

// Function to parse a boolean value from JSON
int parse_json_bool(const char** json_str);

//Function to skip whitespace in a JSON string
void skip_whitespace(const char** json_str);

int main() {
    const char* json_str = "{\"name\":\"John\",\"age\":30,\"admin\":true}";

    json_value* value = parse_json(json_str);
    json_object* obj = value->object_value;

    printf("Name: %s\n", obj->elements->value->string_value);
    printf("Age: %.0f\n", obj->elements->next->value->number_value);
    printf("Admin: %s\n", obj->elements->next->next->value->bool_value == 1 ? "true" : "false");

    return 0;
}

json_value* parse_json(const char* json_str) {
    skip_whitespace(&json_str); // Skip leading whitespace

    json_value* value;

    switch (*json_str) {
        case '{':
            value = (json_value*)malloc(sizeof(json_value));
            value->type = JSON_OBJECT;
            value->object_value = parse_json_object(&json_str);
            break;
        
        case '[':
            value = (json_value*)malloc(sizeof(json_value));
            value->type = JSON_ARRAY;
            value->array_value = parse_json_array(&json_str);
            break;

        case '"':
            value = (json_value*)malloc(sizeof(json_value));
            value->type = JSON_STRING;
            value->string_value = parse_json_string(&json_str);
            break;

        case 't':
        case 'f':
            value = (json_value*)malloc(sizeof(json_value));
            value->type = JSON_TRUE;
            value->bool_value = parse_json_bool(&json_str);
            break;

        case 'n':
            value = (json_value*)malloc(sizeof(json_value));
            value->type = JSON_NULL;
            ++json_str;
            break;

        default:
            value = (json_value*)malloc(sizeof(json_value));
            value->type = JSON_NUMBER;
            value->number_value = parse_json_number(&json_str);
            break;
    }

    skip_whitespace(&json_str); // Skip trailing whitespace

    return value;
}

json_object* parse_json_object(const char** json_str) {
    ++(*json_str); // Skip the opening brace
    skip_whitespace(json_str); // Skip any whitespace after the opening brace

    json_object* object = (json_object*)malloc(sizeof(json_object));
    object->elements = NULL;

    while (**json_str != '}') {
        if (object->elements) { // If this is not the first element
            if (**json_str != ',') { // There must be a comma between elements
                fprintf(stderr, "Error: Expected comma between JSON elements.\n");
                exit(1);
            }
            ++(*json_str); // Skip the comma
        }

        skip_whitespace(json_str); // Skip any whitespace before the element

        char* key = parse_json_string(json_str);
        skip_whitespace(json_str); // Skip any whitespace after the key

        if (**json_str != ':') { // The key-value pair must be separated by a colon
            fprintf(stderr, "Error: Expected colon between JSON key-value pair.\n");
            exit(1);
        }
        ++(*json_str); // Skip the colon

        json_value* value = parse_json(*json_str);
        json_element* element = (json_element*)malloc(sizeof(json_element));
        element->key = key;
        element->value = value;
        element->next = NULL;

        if (object->elements) {
            json_element* tail = object->elements;
            while (tail->next) {
                tail = tail->next;
            }
            tail->next = element;
        } else {
            object->elements = element;
        }

        skip_whitespace(json_str); // Skip whitespace after the element
    }

    ++(*json_str); // Skip the closing brace

    return object;
}

json_array* parse_json_array(const char** json_str) {
    ++(*json_str); // Skip the opening bracket
    skip_whitespace(json_str); // Skip any whitespace after the opening bracket

    json_array* array = (json_array*)malloc(sizeof(json_array));
    array->items = (json_value**)malloc(sizeof(json_value*) * 2);
    array->size = 0;

    while (**json_str != ']') {
        if (array->size > 0) { // If this is not the first element
            if (**json_str != ',') { // There must be a comma between elements
                fprintf(stderr, "Error: Expected comma between JSON elements.\n");
                exit(1);
            }
            ++(*json_str); // Skip the comma
            skip_whitespace(json_str); // Skip any whitespace after the comma
        }

        json_value* value = parse_json(*json_str);

        if (array->size == 0) {
            array->items[0] = value;
            array->size = 1;
        } else {
            array->items = (json_value**)realloc(array->items, sizeof(json_value*) * (array->size + 1));
            array->items[array->size] = value;
            array->size++;
        }

        skip_whitespace(json_str); // Skip whitespace after the element
    }

    ++(*json_str); // Skip the closing bracket

    return array;
}

char* parse_json_string(const char** json_str) {
    ++(*json_str); // Skip the opening quote

    const char* start = *json_str;
    const char* end = start;

    while (*end != '\0' && *end != '\"') {
        if (*end == '\\') { // Handle escape characters
            ++end;
            if (*end == '\0') {
                fprintf(stderr, "Error: Unterminated JSON string.\n");
                exit(1);
            }
        }
        ++end;
    }

    if (*end == '\0') {
        fprintf(stderr, "Error: Unterminated JSON string.\n");
        exit(1);
    }

    int length = end - start;
    char* value = (char*)malloc(length + 1);
    strncpy(value, start, length);
    value[length] = '\0';

    ++end; // Skip the closing quote
    *json_str = end;

    return value;
}

double parse_json_number(const char** json_str) {
    const char* start = *json_str;
    const char* end = start;

    while (*end != '\0' && (*end == '.' || (*end >= '0' && *end <= '9') || *end == 'e' || *end == 'E' || *end == '-' || *end == '+')) {
        ++end;
    }

    if (start == end) {
        fprintf(stderr, "Error: Invalid JSON number.\n");
        exit(1);
    }

    double value = strtod(start, NULL);
    *json_str = end;

    return value;
}

int parse_json_bool(const char** json_str) {
    if (**json_str == 't') {
        *json_str += 4; // Skip "true"
        return 1;
    }

    *json_str += 5; // Skip "false"
    return 0;
}

void skip_whitespace(const char** json_str) {
    while (**json_str != '\0' && (**json_str == ' ' || **json_str == '\n' || **json_str == '\r' || **json_str == '\t')) {
        ++(*json_str);
    }
}