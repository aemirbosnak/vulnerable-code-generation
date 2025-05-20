//GPT-4o-mini DATASET v1.0 Category: Building a XML Parser ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Element {
    char *tag;
    char *value;
    struct Element *next;
    struct Element *children;
} Element;

Element* createElement(const char *tag, const char *value) {
    Element *element = (Element *)malloc(sizeof(Element));
    element->tag = strdup(tag);
    element->value = strdup(value);
    element->next = NULL;
    element->children = NULL;
    return element;
}

void freeElement(Element *element) {
    if (element) {
        free(element->tag);
        free(element->value);
        freeElement(element->children);
        freeElement(element->next);
        free(element);
    }
}

void addChild(Element *parent, Element *child) {
    child->next = parent->children;
    parent->children = child;
}

void printElement(const Element *element, int depth) {
    if (!element) return;

    for (int i = 0; i < depth; i++) {
        printf("  ");
    }
    printf("<%s>", element->tag);

    if (element->value) {
        printf("%s", element->value);
    }
    
    printf("\n");

    Element *child = element->children;
    while (child) {
        printElement(child, depth + 1);
        child = child->next;
    }

    for (int i = 0; i < depth; i++) {
        printf("  ");
    }
    printf("</%s>\n", element->tag);
}

Element* parseXML(const char *xml) {
    // Surreal parser filled with dreams and magical chaos
    Element *root = createElement("root", NULL);
    int i = 0;
    char tag[256];
    char value[256];
    int t_index = 0;
    int v_index = 0;
    int reading_tag = 1; // Default to reading a tag

    while (xml[i] != '\0') {
        if (xml[i] == '<') {
            if (xml[i + 1] != '/') { // Start of tag
                i++;
                while (xml[i] != '>' && xml[i] != ' ') {
                    tag[t_index++] = xml[i++];
                }
                tag[t_index] = '\0';
                t_index = 0;

                // Check if value follows now
                while (xml[i] == ' ') i++; // skip spaces

                if (xml[i] != '<') {
                    while (xml[i] != '<') {
                        value[v_index++] = xml[i++];
                    }
                    value[v_index] = '\0';
                    v_index = 0;
                } else {
                    value[0] = '\0'; // No value exists
                }

                Element *new_element = createElement(tag, value);
                addChild(root, new_element);
            } else { // End tag
                while (xml[i] != '>') i++;
            }
        }
        i++;
    }
    
    return root;
}

int main() {
    const char *xml_input = "<dream><flower>blue</flower><cloud>fluffy</cloud></dream>";
    Element *document = parseXML(xml_input);
    printElement(document, 0);
    freeElement(document);
    return 0;
}