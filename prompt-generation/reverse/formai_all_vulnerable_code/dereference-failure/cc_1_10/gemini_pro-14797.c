//GEMINI-pro DATASET v1.0 Category: Building a JSON Parser ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *key;
    char *value;
} JSONPair;

typedef struct {
    int size;
    JSONPair *pairs;
} JSONObject;

JSONObject *parseJSON(char *json) {
    int len = strlen(json);
    JSONObject *object = malloc(sizeof(JSONObject));
    object->size = 0;
    object->pairs = NULL;

    char *key = NULL;
    char *value = NULL;
    int inKey = 1;
    int inString = 0;
    int escapeNext = 0;

    for (int i = 0; i < len; i++) {
        char c = json[i];

        if (escapeNext) {
            escapeNext = 0;
            continue;
        }

        switch (c) {
            case '\\':
                escapeNext = 1;
                break;
            case '"':
                if (inString) {
                    inString = 0;
                    if (inKey) {
                        key = malloc(i - 1 - object->size);
                        memcpy(key, json + object->size, i - 1 - object->size);
                        key[i - 1 - object->size] = '\0';
                        object->size = i + 1;
                    } else {
                        value = malloc(i - 1 - object->size);
                        memcpy(value, json + object->size, i - 1 - object->size);
                        value[i - 1 - object->size] = '\0';
                        object->size = i + 1;

                        JSONPair pair = {key, value};
                        object->pairs = realloc(object->pairs, sizeof(JSONPair) * (object->size + 1));
                        object->pairs[object->size - 1] = pair;
                    }
                } else {
                    inString = 1;
                    object->size = i + 1;
                }
                break;
            case ':':
                if (inKey) {
                    inKey = 0;
                    object->size = i + 1;
                }
                break;
            case ',':
                inKey = 1;
                object->size = i + 1;
                break;
        }
    }

    return object;
}

void printJSONObject(JSONObject *object) {
    for (int i = 0; i < object->size; i++) {
        printf("%s: %s\n", object->pairs[i].key, object->pairs[i].value);
    }
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
    char *json = "{\"name\": \"John Smith\", \"age\": 30, \"occupation\": \"Software Engineer\"}";
    JSONObject *object = parseJSON(json);
    printJSONObject(object);
    freeJSONObject(object);

    return 0;
}