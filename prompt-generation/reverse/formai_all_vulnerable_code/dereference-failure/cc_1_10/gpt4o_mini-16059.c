//GPT-4o-mini DATASET v1.0 Category: Building a XML Parser ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 256
#define MAX_TAG_LENGTH 64
#define MAX_VALUE_LENGTH 256

typedef struct XmlNode {
    char tag[MAX_TAG_LENGTH];
    char value[MAX_VALUE_LENGTH];
    struct XmlNode *next;
} XmlNode;

XmlNode* create_node(const char *tag, const char *value) {
    XmlNode *node = (XmlNode*)malloc(sizeof(XmlNode));
    if (node == NULL) {
        fprintf(stderr, "Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }
    strncpy(node->tag, tag, MAX_TAG_LENGTH);
    strncpy(node->value, value, MAX_VALUE_LENGTH);
    node->next = NULL;
    return node;
}

void append_node(XmlNode **head, const char *tag, const char *value) {
    XmlNode *new_node = create_node(tag, value);
    if (*head == NULL) {
        *head = new_node;
    } else {
        XmlNode *current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_node;
    }
}

void free_nodes(XmlNode *head) {
    XmlNode *current = head;
    while (current != NULL) {
        XmlNode *temp = current;
        current = current->next;
        free(temp);
    }
}

void parse_xml(const char *filename, XmlNode **head) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        fprintf(stderr, "Could not open file: %s\n", filename);
        exit(EXIT_FAILURE);
    }

    char line[MAX_LINE_LENGTH];
    char tag[MAX_TAG_LENGTH];
    char value[MAX_VALUE_LENGTH];

    while (fgets(line, sizeof(line), file)) {
        char *start_tag = strchr(line, '<');
        if (start_tag != NULL) {
            char *end_tag = strchr(start_tag, '>');
            if (end_tag != NULL) {
                size_t tag_length = end_tag - start_tag - 1;
                strncpy(tag, start_tag + 1, tag_length);
                tag[tag_length] = '\0';

                char *content_start = end_tag + 1;
                char *content_end = strchr(content_start, '<');
                if (content_end != NULL) {
                    size_t value_length = content_end - content_start;
                    strncpy(value, content_start, value_length);
                    value[value_length] = '\0';

                    append_node(head, tag, value);
                }
            }
        }
    }

    fclose(file);
}

void display_xml_nodes(XmlNode *head) {
    XmlNode *current = head;
    while (current != NULL) {
        printf("Tag: %s, Value: %s\n", current->tag, current->value);
        current = current->next;
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <xml-filename>\n", argv[0]);
        return EXIT_FAILURE;
    }

    XmlNode *head = NULL;
    parse_xml(argv[1], &head);
    display_xml_nodes(head);
    free_nodes(head);

    return EXIT_SUCCESS;
}