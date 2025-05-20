//GPT-4o-mini DATASET v1.0 Category: Warehouse Management System ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

#define MAX_ITEMS 100
#define NAME_LENGTH 30
#define WAREHOUSE_CAPACITY 50

typedef struct {
    char name[NAME_LENGTH];
    int quantity;
} Item;

Item warehouse[WAREHOUSE_CAPACITY];
int warehouse_count = 0;
sem_t empty_slots;
sem_t full_slots;

void* add_item(void* arg) {
    Item* new_item = (Item*) arg;
    
    // Wait for an empty slot
    sem_wait(&empty_slots);

    // Simulate processing time
    sleep(rand() % 3 + 1);
    
    // Add item to the warehouse
    warehouse[warehouse_count] = *new_item;
    warehouse_count++;
    
    printf("Added Item: %s, Quantity: %d\n", new_item->name, new_item->quantity);
    
    // Signal that there is a new item
    sem_post(&full_slots);
    return NULL;
}

void* remove_item(void* arg) {
    char* item_name = (char*) arg;
    
    // Wait for a full slot
    sem_wait(&full_slots);
    
    // Simulate processing time
    sleep(rand() % 3 + 1);
    
    for (int i = 0; i < warehouse_count; i++) {
        if (strcmp(warehouse[i].name, item_name) == 0 && warehouse[i].quantity > 0) {
            warehouse[i].quantity--;
            printf("Removed Item: %s, Remaining Quantity: %d\n", warehouse[i].name, warehouse[i].quantity);
            break;
        }
    }

    // Signal that there's an empty slot now
    sem_post(&empty_slots);
    return NULL;
}

int main() {
    srand(time(NULL));
    pthread_t add_thread[10];
    pthread_t remove_thread[10];

    sem_init(&empty_slots, 0, WAREHOUSE_CAPACITY);
    sem_init(&full_slots, 0, 0);

    // Adding items to the warehouse
    for (int i = 0; i < 10; i++) {
        Item* new_item = (Item*) malloc(sizeof(Item));
        snprintf(new_item->name, NAME_LENGTH, "Item%d", i);
        new_item->quantity = rand() % 10 + 1; // Random quantity between 1 and 10

        pthread_create(&add_thread[i], NULL, add_item, (void*) new_item);
    }

    // Removing items from the warehouse
    for (int i = 0; i < 10; i++) {
        char* item_name = (char*) malloc(NAME_LENGTH);
        snprintf(item_name, NAME_LENGTH, "Item%d", rand() % 10);

        pthread_create(&remove_thread[i], NULL, remove_item, (void*) item_name);
    }

    // Join all threads
    for (int i = 0; i < 10; i++) {
        pthread_join(add_thread[i], NULL);
        pthread_join(remove_thread[i], NULL);
    }

    sem_destroy(&empty_slots);
    sem_destroy(&full_slots);

    printf("Final Warehouse State:\n");
    for (int i = 0; i < warehouse_count; i++) {
        printf("%s: %d\n", warehouse[i].name, warehouse[i].quantity);
    }

    return 0;
}