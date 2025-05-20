//GPT-4o-mini DATASET v1.0 Category: Building a JSON Parser ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_JSON_LENGTH 1024
#define MAX_KEY_LENGTH 256
#define MAX_VALUE_LENGTH 256

typedef struct JSONNode {
    char key[MAX_KEY_LENGTH];
    char value[MAX_VALUE_LENGTH];
    struct JSONNode *next;
} JSONNode;

JSONNode* create_node(const char *key, const char *value) {
    JSONNode *node = (JSONNode *)malloc(sizeof(JSONNode));
    if (node) {
        strncpy(node->key, key, MAX_KEY_LENGTH);
        strncpy(node->value, value, MAX_VALUE_LENGTH);
        node->next = NULL;
    }
    return node;
}

void free_list(JSONNode *node) {
    while (node) {
        JSONNode *temp = node;
        node = node->next;
        free(temp);
    }
}

void print_json(JSONNode *node) {
    printf("{\n");
    while (node) {
        printf("  \"%s\": \"%s\"", node->key, node->value);
        node = node->next;
        if (node) {
            printf(",\n");
        } else {
            printf("\n");
        }
    }
    printf("}\n");
}

const char* skip_whitespace(const char *str) {
    while (isspace(*str)) str++;
    return str;
}

char* extract_key(const char **str) {
    const char *start = *str;
    while (**str != ':' && **str != '\0') {
        (*str)++;
    }
    size_t len = *str - start;
    char *key = (char *)malloc(len + 1);
    strncpy(key, start, len);
    key[len] = '\0';
    *str = skip_whitespace(*str + 1); // Move past the colon
    return key;
}

char* extract_value(const char **str) {
    const char *start = *str;
    while (**str != ',' && **str != '}' && **str != '\0') {
        (*str)++;
    }
    size_t len = *str - start;
    char *value = (char *)malloc(len + 1);
    strncpy(value, start, len);
    value[len] = '\0';
    *str = skip_whitespace(*str); // Move past the comma or brace
    return value;
}

JSONNode* parse_json(const char *json) {
    JSONNode *head = NULL, *tail = NULL;

    const char *p = skip_whitespace(json);
    while (*p != '\0') {
        if (*p == '{') {
            p++;
            continue;
        }
        if (*p == '}') {
            break;
        }
        
        char *key = extract_key(&p);
        p = skip_whitespace(p);
        
        if (*p == '"') {
            p++; // Skip the opening quote for the value
            char *value = extract_value(&p);
            p = skip_whitespace(p);
            if (*p == '"') {
                p++; // Skip the closing quote
            }
            
            JSONNode *node = create_node(key, value);
            free(key);
            free(value);
            if (!head) {
                head = tail = node;
            } else {
                tail->next = node;
                tail = node;
            }
        }
        
        p = skip_whitespace(p);
        if (*p == ',') {
            p++;
        }
    }

    return head;
}

int main() {
    printf("🎉 Welcome to the JSON Parser! 🎉\n");

    const char *json_input = "{\"name\": \"Alice\", \"age\": \"30\", \"city\": \"Wonderland\"}";
    printf("Parsing the following JSON string:\n%s\n\n", json_input);

    JSONNode *parsed_json = parse_json(json_input);
    printf("Parsed JSON in key-value pairs:\n");
    print_json(parsed_json);

    free_list(parsed_json);
    printf("\n💖 Thank you for using the JSON Parser! Until next time! 💖\n");

    return 0;
}