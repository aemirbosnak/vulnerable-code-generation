//GPT-4o-mini DATASET v1.0 Category: Building a JSON Parser ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_JSON_SIZE 1024
#define MAX_TOKEN_SIZE 256

typedef struct JSONPair {
    char key[MAX_TOKEN_SIZE];
    char value[MAX_TOKEN_SIZE];
    struct JSONPair* next;
} JSONPair;

typedef struct JSONObject {
    JSONPair* head;
} JSONObject;

// Function prototypes
JSONObject* parse_json(const char* json_str);
void free_json(JSONObject* json_object);
void print_json(JSONObject* json_object);
char* trim_whitespace(char* str);
char* extract_key(const char* json_str, int* index);
char* extract_value(const char* json_str, int* index);

// Main function
int main() {
    const char* json_data = "{\"name\": \"Alice\", \"age\": 25, \"city\": \"Wonderland\"}";
    JSONObject* json_object = parse_json(json_data);

    if (json_object) {
        print_json(json_object);
        free_json(json_object);
    } else {
        printf("Failed to parse JSON.\n");
    }

    return 0;
}

// Parse JSON function
JSONObject* parse_json(const char* json_str) {
    JSONObject* json_object = (JSONObject*)malloc(sizeof(JSONObject));
    if (!json_object) return NULL;

    json_object->head = NULL;
    int index = 0;
    while (json_str[index]) {
        // Skip whitespace
        while (isspace(json_str[index])) index++;
        if (json_str[index] == '\0') break;

        // Extract key and value
        char* key = extract_key(json_str, &index);
        char* value = extract_value(json_str, &index);
        if (key && value) {
            JSONPair* new_pair = (JSONPair*)malloc(sizeof(JSONPair));
            if (!new_pair) {
                free(key);
                free(value);
                free_json(json_object);
                return NULL;
            }
            strcpy(new_pair->key, key);
            strcpy(new_pair->value, value);
            new_pair->next = json_object->head;
            json_object->head = new_pair;
            free(key);
            free(value);
        } else {
            free(key);
            free(value);
            free_json(json_object);
            return NULL;
        }
    }
    return json_object;
}

// Free JSON object
void free_json(JSONObject* json_object) {
    JSONPair* current = json_object->head;
    while (current) {
        JSONPair* temp = current;
        current = current->next;
        free(temp);
    }
    free(json_object);
}

// Print JSON object
void print_json(JSONObject* json_object) {
    JSONPair* current = json_object->head;
    while (current) {
        printf("%s: %s\n", current->key, current->value);
        current = current->next;
    }
}

// Trim whitespace from a string
char* trim_whitespace(char* str) {
    char* end;
    while (isspace((unsigned char)*str)) str++;
    if (*str == 0) return str;
    end = str + strlen(str) - 1;
    while (end > str && isspace((unsigned char)*end)) end--;
    *(end + 1) = 0;
    return str;
}

// Extract key from JSON string
char* extract_key(const char* json_str, int* index) {
    if (json_str[*index] != '\"') return NULL;
    (*index)++;
    const char* start = json_str + *index;

    while (json_str[*index] && json_str[*index] != '\"') {
        (*index)++;
    }

    if (json_str[*index] != '\"') return NULL;
    size_t length = json_str + *index - start;
    char* key = (char*)malloc(length + 1);
    strncpy(key, start, length);
    key[length] = '\0';
    (*index)++; // Skip closing quote
    return trim_whitespace(key);
}

// Extract value from JSON string
char* extract_value(const char* json_str, int* index) {
    while (isspace(json_str[*index])) (*index)++;
    if (json_str[*index] == ':') (*index)++; // skip colon
    while (isspace(json_str[*index])) (*index)++;

    char* value = NULL;
    if (json_str[*index] == '\"') {
        // Extract string value
        (*index)++;
        const char* start = json_str + *index;
        while (json_str[*index] && json_str[*index] != '\"') {
            (*index)++;
        }
        if (json_str[*index] != '\"') return NULL;
        size_t length = json_str + *index - start;
        value = (char*)malloc(length + 1);
        strncpy(value, start, length);
        value[length] = '\0';
        (*index)++;
    } else {
        // Extract number value
        const char* start = json_str + *index;
        while (isdigit(json_str[*index])) {
            (*index)++;
        }
        size_t length = json_str + *index - start;
        value = (char*)malloc(length + 1);
        strncpy(value, start, length);
        value[length] = '\0';
    }
    return trim_whitespace(value);
}