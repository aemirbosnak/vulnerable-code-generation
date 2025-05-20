//MISTRAL-7B DATASET v1.0 Category: Linked list operations ; Style: configurable
#include <stdio.h>
#include <stdlib.h>

typedef struct element {
    int value;
    struct element* next;
} Element;

Element* create_element(int value) {
    Element* new_element = (Element*) malloc(sizeof(Element));
    new_element->value = value;
    new_element->next = NULL;
    return new_element;
}

void print_list(Element* head) {
    Element* current = head;
    printf("[ ");
    while (current != NULL) {
        printf("%d ", current->value);
        current = current->next;
    }
    printf("]\n");
}

void append_list(Element** head, int value) {
    Element* new_element = create_element(value);
    Element* current = *head;
    if (*head == NULL) {
        *head = new_element;
        return;
    }
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = new_element;
}

int main() {
    Element* head = NULL;

    append_list(&head, 5);
    append_list(&head, 10);
    append_list(&head, 15);

    print_list(head);

    free(head);
    return 0;
}