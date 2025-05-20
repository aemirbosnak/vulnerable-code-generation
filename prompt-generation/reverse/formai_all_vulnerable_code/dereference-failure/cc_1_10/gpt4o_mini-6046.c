//GPT-4o-mini DATASET v1.0 Category: Building a XML Parser ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 256
#define MAX_TAG_LENGTH 64
#define MAX_ATTRIBUTES 10
#define MAX_ATTRIBUTE_LENGTH 64

typedef struct {
    char tag[MAX_TAG_LENGTH];
    char attributes[MAX_ATTRIBUTES][MAX_ATTRIBUTE_LENGTH];
    int attr_count;
} XMLNode;

void parse_node(const char *line, XMLNode *node);
void print_node(const XMLNode *node);
int is_closing_tag(const char *line);
void trim_whitespace(char *str);
void process_xml_file(const char *filename);

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <xml_file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    process_xml_file(argv[1]);
    return EXIT_SUCCESS;
}

void process_xml_file(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Unable to open file");
        return;
    }

    char line[MAX_LINE_LENGTH];
    XMLNode current_node;
    
    while (fgets(line, sizeof(line), file)) {
        // Remove new line character
        line[strcspn(line, "\n")] = 0;

        if (!is_closing_tag(line)) {
            parse_node(line, &current_node);
            print_node(&current_node);
        }
    }

    fclose(file);
}

void parse_node(const char *line, XMLNode *node) {
    char *tag_start = strchr(line, '<') + 1;
    char *tag_end = strchr(tag_start, '>');
    size_t tag_length = tag_end - tag_start;

    strncpy(node->tag, tag_start, tag_length);
    node->tag[tag_length] = '\0';
    node->attr_count = 0;

    char *attr_start = strchr(tag_start, ' ');
    while (attr_start && attr_start < tag_end) {
        // Get the attribute name
        char *attr_name_end = strchr(attr_start, '=');
        if (!attr_name_end) break;

        size_t name_length = attr_name_end - attr_start;
        if (name_length < MAX_ATTRIBUTE_LENGTH) {
            strncpy(node->attributes[node->attr_count], attr_start, name_length);
            node->attributes[node->attr_count][name_length] = '\0';
            node->attr_count++;
            if (node->attr_count >= MAX_ATTRIBUTES) break;
        }

        // Move to the next attribute
        attr_start = strchr(attr_name_end + 1, ' ');
    }
}

void print_node(const XMLNode *node) {
    printf("Tag: %s\n", node->tag);
    for (int i = 0; i < node->attr_count; i++) {
        printf("  Attribute %d: %s\n", i + 1, node->attributes[i]);
    }
}

int is_closing_tag(const char *line) {
    return line[0] == '<' && line[1] == '/';
}