//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 1000

// Struct to hold the key-value pairs of a JSON object
struct KeyValue {
    char key[MAX_SIZE];
    char value[MAX_SIZE];
};
typedef struct KeyValue KeyValue;

// Function to parse a JSON object and return an array of KeyValue structs
KeyValue* parseJSON(char* json) {
    int i = 1; // Start at index 1 to skip opening brace

    KeyValue* kvPairs = malloc(sizeof(KeyValue) * MAX_SIZE); // Allocate memory for key-value pairs
    int numPairs = 0;

    while (json[i] != '}') { // Loop until end of object
        while (isspace(json[i])) i++; // Skip whitespace

        // Parse key
        int j = 0;
        while (json[i] != ':') {
            kvPairs[numPairs].key[j] = json[i];
            i++; j++;
        }
        kvPairs[numPairs].key[j] = '\0';

        i++; // Skip colon

        // Parse value
        j = 0;
        while (json[i] != ',' && json[i] != '}') {
            kvPairs[numPairs].value[j] = json[i];
            i++; j++;
        }
        kvPairs[numPairs].value[j] = '\0';

        numPairs++; // Increment number of key-value pairs
        if (json[i] == '}') break; // End loop if end of object
        i++; // Skip comma
    }

    return kvPairs;
}

int main() {
    char* json = "{ \"name\": \"John\", \"age\": 42, \"city\": \"London\" }";

    KeyValue* kvPairs = parseJSON(json);
    printf("Key-Value Pairs:\n");
    for (int i = 0; i < 3; i++) {
        printf("%s: %s\n", kvPairs[i].key, kvPairs[i].value);
    }

    free(kvPairs); // Free allocated memory

    return 0;
}