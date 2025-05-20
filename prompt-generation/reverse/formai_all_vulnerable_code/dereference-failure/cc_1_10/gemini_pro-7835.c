//GEMINI-pro DATASET v1.0 Category: Memory management ; Style: real-life
#include <stdio.h>
#include <stdlib.h>

// Real-life example: Managing a grocery list

typedef struct GroceryItem {
    char *name;
    int quantity;
} GroceryItem;

// Function to create a new grocery item
GroceryItem *createGroceryItem(char *name, int quantity) {
    GroceryItem *item = malloc(sizeof(GroceryItem));
    if (item == NULL) {
        fprintf(stderr, "Error: Failed to allocate memory for grocery item.\n");
        return NULL;
    }
    
    item->name = malloc(strlen(name) + 1);
    if (item->name == NULL) {
        free(item);
        fprintf(stderr, "Error: Failed to allocate memory for grocery item name.\n");
        return NULL;
    }
    
    strcpy(item->name, name);
    item->quantity = quantity;
    
    return item;
}

// Function to add an item to a grocery list
int addGroceryItem(GroceryItem **list, int *size, GroceryItem *item) {
    *list = realloc(*list, (*size + 1) * sizeof(GroceryItem));
    if (*list == NULL) {
        fprintf(stderr, "Error: Failed to allocate memory for grocery list.\n");
        return -1;
    }
    
    (*list)[*size++] = *item;
    return 0;
}

// Function to print a grocery list
void printGroceryList(GroceryItem *list, int size) {
    printf("Grocery List:\n");
    for (int i = 0; i < size; i++) {
        printf("%s: %d\n", list[i].name, list[i].quantity);
    }
}

// Function to free the memory allocated for a grocery item
void freeGroceryItem(GroceryItem *item) {
    if (item != NULL) {
        free(item->name);
        free(item);
    }
}

// Function to free the memory allocated for a grocery list
void freeGroceryList(GroceryItem *list, int size) {
    for (int i = 0; i < size; i++) {
        freeGroceryItem(&list[i]);
    }
    free(list);
}

int main() {
    // Create a grocery list
    GroceryItem *list = NULL;
    int size = 0;
    
    // Add some items to the list
    GroceryItem item1 = {"Milk", 2};
    addGroceryItem(&list, &size, &item1);
    
    GroceryItem item2 = {"Bread", 1};
    addGroceryItem(&list, &size, &item2);
    
    GroceryItem item3 = {"Eggs", 6};
    addGroceryItem(&list, &size, &item3);
    
    // Print the grocery list
    printGroceryList(list, size);
    
    // Free the memory allocated for the grocery list
    freeGroceryList(list, size);
    
    return 0;
}