//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char* key;
    int value;
} KeyValue;

typedef struct {
    KeyValue* keyValues;
    int size;
} JsonObject;

int currentIndex = 0;

char* extractString(char* jsonString) {
    char* result = malloc(sizeof(char) * 256);
    int quoteCount = 0;
    int index = 0;
    do {
        if(jsonString[currentIndex] == '\"') {
            quoteCount++;
        }
        result[index++] = jsonString[currentIndex++];
    } while(quoteCount < 2 && jsonString[currentIndex] != '\0');
    result[index - 1] = '\0';
    return result;
}

int* extractNumber(char* jsonString) {
    char* result = malloc(sizeof(char) * 256);
    int index = 0;
    do {
        result[index++] = jsonString[currentIndex++];
    } while(jsonString[currentIndex] >= '0' && jsonString[currentIndex] <= '9');
    int* numberValue = malloc(sizeof(int));
    *numberValue = strtol(result, NULL, 10);
    return numberValue;
}

KeyValue extractKeyValue(char* jsonString) {
    KeyValue keyValue;
    keyValue.key = extractString(jsonString);
    currentIndex++; // skip the colon
    currentIndex++; // skip the space
    keyValue.value = *extractNumber(jsonString);
    return keyValue;
}

JsonObject* parseJSON(char* jsonString) {
    currentIndex = 0;
    JsonObject* jsonObject = malloc(sizeof(JsonObject));
    KeyValue* keyValues = malloc(sizeof(KeyValue) * 10);
    int keyValuesIndex = 0;
    int jsonObjectSize = 0;
    do {
        currentIndex++; // skip the curly brace or comma
        currentIndex++; // skip the space
        keyValues[keyValuesIndex++] = extractKeyValue(jsonString);
        currentIndex++; // skip the curly brace or comma
        currentIndex++; // skip the space
        jsonObjectSize++;
    } while(jsonString[currentIndex] != '\0');
    jsonObject->keyValues = keyValues;
    jsonObject->size = jsonObjectSize;
    return jsonObject;
}

int main() {
    char* jsonString = "{\n    \"key1\": 100,\n    \"key2\": 200\n}";
    JsonObject* jsonObject = parseJSON(jsonString);
    printf("Keys and values from JSON:\n");
    for(int i=0; i<jsonObject->size; i++) {
        printf("%s -> %d\n", jsonObject->keyValues[i].key, jsonObject->keyValues[i].value);
    }
    return 0;
}