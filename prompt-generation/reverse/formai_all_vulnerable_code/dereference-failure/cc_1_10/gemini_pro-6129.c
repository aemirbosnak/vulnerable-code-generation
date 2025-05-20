//GEMINI-pro DATASET v1.0 Category: Building a JSON Parser ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_JSON_SIZE 1024

typedef struct {
    char *key;
    char *value;
} JSONElement;

typedef struct {
    size_t size;
    JSONElement *elements;
} JSON;

JSON *parse_json(char *json_string) {
    JSON *json = malloc(sizeof(JSON));
    json->size = 0;
    json->elements = NULL;

    char *json_copy = strdup(json_string);
    char *json_ptr = json_copy;

    while (*json_ptr != '\0') {
        // Skip whitespace
        while (*json_ptr == ' ' || *json_ptr == '\t' || *json_ptr == '\n' || *json_ptr == '\r') {
            json_ptr++;
        }

        // Check for the start of an object
        if (*json_ptr == '{') {
            json_ptr++;
            // Parse the object
            JSON *object = parse_json(json_ptr);
            // Add the object to the array of elements
            json->elements = realloc(json->elements, (json->size + 1) * sizeof(JSONElement));
            json->elements[json->size].key = NULL;
            json->elements[json->size].value = object;
            json->size++;
            // Skip to the end of the object
            while (*json_ptr != '}' && *json_ptr != '\0') {
                json_ptr++;
            }
            if (*json_ptr == '}') {
                json_ptr++;
            }
        }
        // Check for the start of an array
        else if (*json_ptr == '[') {
            json_ptr++;
            // Parse the array
            JSON *array = parse_json(json_ptr);
            // Add the array to the array of elements
            json->elements = realloc(json->elements, (json->size + 1) * sizeof(JSONElement));
            json->elements[json->size].key = NULL;
            json->elements[json->size].value = array;
            json->size++;
            // Skip to the end of the array
            while (*json_ptr != ']' && *json_ptr != '\0') {
                json_ptr++;
            }
            if (*json_ptr == ']') {
                json_ptr++;
            }
        }
        // Check for a key-value pair
        else if (*json_ptr == '"') {
            json_ptr++;
            // Parse the key
            char *key = json_ptr;
            while (*json_ptr != '"' && *json_ptr != '\0') {
                json_ptr++;
            }
            *json_ptr = '\0';
            json_ptr++;
            // Parse the value
            char *value = json_ptr;
            while (*json_ptr != ',' && *json_ptr != '}' && *json_ptr != ']' && *json_ptr != '\0') {
                json_ptr++;
            }
            *json_ptr = '\0';
            json_ptr++;
            // Add the key-value pair to the array of elements
            json->elements = realloc(json->elements, (json->size + 1) * sizeof(JSONElement));
            json->elements[json->size].key = strdup(key);
            json->elements[json->size].value = strdup(value);
            json->size++;
        }
        // Skip everything else
        else {
            json_ptr++;
        }
    }

    free(json_copy);

    return json;
}

void print_json(JSON *json, int level) {
    for (size_t i = 0; i < json->size; i++) {
        if (json->elements[i].key != NULL) {
            for (int j = 0; j < level; j++) {
                printf("  ");
            }
            printf("%s: ", json->elements[i].key);
            if (json->elements[i].value != NULL) {
                print_json(json->elements[i].value, level + 1);
            }
        } else {
            for (int j = 0; j < level; j++) {
                printf("  ");
            }
            printf("%s\n", json->elements[i].value);
        }
    }
}

void free_json(JSON *json) {
    for (size_t i = 0; i < json->size; i++) {
        if (json->elements[i].key != NULL) {
            free(json->elements[i].key);
        }
        if (json->elements[i].value != NULL) {
            free_json(json->elements[i].value);
        }
    }
    free(json->elements);
    free(json);
}

int main() {
    // Get the JSON string from the user
    char json_string[MAX_JSON_SIZE];
    printf("Enter a JSON string: ");
    fgets(json_string, MAX_JSON_SIZE, stdin);

    // Parse the JSON string
    JSON *json = parse_json(json_string);

    // Print the JSON object
    print_json(json, 0);

    // Free the JSON object
    free_json(json);

    return 0;
}