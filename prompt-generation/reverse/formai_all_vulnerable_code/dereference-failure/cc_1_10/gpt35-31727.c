//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: invasive
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    char* key;
    char* value;
} KeyValue;

typedef struct {
    KeyValue* base;
    size_t size;
} KeyValueArray;

void initKeyValueArray(KeyValueArray* arr) {
    arr->base = NULL;
    arr->size = 0;
}

void addKeyValue(KeyValueArray* arr, const char* key, const char* value) {
    size_t newSize = arr->size + 1;
    arr->base = realloc(arr->base, newSize * sizeof(KeyValue));
    arr->base[newSize - 1].key = malloc(strlen(key) + 1);
    arr->base[newSize - 1].value = malloc(strlen(value) + 1);
    strcpy(arr->base[newSize - 1].key, key);
    strcpy(arr->base[newSize - 1].value, value);
    arr->size = newSize;
}

KeyValueArray* parseJson(const char* json) {
    KeyValueArray* result = malloc(sizeof(KeyValueArray));
    initKeyValueArray(result);

    // check for empty json
    if (strlen(json) == 0) {
        printf("Error: Empty json.\n");
        return result;
    }

    // strip whitespace from json
    char* strippedJson = malloc(strlen(json) + 1);
    size_t strippedJsonIndex = 0;
    for (size_t i = 0; i < strlen(json); i++) {
        if (json[i] != ' ' && json[i] != '\n' && json[i] != '\t' && json[i] != '\r') {
            strippedJson[strippedJsonIndex] = json[i];
            strippedJsonIndex++;
        }
    }
    strippedJson[strippedJsonIndex] = '\0';

    // check for invalid json
    if (strippedJson[0] != '{' && strippedJson[strlen(strippedJson) - 1] != '}') {
        printf("Error: Invalid json format.\n");
        return result;
    }

    // remove braces from json
    char* keyValueString = malloc(strlen(strippedJson) - 1);
    strncpy(keyValueString, strippedJson + 1, strlen(strippedJson) - 2);
    keyValueString[strlen(keyValueString)] = '\0';

    // loop through key-value pairs
    char* token = strtok(keyValueString, ",");
    while (token != NULL) {
        // split token into key-value pair
        char* keyValuePair = malloc(strlen(token) + 1);
        strcpy(keyValuePair, token);
        char* key = strtok(keyValuePair, ":");
        char* value = strtok(NULL, ":");

        // strip quotes from key and value
        key = strtok(key, "\"");
        value = strtok(value, "\"");

        addKeyValue(result, key, value);

        token = strtok(NULL, ",");
    }

    // free memory
    free(strippedJson);
    free(keyValueString);

    return result;
}

int main() {
    const char* json = "{\"name\": \"Alice\", \"age\": 30}";
    KeyValueArray* result = parseJson(json);

    printf("Parsed %zu key-value pair(s):\n", result->size);
    for (size_t i = 0; i < result->size; i++) {
        printf("%s = %s\n", result->base[i].key, result->base[i].value);
    }

    // free memory
    for (size_t i = 0; i < result->size; i++) {
        free(result->base[i].key);
        free(result->base[i].value);
    }
    free(result->base);
    free(result);

    return 0;
}