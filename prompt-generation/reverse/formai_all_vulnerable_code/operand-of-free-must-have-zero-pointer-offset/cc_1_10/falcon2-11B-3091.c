//Falcon2-11B DATASET v1.0 Category: Building a JSON Parser ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define BUFFER_SIZE 1024

// Function to parse a JSON object and print out the values of the "name" and "age" fields
void parseJSON(char* json, size_t length) {
    // JSON object format: { "name": "John Doe", "age": 30 }
    char* name = NULL;
    char* age = NULL;
    char* value = NULL;

    // Find the end of the JSON object
    char* end = json + length;
    while (json < end && *json!= '}') {
        json++;
    }

    // Check if the JSON object is valid
    if (json >= end) {
        printf("Invalid JSON object\n");
        return;
    }

    // Get the value of the "name" field
    name = strstr(json, "\"name\":");
    if (name!= NULL) {
        name += 8; // Skip "\"name\": "
        value = strstr(name, "\"");
        if (value!= NULL) {
            value += 1; // Skip "
        }
        printf("Name: %s\n", value);
    }

    // Get the value of the "age" field
    age = strstr(json, "\"age\":");
    if (age!= NULL) {
        age += 7; // Skip "\"age\": "
        value = strstr(age, "\"");
        if (value!= NULL) {
            value += 1; // Skip "
        }
        printf("Age: %d\n", atoi(value));
    }

    // Free the memory allocated for the value strings
    free(name);
    free(age);
    free(value);
}

int main() {
    char json[BUFFER_SIZE];
    FILE* file = fopen("data.json", "r");
    if (file == NULL) {
        printf("Error opening file\n");
        return 1;
    }

    fread(json, sizeof(char), BUFFER_SIZE, file);
    fclose(file);

    parseJSON(json, BUFFER_SIZE);

    return 0;
}