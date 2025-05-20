//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_JSON_LENGTH 1000
#define MAX_STRING_LENGTH 100

typedef enum {
    JSON_OBJECT,
    JSON_ARRAY,
    JSON_STRING,
    JSON_NUMBER,
    JSON_BOOL,
    JSON_NULL
} json_type;

typedef struct json_node{
    json_type type;
    char *key;
    union {
        int i;
        double d;
        char *s;
        struct json_node *next;
        struct json_node *child;
    } value;
} json_node;

json_node* parse_json(char *json);

int main(void) {
    char json_string[MAX_JSON_LENGTH] = "{\"name\": \"John\",\"age\":30, \"is_awesome\": true, \"languages\" : [\"C\", \"Python\"]}";
    json_node *root = parse_json(json_string);
    printf("Hello, I am the funniest JSON parser in the world!\n");
    return 0;
}

json_node* parse_json(char *json) {
    json_node *root = malloc(sizeof(json_node));
    root->key = NULL;
    root->value.child = NULL;
    char *current = json;
    char *start = NULL;
    char key[MAX_STRING_LENGTH];
    int key_length = 0;
    int in_string = 0;
    int in_key = 0;
    while (*current != '\0') {
        if (*current == '{') {
            root->type = JSON_OBJECT;
            json_node *child = parse_json(current + 1);
        }
        else if (*current == '}') {
            break;
        }
        else if (*current == '[') {
            root->type = JSON_ARRAY;
            json_node *child = parse_json(current + 1);
        }
        else if (*current == ']') {
            break;
        }
        else if (*current == ',') {
            json_node *next = parse_json(current + 1);
            root->value.next = next;
        }
        else if (*current == ':') {
            if (in_key) {
                in_key = 0;
                key[key_length] = '\0';
                root->key = malloc(strlen(key) + 1);
                strcpy(root->key, key);
            }
        }
        else if (*current == '\"') {
            in_string = !in_string;
        }
        else {
            if (in_string && in_key) {
                key[key_length++] = *current;
            }
        }
        current++;
    }
    return root;
}