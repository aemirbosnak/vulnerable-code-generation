//GPT-4o-mini DATASET v1.0 Category: Building a JSON Parser ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_KEY_LEN 128
#define MAX_VAL_LEN 256
#define MAX_JSON_LEN 1024

// Function prototypes
void trim_whitespace(char *str);
int parse_json(const char *json);
void extract_key_value(const char *json, int *index);

int main() {
    char json[MAX_JSON_LEN];

    printf("Enter a JSON string: ");
    if (fgets(json, sizeof(json), stdin) == NULL) {
        fprintf(stderr, "Error reading input.\n");
        return 1;
    }

    // Remove trailing newline character
    json[strcspn(json, "\n")] = 0;

    // Parsing JSON
    if (parse_json(json) != 0) {
        fprintf(stderr, "Failed to parse JSON.\n");
        return 1;
    }

    return 0;
}

// Function to trim leading and trailing whitespace from a string
void trim_whitespace(char *str) {
    char *end;

    // Trim leading space
    while (isspace((unsigned char)*str)) str++;

    // Trim trailing space
    end = str + strlen(str) - 1;
    while (end > str && isspace((unsigned char)*end)) end--;

    // Null terminate the trimmed string
    *(end + 1) = '\0';
}

// Function to parse the JSON string
int parse_json(const char *json) {
    int index = 0;
    char c;

    // Check for opening brace
    if (json[index] != '{') {
        fprintf(stderr, "JSON must start with '{'\n");
        return -1;
    }
    index++;

    while (json[index] != '\0') {
        // Ignore white space
        while (isspace(json[index])) index++;

        // Check for closing brace
        if (json[index] == '}') {
            return 0;  // Successfully reached the end
        }

        // Extract key-value pair
        extract_key_value(json, &index);
    }

    fprintf(stderr, "JSON parsing error: Missing closing brace\n");
    return -1;
}

// Function to extract key-value pairs from JSON
void extract_key_value(const char *json, int *index) {
    char key[MAX_KEY_LEN], value[MAX_VAL_LEN];

    // Extract key
    if (json[*index] != '"') {
        fprintf(stderr, "Expected '\"' at index %d for key\n", *index);
        return;
    }
    (*index)++;  // Skip opening quote

    // Read the key
    int key_len = 0;
    while (json[*index] != '"' && json[*index] != '\0') {
        if (key_len < MAX_KEY_LEN - 1) {
            key[key_len++] = json[*index];
        }
        (*index)++;
    }
    key[key_len] = '\0';
    (*index)++;  // Skip closing quote

    // Trim whitespace
    trim_whitespace(key);

    // Skip whitespace and expected colon
    while (isspace(json[*index])) (*index)++;
    if (json[*index] != ':') {
        fprintf(stderr, "Expected ':' after key at index %d\n", *index);
        return;
    }
    (*index)++;  // Skip colon

    // Extract value
    while (isspace(json[*index])) (*index)++;
    if (json[*index] != '"') {
        fprintf(stderr, "Expected '\"' at index %d for value\n", *index);
        return;
    }
    (*index)++;  // Skip opening quote

    // Read the value
    int value_len = 0;
    while (json[*index] != '"' && json[*index] != '\0') {
        if (value_len < MAX_VAL_LEN - 1) {
            value[value_len++] = json[*index];
        }
        (*index)++;
    }
    value[value_len] = '\0';
    (*index)++;  // Skip closing quote

    // Trim whitespace
    trim_whitespace(value);

    // Output the key-value pair
    printf("Key: %s, Value: %s\n", key, value);
}