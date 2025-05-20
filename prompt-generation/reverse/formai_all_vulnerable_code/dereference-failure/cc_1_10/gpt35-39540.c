//FormAI DATASET v1.0 Category: Data structures visualization ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

typedef struct node {
    int value;
    struct node *next;
} Node;

typedef struct list {
    Node *head;
    int size;
} List;

List* create_list() {
    List *new_list = malloc(sizeof(List));
    new_list->head = NULL;
    new_list->size = 0;
    return new_list;
}

void insert(List *lst, int value) {
    Node *new_node = malloc(sizeof(Node));
    new_node->value = value;
    new_node->next = NULL;

    if (lst->size == MAX_SIZE) {
        printf("List is already full!\n");
        free(new_node);
        return;
    }

    if (lst->head == NULL) {
        lst->head = new_node;
    } else {
        Node *current_node = lst->head;
        while (current_node->next != NULL) {
            current_node = current_node->next;
        }
        current_node->next = new_node;
    }

    lst->size++;
}

void delete(List *lst, int value) {
    if (lst->head == NULL) {
        printf("List is empty!\n");
        return;
    }

    if (lst->head->value == value) {
        Node *temp = lst->head;
        lst->head = lst->head->next;
        free(temp);
        lst->size--;
        return;
    }

    Node *current_node = lst->head;
    while (current_node->next != NULL && current_node->next->value != value) {
        current_node = current_node->next;
    }

    if (current_node->next == NULL) {
        printf("Value not found in list!\n");
        return;
    }

    Node *temp = current_node->next;
    current_node->next = current_node->next->next;
    free(temp);
    lst->size--;
}

void print(List *lst) {
    printf("Size: %d\n", lst->size);
    printf("Values: ");
    Node *current_node = lst->head;
    while (current_node != NULL) {
        printf("%d ", current_node->value);
        current_node = current_node->next;
    }
    printf("\n");
}

int main() {
    List *my_list = create_list();

    insert(my_list, 10);
    insert(my_list, 20);
    insert(my_list, 30);
    insert(my_list, 40);
    insert(my_list, 50);
    insert(my_list, 60);
    insert(my_list, 70);
    insert(my_list, 80);
    insert(my_list, 90);
    insert(my_list, 100);
    insert(my_list, 110);

    print(my_list);

    delete(my_list, 20);
    delete(my_list, 110);
    delete(my_list, 60);

    print(my_list);

    delete(my_list, 200);

    return 0;
}