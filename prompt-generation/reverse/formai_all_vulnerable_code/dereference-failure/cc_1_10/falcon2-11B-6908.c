//Falcon2-11B DATASET v1.0 Category: Building a JSON Parser ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_JSON_SIZE 10000

// Define the JSON structure
typedef struct {
    char* key;
    char* value;
} json_t;

// Function to parse the JSON string into a structure
json_t* parse_json(const char* json) {
    json_t* result = (json_t*)malloc(sizeof(json_t));
    result->key = (char*)malloc(strlen(json) + 1);
    strcpy(result->key, json);

    int i = 0;
    int j = 0;
    int open_brackets = 0;
    int close_brackets = 0;

    while (i < strlen(json)) {
        if (json[i] == '{' || json[i] == '[' || json[i] == '"' || json[i] == '\'') {
            open_brackets++;
        }
        else if (json[i] == '}' || json[i] == ']' || json[i] == '"' || json[i] == '\'') {
            close_brackets++;
        }
        else if (json[i] == ',' && open_brackets == close_brackets) {
            result->value = (char*)malloc(strlen(json) + 1);
            strcpy(result->value, json + j);
            j = i + 1;
            open_brackets = 0;
            close_brackets = 0;
        }
        i++;
    }
    result->value = (char*)malloc(strlen(json) + 1);
    strcpy(result->value, json + j);
    return result;
}

int main() {
    // Open the JSON file
    FILE* fp = fopen("sample.json", "r");
    if (fp == NULL) {
        fprintf(stderr, "Error opening file\n");
        return 1;
    }

    // Read the JSON file
    char json[MAX_JSON_SIZE];
    fgets(json, MAX_JSON_SIZE, fp);

    // Parse the JSON string into a structure
    json_t* result = parse_json(json);
    if (result == NULL) {
        fprintf(stderr, "Error parsing JSON\n");
        return 1;
    }

    // Print the key-value pairs
    printf("Key: %s, Value: %s\n", result->key, result->value);

    // Free the memory
    free(result->key);
    free(result->value);
    free(result);

    // Close the file
    fclose(fp);

    return 0;
}