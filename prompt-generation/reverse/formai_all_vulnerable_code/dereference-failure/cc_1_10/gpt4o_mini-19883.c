//GPT-4o-mini DATASET v1.0 Category: Building a XML Parser ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct XMLNode {
    char *tag;
    char *content;
    struct XMLNode **children;
    int child_count;
} XMLNode;

// Function to create a new XML node
XMLNode* create_node(const char *tag, const char *content) {
    XMLNode *node = (XMLNode *)malloc(sizeof(XMLNode));
    node->tag = strdup(tag);
    node->content = content ? strdup(content) : NULL;
    node->children = NULL;
    node->child_count = 0;
    return node;
}

// Function to free the XML node
void free_node(XMLNode *node) {
    if (node) {
        free(node->tag);
        if (node->content) free(node->content);
        for (int i = 0; i < node->child_count; i++) {
            free_node(node->children[i]);
        }
        free(node->children);
        free(node);
    }
}

// Function to add a child node
void add_child(XMLNode *parent, XMLNode *child) {
    parent->child_count++;
    parent->children = realloc(parent->children, sizeof(XMLNode *) * parent->child_count);
    parent->children[parent->child_count - 1] = child;
}

// Function to parse a string and create XML nodes
XMLNode* parse_xml(const char *xml) {
    XMLNode *root = create_node("root", NULL);
    char *token;
    char *xml_copy = strdup(xml);
    char *rest = xml_copy;
    
    while ((token = strtok_r(rest, "<>", &rest))) {
        char *tag_end = strchr(token, ' ');
        if (tag_end) {
            *tag_end = '\0';
            char *content_start = tag_end + 1;
            char *content_end = strchr(content_start, '<');
            if (content_end) {
                *content_end = '\0';
                add_child(root, create_node(token, content_start));
                rest = content_end;
            } else {
                add_child(root, create_node(token, content_start));
                break;
            }
        } else {
            add_child(root, create_node(token, NULL));
        }
    }
    free(xml_copy);
    return root;
}

// Function to print XML nodes (for testing)
void print_xml(XMLNode *node, int depth) {
    for (int i = 0; i < depth; i++) printf("  ");
    printf("<%s>", node->tag);
    if (node->content) printf("%s", node->content);
    printf("\n");
    for (int i = 0; i < node->child_count; i++) {
        print_xml(node->children[i], depth + 1);
    }
    for (int i = 0; i < depth; i++) printf("  ");
    printf("</%s>\n", node->tag);
}

// Main function to demonstrate the XML parser
int main() {
    const char *xml_data = "<note><to>Tove</to><from>Jani</from><heading>Reminder</heading><body>Don't forget me this weekend!</body></note>";
    
    printf("Parsing XML data:\n%s\n", xml_data);
    
    XMLNode *parsed_xml = parse_xml(xml_data);
    
    printf("\nParsed XML structure:\n");
    print_xml(parsed_xml, 0);
    
    free_node(parsed_xml);
    
    return 0;
}