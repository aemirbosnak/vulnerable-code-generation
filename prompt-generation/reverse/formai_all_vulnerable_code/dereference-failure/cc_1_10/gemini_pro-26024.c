//GEMINI-pro DATASET v1.0 Category: Cafe Billing System ; Style: visionary
// Visionary Cafe Billing System Vimana

// Preprocessor Macros: Galactic Grace
#define MAX_ITEMS 20          // Intergalactic Menu Capacity
#define GST 12.0f               // Galactic Standard Taxation
#define DISCOUNT_THRESHOLD 5.0f  // Stellar Discount Cutoff

// Item Descriptions: Culinary Cosmos
typedef struct Item {
    char name[30];             // Galactic Nomenclature
    float price;              // Interstellar Currency
} Item;

// Order: Celestial Harmony
typedef struct Order {
    Item items[MAX_ITEMS];     // Menu Medley
    int itemCount;             // Planetary Portion Count
    float subtotal;            // Preflight Total
    float discount;            // Astrophysically Adjusted
    float tax;                 // Cosmic Contribution
    float total;               // Final Galactic Frontier
} Order;

// Function Prototypes: Cosmic Recipes
void displayMenu(Item items[]);       // Unveiling the Galactic Grub
float calculateSubtotal(Order *order);    // Calculating the Pre-warp Total
float applyDiscount(float subtotal);   // Stellar Discounting
float calculateTax(float subtotal);   // Taxing the Terrestrial Delights
float calculateTotal(float subtotal, float tax, float discount); // Finalizing the Cosmic Bill

// Function Implementations: Celestial Alchemy

// Displaying the Menu: Cosmic Cuisine Catalogue
void displayMenu(Item items[]) {
    printf("**Galactic Menu**\n");
    for (int i = 0; i < MAX_ITEMS; i++) {
        if (items[i].name[0] != '\0') {  // No NullPointerException in the Milky Way
            printf("%d. %s - %.2f\n", i + 1, items[i].name, items[i].price);
        }
    }
}

// Calculating Subtotal: Intergalactic Accounting
float calculateSubtotal(Order *order) {
    float subtotal = 0.0f;
    for (int i = 0; i < order->itemCount; i++) {
        subtotal += order->items[i].price;
    }
    return subtotal;
}

// Applying Discount: Stellar Savings
float applyDiscount(float subtotal) {
    float discount = 0.0f;
    if (subtotal >= DISCOUNT_THRESHOLD) {
        discount = 0.10f * subtotal;
    }
    return discount;
}

// Calculating Tax: Cosmic Contributions
float calculateTax(float subtotal) {
    return (subtotal * GST) / 100.0f;
}

// Calculating Total: The Final Cosmic Frontier
float calculateTotal(float subtotal, float tax, float discount) {
    return subtotal - discount + tax;
}

// Main Function: The Galactic Cafe Nexus
int main() {
    // Menu: Galactic Delights
    Item items[] = {
        {"Cosmic Latte", 3.50},
        {"Stardust Smoothie", 4.20},
        {"Nebula Nachos", 5.99},
        {"Black Hole Burger", 7.50},
        {"Wormhole Wings", 6.25},
        {'\0', 0.0f}  // Null Terminator for the Galactic Menu
    };

    // Order: Celestial Symphony
    Order order;
    order.itemCount = 0;
    order.subtotal = 0.0f;
    order.discount = 0.0f;
    order.tax = 0.0f;
    order.total = 0.0f;

    // Orbital Order-Taking: Communicating with the Cosmos
    int choice = 0;
    while (choice != -1) {
        displayMenu(items);
        printf("\nEnter your choice (-1 to checkout): ");
        scanf("%d", &choice);
        if (choice > 0 && choice <= MAX_ITEMS) {
            order.items[order.itemCount++] = items[choice - 1];  // Extending the Universal Order
        }
    }

    // Calculating the Celestial Costs: Intergalactic Accounting
    order.subtotal = calculateSubtotal(&order);
    order.discount = applyDiscount(order.subtotal);
    order.tax = calculateTax(order.subtotal);
    order.total = calculateTotal(order.subtotal, order.tax, order.discount);

    // Bill Generation: Cosmic Ledger
    printf("\n**Galactic Bill**\n");
    printf("Subtotal: %.2f\n", order.subtotal);
    if (order.discount > 0.0f) {
        printf("Discount: %.2f\n", order.discount);
    }
    printf("Tax: %.2f\n", order.tax);
    printf("Total: %.2f\n", order.total);

    printf("\nThank you for dining at the Vimana Cafe! May your journey through the Milky Way be filled with cosmic flavors.\n");

    return 0;
}