//Falcon2-11B DATASET v1.0 Category: Building a XML Parser ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct Node {
    char *name;
    struct Node *children;
} Node;

Node* parse_xml(const char* xml) {
    Node* root = NULL;
    Node* node = NULL;
    int i;

    // Initialize the root node
    root = malloc(sizeof(Node));
    root->name = strdup(xml);

    // Parse the XML string and build the tree
    for (i = 0; i < strlen(xml); i++) {
        if (xml[i] == '<') {
            char tag[100];
            strncpy(tag, xml+i+1, strlen(xml)-1-i-1);
            tag[strlen(xml)-1-i-1] = '\0';
            node = root;
            for (int j = 0; j < strlen(tag); j++) {
                if (tag[j] == '/') {
                    break;
                }
                node = &node->children;
            }
            if (node->name == NULL) {
                node->name = strdup(tag);
                node->children = malloc(sizeof(Node));
            } else {
                node->children = malloc(sizeof(Node));
                node->children->name = strdup(tag);
            }
        }
    }
    return root;
}

int main() {
    const char* xml = "<root><node><tag/></node></root>";
    Node* root = parse_xml(xml);
    if (root!= NULL) {
        printf("XML tree:\n");
        Node* node = root;
        while (node!= NULL) {
            printf("%s --> ", node->name);
            node = node->children;
        }
        printf("NULL\n");
        free(root);
    } else {
        printf("Failed to parse XML\n");
    }
    return 0;
}