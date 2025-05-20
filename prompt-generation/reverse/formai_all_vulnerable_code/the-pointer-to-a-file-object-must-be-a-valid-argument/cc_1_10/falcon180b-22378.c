//Falcon-180B DATASET v1.0 Category: Building a XML Parser ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ELEMENT_SIZE 1000
#define MAX_ELEMENT_NUMBER 1000

typedef struct element {
    char name[MAX_ELEMENT_SIZE];
    char value[MAX_ELEMENT_SIZE];
    struct element *next;
} Element;

Element *createElement(char *name, char *value) {
    Element *element = (Element *)malloc(sizeof(Element));
    strcpy(element->name, name);
    strcpy(element->value, value);
    element->next = NULL;
    return element;
}

void addElement(Element *head, Element *element) {
    Element *tail = head;
    while (tail->next!= NULL) {
        tail = tail->next;
    }
    tail->next = element;
}

void printElement(Element *element) {
    printf("<%s>%s</%s>\n", element->name, element->value, element->name);
}

void freeElement(Element *element) {
    free(element);
}

int main() {
    FILE *file = fopen("example.xml", "r");
    char line[MAX_ELEMENT_SIZE];
    Element *head = NULL;
    Element *tail = NULL;
    while (fgets(line, MAX_ELEMENT_SIZE, file)!= NULL) {
        char *name = strtok(line, " \t\r\n");
        char *value = strtok(NULL, " \t\r\n");
        if (name == NULL || value == NULL) {
            continue;
        }
        Element *element = createElement(name, value);
        if (head == NULL) {
            head = element;
            tail = element;
        } else {
            tail->next = element;
            tail = element;
        }
    }
    fclose(file);

    printf("XML Elements:\n");
    Element *current = head;
    while (current!= NULL) {
        printElement(current);
        current = current->next;
    }

    freeElement(head);
    return 0;
}