//GPT-4o-mini DATASET v1.0 Category: Product Inventory System ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>

#define MAX_PRODUCTS 100
#define NAME_LENGTH 50
#define DESCRIPTION_LENGTH 200

typedef struct {
    int id;
    char name[NAME_LENGTH];
    char description[DESCRIPTION_LENGTH];
    int quantity;
} Product;

Product inventory[MAX_PRODUCTS];
int productCount = 0;
pthread_mutex_t lock;

void* addProduct(void* arg) {
    Product* newProduct = (Product*)arg;

    pthread_mutex_lock(&lock);
    if (productCount < MAX_PRODUCTS) {
        inventory[productCount] = *newProduct;
        productCount++;
        printf("Added Product - ID: %d, Name: %s, Quantity: %d\n", newProduct->id, newProduct->name, newProduct->quantity);
    } else {
        printf("Inventory full! Cannot add product %s\n", newProduct->name);
    }
    pthread_mutex_unlock(&lock);
    return NULL;
}

void* viewInventory(void* arg) {
    pthread_mutex_lock(&lock);
    printf("Current Inventory:\n");
    for (int i = 0; i < productCount; i++) {
        printf("ID: %d, Name: %s, Description: %s, Quantity: %d\n", inventory[i].id, inventory[i].name, inventory[i].description, inventory[i].quantity);
    }
    pthread_mutex_unlock(&lock);
    return NULL;
}

void* updateProduct(void* arg) {
    int* productId = (int*)arg;
    int found = 0;

    pthread_mutex_lock(&lock);
    for (int i = 0; i < productCount; i++) {
        if (inventory[i].id == *productId) {
            inventory[i].quantity += 10; // increment quantity for demo
            printf("Updated Product ID: %d, New Quantity: %d\n", inventory[i].id, inventory[i].quantity);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Product with ID: %d not found.\n", *productId);
    }
    pthread_mutex_unlock(&lock);
    return NULL;
}

void* removeProduct(void* arg) {
    int* productId = (int*)arg;
    int index = -1;

    pthread_mutex_lock(&lock);
    for (int i = 0; i < productCount; i++) {
        if (inventory[i].id == *productId) {
            index = i;
            break;
        }
    }

    if (index != -1) {
        printf("Removing Product ID: %d, Name: %s\n", inventory[index].id, inventory[index].name);
        for (int i = index; i < productCount - 1; i++) {
            inventory[i] = inventory[i + 1];
        }
        productCount--;
    } else {
        printf("Product with ID: %d not found.\n", *productId);
    }
    pthread_mutex_unlock(&lock);
    return NULL;
}

void createProduct(int id, const char* name, const char* description, int quantity) {
    Product* newProduct = (Product*)malloc(sizeof(Product));
    newProduct->id = id;
    strncpy(newProduct->name, name, NAME_LENGTH);
    strncpy(newProduct->description, description, DESCRIPTION_LENGTH);
    newProduct->quantity = quantity;

    pthread_t thread;
    pthread_create(&thread, NULL, addProduct, newProduct);
    pthread_detach(thread);
}

int main() {
    pthread_mutex_init(&lock, NULL);

    createProduct(1, "Product A", "Description for Product A", 20);
    createProduct(2, "Product B", "Description for Product B", 30);
    createProduct(3, "Product C", "Description for Product C", 50);
    
    sleep(1); // Give time for adding products
    
    pthread_t viewThread;
    pthread_create(&viewThread, NULL, viewInventory, NULL);
    pthread_detach(viewThread);
    
    int updateId = 2;
    pthread_t updateThread;
    pthread_create(&updateThread, NULL, updateProduct, &updateId);
    pthread_detach(updateThread);

    sleep(1); // Give time for updating product
    
    int removeId = 1;
    pthread_t removeThread;
    pthread_create(&removeThread, NULL, removeProduct, &removeId);
    pthread_detach(removeThread);

    // Final sleep to ensure all operations are likely completed
    sleep(2); 
    pthread_mutex_destroy(&lock);
    
    return 0;
}