//GPT-4o-mini DATASET v1.0 Category: Building a JSON Parser ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_JSON_SIZE 1024
#define MAX_KEY_SIZE 256

typedef struct JSONValue {
    char key[MAX_KEY_SIZE];
    char value[MAX_JSON_SIZE];
    struct JSONValue* next;
} JSONValue;

JSONValue* createJSONValue(const char* key, const char* value) {
    JSONValue* newValue = (JSONValue*)malloc(sizeof(JSONValue));
    strncpy(newValue->key, key, MAX_KEY_SIZE);
    strncpy(newValue->value, value, MAX_JSON_SIZE);
    newValue->next = NULL;
    return newValue;
}

void freeJSONValue(JSONValue* value) {
    while (value != NULL) {
        JSONValue* temp = value;
        value = value->next;
        free(temp);
    }
}

void trimWhitespace(char* str) {
    char* start = str;
    while (isspace((unsigned char)*start)) start++;

    char* end = str + strlen(str) - 1;
    while (end > start && isspace((unsigned char)*end)) end--;

    *(end + 1) = '\0'; // Null-terminate the string after trimming.
    memmove(str, start, end - start + 2); // Move trimmed string to the beginning.
}

void parseJSON(const char* jsonString, JSONValue** jsonValues) {
    const char* p = jsonString;
    char key[MAX_KEY_SIZE] = {0};
    char value[MAX_JSON_SIZE] = {0};
    while (*p) {
        if (*p == '{' || *p == ',' || *p == ' ') {
            p++; // Skip '{', ',', or spaces.
            continue;
        }
        
        // Parse key
        if (*p == '"') {
            p++; // Skip the opening quote.
            char* keyStart = key;
            while (*p && *p != '"') {
                *keyStart++ = *p++;
            }
            *keyStart = '\0'; // Null-terminate key.
            p++; // Skip the closing quote.
            
            // Skip whitespace and the colon marker.
            while (*p == ' ' || *p == ':') p++;
            
            // Parse value
            if (*p == '"') {
                p++; // Skip the opening quote.
                char* valueStart = value;
                while (*p && *p != '"') {
                    *valueStart++ = *p++;
                }
                *valueStart = '\0'; // Null-terminate value.
                p++; // Skip the closing quote.
            } else {
                // Assume numeric value for now.
                char* valueStart = value;
                while (*p && *p != ',' && *p != '}') {
                    *valueStart++ = *p++;
                }
                *valueStart = '\0'; // Null-terminate value.
            }
            
            // Trim whitespace for key and value
            trimWhitespace(key);
            trimWhitespace(value);
            
            // Create JSONValue and add to list
            JSONValue* newValue = createJSONValue(key, value);
            newValue->next = *jsonValues;
            *jsonValues = newValue;
            
            // Reset the values for the next iteration
            memset(key, 0, sizeof(key));
            memset(value, 0, sizeof(value));
        }
        else {
            p++; // Move to the next character.
        }
    }
}

void printJSONValues(JSONValue* jsonValues) {
    while (jsonValues) {
        printf("Key: %s, Value: %s\n", jsonValues->key, jsonValues->value);
        jsonValues = jsonValues->next;
    }
}

int main() {
    char jsonString[MAX_JSON_SIZE] = "{\"name\": \"Alice\", \"age\": \"30\", \"city\": \"Wonderland\"}";
    JSONValue* jsonValues = NULL;

    printf("Parsing the JSON string: %s\n", jsonString);
    parseJSON(jsonString, &jsonValues);
    
    printf("\n=== Parsed JSON Values ===\n");
    printJSONValues(jsonValues);
    
    // Cleanup
    freeJSONValue(jsonValues);
    return 0;
}