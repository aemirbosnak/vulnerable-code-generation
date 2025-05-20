//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Declare structs
typedef struct JSONValue {
    enum { JSON_STRING, JSON_NUMBER, JSON_OBJECT, JSON_ARRAY } type;
    union {
        char* string;
        double number;
        struct JSONObject* object;
        struct JSONArray* array;
    } value;
} JSONValue;

typedef struct JSONObject {
    int size;
    char** keys;
    JSONValue** values;
} JSONObject;

typedef struct JSONArray {
    int size;
    JSONValue** values;
} JSONArray;

JSONValue* parseJSONValue(char* jsonString);
JSONObject* parseJSONObject(char* jsonString);
JSONArray* parseJSONArray(char* jsonString);

// Helper function to get the value of a key from a JSONObject
JSONValue* getValueFromJSONObject(JSONObject* object, char* key) {
    for (int i = 0; i < object->size; i++) {
        if (strcmp(object->keys[i], key) == 0) {
            return object->values[i];
        }
    }
    return NULL;
}

// Main function
int main() {
    // Example JSON string
    char* jsonString = "{\"name\": \"Alex\", \"age\": 25, \"isMarried\": true, \"hobbies\": [\"reading\", \"coding\"]}";

    // Parse the JSON string
    JSONValue* json = parseJSONValue(jsonString);

    // Get the name value from the JSONObject
    JSONValue* nameValue = getValueFromJSONObject(json->value.object, "name");

    // Print the name value
    printf("Name: %s\n", nameValue->value.string);

    return 0;
}

JSONValue* parseJSONValue(char* jsonString) {
    JSONValue* jsonValue = malloc(sizeof(JSONValue));
    char* currentChar = jsonString;

    if (*currentChar == '{') {
        jsonValue->type = JSON_OBJECT;
        jsonValue->value.object = parseJSONObject(currentChar);
    } else if (*currentChar == '[') {
        jsonValue->type = JSON_ARRAY;
        jsonValue->value.array = parseJSONArray(currentChar);
    } else if (*currentChar == '\"') {
        jsonValue->type = JSON_STRING;
        // TODO: Parse string
    } else {
        jsonValue->type = JSON_NUMBER;
        // TODO: Parse number
    }

    return jsonValue;
}

JSONObject* parseJSONObject(char* jsonString) {
    JSONObject* jsonObject = malloc(sizeof(JSONObject));
    int keyCount = 0;

    // Count the number of keys in the JSONObject
    for (char* currentChar = jsonString; *currentChar != '}'; currentChar++) {
        if (*currentChar == '\"') {
            keyCount++;
        }
    }

    jsonObject->keys = malloc(sizeof(char*) * keyCount);
    jsonObject->values = malloc(sizeof(JSONValue*) * keyCount);
    jsonObject->size = keyCount;

    // TODO: Parse keys and values

    return jsonObject;
}

JSONArray* parseJSONArray(char* jsonString) {
    JSONArray* jsonArray = malloc(sizeof(JSONArray));
    int valueCount = 0;

    // Count the number of values in the JSONArray
    for (char* currentChar = jsonString; *currentChar != ']'; currentChar++) {
        if (*currentChar == '{' || *currentChar == '[' || *currentChar == '\"' || (*currentChar >= '0' && *currentChar <= '9') || *currentChar == '-' || *currentChar == 't' || *currentChar == 'f') {
            valueCount++;
        }
    }

    jsonArray->values = malloc(sizeof(JSONValue*) * valueCount);
    jsonArray->size = valueCount;

    // TODO: Parse values

    return jsonArray;
}