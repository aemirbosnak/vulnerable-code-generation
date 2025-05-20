//Falcon-180B DATASET v1.0 Category: Building a XML Parser ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Node structure for XML parser
typedef struct node {
    char* name;
    char* value;
    struct node* child;
    struct node* next;
} Node;

Node* createNode(char* name, char* value) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->name = name;
    newNode->value = value;
    newNode->child = NULL;
    newNode->next = NULL;
    return newNode;
}

Node* addChild(Node* parent, Node* child) {
    if (parent->child == NULL) {
        parent->child = child;
    } else {
        Node* temp = parent->child;
        while (temp->next!= NULL) {
            temp = temp->next;
        }
        temp->next = child;
    }
    return parent;
}

void printNode(Node* node, int depth) {
    for (int i = 0; i < depth; i++) {
        printf("  ");
    }
    printf("%s=%s\n", node->name, node->value);
    if (node->child!= NULL) {
        Node* child = node->child;
        while (child!= NULL) {
            printNode(child, depth + 1);
            child = child->next;
        }
    }
}

int main() {
    FILE* fp = fopen("example.xml", "r");
    if (fp == NULL) {
        printf("Error: Unable to open file\n");
        exit(1);
    }

    char ch;
    Node* root = NULL;
    Node* current = NULL;

    while ((ch = fgetc(fp))!= EOF) {
        if (ch == '<') {
            char name[100];
            int i = 0;
            while ((ch = fgetc(fp))!= '>' && ch!= EOF) {
                if (i < 100) {
                    name[i++] = ch;
                }
            }
            name[i] = '\0';

            if (root == NULL) {
                root = createNode(name, "");
                current = root;
            } else {
                current = addChild(current, createNode(name, ""));
            }
        } else if (ch == '"') {
            char value[100];
            int i = 0;
            while ((ch = fgetc(fp))!= '"' && ch!= EOF) {
                if (i < 100) {
                    value[i++] = ch;
                }
            }
            value[i] = '\0';

            if (current->value == NULL) {
                current->value = strdup(value);
            }
        }
    }

    fclose(fp);

    printNode(root, 0);

    return 0;
}