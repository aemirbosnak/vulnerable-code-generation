//Falcon-180B DATASET v1.0 Category: Building a JSON Parser ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VALUE_LEN 1024
#define MAX_KEY_LEN 256

// Data structures for parsing JSON
typedef struct {
    char* key;
    char* value;
} JsonPair;

typedef struct {
    int count;
    JsonPair* pairs;
} JsonObject;

// Function prototypes
JsonObject* createJsonObject();
void addPairToJsonObject(JsonObject* obj, char* key, char* value);
void printJsonObject(JsonObject* obj);
void deleteJsonObject(JsonObject* obj);

// Function to create a new JSON object
JsonObject* createJsonObject() {
    JsonObject* obj = (JsonObject*) malloc(sizeof(JsonObject));
    obj->count = 0;
    obj->pairs = (JsonPair*) malloc(sizeof(JsonPair));
    return obj;
}

// Function to add a key-value pair to a JSON object
void addPairToJsonObject(JsonObject* obj, char* key, char* value) {
    obj->count++;
    obj->pairs = (JsonPair*) realloc(obj->pairs, sizeof(JsonPair) * obj->count);
    obj->pairs[obj->count - 1].key = strdup(key);
    obj->pairs[obj->count - 1].value = strdup(value);
}

// Function to print a JSON object
void printJsonObject(JsonObject* obj) {
    for (int i = 0; i < obj->count; i++) {
        printf("%s: %s\n", obj->pairs[i].key, obj->pairs[i].value);
    }
}

// Function to delete a JSON object and free memory
void deleteJsonObject(JsonObject* obj) {
    for (int i = 0; i < obj->count; i++) {
        free(obj->pairs[i].key);
        free(obj->pairs[i].value);
    }
    free(obj->pairs);
    free(obj);
}

int main() {
    char jsonString[] = "{\"name\": \"John\", \"age\": 30, \"city\": \"New York\"}";
    JsonObject* jsonObj = createJsonObject();
    char* token = strtok(jsonString, " \t\r\n\",\"\\");
    while (token!= NULL) {
        if (strlen(token) > 0) {
            char* equalPos = strchr(token, '=');
            if (equalPos!= NULL) {
                *equalPos = '\0';
                char* key = strdup(token);
                char* value = strdup(equalPos + 1);
                addPairToJsonObject(jsonObj, key, value);
            }
        }
        token = strtok(NULL, " \t\r\n\",\"\\");
    }
    printJsonObject(jsonObj);
    deleteJsonObject(jsonObj);
    return 0;
}