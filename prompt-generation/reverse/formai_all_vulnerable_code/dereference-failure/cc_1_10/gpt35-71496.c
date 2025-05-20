//FormAI DATASET v1.0 Category: Building a XML Parser ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    char tag[50];
    char text[50];
    struct node* child;
    struct node* sibling;
} node;

node* parse_xml(char* xml) {
    node* root = (node*)malloc(sizeof(node));
    node* curr = root;
    char* ptr = xml;
    while (*ptr) {
        if (*ptr == '<') {
            char* tag_start = ptr + 1;
            char* tag_end = strchr(tag_start, '>');
            char* text_start = tag_end + 1;
            char* text_end = strstr(text_start, "<");
            if (tag_start[0] == '/') {
                curr = curr->child;
            } else {
                node* new_node = (node*)malloc(sizeof(node));
                strncpy(new_node->tag, tag_start, tag_end - tag_start);
                new_node->child = NULL;
                new_node->sibling = NULL;
                if (root == curr) {
                    root = new_node;
                    curr = new_node;
                } else if (curr->child == NULL) {
                    curr->child = new_node;
                    curr = new_node;
                } else {
                    curr = curr->child;
                    while (curr->sibling != NULL) {
                        curr = curr->sibling;
                    }
                    curr->sibling = new_node;
                    curr = new_node;
                }
                if (text_end - text_start > 0) {
                    strncpy(curr->text, text_start, text_end - text_start);
                }
            }
            ptr = text_end;
        }
        ptr++;
    }
    return root;
}

void print_tree(node* tree) {
    while (tree != NULL) {
        printf("%s: %s\n", tree->tag, tree->text);
        print_tree(tree->child);
        tree = tree->sibling;
    }
}

int main() {
    char* xml = "<root><person><name>John<\/name><age>30<\/age><\/person><person><name>Jane<\/name><age>25<\/age><\/person><\/root>";
    node* root = parse_xml(xml);
    print_tree(root);
    return 0;
}