//GPT-4o-mini DATASET v1.0 Category: Building a JSON Parser ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_JSON_SIZE 1024
#define MAX_KEY_SIZE 256
#define MAX_VALUE_SIZE 256

typedef struct KeyValue {
    char key[MAX_KEY_SIZE];
    char value[MAX_VALUE_SIZE];
    struct KeyValue *next;
} KeyValue;

KeyValue* createKeyValue(const char *key, const char *value) {
    KeyValue *newPair = (KeyValue *)malloc(sizeof(KeyValue));
    strcpy(newPair->key, key);
    strcpy(newPair->value, value);
    newPair->next = NULL;
    return newPair;
}

void addKeyValue(KeyValue **head, const char *key, const char *value) {
    KeyValue *newPair = createKeyValue(key, value);
    newPair->next = *head;
    *head = newPair;
}

void freeKeyValues(KeyValue *head) {
    KeyValue *tmp;
    while (head) {
        tmp = head;
        head = head->next;
        free(tmp);
    }
}

void trimWhitespace(char *str) {
    char *end;

    while (isspace((unsigned char)*str)) str++;

    end = str + strlen(str) - 1;
    while (end > str && isspace((unsigned char)*end)) end--;

    *(end + 1) = '\0';
}

void parseJSON(const char *json, KeyValue **keyValueList) {
    char key[MAX_KEY_SIZE];
    char value[MAX_VALUE_SIZE];
    const char *p = json;
    
    while (*p) {
        if (*p == '{' || *p == ' ' || *p == '\n' || *p == '\t') {
            p++;
            continue;
        }

        if (*p == '"') {
            p++; // Skip opening quote
            char *keyStart = p;
            while (*p && *p != '"') p++;
            strncpy(key, keyStart, p - keyStart);
            key[p - keyStart] = '\0';

            p++; // Skip closing quote
            while (*p && (*p == ' ' || *p == ':')) p++;
            if (*p == '"') {
                p++; // Skip opening quote
                char *valueStart = p;
                while (*p && *p != '"') p++;
                strncpy(value, valueStart, p - valueStart);
                value[p - valueStart] = '\0';

                p++; // Skip closing quote
                addKeyValue(keyValueList, key, value);
            }
        } else {
            p++;
        }
    }
}

void printKeyValues(KeyValue *head) {
    KeyValue *current = head;
    while (current) {
        printf("Key: %s, Value: %s\n", current->key, current->value);
        current = current->next;
    }
}

int main() {
    const char *jsonString = "{\"name\": \"John\", \"age\": \"30\", \"city\": \"New York\"}";
    KeyValue *keyValueList = NULL;

    parseJSON(jsonString, &keyValueList);
    
    printf("Parsed JSON key-value pairs:\n");
    printKeyValues(keyValueList);

    freeKeyValues(keyValueList);
    return 0;
}