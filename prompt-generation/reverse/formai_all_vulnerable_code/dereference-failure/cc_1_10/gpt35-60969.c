//FormAI DATASET v1.0 Category: Building a XML Parser ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TAG_LEN 100
#define MAX_ATTRS 10
#define MAX_ATTR_LEN 50
#define MAX_DATA_LEN 100

struct xml_node {
    char tag[MAX_TAG_LEN];
    char attrs[MAX_ATTRS][MAX_ATTR_LEN];
    char data[MAX_DATA_LEN];
    struct xml_node *child;
    struct xml_node *next;
};

struct xml_node* parse_xml(char *filename);
void add_child(struct xml_node *parent, struct xml_node *child);
void add_sibling(struct xml_node *node, struct xml_node *sibling);
void print_xml(struct xml_node *node);
void free_xml(struct xml_node *node);

int main() {
    struct xml_node *root = parse_xml("example.xml");
    print_xml(root);
    free_xml(root);
    return 0;
}

struct xml_node* parse_xml(char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("Error: Could not open file %s\n", filename);
        return NULL;
    }

    struct xml_node *root = NULL;
    struct xml_node *current = NULL;
    char line[100];
    while (fgets(line, sizeof(line), file)) {
        if (strncmp(line, "<", 1) == 0) {
            struct xml_node *node = (struct xml_node*) malloc(sizeof(struct xml_node));
            char *tag_end = strchr(line, '>');
            if (tag_end) {
                int tag_len = tag_end - line - 1;
                strncpy(node->tag, line + 1, tag_len);
                node->tag[tag_len] = '\0';

                char *attr_start = line + tag_len + 2;
                char *attr_end = strchr(attr_start, '>');
                int attr_len = attr_end - attr_start;
                if (attr_len > 0) {
                    char attrs[MAX_ATTRS][MAX_ATTR_LEN];
                    int i = 0;
                    char *token = strtok(attr_start, " ");
                    while (token) {
                        if (i < MAX_ATTRS) {
                            strncpy(attrs[i], token, strlen(token));
                            attrs[i][strlen(token)] = '\0';
                            i++;
                        }
                        token = strtok(NULL, " ");
                    }
                    memcpy(node->attrs, attrs, sizeof(attrs));
                }

                char *data_start = tag_end + 1;
                char *data_end = strchr(line, '<');
                int data_len = data_end - data_start;
                if (data_len > 0) {
                    strncpy(node->data, data_start, data_len);
                    node->data[data_len] = '\0';
                }

                if (!root) {
                    root = node;
                    current = node;
                } else {
                    add_child(current, node);
                    current = node;
                }
            }
        } else if (strncmp(line, "</", 2) == 0) {
            if (current->child) {
                current = current->child;
            } else {
                while (current && current->next == NULL) {
                    current = current->child;
                }
                if (current) {
                    current = current->next;
                }
            }
        }
    }
    fclose(file);

    return root;
}

void add_child(struct xml_node *parent, struct xml_node *child) {
    parent->child = child;
}

void add_sibling(struct xml_node *node, struct xml_node *sibling) {
    node->next = sibling;
}

void print_xml(struct xml_node *node) {
    if (!node) {
        return;
    }

    printf("<%s", node->tag);
    for (int i = 0; i < MAX_ATTRS && node->attrs[i][0] != '\0'; i++) {
        printf(" %s", node->attrs[i]);
    }
    printf(">");

    if (node->data && strlen(node->data) > 0) {
        printf("%s", node->data);
    }

    if (node->child) {
        print_xml(node->child);
    }

    printf("</%s>", node->tag);

    if (node->next) {
        print_xml(node->next);
    }
}

void free_xml(struct xml_node *node) {
    if (!node) {
        return;
    }

    if (node->child) {
        free_xml(node->child);
    }

    if (node->next) {
        free_xml(node->next);
    }

    free(node);
}