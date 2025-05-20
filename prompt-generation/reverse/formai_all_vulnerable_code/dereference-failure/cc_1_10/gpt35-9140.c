//FormAI DATASET v1.0 Category: Memory management ; Style: safe
#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

typedef struct List
{
    Node *head;
    int size;
} List;

List* create_list()
{
    List* list = (List*) malloc(sizeof(List));
    list->head = NULL;
    list->size = 0;
    return list;
}

void delete_list(List* list)
{
    Node* current = list->head;
    while (current != NULL)
    {
        Node* next = current->next;
        free(current);
        current = next;
    }

    free(list);
}

void add_element(List* list, int data)
{
    Node* new_node = (Node*) malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = list->head;
    list->head = new_node;
    list->size++;
}

int get_element(List* list, int index)
{
    if (index >= list->size)
    {
        printf("Index out of range!\n");
        return -1;
    }

    Node* current = list->head;
    for (int i = 0; i < index; i++)
    {
        current = current->next;
    }

    return current->data;
}

int main()
{
    List* list = create_list();

    add_element(list, 3);
    add_element(list, 2);
    add_element(list, 1);

    printf("Element at index 0: %d\n", get_element(list, 0));
    printf("Element at index 1: %d\n", get_element(list, 1));
    printf("Element at index 2: %d\n", get_element(list, 2));

    delete_list(list);

    return 0;
}