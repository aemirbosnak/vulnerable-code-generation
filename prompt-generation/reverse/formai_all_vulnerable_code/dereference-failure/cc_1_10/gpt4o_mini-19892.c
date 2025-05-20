//GPT-4o-mini DATASET v1.0 Category: Building a JSON Parser ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_JSON_SIZE 1024

typedef enum {
    JSON_UNKNOWN,
    JSON_STRING,
    JSON_NUMBER,
    JSON_OBJECT,
    JSON_ARRAY
} JsonType;

typedef struct JsonValue {
    JsonType type;
    char *key;
    char *value;
    struct JsonValue *next;
} JsonValue;

void skipWhitespace(const char **json) {
    while (isspace(**json)) (*json)++;
}

JsonValue *parseJson(const char **json) {
    JsonValue *head = NULL;
    JsonValue *tail = NULL;

    while (**json) {
        skipWhitespace(json);
        if (**json == '}') {
            (*json)++;
            break;
        }

        JsonValue *newValue = malloc(sizeof(JsonValue));
        newValue->next = NULL;

        if (**json == '"') {
            (*json)++;
            const char *keyStart = *json;
            while (**json && **json != '"') (*json)++;
            size_t keyLength = *json - keyStart;

            newValue->key = malloc(keyLength + 1);
            strncpy(newValue->key, keyStart, keyLength);
            newValue->key[keyLength] = '\0';
            (*json)++; // skip closing quote

            skipWhitespace(json);
            if (**json == ':') {
                (*json)++;
                skipWhitespace(json);

                if (**json == '"') {
                    newValue->type = JSON_STRING;
                    (*json)++;
                    const char *valueStart = *json;
                    while (**json && **json != '"') (*json)++;
                    size_t valueLength = *json - valueStart;

                    newValue->value = malloc(valueLength + 1);
                    strncpy(newValue->value, valueStart, valueLength);
                    newValue->value[valueLength] = '\0';
                    (*json)++; // skip closing quote
                } else if (isdigit(**json) || **json == '-') {
                    newValue->type = JSON_NUMBER;
                    const char *valueStart = *json;
                    while (isdigit(**json) || **json == '.') (*json)++;
                    size_t valueLength = *json - valueStart;

                    newValue->value = malloc(valueLength + 1);
                    strncpy(newValue->value, valueStart, valueLength);
                    newValue->value[valueLength] = '\0';
                } else {
                    // Handle unsupported types
                    newValue->type = JSON_UNKNOWN;
                    newValue->value = NULL;
                }
            }
        }

        if (head == NULL) {
            head = newValue;
            tail = newValue;
        } else {
            tail->next = newValue;
            tail = newValue;
        }

        skipWhitespace(json);
        if (**json == ',') {
            (*json)++;
        }
    }

    return head;
}

void freeJson(JsonValue *json) {
    while (json) {
        JsonValue *next = json->next;
        free(json->key);
        free(json->value);
        free(json);
        json = next;
    }
}

void printJson(JsonValue *json) {
    while (json) {
        printf("Key: %s, Type: %s, Value: %s\n",
               json->key,
               json->type == JSON_STRING ? "String" : 
               json->type == JSON_NUMBER ? "Number" : 
               "Unknown",
               json->value ? json->value : "null");
        json = json->next;
    }
}

int main() {
    const char *jsonString = "{\"name\": \"John Doe\", \"age\": 30, \"occupation\": \"Developer\"}";
    
    printf("Parsing JSON: %s\n", jsonString);
    
    const char *jsonPtr = jsonString;
    JsonValue *json = parseJson(&jsonPtr);
    
    printf("Parsed JSON:\n");
    printJson(json);

    freeJson(json);
    return 0;
}