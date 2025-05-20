//FormAI DATASET v1.0 Category: HTML beautifier ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    char* tag;
    char* content;
    struct Node* next;
} Node;

int indent = 0;

void printIndent() {
    int i;
    for (i = 0; i < indent; i++) {
        printf("    ");
    }
}

void printTag(Node* node) {
    printIndent();
    printf("<%s>", node->tag);
    if (node->content != NULL) {
        printf("%s", node->content);
    }
    printf("\n");
}

void printClosingTag(Node* node) {
    printIndent();
    printf("</%s>\n", node->tag);
}

void printBeautified(Node* node) {
    printTag(node);
    if (node->next != NULL) {
        indent++;
        printBeautified(node->next);
        indent--;
    }
    printClosingTag(node);
}

Node* createNode(char* tag, char* content) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->tag = tag;
    node->content = content;
    node->next = NULL;
    return node;
}

void addNode(Node* parent, Node* child) {
    Node* curr = parent;
    while (curr->next != NULL) {
        curr = curr->next;
    }
    curr->next = child;
}

int main() {
    Node* html = createNode("html", NULL);
    Node* head = createNode("head", NULL);
    Node* title = createNode("title", "Beautify C HTML");
    Node* body = createNode("body", NULL);
    Node* h1 = createNode("h1", "Welcome");
    Node* p = createNode("p", "This program will beautify your C HTML!");

    addNode(html, head);
    addNode(html, body);
    addNode(head, title);
    addNode(body, h1);
    addNode(body, p);

    printBeautified(html);
    return 0;
}