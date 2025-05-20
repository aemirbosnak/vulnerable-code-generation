//GEMINI-pro DATASET v1.0 Category: Building a XML Parser ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* XML Parser */
typedef enum {
    DOC,
    ELEM,
    ATTR,
    TEXT,
    END
} XML_Type;

typedef struct {
    char *name;
    XML_Type type;
    struct XML_Node *parent;
    struct XML_Node *child;
    struct XML_Node *next;
} XML_Node;

XML_Node *XML_Parse(const char *str, XML_Node **root) {
    XML_Node *node, *cur;
    const char *p;
    int state = DOC;

    *root = malloc(sizeof(XML_Node));
    node = *root;

    for (p = str; *p; p++) {
        switch (state) {
        case DOC:
            if (*p == '<') {
                state = ELEM;
                cur = node;
            }
            break;
        case ELEM:
            if (*p == '>') {
                state = TEXT;
            } else if (*p == '/') {
                state = END;
            } else if (*p != ' ') {
                node = malloc(sizeof(XML_Node));
                node->type = ELEM;
                node->name = strdup(p);
                node->child = NULL;
                node->parent = cur;
                cur->next = node;
                cur = node;
            }
            break;
        case ATTR:
            if (*p == '"') {
                state = ELEM;
            }
            break;
        case TEXT:
            if (*p == '<') {
                state = ELEM;
            }
            break;
        case END:
            if (*p == '>') {
                state = TEXT;
                cur = cur->parent;
            }
            break;
        }
    }

    return (*root);
}

void XML_Print(XML_Node *node, int level) {
    int i;

    for (i = 0; i < level; i++) {
        printf("  ");
    }

    switch (node->type) {
    case DOC:
        printf("Document\n");
        break;
    case ELEM:
        printf("%s\n", node->name);
        break;
    case ATTR:
        printf("%s=\"%s\"\n", node->name, node->name);
        break;
    case TEXT:
        printf("%s\n", node->name);
        break;
    case END:
        printf("</%s>\n", node->name);
        break;
    }

    if (node->child) {
        XML_Print(node->child, level + 1);
    }

    if (node->next) {
        XML_Print(node->next, level);
    }
}

int main(int argc, char *argv[]) {
    XML_Node *root;

    if (argc < 2) {
        fprintf(stderr, "Usage: %s filename\n", argv[0]);
        return 1;
    }

    if (!XML_Parse(argv[1], &root)) {
        fprintf(stderr, "Error parsing XML file\n");
        return 1;
    }

    XML_Print(root, 0);

    return 0;
}