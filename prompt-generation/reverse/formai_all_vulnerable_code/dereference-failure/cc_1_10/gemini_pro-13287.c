//GEMINI-pro DATASET v1.0 Category: Building a XML Parser ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    char *tag;
    struct node *parent;
    struct node *firstChild;
    struct node *nextSibling;
    char *data;
} node;

node *parse(char *xml) {
    node *root = NULL, *current = NULL;
    int i = 0;
    while (xml[i]) {
        if (xml[i] == '<') {
            if (xml[i + 1] == '/') {
                current = current->parent;
                i += 2;
                while (xml[i] != '>') i++;
            } else {
                node *new = malloc(sizeof(node));
                new->tag = malloc(sizeof(char) * 100);
                new->parent = current;
                new->firstChild = NULL;
                new->nextSibling = NULL;
                new->data = NULL;
                int j = 0;
                while (xml[i + j] != ' ' && xml[i + j] != '>' && xml[i + j] != '/') j++;
                strncpy(new->tag, xml + i + 1, j - 1);
                new->tag[j - 1] = '\0';
                if (current) {
                    if (!current->firstChild) current->firstChild = new;
                    else {
                        node *tmp = current->firstChild;
                        while (tmp->nextSibling) tmp = tmp->nextSibling;
                        tmp->nextSibling = new;
                    }
                } else root = new;
                current = new;
                i += j + 1;
            }
        } else if (xml[i] != '\n') {
            int j = 0;
            while (xml[i + j] != '<' && xml[i + j] != '\0') j++;
            current->data = malloc(sizeof(char) * (j + 1));
            strncpy(current->data, xml + i, j);
            current->data[j] = '\0';
            i += j;
        } else i++;
    }
    return root;
}

void print(node *root) {
    if (!root) return;
    printf("<%s", root->tag);
    if (root->data) printf(">%s</%s>", root->data, root->tag);
    else {
        printf(">");
        print(root->firstChild);
        printf("</%s>", root->tag);
    }
    print(root->nextSibling);
}

int main() {
    char *xml = "<root><child>Hello</child><child>World</child></root>";
    node *root = parse(xml);
    print(root);
    return 0;
}