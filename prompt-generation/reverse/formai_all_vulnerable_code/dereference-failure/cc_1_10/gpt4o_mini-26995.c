//GPT-4o-mini DATASET v1.0 Category: Building a XML Parser ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Element {
    char name[50];
    char content[200];
    struct Element* next;
    struct Element* child;
} Element;

Element* createElement(const char* name, const char* content) {
    Element* newElement = (Element*)malloc(sizeof(Element));
    strcpy(newElement->name, name);
    strcpy(newElement->content, content);
    newElement->next = NULL;
    newElement->child = NULL;
    return newElement;
}

void addChild(Element* parent, Element* child) {
    if (parent->child == NULL) {
        parent->child = child;
    } else {
        Element* temp = parent->child;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = child;
    }
}

void freeElements(Element* elem) {
    if (elem == NULL) return;

    freeElements(elem->child);
    freeElements(elem->next);
    free(elem);
}

void printXML(Element* elem, int level) {
    if (elem == NULL) return;

    for (int i = 0; i < level; i++) {
        printf("  ");
    }
    printf("<%s>%s\n", elem->name, elem->content);
    printXML(elem->child, level + 1);
    
    for (int i = 0; i < level; i++) {
        printf("  ");
    }
    printf("</%s>\n", elem->name);
    printXML(elem->next, level);
}

int parseXML(const char* filename, Element** root) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        fprintf(stderr, "Cannot open file %s\n", filename);
        return -1;
    }
    
    char buffer[256];
    Element* currentElement = NULL;
    Element* lastElement = NULL;

    while (fgets(buffer, sizeof(buffer), file)) {
        char name[50], content[200];

        if (sscanf(buffer, "<%49[^>]>%199[^<]", name, content) == 2) {
            printf("Found opening tag <%s> with content '%s'\n", name, content);
            Element* newElem = createElement(name, content);
            if (*root == NULL) {
                *root = newElem; // Set the root element
            } else {
                // Add element to the last child of the currentElement
                if (currentElement) {
                    addChild(currentElement, newElem);
                }
            }
            currentElement = newElem; // Update current element
            lastElement = currentElement;

        } else if (sscanf(buffer, "</%49[^>]>", name) == 1) {
            printf("Found closing tag </%s>\n", name);
            if (lastElement) {
                currentElement = NULL; // Go back to parent
            }
        }
    }
    fclose(file);
    return 0;
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename.xml>\n", argv[0]);
        return EXIT_FAILURE;
    }

    Element* root = NULL;
    
    printf("Starting XML parsing from file: %s\n", argv[1]);
    if (parseXML(argv[1], &root) != 0) {
        return EXIT_FAILURE;
    }

    printf("Parsed XML Structure:\n");
    printXML(root, 0);
    
    freeElements(root);
    return EXIT_SUCCESS;
}