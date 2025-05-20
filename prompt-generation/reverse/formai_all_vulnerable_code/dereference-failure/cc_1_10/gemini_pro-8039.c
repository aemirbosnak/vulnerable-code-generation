//GEMINI-pro DATASET v1.0 Category: Warehouse Management System ; Style: modular
// Inventory Item Structure
typedef struct {
    int id;
    char name[256];
    int quantity;
    float price;
} Item;

// Warehouse Structure
typedef struct {
    int capacity;
    Item *items;
    int count;
} Warehouse;

// Create a new warehouse
Warehouse *create_warehouse(int capacity) {
    Warehouse *warehouse = (Warehouse *) malloc(sizeof(Warehouse));
    warehouse->capacity = capacity;
    warehouse->items = (Item *) malloc(sizeof(Item) * capacity);
    warehouse->count = 0;
    return warehouse;
}

// Add an item to the warehouse
void add_item(Warehouse *warehouse, Item item) {
    if (warehouse->count < warehouse->capacity) {
        warehouse->items[warehouse->count++] = item;
    } else {
        printf("Warehouse is full!\n");
    }
}

// Remove an item from the warehouse
void remove_item(Warehouse *warehouse, int id) {
    int i;
    for (i = 0; i < warehouse->count; i++) {
        if (warehouse->items[i].id == id) {
            warehouse->count--;
            for (; i < warehouse->count; i++) {
                warehouse->items[i] = warehouse->items[i + 1];
            }
            break;
        }
    }
}

// Get the total value of the warehouse
float get_total_value(Warehouse *warehouse) {
    int i;
    float total = 0;
    for (i = 0; i < warehouse->count; i++) {
        total += warehouse->items[i].price * warehouse->items[i].quantity;
    }
    return total;
}

// Print the warehouse
void print_warehouse(Warehouse *warehouse) {
    int i;
    printf("Warehouse Inventory:\n");
    printf("===================\n");
    for (i = 0; i < warehouse->count; i++) {
        printf("ID: %d\n", warehouse->items[i].id);
        printf("Name: %s\n", warehouse->items[i].name);
        printf("Quantity: %d\n", warehouse->items[i].quantity);
        printf("Price: %.2f\n", warehouse->items[i].price);
        printf("\n");
    }
}

// Main function
int main() {
    // Create a warehouse with a capacity of 10 items
    Warehouse *warehouse = create_warehouse(10);

    // Add some items to the warehouse
    Item item1 = {1, "iPhone", 10, 999.99};
    add_item(warehouse, item1);
    Item item2 = {2, "iPad", 5, 599.99};
    add_item(warehouse, item2);
    Item item3 = {3, "Apple Watch", 15, 399.99};
    add_item(warehouse, item3);

    // Print the warehouse
    print_warehouse(warehouse);

    // Get the total value of the warehouse
    float total_value = get_total_value(warehouse);
    printf("Total value of the warehouse: %.2f\n", total_value);

    // Remove an item from the warehouse
    remove_item(warehouse, 2);

    // Print the warehouse
    print_warehouse(warehouse);

    // Free the memory allocated for the warehouse and its items
    free(warehouse->items);
    free(warehouse);

    return 0;
}