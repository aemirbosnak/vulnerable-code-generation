//GEMINI-pro DATASET v1.0 Category: Building a JSON Parser ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Type definitions
typedef struct {
    char *key;
    char *value;
} JSONPair;

typedef struct {
    JSONPair *pairs;
    int num_pairs;
} JSONObject;

// Function declarations
JSONObject *parse_json(char *json);
void free_json(JSONObject *json);
void print_json(JSONObject *json);

// Main function
int main() {
    // Parse the JSON string
    char *json_string = "{ \"name\": \"John Doe\", \"age\": 30, \"occupation\": \"Software Engineer\" }";
    JSONObject *json = parse_json(json_string);

    // Print the JSON object
    print_json(json);

    // Free the JSON object
    free_json(json);

    return 0;
}

// Parse the JSON string
JSONObject *parse_json(char *json) {
    // Allocate memory for the JSON object
    JSONObject *json_object = malloc(sizeof(JSONObject));

    // Initialize the JSON object
    json_object->pairs = NULL;
    json_object->num_pairs = 0;

    // Parse the JSON string
    char *start = json;
    while (*start != '\0') {
        // Skip whitespace
        while (isspace(*start)) {
            start++;
        }

        // Check for the start of a key
        if (*start == '"') {
            // Get the key
            char *key_start = start + 1;
            char *key_end = strchr(start + 1, '"');
            if (key_end == NULL) {
                // Invalid JSON: missing closing quote for key
                return NULL;
            }
            int key_len = key_end - key_start;
            char *key = malloc(key_len + 1);
            memcpy(key, key_start, key_len);
            key[key_len] = '\0';

            // Skip the colon
            start = key_end + 1;
            while (isspace(*start)) {
                start++;
            }
            if (*start != ':') {
                // Invalid JSON: missing colon after key
                free(key);
                return NULL;
            }
            start++;

            // Skip whitespace
            while (isspace(*start)) {
                start++;
            }

            // Get the value
            char *value_start = start;
            char *value_end;
            switch (*start) {
                case '"':
                    // String value
                    value_end = strchr(start + 1, '"');
                    if (value_end == NULL) {
                        // Invalid JSON: missing closing quote for value
                        free(key);
                        return NULL;
                    }
                    break;
                case '{':
                    // Object value
                    value_end = strchr(start + 1, '}');
                    if (value_end == NULL) {
                        // Invalid JSON: missing closing brace for value
                        free(key);
                        return NULL;
                    }
                    break;
                case '[':
                    // Array value
                    value_end = strchr(start + 1, ']');
                    if (value_end == NULL) {
                        // Invalid JSON: missing closing bracket for value
                        free(key);
                        return NULL;
                    }
                    break;
                default:
                    // Invalid JSON: unexpected character at start of value
                    free(key);
                    return NULL;
            }
            int value_len = value_end - value_start;
            char *value = malloc(value_len + 1);
            memcpy(value, value_start, value_len);
            value[value_len] = '\0';

            // Add the key-value pair to the JSON object
            json_object->pairs = realloc(json_object->pairs, sizeof(JSONPair) * (json_object->num_pairs + 1));
            json_object->pairs[json_object->num_pairs].key = key;
            json_object->pairs[json_object->num_pairs].value = value;
            json_object->num_pairs++;

            // Skip the comma or closing brace
            start = value_end + 1;
            while (isspace(*start)) {
                start++;
            }
            if (*start == ',' || *start == '}') {
                start++;
            }
        }
    }

    return json_object;
}

// Free the JSON object
void free_json(JSONObject *json) {
    for (int i = 0; i < json->num_pairs; i++) {
        free(json->pairs[i].key);
        free(json->pairs[i].value);
    }
    free(json->pairs);
    free(json);
}

// Print the JSON object
void print_json(JSONObject *json) {
    printf("{");
    for (int i = 0; i < json->num_pairs; i++) {
        if (i > 0) {
            printf(", ");
        }
        printf("\"%s\": \"%s\"", json->pairs[i].key, json->pairs[i].value);
    }
    printf("}");
}