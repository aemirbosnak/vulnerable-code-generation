//Falcon-180B DATASET v1.0 Category: Building a XML Parser ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_ELEMENT_SIZE 256
#define MAX_ELEMENT_NUM 100

typedef struct {
    char name[MAX_ELEMENT_SIZE];
    char value[MAX_ELEMENT_SIZE];
    struct element *next;
} element;

element *create_element(char *name, char *value) {
    element *new_element = malloc(sizeof(element));
    strcpy(new_element->name, name);
    strcpy(new_element->value, value);
    new_element->next = NULL;
    return new_element;
}

void add_element(element **head, char *name, char *value) {
    element *new_element = create_element(name, value);
    if (*head == NULL) {
        *head = new_element;
    } else {
        element *current = *head;
        while (current->next!= NULL) {
            current = current->next;
        }
        current->next = new_element;
    }
}

void print_element(element *element) {
    printf("<%s>%s</%s>\n", element->name, element->value, element->name);
}

void print_document(element *head) {
    printf("<?xml version=\"1.0\"?>\n");
    printf("<document>\n");
    element *current = head;
    while (current!= NULL) {
        print_element(current);
        current = current->next;
    }
    printf("</document>\n");
}

int main() {
    element *head = NULL;
    char buffer[MAX_ELEMENT_SIZE];
    int element_count = 0;
    while (fgets(buffer, MAX_ELEMENT_SIZE, stdin)!= NULL) {
        if (element_count >= MAX_ELEMENT_NUM) {
            printf("Error: Maximum number of elements reached.\n");
            exit(1);
        }
        char *name = strtok(buffer, " ");
        char *value = strtok(NULL, " ");
        if (name == NULL || value == NULL) {
            printf("Error: Invalid element format.\n");
            exit(1);
        }
        add_element(&head, name, value);
        element_count++;
    }
    print_document(head);
    return 0;
}