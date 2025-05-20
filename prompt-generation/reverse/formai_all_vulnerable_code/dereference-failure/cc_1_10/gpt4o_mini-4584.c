//GPT-4o-mini DATASET v1.0 Category: Building a JSON Parser ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_BUFFER 1024

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
void freeJsonObject(JsonObject *obj);
void printJsonObject(JsonObject *obj);
void parseJson(const char *jsonStr, JsonObject *jsonObj);
char *trimWhitespace(char *str);
void parseKeyValue(char *keyValue, JsonObject *jsonObj);
void handleError(const char *message);

// Main function
int main(int argc, char **argv) {
    if (argc < 2) {
        handleError("Usage: ./jsonparser 'json_string'");
    }

    JsonObject *jsonObj = createJsonObject();
    parseJson(argv[1], jsonObj);
    printJsonObject(jsonObj);
    freeJsonObject(jsonObj);

    return 0;
}

// Function to create a new JsonObject
JsonObject *createJsonObject() {
    JsonObject *obj = (JsonObject *)malloc(sizeof(JsonObject));
    obj->head = NULL;
    return obj;
}

// Function to add key-value pair to JsonObject
void addJsonValue(JsonObject *obj, const char *key, const char *value) {
    JsonValue *newValue = (JsonValue *)malloc(sizeof(JsonValue));
    newValue->key = strdup(key);
    newValue->value = strdup(value);
    newValue->next = obj->head;
    obj->head = newValue;
}

// Function to free the memory of JsonObject
void freeJsonObject(JsonObject *obj) {
    JsonValue *current = obj->head;
    JsonValue *next;
    
    while (current != NULL) {
        next = current->next;
        free(current->key);
        free(current->value);
        free(current);
        current = next;
    }
    free(obj);
}

// Function to print JsonObject
void printJsonObject(JsonObject *obj) {
    JsonValue *current = obj->head;
    printf("{\n");
    
    while (current != NULL) {
        printf("  \"%s\": \"%s\",\n", current->key, current->value);
        current = current->next;
    }
    printf("}\n");
}

// Function to parse and populate JsonObject from a JSON string
void parseJson(const char *jsonStr, JsonObject *jsonObj) {
    char buffer[MAX_BUFFER];
    int i = 0;

    while (*jsonStr) {
        if (*jsonStr == '{' || *jsonStr == '}' || *jsonStr == ',') {
            jsonStr++;
            continue;
        }

        if (*jsonStr == '"') {
            jsonStr++; // Skip the starting double quote
            while (*jsonStr != '"' && *jsonStr) {
                buffer[i++] = *jsonStr++;
            }
            buffer[i] = '\0';
            char *key = trimWhitespace(buffer);
            i = 0; // Reset buffer index

            // Expecting the colon after key
            while (*jsonStr && *jsonStr != ':') jsonStr++;
            jsonStr++; // Skip the colon

            // Now expect a value
            if (*jsonStr == '"') {
                jsonStr++; // Skip the double quote
                while (*jsonStr != '"' && *jsonStr) {
                    buffer[i++] = *jsonStr++;
                }
                buffer[i] = '\0';
                char *value = trimWhitespace(buffer);
                addJsonValue(jsonObj, key, value);
                i = 0; // Reset buffer index
            }
            free(key);
        }
        jsonStr++;
    }
}

// Function to trim whitespace from a string
char *trimWhitespace(char *str) {
    char *end;

    // Trim leading space
    while (isspace((unsigned char)*str)) str++;

    // Trim trailing space
    end = str + strlen(str) - 1;
    while (end > str && isspace((unsigned char)*end)) end--;

    // Null terminate after the last non-space character
    *(end + 1) = '\0';
    return str;
}

// Function to handle errors
void handleError(const char *message) {
    fprintf(stderr, "Error: %s\n", message);
    exit(EXIT_FAILURE);
}