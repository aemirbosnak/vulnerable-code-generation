//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struct to represent a JSON object
typedef struct {
    char *key;
    char *value;
} JSONObject;

// Function to parse the JSON string and return an array of JSONObjects
JSONObject* parseJSON(char *json, int *numObjects) {
    // Declare necessary variables
    int numObjectsFound = 0, i = 0, j = 0;

    // Find the number of objects in the JSON string
    while (json[i] != '\0') {
        if (json[i] == '{') {
            numObjectsFound++;
        }
        i++;
    }

    // Allocate memory for the array of JSONObjects
    JSONObject* objArray = malloc(numObjectsFound * sizeof(JSONObject));

    // Parse the JSON string to populate the array of JSONObjects
    i = 0;
    while (json[i] != '\0') {
        if (json[i] == '{') {
            j = i + 1;
            while (json[j] != '}') {
                if (json[j] == ':') {
                    // Found a key-value pair, extract the key and value
                    char *key = malloc((j - i) * sizeof(char));
                    char *value = malloc((strlen(json) - j - 1) * sizeof(char));
                    memcpy(key, json + i + 1, j - i - 1);
                    key[j - i - 1] = '\0';
                    memcpy(value, json + j + 1, strlen(json) - j - 1);
                    value[strlen(json) - j - 2] = '\0';

                    // Assign the key-value pair to the next object in the array
                    objArray[numObjectsFound - 1].key = key;
                    objArray[numObjectsFound - 1].value = value;

                    // Increment the number of objects found and the index of the array
                    numObjectsFound--;
                    break;
                }
                j++;
            }
        }
        i++;
    }

    // Set the number of objects found and return the array of JSONObjects
    *numObjects = numObjectsFound;
    return objArray;
}

int main() {
    // Sample JSON string to parse
    char *jsonString = "{\"name\": \"John Smith\", \"age\": 30, \"city\": \"New York\"}";

    // Parse the JSON string and obtain the resulting array of JSONObjects
    int numObjects;
    JSONObject *objectArray = parseJSON(jsonString, &numObjects);

    // Print out the key and value for each key-value pair in each JSONObject
    for (int i = 0; i < numObjects; i++) {
        printf("Key: %s, Value: %s\n", objectArray[i].key, objectArray[i].value);
    }

    return 0;
}