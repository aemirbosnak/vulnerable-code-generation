//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Define the maximum buffer size for input and output
#define BUFFER_SIZE 1024

// Define structure for JSON object
typedef struct json_object {
    char *key;
    char *value;
} json_object;

// Define function to strip whitespace from a string
void strip_whitespace(char *str) {
    char *src, *dst;
    for (src = dst = str; *src != '\0'; src++) {
        if (!isspace((unsigned char)*src)) {
            *dst++ = *src;
        }
    }
    *dst = '\0';
}

// Define function to parse a JSON object
json_object *parse_object(char *input) {
    char buffer[BUFFER_SIZE];
    json_object *object = malloc(sizeof(json_object));
    if (object == NULL) {
        fprintf(stderr, "Error: out of memory\n");
        exit(EXIT_FAILURE);
    }
    // Find the key
    char *key_start = strchr(input, '"') + 1;
    char *key_end = strchr(key_start, '"');
    int key_length = key_end - key_start;
    if (key_end == NULL) {
        fprintf(stderr, "Error: missing key in JSON object\n");
        exit(EXIT_FAILURE);
    }
    strncpy(object->key, key_start, key_length);
    // Find the value
    char *value_start = strchr(key_end, ':') + 1;
    char *value_end = strchr(value_start, ',');
    if (value_end == NULL) {
        value_end = strchr(value_start, '}');
    }
    if (value_end == NULL) {
        fprintf(stderr, "Error: missing value in JSON object\n");
        exit(EXIT_FAILURE);
    }
    int value_length = value_end - value_start;
    strncpy(object->value, value_start, value_length);
    // Strip whitespace from key and value
    strip_whitespace(object->key);
    strip_whitespace(object->value);
    // Return the parsed object
    return object;
}

int main() {
    // Read input from user
    printf("Enter a JSON string: ");
    char input[BUFFER_SIZE];
    fgets(input, BUFFER_SIZE, stdin);
    // Strip whitespace from input
    strip_whitespace(input);
    // Check if input starts with opening brace
    char *c = input;
    if (c == NULL || *c != '{') {
        fprintf(stderr, "Error: invalid JSON string\n");
        return EXIT_FAILURE;
    }
    // Parse the JSON object
    json_object *object = parse_object(c);
    // Print the parsed object
    printf("Key: %s\nValue: %s\n", object->key, object->value);
    // Free memory
    free(object->key);
    free(object->value);
    free(object);
    return 0;
}