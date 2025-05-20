//GEMINI-pro DATASET v1.0 Category: Building a JSON Parser ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *key;
    char *value;
} JSONPair;

typedef struct {
    JSONPair *pairs;
    int numPairs;
} JSONObject;

JSONObject *parseJSON(char *json) {
    JSONObject *object = malloc(sizeof(JSONObject));
    object->pairs = NULL;
    object->numPairs = 0;

    char *token = strtok(json, ",");
    while (token != NULL) {
        char *key = strtok(token, ":");
        char *value = strtok(NULL, ":");

        JSONPair *pair = malloc(sizeof(JSONPair));
        pair->key = key;
        pair->value = value;

        object->pairs = realloc(object->pairs, (object->numPairs + 1) * sizeof(JSONPair));
        object->pairs[object->numPairs++] = *pair;

        token = strtok(NULL, ",");
    }

    return object;
}

void printJSON(JSONObject *object) {
    for (int i = 0; i < object->numPairs; i++) {
        printf("%s: %s\n", object->pairs[i].key, object->pairs[i].value);
    }
}

int main() {
    char *json = "{ \"name\": \"John Doe\", \"age\": 30, \"city\": \"New York\" }";

    JSONObject *object = parseJSON(json);
    printJSON(object);

    return 0;
}