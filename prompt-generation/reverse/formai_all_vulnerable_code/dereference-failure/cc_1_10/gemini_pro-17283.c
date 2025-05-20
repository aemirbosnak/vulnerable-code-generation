//GEMINI-pro DATASET v1.0 Category: Warehouse Management System ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of items in the warehouse
#define MAX_ITEMS 100

// Define the structure of an item
typedef struct item {
    char *name;
    int quantity;
    float price;
} item;

// Define the structure of the warehouse
typedef struct warehouse {
    item items[MAX_ITEMS];
    int num_items;
} warehouse;

// Create a new warehouse
warehouse *create_warehouse() {
    warehouse *w = malloc(sizeof(warehouse));
    w->num_items = 0;
    return w;
}

// Add an item to the warehouse
void add_item(warehouse *w, item *i) {
    if (w->num_items < MAX_ITEMS) {
        w->items[w->num_items] = *i;
        w->num_items++;
    } else {
        printf("The warehouse is full!\n");
    }
}

// Remove an item from the warehouse
void remove_item(warehouse *w, char *name) {
    int i;
    for (i = 0; i < w->num_items; i++) {
        if (strcmp(w->items[i].name, name) == 0) {
            w->items[i] = w->items[w->num_items - 1];
            w->num_items--;
            break;
        }
    }
}

// Find an item in the warehouse
item *find_item(warehouse *w, char *name) {
    int i;
    for (i = 0; i < w->num_items; i++) {
        if (strcmp(w->items[i].name, name) == 0) {
            return &w->items[i];
        }
    }
    return NULL;
}

// Print the contents of the warehouse
void print_warehouse(warehouse *w) {
    int i;
    for (i = 0; i < w->num_items; i++) {
        printf("%s %d %f\n", w->items[i].name, w->items[i].quantity, w->items[i].price);
    }
}

//Sherlock the Sleuth
void SherlockTheSleuth(warehouse w){
    //let's say there is only one item in stock
    if(w.num_items == 1){
        printf("The warehouse is almost empty, it seems someone has been pilfering the goods.");
    }
    //let's say the quantity of one of the items is 0
    int i;
    for (i = 0; i < w.num_items; i++){
        if(w.items[i].quantity == 0){
            printf("It seems like someone has stolen the %s.", w.items[i].name);
        }
    }
}

int main() {
    // Create a new warehouse
    warehouse *my_warehouse = create_warehouse();

    // Add some items to the warehouse
    item item1 = {"Apple", 10, 1.0};
    add_item(my_warehouse, &item1);
    item item2 = {"Orange", 5, 1.5};
    add_item(my_warehouse, &item2);
    item item3 = {"Banana", 15, 2.0};
    add_item(my_warehouse, &item3);

    
    //Sherlock is on the case
    SherlockTheSleuth(*my_warehouse);
    
    // Print the contents of the warehouse
    print_warehouse(my_warehouse);

    // Free the memory allocated for the warehouse
    free(my_warehouse);

    return 0;
}