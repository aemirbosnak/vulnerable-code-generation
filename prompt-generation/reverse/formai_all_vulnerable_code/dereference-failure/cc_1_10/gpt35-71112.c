//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Define a simple structure for storing key-value pairs */
typedef struct {
    char *key;
    char *value;
} KeyValuePair;

/* Define a function to parse a JSON string and return an array of KeyValuePair structures */
KeyValuePair* parseJSON(char* jsonString, int* numPairs) {
    /* Allocate memory for the array of KeyValuePair structures */
    KeyValuePair *pairs = (KeyValuePair*)malloc(sizeof(KeyValuePair) * 10);
    
    /* Initialize variables for iterating through the string */
    char *p = jsonString;
    char *start = NULL, *end = NULL;
    char *keyStart = NULL, *keyEnd = NULL;
    char *valueStart = NULL, *valueEnd = NULL;
    
    /* Initialize variables for tracking the number of pairs and the current pair index */
    int pairCount = 0;
    int pairIndex = 0;
    
    /* Iterate through the string */
    while (*p != '\0') {
        /* Look for the start of a new pair */
        if (*p == '{') {
            pairCount++;
            /* If we've reached the maximum number of pairs allocated in the array, double the capacity */
            if (pairCount > 10) {
                pairs = (KeyValuePair*)realloc(pairs, sizeof(KeyValuePair) * pairCount * 2);
            }
            /* Move to the start of the key */
            start = p + 1;
        }
        /* Look for the end of a key */
        else if (*p == ':') {
            /* Move to the end of the key */
            keyEnd = p - 1;
            /* Allocate memory for the key and copy it from the string */
            pairs[pairIndex].key = (char*)malloc(sizeof(char) * (keyEnd - keyStart + 2));
            strncpy(pairs[pairIndex].key, keyStart, keyEnd - keyStart + 1);
            pairs[pairIndex].key[keyEnd - keyStart + 1] = '\0';
            /* Move to the start of the value */
            valueStart = p + 1;
        }
        /* Look for the end of a value */
        else if (*p == ',' || *p == '}') {
            /* Move to the end of the value */
            valueEnd = p - 1;
            /* Allocate memory for the value and copy it from the string */
            pairs[pairIndex].value = (char*)malloc(sizeof(char) * (valueEnd - valueStart + 2));
            strncpy(pairs[pairIndex].value, valueStart, valueEnd - valueStart + 1);
            pairs[pairIndex].value[valueEnd - valueStart + 1] = '\0';
            /* Move to the start of the next pair, if there is one */
            if (*p == ',') {
                pairIndex++;
                start = p + 1;
            }
        }
        /* Look for the start of a key */
        else if (*p == '"') {
            if (keyStart == NULL) {
                /* Move to the start of the key */
                keyStart = p + 1;
            } else {
                /* Move to the end of the value */
                valueEnd = p - 1;
                /* Allocate memory for the value and copy it from the string */
                pairs[pairIndex].value = (char*)malloc(sizeof(char) * (valueEnd - valueStart + 2));
                strncpy(pairs[pairIndex].value, valueStart, valueEnd - valueStart + 1);
                pairs[pairIndex].value[valueEnd - valueStart + 1] = '\0';
                /* Move to the start of the next pair */
                pairIndex++;
                start = p + 1;
                /* Reset keyStart so we know we're looking for a new key */
                keyStart = NULL;
            }
        }
        /* Move to the next character */
        p++;
    }
    
    /* Set numPairs to the number of pairs we've found */
    *numPairs = pairCount;
    
    /* Return the array of KeyValuePair structures */
    return pairs;
}

int main() {
    /* Define a test JSON string */
    char jsonString[] = "{\"name\":\"John\",\"age\":30,\"city\":\"New York\"}";
    
    /* Parse the JSON string */
    int numPairs = 0;
    KeyValuePair *pairs = parseJSON(jsonString, &numPairs);
    
    /* Output the contents of the array */
    for (int i = 0; i < numPairs; i++) {
        printf("%s: %s\n", pairs[i].key, pairs[i].value);
    }
    
    /* Free the memory allocated for the array and its contents */
    for (int i = 0; i < numPairs; i++) {
        free(pairs[i].key);
        free(pairs[i].value);
    }
    free(pairs);
    
    return 0;
}