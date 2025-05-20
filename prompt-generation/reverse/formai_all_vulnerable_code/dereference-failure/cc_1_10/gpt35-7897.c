//FormAI DATASET v1.0 Category: Building a XML Parser ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TAG_LEN  20
#define MAX_ATTRIB_LEN  20
#define MAX_ATTRIB_VAL 100

typedef struct _node {
    char* tag;
    char* attrib_name[MAX_ATTRIB_VAL];
    char* attrib_value[MAX_ATTRIB_VAL];
    int num_attribs;
    struct _node** children;
    int num_children;
} Node;

Node* createNode() {
    Node* root = (Node*)malloc(sizeof(Node));
    root->num_attribs = 0;
    root->num_children = 0;
    root->tag = NULL;
    root->children = NULL;
    return root;
}

void parse(Node* parent, char* xml) {
    char tag[MAX_TAG_LEN + 1];
    char attrib_name[MAX_ATTRIB_LEN + 1];
    char attrib_value[MAX_ATTRIB_VAL + 1];

    while (*xml) {
        if (*xml == '<') {
            xml++;
            int i = 0;
            while (*xml != '>' && *xml != ' ' && i < MAX_TAG_LEN) {
                tag[i++] = *xml++;
            }
            tag[i] = '\0';

            if (*xml == ' ') {
                parent->attrib_name[parent->num_attribs] = (char*)malloc(MAX_ATTRIB_LEN + 1);
                parent->attrib_value[parent->num_attribs] = (char*)malloc(MAX_ATTRIB_VAL + 1);

                while (*xml != '>') {
                    xml++;
                    i = 0;
                    while (*xml != '=' && i < MAX_ATTRIB_LEN) {
                        attrib_name[i++] = *xml++;
                    }
                    attrib_name[i] = '\0';

                    xml++;
                    if (*xml == '\"' || *xml == '\'') {
                        char delimiter = *xml;
                        xml++;
                        i = 0;
                        while (*xml != delimiter && i < MAX_ATTRIB_VAL) {
                            attrib_value[i++] = *xml++;
                        }
                        attrib_value[i] = '\0';

                        parent->attrib_name[parent->num_attribs] = strdup(attrib_name);
                        parent->attrib_value[parent->num_attribs] = strdup(attrib_value);
                        parent->num_attribs++;
                    }
                }
            }

            if (*xml == '>') {
                xml++;
                Node* child = createNode();
                child->tag = strdup(tag);
                parent->children = (Node**)realloc(parent->children, sizeof(Node*) * (parent->num_children + 1));
                parent->children[parent->num_children] = child;
                parent->num_children++;
                parse(child, xml);
            }
        } else {
            xml++;
        }
    }
}

void printNode(Node* node, int depth) {
    for (int i = 0; i < depth; i++) {
        printf("    ");
    }
    printf("<%s", node->tag);

    for (int i = 0; i < node->num_attribs; i++) {
        printf(" %s=\"%s\"", node->attrib_name[i], node->attrib_value[i]);
    }
    printf(">\n");

    for (int i = 0; i < node->num_children; i++) {
        printNode(node->children[i], depth + 1);
    }

    for (int i = 0; i < depth; i++) {
        printf("    ");
    }
    printf("</%s>\n", node->tag);
}

int main() {
    char xml[] = "<player class=\"cyborg\"><name first=\"john\" last=\"doe\"></name><level>5</level><weapon type=\"laser gun\">cyber weapon</weapon></player>";
    Node* root = createNode();
    parse(root, xml);
    printNode(root, 0);
    return 0;
}