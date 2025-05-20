//Falcon-180B DATASET v1.0 Category: Cafe Billing System ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define MAX 100

struct item {
    char name[20];
    float price;
};

void addItem(struct item menu[], int *size) {
    printf("Enter item name: ");
    scanf("%s", menu[*size].name);
    printf("Enter item price: ");
    scanf("%f", &menu[*size].price);
    (*size)++;
}

void displayMenu(struct item menu[], int size) {
    printf("\nMenu:\n");
    for (int i = 0; i < size; i++) {
        printf("%d. %s - $%.2f\n", i + 1, menu[i].name, menu[i].price);
    }
}

void placeOrder(struct item menu[], int size, int customerOrder[], int orderSize) {
    printf("\nOrder:\n");
    for (int i = 0; i < orderSize; i++) {
        int index = -1;
        for (int j = 0; j < size; j++) {
            if (strcmp(menu[j].name, customerOrder[i]) == 0) {
                index = j;
                break;
            }
        }
        if (index == -1) {
            printf("%s not found in the menu.\n", customerOrder[i]);
        } else {
            printf("%s - $%.2f\n", menu[index].name, menu[index].price);
        }
    }
}

void calculateTotal(struct item menu[], int size, int customerOrder[], int orderSize) {
    float total = 0.0;
    for (int i = 0; i < orderSize; i++) {
        int index = -1;
        for (int j = 0; j < size; j++) {
            if (strcmp(menu[j].name, customerOrder[i]) == 0) {
                index = j;
                break;
            }
        }
        if (index!= -1) {
            total += menu[index].price;
        }
    }
    printf("\nTotal: $%.2f\n", total);
}

int main() {
    struct item menu[MAX];
    int size = 0;

    addItem(menu, &size);
    addItem(menu, &size);
    addItem(menu, &size);

    int customerOrder[MAX];
    int orderSize = 0;

    printf("Welcome to the Cafe!\n");
    while (orderSize < MAX) {
        printf("Enter item number to order or 0 to finish: ");
        int choice;
        scanf("%d", &choice);
        if (choice == 0) {
            break;
        } else if (choice > 0 && choice <= size) {
            strcpy(customerOrder[orderSize], menu[choice - 1].name);
            orderSize++;
        } else {
            printf("Invalid choice.\n");
        }
    }

    displayMenu(menu, size);
    placeOrder(menu, size, customerOrder, orderSize);
    calculateTotal(menu, size, customerOrder, orderSize);

    return 0;
}