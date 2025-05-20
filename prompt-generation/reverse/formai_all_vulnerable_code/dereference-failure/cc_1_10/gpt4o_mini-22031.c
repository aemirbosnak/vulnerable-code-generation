//GPT-4o-mini DATASET v1.0 Category: Building a JSON Parser ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct JsonValue {
    enum { JSON_NULL, JSON_BOOL, JSON_NUMBER, JSON_STRING, JSON_OBJECT, JSON_ARRAY } type;
    union {
        int boolean; // For bool type
        double number; // For number type
        char *string; // For string type
        struct JsonValue *object; // For object type (key-value pairs)
        struct JsonValue *array; // For array type (list of values)
    } value;
    struct JsonValue *next; // For linked list of JSON elements
} JsonValue;

// Function prototypes
JsonValue *parse_json(const char *json);
JsonValue *parse_value(const char **json);
JsonValue *parse_object(const char **json);
JsonValue *parse_array(const char **json);
JsonValue *parse_string(const char **json);
JsonValue *parse_number(const char **json);
JsonValue *parse_bool(const char **json);
void parse_whitespace(const char **json);
void free_json(JsonValue *value);
void print_json(JsonValue *value, int indent);

int main() {
    const char *json_text = "{\"name\": \"John\", \"age\": 30, \"isStudent\": false, \"courses\": [\"Math\", \"Science\"]}";
    
    JsonValue *parsed_value = parse_json(json_text);
    if (parsed_value) {
        printf("Parsed JSON:\n");
        print_json(parsed_value, 0);
        free_json(parsed_value);
    } else {
        fprintf(stderr, "Failed to parse JSON\n");
    }
    
    return 0;
}

JsonValue *parse_json(const char *json) {
    parse_whitespace(&json);
    JsonValue *value = parse_value(&json);
    parse_whitespace(&json);
    
    if (*json != '\0') {
        free_json(value);
        return NULL; // Trailing characters found
    }
    
    return value;
}

JsonValue *parse_value(const char **json) {
    parse_whitespace(json);
    
    if (**json == 'n') return parse_string(json);
    if (**json == 't' || **json == 'f') return parse_bool(json);
    if (isdigit(**json) || **json == '-') return parse_number(json);
    if (**json == '"') return parse_string(json);
    if (**json == '{') return parse_object(json);
    if (**json == '[') return parse_array(json);
    
    return NULL; // Invalid JSON
}

void parse_whitespace(const char **json) {
    while (isspace(**json)) {
        (*json)++;
    }
}

JsonValue *parse_object(const char **json) {
    JsonValue *object = malloc(sizeof(JsonValue));
    object->type = JSON_OBJECT;
    object->next = NULL;

    (*json)++; // Skip '{'
    parse_whitespace(json);
    
    while (**json != '}') {
        // Parse key
        if (**json != '"') return NULL; // Key must start with a quote
        char *key = parse_string(json);
        
        parse_whitespace(json);
        if (**json != ':') return NULL; // Expecting ':'
        (*json)++; // Skip ':'
        
        // Parse value
        JsonValue *value = parse_value(json);
        value->next = object->next; 
        object->next = value; // Insert new key-value pair
        
        parse_whitespace(json);
        if (**json == ',') (*json)++; // Skip ',' for multiple pairs
        
        parse_whitespace(json);
    }
    
    (*json)++; // Skip '}'
    return object;
}

JsonValue *parse_array(const char **json) {
    JsonValue *array = malloc(sizeof(JsonValue));
    array->type = JSON_ARRAY;
    array->next = NULL;

    (*json)++; // Skip '['
    parse_whitespace(json);
    
    JsonValue *tail = NULL;
    while (**json != ']') {
        JsonValue *value = parse_value(json);
        
        if (tail) {
            tail->next = value;
        } else {
            array->next = value; // First element
        }
        tail = value; // Move tail to last element
        
        parse_whitespace(json);
        if (**json == ',') (*json)++; // Skip ',' for multiple elements
    }
    
    (*json)++; // Skip ']'
    return array;
}

JsonValue *parse_string(const char **json) {
    (*json)++; // Skip '"'
    const char *start = *json;

    while (**json != '"') {
        if (**json == '\0') return NULL; // Underflow
        (*json)++;
    }

    int length = *json - start;
    JsonValue *string_value = malloc(sizeof(JsonValue));
    string_value->type = JSON_STRING;
    string_value->value.string = malloc(length + 1);
    strncpy(string_value->value.string, start, length);
    string_value->value.string[length] = '\0'; // Null terminate
    (*json)++; // Skip '"'
    
    return string_value;
}

JsonValue *parse_number(const char **json) {
    const char *start = *json;

    while (isdigit(**json) || **json == '-' || **json == '.') {
        (*json)++;
    }

    int length = *json - start;
    char *number_str = malloc(length + 1);
    strncpy(number_str, start, length);
    number_str[length] = '\0'; // Null terminate

    JsonValue *num_value = malloc(sizeof(JsonValue));
    num_value->type = JSON_NUMBER;
    num_value->value.number = atof(number_str);
    free(number_str);

    return num_value;
}

JsonValue *parse_bool(const char **json) {
    if (strncmp(*json, "true", 4) == 0) {
        *json += 4;
        JsonValue *true_value = malloc(sizeof(JsonValue));
        true_value->type = JSON_BOOL;
        true_value->value.boolean = 1;
        return true_value;
    }
    if (strncmp(*json, "false", 5) == 0) {
        *json += 5;
        JsonValue *false_value = malloc(sizeof(JsonValue));
        false_value->type = JSON_BOOL;
        false_value->value.boolean = 0;
        return false_value;
    }
    return NULL; // Not a bool
}

void free_json(JsonValue *value) {
    if (!value) return;

    if (value->type == JSON_STRING) {
        free(value->value.string);
    } else if (value->type == JSON_OBJECT || value->type == JSON_ARRAY) {
        JsonValue *current = value->next;
        while (current) {
            JsonValue *next = current->next;
            free_json(current);
            current = next;
        }
    }
    
    free(value);
}

void print_json(JsonValue *value, int indent) {
    if (!value) {
        printf("null");
        return;
    }
    
    switch (value->type) {
        case JSON_NULL:
            printf("null");
            break;
        case JSON_BOOL:
            printf(value->value.boolean ? "true" : "false");
            break;
        case JSON_NUMBER:
            printf("%f", value->value.number);
            break;
        case JSON_STRING:
            printf("\"%s\"", value->value.string);
            break;
        case JSON_OBJECT:
            printf("{\n");
            for (JsonValue *current = value->next; current; current = current->next) {
                printf("%*s", indent + 2, "");
                print_json(current, indent + 2);
                if (current->next) printf(",\n");
            }
            printf("\n%*s}", indent, "");
            break;
        case JSON_ARRAY:
            printf("[\n");
            for (JsonValue *current = value->next; current; current = current->next) {
                printf("%*s", indent + 2, "");
                print_json(current, indent + 2);
                if (current->next) printf(",\n");
            }
            printf("\n%*s]", indent, "");
            break;
    }
}