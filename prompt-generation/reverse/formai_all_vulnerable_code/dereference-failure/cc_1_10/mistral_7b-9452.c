//MISTRAL-7B DATASET v1.0 Category: Medical Store Management System ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

typedef struct {
    char name[50];
    int stock;
    float price;
} Medicine;

typedef struct {
    int id;
    char name[50];
    Medicine* medicines;
    int num_medicines;
} Store;

void generate_id(int* id) {
    time_t t;
    char time_str[11];

    time(&t);
    strftime(time_str, sizeof(time_str), "%Y%m%d%H%M%S", localtime(&t));

    *id = atoi(time_str);
}

Store create_store(char* name, int capacity) {
    Store store;
    store.id = 0;
    strcpy(store.name, name);
    store.medicines = malloc(capacity * sizeof(Medicine));
    store.num_medicines = 0;

    generate_id(&store.id);

    return store;
}

void add_medicine(Store* store, char* name, int stock, float price) {
    Medicine medicine;
    strcpy(medicine.name, name);
    medicine.stock = stock;
    medicine.price = price;

    store->medicines[store->num_medicines] = medicine;
    store->num_medicines++;
}

void print_store_info(Store store) {
    printf("\nStore Information:\n");
    printf("Name: %s\n", store.name);
    printf("ID: %d\n", store.id);

    printf("\nMedicines:\n");
    for (int i = 0; i < store.num_medicines; i++) {
        printf("%s - Stock: %d - Price: %.2f\n", store.medicines[i].name, store.medicines[i].stock, store.medicines[i].price);
    }
}

int main() {
    Store my_store = create_store("Mind-Bending Medical Store", 10);
    add_medicine(&my_store, "Mind-Expander Pills", 20, 12.5);
    add_medicine(&my_store, "Memory Boosters", 15, 15.0);
    add_medicine(&my_store, "Paradox Pills", 7, 25.5);
    add_medicine(&my_store, "Brainwave Balancers", 30, 10.0);

    print_store_info(my_store);

    free(my_store.medicines);
    return 0;
}