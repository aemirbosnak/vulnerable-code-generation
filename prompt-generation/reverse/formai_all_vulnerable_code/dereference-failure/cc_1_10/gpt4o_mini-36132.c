//GPT-4o-mini DATASET v1.0 Category: Building a JSON Parser ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_KEY_LENGTH 128
#define MAX_VALUE_LENGTH 256

typedef struct JsonNode {
    char key[MAX_KEY_LENGTH];
    char value[MAX_VALUE_LENGTH];
    struct JsonNode* next;
} JsonNode;

JsonNode* createNode(const char* key, const char* value) {
    JsonNode* newNode = (JsonNode*)malloc(sizeof(JsonNode));
    if (newNode) {
        strncpy(newNode->key, key, MAX_KEY_LENGTH);
        strncpy(newNode->value, value, MAX_VALUE_LENGTH);
        newNode->next = NULL;
    }
    return newNode;
}

void appendNode(JsonNode** head, JsonNode* newNode) {
    if (*head == NULL) {
        *head = newNode;
    } else {
        JsonNode* current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}

void freeList(JsonNode* head) {
    JsonNode* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

void printList(const JsonNode* head) {
    while (head != NULL) {
        printf("Key: %s, Value: %s\n", head->key, head->value);
        head = head->next;
    }
}

void parseJson(const char* jsonString, JsonNode** head) {
    const char* p = jsonString;
    char key[MAX_KEY_LENGTH];
    char value[MAX_VALUE_LENGTH];
    while (*p) {
        // Read key
        if (*p == '\"') {
            p++;
            int keyIndex = 0;
            while (*p != '\"' && keyIndex < MAX_KEY_LENGTH - 1) {
                key[keyIndex++] = *p++;
            }
            key[keyIndex] = '\0';
            p += 2; // Skip over '":"'

            // Read value
            if (*p == '\"') {
                p++;
                int valueIndex = 0;
                while (*p != '\"' && valueIndex < MAX_VALUE_LENGTH - 1) {
                    value[valueIndex++] = *p++;
                }
                value[valueIndex] = '\0';
                appendNode(head, createNode(key, value));
            }
        }
        p++;
    }
}

int main() {
    const char* jsonString = "{\"name\": \"John\", \"age\": \"30\", \"city\": \"New York\"}";
    JsonNode* jsonHead = NULL;

    parseJson(jsonString, &jsonHead);
    printList(jsonHead);
    freeList(jsonHead);

    return 0;
}