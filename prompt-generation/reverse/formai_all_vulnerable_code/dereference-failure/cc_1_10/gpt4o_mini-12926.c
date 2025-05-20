//GPT-4o-mini DATASET v1.0 Category: Building a XML Parser ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_TAG_LENGTH 128
#define MAX_VALUE_LENGTH 256

struct XmlNode {
    char tag[MAX_TAG_LENGTH];
    char value[MAX_VALUE_LENGTH];
    struct XmlNode* next;
};

struct XmlNode* create_node(const char* tag, const char* value) {
    struct XmlNode* new_node = (struct XmlNode*)malloc(sizeof(struct XmlNode));
    if (new_node == NULL) {
        perror("Failed to allocate memory");
        exit(EXIT_FAILURE);
    }
    strncpy(new_node->tag, tag, MAX_TAG_LENGTH);
    strncpy(new_node->value, value, MAX_VALUE_LENGTH);
    new_node->next = NULL;
    return new_node;
}

void append_node(struct XmlNode** head, const char* tag, const char* value) {
    struct XmlNode* new_node = create_node(tag, value);
    if (*head == NULL) {
        *head = new_node;
    } else {
        struct XmlNode* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = new_node;
    }
}

void free_nodes(struct XmlNode* head) {
    struct XmlNode* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

void print_xml_nodes(struct XmlNode* head) {
    struct XmlNode* temp = head;
    while (temp != NULL) {
        printf("Tag: <%s>, Value: \"%s\"\n", temp->tag, temp->value);
        temp = temp->next;
    }
}

void parse_xml(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        perror("Could not open file");
        exit(EXIT_FAILURE);
    }

    char line[MAX_LINE_LENGTH];
    struct XmlNode* xml_list = NULL;

    while (fgets(line, sizeof(line), file) != NULL) {
        char tag[MAX_TAG_LENGTH];
        char value[MAX_VALUE_LENGTH] = "";
        
        // Look for the opening tag
        if (sscanf(line, "<%127[^>]>", tag) == 1) {
            // Look for the closing tag or the standalone tag
            if (strstr(line, "/>") == NULL) { // Not a self-closing tag
                if (fgets(line, sizeof(line), file) != NULL) {
                    sscanf(line, "%255[^<]", value); // Get the value before the closing tag
                    append_node(&xml_list, tag, value);
                }
                fgets(line, sizeof(line), file); // Read the closing tag line
            } else {
                // Handle self-closing tag
                append_node(&xml_list, tag, "");
            }
        }
    }
    
    fclose(file);
    
    // Print the parsed XML contents
    printf("Parsed XML Contents:\n");
    print_xml_nodes(xml_list);
    
    // Free the linked list
    free_nodes(xml_list);
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        printf("Usage: %s <xml_file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    parse_xml(argv[1]);
    return EXIT_SUCCESS;
}