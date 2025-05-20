//GPT-4o-mini DATASET v1.0 Category: Building a JSON Parser ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER 1024

typedef struct JSONValue {
    char key[MAX_BUFFER];
    char value[MAX_BUFFER];
    struct JSONValue *next;
} JSONValue;

void parseJSON(const char *json, JSONValue **head) {
    const char *cur = json;
    JSONValue *newValue = NULL;
    
    while (*cur) {
        if (*cur == '{') {
            cur++; // Skip '{'
            continue;
        }
        
        if (*cur == '}') {
            break; // End of JSON object
        }

        newValue = (JSONValue *)malloc(sizeof(JSONValue));
        if (!newValue) {
            fprintf(stderr, "Memory allocation failure\n");
            exit(1);
        }
        
        // Read key (skipping quotes)
        cur++; // skip past '"'
        char *keyStart = (char*)cur;
        while (*cur && *cur != '"') {
            cur++;
        }
        strncpy(newValue->key, keyStart, cur - keyStart);
        newValue->key[cur - keyStart] = '\0';

        cur++; // skip closing '"'
        cur++; // skip past ':'

        // Read value (skipping quotes)
        cur++; // skip past '"'
        char *valueStart = (char*)cur;
        while (*cur && *cur != '"') {
            cur++;
        }
        strncpy(newValue->value, valueStart, cur - valueStart);
        newValue->value[cur - valueStart] = '\0';

        // Append to the list
        newValue->next = *head;
        *head = newValue;

        cur++; // skip closing '"'
        if (*cur == ',') {
            cur++; // skip past ','
        }
    }
}

void printJSONValues(const JSONValue *head) {
    const JSONValue *current = head;
    while (current) {
        printf("Key: %s, Value: %s\n", current->key, current->value);
        current = current->next;
    }
}

void freeJSONList(JSONValue *head) {
    JSONValue *current = head;
    JSONValue *next;

    while (current) {
        next = current->next;
        free(current);
        current = next;
    }
}

char *getNextLine(FILE *file) {
    char *line = malloc(MAX_BUFFER);
    if (!line) {
        fprintf(stderr, "Memory allocation failure\n");
        exit(1);
    }
    
    if (fgets(line, MAX_BUFFER, file) != NULL) return line;

    free(line);
    return NULL;
}

int main() {
    const char *json = "{\"name\":\"Rover\",\"type\":\"robot\",\"status\":\"active\"}";
    JSONValue *jsonValues = NULL;

    printf("Parsing JSON in the wasteland...\n");
    parseJSON(json, &jsonValues);
    
    printf("Extracted data:\n");
    printJSONValues(jsonValues);
    
    // Free the allocated memory
    freeJSONList(jsonValues);

    return 0;
}