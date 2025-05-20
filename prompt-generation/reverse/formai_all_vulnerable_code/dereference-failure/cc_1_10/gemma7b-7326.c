//Gemma-7B DATASET v1.0 Category: Building a JSON Parser ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

typedef struct JsonNode {
    char *data;
    struct JsonNode *next;
    struct JsonNode *child;
} JsonNode;

JsonNode *parseJson(char *jsonStr) {
    JsonNode *head = NULL;
    JsonNode *currNode = NULL;

    // Allocate memory for the first node
    if (head == NULL) {
        head = (JsonNode *)malloc(sizeof(JsonNode));
        currNode = head;
    }

    // Parse the JSON string
    // (This code can be replaced with a JSON parser library)
    char *ptr = jsonStr;
    while (*ptr) {
        // Check if the current character is a key-value pair delimiter
        if (*ptr == '{') {
            // Allocate memory for a new node
            currNode->child = (JsonNode *)malloc(sizeof(JsonNode));
            currNode = currNode->child;
        } else if (*ptr == '}') {
            // Null terminate the data of the current node
            currNode->data = NULL;
            currNode = head;
        } else if (*ptr == '"') {
            // Store the key or value in the current node
            ptr++;
            currNode->data = malloc(MAX_BUFFER_SIZE);
            strcpy(currNode->data, ptr);
        } else if (*ptr == ':') {
            // Skip the colon
            ptr++;
        }
        ptr++;
    }

    // Return the head of the JSON tree
    return head;
}

int main() {
    char jsonStr[] = "{ 'name': 'John Doe', 'age': 30 }";
    JsonNode *head = parseJson(jsonStr);

    // Print the JSON data
    JsonNode *currNode = head;
    while (currNode) {
        printf("%s: %s\n", currNode->data, currNode->child->data);
        currNode = currNode->next;
    }

    return 0;
}