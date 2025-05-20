//GPT-4o-mini DATASET v1.0 Category: Building a XML Parser ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_TAG_LENGTH 256

typedef struct Element {
    char tag[MAX_TAG_LENGTH];
    char content[MAX_LINE_LENGTH];
    struct Element *next;
} Element;

Element *create_element(const char *tag, const char *content) {
    Element *new_element = (Element *)malloc(sizeof(Element));
    if (!new_element) {
        perror("Failed to allocate memory for an Element");
        exit(EXIT_FAILURE);
    }
    strncpy(new_element->tag, tag, MAX_TAG_LENGTH);
    strncpy(new_element->content, content, MAX_LINE_LENGTH);
    new_element->next = NULL;
    return new_element;
}

void free_elements(Element *head) {
    Element *tmp;
    while (head) {
        tmp = head;
        head = head->next;
        free(tmp);
    }
}

void parse_xml(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Could not open XML file");
        exit(EXIT_FAILURE);
    }

    char line[MAX_LINE_LENGTH];
    char current_tag[MAX_TAG_LENGTH] = "";
    char content_buffer[MAX_LINE_LENGTH] = "";
    int in_tag = 0, in_content = 0;
    Element *head = NULL, *tail = NULL;

    while (fgets(line, MAX_LINE_LENGTH, file)) {
        char *tag_start = strchr(line, '<');
        char *tag_end = strchr(line, '>');
        
        if (tag_start && tag_end && tag_start < tag_end) {
            *tag_end = '\0'; // Null-terminate tag for easy string operations
            if (*(tag_start + 1) == '/') {
                // Closing tag
                in_tag = 0;
                if (strlen(content_buffer) > 0) {
                    Element *element = create_element(current_tag, content_buffer);
                    if (!head) {
                        head = element;
                        tail = element;
                    } else {
                        tail->next = element;
                        tail = element;
                    }
                    content_buffer[0] = '\0'; // Reset the buffer
                }
            } else {
                // Opening tag
                in_tag = 1;
                strcpy(current_tag, tag_start + 1);
                current_tag[strcspn(current_tag, " ")] = '\0'; // Remove attributes if present
                in_content = 1; // Now we expect content
            }
        } else if (in_content) {
            strncat(content_buffer, line, MAX_LINE_LENGTH - strlen(content_buffer) - 1);
        }
    }

    fclose(file);

    // Print the parsed XML elements
    Element *current = head;
    while (current) {
        printf("Tag: %s, Content: %s\n", current->tag, current->content);
        current = current->next;
    }

    // Free allocated memory
    free_elements(head);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return EXIT_FAILURE;
    }

    parse_xml(argv[1]);

    return EXIT_SUCCESS;
}