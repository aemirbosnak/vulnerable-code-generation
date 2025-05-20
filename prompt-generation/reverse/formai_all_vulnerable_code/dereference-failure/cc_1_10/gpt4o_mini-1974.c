//GPT-4o-mini DATASET v1.0 Category: Building a JSON Parser ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_JSON_SIZE 1024
#define MAX_KEY_SIZE 128
#define MAX_VALUE_SIZE 256

typedef struct JSONNode {
    char key[MAX_KEY_SIZE];
    char value[MAX_VALUE_SIZE];
    struct JSONNode* next;
} JSONNode;

JSONNode* createNode(const char* key, const char* value) {
    JSONNode* node = (JSONNode*)malloc(sizeof(JSONNode));
    strncpy(node->key, key, MAX_KEY_SIZE);
    strncpy(node->value, value, MAX_VALUE_SIZE);
    node->next = NULL;
    return node;
}

void freeList(JSONNode* head) {
    JSONNode* current = head;
    JSONNode* next;
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
}

void parseJSON(const char* json, JSONNode** head) {
    const char* p = json;
    char key[MAX_KEY_SIZE] = {0};
    char value[MAX_VALUE_SIZE] = {0};
    int inString = 0;
    int keyIndex = 0, valueIndex = 0;

    while (*p) {
        // Skip whitespace
        while (isspace(*p)) p++;
        
        // Check for the beginning of a key
        if (*p == '"') {
            inString = !inString; // toggle inverted state
            p++;
            keyIndex = 0;

            // Read key
            while (*p && (*p != '"' && inString)) {
                key[keyIndex++] = *p;
                p++;
            }
            key[keyIndex] = '\0'; // null-terminate key
            inString = 0; // reset for value

            p++; // skip the closing quote

            // Skip whitespace
            while (isspace(*p)) p++;
            if (*p != ':') {
                fprintf(stderr, "Error: Expected ':' after key.\n");
                return;
            }
            p++; // skip ':'

            // Read value
            inString = 1; // now we expect a value
            valueIndex = 0;
            while (*p && (*p != ',' && *p != '}') && inString) {
                if (*p == '"') {
                    inString = !inString;  // toggle inverted state
                    p++;
                    continue;
                }

                if (inString) {
                    value[valueIndex++] = *p;
                }
                p++;
            }
            value[valueIndex] = '\0'; // null-terminate value

            // Create a new JSON node
            JSONNode* newNode = createNode(key, value);
            newNode->next = *head;
            *head = newNode;

            // Skip comma
            if (*p == ',') p++;
        }
        // Check for the ending brace
        if (*p == '}') {
            break;
        }
    }
}

void printJSON(JSONNode* head) {
    JSONNode* current = head;
    while (current != NULL) {
        printf("Key: \"%s\", Value: \"%s\"\n", current->key, current->value);
        current = current->next;
    }
}

int main() {
    char json[MAX_JSON_SIZE];
    printf("Enter JSON data (Max %d characters):\n", MAX_JSON_SIZE);
    fgets(json, MAX_JSON_SIZE, stdin);

    // Remove newline character
    size_t len = strlen(json);
    if (len > 0 && json[len - 1] == '\n') {
        json[len - 1] = '\0';
    }

    JSONNode* head = NULL;
    parseJSON(json, &head);
    printJSON(head);
    freeList(head);
    
    return 0;
}