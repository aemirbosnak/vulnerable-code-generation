//FormAI DATASET v1.0 Category: Building a XML Parser ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CHILDREN 10

typedef struct xml_node_struct {
    char *name;
    char *data;
    struct xml_node_struct *parent;
    struct xml_node_struct *children[MAX_CHILDREN];
    int num_children;
} xml_node;

xml_node *parse_xml(char *filename);
xml_node *parse_node(char **xml, xml_node *parent);
int find_end_of_tag(char *xml);
char *extract_tag_name(char *start_tag);
void print_xml(xml_node *root, int level);

int main()
{
    char filename[] = "example.xml";
    xml_node *root = parse_xml(filename);
    print_xml(root, 0);
    return 0;
}

xml_node *parse_xml(char *filename)
{
    xml_node *root = NULL;
    FILE *fp;
    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: could not open file '%s'\n", filename);
        return NULL;
    }
    fseek(fp, 0, SEEK_END);
    long file_size = ftell(fp);
    rewind(fp);
    char *xml_string = calloc(file_size + 1, 1);
    fread(xml_string, file_size, 1, fp);
    fclose(fp);
    root = parse_node(&xml_string, NULL);
    free(xml_string);
    return root;
}

xml_node *parse_node(char **xml, xml_node *parent)
{
    // Extract tag name
    char *start_tag = strstr(*xml, "<");
    if (start_tag == NULL) {
        return NULL;
    }
    char *tag_name = extract_tag_name(start_tag);
    // Extract data
    char *end_tag = strstr(start_tag, ">");
    if (end_tag == NULL) {
        return NULL;
    }
    int data_start = end_tag - *xml + 1;
    int data_end = find_end_of_tag(*xml) - 1;
    char *data = calloc(data_end - data_start + 2, 1);
    strncpy(data, *xml + data_start, data_end - data_start + 1);
    // Create node
    xml_node *node = calloc(1, sizeof(xml_node));
    node->name = tag_name;
    node->data = data;
    node->parent = parent;
    // Parse children
    *xml = end_tag + 1;  // Skip to end of start tag
    while (**xml != '\0') {
        xml_node *child = parse_node(xml, node);
        if (child != NULL) {
            node->children[node->num_children] = child;
            node->num_children++;
        } else {
            break;
        }
    }
    return node;
}

int find_end_of_tag(char *xml)
{
    int i = 0;
    while (xml[i] != '\0') {
        if (xml[i] == '>') {
            return i;
        } else {
            i++;
        }
    }
    return -1;
}

char *extract_tag_name(char *start_tag)
{
    char *tag_name_start = start_tag + 1;
    char *tag_name_end = strstr(start_tag, " ");
    if (tag_name_end == NULL) {
        tag_name_end = strstr(start_tag, ">");
    }
    int tag_name_length = tag_name_end - tag_name_start;
    char *tag_name = calloc(tag_name_length + 1, 1);
    strncpy(tag_name, tag_name_start, tag_name_length);
    return tag_name;
}

void print_xml(xml_node *root, int level)
{
    for (int i = 0; i < level; i++) {
        printf("  ");
    }
    printf("<%s>%s", root->name, root->data);
    if (root->num_children > 0) {
        printf("\n");
        for (int i = 0; i < root->num_children; i++) {
            print_xml(root->children[i], level + 1);
        }
        for (int i = 0; i < level; i++) {
            printf("  ");
        }
    }
    printf("</%s>\n", root->name);
}