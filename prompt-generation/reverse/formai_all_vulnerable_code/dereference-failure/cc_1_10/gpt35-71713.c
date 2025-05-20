//FormAI DATASET v1.0 Category: Building a XML Parser ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct xml_node {
    char *name;
    char *value;
    int num_children;
    struct xml_node *children[10];
} xml_node;

static char *read_file(const char *filename) {
    FILE *fp;
    char *buffer;
    long length;

    fp = fopen(filename, "r");
    if (fp == NULL) {
        perror("Error opening file");
        exit(1);
    }
    fseek(fp, 0, SEEK_END);
    length = ftell(fp);
    fseek(fp, 0, SEEK_SET);
    buffer = malloc(length);
    if (buffer == NULL) {
        perror("Error allocating buffer");
        exit(1);
    }
    fread(buffer, 1, length, fp);
    fclose(fp);

    return buffer;
}

static xml_node *parse_xml(char *xml) {
    xml_node *root = malloc(sizeof(xml_node));
    root->name = NULL;
    root->value = NULL;
    root->num_children = 0;

    int pos = 0;
    while (pos < strlen(xml)) {
        if (xml[pos] == '<') {
            // Start of a new XML tag
            int end_pos = strchr(xml + pos, '>') - xml;
            char *tag = strndup(xml + pos + 1, end_pos - pos - 1);
            if (tag[0] == '/') {
                // End tag, return to parent
                free(tag);
                return root;
            } else {
                // New node, add to children of current node
                xml_node *child = malloc(sizeof(xml_node));
                child->name = tag;
                child->value = NULL;
                child->num_children = 0;
                root->children[root->num_children++] = child;
                root = child;
                pos = end_pos + 1;
            }
        } else {
            // Inside a tag, read value until next start tag
            int start_pos = pos;
            int end_pos = strchr(xml + pos, '<') - xml;
            pos = end_pos;
            char *value = strndup(xml + start_pos, end_pos - start_pos);
            root->value = value;
        }
    }

    return root;
}

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    char *xml = read_file(argv[1]);
    xml_node *root = parse_xml(xml);
    printf("Parsed XML file with %d nodes\n", root->num_children);

    return 0;
}