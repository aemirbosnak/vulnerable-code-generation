//FormAI DATASET v1.0 Category: Building a XML Parser ; Style: interoperable
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* A simple XML node structure */
typedef struct xml_node {
    struct xml_node* parent;
    struct xml_node* first_child;
    struct xml_node* next_sibling;
    char* name;
    char* value;
} xml_node;

/* A struct to hold our XML parser state */
typedef struct xml_parser {
    xml_node* root;
    xml_node* current;
    char* buffer;
    int buffer_len;
    int buffer_pos;
} xml_parser;

/* Create a new XML node */
xml_node* xml_node_create(xml_node* parent, char* name, char* value) {
    xml_node* node = (xml_node*) malloc(sizeof(xml_node));
    node->parent = parent;
    node->first_child = NULL;
    node->next_sibling = NULL;
    node->name = strdup(name);
    node->value = strdup(value);
    return node;
}

/* Create a new XML parser */
xml_parser* xml_parser_create() {
    xml_parser* parser = (xml_parser*) malloc(sizeof(xml_parser));
    parser->root = NULL;
    parser->current = NULL;
    parser->buffer = NULL;
    parser->buffer_len = 0;
    parser->buffer_pos = 0;
    return parser;
}

/* Destroy an XML node */
void xml_node_destroy(xml_node* node) {
    if (!node) {
        return;
    }
    xml_node_destroy(node->first_child);
    xml_node_destroy(node->next_sibling);
    free(node->name);
    free(node->value);
    free(node);
}

/* Destroy an XML parser */
void xml_parser_destroy(xml_parser* parser) {
    xml_node_destroy(parser->root);
    free(parser->buffer);
    free(parser);
}

/* Append a character to the buffer */
void xml_parser_append_char(xml_parser* parser, char c) {
    /* If the buffer is full, double its size */
    if (parser->buffer_pos >= parser->buffer_len) {
        parser->buffer_len = parser->buffer_len ? parser->buffer_len * 2 : 1024;
        parser->buffer = (char*) realloc(parser->buffer, parser->buffer_len * sizeof(char));
    }
    /* Append the character to the buffer */
    parser->buffer[parser->buffer_pos++] = c;
}

/* Parse an XML document */
xml_parser* xml_parse(char* xml) {
    xml_parser* parser = xml_parser_create();
    char* p = xml;
    while (*p) {
        /* If we are inside a tag */
        if (parser->current) {
            /* If we see the end of the tag */
            if (*p == '>') {
                xml_parser_append_char(parser, '\0');
                /* If this is an opening tag */
                if (parser->current->name[0] != '/') {
                    /* Create a new child node */
                    xml_node* node = xml_node_create(parser->current, parser->buffer, "");
                    /* Link it to its parent and siblings */
                    if (parser->current->first_child) {
                        xml_node* sibling = parser->current->first_child;
                        while (sibling->next_sibling) {
                            sibling = sibling->next_sibling;
                        }
                        sibling->next_sibling = node;
                    } else {
                        parser->current->first_child = node;
                    }
                    /* Make the new node the current node */
                    parser->current = node;
                /* If this is a closing tag */
                } else {
                    /* If this is the end of the root node */
                    if (!parser->current->parent) {
                        break;
                    }
                    /* Close the current node */
                    parser->current = parser->current->parent;
                }
                /* Clear the buffer */
                parser->buffer_pos = 0;
            /* Otherwise, append the character to the buffer */
            } else {
                xml_parser_append_char(parser, *p);
            }
        /* If we are outside a tag */
        } else {
            /* If we see the start of a tag */
            if (*p == '<') {
                /* Make a new node for the root */
                if (parser->root == NULL) {
                    parser->root = xml_node_create(NULL, "", "");
                    parser->current = parser->root;
                /* Set the current node to the new sibling */
                } else {
                    xml_node* node = xml_node_create(parser->current->parent, "", "");
                    parser->current->next_sibling = node;
                    parser->current = node;
                }
            }
        }
        p++;
    }
    return parser;
}

/* Print an XML node and all its children */
void xml_node_print(xml_node* node, int indent) {
    for (int i = 0; i < indent; i++) {
        printf("  ");
    }
    printf("<%s>%s</%s>\n", node->name, node->value, node->name);
    for (xml_node* child = node->first_child; child; child = child->next_sibling) {
        xml_node_print(child, indent + 1);
    }
}

int main() {
    char* xml = "<root><a>hello</a><b><c>world</c></b></root>";
    xml_parser* parser = xml_parse(xml);
    xml_node_print(parser->root, 0);
    xml_parser_destroy(parser);
    return 0;
}