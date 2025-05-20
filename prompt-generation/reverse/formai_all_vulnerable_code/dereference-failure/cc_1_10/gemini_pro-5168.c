//GEMINI-pro DATASET v1.0 Category: Building a XML Parser ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *name;
    char *value;
    struct xml_node *parent;
    struct xml_node *children;
    struct xml_node *next;
} xml_node;

xml_node *xml_parse(char *str) {
    xml_node *root = NULL;
    xml_node *current = NULL;
    char *start = str;
    char *end = NULL;
    while (*str != '\0') {
        if (*str == '<') {
            if (*(str + 1) == '/') {
                str += 2;
                while (*str != '>') str++;
                if (current != NULL) current = current->parent;
            } else {
                start = str + 1;
                while (*str != '>') str++;
                end = str;
                char *name = malloc(end - start + 1);
                strncpy(name, start, end - start);
                name[end - start] = '\0';
                xml_node *node = malloc(sizeof(xml_node));
                node->name = name;
                node->value = NULL;
                node->parent = current;
                node->children = NULL;
                node->next = NULL;
                if (root == NULL) root = node;
                if (current != NULL) current->children = node;
                current = node;
            }
        } else if (*str == '=') {
            start = str + 1;
            while (*str != '"') str++;
            end = str;
            char *value = malloc(end - start + 1);
            strncpy(value, start, end - start);
            value[end - start] = '\0';
            current->value = value;
        }
        str++;
    }
    return root;
}

void xml_print(xml_node *node) {
    if (node == NULL) return;
    printf("<%s", node->name);
    if (node->value != NULL) printf("=\"%s\"", node->value);
    printf(">");
    xml_print(node->children);
    printf("</%s>", node->name);
}

int main() {
    char *str = "<root><child1 value=\"hello\"/><child2><grandchild1 value=\"world\"/><grandchild2/></child2></root>";
    xml_node *root = xml_parse(str);
    xml_print(root);
    return 0;
}