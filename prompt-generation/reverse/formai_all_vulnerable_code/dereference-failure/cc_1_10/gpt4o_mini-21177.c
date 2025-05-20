//GPT-4o-mini DATASET v1.0 Category: Building a XML Parser ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char *tag;
    char *content;
    struct Node **children;
    int child_count;
} Node;

Node* create_node(const char *tag, const char *content) {
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->tag = strdup(tag);
    new_node->content = strdup(content);
    new_node->children = NULL;
    new_node->child_count = 0;
    return new_node;
}

void add_child(Node *parent, Node *child) {
    parent->child_count++;
    parent->children = (Node **)realloc(parent->children, sizeof(Node *) * parent->child_count);
    parent->children[parent->child_count - 1] = child;
}

void free_node(Node *node) {
    if (node) {
        free(node->tag);
        free(node->content);
        for (int i = 0; i < node->child_count; i++) {
            free_node(node->children[i]);
        }
        free(node->children);
        free(node);
    }
}

void print_node(Node *node, int depth) {
    for (int i = 0; i < depth; i++) {
        printf("  ");
    }
    printf("<%s>", node->tag);
    if (node->content && strlen(node->content) > 0) {
        printf("%s", node->content);
    }
    printf("\n");
    for (int i = 0; i < node->child_count; i++) {
        print_node(node->children[i], depth + 1);
    }
    for (int i = 0; i < depth; i++) {
        printf("  ");
    }
    printf("</%s>\n", node->tag);
}

Node* parse_xml(const char *xml) {
    Node *root = create_node("root", "");
    char *current_tag = NULL;
    char *current_content = NULL;
    Node *current_node = root;

    const char *ptr = xml;
    while (*ptr) {
        if (*ptr == '<') {
            if (*(ptr + 1) == '/') {
                // closing tag
                if (current_tag) {
                    free(current_tag);
                    current_tag = NULL;
                }
                if (current_node) {
                    current_node = root;  // back to root
                }
                while (*ptr && *ptr != '>') ptr++;
                if (*ptr) ptr++;  // skip '>'
            } else {
                // opening tag
                char *end_tag = strchr(ptr, '>');
                if (end_tag) {
                    size_t tag_len = end_tag - (ptr + 1);
                    current_tag = (char *)malloc(tag_len + 1);
                    strncpy(current_tag, ptr + 1, tag_len);
                    current_tag[tag_len] = '\0';
                    current_content = NULL;
                    Node *new_node = create_node(current_tag, current_content);
                    add_child(current_node, new_node);
                    current_node = new_node;
                    ptr = end_tag + 1;  // move past '>'
                } else {
                    break;
                }
            }
        } else {
            // handle content
            const char *content_start = ptr;
            while (*ptr && *ptr != '<') ptr++;
            size_t content_len = ptr - content_start;
            if (current_node && content_len > 0) {
                current_node->content = (char *)realloc(current_node->content, strlen(current_node->content) + content_len + 1);
                strncat(current_node->content, content_start, content_len);
                current_node->content[strlen(current_node->content) + content_len] = '\0';
            }
        }
    }
    
    if (current_tag) free(current_tag);
    return root;
}

int main() {
    const char *xml_data =
        "<note>\n"
        "    <to>Tove</to>\n"
        "    <from>Jani</from>\n"
        "    <heading>Reminder</heading>\n"
        "    <body>Don't forget me this weekend!</body>\n"
        "</note>";

    Node *parsed_xml = parse_xml(xml_data);
    print_node(parsed_xml, 0);

    free_node(parsed_xml);
    return 0;
}