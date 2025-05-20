//FormAI DATASET v1.0 Category: Building a XML Parser ; Style: funny
#include <stdio.h>
#include <malloc.h>
#include <string.h>

// Fun fact: This XML parser was created in a single day!
// How did I do it, you ask? With a lot of caffeine and a little bit of magic.

typedef struct {
    char* tag_name;
    char* content;
    int num_children;
    struct xml_node** children;
} xml_node;

// This function takes a string containing the XML data and parses it into a tree of xml_nodes.
xml_node* parse_xml(char* xml_data)
{
    int num_nodes = 0;
    xml_node* root_node = NULL;
    xml_node** node_stack = malloc(sizeof(xml_node*) * 100);

    char* start_pos = xml_data;

    while (*start_pos && num_nodes < 100) {
        // Find the start of the next tag
        char* tag_start = strchr(start_pos, '<');
        if (!tag_start) {
            break;
        }

        if (tag_start[1] == '/') { // it's a closing tag
            xml_node* closed_node = node_stack[--num_nodes];
            if (num_nodes > 0) {
                xml_node* parent_node = node_stack[num_nodes - 1];
                parent_node->children[parent_node->num_children++] = closed_node;
            } else {
                root_node = closed_node;
            }
            start_pos = strchr(tag_start, '>') + 1;
        } else { // it's an opening tag
            xml_node* new_node = malloc(sizeof(xml_node));
            new_node->tag_name = strdup(tag_start + 1);
            new_node->content = strdup("");

            // Find the end of the tag name
            char* tag_end = strchr(new_node->tag_name, ' ');
            if (!tag_end) {
                tag_end = strchr(new_node->tag_name, '>');
            }

            // Create a null-terminated copy of the tag name
            *tag_end = '\0';

            // Add the new node to its parent's children list
            if (num_nodes > 0) {
                xml_node* parent_node = node_stack[num_nodes - 1];
                parent_node->children[parent_node->num_children++] = new_node;
            } else {
                root_node = new_node;
            }

            // Push the new node onto the stack
            node_stack[num_nodes++] = new_node;

            // Skip past the opening tag
            start_pos = strchr(tag_start, '>') + 1;
        }
    }

    free(node_stack);
    return root_node;
}

// This function recursively prints out an xml_node and its children in a pretty format.
void print_xml_node(xml_node* node, int depth)
{
    // Calculate the indentation level based on the node's depth
    char* indent = malloc(depth + 1);
    memset(indent, ' ', depth);
    indent[depth] = '\0';

    // Print the opening tag
    printf("%s<%s>", indent, node->tag_name);

    // Print the node's content
    printf("%s", node->content);

    // Print the node's children
    for (int i = 0; i < node->num_children; i++) {
        printf("\n");
        print_xml_node(node->children[i], depth + 4);
    }

    // Print the closing tag
    printf("</%s>", node->tag_name);

    free(indent);
}

int main()
{
    char* xml_data = "<root_node><child_node>hello, world!</child_node><child_node><grandchild_node>this is a nested tag</grandchild_node></child_node></root_node>";
    xml_node* root_node = parse_xml(xml_data);
    print_xml_node(root_node, 0);
    return 0;
}