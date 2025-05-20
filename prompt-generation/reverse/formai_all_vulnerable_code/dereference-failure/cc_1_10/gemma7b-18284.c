//Gemma-7B DATASET v1.0 Category: Warehouse Management System ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100

typedef struct Item {
    char name[50];
    int quantity;
    float price;
    struct Item* next;
} Item;

Item* insertItem(Item* head) {
    Item* newNode = (Item*)malloc(sizeof(Item));
    scanf("%s", newNode->name);
    scanf("%d", &newNode->quantity);
    scanf("%f", &newNode->price);

    if (head == NULL) {
        head = newNode;
    } else {
        newNode->next = head;
        head = newNode;
    }

    return head;
}

void printItems(Item* head) {
    while (head) {
        printf("%s - %d - %.2f\n", head->name, head->quantity, head->price);
        head = head->next;
    }
}

int main() {
    Item* head = NULL;

    printf("Enter command (add/print): ");
    char command;
    scanf("%c", &command);

    switch (command) {
        case 'a':
            head = insertItem(head);
            break;
        case 'p':
            printItems(head);
            break;
        default:
            printf("Invalid command.\n");
    }

    return 0;
}