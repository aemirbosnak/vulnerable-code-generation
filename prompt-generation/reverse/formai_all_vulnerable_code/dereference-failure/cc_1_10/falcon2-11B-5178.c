//Falcon2-11B DATASET v1.0 Category: Building a JSON Parser ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include <assert.h>

typedef struct {
    char* key;
    char* value;
} JsonPair;

typedef struct {
    JsonPair* pairs;
    int count;
} JsonObject;

JsonObject* parseJson(const char* jsonStr) {
    JsonObject* obj = (JsonObject*)malloc(sizeof(JsonObject));
    if (obj == NULL) {
        return NULL;
    }
    obj->pairs = NULL;
    obj->count = 0;
    char* curPtr = jsonStr;
    int braceCount = 0;
    while (*curPtr) {
        if (*curPtr == '{') {
            braceCount++;
        } else if (*curPtr == '}') {
            braceCount--;
            if (braceCount == 0) {
                break;
            }
        } else if (*curPtr == ':') {
            curPtr++;
            while (*curPtr!= ',' && *curPtr!= '}') {
                curPtr++;
            }
            curPtr++;
            JsonPair pair = {curPtr, NULL};
            if (obj->pairs == NULL) {
                obj->pairs = (JsonPair*)malloc(sizeof(JsonPair));
                obj->pairs->key = pair.key;
                obj->pairs->value = pair.value;
                obj->count++;
            } else {
                JsonPair* newPair = (JsonPair*)malloc(sizeof(JsonPair));
                if (newPair == NULL) {
                    return NULL;
                }
                newPair->key = pair.key;
                newPair->value = pair.value;
                obj->pairs = (JsonPair*)realloc(obj->pairs, (obj->count + 1) * sizeof(JsonPair));
                obj->pairs[obj->count] = *newPair;
                obj->count++;
            }
        } else if (*curPtr == ',' || *curPtr == '}') {
            continue;
        } else {
            if (obj->pairs == NULL) {
                obj->pairs = (JsonPair*)malloc(sizeof(JsonPair));
                obj->pairs->key = curPtr;
                obj->pairs->value = NULL;
                obj->count++;
            } else {
                JsonPair* newPair = (JsonPair*)malloc(sizeof(JsonPair));
                if (newPair == NULL) {
                    return NULL;
                }
                newPair->key = curPtr;
                newPair->value = NULL;
                obj->pairs = (JsonPair*)realloc(obj->pairs, (obj->count + 1) * sizeof(JsonPair));
                obj->pairs[obj->count] = *newPair;
                obj->count++;
            }
        }
        curPtr++;
    }
    return obj;
}

void printJson(JsonObject* obj) {
    if (obj == NULL || obj->count == 0) {
        return;
    }
    printf("{\n");
    int braceCount = 0;
    int pairCount = 0;
    for (int i = 0; i < obj->count; i++) {
        JsonPair* pair = &obj->pairs[i];
        if (pair->key!= NULL && pair->value!= NULL) {
            printf("  %s: %s,\n", pair->key, pair->value);
        } else {
            printf("  %s,\n", pair->key);
        }
        if (i < obj->count - 1) {
            printf("  ");
            braceCount++;
            pairCount++;
        }
    }
    printf("}\n");
}

int main() {
    const char* jsonStr = "{\"name\":\"John\",\"age\":30,\"city\":\"New York\"}";
    JsonObject* obj = parseJson(jsonStr);
    if (obj!= NULL) {
        printJson(obj);
        free(obj);
    }
    return 0;
}