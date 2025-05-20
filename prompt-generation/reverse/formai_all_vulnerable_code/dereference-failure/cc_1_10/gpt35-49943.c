//FormAI DATASET v1.0 Category: Product Inventory System ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_PRODUCTS 10

// Define a struct for each product
typedef struct {
    int id;
    char* name;
    int stock;
} Product;

// Declare the array of products and initialize it with some initial values
Product products[NUM_PRODUCTS] = {
    {1, "Mouse", 20},
    {2, "Keyboard", 15},
    {3, "Monitor", 10},
    {4, "Headphones", 30},
    {5, "Speakers", 25},
    {6, "Printer", 5},
    {7, "Scanner", 3},
    {8, "Webcam", 8},
    {9, "Router", 22},
    {10, "Switch", 18}
};

// Declare a mutex for synchronizing access to the products array
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

// Define the function that will be run by each thread
void* update_inventory(void* arg) {
    // Cast the argument to an integer representing the index of the product to be updated
    int index = *((int*) arg);

    // Generate a random number between 1 and 10 to simulate the number of items sold or restocked
    int quantity = rand() % 10 + 1;

    // Acquire the mutex before accessing the products array
    pthread_mutex_lock(&mutex);

    // Update the stock of the product
    products[index].stock += quantity;

    // Print a message to indicate the update
    printf("Updated inventory for product %d (%s). Stock: %d\n", products[index].id, products[index].name, products[index].stock);

    // Release the mutex before exiting the thread
    pthread_mutex_unlock(&mutex);

    // Exit the thread
    pthread_exit(NULL);
}

int main() {
    // Declare an array of threads
    pthread_t threads[NUM_PRODUCTS];

    // Loop over the products array and create a thread for each product
    for (int i = 0; i < NUM_PRODUCTS; i++) {
        // Create a new integer to serve as the argument to the thread
        int* arg = malloc(sizeof(*arg));
        *arg = i;

        // Create the thread for the current product and pass in the index of the product as the argument
        pthread_create(&threads[i], NULL, update_inventory, arg);
    }

    // Join all the threads before exiting
    for (int i = 0; i < NUM_PRODUCTS; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}