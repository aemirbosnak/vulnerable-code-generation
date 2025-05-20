//GPT-4o-mini DATASET v1.0 Category: Building a JSON Parser ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Define structure to hold JSON key-value pairs
typedef struct JsonNode {
    char *key;
    char *value;
    struct JsonNode *next;
} JsonNode;

// Function to create a new JSON node
JsonNode* createNode(const char *key, const char *value) {
    JsonNode *node = (JsonNode *) malloc(sizeof(JsonNode));
    node->key = strdup(key);
    node->value = strdup(value);
    node->next = NULL;
    return node;
}

// Function to free nodes in the JSON linked list
void freeJson(JsonNode *node) {
    JsonNode *temp;
    while (node) {
        temp = node;
        node = node->next;
        free(temp->key);
        free(temp->value);
        free(temp);
    }
}

// Function to skip white spaces in JSON
void skipWhitespace(const char **ptr) {
    while (isspace(**ptr)) {
        (*ptr)++;
    }
}

// Function to parse the JSON string
JsonNode* parseJson(const char *json) {
    JsonNode *head = NULL;
    JsonNode *tail = NULL;

    const char *ptr = json;
    skipWhitespace(&ptr);

    // Check for opening brace
    if (*ptr != '{') {
        fprintf(stderr, "Invalid JSON format\n");
        return NULL;
    }
    ptr++;

    while (*ptr) {
        skipWhitespace(&ptr);
        if (*ptr == '}') {
            break; // End of object
        }

        // Get key
        if (*ptr != '\"') {
            fprintf(stderr, "Expected string key\n");
            freeJson(head);
            return NULL;
        }
        ptr++;
        const char *keyStart = ptr;
        while (*ptr && *ptr != '\"') {
            ptr++;
        }
        if (!*ptr) {
            fprintf(stderr, "Unmatched quotes for key\n");
            freeJson(head);
            return NULL;
        }
        char *key = strndup(keyStart, ptr - keyStart);
        ptr++; // Skip closing quote

        skipWhitespace(&ptr);
        if (*ptr != ':') {
            fprintf(stderr, "Expected ':' after key\n");
            free(key);
            freeJson(head);
            return NULL;
        }
        ptr++; // Skip ':'

        skipWhitespace(&ptr);
        if (*ptr != '\"') {
            fprintf(stderr, "Expected string value\n");
            free(key);
            freeJson(head);
            return NULL;
        }
        ptr++;
        const char *valueStart = ptr;
        while (*ptr && *ptr != '\"') {
            ptr++;
        }
        if (!*ptr) {
            fprintf(stderr, "Unmatched quotes for value\n");
            free(key);
            freeJson(head);
            return NULL;
        }
        char *value = strndup(valueStart, ptr - valueStart);
        ptr++; // Skip closing quote

        // Create and link new node
        JsonNode *newNode = createNode(key, value);
        free(key);
        free(value);
        
        if (!head) {
            head = newNode;
        } else {
            tail->next = newNode;
        }
        tail = newNode;

        skipWhitespace(&ptr);
        if (*ptr == ',') {
            ptr++; // Skip ','
        } else if (*ptr != '}') {
            fprintf(stderr, "Expected ',' or '}'\n");
            freeJson(head);
            return NULL;
        }
    }

    return head;
}

// Function to print JSON nodes
void printJson(JsonNode *node) {
    while (node) {
        printf("\"%s\": \"%s\"\n", node->key, node->value);
        node = node->next;
    }
}

// Main function to demonstrate JSON parsing
int main() {
    const char *jsonString = "{\"name\": \"John\", \"age\": \"30\", \"city\": \"New York\"}";

    JsonNode *jsonData = parseJson(jsonString);
    if (jsonData) {
        printf("Parsed JSON:\n");
        printJson(jsonData);
        freeJson(jsonData); // Free allocated memory
    } else {
        printf("Failed to parse JSON\n");
    }

    return 0;
}