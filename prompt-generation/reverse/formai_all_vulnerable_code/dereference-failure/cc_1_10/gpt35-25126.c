//FormAI DATASET v1.0 Category: Building a XML Parser ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char *name;
    char *value;
    struct Node *parent;
    struct Node *next;
    struct Node *child;
} Node;

int parse_xml(char *xml, Node **root);
Node *new_node(char *name, Node *parent);
void add_attribute(Node *node, char *name, char *value);
void add_child(Node *parent, Node *child);
void free_tree(Node *root);
void print_tree(Node *root);

int main() {
    char *xml = "<root>\n"
                "   <child name=\"foo\">bar</child>\n"
                "   <child>baz</child>\n"
                "</root>\n";

    Node *root = NULL;
    int res = parse_xml(xml, &root);
    if (res == 0) {
        print_tree(root);
        free_tree(root);
    } else {
        printf("Error parsing XML: %d", res);
    }

    return 0;
}

int parse_xml(char *xml, Node **root) {
    char *tmp;
    Node *curr_node = NULL;

    while (*xml) {
        switch (*xml) {
            case '<':
                if (*(xml + 1) == '/') {
                    // end tag
                    tmp = strchr(xml, '>');
                    if (tmp == NULL) return 1; // malformed XML
                    *tmp = '\0';

                    if (curr_node == NULL) return 2; // no matching start tag
                    if (strcmp(xml+2, curr_node->name) != 0) return 3; // start and end tags don't match

                    curr_node = curr_node->parent;
                    xml = tmp + 1;
                } else {
                    // start tag
                    tmp = strchr(xml, '>');
                    if (tmp == NULL) return 1; // malformed XML
                    *tmp = '\0';

                    char *name = xml + 1;
                    Node *node = new_node(name, curr_node);
                    if (curr_node != NULL) {
                        add_child(curr_node, node);
                    } else {
                        *root = node;
                    }
                    curr_node = node;

                    // parse attributes
                    char *attr = name + strlen(name) + 1;
                    while (*attr) {
                        if (*attr == '/') {
                            curr_node = curr_node->parent;
                            break;
                        }
                        char *attr_name = attr;
                        char *attr_value = strchr(attr, '=');
                        if (attr_value == NULL) {
                            return 1; // malformed XML
                        }
                        *attr_value = '\0';
                        attr_value += 2; // skip the '=' and the opening quote
                        char *attr_value_end = strchr(attr_value, '\"');
                        if (attr_value_end == NULL) {
                            return 1; // malformed XML
                        }
                        *attr_value_end = '\0';
                        add_attribute(curr_node, attr_name, attr_value);
                        attr = attr_value_end + 2; // skip the closing quote and the space
                    }

                    xml = tmp + 1;
                }
                break;
            case '\n':
            case ' ':
            case '\t':
                // ignore whitespace
                xml++;
                break;
            default:
                // text
                tmp = strchr(xml, '<');
                if (tmp == NULL) {
                    return 1; // malformed XML
                }
                *tmp = '\0';

                Node *node = new_node("", curr_node);
                node->value = strdup(xml);
                add_child(curr_node, node);

                xml = tmp;
                break;
        }
    }

    return 0;
}

Node *new_node(char *name, Node *parent) {
    Node *node = malloc(sizeof(Node));
    node->name = strdup(name);
    node->value = NULL;
    node->parent = parent;
    node->next = NULL;
    node->child = NULL;
    return node;
}

void add_attribute(Node *node, char *name, char *value) {
    // not implemented in this example
}

void add_child(Node *parent, Node *child) {
    if (parent->child == NULL) {
        parent->child = child;
    } else {
        Node *curr = parent->child;
        while (curr->next != NULL) {
            curr = curr->next;
        }
        curr->next = child;
    }
}

void free_tree(Node *root) {
    if (root == NULL) return;
    Node *curr = root->child;
    while (curr != NULL) {
        Node *next = curr->next;
        free_tree(curr);
        curr = next;
    }
    free(root->name);
    free(root->value);
    free(root);
}

void print_tree(Node *root) {
    if (root == NULL) return;
    printf("<%s", root->name);
    Node *attr = root->child;
    while (attr != NULL) {
        printf(" %s=\"%s\"", attr->name, attr->value);
        attr = attr->next;
    }
    printf(">");
    if (root->value != NULL) printf("%s", root->value);
    Node *child = root->child;
    while (child != NULL) {
        if (child->value == NULL) printf("\n");
        print_tree(child);
        child = child->next;
    }
    printf("</%s>\n", root->name);
}