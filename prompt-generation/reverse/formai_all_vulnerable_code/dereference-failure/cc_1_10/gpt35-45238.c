//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Define the JSON object structure
typedef struct {
    char *key;
    char *value;
} JSONObject;

// Define the JSON parser function
JSONObject* parseJSON(char *jsonString) {
    // Initialize the JSON object array
    JSONObject* jsonObjectArray = (JSONObject*)malloc(sizeof(JSONObject));
    int jsonObjectCount = 0;

    // Loop through the JSON string
    char *currentChar = jsonString;
    while (*currentChar != '\0') {
        // Find the beginning of a key
        if (*currentChar == '\"') {
            char *keyStart = currentChar + 1;
            char *keyEnd = strchr(keyStart, '\"');
            if (keyEnd == NULL) {
                printf("Error: Invalid JSON format.");
                exit(1);
            }
            int keyLength = keyEnd - keyStart;
            char *key = (char*)malloc(keyLength + 1);
            strncpy(key, keyStart, keyLength);
            key[keyLength] = '\0';

            // Find the beginning of a value
            currentChar = keyEnd + 1;
            while (isspace(*currentChar)) {
                currentChar++;
            }
            if (*currentChar != ':') {
                printf("Error: Invalid JSON format.");
                exit(1);
            }
            currentChar++;
            while (isspace(*currentChar)) {
                currentChar++;
            }

            // Find the end of the value
            char *valueStart = currentChar;
            char *valueEnd = currentChar;
            if (*valueStart == '{' || *valueStart == '[') {
                int nestingLevel = 1;
                while (nestingLevel > 0 && *valueEnd != '\0') {
                    valueEnd++;
                    if (*valueEnd == '{' || *valueEnd == '[') {
                        nestingLevel++;
                    } else if (*valueEnd == '}' || *valueEnd == ']') {
                        nestingLevel--;
                    }
                }
                if (nestingLevel > 0) {
                    printf("Error: Invalid JSON format.");
                    exit(1);
                }
            } else {
                valueEnd = strchr(valueStart, ',');
                if (valueEnd == NULL) {
                    valueEnd = strchr(valueStart, '}');
                    if (valueEnd == NULL) {
                        printf("Error: Invalid JSON format.");
                        exit(1);
                    }
                } else {
                    valueEnd--;
                }
            }
            int valueLength = valueEnd - valueStart + 1;
            char *value = (char*)malloc(valueLength + 1);
            strncpy(value, valueStart, valueLength);
            value[valueLength] = '\0';

            // Create the JSON object and add it to the array
            jsonObjectArray = (JSONObject*)realloc(jsonObjectArray, (jsonObjectCount + 1) * sizeof(JSONObject));
            jsonObjectArray[jsonObjectCount].key = key;
            jsonObjectArray[jsonObjectCount].value = value;
            jsonObjectCount++;
        }
        currentChar++;
    }

    return jsonObjectArray;
}

int main() {
    // Example JSON string
    char *jsonString = "{\"name\": \"John\", \"age\": 30, \"city\": \"New York\"}";

    // Parse the JSON string
    JSONObject* jsonObjectArray = parseJSON(jsonString);

    // Print the JSON objects
    for (int i = 0; i < sizeof(jsonObjectArray) / sizeof(jsonObjectArray[0]); i++) {
        printf("%s: %s\n", jsonObjectArray[i].key, jsonObjectArray[i].value);
    }

    return 0;
}