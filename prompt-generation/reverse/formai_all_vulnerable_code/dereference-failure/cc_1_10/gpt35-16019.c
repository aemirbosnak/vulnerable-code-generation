//FormAI DATASET v1.0 Category: Building a XML Parser ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    char* tag;
    char* value;
    struct Node* children;
    struct Node* next;
};

struct Node* create_node(char* tag, char* value) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->tag = strdup(tag);
    node->value = strdup(value);
    node->children = NULL;
    node->next = NULL;
    return node;
}

void add_child(struct Node* parent, struct Node* child) {
    if (parent->children == NULL) {
        parent->children = child;
        return;
    }
    struct Node* curr = parent->children;
    while (curr->next != NULL) {
        curr = curr->next;
    }
    curr->next = child;
}

struct Node* parse_xml(char* xml_string) {
    struct Node* root = NULL;
    struct Node* curr = NULL;
    char* ptr = xml_string;
    while (*ptr != '\0') {
        if (*ptr == '<') {
            ptr++;
            int tag_start = ptr - xml_string;
            while (*ptr != '>') {
                ptr++;
            }
            int tag_end = ptr - xml_string;
            char tag[tag_end - tag_start + 1];
            memset(tag, 0, tag_end - tag_start + 1);
            strncpy(tag, xml_string + tag_start, tag_end - tag_start);

            ptr++;
            int value_start = ptr - xml_string;
            while (*ptr != '<' && *ptr != '\0') {
                ptr++;
            }
            int value_end = ptr - xml_string;
            char value[value_end - value_start + 1];
            memset(value, 0, value_end - value_start + 1);
            strncpy(value, xml_string + value_start, value_end - value_start);

            if (tag[0] == '/') {
                curr = curr->children;
            } else {
                struct Node* node = create_node(tag, value);
                if (root == NULL) {
                    root = node;
                    curr = node;
                } else {
                    add_child(curr, node);
                    curr = node;
                }
            }
        } else {
            ptr++;
        }
    }
    return root;
}

void print_xml(struct Node* node, int depth) {
    if (node == NULL) {
        return;
    }
    for (int i = 0; i < depth; i++) {
        printf("  ");
    }
    printf("<%s>", node->tag);
    if (node->value[0] != '\0') {
        printf("%s", node->value);
    }
    printf("\n");
    print_xml(node->children, depth + 1);
    for (int i = 0; i < depth; i++) {
        printf("  ");
    }
    printf("</%s>\n", node->tag);
    print_xml(node->next, depth);
}

int main() {
    char* xml_string = "<root><hello>world</hello><foo><bar>baz</bar></foo></root>";
    struct Node* root = parse_xml(xml_string);
    print_xml(root, 0);
    return 0;
}