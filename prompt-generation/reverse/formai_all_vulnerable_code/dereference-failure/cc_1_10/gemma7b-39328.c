//Gemma-7B DATASET v1.0 Category: File Backup System ; Style: medieval
#include <stdio.h>
#include <string.h>

#define MAX_STORAGE 1024

typedef struct Item {
    char name[256];
    int quantity;
    struct Item* next;
} Item;

typedef struct Vault {
    Item* head;
    int size;
    int capacity;
} Vault;

Vault vault;

void initializeVault() {
    vault.head = NULL;
    vault.size = 0;
    vault.capacity = MAX_STORAGE;
}

void addToVault(char* name, int quantity) {
    Item* newItem = malloc(sizeof(Item));
    strcpy(newItem->name, name);
    newItem->quantity = quantity;
    newItem->next = NULL;

    if (vault.head == NULL) {
        vault.head = newItem;
    } else {
        vault.head->next = newItem;
    }

    vault.size++;
}

void listVault() {
    Item* currentItem = vault.head;
    printf("Items in the vault:\n");
    while (currentItem) {
        printf("%s: %d\n", currentItem->name, currentItem->quantity);
        currentItem = currentItem->next;
    }
}

int main() {
    initializeVault();

    addToVault("Bread", 10);
    addToVault("Honey", 5);
    addToVault("Sword", 1);

    listVault();

    return 0;
}