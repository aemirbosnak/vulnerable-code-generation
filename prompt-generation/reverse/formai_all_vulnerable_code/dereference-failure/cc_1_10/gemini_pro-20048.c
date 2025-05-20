//GEMINI-pro DATASET v1.0 Category: Medical Store Management System ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// Structure to represent a medical store item
typedef struct Item {
  char name[50];
  int quantity;
  float price;
} Item;

// Global variables
Item inventory[100];  // Array to store inventory items
int num_items = 0;    // Number of items in inventory
pthread_mutex_t lock; // Mutex to protect critical section

// Function to add an item to the inventory
void add_item(Item item) {
  pthread_mutex_lock(&lock);
  inventory[num_items++] = item;
  pthread_mutex_unlock(&lock);
}

// Function to remove an item from the inventory
void remove_item(char* name) {
  pthread_mutex_lock(&lock);
  for (int i = 0; i < num_items; i++) {
    if (strcmp(inventory[i].name, name) == 0) {
      inventory[i] = inventory[num_items - 1];
      num_items--;
      break;
    }
  }
  pthread_mutex_unlock(&lock);
}

// Function to sell an item from the inventory
void sell_item(char* name, int quantity) {
  pthread_mutex_lock(&lock);
  for (int i = 0; i < num_items; i++) {
    if (strcmp(inventory[i].name, name) == 0) {
      if (inventory[i].quantity >= quantity) {
        inventory[i].quantity -= quantity;
        break;
      } else {
        printf("Insufficient quantity of %s in stock.\n", name);
      }
    }
  }
  pthread_mutex_unlock(&lock);
}

// Function to print the inventory
void print_inventory() {
  pthread_mutex_lock(&lock);
  printf("Inventory:\n");
  for (int i = 0; i < num_items; i++) {
    printf("%s %d %.2f\n", inventory[i].name, inventory[i].quantity, inventory[i].price);
  }
  pthread_mutex_unlock(&lock);
}

// Thread function to simulate customer requests
void* customer_thread(void* arg) {
  int num_requests = rand() % 10;
  for (int i = 0; i < num_requests; i++) {
    int operation = rand() % 3;
    char* name = (char*) malloc(50);
    int quantity = rand() % 10;
    switch (operation) {
      case 0:
        printf("Adding item %s to inventory.\n", name);
        Item item = {name, quantity, rand() % 100};
        add_item(item);
        break;
      case 1:
        printf("Removing item %s from inventory.\n", name);
        remove_item(name);
        break;
      case 2:
        printf("Selling %d units of item %s from inventory.\n", quantity, name);
        sell_item(name, quantity);
        break;
    }
    sleep(1);
  }
  return NULL;
}

int main() {
  // Initialize the mutex
  pthread_mutex_init(&lock, NULL);

  // Create a pool of threads to simulate customer requests
  int num_threads = 10;
  pthread_t threads[num_threads];
  for (int i = 0; i < num_threads; i++) {
    pthread_create(&threads[i], NULL, customer_thread, NULL);
  }

  // Join the threads
  for (int i = 0; i < num_threads; i++) {
    pthread_join(threads[i], NULL);
  }

  // Print the inventory
  print_inventory();

  // Destroy the mutex
  pthread_mutex_destroy(&lock);

  return 0;
}