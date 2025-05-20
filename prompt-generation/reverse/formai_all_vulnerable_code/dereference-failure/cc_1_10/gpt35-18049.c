//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to hold key-value pair
struct KeyValue {
    char *key;
    char *value;
};

// Structure to hold JSON object
struct JSONObject {
    struct KeyValue *pairs;
    int numPairs;
};

// Parse JSON string and return JSONObject
struct JSONObject* parseJSON(char *jsonString) {
    struct JSONObject *jsonObject = (struct JSONObject*) malloc(sizeof(struct JSONObject));
    int numPairs = 0;
    int maxPairs = 10;

    jsonObject->pairs = (struct KeyValue*) malloc(sizeof(struct KeyValue) * maxPairs);

    char *token = strtok(jsonString, "{,\"}");
    char *lastToken = "";

    while (token != NULL) {
        // check token to see if it is a new pair or just the value part of the previous pair
        if (strcmp(lastToken, ":") == 0) {
            // add new key-value pair
            if (numPairs + 1 >= maxPairs) {
                maxPairs *= 2;
                jsonObject->pairs = (struct KeyValue*) realloc(jsonObject->pairs, sizeof(struct KeyValue) * maxPairs);
            } 
            jsonObject->pairs[numPairs].key = lastToken - 1; //set key of previous pair
            jsonObject->pairs[numPairs].value = token + 1; //set value of new pair
            numPairs++;
        } 
        lastToken = token; //store last seen token
        token = strtok(NULL, "{,\"}");
    }

    jsonObject->numPairs = numPairs;
    return jsonObject;
}

int main() {
    char *jsonString = "{\"name\":\"John\",\"age\":30,\"city\":\"New York\"}";

    struct JSONObject *jsonObject = parseJSON(jsonString);

    printf("Number of key-value pairs: %d\n", jsonObject->numPairs);
    for (int i = 0; i < jsonObject->numPairs; i++) {
        printf("Key: %s, Value: %s\n", jsonObject->pairs[i].key, jsonObject->pairs[i].value);
    }

    free(jsonObject);
    return 0;
}