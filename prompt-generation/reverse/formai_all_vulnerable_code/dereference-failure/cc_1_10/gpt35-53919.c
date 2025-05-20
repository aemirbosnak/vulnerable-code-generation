//FormAI DATASET v1.0 Category: Building a XML Parser ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    char* name;
    char* content;
    int n_child;
    struct Node** children;
};

typedef struct Node* NodePtr;

NodePtr create_node(char* name, int n_child) {
    NodePtr node = (NodePtr) malloc(sizeof(struct Node));
    node->name = (char*) malloc(strlen(name) + 1);
    strcpy(node->name, name);
    node->content = NULL;
    node->n_child = n_child;
    node->children = (NodePtr*) malloc(n_child * sizeof(NodePtr));
    for (int i = 0; i < n_child; i++) {
        node->children[i] = NULL;
    }
    return node;
}

void set_content(NodePtr node, char* content) {
    node->content = (char*) malloc(strlen(content) + 1);
    strcpy(node->content, content);
}

void add_child(NodePtr parent, NodePtr child) {
    for (int i = 0; i < parent->n_child; i++) {
        if (parent->children[i] == NULL) {
            parent->children[i] = child;
            break;
        }
    }
}

NodePtr parse_xml(char* xml) {
    NodePtr root = NULL;
    char* name = NULL;
    char* content = NULL;
    int n_child = 0;
    NodePtr node = NULL;
    NodePtr parent = NULL;
    int i = 0;
    while (xml[i] != '\0') {
        if (xml[i] == '<') {
            i++;
            if (xml[i] == '/') {
                i++;
                parent = node;
                node = NULL;
                while (xml[i] != '>') {
                    i++;
                }
                i++;
            } else {
                name = (char*) malloc(20 * sizeof(char));
                int j = 0;
                while (xml[i] != ' ' && xml[i] != '>') {
                    name[j] = xml[i];
                    j++;
                    i++;
                }
                name[j] = '\0';
                node = create_node(name, 10);
                free(name);
                if (root == NULL) {
                    root = node;
                } else if (parent != NULL) {
                    add_child(parent, node);
                }
                parent = node;
                n_child = 0;
                while (xml[i] != '>') {
                    i++;
                    if (xml[i] == '/') {
                        i++;
                        break;
                    } else if (xml[i] == ' ') {
                        i++;
                        continue;
                    } else {
                        name = (char*) malloc(20 * sizeof(char));
                        int j = 0;
                        while (xml[i] != ' ' && xml[i] != '=') {
                            name[j] = xml[i];
                            j++;
                            i++;
                        }
                        name[j] = '\0';
                        while (xml[i] != '\"') {
                            i++;
                        }
                        i++;
                        content = (char*) malloc(100 * sizeof(char));
                        int k = 0;
                        while (xml[i] != '\"') {
                            content[k] = xml[i];
                            k++;
                            i++;
                        }
                        content[k] = '\0';
                        set_content(node, content);
                        free(name);
                        free(content);
                        n_child++;
                    }
                }
                if (xml[i] != '/') {
                    i++;
                }
                node->n_child = n_child;
            }
        }
    }
    return root;
}

void print_tree(NodePtr node, int level) {
    if (node == NULL) {
        return;
    }
    for (int i = 0; i < level; i++) {
        printf(" ");
    }
    printf("%s: %s\n", node->name, node->content);
    for (int i = 0; i < node->n_child; i++) {
        print_tree(node->children[i], level + 1);
    }
}

int main() {
    char* xml = "<root><person age=\"30\" gender=\"male\">John Doe</person><person age=\"25\" gender=\"female\">Jane Smith</person></root>";
    NodePtr root = parse_xml(xml);
    print_tree(root, 0);
    return 0;
}