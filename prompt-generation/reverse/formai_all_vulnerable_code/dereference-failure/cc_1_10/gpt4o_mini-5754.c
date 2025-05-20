//GPT-4o-mini DATASET v1.0 Category: Building a XML Parser ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024
#define TAG_SIZE 64

typedef struct XmlNode {
    char tag[TAG_SIZE];
    char content[BUFFER_SIZE];
    struct XmlNode *next;
} XmlNode;

XmlNode* create_node(const char* tag, const char* content) {
    XmlNode* new_node = (XmlNode*)malloc(sizeof(XmlNode));
    if (new_node == NULL) {
        fprintf(stderr, "Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }
    strncpy(new_node->tag, tag, TAG_SIZE - 1);
    new_node->tag[TAG_SIZE - 1] = '\0'; // Ensure null termination
    strncpy(new_node->content, content, BUFFER_SIZE - 1);
    new_node->content[BUFFER_SIZE - 1] = '\0'; // Ensure null termination
    new_node->next = NULL;
    return new_node;
}

void free_nodes(XmlNode* head) {
    XmlNode* current = head;
    while (current != NULL) {
        XmlNode* next_node = current->next;
        free(current);
        current = next_node;
    }
}

void print_xml(XmlNode* head) {
    XmlNode* current = head;
    while (current != NULL) {
        printf("<%s>%s</%s>\n", current->tag, current->content, current->tag);
        current = current->next;
    }
}

void parse_xml_file(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        fprintf(stderr, "Could not open file %s\n", filename);
        exit(EXIT_FAILURE);
    }

    char buffer[BUFFER_SIZE];
    XmlNode* head = NULL;
    XmlNode* tail = NULL;

    while (fgets(buffer, sizeof(buffer), file)) {
        char tag[TAG_SIZE];
        char content[BUFFER_SIZE];

        // Example of simple parsing, extracting tag and content.
        if (sscanf(buffer, "<%63[^>]>%1023[^<]", tag, content) == 2) {
            XmlNode* new_node = create_node(tag, content);
            if (head == NULL) {
                head = new_node;
                tail = new_node;
            } else {
                tail->next = new_node;
                tail = new_node;
            }
        }
    }

    fclose(file);
    print_xml(head);
    free_nodes(head);
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <xml_file>\n", argv[0]);
        return EXIT_FAILURE;
    }
    parse_xml_file(argv[1]);
    return EXIT_SUCCESS;
}