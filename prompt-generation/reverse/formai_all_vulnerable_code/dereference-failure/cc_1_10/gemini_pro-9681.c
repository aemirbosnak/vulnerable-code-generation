//GEMINI-pro DATASET v1.0 Category: Cafe Billing System ; Style: Linus Torvalds
// Ain't nobody got time for fancy comments, just caffeine!

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// I'm a coffee aficionado, not a mathematician!
typedef enum {
    ESPRESSO,
    CAPPUCCINO,
    LATTE,
    AMERICANO,
    TURKISH
} Coffee;

// A little union action to save some precious bytes
typedef union {
    char *name;
    Coffee coffee;
} Item;

// Even Linus can't resist a good struct
typedef struct {
    Item items[100];
    int count;
    int total;
} Order;

// The menu, straight from the heavens
const char *menu[] = {
    "Espresso",
    "Cappuccino",
    "Latte",
    "Americano",
    "Turkish"
};

// The prices, in the universal currency of caffeine
const int prices[] = {
    2,
    3,
    4,
    3,
    5
};

// Coffee time!
int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <order>\n", argv[0]);
        return 1;
    }

    // Parse the order
    Order order;
    order.count = 0;
    order.total = 0;
    for (int i = 1; i < argc; i++) {
        int coffee;
        for (coffee = 0; coffee < 5; coffee++) {
            if (strcmp(argv[i], menu[coffee]) == 0) {
                break;
            }
        }
        if (coffee == 5) {
            printf("Unknown coffee: %s\n", argv[i]);
            return 1;
        }
        order.items[order.count].coffee = coffee;
        order.count++;
        order.total += prices[coffee];
    }

    // Print the receipt
    printf("Your order:\n");
    for (int i = 0; i < order.count; i++) {
        printf("%s x %d\n", menu[order.items[i].coffee], prices[order.items[i].coffee]);
    }
    printf("Total: %d\n", order.total);

    return 0;
}