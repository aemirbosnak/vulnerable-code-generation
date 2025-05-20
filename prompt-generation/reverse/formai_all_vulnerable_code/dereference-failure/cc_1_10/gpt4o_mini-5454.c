//GPT-4o-mini DATASET v1.0 Category: Building a JSON Parser ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_JSON_LENGTH 1024
#define MAX_KEY_LENGTH 256
#define MAX_VALUE_LENGTH 256

typedef struct JsonNode {
    char key[MAX_KEY_LENGTH];
    char value[MAX_VALUE_LENGTH];
    struct JsonNode* next;
} JsonNode;

typedef struct JsonParser {
    JsonNode* head;
} JsonParser;

// Function Prototypes
JsonParser* create_json_parser();
void free_json_parser(JsonParser* parser);
void add_json_node(JsonParser* parser, const char* key, const char* value);
void parse_json(const char* json_str, JsonParser* parser);
void trim_whitespace(char* str);
void print_json(JsonParser* parser);

// Main function
int main() {
    const char* json_example = "{\"name\":\"John\", \"age\":\"30\", \"city\":\"New York\"}";
    JsonParser* parser = create_json_parser();

    parse_json(json_example, parser);
    print_json(parser);
    
    free_json_parser(parser);
    return 0;
}

// Function to create a new JsonParser
JsonParser* create_json_parser() {
    JsonParser* parser = (JsonParser*)malloc(sizeof(JsonParser));
    parser->head = NULL;
    return parser;
}

// Function to free memory used by JsonParser
void free_json_parser(JsonParser* parser) {
    JsonNode* current = parser->head;
    while (current != NULL) {
        JsonNode* temp = current;
        current = current->next;
        free(temp);
    }
    free(parser);
}

// Function to add a JSON node to the parser
void add_json_node(JsonParser* parser, const char* key, const char* value) {
    JsonNode* new_node = (JsonNode*)malloc(sizeof(JsonNode));
    strncpy(new_node->key, key, MAX_KEY_LENGTH);
    strncpy(new_node->value, value, MAX_VALUE_LENGTH);
    new_node->next = parser->head;
    parser->head = new_node;
}

// Function to parse a JSON string and populate the parser
void parse_json(const char* json_str, JsonParser* parser) {
    char key[MAX_KEY_LENGTH] = {0};
    char value[MAX_VALUE_LENGTH] = {0};
    int parsing_key = 1;
    int i = 0, j = 0;

    while (json_str[i] != '\0') {
        if (json_str[i] == '"') {
            i++;
            j = 0;
            while (json_str[i] != '"' && json_str[i] != '\0') {
                if (j < MAX_KEY_LENGTH - 1) {
                    if (parsing_key) {
                        key[j++] = json_str[i];
                    } else {
                        value[j++] = json_str[i];
                    }
                }
                i++;
            }
            key[j] = '\0';
            value[j] = '\0';
            parsing_key = !parsing_key;

            if (!parsing_key) {
                trim_whitespace(key);
                trim_whitespace(value);
                add_json_node(parser, key, value);
            }
        }
        i++;
    }
}

// Function to trim leading and trailing white spaces from a string
void trim_whitespace(char* str) {
    char* start = str;
    while (isspace((unsigned char)*start)) {
        start++;
    }
    char* end = start + strlen(start) - 1;
    while (end > start && isspace((unsigned char)*end)) {
        end--;
    }
    *(end + 1) = '\0';
    if (start != str) {
        memmove(str, start, strlen(start) + 1);
    }
}

// Function to print the parsed JSON nodes
void print_json(JsonParser* parser) {
    JsonNode* current = parser->head;
    printf("{\n");
    while (current != NULL) {
        printf("  \"%s\": \"%s\"", current->key, current->value);
        current = current->next;
        if (current != NULL) {
            printf(",\n");
        }
    }
    printf("\n}\n");
}