//GEMINI-pro DATASET v1.0 Category: Medical Store Management System ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of drugs that can be stored
#define MAX_DRUGS 100

// Define the structure of a drug
typedef struct drug {
    char name[50];
    char description[200];
    float price;
    int quantity;
} drug;

// Define the structure of the medical store
typedef struct medical_store {
    drug drugs[MAX_DRUGS];
    int num_drugs;
} medical_store;

// Create a new medical store
medical_store *create_medical_store() {
    medical_store *store = (medical_store *)malloc(sizeof(medical_store));
    store->num_drugs = 0;
    return store;
}

// Add a new drug to the medical store
void add_drug(medical_store *store, drug *drug) {
    store->drugs[store->num_drugs] = *drug;
    store->num_drugs++;
}

// Find a drug in the medical store by name
drug *find_drug(medical_store *store, char *name) {
    for (int i = 0; i < store->num_drugs; i++) {
        if (strcmp(store->drugs[i].name, name) == 0) {
            return &store->drugs[i];
        }
    }
    return NULL;
}

// Sell a drug from the medical store
void sell_drug(medical_store *store, char *name, int quantity) {
    drug *drug = find_drug(store, name);
    if (drug == NULL) {
        printf("Drug not found.\n");
        return;
    }
    if (drug->quantity < quantity) {
        printf("Insufficient quantity.\n");
        return;
    }
    drug->quantity -= quantity;
}

// Print the contents of the medical store
void print_medical_store(medical_store *store) {
    for (int i = 0; i < store->num_drugs; i++) {
        printf("%s - %s - $%.2f - %d\n", store->drugs[i].name, store->drugs[i].description, store->drugs[i].price, store->drugs[i].quantity);
    }
}

// Free the memory allocated to the medical store
void free_medical_store(medical_store *store) {
    free(store);
}

// Main function
int main() {
    // Create a new medical store
    medical_store *store = create_medical_store();

    // Add some drugs to the medical store
    drug drug1 = {"Paracetamol", "Pain reliever", 10.0, 100};
    add_drug(store, &drug1);
    drug drug2 = {"Ibuprofen", "Anti-inflammatory", 12.0, 50};
    add_drug(store, &drug2);
    drug drug3 = {"Aspirin", "Pain reliever", 8.0, 75};
    add_drug(store, &drug3);

    // Print the contents of the medical store
    printf("Medical Store:\n");
    print_medical_store(store);

    // Sell some drugs from the medical store
    sell_drug(store, "Paracetamol", 20);
    sell_drug(store, "Ibuprofen", 10);

    // Print the contents of the medical store
    printf("Medical Store after selling some drugs:\n");
    print_medical_store(store);

    // Free the memory allocated to the medical store
    free_medical_store(store);

    return 0;
}