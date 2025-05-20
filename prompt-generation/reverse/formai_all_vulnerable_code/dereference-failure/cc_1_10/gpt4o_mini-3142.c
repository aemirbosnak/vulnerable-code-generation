//GPT-4o-mini DATASET v1.0 Category: Building a JSON Parser ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_JSON_SIZE 1024
#define MAX_KEY_SIZE 128
#define MAX_VALUE_SIZE 256

// Enumeration to define JSON value types
typedef enum {
    JSON_STRING,
    JSON_NUMBER,
    JSON_OBJECT,
    JSON_ARRAY,
    JSON_BOOL,
    JSON_NULL,
    JSON_UNKNOWN
} json_value_type;

// Structure to represent a JSON key-value pair
typedef struct json_pair {
    char key[MAX_KEY_SIZE];
    char value[MAX_VALUE_SIZE];
    json_value_type type;
} json_pair;

// Structure to represent a JSON object
typedef struct json_object {
    json_pair pairs[MAX_JSON_SIZE];
    int size;
} json_object;

// Function to trim whitespace from a string
char* trim_whitespace(char *str) {
    char *end;

    while (isspace((unsigned char)*str)) str++; // Trim from start
    if (*str == 0) return str; // All spaces

    end = str + strlen(str) - 1;
    while (end > str && isspace((unsigned char)*end)) end--; // Trim from end
    *(end + 1) = 0;

    return str;
}

// Function to parse a JSON string
json_object* parse_json(const char *json) {
    json_object *obj = malloc(sizeof(json_object));
    obj->size = 0;

    char *temp_json = strdup(json); // Duplicate JSON string
    temp_json = trim_whitespace(temp_json);

    char *token = strtok(temp_json, ",:{}");
    while (token != NULL) {
        char *key_value = strtok(token, ":");
        if (key_value != NULL) {
            strncpy(obj->pairs[obj->size].key, trim_whitespace(key_value), MAX_KEY_SIZE);
            char *value = strtok(NULL, ":");
            if (value != NULL) {
                strncpy(obj->pairs[obj->size].value, trim_whitespace(value), MAX_VALUE_SIZE);
                // Determine the type of the value
                if (obj->pairs[obj->size].value[0] == '"') {
                    obj->pairs[obj->size].type = JSON_STRING;
                } else if (isdigit(obj->pairs[obj->size].value[0]) || 
                           (obj->pairs[obj->size].value[0] == '-' && isdigit(obj->pairs[obj->size].value[1]))) {
                    obj->pairs[obj->size].type = JSON_NUMBER;
                } else if (strcmp(obj->pairs[obj->size].value, "true") == 0 ||
                           strcmp(obj->pairs[obj->size].value, "false") == 0) {
                    obj->pairs[obj->size].type = JSON_BOOL;
                } else if (strcmp(obj->pairs[obj->size].value, "null") == 0) {
                    obj->pairs[obj->size].type = JSON_NULL;
                } else {
                    obj->pairs[obj->size].type = JSON_UNKNOWN;
                }
                obj->size++;
            }
        }
        token = strtok(NULL, ",:{}");
    }

    free(temp_json);
    return obj;
}

// Function to print the parsed JSON object
void print_json_object(json_object *obj) {
    printf("{\n");
    for (int i = 0; i < obj->size; i++) {
        printf("  \"%s\": ", obj->pairs[i].key);
        switch (obj->pairs[i].type) {
            case JSON_STRING:
                printf("\"%s\"", obj->pairs[i].value);
                break;
            case JSON_NUMBER:
            case JSON_BOOL:
            case JSON_NULL:
            case JSON_UNKNOWN:
                printf("%s", obj->pairs[i].value);
                break;
            default:
                break;
        }
        if (i < obj->size - 1) {
            printf(",\n");
        }
    }
    printf("\n}\n");
}

// Free memory associated with the JSON object
void free_json_object(json_object *obj) {
    free(obj);
}

int main() {
    const char *json_input = "{\"name\":\"Ada Lovelace\", \"age\": 30, \"is_programmer\": true, \"skills\": \"Algorithm, Computing\"}";
    json_object *json_obj = parse_json(json_input);

    printf("Parsed JSON Object:\n");
    print_json_object(json_obj);

    free_json_object(json_obj);
    return 0;
}