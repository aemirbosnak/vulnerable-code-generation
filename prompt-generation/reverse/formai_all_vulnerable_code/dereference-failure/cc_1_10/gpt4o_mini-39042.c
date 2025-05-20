//GPT-4o-mini DATASET v1.0 Category: Building a XML Parser ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct XmlNode {
    char *tag;
    char *content;
    struct XmlNode **children;
    int child_count;
} XmlNode;

XmlNode* create_node(const char *tag, const char *content) {
    XmlNode *node = (XmlNode *)malloc(sizeof(XmlNode));
    node->tag = strdup(tag);
    node->content = strdup(content);
    node->children = NULL;
    node->child_count = 0;
    return node;
}

void add_child(XmlNode *parent, XmlNode *child) {
    parent->children = (XmlNode **)realloc(parent->children, sizeof(XmlNode *) * (parent->child_count + 1));
    parent->children[parent->child_count] = child;
    parent->child_count++;
}

void free_xml_node(XmlNode *node) {
    if (node) {
        free(node->tag);
        free(node->content);
        for (int i = 0; i < node->child_count; i++) {
            free_xml_node(node->children[i]);
        }
        free(node->children);
        free(node);
    }
}

void print_xml(XmlNode *node, int depth) {
    if (!node) return;
    
    for (int i = 0; i < depth; i++) {
        printf("    ");
    }
    printf("<%s>", node->tag);
    if (node->content && strlen(node->content) > 0) {
        printf("%s", node->content);
    }
    printf("\n");

    for (int i = 0; i < node->child_count; i++) {
        print_xml(node->children[i], depth + 1);
    }

    for (int i = 0; i < depth; i++) {
        printf("    ");
    }
    printf("</%s>\n", node->tag);
}

XmlNode* parse_xml(const char *xml) {
    XmlNode *root = NULL;
    char tag[100];
    char content[100];
    int i = 0, j = 0, in_tag = 0, in_content = 0;
    XmlNode *current = NULL;
    
    while (xml[i] != '\0') {
        if (xml[i] == '<') {
            if (xml[i + 1] == '/') { // Closing tag
                tag[j] = '\0'; // Null-terminate tag
                j = 0;
                i++; // Skip '/'
                while (xml[i] != '>') {
                    tag[j++] = xml[i++];
                }
                tag[j] = '\0'; // Null-terminate closing tag
                if (current) {
                    current = current->children[current->child_count - 1]; // Go back up
                }
            } else { // Opening tag
                tag[j] = '\0'; // Null-terminate tag
                j = 0;
                i++; // Skip '<'
                while (xml[i] != '>') {
                    tag[j++] = xml[i++];
                }
                tag[j] = '\0'; // Null-terminate opening tag
                if (!root) {
                    root = create_node(tag, "");
                    current = root;
                } else {
                    XmlNode *new_node = create_node(tag, "");
                    add_child(current, new_node);
                    current = new_node; // Move current to new node
                }
            }
        } else if (xml[i] != ' ' && xml[i] != '\n' && xml[i] != '\r' && !in_content) {
            in_content = 1; // Start of content
            j = 0;
        }
        
        if (in_content) {
            if (xml[i] == '<') {
                in_content = 0; // Content has ended
                content[j] = '\0';
                if (current) {
                    free(current->content);
                    current->content = strdup(content);
                }
            } else if (in_content) {
                content[j++] = xml[i];
            }
        }
        i++;
    }

    return root;
}

int main() {
    const char *xml_data = "<root><child1>Content1</child1><child2>Content2</child2></root>";
    
    XmlNode *xml_tree = parse_xml(xml_data);

    printf("Parsed XML:\n");
    print_xml(xml_tree, 0);

    free_xml_node(xml_tree);
    return 0;
}