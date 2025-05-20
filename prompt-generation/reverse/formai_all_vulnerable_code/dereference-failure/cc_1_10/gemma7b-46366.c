//Gemma-7B DATASET v1.0 Category: Cafe Billing System ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ORDERS 100

typedef struct Order {
    char name[50];
    char item[50];
    int quantity;
    float price;
    struct Order* next;
} Order;

Order* head = NULL;

void addOrder(char* name, char* item, int quantity, float price) {
    Order* newOrder = malloc(sizeof(Order));
    strcpy(newOrder->name, name);
    strcpy(newOrder->item, item);
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

void printOrders() {
    Order* temp = head;
    while (temp) {
        printf("%s - %s, %d, %.2f\n", temp->name, temp->item, temp->quantity, temp->price);
        temp = temp->next;
    }
}

void calculateTotal() {
    float total = 0.0;
    Order* temp = head;
    while (temp) {
        total += temp->quantity * temp->price;
        temp = temp->next;
    }
    printf("Total: %.2f\n", total);
}

int main() {
    addOrder("John Doe", "Coffee", 2, 3.50);
    addOrder("Jane Doe", "Tea", 1, 2.00);
    addOrder("Bill Smith", "Juice", 3, 4.00);

    printOrders();
    calculateTotal();

    return 0;
}