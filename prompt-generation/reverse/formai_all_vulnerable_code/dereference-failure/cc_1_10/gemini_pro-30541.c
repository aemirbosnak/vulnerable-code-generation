//GEMINI-pro DATASET v1.0 Category: Building a JSON Parser ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Our JSON object, a celestial body of data
typedef struct JSON {
    char *key;  // The key to our JSON treasure trove
    char *value;  // The value that unlocks its secrets
    struct JSON *next;  // A pointer to the next JSON object in our celestial chain
} JSON;

// Our JSON parser, a celestial navigator
JSON *parseJSON(const char *json) {
    JSON *head = NULL;  // The head of our JSON linked list, where all good things begin
    JSON *current = NULL;  // The current JSON object we're parsing, our intrepid explorer
    
    char *key = NULL;  // The key to our JSON kingdom
    char *value = NULL;  // The value, the treasure we seek
    char *start = NULL;  // The starting point of our parsing adventure
    char *end = NULL;  // The end of our parsing voyage
    
    while (*json != '\0') {
        // Is it a curly brace? A gateway to a new realm of JSON wonders?
        if (*json == '{') {
            start = json + 1;  // Mark the start of our exploration
            end = strchr(start, '}');  // Find the end of our JSON realm
            if (end == NULL) {
                fprintf(stderr, "Error: Invalid JSON format\n");
                return NULL;
            }
            
            // Parse the key and value within this JSON realm
            key = strtok(start, ":");
            value = strtok(NULL, ":");
            
            // Create a new JSON object to hold our celestial treasure
            JSON *new = malloc(sizeof(JSON));
            new->key = strdup(key);
            new->value = strdup(value);
            new->next = NULL;
            
            // Link our new JSON object into our celestial chain
            if (head == NULL) {
                head = new;
            } else {
                current->next = new;
            }
            
            // Advance our intrepid explorer to the next JSON realm
            current = new;
            
            // Skip past the curly brace
            json = end + 1;
        }
        // Is it a square brace? A gateway to an array of JSON wonders?
        else if (*json == '[') {
            fprintf(stderr, "Error: Arrays not supported yet\n");
            return NULL;
        }
        // Is it a string? A treasure trove of characters?
        else if (*json == '"') {
            start = json + 1;  // Mark the start of our stringy adventure
            end = strchr(start, '"');  // Find the end of our stringy realm
            if (end == NULL) {
                fprintf(stderr, "Error: Invalid JSON format\n");
                return NULL;
            }
            
            // Create a new JSON object to hold our stringy treasure
            JSON *new = malloc(sizeof(JSON));
            new->key = NULL;
            new->value = strndup(start, end - start);
            new->next = NULL;
            
            // Link our new JSON object into our celestial chain
            if (head == NULL) {
                head = new;
            } else {
                current->next = new;
            }
            
            // Advance our intrepid explorer to the next JSON realm
            current = new;
            
            // Skip past the string
            json = end + 1;
        }
        // Is it a number? A numerical treasure?
        else if (*json >= '0' && *json <= '9') {
            start = json;  // Mark the start of our numerical adventure
            end = strchr(start, ',');  // Find the end of our numerical realm
            if (end == NULL) {
                end = strchr(start, '}');  // Or find the end of our JSON realm
            }
            if (end == NULL) {
                fprintf(stderr, "Error: Invalid JSON format\n");
                return NULL;
            }
            
            // Create a new JSON object to hold our numerical treasure
            JSON *new = malloc(sizeof(JSON));
            new->key = NULL;
            new->value = strndup(start, end - start);
            new->next = NULL;
            
            // Link our new JSON object into our celestial chain
            if (head == NULL) {
                head = new;
            } else {
                current->next = new;
            }
            
            // Advance our intrepid explorer to the next JSON realm
            current = new;
            
            // Skip past the number
            json = end + 1;
        }
        // Is it a space? A void in the JSON expanse?
        else if (*json == ' ') {
            // Skip past the space
            json++;
        }
        // Is it a comma? A separator of JSON realms?
        else if (*json == ',') {
            // Skip past the comma
            json++;
        }
        // Is it the end of our JSON journey?
        else if (*json == '\0') {
            // We've reached the end of our JSON universe
            break;
        }
        // Is it an invalid character? A cosmic anomaly?
        else {
            fprintf(stderr, "Error: Invalid JSON format\n");
            return NULL;
        }
    }
    
    return head;  // Return the head of our celestial JSON chain
}

// A function to free the celestial JSON chain
void freeJSON(JSON *json) {
    if (json == NULL) {
        return;
    }
    
    freeJSON(json->next);  // Free the next JSON realm in the chain
    free(json->key);  // Free the key to our JSON kingdom
    free(json->value);  // Free the value, the treasure we seek
    free(json);  // Free the JSON object itself
}

// A function to print the celestial JSON chain
void printJSON(JSON *json) {
    if (json == NULL) {
        return;
    }
    
    printf("{\n");  // Start of a new JSON realm
    
    while (json != NULL) {
        if (json->key != NULL) {
            printf("    \"%s\": \"%s\",\n", json->key, json->value);  // Print key-value pair
        } else {
            printf("    %s,\n", json->value);  // Print value
        }
        
        json = json->next;  // Advance to the next JSON realm
    }
    
    printf("}\n");  // End of the JSON realm
}

// An example of parsing a JSON string
int main() {
    const char *json = "{\"name\": \"John Doe\", \"age\": 30, \"city\": \"New York\"}";
    
    JSON *parsedJSON = parseJSON(json);
    if (parsedJSON == NULL) {
        fprintf(stderr, "Error: Failed to parse JSON\n");
        return 1;
    }
    
    printJSON(parsedJSON);
    
    freeJSON(parsedJSON);
    
    return 0;
}