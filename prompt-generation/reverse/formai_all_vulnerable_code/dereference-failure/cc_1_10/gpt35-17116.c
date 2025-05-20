//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: sophisticated
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// Struct to store JSON key-value pair
typedef struct keyValPair {
    char *key;
    char *value;
} keyValPair;

// Function to parse JSON string and return array of key-value pairs
keyValPair *parseJsonString(char *jsonString, int *numPairs) {
    // First, count number of key-value pairs in the JSON string
    int count = 0;
    char *ptr = jsonString;
    while (*ptr) {
        if (*ptr == '{') {
            count++;
        }
        ptr++;
    }

    // Allocate memory for array of key-value pairs
    keyValPair *pairs = (keyValPair *) malloc(count * sizeof(keyValPair));

    // Parse JSON string and extract key-value pairs
    int index = 0;
    ptr = jsonString;
    while (*ptr) {
        if (*ptr == '{') {
            char *keyStart = NULL, *keyEnd = NULL, *valStart = NULL, *valEnd = NULL;
            ptr++;
            while (*ptr != '}') {
                if (*ptr == '\"') {
                    if (keyStart == NULL) {
                        keyStart = ptr + 1;
                    } else if (keyEnd == NULL) {
                        keyEnd = ptr;
                    } else if (valStart == NULL) {
                        valStart = ptr + 1;
                    } else if (valEnd == NULL) {
                        valEnd = ptr;
                    }
                }
                ptr++;
            }

            // Extract key and value strings
            int keyLen = keyEnd - keyStart;
            char *keyStr = (char *) malloc((keyLen + 1) * sizeof(char));
            strncpy(keyStr, keyStart, keyLen);
            keyStr[keyLen] = '\0';

            int valLen = valEnd - valStart;
            char *valStr = (char *) malloc((valLen + 1) * sizeof(char));
            strncpy(valStr, valStart, valLen);
            valStr[valLen] = '\0';

            // Store key-value pair in array
            pairs[index].key = keyStr;
            pairs[index].value = valStr;
            index++;
        }
        ptr++;
    }

    *numPairs = count;
    return pairs;
}

int main() {
    // Example JSON string
    char jsonString[] = "{\"name\":\"John\",\"age\":30,\"city\":\"New York\"}";

    // Parse JSON string and print key-value pairs
    int numPairs;
    keyValPair *pairs = parseJsonString(jsonString, &numPairs);
    for (int i = 0; i < numPairs; i++) {
        printf("%s: %s\n", pairs[i].key, pairs[i].value);
    }

    // Free allocated memory
    for (int i = 0; i < numPairs; i++) {
        free(pairs[i].key);
        free(pairs[i].value);
    }
    free(pairs);

    return 0;
}