//Falcon2-11B DATASET v1.0 Category: Building a JSON Parser ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char* key;
    char* value;
} JsonObject;

typedef struct {
    JsonObject* objects;
    int count;
} JsonArray;

JsonObject* createJsonObject(const char* key, const char* value) {
    JsonObject* obj = malloc(sizeof(JsonObject));
    if (obj == NULL) {
        fprintf(stderr, "Error: Out of memory\n");
        exit(1);
    }
    obj->key = strdup(key);
    obj->value = strdup(value);
    return obj;
}

JsonArray* createJsonArray() {
    JsonArray* arr = malloc(sizeof(JsonArray));
    if (arr == NULL) {
        fprintf(stderr, "Error: Out of memory\n");
        exit(1);
    }
    arr->objects = NULL;
    arr->count = 0;
    return arr;
}

void addJsonObjectToArray(JsonArray* arr, JsonObject* obj) {
    if (arr->objects == NULL) {
        arr->objects = malloc(sizeof(JsonObject));
        if (arr->objects == NULL) {
            fprintf(stderr, "Error: Out of memory\n");
            exit(1);
        }
        arr->objects->key = NULL;
        arr->objects->value = NULL;
        arr->count++;
    }
    else {
        arr->count++;
    }
    arr->objects = realloc(arr->objects, sizeof(JsonObject) * arr->count);
    if (arr->objects == NULL) {
        fprintf(stderr, "Error: Out of memory\n");
        exit(1);
    }
    arr->objects[arr->count - 1].key = strdup(obj->key);
    arr->objects[arr->count - 1].value = strdup(obj->value);
}

void freeJsonArray(JsonArray* arr) {
    for (int i = 0; i < arr->count; i++) {
        free(arr->objects[i].key);
        free(arr->objects[i].value);
    }
    free(arr->objects);
    free(arr);
}

void printJsonArray(JsonArray* arr) {
    for (int i = 0; i < arr->count; i++) {
        printf("Key: %s, Value: %s\n", arr->objects[i].key, arr->objects[i].value);
    }
}

int main() {
    JsonArray* arr = createJsonArray();

    JsonObject* obj1 = createJsonObject("name", "John Doe");
    addJsonObjectToArray(arr, obj1);

    JsonObject* obj2 = createJsonObject("age", "25");
    addJsonObjectToArray(arr, obj2);

    JsonObject* obj3 = createJsonObject("city", "New York");
    addJsonObjectToArray(arr, obj3);

    JsonObject* obj4 = createJsonObject("email", "johndoe@example.com");
    addJsonObjectToArray(arr, obj4);

    JsonObject* obj5 = createJsonObject("phone", "123-456-7890");
    addJsonObjectToArray(arr, obj5);

    printJsonArray(arr);

    freeJsonArray(arr);

    return 0;
}