//GEMINI-pro DATASET v1.0 Category: Building a XML Parser ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TAGS 100
#define MAX_TAG_LEN 256

typedef struct {
    char *name;
    int num_children;
    struct tag *children[MAX_TAGS];
    char *value;
} tag;

tag *parse_xml(char *xml) {
    tag *root = malloc(sizeof(tag));
    root->name = strtok(xml, "<>");
    root->num_children = 0;

    while (1) {
        char *tag_name = strtok(NULL, "<>");
        if (tag_name == NULL) break;

        if (tag_name[0] == '/') {
            return root;
        } else {
            tag *child = parse_xml(tag_name);
            root->children[root->num_children++] = child;
        }
    }

    root->value = strtok(NULL, "<>");
    return root;
}

void print_xml(tag *root, int indent) {
    for (int i = 0; i < indent; i++) printf("  ");
    printf("<%s", root->name);

    if (root->value != NULL) {
        printf(">%s", root->value);
    } else {
        printf(">\n");
        for (int i = 0; i < root->num_children; i++) {
            print_xml(root->children[i], indent + 1);
        }
        for (int i = 0; i < indent; i++) printf("  ");
        printf("</%s>\n", root->name);
    }
}

int main() {
    char *xml = "<root><child1>This is child 1</child1><child2>This is child 2</child2></root>";
    tag *root = parse_xml(xml);
    print_xml(root, 0);
    return 0;
}