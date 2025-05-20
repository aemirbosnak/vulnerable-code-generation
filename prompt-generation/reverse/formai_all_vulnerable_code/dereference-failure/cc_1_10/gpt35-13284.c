//FormAI DATASET v1.0 Category: Database simulation ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Cryptic Database Simulation

typedef struct cryptic_data {
    int id;
    char name[20];
    float balance;
} CrypticData;

void addCrypticData(CrypticData** crypticArray, int* size) {
    CrypticData* newData = (CrypticData*) malloc(sizeof(CrypticData));
    printf("Enter ID: ");
    scanf("%d", &(newData->id));
    printf("Enter name: ");
    scanf("%s", newData->name);
    printf("Enter balance: ");
    scanf("%f", &(newData->balance));
    (*size)++;
    *crypticArray = (CrypticData*) realloc(*crypticArray, (*size) * sizeof(CrypticData));
    (*crypticArray)[*size - 1] = *newData;
    free(newData);
    printf("CrypticData added!\n");
}

void deleteCrypticData(CrypticData** crypticArray, int* size, int id) {
    int found = 0;
    for (int i = 0; i < *size; i++) {
        if ((*crypticArray)[i].id == id) {
            found = 1;
            for (int j = i; j < *size - 1; j++) {
                (*crypticArray)[j] = (*crypticArray)[j + 1];
            }
            (*size)--;
            *crypticArray = (CrypticData*) realloc(*crypticArray, (*size) * sizeof(CrypticData));
            printf("CrypticData deleted!\n");
            break;
        }
    }
    if (!found) {
        printf("CrypticData not found!\n");
    }
}

void showCrypticData(CrypticData* crypticArray, int size) {
    for (int i = 0; i < size; i++) {
        printf("ID: %d, Name: %s, Balance: %.2f\n", crypticArray[i].id, crypticArray[i].name, crypticArray[i].balance);
    }
}

int main() {
    CrypticData* crypticArray = NULL;
    int size = 0;
    int choice = 0;
    while (1) {
        printf("\n1. Add CrypticData\n2. Delete CrypticData\n3. Show CrypticData\n4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                addCrypticData(&crypticArray, &size);
                break;
            case 2:
                if (size == 0) {
                    printf("CrypticData is empty!\n");
                    break;
                }
                int id;
                printf("Enter ID to delete: ");
                scanf("%d", &id);
                deleteCrypticData(&crypticArray, &size, id);
                break;
            case 3:
                if (size == 0) {
                    printf("CrypticData is empty!\n");
                    break;
                }
                showCrypticData(crypticArray, size);
                break;
            case 4:
                printf("Exiting program...\n");
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}