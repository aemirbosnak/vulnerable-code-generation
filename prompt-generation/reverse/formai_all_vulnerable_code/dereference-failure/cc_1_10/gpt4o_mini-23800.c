//GPT-4o-mini DATASET v1.0 Category: Building a JSON Parser ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef enum {
    JSON_NULL, JSON_TRUE, JSON_FALSE, JSON_NUMBER, JSON_STRING, JSON_ARRAY, JSON_OBJECT
} JsonType;

typedef struct JsonValue {
    JsonType type;
    union {
        double number;
        char *string;
        struct JsonValue *array; // Points to an array of JsonValue
        struct KeyValuePair *object; // Points to the root of an object
    } value;
} JsonValue;

typedef struct KeyValuePair {
    char *key;
    JsonValue value;
    struct KeyValuePair *next;
} KeyValuePair;

// Function prototypes
JsonValue parse_json(const char *json);
void free_json(JsonValue json);
void print_json(JsonValue json);
KeyValuePair *parse_object(const char **json);
JsonValue parse_array(const char **json);
JsonValue parse_value(const char **json);
char *parse_string(const char **json);
double parse_number(const char **json);

// Function responsible for parsing a JSON string
JsonValue parse_json(const char *json) {
    return parse_value(&json);
}

// Free allocated memory for JSON value
void free_json(JsonValue json) {
    if (json.type == JSON_STRING) {
        free(json.value.string);
    } else if (json.type == JSON_ARRAY) {
        // Assuming array of JsonValue
        for (int i = 0; json.value.array[i].type != JSON_NULL; i++) {
            free_json(json.value.array[i]);
        }
        free(json.value.array);
    } else if (json.type == JSON_OBJECT) {
        // Free key-value pairs of an object
        KeyValuePair *pair = json.value.object;
        while (pair) {
            free(pair->key);
            free_json(pair->value);
            KeyValuePair *temp = pair;
            pair = pair->next;
            free(temp);
        }
    }
}

// Print the JSON value in a simple format
void print_json(JsonValue json) {
    switch (json.type) {
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
            printf("%g", json.value.number);
            break;
        case JSON_STRING:
            printf("\"%s\"", json.value.string);
            break;
        case JSON_ARRAY:
            printf("[");
            for (int i = 0; json.value.array[i].type != JSON_NULL; i++) {
                print_json(json.value.array[i]);
                if (json.value.array[i + 1].type != JSON_NULL) {
                    printf(", ");
                }
            }
            printf("]");
            break;
        case JSON_OBJECT:
            printf("{");
            KeyValuePair *pair = json.value.object;
            while (pair) {
                printf("\"%s\": ", pair->key);
                print_json(pair->value);
                if (pair->next != NULL) {
                    printf(", ");
                }
                pair = pair->next;
            }
            printf("}");
            break;
    }
}

// Function to parse JSON object
KeyValuePair *parse_object(const char **json) {
    // Skip '{'
    (*json)++;
    KeyValuePair *head = NULL, *tail = NULL;

    while (**json != '}') {
        // Parse key
        char *key = parse_string(json);
        (*json)++; // Skip ':'
        JsonValue value = parse_value(json);

        KeyValuePair *new_pair = malloc(sizeof(KeyValuePair));
        new_pair->key = key;
        new_pair->value = value;
        new_pair->next = NULL;

        if (head == NULL) {
            head = new_pair;
            tail = new_pair;
        } else {
            tail->next = new_pair;
            tail = new_pair;
        }

        if (**json == ',') {
            (*json)++; // Skip ','
        }
    }
    // Skip '}'
    (*json)++;
    return head;
}

// Function to parse JSON array
JsonValue parse_array(const char **json) {
    // Skip '['
    (*json)++;
    JsonValue array_value = { .type = JSON_ARRAY };
    array_value.value.array = calloc(128, sizeof(JsonValue)); // Arbitrary size

    int index = 0;
    while (**json != ']') {
        if (index >= 127) { // Prevent overflow
            break;
        }
        array_value.value.array[index++] = parse_value(json);
        if (**json == ',') {
            (*json)++;
        }
    }
    // Mark end of array
    array_value.value.array[index].type = JSON_NULL;
    // Skip ']'
    (*json)++;
    return array_value;
}

// Function to parse JSON value
JsonValue parse_value(const char **json) {
    while (isspace(**json)) (*json)++; // Skip whitespace
    JsonValue value;

    if (**json == '{') {
        value.type = JSON_OBJECT;
        value.value.object = parse_object(json);
    } else if (**json == '[') {
        value = parse_array(json);
    } else if (**json == '\"') {
        value.type = JSON_STRING;
        value.value.string = parse_string(json);
    } else if (isdigit(**json) || **json == '-') {
        value.type = JSON_NUMBER;
        value.value.number = parse_number(json);
    } else if (strncmp(*json, "true", 4) == 0) {
        value.type = JSON_TRUE;
        *json += 4;
    } else if (strncmp(*json, "false", 5) == 0) {
        value.type = JSON_FALSE;
        *json += 5;
    } else if (strncmp(*json, "null", 4) == 0) {
        value.type = JSON_NULL;
        *json += 4;
    } else {
        perror("Invalid JSON!");
        exit(EXIT_FAILURE);
    }

    return value;
}

// Function to parse JSON string
char *parse_string(const char **json) {
    (*json)++; // Skip initial "
    const char *start = *json;
    while (**json != '\"') {
        if (**json == '\\') {
            (*json)++; // Skip escape character
        }
        (*json)++;
    }
    size_t length = *json - start;
    char *str = malloc(length + 1);
    strncpy(str, start, length);
    str[length] = '\0';
    (*json)++; // Skip final "
    return str;
}

// Function to parse JSON number
double parse_number(const char **json) {
    char *end_ptr;
    double number = strtod(*json, &end_ptr);
    *json = end_ptr; // Update position
    return number;
}

// Main function for testing the JSON parser
int main() {
    const char *json_input = "{\"name\":\"John Doe\", \"age\":30, \"is_student\":false, \"courses\":[\"Math\", \"Science\"]}";
    JsonValue json = parse_json(json_input);
    print_json(json);
    printf("\n");

    // Free allocated resources
    free_json(json);
    return 0;
}