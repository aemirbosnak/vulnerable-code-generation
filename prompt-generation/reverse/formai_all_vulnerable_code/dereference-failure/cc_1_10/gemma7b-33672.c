//Gemma-7B DATASET v1.0 Category: Building a XML Parser ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

typedef struct Node {
    char *data;
    struct Node *next;
} Node;

typedef struct Parser {
    Node *root;
    int state;
    char buffer[MAX_BUFFER_SIZE];
    int buffer_size;
    int current_position;
} Parser;

Parser *parser_init(void) {
    Parser *p = malloc(sizeof(Parser));
    p->root = NULL;
    p->state = 0;
    p->buffer_size = MAX_BUFFER_SIZE;
    p->current_position = 0;
    return p;
}

void parser_parse(Parser *p, char *xml_data) {
    int i = 0;
    for (; xml_data[i] != '\0'; i++) {
        switch (p->state) {
            case 0:
                if (xml_data[i] == '<') {
                    p->state = 1;
                    p->buffer[p->current_position++] = xml_data[i];
                } else {
                    p->buffer[p->current_position++] = xml_data[i];
                }
                break;
            case 1:
                if (xml_data[i] == '>' && p->current_position - 1 > 0) {
                    p->state = 0;
                    Node *node = malloc(sizeof(Node));
                    node->data = strdup(p->buffer);
                    node->next = p->root;
                    p->root = node;
                    p->current_position = 0;
                } else {
                    p->buffer[p->current_position++] = xml_data[i];
                }
                break;
        }
    }
}

void parser_print(Parser *p) {
    Node *node = p->root;
    while (node) {
        printf("%s\n", node->data);
        node = node->next;
    }
}

int main() {
    Parser *p = parser_init();
    parser_parse(p, "<foo><bar>baz</bar></foo>");
    parser_print(p);

    return 0;
}