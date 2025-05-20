//Falcon2-11B DATASET v1.0 Category: Warehouse Management System ; Style: imaginative
#include<stdio.h>
#include<stdlib.h>

//Structure to represent an item
struct Item {
    char* name;
    int quantity;
    float cost;
};

int main() {
    //Array to store items
    struct Item items[100];
    int numItems = 0;

    //Prompt user to enter number of items
    printf("Enter number of items: ");
    int num;
    scanf("%d", &num);

    for(int i = 0; i < num; i++) {
        //Prompt user to enter details for each item
        printf("Enter item name: ");
        fgets(items[i].name, 100, stdin);
        items[i].name[strcspn(items[i].name, "\n")] = '\0';

        printf("Enter item quantity: ");
        scanf("%d", &items[i].quantity);

        printf("Enter item cost: ");
        scanf("%f", &items[i].cost);
    }

    //Sort items by name
    for(int i = 0; i < numItems - 1; i++) {
        for(int j = 0; j < numItems - i - 1; j++) {
            if(strcmp(items[j].name, items[j+1].name) > 0) {
                struct Item temp = items[j];
                items[j] = items[j+1];
                items[j+1] = temp;
            }
        }
    }

    //Print sorted items
    for(int i = 0; i < numItems; i++) {
        printf("Name: %s\nQuantity: %d\nCost: %.2f\n", items[i].name, items[i].quantity, items[i].cost);
    }

    //Calculate total cost
    float totalCost = 0.0;
    for(int i = 0; i < numItems; i++) {
        totalCost += items[i].quantity * items[i].cost;
    }

    printf("Total cost: %.2f\n", totalCost);

    return 0;
}