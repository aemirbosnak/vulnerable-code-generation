//FormAI DATASET v1.0 Category: Building a XML Parser ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TAG_LEN 100

typedef struct node {
    char tag[MAX_TAG_LEN];
    struct node *parent;
    struct node *children;
    struct node *next;
} Node;

Node *root = NULL;
Node *current = NULL;

void parse_start_tag(char *tag) {
    Node *node = malloc(sizeof(Node));
    strncpy(node->tag, tag, MAX_TAG_LEN - 1);
    node->parent = current;
    node->children = NULL;
    node->next = NULL;
    
    if (root == NULL) {
        root = node;
    } else {
        current->children = node;
    }
    
    current = node;
}

void parse_end_tag(char *tag) {
    if (strcmp(current->tag, tag) != 0) {
        fprintf(stderr, "Error: expected end tag '%s', got '%s'\n", current->tag, tag);
        exit(1);
    }
    
    current = current->parent;
}

void parse_text(char *text) {
    //TODO: handle text nodes
}

void parse_xml(char *xml) {
    char *p = xml;
    char tag[MAX_TAG_LEN];
    int tag_start = 0;
    int in_tag = 0;
    
    while (*p != '\0') {
        if (*p == '<') {
            in_tag = 1;
            tag_start = 1;
            p++;
        } else if (*p == '>') {
            in_tag = 0;
            if (tag_start) {
                tag[tag_start - 1] = '\0';
                if (tag[0] == '/') {
                    parse_end_tag(tag + 1);
                } else {
                    parse_start_tag(tag);
                }
                tag_start = 0;
            }
            p++;
        } else if (in_tag) {
            tag[tag_start - 1] = *p;
            tag_start++;
            p++;
        } else {
            //TODO: handle text nodes
            p++;
        }
    }
}

int main() {
    char *xml = "<html><head><title>My Page</title></head><body><div id=\"content\">Hello, world!</div></body></html>";
    
    parse_xml(xml);
    
    //TODO: traverse DOM tree
}