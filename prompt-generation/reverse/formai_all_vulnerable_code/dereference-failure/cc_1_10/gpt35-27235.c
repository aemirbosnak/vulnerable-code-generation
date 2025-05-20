//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the JSON structure
typedef struct {
    char *key;
    char *value;
} JSON;

// Parse the JSON string and return an array of JSON objects
JSON *parseJSON(char *jsonString, int *count) {
    char *token, *rest;
    int i = 0, arr_size = 10;
    JSON *jsonArray = malloc(sizeof(JSON) * arr_size);
    
    // Loop through the string and tokenize it
    for (token = strtok_r(jsonString, "{}\":,", &rest); token != NULL; token = strtok_r(NULL, "{}\":,", &rest)) {
        
        // Check if the token is a key or value
        if (i % 2 == 0) {
            // Allocate memory for the key
            jsonArray[i/2].key = malloc(strlen(token) + 1);
            strcpy(jsonArray[i/2].key, token);
        } else {
            // Allocate memory for the value
            jsonArray[i/2].value = malloc(strlen(token) + 1);
            strcpy(jsonArray[i/2].value, token);
        }
        
        i++;
        
        // If the array is full, reallocate more memory
        if (i/2 >= arr_size) {
            arr_size *= 2;
            jsonArray = realloc(jsonArray, sizeof(JSON) * arr_size);
        }
    }
    
    *count = i/2;
    return jsonArray;
}

int main() {
    char *jsonString = "{\"name\":\"John Doe\",\"age\":30,\"city\":\"New York\"}";
    int count = 0;
    JSON *jsonArray = parseJSON(jsonString, &count);
    
    // Print each JSON object
    for (int i = 0; i < count; i++) {
        printf("%s: %s\n", jsonArray[i].key, jsonArray[i].value);
    }
    
    // Free the memory used by the JSON objects
    for (int i = 0; i < count; i++) {
        free(jsonArray[i].key);
        free(jsonArray[i].value);
    }
    
    free(jsonArray);
    return 0;
}