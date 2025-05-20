//GPT-4o-mini DATASET v1.0 Category: Building a JSON Parser ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_JSON_SIZE 1024
#define MAX_KEY_SIZE 128
#define MAX_VALUE_SIZE 256

typedef struct JsonObject {
    char key[MAX_KEY_SIZE];
    char value[MAX_VALUE_SIZE];
    struct JsonObject* next;
} JsonObject;

JsonObject* createJsonObject(const char* key, const char* value) {
    JsonObject* newObject = (JsonObject*)malloc(sizeof(JsonObject));
    if (newObject == NULL) {
        fprintf(stderr, "Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }
    strncpy(newObject->key, key, MAX_KEY_SIZE);
    strncpy(newObject->value, value, MAX_VALUE_SIZE);
    newObject->next = NULL;
    return newObject;
}

void freeJsonObject(JsonObject* object) {
    free(object);
}

void freeJsonList(JsonObject* head) {
    JsonObject* tmp;
    while (head) {
        tmp = head;
        head = head->next;
        freeJsonObject(tmp);
    }
}

void trimWhitespace(char* str) {
    char* end;

    while (isspace((unsigned char)*str)) str++;

    if (*str == 0) return;

    end = str + strlen(str) - 1;
    while (end > str && isspace((unsigned char)*end)) end--;

    *(end + 1) = 0;
}

char* parseKeyValue(const char* jsonStr, char** key, size_t* keySize, char** value, size_t* valueSize) {
    char* colon = strchr(jsonStr, ':');
    if (colon == NULL) return NULL;

    *keySize = colon - jsonStr;
    *key = (char*)malloc((*keySize + 1) * sizeof(char));
    strncpy(*key, jsonStr, *keySize);
    (*key)[*keySize] = '\0';
    trimWhitespace(*key);

    const char* startValue = colon + 1;
    const char* endValue = strchr(startValue, ',');
    if (endValue == NULL) {
        endValue = strchr(startValue, '}');
    }
    if (endValue == NULL) return NULL;

    *valueSize = endValue - startValue;
    *value = (char*)malloc((*valueSize + 1) * sizeof(char));
    strncpy(*value, startValue, *valueSize);
    (*value)[*valueSize] = '\0';
    trimWhitespace(*value);

    return (char*)endValue;
}

JsonObject* parseJSON(const char* jsonStr) {
    JsonObject* head = NULL;
    JsonObject* tail = NULL;

    const char* cursor = jsonStr;
    while (*cursor) {
        char* key;
        char* value;
        size_t keySize, valueSize;
        
        cursor = parseKeyValue(cursor, &key, &keySize, &value, &valueSize);
        if (cursor == NULL) break;

        JsonObject* newObject = createJsonObject(key, value);
        free(key);
        free(value);

        if (head == NULL) {
            head = newObject;
            tail = newObject;
        } else {
            tail->next = newObject;
            tail = newObject;
        }

        cursor++; // Move past the comma or closing brace
    }

    return head;
}

void printJson(JsonObject* json) {
    JsonObject* current = json;
    printf("{\n");
    while (current != NULL) {
        printf("    \"%s\": \"%s\",\n", current->key, current->value);
        current = current->next;
    }
    printf("}\n");
}

int main() {
    printf("Welcome to the amazing JSON Parser in C! 🎉\n");
    char jsonString[MAX_JSON_SIZE] = "{\"name\": \"John\", \"age\": \"30\", \"city\": \"New York\"}";

    printf("Parsing the following JSON string:\n%s\n\n", jsonString);

    JsonObject* jsonObject = parseJSON(jsonString);
    if (jsonObject) {
        printf("Parsed JSON Object:\n");
        printJson(jsonObject);
        freeJsonList(jsonObject);
    } else {
        printf("Failed to parse JSON!\n");
    }

    printf("End of the exhilarating JSON parsing journey! 🚀\n");
    return 0;
}