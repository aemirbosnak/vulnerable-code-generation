//Falcon-180B DATASET v1.0 Category: Cafe Billing System ; Style: invasive
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char name[50];
    int quantity;
    float price;
} Item;

typedef struct {
    char name[50];
    int quantity;
    float price;
} Order;

int main() {
    int n;
    printf("Enter the number of items: ");
    scanf("%d", &n);

    Item menu[n];
    printf("Enter the items:\n");
    for (int i = 0; i < n; i++) {
        printf("Name: ");
        scanf("%s", menu[i].name);
        printf("Quantity: ");
        scanf("%d", &menu[i].quantity);
        printf("Price: ");
        scanf("%f", &menu[i].price);
    }

    int m;
    printf("Enter the number of orders: ");
    scanf("%d", &m);

    Order order[m];
    printf("Enter the orders:\n");
    for (int i = 0; i < m; i++) {
        printf("Name: ");
        scanf("%s", order[i].name);
        printf("Quantity: ");
        scanf("%d", &order[i].quantity);
        printf("Price: ");
        scanf("%f", &order[i].price);
    }

    float total = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (strcmp(order[i].name, menu[j].name) == 0) {
                total += order[i].quantity * menu[j].price;
                break;
            }
        }
    }

    printf("Total: $%.2f\n", total);

    return 0;
}