//FormAI DATASET v1.0 Category: Building a XML Parser ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *name;
    char *value;
} attribute;

typedef struct {
    char *name;
    attribute *attributes;
    int num_attributes;
    char *content;
    struct node *children;
    struct node *next;
} node;

node *parse_xml(char *xml);
node *parse_node(char *xml, int *index);
attribute *parse_attributes(char *xml, int *index);
char *parse_content(char *xml, int *index);

int main() {
    char *xml = "<root><person name=\"John Doe\"><age>25</age><gender>male</gender></person></root>";
    node *root = parse_xml(xml);

    // print out the root node
    printf("Root Node: %s\n", root->name);

    // print out the first child node
    node *child = root->children;
    printf("Child Node: %s\n", child->name);

    // print out the child node's attributes
    attribute *attributes = child->attributes;
    for (int i = 0; i < child->num_attributes; i++) {
        printf("%s=%s\n", attributes[i].name, attributes[i].value);
    }

    // print out the child node's content
    printf("Content: %s\n", child->content);

    // print out the child node's children
    node *grandchild = child->children;
    printf("Grandchild Node: %s\n", grandchild->name);

    return 0;
}

// parses the entire xml string into a node structure
node *parse_xml(char *xml) {
    int index = 0;
    node *root = parse_node(xml, &index);
    return root;
}

// parses a single node from the xml string
node *parse_node(char *xml, int *index) {
    node *n = malloc(sizeof(node));
    n->name = parse_content(xml, index);
    n->attributes = parse_attributes(xml, index);
    n->num_attributes = 0;
    n->content = NULL;
    n->children = NULL;
    n->next = NULL;

    char c;
    while ((c = xml[*index]) != '\0') {
        if (c == '>') {
            (*index)++;
            break;
        } else if (c == '/') {
            (*index)++;
            if (xml[*index] == '>') {
                (*index)++;
                return n;
            }
        } else if (c == ' ') {
            (*index)++;
            n->attributes = parse_attributes(xml, index);
        } else {
            n->children = parse_node(xml, index);
            node *child = n->children;
            while (child) {
                n->num_attributes += child->num_attributes;
                child = child->next;
            }
        }
    }

    n->content = parse_content(xml, index);

    while ((c = xml[*index]) != '\0') {
        if (c == '<' && xml[*index + 1] == '/') {
            break;
        } else if (c == '<') {
            node *child = parse_node(xml, index);
            if (n->children == NULL) {
                n->children = child;
            } else {
                node *prev = n->children;
                while (prev->next) {
                    prev = prev->next;
                }
                prev->next = child;
            }
        } else {
            (*index)++;
        }
    }

    if (xml[*index] == '<') {
        (*index) += 2;
        char *end_name = parse_content(xml, index);
        if (strcmp(n->name, end_name) != 0) {
            printf("Error: opening and closing tags do not match\n");
            exit(1);
        }
    }

    return n;
}

// parses a list of attributes from the xml string
attribute *parse_attributes(char *xml, int *index) {
    attribute *attributes = malloc(sizeof(attribute) * 10);
    int num_attributes = 0;

    char c;
    while ((c = xml[*index]) != '\0') {
        if (c == '>') {
            (*index)++;
            break;
        } else if (c == '/') {
            (*index)++;
            if (xml[*index] == '>') {
                (*index)++;
                return attributes;
            }
        } else if (c != ' ') {
            char *name = parse_content(xml, index);
            if (xml[*index] == '=') {
                (*index)++;
                char *value = parse_content(xml, index);
                attributes[num_attributes].name = name;
                attributes[num_attributes].value = value;
                num_attributes++;
            }
        } else {
            (*index)++;
        }
    }

    attribute *final_attributes = malloc(sizeof(attribute) * num_attributes);
    memcpy(final_attributes, attributes, sizeof(attribute) * num_attributes);

    free(attributes);

    return final_attributes;
}

// parses content from the xml string
char *parse_content(char *xml, int *index) {
    char *p = xml + (*index);
    char *start = strstr(p, "<");
    if (start) {
        int length = start - p;
        char *content = malloc(length + 1);
        memcpy(content, p, length);
        content[length] = '\0';
        *index += length;
        return content;
    } else {
        return NULL;
    }
}