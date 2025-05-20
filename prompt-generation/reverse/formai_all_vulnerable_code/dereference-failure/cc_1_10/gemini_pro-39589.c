//GEMINI-pro DATASET v1.0 Category: Stock market tracker ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Stock {
    char *name;
    double price;
    double volume;
} Stock;

typedef struct Node {
    Stock *stock;
    struct Node *next;
} Node;

typedef struct LinkedList {
    Node *head;
    Node *tail;
    int size;
} LinkedList;

LinkedList *createLinkedList() {
    LinkedList *list = malloc(sizeof(LinkedList));
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
    return list;
}

void addStock(LinkedList *list, Stock *stock) {
    Node *node = malloc(sizeof(Node));
    node->stock = stock;
    node->next = NULL;
    if (list->head == NULL) {
        list->head = node;
        list->tail = node;
    } else {
        list->tail->next = node;
        list->tail = node;
    }
    list->size++;
}

void printLinkedList(LinkedList *list) {
    Node *node = list->head;
    while (node != NULL) {
        printf("%s: $%.2f\n", node->stock->name, node->stock->price);
        node = node->next;
    }
}

void freeLinkedList(LinkedList *list) {
    Node *node = list->head;
    while (node != NULL) {
        Node *next = node->next;
        free(node->stock->name);
        free(node->stock);
        free(node);
        node = next;
    }
    free(list);
}

int main() {
    LinkedList *list = createLinkedList();

    Stock *stock1 = malloc(sizeof(Stock));
    stock1->name = malloc(strlen("Apple") + 1);
    strcpy(stock1->name, "Apple");
    stock1->price = 100.00;
    stock1->volume = 10000000.00;
    addStock(list, stock1);

    Stock *stock2 = malloc(sizeof(Stock));
    stock2->name = malloc(strlen("Google") + 1);
    strcpy(stock2->name, "Google");
    stock2->price = 120.00;
    stock2->volume = 5000000.00;
    addStock(list, stock2);

    Stock *stock3 = malloc(sizeof(Stock));
    stock3->name = malloc(strlen("Microsoft") + 1);
    strcpy(stock3->name, "Microsoft");
    stock3->price = 110.00;
    stock3->volume = 4000000.00;
    addStock(list, stock3);

    printLinkedList(list);

    freeLinkedList(list);

    return 0;
}