//MISTRAL-7B DATASET v1.0 Category: Resume Parsing System ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct Node {
    char *name;
    int type;
    struct Node *next;
    struct Node *children;
} Node;

void print_node(Node *node);
Node *parse_node(char **str);

int main(int argc, char *argv[]) {
    char *input = argv[1];
    Node *root = NULL;

    while (*input != '\0') {
        Node *temp = parse_node(&input);

        if (temp != NULL) {
            if (root == NULL) {
                root = temp;
            } else {
                Node *current = root;

                while (current->next != NULL) {
                    current = current->next;
                }

                current->next = temp;
            }
        }
    }

    print_node(root);

    return 0;
}

Node *parse_node(char **str) {
    char *name_start = *str;
    char *name_end;

    int name_length = 0;

    while (**str != '{' && **str != '\0') {
        if (**str == ' ') {
            *str += 1;
            continue;
        }

        if (**str == ':') {
            **str += 1;
            break;
        }

        name_length++;
        *str += 1;
    }

    name_end = *str;
    *str += 1;

    Node *node = (Node *)malloc(sizeof(Node));

    node->name = malloc(name_length + 1);
    strncpy(node->name, name_start, name_length);
    node->name[name_length] = '\0';

    node->type = (*(*str) == '{' ? 1 : 0);

    if (node->type) {
        node->children = parse_node(str);
    } else {
        node->children = NULL;
    }

    node->next = NULL;

    return node;
}

void print_node(Node *node) {
    if (node == NULL) {
        return;
    }

    printf("%s: ", node->name);

    if (node->type) {
        print_node(node->children);
    } else {
        printf("Leaf\n");
    }
}