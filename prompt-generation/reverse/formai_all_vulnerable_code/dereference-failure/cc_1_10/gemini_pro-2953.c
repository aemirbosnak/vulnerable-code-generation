//GEMINI-pro DATASET v1.0 Category: Building a JSON Parser ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_JSON_LENGTH 1024

typedef struct {
    char *key;
    char *value;
} JSONPair;

typedef struct {
    JSONPair *pairs;
    int length;
} JSONObject;

JSONObject *parse_json(char *json) {
    // Allocate memory for the JSON object
    JSONObject *object = malloc(sizeof(JSONObject));
    object->length = 0;
    object->pairs = NULL;

    // Copy the JSON string
    char *json_copy = malloc(strlen(json) + 1);
    strcpy(json_copy, json);

    // Parse the JSON string
    char *current_key = NULL;
    char *current_value = NULL;
    char *current_char = json_copy;
    while (*current_char != '\0') {
        // Skip whitespace
        while (*current_char == ' ' || *current_char == '\t' || *current_char == '\n' || *current_char == '\r') {
            current_char++;
        }

        // Check for a colon
        if (*current_char == ':') {
            // End the key and start the value
            *current_char = '\0';
            current_key = current_char + 1;
            current_char++;

            // Skip whitespace
            while (*current_char == ' ' || *current_char == '\t' || *current_char == '\n' || *current_char == '\r') {
                current_char++;
            }

            // Check for a quotation mark
            if (*current_char == '"') {
                // Start the value
                current_value = current_char + 1;
                current_char++;

                // Find the end of the value
                while (*current_char != '"' && *current_char != '\0') {
                    current_char++;
                }

                // End the value
                *current_char = '\0';

                // Add the pair to the object
                object->pairs = realloc(object->pairs, (object->length + 1) * sizeof(JSONPair));
                object->pairs[object->length].key = current_key;
                object->pairs[object->length].value = current_value;
                object->length++;

                // Move to the next character
                current_char++;
            }
        }

        // Check for a comma
        else if (*current_char == ',') {
            // End the key
            *current_char = '\0';

            // Move to the next character
            current_char++;
        }

        // Check for a closing brace
        else if (*current_char == '}') {
            // End the object
            *current_char = '\0';

            // Break the loop
            break;
        }

        // Move to the next character
        current_char++;
    }

    // Free the JSON copy
    free(json_copy);

    // Return the JSON object
    return object;
}

void print_json_object(JSONObject *object) {
    // Print the object
    printf("{");
    for (int i = 0; i < object->length; i++) {
        printf("\"%s\": \"%s\"", object->pairs[i].key, object->pairs[i].value);
        if (i < object->length - 1) {
            printf(", ");
        }
    }
    printf("}\n");
}

void free_json_object(JSONObject *object) {
    // Free the pairs
    for (int i = 0; i < object->length; i++) {
        free(object->pairs[i].key);
        free(object->pairs[i].value);
    }

    // Free the object
    free(object->pairs);
    free(object);
}

int main() {
    // Get the JSON string
    char *json = "{\"name\": \"John Doe\", \"age\": 30}";

    // Parse the JSON string
    JSONObject *object = parse_json(json);

    // Print the JSON object
    print_json_object(object);

    // Free the JSON object
    free_json_object(object);

    return 0;
}