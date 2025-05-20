//GEMINI-pro DATASET v1.0 Category: Medical Store Management System ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct medicine {
    char name[50];
    int quantity;
    float price;
};

struct medicine_store {
    struct medicine *medicines;
    int num_medicines;
};

void add_medicine(struct medicine_store *store, char *name, int quantity, float price) {
    store->medicines = realloc(store->medicines, (store->num_medicines + 1) * sizeof(struct medicine));
    strcpy(store->medicines[store->num_medicines].name, name);
    store->medicines[store->num_medicines].quantity = quantity;
    store->medicines[store->num_medicines].price = price;
    store->num_medicines++;
}

void remove_medicine(struct medicine_store *store, char *name) {
    int i;
    for (i = 0; i < store->num_medicines; i++) {
        if (strcmp(store->medicines[i].name, name) == 0) {
            break;
        }
    }

    if (i == store->num_medicines) {
        printf("Medicine not found.\n");
        return;
    }

    for (i = i + 1; i < store->num_medicines; i++) {
        store->medicines[i - 1] = store->medicines[i];
    }

    store->num_medicines--;
}

void print_medicines(struct medicine_store *store) {
    int i;
    for (i = 0; i < store->num_medicines; i++) {
        printf("%s %d %f\n", store->medicines[i].name, store->medicines[i].quantity, store->medicines[i].price);
    }
}

int main() {
    struct medicine_store store;
    store.medicines = NULL;
    store.num_medicines = 0;

    add_medicine(&store, "Paracetamol", 100, 10.0);
    add_medicine(&store, "Ibuprofen", 50, 15.0);
    add_medicine(&store, "Aspirin", 25, 5.0);

    print_medicines(&store);

    remove_medicine(&store, "Ibuprofen");

    print_medicines(&store);

    return 0;
}