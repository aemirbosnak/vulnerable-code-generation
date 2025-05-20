//FormAI DATASET v1.0 Category: Building a XML Parser ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct xml_node xml_node;
struct xml_node {
    char *tag_name;
    char *content;
    xml_node *child;
    xml_node *sibling;
};

xml_node *parse_xml(char *xml_string);
void print_tree(xml_node *root, int lvl);

int main() {
    char test_xml[] = "<document>\n"
                      "  <title>Example document</title>\n"
                      "  <body>\n"
                      "    <paragraph>Some text here</paragraph>\n"
                      "    <paragraph>More text here</paragraph>\n"
                      "  </body>\n"
                      "</document>";

    xml_node *root = parse_xml(test_xml);
    printf("Parsed XML:\n");
    print_tree(root, 0);

    return 0;
}

xml_node *parse_xml(char *xml_string) {
    xml_node *root = NULL;
    xml_node *prev = NULL;
    xml_node *curr = NULL;
    char *token = NULL;
    char *tag_name = NULL;
    char *content = NULL;
    char *saveptr = NULL;
    int in_tag = 0;
    int in_content = 0;

    token = strtok_r(xml_string, "<>", &saveptr);

    while (token != NULL) {
        if (in_tag) {
            if (token[0] == '/') {
                in_tag = 0;
                curr->content = content;
                content = NULL;
                if (prev != NULL) {
                    prev->sibling = curr;
                } else {
                    root = curr;
                }
                prev = curr;
                curr = NULL;
            } else {
                in_content = 1;
                if (curr == NULL) {
                    curr = malloc(sizeof(xml_node));
                    curr->tag_name = strdup(token);
                    curr->sibling = NULL;
                    curr->child = NULL;
                } else {
                    xml_node *new_node = malloc(sizeof(xml_node));
                    new_node->tag_name = strdup(token);
                    new_node->child = NULL;
                    new_node->sibling = NULL;
                    curr->child = new_node;
                    curr = new_node;
                }
            }
        } else {
            if (in_content) {
                content = strdup(token);
                in_content = 0;
            } else {
                tag_name = strdup(token);
                in_tag = 1;
            }
        }

        token = strtok_r(NULL, "<>", &saveptr);
    }

    return root;
}

void print_tree(xml_node *root, int lvl) {
    if (root == NULL) {
        return;
    }

    for (int i = 0; i < lvl; i++) {
        putchar(' ');
    }

    printf("<%s>", root->tag_name);
    if (root->content != NULL) {
        printf("%s", root->content);
    }
    putchar('\n');

    print_tree(root->child, lvl + 1);

    print_tree(root->sibling, lvl);
}