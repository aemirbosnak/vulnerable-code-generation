//GPT-4o-mini DATASET v1.0 Category: Building a JSON Parser ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Define a structure for the JSON object
typedef struct JSONValue {
    int type; // 0 for object, 1 for array, 2 for string, 3 for number, 4 for boolean, 5 for null
    union {
        struct JSONValue* obj; // For JSON objects
        struct JSONValue* arr; // For JSON arrays
        char* str;             // For JSON strings
        double number;         // For JSON numbers
        int boolean;           // For JSON booleans
    } value;
} JSONValue;

// Define constants for value types
#define JSON_OBJECT 0
#define JSON_ARRAY 1
#define JSON_STRING 2
#define JSON_NUMBER 3
#define JSON_BOOLEAN 4
#define JSON_NULL 5

// Function prototypes
JSONValue* parse_json(const char* json);
void free_json(JSONValue* val);
void print_json(JSONValue* val, int indent);

// Function to skip whitespace characters
const char* skip_whitespace(const char* json) {
    while (isspace(*json)) json++;
    return json;
}

// Function to parse a string value
char* parse_string(const char** json) {
    const char* start = ++(*json); // Skip the opening quote
    while (**json != '"' && **json != '\0') {
        if (**json == '\\') (*json)++; // Skip escaping character
        (*json)++;
    }
    size_t length = *json - start;
    char* str = (char*)malloc(length + 1);
    strncpy(str, start, length);
    str[length] = '\0';
    (*json)++; // Skip the closing quote
    return str;
}

// Function to parse a number
double parse_number(const char** json) {
    char* end;
    double value = strtod(*json, &end);
    *json = end;
    return value;
}

// Function to parse a boolean
int parse_boolean(const char** json) {
    if (strncmp(*json, "true", 4) == 0) {
        *json += 4;
        return 1;
    } else if (strncmp(*json, "false", 5) == 0) {
        *json += 5;
        return 0;
    }
    return -1; // Error case
}

// Function to parse null
void parse_null(const char** json) {
    *json += 4; // Move past "null"
}

// Function to parse an array
JSONValue* parse_array(const char** json) {
    JSONValue* array = (JSONValue*)malloc(sizeof(JSONValue));
    array->type = JSON_ARRAY;

    (*json)++; // Skip '['
    while (**json != ']') {
        *json = skip_whitespace(*json);
        JSONValue* item = parse_json(*json);
        if (!item) break; // Error while parsing item

        // Here, normally would grow the array and append the item
        // Simplified for this example
        *json = skip_whitespace(*json);
        if (**json == ',') (*json)++; // Skip comma
    }
    (*json)++; // Skip ']'
    return array;
}

// Function to parse JSON
JSONValue* parse_json(const char* json) {
    json = skip_whitespace(json);
    
    if (*json == '{') {
        // Parsing an object (not implemented in this simplified version)
        // Just returning NULL to indicate not implemented
        return NULL;
    } else if (*json == '[') {
        return parse_array(&json);
    } else if (*json == '"') {
        JSONValue* value = (JSONValue*)malloc(sizeof(JSONValue));
        value->type = JSON_STRING;
        value->value.str = parse_string(&json);
        return value;
    } else if (isdigit(*json) || *json == '-') {
        JSONValue* value = (JSONValue*)malloc(sizeof(JSONValue));
        value->type = JSON_NUMBER;
        value->value.number = parse_number(&json);
        return value;
    } else if (strncmp(json, "true", 4) == 0 || strncmp(json, "false", 5) == 0) {
        JSONValue* value = (JSONValue*)malloc(sizeof(JSONValue));
        value->type = JSON_BOOLEAN;
        value->value.boolean = parse_boolean(&json);
        return value;
    } else if (strncmp(json, "null", 4) == 0) {
        JSONValue* value = (JSONValue*)malloc(sizeof(JSONValue));
        value->type = JSON_NULL;
        parse_null(&json);
        return value;
    }
    return NULL; // Error case
}

// Function to free JSON allocated memory
void free_json(JSONValue* val) {
    if (!val) return;
    if (val->type == JSON_STRING) {
        free(val->value.str);
    } else if (val->type == JSON_ARRAY) {
        // Normally we would free items here, but omitted for simplicity
    }
    free(val);
}

// Function to print JSON value
void print_json(JSONValue* val, int indent) {
    if (!val) return;

    for (int i = 0; i < indent; i++) printf(" ");
    if (val->type == JSON_STRING) {
        printf("\"%s\"\n", val->value.str);
    } else if (val->type == JSON_NUMBER) {
        printf("%lf\n", val->value.number);
    } else if (val->type == JSON_BOOLEAN) {
        printf(val->value.boolean ? "true\n" : "false\n");
    } else if (val->type == JSON_NULL) {
        printf("null\n");
    } else if (val->type == JSON_ARRAY) {
        printf("[\n");
        // Print array items
        printf("]\n");
    }
}

int main() {
    const char* json = "[\"Hello, World!\", true, 3.14, null, [1, 2, 3]]";
    JSONValue* parsed_json = parse_json(json);

    if (parsed_json) {
        print_json(parsed_json, 0);
        free_json(parsed_json); // Clean up allocated memory
    } else {
        printf("Error parsing JSON\n");
    }

    return 0;
}