//FormAI DATASET v1.0 Category: Building a XML Parser ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure to hold our parsed XML data.
typedef struct xml_node {
    char *tag;
    char *content;
    struct xml_node *next;
    struct xml_node *children;
} xml_node;

// A helper function to parse the attributes of an XML tag.
void parse_attributes(char *tag, char **key, char **value) {
    char *ptr = strstr(tag, "=\"");
    int len = 0;

    while (ptr) {
        ptr += 2;
        *key = realloc(*key, len + 1);
        *value = realloc(*value, len + 1);

        while (tag != ptr) (*key)[len++] = *(tag++);
        (*key)[len - 1] = '\0';

        ptr += 2;
        len = 0;

        while (*ptr != '\"') {
            (*value)[len++] = *(ptr++);
        }

        (*value)[len] = '\0';
        ptr = strstr(ptr, "=\"");
    }
}

// A recursive function to parse the XML tree.
void parse_xml(xml_node **node_ptr, char **xml_str) {
    char *tag_start, *content_start, *ptr;
    xml_node *cur_node = *node_ptr;
    *xml_str = strchr(*xml_str, '<');

    while (*xml_str) {
        tag_start = ++(*xml_str);

        // Check for the end of an XML tag.
        if (*tag_start == '/') {
            ptr = strchr(tag_start, '>');
            *ptr = '\0';
            *xml_str = ptr + 1;
            return;
        }

        // Parse the tag.
        while (*(*xml_str) != '>') ++(*xml_str);
        *(*xml_str)++ = '\0';
        cur_node->tag = strdup(tag_start);

        // Check for attributes.
        char *key = NULL, *value = NULL, *attr = strchr(tag_start, ' ');
        if (attr) parse_attributes(attr + 1, &key, &value);

        // Check for content.
        content_start = *xml_str;
        ptr = strstr(content_start, "<");
        if (!attr || (ptr - content_start < attr - tag_start - 1)) {
            while (*(*xml_str) != '<') ++(*xml_str);
            cur_node->content = strndup(content_start, *xml_str - content_start);
        }
        else {
            cur_node->content = NULL;
        }

        // Allocate space for the children nodes.
        cur_node->children = calloc(1, sizeof(xml_node));

        // Recursively parse the children nodes.
        parse_xml(&(cur_node->children), xml_str);

        // Allocate space for the next node.
        cur_node->next = calloc(1, sizeof(xml_node));
        cur_node = cur_node->next;
    }
}

int main() {
    // An example XML string to parse.
    char xml_str[] = "<root><child1>Content 1</child1><child2 attr1=\"val1\" attr2=\"val2\">Content 2<child3>Child content</child3></child2></root>";

    // Allocate space for the root node
    xml_node *root = calloc(1, sizeof(xml_node));

    // Parse the XML tree.
    parse_xml(&root, &xml_str);

    // Print the XML tree.
    xml_node *cur_node = root;
    while (cur_node->tag) {
        printf("<%s", cur_node->tag);

        if (cur_node->content) {
            printf(">%s</%s>", cur_node->content, cur_node->tag);
        }
        else {
            printf(">");

            cur_node = cur_node->children;
            while (cur_node->tag) {
                printf("<%s", cur_node->tag);

                if (cur_node->content) {
                    printf(">%s</%s>", cur_node->content, cur_node->tag);
                }
                else {
                    printf(">");

                    cur_node = cur_node->children;
                }

                printf("</%s>\n", cur_node->tag);
                cur_node = cur_node->next;
            }

            printf("</%s>\n", cur_node->tag);
        }

        cur_node = cur_node->next;
    }

    return 0;
}