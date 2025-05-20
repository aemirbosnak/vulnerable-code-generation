//MISTRAL-7B DATASET v1.0 Category: Cafe Billing System ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct MenuItem {
    char name[50];
    float price;
} MenuItem;

typedef struct Node {
    MenuItem item;
    struct Node* next;
} Node;

void addMenuItem(Node** head, const char* name, float price) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->item.name, name);
    newNode->item.price = price;
    newNode->next = *head;
    *head = newNode;
}

void printMenu(const Node* head) {
    Node* current = head;
    while (current != NULL) {
        printf("%s: %.2f\n", current->item.name, current->item.price);
        current = current->next;
    }
}

void calculateBill(const Node* head, float* bill) {
    Node* current = head;
    int qty;

    while (current != NULL) {
        printf("How many %s do you want? ", current->item.name);
        scanf("%d", &qty);

        *bill += current->item.price * qty;
        current = current->next;
    }
}

int main() {
    Node* menuHead = NULL;

    addMenuItem(&menuHead, "Cappuccino", 3.50);
    addMenuItem(&menuHead, "Latte", 2.80);
    addMenuItem(&menuHead, "Americano", 2.50);
    addMenuItem(&menuHead, "Espresso", 2.00);

    printMenu(menuHead);

    float bill = 0.0;
    calculateBill(menuHead, &bill);

    printf("Your total bill is: %.2f\n", bill);

    return 0;
}