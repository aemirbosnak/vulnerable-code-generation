//GEMINI-pro DATASET v1.0 Category: Medical Store Management System ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// Define the structure of a medical item
typedef struct {
    int id;
    char name[50];
    int quantity;
    float price;
} MedicalItem;

// Define the structure of a medical store
typedef struct {
    MedicalItem *items;
    int num_items;
} MedicalStore;

// Define the structure of a thread argument
typedef struct {
    MedicalStore *store;
    int customer_id;
} ThreadArg;

// Function to create a new medical store
MedicalStore *create_store(int num_items) {
    MedicalStore *store = malloc(sizeof(MedicalStore));
    store->items = malloc(sizeof(MedicalItem) * num_items);
    store->num_items = num_items;
    return store;
}

// Function to add a new medical item to the store
void add_item(MedicalStore *store, MedicalItem item) {
    store->items[store->num_items++] = item;
}

// Function to get the index of a medical item in the store
int get_item_index(MedicalStore *store, int item_id) {
    for (int i = 0; i < store->num_items; i++) {
        if (store->items[i].id == item_id) {
            return i;
        }
    }
    return -1;
}

// Function to buy a medical item from the store
void buy_item(MedicalStore *store, ThreadArg *arg) {
    int item_id = arg->customer_id;
    int quantity = 1;

    // Get the index of the item in the store
    int item_index = get_item_index(store, item_id);

    // Check if the item is in stock
    if (item_index == -1) {
        printf("Item %d is not in stock.\n", item_id);
        return;
    }

    // Check if the store has enough quantity of the item
    if (quantity > store->items[item_index].quantity) {
        printf("Sorry, there is not enough quantity of item %d in stock.\n", item_id);
        return;
    }

    // Update the store's inventory
    store->items[item_index].quantity -= quantity;

    // Print the receipt
    printf("Customer %d bought %d unit(s) of item %d for $%.2f.\n", arg->customer_id, quantity, item_id, quantity * store->items[item_index].price);
}

// Function to run the medical store
void run_store(MedicalStore *store, int num_customers) {
    // Create a thread pool
    pthread_t *threads = malloc(sizeof(pthread_t) * num_customers);

    // Create a thread argument for each customer
    ThreadArg *args = malloc(sizeof(ThreadArg) * num_customers);
    for (int i = 0; i < num_customers; i++) {
        args[i].store = store;
        args[i].customer_id = i + 1;
    }

    // Create a thread for each customer
    for (int i = 0; i < num_customers; i++) {
        pthread_create(&threads[i], NULL, (void *)&buy_item, &args[i]);
    }

    // Join all the threads
    for (int i = 0; i < num_customers; i++) {
        pthread_join(threads[i], NULL);
    }

    // Free the allocated memory
    free(threads);
    free(args);
}

// Main function
int main() {
    // Create a new medical store
    MedicalStore *store = create_store(5);

    // Add some medical items to the store
    add_item(store, (MedicalItem){1, "Aspirin", 100, 1.00});
    add_item(store, (MedicalItem){2, "Ibuprofen", 50, 2.00});
    add_item(store, (MedicalItem){3, "Acetaminophen", 75, 3.00});
    add_item(store, (MedicalItem){4, "Loratadine", 25, 4.00});
    add_item(store, (MedicalItem){5, "Cetirizine", 15, 5.00});

    // Run the medical store
    run_store(store, 10);

    // Free the allocated memory
    free(store->items);
    free(store);

    return 0;
}