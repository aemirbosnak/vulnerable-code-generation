//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdint.h>
#include <time.h>
#include <math.h>
#include <unistd.h>
#include <sys/time.h>
#include <pthread.h>

typedef struct {
    char *name;
    double price;
    int stock;
} medicine;

typedef struct {
    medicine *medicines;
    int size;
    int capacity;
} medicine_list;

void init(medicine_list *list, int capacity) {
    list->medicines = malloc(capacity * sizeof(medicine));
    list->size = 0;
    list->capacity = capacity;
}

void destroy(medicine_list *list) {
    free(list->medicines);
}

void add_medicine(medicine_list *list, medicine *med) {
    if (list->size >= list->capacity) {
        list->capacity *= 2;
        list->medicines = realloc(list->medicines, list->capacity * sizeof(medicine));
    }
    memcpy(&list->medicines[list->size++], med, sizeof(medicine));
}

bool remove_medicine(medicine_list *list, char *name) {
    bool removed = false;
    for (int i = 0; i < list->size; i++) {
        if (strcmp(list->medicines[i].name, name) == 0) {
            list->size--;
            memcpy(&list->medicines[i], &list->medicines[list->size], sizeof(medicine));
            removed = true;
            break;
        }
    }
    return removed;
}

medicine *find_medicine(medicine_list *list, char *name) {
    for (int i = 0; i < list->size; i++) {
        if (strcmp(list->medicines[i].name, name) == 0) {
            return &list->medicines[i];
        }
    }
    return NULL;
}

void print_medicines(medicine_list *list) {
    printf("\n%-20s | %10s | %10s\n", "Name", "Price", "Stock");
    printf("----------------------------------------------\n");
    for (int i = 0; i < list->size; i++) {
        printf("%-20s | %10.2f | %10d\n",
            list->medicines[i].name,
            list->medicines[i].price,
            list->medicines[i].stock);
    }
    printf("\n");
}

medicine_list inventory;
pthread_mutex_t inventory_lock;

void *customer_entry(void *arg) {
    char *name = (char *) arg;
    printf("%s entering the store.\n", name);
    pthread_mutex_lock(&inventory_lock);
    printf("%s is browsing the inventory.\n", name);
    print_medicines(&inventory);
    // pretend the customer buys something
    int medicine_idx = rand() % inventory.size;
    inventory.medicines[medicine_idx].stock--;
    printf("%s bought 1 unit of %s.\n", name, inventory.medicines[medicine_idx].name);
    pthread_mutex_unlock(&inventory_lock);
    printf("%s leaves the store.\n", name);
    pthread_exit(NULL);
}

int main() {
    pthread_mutex_init(&inventory_lock, NULL);
    init(&inventory, 10);
    medicine med1 = {"Paracetamol", 2.5, 50};
    medicine med2 = {"Ibuprofen", 3.5, 30};
    medicine med3 = {"Aspirin", 1.5, 20};
    add_medicine(&inventory, &med1);
    add_medicine(&inventory, &med2);
    add_medicine(&inventory, &med3);

    // simulate customer entry using threads
    pthread_t th1, th2;
    pthread_create(&th1, NULL, customer_entry, "John");
    pthread_create(&th2, NULL, customer_entry, "Mary");

    pthread_join(th1, NULL);
    pthread_join(th2, NULL);

    destroy(&inventory);
    pthread_mutex_destroy(&inventory_lock);
    printf("\nAll threads finished.\n");
    return 0;
}