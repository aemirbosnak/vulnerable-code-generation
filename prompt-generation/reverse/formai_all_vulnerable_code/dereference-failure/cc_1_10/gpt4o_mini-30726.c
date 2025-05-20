//GPT-4o-mini DATASET v1.0 Category: Building a JSON Parser ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_JSON_SIZE 1024
#define MAX_KEY_SIZE 128

typedef struct JsonValue {
    char *key;
    char *value;
    struct JsonValue *next;
} JsonValue;

void freeJsonValue(JsonValue *node) {
    if (node) {
        free(node->key);
        free(node->value);
        free(node);
    }
}

JsonValue *parseJson(const char *json) {
    JsonValue *head = NULL, *tail = NULL;
    const char *p = json;

    while (*p) {
        // Skip whitespace and commas
        while (isspace(*p) || *p == ',') p++;

        // Check for opening brace
        if (*p == '{') {
            p++;
            continue;
        }

        // Capture the "key"
        if (*p == '\"') {
            const char *start = ++p;
            while (*p && *p != '\"') p++;
            if (*p != '\"') {
                fprintf(stderr, "Error: Unmatched quotes in JSON.\n");
                return NULL;
            }
            size_t key_len = p - start;
            char *key = malloc(key_len + 1);
            strncpy(key, start, key_len);
            key[key_len] = '\0';
            p++; // Move past the closing quote

            // Skip whitespace and colon
            while (isspace(*p) || *p == ':') p++;

            // Capture the "value"
            if (*p == '\"') {
                start = ++p;
                while (*p && *p != '\"') p++;
                if (*p != '\"') {
                    free(key);
                    fprintf(stderr, "Error: Unmatched quotes in JSON.\n");
                    return NULL;
                }
                size_t value_len = p - start;
                char *value = malloc(value_len + 1);
                strncpy(value, start, value_len);
                value[value_len] = '\0';
                p++; // Move past the closing quote

                // Create a new JsonValue node
                JsonValue *newNode = malloc(sizeof(JsonValue));
                newNode->key = key;
                newNode->value = value;
                newNode->next = NULL;

                // Link the new node into the list
                if (tail) {
                    tail->next = newNode;
                } else {
                    head = newNode; // First node
                }
                tail = newNode; // Move tail to the new node
            } else {
                free(key);
                fprintf(stderr, "Error: Value must be a string in JSON.\n");
                return NULL;
            }
        }

        // Skip the closing brace
        while (*p && *p != '}') p++;
        if (*p == '}') {
            p++; // Move past the closing brace
        }
    }
    return head;
}

void printJson(JsonValue *node) {
    printf("{\n");
    while (node) {
        printf("  \"%s\": \"%s\"", node->key, node->value);
        node = node->next;
        if (node) printf(",\n");
    }
    printf("\n}\n");
}

void cleanupJson(JsonValue *node) {
    while (node) {
        JsonValue *nextNode = node->next;
        freeJsonValue(node);
        node = nextNode;
    }
}

int main() {
    const char *jsonInput = "{\"name\":\"Deckard\",\"role\":\"Blade Runner\",\"location\":\"Neon City\"}";

    printf("Loading JSON in the current dystopia...\n");
    
    JsonValue *jsonValues = parseJson(jsonInput);
    if (!jsonValues) {
        fprintf(stderr, "Failed to parse JSON. Check the fuel lines!\n");
        exit(EXIT_FAILURE);
    }

    printf("Parsed JSON data:\n");
    printJson(jsonValues);

    cleanupJson(jsonValues);
    printf("Data wiped from memory. It's safer this way...\n");

    return 0;
}