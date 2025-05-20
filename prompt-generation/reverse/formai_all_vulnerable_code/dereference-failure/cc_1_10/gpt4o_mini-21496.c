//GPT-4o-mini DATASET v1.0 Category: Building a XML Parser ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Element {
    char *name;
    char *value;
    struct Element *next;
    struct Element *child;
} Element;

Element* create_element(const char *name, const char *value) {
    Element *new_element = (Element*)malloc(sizeof(Element));
    new_element->name = strdup(name);
    new_element->value = value ? strdup(value) : NULL;
    new_element->next = NULL;
    new_element->child = NULL;
    return new_element;
}

void free_element(Element *element) {
    if (element) {
        free(element->name);
        if (element->value) {
            free(element->value);
        }
        free_element(element->child);
        free_element(element->next);
        free(element);
    }
}

void append_child(Element *parent, Element *child) {
    if (parent->child == NULL) {
        parent->child = child;
    } else {
        Element *tmp = parent->child;
        while (tmp->next != NULL) {
            tmp = tmp->next;
        }
        tmp->next = child;
    }
}

void print_element(Element *element, int level) {
    if (!element) return;
    for (int i = 0; i < level; i++) printf("  ");
    printf("<%s>%s\n", element->name, element->value ? element->value : "");
    print_element(element->child, level + 1);
    for (int i = 0; i < level; i++) printf("  ");
    printf("</%s>\n", element->name);
    print_element(element->next, level);
}

Element* parse_xml(const char *xml) {
    Element *root = NULL;
    Element *current = NULL;
    char name[256];
    char value[256];
    int pos = 0;
    int value_pos = 0;
    int in_tag = 0;
    int in_value = 0;

    while (*xml) {
        if (*xml == '<') {
            // Check if closing tag
            if (*(xml + 1) == '/') {
                while (*xml && *xml != '>') xml++;
                xml++; // move past '>'
                in_tag = 0;
                continue;
            }

            // New tag
            in_tag = 1;
            pos = 0;
            xml++; // move past '<'

            while (*xml && *xml != '>' && *xml != ' ') {
                name[pos++] = *xml++;
            }
            name[pos] = '\0';
            root = create_element(name, NULL);
            current = root;
            while (*xml && *xml != '>') {
                if (*xml == ' ') {
                    xml++;
                    continue;
                }
                if (*xml == '=') {
                    xml++;
                    value_pos = 0;
                    if (*xml == '\"' || *xml == '\'') {
                        char quote = *xml++;
                        while (*xml && *xml != quote) {
                            value[value_pos++] = *xml++;
                        }
                        value[value_pos] = '\0';
                        current->value = strdup(value);
                    }
                }
            }
            xml++; // move past '>'
            in_value = 0;
            continue;
        }
        else if (*xml == '>') {
            in_tag = 0;
            xml++;
            continue;
        }

        // Adding possible children or moving to next tag
        if (in_value) {
            if (current) {
                value[value_pos++] = *xml;
            }
        }

        if (*xml == '/' && *(xml + 1) == '>') {
            xml += 2; // Skip '/>'
            in_tag = 0;
            in_value = 0;
            if (current) {
                Element *child = create_element(name, NULL);
                append_child(current, child);
            }
            current = NULL; 
            continue;
        }

        xml++;
    }
    return root;
}

int main(int argc, char **argv) {
    const char *xml_data = "<root><child1>Value1</child1><child2>Value2</child2></root>";
    Element *parsed_data = parse_xml(xml_data);

    if (parsed_data) {
        print_element(parsed_data, 0);
        free_element(parsed_data);
    } else {
        printf("Failed to parse XML.\n");
    }

    return 0;
}