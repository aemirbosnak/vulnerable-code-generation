//GPT-4o-mini DATASET v1.0 Category: Building a JSON Parser ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct JsonValue {
    char *key;
    char *value;
    struct JsonValue *next;
} JsonValue;

typedef struct JsonObject {
    JsonValue *head;
} JsonObject;

// Function prototypes
JsonObject *createJsonObject();
void addJsonValue(JsonObject *obj, const char *key, const char *value);
void parseJson(const char *jsonString, JsonObject *obj);
void printJsonObject(JsonObject *obj);
void freeJsonObject(JsonObject *obj);

// Function to create a new JsonObject
JsonObject *createJsonObject() {
    JsonObject *obj = (JsonObject *)malloc(sizeof(JsonObject));
    obj->head = NULL;
    return obj;
}

// Function to add a key-value pair to the JsonObject
void addJsonValue(JsonObject *obj, const char *key, const char *value) {
    JsonValue *newValue = (JsonValue *)malloc(sizeof(JsonValue));
    newValue->key = strdup(key);
    newValue->value = strdup(value);
    newValue->next = obj->head;
    obj->head = newValue;
}

// Function to trim whitespace
char *trimWhitespace(char *str) {
    char *end;

    while (isspace((unsigned char)*str)) str++;
    if (*str == 0) return str;
    
    end = str + strlen(str) - 1;
    while (end > str && isspace((unsigned char)*end)) end--;

    *(end + 1) = 0;
    return str;
}

// Function to parse a JSON string
void parseJson(const char *jsonString, JsonObject *obj) {
    char *jsonCopy = strdup(jsonString);
    char *line = strtok(jsonCopy, ",{}:");
    
    while (line != NULL) {
        line = trimWhitespace(line);
        if (*line) {
            char *keyValue = strdup(line);
            char *key = strtok(keyValue, ":");
            char *value = strtok(NULL, ":");
            if (key && value) {
                addJsonValue(obj, trimWhitespace(key), trimWhitespace(value));
            }
            free(keyValue);
        }
        line = strtok(NULL, ",{}:");
    }
    
    free(jsonCopy);
}

// Function to print the JsonObject
void printJsonObject(JsonObject *obj) {
    JsonValue *current = obj->head;
    printf("{\n");
    while (current != NULL) {
        printf("    \"%s\": \"%s\"", current->key, current->value);
        if (current->next != NULL) {
            printf(",");
        }
        printf("\n");
        current = current->next;
    }
    printf("}\n");
}

// Function to free the JsonObject
void freeJsonObject(JsonObject *obj) {
    JsonValue *current = obj->head;
    while (current != NULL) {
        JsonValue *temp = current;
        current = current->next;
        free(temp->key);
        free(temp->value);
        free(temp);
    }
    free(obj);
}

// Main function demonstrating the JSON parser
int main() {
    const char *jsonString = "{\"name\":\"John\", \"age\":\"30\", \"city\":\"New York\"}";
    
    JsonObject *jsonObject = createJsonObject();
    parseJson(jsonString, jsonObject);
    printJsonObject(jsonObject);
    freeJsonObject(jsonObject);
    
    return 0;
}