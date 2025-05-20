//Gemma-7B DATASET v1.0 Category: Cafe Billing System ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ORDERS 10

typedef struct Order {
    char name[50];
    int quantity;
    float price;
    struct Order* next;
} Order;

Order* head = NULL;

void addOrder(char* name, int quantity, float price) {
    Order* newOrder = (Order*)malloc(sizeof(Order));
    strcpy(newOrder->name, name);
    newOrder->quantity = quantity;
    newOrder->price = price;
    newOrder->next = NULL;

    if (head == NULL) {
        head = newOrder;
    } else {
        Order* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newOrder;
    }
}

void printOrder() {
    Order* temp = head;
    printf("Orders:\n");
    while (temp) {
        printf("%s - %d - %.2f\n", temp->name, temp->quantity, temp->price);
        temp = temp->next;
    }
}

void calculateTotal() {
    Order* temp = head;
    float total = 0;
    while (temp) {
        total += temp->quantity * temp->price;
        temp = temp->next;
    }
    printf("Total cost: %.2f\n", total);
}

int main() {
    addOrder("Coffee", 2, 2.50);
    addOrder("Tea", 1, 1.20);
    addOrder("Juice", 3, 1.80);

    printOrder();
    calculateTotal();

    return 0;
}