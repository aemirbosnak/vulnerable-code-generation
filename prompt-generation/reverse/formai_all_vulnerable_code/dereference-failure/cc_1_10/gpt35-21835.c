//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struct for JSON object
typedef struct {
    char name[50];
    char value[50];
} JSONObject;

// Function to parse JSON string into array of JSON objects
JSONObject* parseJSON(char* jsonString, int* count) {
    JSONObject* objects = NULL;
    char* token;
    char* rest = jsonString;
    int i = 0;

    // Parse each line of the string as a JSON object
    while ((token = strtok_r(rest, "\n", &rest))) {
        // Allocate memory for new object
        objects = realloc(objects, (i + 1) * sizeof(JSONObject));

        // Parse object string
        char* name = strtok(token, ":");
        char* value = strtok(NULL, ":");
        if (name != NULL && value != NULL) {
            // Remove quotes and new line characters
            name[strcspn(name, "\"\n")] = '\0';
            value[strcspn(value, "\"\n")] = '\0';

            // Copy object values into struct
            strcpy(objects[i].name, name);
            strcpy(objects[i].value, value);
            i++;
        }
    }

    // Set count of objects parsed
    *count = i;

    return objects;
}

int main() {
    // Example JSON string
    char* jsonString = "{\"name\": \"John\", \n \"age\": \"25\", \n \"city\": \"New York\"}";

    // Parse JSON string into array of JSON objects
    int count;
    JSONObject* objects = parseJSON(jsonString, &count);

    // Print parsed objects
    for (int i = 0; i < count; i++) {
        printf("%s: %s \n", objects[i].name, objects[i].value);
    }

    // Free allocated memory
    free(objects);

    return 0;
}