//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: Romeo and Juliet
/* 
 * Romeo, oh Romeo! Wherefore art thou Romeo?
 * I need thee to write a JSON parser for me.
 * Forsooth, it shall be the finest in all the land!
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Define some constants
#define MAX_DEPTH 10
#define MAX_KEY_LENGTH 50
#define MAX_VALUE_LENGTH 100

// Define the JSON structure
typedef struct JSON {
    char key[MAX_KEY_LENGTH];
    char value[MAX_VALUE_LENGTH];
    bool is_object;
    struct JSON *sub_json;
} JSON;

// Define our JSON parser function
JSON* parse_json(char *json_string, int depth) {
    JSON *json = (JSON*) malloc(sizeof(JSON));
    char curr_char;
    char curr_key[MAX_KEY_LENGTH] = "";
    int key_index = 0;
    char curr_value[MAX_VALUE_LENGTH] = "";
    int value_index = 0;
    bool is_key = true;
    bool is_value = false;
    bool is_object = false;
    int object_count = 0;

    while (*json_string != '\0') {
        curr_char = *json_string;

        // If we're at max depth, return NULL
        if (depth >= MAX_DEPTH) {
            return NULL;
        }

        // Process the current character
        switch (curr_char) {
            case '{':
                // If we're already in an object, create a sub-json struct
                if (is_object) {
                    json->sub_json = parse_json(json_string, depth + 1);
                }
                object_count++;
                is_object = true;
                break;
            case ':':
                is_key = false;
                is_value = true;
                break;
            case ',':
                // If we're in an object, create a sub-json struct
                if (is_object && object_count <= 1) {
                    json->sub_json = parse_json(json_string, depth + 1);
                }
                key_index = 0;
                value_index = 0;
                is_key = true;
                is_value = false;
                break;
            case '}':
                if (is_value) {
                    strncpy(json->value, curr_value, value_index);
                }
                object_count--;
                if (object_count == 0) {
                    is_object = false;
                    return json;
                }
                break;
            default:
                if (is_key) {
                    curr_key[key_index] = curr_char;
                    key_index++;
                } else if (is_value) {
                    curr_value[value_index] = curr_char;
                    value_index++;
                }
                break;
        }

        // Move to the next character
        json_string++;
    }

    return NULL;
}

int main() {
    // Example JSON string
    char *example_json_string = "{"
        "\"name\": \"Romeo\", "
        "\"age\": 21, "
        "\"address\": {"
            "\"street\": \"123 Main St.\", "
            "\"city\": \"Verona\", "
            "\"state\": \"Italy\""
        "}"
    "}";

    // Parse the JSON string
    JSON *json = parse_json(example_json_string, 0);

    // Print the parsed JSON
    printf("Key: %s\n", json->key);
    printf("Value: %s\n", json->value);
    printf("Is object: %d\n", json->is_object);
    if (json->sub_json != NULL) {
        printf("Sub-json:\n");
        printf("  Key: %s\n", json->sub_json->key);
        printf("  Value: %s\n", json->sub_json->value);
        printf("  Is object: %d\n", json->sub_json->is_object);
        if (json->sub_json->sub_json != NULL) {
            printf("  Sub-json:\n");
            printf("    Key: %s\n", json->sub_json->sub_json->key);
            printf("    Value: %s\n", json->sub_json->sub_json->value);
            printf("    Is object: %d\n", json->sub_json->sub_json->is_object);
        }
    }

    return 0;
}