//FormAI DATASET v1.0 Category: Data structures visualization ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/* Surreal Data Structure Visualization */

typedef struct node {
    int data;
    struct node *next;
} Node;

typedef struct {
    Node *head;
    Node *tail;
} List;

void init(List* list) {
    list->head = NULL;
    list->tail = NULL;
}

void add(List* list, int data) {
    Node* node = (Node*) malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    if (list->head == NULL) {
        list->head = node;
    } else {
        list->tail->next = node;
    }
    list->tail = node;
}

void remove_head(List* list) {
    if (list->head == NULL) {
        return;
    }
    Node* new_head = list->head->next;
    free(list->head);
    list->head = new_head;
    if (list->head == NULL) {
        list->tail = NULL;
    }
}

void print(List* list) {
    sleep(1);
    system("clear");
    printf("     _____\n");
    printf("    /     \\\n");
    printf("   | %4d  |\n", list->head->data);
    printf("    \\_____/\n");
    Node* node = list->head->next;
    while (node != NULL) {
        printf("        |\n");
        printf("        | %4d\n", node->data);
        printf("        |\n");
        printf("     ___V___\n");
        node = node->next;
    }
    printf("\n");
}

int main() {
    List list;
    init(&list);
    add(&list, 5);
    add(&list, 3);
    add(&list, 9);
    add(&list, 7);
    add(&list, 1);
    add(&list, 10);
    add(&list, 8);
    add(&list, 2);
    add(&list, 4);
    while (list.head != NULL) {
        print(&list);
        remove_head(&list);
    }
    printf("List is empty.\n");
    return 0;
}