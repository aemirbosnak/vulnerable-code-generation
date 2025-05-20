//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_KEYS 20
#define MAX_VALUE_LENGTH 100

// Define a structure for storing key-value pairs
typedef struct {
    char *key;
    char *value;
} KeyValue;

// Define a structure for storing JSON objects
typedef struct {
    KeyValue keyValues[MAX_KEYS];
    int numKeyValues;
} JSONObject;

// Function for parsing JSON objects
JSONObject parseJSONObject(char *JSONString);

// Function for parsing individual key-value pairs
KeyValue parseKeyValue(char *JSONString, int *index);

int main() {
    // Define a sample JSON string
    char *JSONString = "{\"name\": \"John\", \"age\": 42, \"city\": \"New York\"}";

    // Parse the JSON string into an object
    JSONObject object = parseJSONObject(JSONString);

    // Print the object's key-value pairs
    printf("Parsed JSON object:\n");
    for(int i = 0; i < object.numKeyValues; i++) {
        printf("%s: %s\n", object.keyValues[i].key, object.keyValues[i].value);
    }

    return 0;
}

JSONObject parseJSONObject(char *JSONString) {
    // Initialize the object with an empty array of key-value pairs
    JSONObject object;
    object.numKeyValues = 0;

    // Skip the opening curly brace
    int index = 1;

    // Loop through the rest of the string until the closing curly brace is reached
    while(JSONString[index] != '}') {
        // Parse the next key-value pair
        KeyValue keyValue = parseKeyValue(JSONString, &index);

        // Add the key-value pair to the object if it is valid
        if(keyValue.key != NULL && keyValue.value != NULL && object.numKeyValues < MAX_KEYS) {
            object.keyValues[object.numKeyValues] = keyValue;
            object.numKeyValues++;
        }
    }

    return object;
}

KeyValue parseKeyValue(char *JSONString, int *index) {
    // Initialize the key-value pair with NULL values
    KeyValue keyValue;
    keyValue.key = NULL;
    keyValue.value = NULL;

    // Skip any whitespace characters
    while(JSONString[*index] == ' ' || JSONString[*index] == '\t' || JSONString[*index] == '\n') {
        (*index)++;
    }

    // Parse the key
    int keyStart = *index;
    while(JSONString[*index] != ':' && JSONString[*index] != '}') {
        (*index)++;
    }
    int keyLength = *index - keyStart;

    // Skip the colon and any whitespace characters
    (*index)++;
    while(JSONString[*index] == ' ' || JSONString[*index] == '\t' || JSONString[*index] == '\n') {
        (*index)++;
    }

    // Parse the value
    int valueStart = *index;
    int valueLength = 0;
    if(JSONString[*index] == '\"') {
        // Parse a string value
        (*index)++;
        while(JSONString[*index] != '\"' && JSONString[*index] != '\0') {
            (*index)++;
        }
        valueLength = *index - valueStart - 1;
        (*index)++;
    } else {
        // Parse a numeric value
        while(JSONString[*index] != ',' && JSONString[*index] != '\0' && JSONString[*index] != '}') {
            (*index)++;
        }
        valueLength = *index - valueStart;
    }

    // Allocate memory for the key and value strings
    if(keyLength > 0 && valueLength > 0) {
        char *key = (char*) malloc(keyLength + 1);
        strncpy(key, JSONString + keyStart, keyLength);
        key[keyLength] = '\0';
        char *value = (char*) malloc(valueLength + 1);
        strncpy(value, JSONString + valueStart, valueLength);
        value[valueLength] = '\0';
        keyValue.key = key;
        keyValue.value = value;
    }

    return keyValue;
}