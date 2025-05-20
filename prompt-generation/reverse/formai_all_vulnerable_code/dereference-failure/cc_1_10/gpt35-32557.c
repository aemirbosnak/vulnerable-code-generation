//FormAI DATASET v1.0 Category: Building a XML Parser ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    char* tag_name;
    char* content;
    int content_length;
    struct Node** children;
    int num_children;
};

void parse_xml(char* xml_string, struct Node* root);
void print_xml(struct Node* node, int depth);

int main() {
    char example_xml[] = "<root><person><name>John</name><age>30</age></person><person><name>Jane</name><age>25</age></person></root>";
    struct Node root;
    parse_xml(example_xml, &root);
    print_xml(&root, 0);
    return 0;
}

void parse_xml(char* xml_string, struct Node* root) {
    // TODO: Implement XML parsing logic
}

void print_xml(struct Node* node, int depth) {
    // Print start tag
    for (int i = 0; i < depth; i++) {
        printf("  ");
    }
    printf("<%s>", node->tag_name);

    // Print content
    if (node->content_length > 0) {
        printf("%s", node->content);
    }

    // Print children
    for (int i = 0; i < node->num_children; i++) {
        printf("\n");
        print_xml(node->children[i], depth+1);
    }

    // Print end tag
    if (node->num_children > 0) {
        printf("\n");
        for (int i = 0; i < depth; i++) {
            printf("  ");
        }
    }
    printf("</%s>\n", node->tag_name);
}