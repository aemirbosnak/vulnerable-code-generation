//GEMINI-pro DATASET v1.0 Category: Linked list operations ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>

struct dreamscape {
    void *data;
    struct dreamscape *next;
};

struct dreamscape *head = NULL;

void add_to_dreamscape(void *data) {
    struct dreamscape *new_node = malloc(sizeof(struct dreamscape));
    new_node->data = data;
    new_node->next = head;
    head = new_node;
}

void remove_from_dreamscape(void *data) {
    struct dreamscape *current = head;
    struct dreamscape *previous = NULL;

    while (current != NULL) {
        if (current->data == data) {
            if (previous == NULL) {
                head = current->next;
            } else {
                previous->next = current->next;
            }
            free(current);
            break;
        }
        previous = current;
        current = current->next;
    }
}

void print_dreamscape() {
    struct dreamscape *current = head;

    while (current != NULL) {
        printf("%p ", current->data);
        current = current->next;
    }

    printf("\n");
}

int main() {
    add_to_dreamscape("Cheshire Cat");
    add_to_dreamscape("Mad Hatter");
    add_to_dreamscape("三月兔");
    add_to_dreamscape("爱丽丝");

    print_dreamscape();

    remove_from_dreamscape("三月兔");

    print_dreamscape();

    return 0;
}