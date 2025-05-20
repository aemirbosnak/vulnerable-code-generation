//Gemma-7B DATASET v1.0 Category: Building a JSON Parser ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

typedef struct Node {
    char *data;
    struct Node *next;
} Node;

typedef struct JSONParser {
    Node *head;
    int depth;
} JSONParser;

JSONParser *parser_init(int depth) {
    JSONParser *parser = malloc(sizeof(JSONParser));
    parser->head = NULL;
    parser->depth = depth;
    return parser;
}

void parser_add_node(JSONParser *parser, char *data) {
    Node *newNode = malloc(sizeof(Node));
    newNode->data = strdup(data);
    newNode->next = NULL;

    if (parser->head == NULL) {
        parser->head = newNode;
    } else {
        Node *temp = parser->head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void parser_parse(JSONParser *parser, char *json_str) {
    char *buffer = malloc(MAX_BUFFER_SIZE);
    char *ptr = json_str;
    int index = 0;

    while (*ptr) {
        switch (*ptr) {
            case '"':
                parser_add_node(parser, ptr);
                break;
            case ':':
                parser_add_node(parser, ptr);
                break;
            case ',':
                parser_add_node(parser, ptr);
                break;
            default:
                buffer[index++] = *ptr;
                break;
        }

        ptr++;
    }

    free(buffer);
}

int main() {
    JSONParser *parser = parser_init(2);
    parser_parse(parser, "{ 'name': 'John Doe', 'age': 30 }");

    Node *node = parser->head;
    while (node) {
        printf("%s\n", node->data);
        node = node->next;
    }

    free(parser);
    return 0;
}