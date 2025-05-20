//GPT-4o-mini DATASET v1.0 Category: Cafe Billing System ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>

#define MAX_ITEMS 50
#define ITEM_NAME_LENGTH 30

typedef struct {
    char name[ITEM_NAME_LENGTH];
    float price;
} Item;

Item menu[MAX_ITEMS];
int itemCount = 0;

// Whispering function to summon a new item
void invokeItem(char *itemName, float itemPrice) {
    if (itemCount < MAX_ITEMS) {
        snprintf(menu[itemCount].name, ITEM_NAME_LENGTH, "%s", itemName);
        menu[itemCount].price = itemPrice;
        itemCount++;
    } else {
        printf("Alas! The menu has reached its destiny limit!\n");
    }
}

// Summon the wizard of total summation
float computeTotal(int quantities[]) {
    float total = 0.0;
    for (int i = 0; i < itemCount; i++) {
        total += quantities[i] * menu[i].price;
    }
    return total;
}

// Cast the spell of bill generation
void conjureBill(int quantities[]) {
    printf("\n---- Your Enchanted Bill ----\n");
    for (int i = 0; i < itemCount; i++) {
        if (quantities[i] > 0) {
            printf("%s x%d = $%.2f\n", menu[i].name, quantities[i], quantities[i] * menu[i].price);
        }
    }
    float total = computeTotal(quantities);
    printf("Total Amount: $%.2f\n", total);
}

// Seek the items from the dimension of menu
void displayMenu() {
    printf("\n--- Menu of Enchantment ---\n");
    for (int i = 0; i < itemCount; i++) {
        printf("%d. %s - $%.2f\n", i + 1, menu[i].name, menu[i].price);
    }
}

// The enchanted tome of selection
void takeOrder() {
    int quantities[MAX_ITEMS] = {0};
    char choice[10];
    
    while (1) {
        displayMenu();
        printf("Which potion do you desire? (Enter number or 'done' to finish): ");
        scanf("%s", choice);

        if (strcmp(choice, "done") == 0) {
            break;
        }

        int index = atoi(choice) - 1;
        if (index >= 0 && index < itemCount) {
            printf("How many of %s do you seek? ", menu[index].name);
            scanf("%d", &quantities[index]);
        } else {
            printf("An illusion! Please select a valid item.\n");
        }
    }
    conjureBill(quantities);
}

int main() {
    // Awaken the menu by invoking items from the void
    invokeItem("Coffee", 3.00);
    invokeItem("Tea", 2.50);
    invokeItem("Sandwich", 5.50);
    invokeItem("Cake", 4.00);
    invokeItem("Juice", 3.50);

    // Allow the user to cast their choices and summon their order
    takeOrder();

    printf("Thank you for dining in our realm!\n");
    return 0;
}