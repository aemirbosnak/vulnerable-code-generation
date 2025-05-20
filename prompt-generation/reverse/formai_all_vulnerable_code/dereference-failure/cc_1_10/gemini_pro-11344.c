//GEMINI-pro DATASET v1.0 Category: Building a JSON Parser ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *key;
    char *value;
} JSONPair;

typedef struct {
    JSONPair *pairs;
    int size;
    int capacity;
} JSONObject;

JSONObject *createJSONObject() {
    JSONObject *object = malloc(sizeof(JSONObject));
    object->pairs = malloc(sizeof(JSONPair) * 10);
    object->size = 0;
    object->capacity = 10;
    return object;
}

void addPairToJSONObject(JSONObject *object, char *key, char *value) {
    if (object->size == object->capacity) {
        object->pairs = realloc(object->pairs, sizeof(JSONPair) * object->capacity * 2);
        object->capacity *= 2;
    }
    JSONPair pair = {key, value};
    object->pairs[object->size++] = pair;
}

char *getJSONValue(JSONObject *object, char *key) {
    for (int i = 0; i < object->size; i++) {
        if (strcmp(object->pairs[i].key, key) == 0) {
            return object->pairs[i].value;
        }
    }
    return NULL;
}

void freeJSONObject(JSONObject *object) {
    for (int i = 0; i < object->size; i++) {
        free(object->pairs[i].key);
        free(object->pairs[i].value);
    }
    free(object->pairs);
    free(object);
}

int main() {
    char *json = "{\"name\": \"John Doe\", \"age\": 30, \"occupation\": \"Software Engineer\"}";

    JSONObject *object = createJSONObject();

    char *key;
    char *value;
    key = strtok(json, ":\"");
    while (key != NULL) {
        value = strtok(NULL, "\",");
        value[strlen(value) - 1] = '\0';
        addPairToJSONObject(object, key, value);
        key = strtok(NULL, ":\"");
    }

    printf("Name: %s\n", getJSONValue(object, "name"));
    printf("Age: %s\n", getJSONValue(object, "age"));
    printf("Occupation: %s\n", getJSONValue(object, "occupation"));

    freeJSONObject(object);

    return 0;
}