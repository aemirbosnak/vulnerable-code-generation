//Falcon-180B DATASET v1.0 Category: Building a XML Parser ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ELEMENTS 100
#define MAX_ELEMENT_SIZE 100

typedef struct {
    char *name;
    char *value;
    struct element *next;
} element;

element *head = NULL;

void startElement(char *name, char *value) {
    element *newElement = (element*) malloc(sizeof(element));
    newElement->name = strdup(name);
    newElement->value = strdup(value);
    newElement->next = NULL;

    if (head == NULL) {
        head = newElement;
    } else {
        element *current = head;
        while (current->next!= NULL) {
            current = current->next;
        }
        current->next = newElement;
    }
}

void endElement() {
    element *current = head;
    while (current!= NULL && strcmp(current->name, "")!= 0) {
        current = current->next;
    }

    if (current!= NULL) {
        free(current->name);
        free(current->value);
        free(current);
        head = current->next;
    }
}

void characterData(char *data) {
    element *current = head;
    while (current!= NULL && strcmp(current->name, "")!= 0) {
        current = current->next;
    }

    if (current!= NULL) {
        current->value = realloc(current->value, strlen(current->value) + strlen(data) + 1);
        strcat(current->value, data);
    }
}

int main() {
    startElement("root", "");
    startElement("child1", "value1");
    characterData("data1");
    endElement();
    startElement("child2", "value2");
    characterData("data2");
    endElement();
    endElement();

    element *current = head;
    while (current!= NULL) {
        printf("<%s>%s</%s>\n", current->name, current->value, current->name);
        current = current->next;
    }

    return 0;
}