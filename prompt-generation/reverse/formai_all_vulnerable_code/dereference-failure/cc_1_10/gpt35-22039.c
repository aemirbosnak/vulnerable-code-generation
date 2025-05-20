//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// define a struct to represent a JSON object
typedef struct {
    char* key;
    char* value;
} JsonObject;

// define a struct to represent a JSON array
typedef struct {
    int count;
    JsonObject** items;
} JsonArray;

// function to parse a JSON object
JsonObject* parseJsonObject(char* jsonString) {
    // allocate memory for the object
    JsonObject* object = malloc(sizeof(JsonObject));
    // find the start and end of the key and value strings
    char* keyStart = strchr(jsonString, '"') + 1;
    char* keyEnd = strchr(keyStart, '"');
    char* valStart = strchr(keyEnd, ':') + 1;
    char* valEnd = strchr(valStart, ',');

    // allocate memory for the key and value strings
    object->key = malloc(keyEnd - keyStart + 1);
    object->value = malloc(valEnd - valStart + 1);

    // copy the key and value strings
    strncpy(object->key, keyStart, keyEnd - keyStart);
    strncpy(object->value, valStart, valEnd - valStart);

    // add null terminator to the strings
    object->key[keyEnd - keyStart] = '\0';
    /* If this is the last item in the object, 
    the value string might end with a '}' instead of a ',' */
    if (valEnd[1] == '}') {
        object->value[valEnd - valStart] = '\0';
    } else {
        object->value[valEnd - valStart - 1] = '\0';
    }
    
    // return the parsed object
    return object;
}

// function to parse a JSON array
JsonArray* parseJsonArray(char* jsonString) {
    JsonArray* array = malloc(sizeof(JsonArray));
    array->count = 0;
    array->items = malloc(sizeof(JsonObject*));
    char* itemStart = strchr(jsonString, '[') + 1;
    char* itemEnd = strchr(itemStart, ']');
    char* commaPos = strchr(itemStart, ',');
    while (commaPos != NULL && commaPos <= itemEnd) {
        // parse each item in the array recursively
        array->items[array->count] = parseJsonObject(itemStart);
        array->count++;
        array->items = realloc(array->items, sizeof(JsonObject*) * (array->count + 1));
        itemStart = commaPos + 1;
        commaPos = strchr(itemStart, ',');
    }
    // parse the last item in the array
    array->items[array->count] = parseJsonObject(itemStart);
    array->count++;
    array->items = realloc(array->items, sizeof(JsonObject*) * (array->count + 1));
    return array;
}

int main() {
    char* jsonString = "{\"name\":\"John\",\"age\":30,\"city\":\"New York\"}";
    JsonObject* object = parseJsonObject(jsonString);
    printf("Object key: %s\n", object->key);
    printf("Object value: %s\n", object->value);
    free(object->key);
    free(object->value);
    free(object);

    jsonString = "[{\"name\":\"John\",\"age\":30},{\"name\":\"Jane\",\"age\":25}]";
    JsonArray* array = parseJsonArray(jsonString);
    for (int i = 0; i < array->count; i++) {
        printf("\nArray item %d\n", i);
        printf("Object key: %s\n", array->items[i]->key);
        printf("Object value: %s\n", array->items[i]->value);
        free(array->items[i]->key);
        free(array->items[i]->value);
        free(array->items[i]);
    }
    free(array->items);
    free(array);
    return 0;
}