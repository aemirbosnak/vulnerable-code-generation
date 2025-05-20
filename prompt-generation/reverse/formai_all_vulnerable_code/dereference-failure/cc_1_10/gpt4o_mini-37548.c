//GPT-4o-mini DATASET v1.0 Category: Building a JSON Parser ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct JSONValue {
    char *key;
    char *value;
    struct JSONValue *next;
} JSONValue;

typedef struct JSONObject {
    JSONValue *head;
} JSONObject;

// Function to create a new JSONObject
JSONObject* createJSONObject() {
    JSONObject *obj = (JSONObject*) malloc(sizeof(JSONObject));
    obj->head = NULL;
    return obj;
}

// Function to create a new JSONValue
JSONValue* createJSONValue(const char *key, const char *value) {
    JSONValue *newValue = (JSONValue*) malloc(sizeof(JSONValue));
    newValue->key = strdup(key);
    newValue->value = strdup(value);
    newValue->next = NULL;
    return newValue;
}

// Function to add a key-value pair to the JSONObject
void addJSONObject(JSONObject *obj, const char *key, const char *value) {
    JSONValue *newValue = createJSONValue(key, value);
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

// Function to parse a simple JSON string representation
JSONObject* parseJSON(const char *json) {
    JSONObject *obj = createJSONObject();
    char *jsonCopy = strdup(json);
    char *line = strtok(jsonCopy, ",{}:");

    while (line != NULL) {
        char *key = trimWhitespace(line);
        line = strtok(NULL, ",{}:");
        if (line == NULL) break;
        char *value = trimWhitespace(line);
        addJSONObject(obj, key, value);
        line = strtok(NULL, ",{}:");
    }

    free(jsonCopy);
    return obj;
}

// Function to print the JSONObject
void printJSONObject(JSONObject *obj) {
    JSONValue *current = obj->head;
    printf("{\n");
    while (current != NULL) {
        printf("  \"%s\": \"%s\"", current->key, current->value);
        current = current->next;
        if (current != NULL) {
            printf(",\n");
        }
    }
    printf("\n}\n");
}

// Function to free the JSONObject and its values
void freeJSONObject(JSONObject *obj) {
    JSONValue *current = obj->head;
    while (current != NULL) {
        JSONValue *temp = current;
        current = current->next;
        free(temp->key);
        free(temp->value);
        free(temp);
    }
    free(obj);
}

int main() {
    const char *jsonString = "{name: John Doe, age: 30, country: USA}";
    
    printf("Parsing JSON string: \n%s\n", jsonString);
    
    JSONObject *jsonObject = parseJSON(jsonString);
    
    printf("\nParsed JSON object:\n");
    printJSONObject(jsonObject);
    
    freeJSONObject(jsonObject);
    
    return 0;
}