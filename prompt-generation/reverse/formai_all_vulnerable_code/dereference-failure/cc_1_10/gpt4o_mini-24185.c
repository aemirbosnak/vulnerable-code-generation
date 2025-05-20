//GPT-4o-mini DATASET v1.0 Category: Building a XML Parser ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_TAG_LENGTH 256
#define MAX_ATTR_LENGTH 256
#define MAX_VALUE_LENGTH 256

typedef struct Element {
    char tag[MAX_TAG_LENGTH];
    char attributes[MAX_ATTR_LENGTH];
    char value[MAX_VALUE_LENGTH];
    struct Element* next;
} Element;

Element* create_element(const char* tag, const char* attributes, const char* value) {
    Element* elem = (Element*)malloc(sizeof(Element));
    if (elem == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    strncpy(elem->tag, tag, MAX_TAG_LENGTH);
    strncpy(elem->attributes, attributes, MAX_ATTR_LENGTH);
    strncpy(elem->value, value, MAX_VALUE_LENGTH);
    elem->next = NULL;
    return elem;
}

void free_elements(Element* head) {
    Element* current = head;
    while (current != NULL) {
        Element* temp = current;
        current = current->next;
        free(temp);
    }
}

void print_elements(Element* head) {
    Element* current = head;
    while (current != NULL) {
        printf("Tag: %s\n", current->tag);
        if (strlen(current->attributes) > 0) {
            printf("Attributes: %s\n", current->attributes);
        }
        if (strlen(current->value) > 0) {
            printf("Value: %s\n", current->value);
        }
        current = current->next;
        printf("\n");
    }
}

void parse_xml(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        fprintf(stderr, "Could not open file %s\n", filename);
        return;
    }

    char line[MAX_LINE_LENGTH];
    Element* head = NULL;
    Element* tail = NULL;

    while (fgets(line, sizeof(line), file)) {
        char tag[MAX_TAG_LENGTH] = {0};
        char attributes[MAX_ATTR_LENGTH] = {0};
        char value[MAX_VALUE_LENGTH] = {0};

        // Extracting tag and optional attributes
        if (sscanf(line, "<%[^ ] %[^>]>", tag, attributes) > 0) {
            // Strip off trailing '>'
            char* closing_bracket = strchr(attributes, '>');
            if (closing_bracket != NULL) {
                *closing_bracket = '\0';  // null-terminate the attribute string
            }
            // Now we find the value if it exists
            if (fgets(line, sizeof(line), file)) {
                sscanf(line, "%[^<]", value);
                // converting new line character to null terminator
                value[strcspn(value, "\n")] = 0;
            }
            Element* new_element = create_element(tag, attributes, value);
            if (head == NULL) {
                head = new_element;
                tail = new_element;
            } else {
                tail->next = new_element;
                tail = new_element;
            }
        }
    }

    fclose(file);
    print_elements(head);
    free_elements(head);
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return EXIT_FAILURE;
    }

    parse_xml(argv[1]);
    return EXIT_SUCCESS;
}