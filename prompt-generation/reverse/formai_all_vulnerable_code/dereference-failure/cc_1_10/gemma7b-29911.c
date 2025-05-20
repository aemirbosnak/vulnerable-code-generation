//Gemma-7B DATASET v1.0 Category: Syntax parsing ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char data;
    struct Node* next;
} Node;

typedef struct Parser {
    Node* head;
    char* input;
    int pos;
} Parser;

Parser* parser_init(char* input) {
    Parser* p = malloc(sizeof(Parser));
    p->head = NULL;
    p->input = input;
    p->pos = 0;
    return p;
}

void parser_parse(Parser* p) {
    char token[10] = "";
    while (p->pos < strlen(p->input) && token[0] == '\0') {
        char ch = p->input[p->pos];
        p->pos++;
        if (ch >= 'a' && ch <= 'z') {
            token[0] = ch;
            token[1] = '\0';
        } else if (ch >= 'A' && ch <= 'Z') {
            token[0] = ch;
            token[1] = '\0';
        } else if (ch == '+') {
            token[0] = '+';
            token[1] = '\0';
        } else if (ch == '-') {
            token[0] = '-';
            token[1] = '\0';
        } else if (ch == '*') {
            token[0] = '*';
            token[1] = '\0';
        } else if (ch == '/') {
            token[0] = '/';
            token[1] = '\0';
        } else if (ch == '(') {
            token[0] = '(';
            token[1] = '\0';
        } else if (ch == ')') {
            token[0] = ')';
            token[1] = '\0';
        }
        if (token[0] != '\0') {
            Node* node = malloc(sizeof(Node));
            node->data = token[0];
            node->next = p->head;
            p->head = node;
        }
    }
}

int main() {
    char* input = "abc+12*";
    Parser* p = parser_init(input);
    parser_parse(p);
    Node* node = p->head;
    while (node) {
        printf("%c ", node->data);
        node = node->next;
    }
    printf("\n");
    return 0;
}