//GEMINI-pro DATASET v1.0 Category: Building a XML Parser ; Style: shape shifting
#include <assert.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define NODE_SIZE 256

typedef struct Node Node;
struct Node {
    Node *parent;
    Node *child;
    Node *next;
    Node *prev;
    char *data;
    char *name;
    char *value;
};

Node *create_node(const char *name, const char *value, Node *parent) {
    Node *node = malloc(sizeof(Node));
    node->name = strdup(name);
    node->value = strdup(value);
    node->parent = parent;
    return node;
}

Node *parse_xml(const char *xml) {
    Node *root = create_node("root", "", NULL);
    Node *current = root;
    for (const char *p = xml; *p; p++) {
        switch (*p) {
        case '<':
            if (p[1] == '/') {
                p += 2;
                current = current->parent;
            } else {
                p++;
                char *name = strtok(strdup(p), " >");
                char *value = strtok(NULL, NULL);
                while (*value && isspace(*value)) value++;
                current = current->child = create_node(name, value, current);
            }
            break;
        case '/':
            if (p[1] == '>') {
                p += 2;
            } else {
                p++;
            }
            break;
        case '>':
            break;
        default:
            strcat(current->value, p);
        }
    }
    return root;
}

void print_xml(Node *node, int depth) {
    for (int i = 0; i < depth; i++) {
        printf("  ");
    }
    printf("- %s: %s\n", node->name, node->value);
    for (Node *child = node->child; child; child = child->next) {
        print_xml(child, depth+1);
    }
}

int main() {
    const char *xml = "<root>\n  <child1>hello</child1>\n  <child2>\n    <grandchild1>world</grandchild1>\n  </child2>\n</root>";
    Node *root = parse_xml(xml);
    print_xml(root, 0);
    return 0;
}