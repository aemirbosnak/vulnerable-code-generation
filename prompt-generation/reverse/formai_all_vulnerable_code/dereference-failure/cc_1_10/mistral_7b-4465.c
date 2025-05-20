//MISTRAL-7B DATASET v1.0 Category: Data structures visualization ; Style: random
#include <stdio.h>
#include <stdlib.h>

typedef struct Node Node;
typedef struct LinkedList LinkedList;

struct Node {
    int key;
    int value;
    Node* next;
};

struct LinkedList {
    int length;
    Node* head;
};

void print_list(LinkedList list) {
    Node* current = list.head;
    printf("List: ");
    while (current != NULL) {
        printf("(%d, %d) -> ", current->key, current->value);
        current = current->next;
    }
    printf("NULL\n");
}

void insert_node(LinkedList* list, int key, int value) {
    Node* new_node = (Node*) malloc(sizeof(Node));
    new_node->key = key;
    new_node->value = value;
    new_node->next = NULL;

    if (list->head == NULL) {
        list->head = new_node;
    } else {
        Node* current = list->head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_node;
    }
    list->length++;
}

int main(void) {
    LinkedList my_list = {0, NULL};

    printf("Initially empty list:\n");
    print_list(my_list);

    insert_node(&my_list, 5, 10);
    print_list(my_list);

    insert_node(&my_list, 3, 15);
    print_list(my_list);

    insert_node(&my_list, 1, 20);
    print_list(my_list);

    return 0;
}