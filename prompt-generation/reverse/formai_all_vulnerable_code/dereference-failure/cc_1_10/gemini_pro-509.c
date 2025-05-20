//GEMINI-pro DATASET v1.0 Category: Cafe Billing System ; Style: mind-bending
#include<stdio.h>
#include<stdlib.h>

typedef struct cafe_item {
    char *name;
    float price;
    int quantity;
} cafe_item_t;

typedef struct cafe_order {
    cafe_item_t *items;
    int num_items;
    float total_price;
} cafe_order_t;

void print_menu() {
    printf("Welcome to the Cafe!\n");
    printf("--------------------\n");
    printf("1. Coffee - $2.50\n");
    printf("2. Tea - $2.00\n");
    printf("3. Cake - $3.00\n");
    printf("4. Muffin - $2.50\n");
    printf("5. Croissant - $3.00\n");
}

cafe_order_t *create_order() {
    cafe_order_t *order = malloc(sizeof(cafe_order_t));
    order->items = malloc(sizeof(cafe_item_t));
    order->num_items = 0;
    order->total_price = 0.0;
    return order;
}

void add_item_to_order(cafe_order_t *order, cafe_item_t item) {
    order->items[order->num_items] = item;
    order->num_items++;
    order->total_price += item.price * item.quantity;
}

void print_order(cafe_order_t *order) {
    printf("Your order:\n");
    printf("--------------------\n");
    for (int i = 0; i < order->num_items; i++) {
        printf("%d. %s - $%.2f x %d = $%.2f\n", i + 1, order->items[i].name, order->items[i].price, order->items[i].quantity, order->items[i].price * order->items[i].quantity);
    }
    printf("Total: $%.2f\n", order->total_price);
}

int main() {
    cafe_order_t *order = create_order();
    print_menu();
    int choice;
    while (1) {
        printf("Enter your choice (1-5, 0 to exit): ");
        scanf("%d", &choice);
        if (choice == 0) {
            break;
        } else if (choice < 1 || choice > 5) {
            printf("Invalid choice!\n");
        } else {
            cafe_item_t item;
            switch (choice) {
                case 1:
                    item.name = "Coffee";
                    item.price = 2.50;
                    break;
                case 2:
                    item.name = "Tea";
                    item.price = 2.00;
                    break;
                case 3:
                    item.name = "Cake";
                    item.price = 3.00;
                    break;
                case 4:
                    item.name = "Muffin";
                    item.price = 2.50;
                    break;
                case 5:
                    item.name = "Croissant";
                    item.price = 3.00;
                    break;
            }
            printf("Enter quantity: ");
            scanf("%d", &item.quantity);
            add_item_to_order(order, item);
        }
    }
    print_order(order);
    return 0;
}