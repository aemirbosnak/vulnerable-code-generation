//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define data structures for medical store management
typedef struct {
    char name[50];
    int quantity;
    float price;
} Medicine;

typedef struct {
    Medicine* medicines[100];
    int num_medicines;
} MedicineStore;

// Function to randomly generate medicine prices based on a chaotic algorithm
float generate_price() {
    float chaos = (float) rand() / RAND_MAX;
    float price = 10 + chaos * 90;
    return price;
}

// Function to add a medicine to the store
void add_medicine(MedicineStore* store, char* name, int quantity) {
    Medicine* medicine = (Medicine*) malloc(sizeof(Medicine));
    strcpy(medicine->name, name);
    medicine->quantity = quantity;
    medicine->price = generate_price();
    store->medicines[store->num_medicines++] = medicine;
}

int main() {
    // Seed the random number generator with the current time
    srand((unsigned int) time(NULL));

    // Create a new medicine store
    MedicineStore store;
    store.num_medicines = 0;

    // Add some medicines to the store
    add_medicine(&store, "Aspirin", 100);
    add_medicine(&store, "Ibuprofen", 50);
    add_medicine(&store, "Paracetamol", 75);

    // Print out the details of each medicine in the store
    for (int i = 0; i < store.num_medicines; i++) {
        Medicine* medicine = store.medicines[i];
        printf("Medicine Name: %s\n", medicine->name);
        printf("Quantity: %d\n", medicine->quantity);
        printf("Price: $%.2f\n", medicine->price);
    }

    return 0;
}