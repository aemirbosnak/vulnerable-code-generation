//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_JSON_LEN 1024

// JSON Node data structure
typedef struct json_node {
    char* key;
    char* value;
    struct json_node* next;
} json_node;

// Function to create a new JSON Node
json_node* new_json_node(char* key, char* value) {
    json_node* node = (json_node*) malloc(sizeof(json_node));
    node->key = key;
    node->value = value;
    node->next = NULL;
    return node;
}

// Function to parse JSON Object
json_node* parse_json(char* json) {
    char key[MAX_JSON_LEN], value[MAX_JSON_LEN];
    int i = 0, j = 0, in_quotes = 0;
    json_node* head = NULL, *tail = NULL;
    while (json[i]) {
        if (json[i] == '\"') {
            in_quotes = !in_quotes;
        } else if (json[i] == ':' && !in_quotes) {
            key[j] = '\0';
            j = 0;
        } else if (json[i] == ',' && !in_quotes) {
            value[j] = '\0';
            j = 0;
            if (head == NULL) {
                head = new_json_node(key, value);
                tail = head;
            } else {
                tail->next = new_json_node(key, value);
                tail = tail->next;
            }
        } else if (json[i] == '}') {
            value[j] = '\0';
            if (head == NULL) {
                head = new_json_node(key, value);
                tail = head;
            } else {
                tail->next = new_json_node(key, value);
                tail = tail->next;
            }
            break;
        } else if (in_quotes) {
            if (j == 0) {
                key[0] = json[i];
                j++;
            } else {
                value[j] = json[i];
                j++;
            }
        }
        i++;
    }
    return head;
}

// Function to print the parsed JSON Object
void print_json(json_node* node) {
    printf("{\n");
    while (node) {
        printf("\t\"%s\": \"%s\"", node->key, node->value);
        if (node->next) {
            printf(",");
        }
        printf("\n");
        node = node->next;
    }
    printf("}\n");
}

int main() {
    char json[MAX_JSON_LEN] = "{\"name\": \"John Smith\", \"age\": \"30\", \"city\": \"New York\"}";
    json_node* root = parse_json(json);
    print_json(root);
    return 0;
}