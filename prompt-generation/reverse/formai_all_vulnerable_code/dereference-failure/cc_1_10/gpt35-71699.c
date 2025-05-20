//FormAI DATASET v1.0 Category: Stock market tracker ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>

// Struct for holding stock information
typedef struct {
    char* name;
    double price;
    double change;
} Stock;

// Function for creating a new stock object
Stock* newStock(char* name, double price, double change) {
    Stock* stock = (Stock*) malloc(sizeof(Stock));
    
    stock->name = name;
    stock->price = price;
    stock->change = change;
    
    return stock;
}

// Function for updating a stock's information
void updateStock(Stock* stock, double price, double change) {
    stock->price = price;
    stock->change = change;
}

int main() {
    // Create some sample stock objects
    Stock* apple = newStock("AAPL", 150.99, 1.05);
    Stock* microsoft = newStock("MSFT", 245.87, -0.23);
    Stock* tesla = newStock("TSLA", 864.16, 5.32);
    
    // Print out the initial information for each stock
    printf("Initial Stock Information:\n");
    printf("%s - $%.2f (%+.2f%%)\n", apple->name, apple->price, apple->change);
    printf("%s - $%.2f (%+.2f%%)\n", microsoft->name, microsoft->price, microsoft->change);
    printf("%s - $%.2f (%+.2f%%)\n", tesla->name, tesla->price, tesla->change);

    printf("\nUpdating Stock Information...\n\n");
    
    // Update each stock's information
    updateStock(apple, 152.14, 0.89);
    updateStock(microsoft, 246.05, 1.27);
    updateStock(tesla, 879.24, -2.17);
    
    // Print out the updated information for each stock
    printf("Updated Stock Information:\n");
    printf("%s - $%.2f (%+.2f%%)\n", apple->name, apple->price, apple->change);
    printf("%s - $%.2f (%+.2f%%)\n", microsoft->name, microsoft->price, microsoft->change);
    printf("%s - $%.2f (%+.2f%%)\n", tesla->name, tesla->price, tesla->change);
    
    // Free the memory allocated for each stock object
    free(apple);
    free(microsoft);
    free(tesla);
    
    return 0;
}