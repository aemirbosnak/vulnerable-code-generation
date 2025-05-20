//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure for holding JSON key/value pairs
typedef struct json_pair {
    char *key;
    char *value;
} json_pair_t;

// Structure for holding JSON objects
typedef struct json_object {
    int num_pairs;
    json_pair_t **pairs;
} json_object_t;

// Parse a string into a JSON object
json_object_t *parse_json(char *string) {
    // Allocate memory for the top-level JSON object
    json_object_t *object = (json_object_t *) malloc(sizeof(json_object_t));
    object->num_pairs = 0;
    object->pairs = NULL;
    // Begin parsing the string
    char *pos = string;
    char current;
    // Loop through the string, parsing key/value pairs
    while ((current = *pos++) != '\0') {
        // Skip whitespace
        if (current == ' ' || current == '\n' || current == '\r' || current == '\t') {
            continue;
        }
        // Parse the key
        char key[256];
        int key_length = 0;
        while ((current = *pos++) != ':') {
            key[key_length++] = current;
        }
        key[key_length] = '\0';
        // Skip whitespace before the value
        while ((current = *pos++) == ' ' || current == '\n' || current == '\r' || current == '\t') {
            continue;
        }
        // Parse the value
        char value[256];
        int value_length = 0;
        while ((current = *pos++) != ',' && current != '\0') {
            value[value_length++] = current;
        }
        value[value_length] = '\0';
        // Allocate memory for the key/value pair
        json_pair_t *pair = (json_pair_t *) malloc(sizeof(json_pair_t));
        pair->key = strdup(key);
        pair->value = strdup(value);
        // Add the pair to the object
        object->num_pairs++;
        object->pairs = (json_pair_t **) realloc(object->pairs, sizeof(json_pair_t *) * object->num_pairs);
        object->pairs[object->num_pairs - 1] = pair;
    }
    return object;
}

int main() {
    char *json_string = "{ \"name\": \"Alice\", \"age\": 30, \"location\": \"New York\" }";
    json_object_t *object = parse_json(json_string);
    printf("Object contains %d pairs:\n", object->num_pairs);
    for (int i = 0; i < object->num_pairs; i++) {
        printf("%s: %s\n", object->pairs[i]->key, object->pairs[i]->value);
    }
    return 0;
}