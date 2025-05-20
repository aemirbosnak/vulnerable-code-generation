//GPT-4o-mini DATASET v1.0 Category: Building a JSON Parser ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_JSON_SIZE 1024
#define MAX_KEY_SIZE 256
#define MAX_VALUE_SIZE 256

typedef enum {
    JSON_UNDEFINED,
    JSON_STRING,
    JSON_NUMBER,
    JSON_BOOLEAN,
    JSON_NULL,
    JSON_OBJECT,
    JSON_ARRAY
} JsonType;

typedef struct JsonNode {
    char key[MAX_KEY_SIZE];
    char value[MAX_VALUE_SIZE];
    JsonType type;
    struct JsonNode *next;
} JsonNode;

typedef struct {
    JsonNode *head;
} JsonObject;

// Function declarations
JsonObject *parse_json(const char *json_string);
void free_json_object(JsonObject *json_obj);
void add_key_value(JsonObject *json_obj, const char *key, const char *value, JsonType type);
void trim_whitespace(char **str);
void print_json_object(JsonObject *json_obj);

// Main function
int main() {
    const char *json_string = "{\"name\":\"John\", \"age\":30, \"isStudent\":false, \"address\":null}";
    
    JsonObject *json_obj = parse_json(json_string);
    print_json_object(json_obj);
    
    free_json_object(json_obj);
    return 0;
}

// Function to parse a JSON string
JsonObject *parse_json(const char *json_string) {
    JsonObject *json_obj = malloc(sizeof(JsonObject));
    json_obj->head = NULL;

    char *json_copy = strdup(json_string);
    trim_whitespace(&json_copy);

    char *token = strtok(json_copy, "{,:\"}");
    while (token != NULL) {
        char key[MAX_KEY_SIZE] = {0};
        char value[MAX_VALUE_SIZE] = {0};
        JsonType type = JSON_UNDEFINED;

        strcpy(key, token);
        trim_whitespace(&token);
        
        // Getting the next token for value
        token = strtok(NULL, "{,:\"}");
        strcpy(value, token);
        trim_whitespace(&token);
        
        // Determine the type of the value
        if (strcmp(value, "true") == 0 || strcmp(value, "false") == 0) {
            type = JSON_BOOLEAN;
        } else if (strcmp(value, "null") == 0) {
            type = JSON_NULL;
        } else if (isdigit(value[0]) || value[0] == '-') {
            type = JSON_NUMBER;
        } else {
            type = JSON_STRING;
        }

        add_key_value(json_obj, key, value, type);
        token = strtok(NULL, "{,:\"}");
    }

    free(json_copy);
    return json_obj;
}

// Add key-value pair to the JSON object
void add_key_value(JsonObject *json_obj, const char *key, const char *value, JsonType type) {
    JsonNode *new_node = malloc(sizeof(JsonNode));
    strncpy(new_node->key, key, MAX_KEY_SIZE);
    strncpy(new_node->value, value, MAX_VALUE_SIZE);
    new_node->type = type;
    new_node->next = json_obj->head;
    json_obj->head = new_node;
}

// Print the contents of the JSON object
void print_json_object(JsonObject *json_obj) {
    JsonNode *current = json_obj->head;
    while (current) {
        printf("Key: %s, Value: %s, Type: %d\n", current->key, current->value, current->type);
        current = current->next;
    }
}

// Free the allocated memory for the JSON object
void free_json_object(JsonObject *json_obj) {
    JsonNode *current = json_obj->head;
    while (current) {
        JsonNode *temp = current;
        current = current->next;
        free(temp);
    }
    free(json_obj);
}

// Trim whitespace from the string
void trim_whitespace(char **str) {
    char *end;
    while (isspace((unsigned char)(*str)[0])) (*str)++;
    end = *str + strlen(*str) - 1;
    while (end > *str && isspace((unsigned char)*end)) end--;
    end[1] = '\0';
}