//Gemma-7B DATASET v1.0 Category: Cafe Billing System ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ORDERS 10

typedef struct Order {
    char name[50];
    char item[50];
    int quantity;
    float price;
    struct Order* next;
} Order;

Order* insertOrder(Order* head, char* name, char* item, int quantity, float price) {
    Order* newOrder = (Order*)malloc(sizeof(Order));
    strcpy(newOrder->name, name);
    strcpy(newOrder->item, item);
    newOrder->quantity = quantity;
    newOrder->price = price;
    newOrder->next = NULL;

    if (head == NULL) {
        head = newOrder;
    } else {
        head->next = newOrder;
    }

    return head;
}

void printOrders(Order* head) {
    Order* currentOrder = head;
    while (currentOrder) {
        printf("Name: %s\n", currentOrder->name);
        printf("Item: %s\n", currentOrder->item);
        printf("Quantity: %d\n", currentOrder->quantity);
        printf("Price: %.2f\n", currentOrder->price);
        printf("------------------------\n");
        currentOrder = currentOrder->next;
    }
}

int main() {
    Order* head = NULL;

    insertOrder(head, "John Doe", "Coffee", 2, 3.50);
    insertOrder(head, "Jane Doe", "Tea", 1, 2.00);
    insertOrder(head, "Peter Pan", "Juice", 3, 1.50);

    printOrders(head);

    return 0;
}