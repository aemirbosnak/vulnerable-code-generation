//FormAI DATASET v1.0 Category: Data mining ; Style: Cyberpunk
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct cyber_node {
    int data;
    struct cyber_node* next;
};

struct cyber_list {
    struct cyber_node* head;
    struct cyber_node* tail;
    int size;
};

struct cyber_list* create_cyber_list() {
    struct cyber_list* list = (struct cyber_list*) malloc(sizeof(struct cyber_list));
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
    return list;
}

void add_to_cyber_list(struct cyber_list* list, int data) {
    struct cyber_node* new_node = (struct cyber_node*) malloc(sizeof(struct cyber_node));
    new_node->data = data;
    new_node->next = NULL;
    if (list->head == NULL) {
        list->head = new_node;
        list->tail = new_node;
    }
    else {
        list->tail->next = new_node;
        list->tail = new_node;
    }
    list->size++;
}

void print_cyber_list(struct cyber_list* list) {
    struct cyber_node* curr = list->head;
    while (curr != NULL) {
        printf("%d ", curr->data);
        curr = curr->next;
    }
}

int main() {
    printf("Welcome to the Cyber Data Mining Example!\n");
    struct cyber_list* list = create_cyber_list();
    add_to_cyber_list(list, 42);
    add_to_cyber_list(list, 1337);
    add_to_cyber_list(list, 666);
    printf("Here is the data we have collected:\n");
    print_cyber_list(list);
    printf("\nNow let's analyze the data...\n");
    int sum = 0;
    struct cyber_node* curr = list->head;
    while (curr != NULL) {
        sum += curr->data;
        curr = curr->next;
    }
    printf("The sum of the data is %d.\n", sum);
    printf("Thanks for using our Cyber Data Mining program!\n");
    return 0;
}