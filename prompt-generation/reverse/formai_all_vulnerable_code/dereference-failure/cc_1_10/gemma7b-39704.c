//Gemma-7B DATASET v1.0 Category: Building a JSON Parser ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char data;
    struct Node* next;
} Node;

typedef struct Parser {
    Node* head;
    char* json_str;
    int pos;
} Parser;

void parser_init(Parser* parser, char* json_str) {
    parser->head = NULL;
    parser->json_str = json_str;
    parser->pos = 0;
}

void parser_add_node(Parser* parser, char data) {
    Node* new_node = malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;

    if (parser->head == NULL) {
        parser->head = new_node;
    } else {
        parser->head->next = new_node;
        parser->head = new_node;
    }
}

void parser_parse(Parser* parser) {
    char current_char;

    while ((current_char = parser->json_str[parser->pos]) != '\0') {
        switch (current_char) {
            case '"':
                parser_add_node(parser, '"');
                break;
            case ':':
                parser_add_node(parser, ':');
                break;
            case ',':
                parser_add_node(parser, ',');
                break;
            case ' ':
                parser_add_node(parser, ' ');
                break;
            default:
                parser_add_node(parser, current_char);
                break;
        }

        parser->pos++;
    }
}

int main() {
    char* json_str = "{\"name\":\"John Doe\", \"age\":30}";
    Parser* parser = malloc(sizeof(Parser));

    parser_init(parser, json_str);
    parser_parse(parser);

    // Print the JSON data
    Node* current_node = parser->head;
    while (current_node) {
        printf("%c ", current_node->data);
        current_node = current_node->next;
    }

    printf("\n");

    return 0;
}