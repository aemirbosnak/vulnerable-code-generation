//GPT-4o-mini DATASET v1.0 Category: Building a JSON Parser ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_NUM_ELEMENTS 100

typedef struct {
    char *key;
    char *value;
} JsonPair;

typedef struct {
    JsonPair pairs[MAX_NUM_ELEMENTS];
    int size;
} JsonObject;

// Function prototypes
JsonObject* parse_json(const char *json);
void trim_whitespace(char *str);
char* extract_string(const char *json, int *index);
void free_json_object(JsonObject *jsonObject);
void print_json_object(JsonObject *jsonObject);

// Entry point
int main() {
    const char *json_str = "{\"name\": \"John\", \"age\": \"30\", \"city\": \"New York\"}";

    JsonObject *jsonObject = parse_json(json_str);
    if (jsonObject != NULL) {
        print_json_object(jsonObject);
        free_json_object(jsonObject);
    } else {
        printf("Failed to parse JSON.\n");
    }

    return 0;
}

// Function to parse JSON string into JsonObject
JsonObject* parse_json(const char *json) {
    JsonObject *jsonObject = (JsonObject *)malloc(sizeof(JsonObject));
    jsonObject->size = 0;

    int i = 0;
    int length = strlen(json);
    
    // Skip initial spaces and opening brace
    while (i < length && (json[i] == ' ' || json[i] == '{')) {
        i++;
    }

    while (i < length && json[i] != '}') {
        char *key = extract_string(json, &i);
        while (i < length && (json[i] == ' ' || json[i] == ':')) {
            i++;
        }
        char *value = extract_string(json, &i);

        if (key != NULL && value != NULL) {
            jsonObject->pairs[jsonObject->size].key = key;
            jsonObject->pairs[jsonObject->size].value = value;
            jsonObject->size++;
        }

        while (i < length && json[i] != '}' && json[i] != ',') {
            i++;
        }
        i++; // Move past the comma or closing brace
    }

    return jsonObject;
}

// Function to extract a quoted string from JSON
char* extract_string(const char *json, int *index) {
    while (json[*index] != '\"' && *index < strlen(json)) {
        (*index)++;
    }

    if (json[*index] == '\"') {
        (*index)++;
        int start = *index;

        while (json[*index] != '\"' && *index < strlen(json)) {
            (*index)++;
        }

        if (json[*index] == '\"') {
            int length = *index - start;
            char *result = (char *)malloc(length + 1);
            strncpy(result, json + start, length);
            result[length] = '\0';
            (*index)++;
            return result;
        }
    }
  
    return NULL;
}

// Function to trim whitespace from a string
void trim_whitespace(char *str) {
    int start = 0;
    while (isspace((unsigned char)str[start])) start++;

    int end = strlen(str) - 1;
    while (end >= start && isspace((unsigned char)str[end])) end--;

    memmove(str, str + start, end - start + 1);
    str[end - start + 1] = '\0';
}

// Function to free allocated memory of JsonObject
void free_json_object(JsonObject *jsonObject) {
    for (int i = 0; i < jsonObject->size; i++) {
        free(jsonObject->pairs[i].key);
        free(jsonObject->pairs[i].value);
    }
    free(jsonObject);
}

// Function to print the contents of JsonObject
void print_json_object(JsonObject *jsonObject) {
    for (int i = 0; i < jsonObject->size; i++) {
        printf("Key: %s, Value: %s\n", jsonObject->pairs[i].key, jsonObject->pairs[i].value);
    }
}