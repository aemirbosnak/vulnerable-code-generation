//FormAI DATASET v1.0 Category: Building a XML Parser ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TAG_SIZE 100    // Maximum size of a tag
#define MAX_ATTR_SIZE 100   // Maximum number of attributes for a tag

struct attribute {
    char key[MAX_ATTR_SIZE];
    char value[MAX_ATTR_SIZE];
};
typedef struct attribute Attribute;

struct node {
    char name[MAX_TAG_SIZE];
    Attribute attrs[MAX_ATTR_SIZE];
    int attr_count;
    struct node *children;
};
typedef struct node Node;

Node* create_node(char* name) {
    Node* node = malloc(sizeof(Node));
    strcpy(node->name, name);
    node->attr_count = 0;
    node->children = NULL;
    return node;
}

void add_attribute(Node* node, char* key, char* value) {
    if (node->attr_count < MAX_ATTR_SIZE) {
        strcpy(node->attrs[node->attr_count].key, key);
        strcpy(node->attrs[node->attr_count].value, value);
        node->attr_count++;
    }
}

void add_child(Node* parent, Node* child) {
    if (parent->children == NULL) {
        parent->children = child;
    } else {
        Node* current = parent->children;
        while (current->children != NULL) {
            current = current->children;
        }
        current->children = child;
    }
}

Node* parse_xml(char* xml) {
    Node* root = NULL;
    Node* current = NULL;
    int i = 0;

    while (xml[i] != '\0') {
        if (xml[i] == '<' && xml[i+1] != '/') {
            // Tag opening
            char tag[MAX_TAG_SIZE];
            int j = 0;
            i++;

            while (xml[i] != '>' && xml[i] != ' ') {
                tag[j] = xml[i];
                j++;
                i++;
            }
            tag[j] = '\0';

            Node* node = create_node(tag);

            while (xml[i] != '>') {
                // Attributes
                if (xml[i] == ' ') {
                    i++;
                    char key[MAX_ATTR_SIZE];
                    char value[MAX_ATTR_SIZE];
                    int k = 0;

                    while (xml[i] != '=') {
                        key[k] = xml[i];
                        k++;
                        i++;
                    }
                    key[k] = '\0';
                    i++;

                    if (xml[i] == '\"') {
                        i++;
                        k = 0;

                        while (xml[i] != '\"') {
                            value[k] = xml[i];
                            k++;
                            i++;
                        }
                        value[k] = '\0';
                        add_attribute(node, key, value);
                        i++; 
                    }
                } else {
                    i++;
                }
            }

            if (current == NULL) {
                root = node;
                current = node;
            } else {
                add_child(current, node);
                current = node;
            }
        } else if (xml[i] == '<' && xml[i+1] == '/') {
            // Tag closing
            int j = i+2;
            char tag[MAX_TAG_SIZE];
            int k = 0;

            while (xml[j] != '>') {
                tag[k] = xml[j];
                k++;
                j++;
            }
            tag[k] = '\0';

            if (strcmp(current->name, tag) == 0) {
                current = current->children;
            } else {
                printf("Error: tag not closed properly\n");
                return NULL;
            }
            i = j;
        } else {
            i++;
        }
    }

    return root;
}

void print_node(Node* node, int depth) {
    for (int i=0; i<depth; i++) {
        printf("  ");
    }
    printf("<%s", node->name);
    for (int i=0; i<node->attr_count; i++) {
        printf(" %s=\"%s\"", node->attrs[i].key, node->attrs[i].value);
    }
    printf(">\n");
    if (node->children != NULL) {
        print_node(node->children, depth+1);
    }
    for (int i=0; i<depth; i++) {
        printf("  ");
    }
    printf("</%s>\n", node->name);
    if (node->children != NULL && node->children->children != NULL) {
        print_node(node->children->children, depth);
    }
}

int main() {
    char xml[] = "<bookstore><book category=\"cooking\"><title lang=\"en\">Everyday Italian</title><author>Giada De Laurentiis</author><year>2005</year><price>30.00</price></book><book category=\"children\"><title lang=\"en\">Harry Potter</title><author>J.K. Rowling</author><year>2005</year><price>29.99</price></book><book category=\"web\"><title lang=\"en\">Learning XML</title><author>Erik T. Ray</author><year>2003</year><price>39.95</price></book></bookstore>";
    Node* root = parse_xml(xml);

    if (root == NULL) {
        return 1;
    }

    print_node(root, 0);

    return 0;
}