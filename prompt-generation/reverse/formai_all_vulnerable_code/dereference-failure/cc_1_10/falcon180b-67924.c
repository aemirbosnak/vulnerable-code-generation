//Falcon-180B DATASET v1.0 Category: Building a XML Parser ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ELEMENTS 100
#define MAX_NAME_LENGTH 50
#define MAX_VALUE_LENGTH 100

typedef struct element {
    char name[MAX_NAME_LENGTH];
    char value[MAX_VALUE_LENGTH];
    struct element *next;
} element;

element *head = NULL;

void add_element(char *name, char *value) {
    element *new_element = (element *) malloc(sizeof(element));
    strncpy(new_element->name, name, MAX_NAME_LENGTH);
    strncpy(new_element->value, value, MAX_VALUE_LENGTH);
    new_element->next = NULL;
    
    if (head == NULL) {
        head = new_element;
    } else {
        element *current = head;
        while (current->next!= NULL) {
            current = current->next;
        }
        current->next = new_element;
    }
}

void print_elements() {
    element *current = head;
    while (current!= NULL) {
        printf("<%s>%s</%s>\n", current->name, current->value, current->name);
        current = current->next;
    }
}

int main() {
    char *xml_string = "<book><title>The Great Gatsby</title><author>F. Scott Fitzgerald</author></book>";
    char *token = strtok(xml_string, " <>");
    while (token!= NULL) {
        if (strncmp(token, "<", 1) == 0) {
            char *name = strtok(NULL, " <>");
            char *value = strtok(NULL, " <>");
            add_element(name, value);
        }
        token = strtok(NULL, " <>");
    }
    print_elements();
    return 0;
}