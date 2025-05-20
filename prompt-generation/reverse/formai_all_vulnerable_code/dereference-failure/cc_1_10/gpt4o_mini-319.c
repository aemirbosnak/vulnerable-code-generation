//GPT-4o-mini DATASET v1.0 Category: Building a XML Parser ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure to hold XML element data
typedef struct XmlElement {
    char *tag;
    char *value;
    struct XmlElement *next;
} XmlElement;

// Function prototypes
XmlElement* create_element(const char *tag, const char *value);
void add_element(XmlElement **head, const char *tag, const char *value);
void free_elements(XmlElement *head);
void parse_xml(FILE *file, XmlElement **head);
void print_elements(XmlElement *head);

int main() {
    FILE *file;
    XmlElement *elements = NULL;

    // Open the XML file
    file = fopen("example.xml", "r");
    if (!file) {
        perror("Error opening file");
        return EXIT_FAILURE;
    }

    // Parse the XML file
    parse_xml(file, &elements);

    // Close the file
    fclose(file);

    // Print the parsed elements
    printf("Parsed XML Elements:\n");
    print_elements(elements);

    // Free the allocated memory
    free_elements(elements);

    return EXIT_SUCCESS;
}

// Create a new XML element
XmlElement* create_element(const char *tag, const char *value) {
    XmlElement *new_element = (XmlElement *)malloc(sizeof(XmlElement));
    new_element->tag = strdup(tag);
    new_element->value = strdup(value);
    new_element->next = NULL;
    return new_element;
}

// Add an element to the linked list
void add_element(XmlElement **head, const char *tag, const char *value) {
    XmlElement *new_element = create_element(tag, value);
    new_element->next = *head;
    *head = new_element;
}

// Free allocated memory for the element list
void free_elements(XmlElement *head) {
    XmlElement *current = head;
    while (current != NULL) {
        XmlElement *next = current->next;
        free(current->tag);
        free(current->value);
        free(current);
        current = next;
    }
}

// Parse the XML file and extract elements
void parse_xml(FILE *file, XmlElement **head) {
    char line[256];
    char tag[64], value[192];
    while (fgets(line, sizeof(line), file)) {
        // Extracting the tag and value from the XML line
        if (sscanf(line, "<%63[^>]>%191[^<]</%63[^>]>",
            tag, value, tag) == 3) {
            add_element(head, tag, value);
        }
    }
}

// Print all elements
void print_elements(XmlElement *head) {
    XmlElement *current = head;
    while (current != NULL) {
        printf("Tag: %s, Value: %s\n", current->tag, current->value);
        current = current->next;
    }
}