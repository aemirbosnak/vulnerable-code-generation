//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: introspective
#include <stdio.h>
#include <stdlib.h>

struct order{
    char item_name[50];
    int quantity;
    float price;
};

int main(){
    int num_items;
    float total = 0;
    
    printf("Welcome to our cafe billing system\n\n");
    printf("How many items did the customer order?\n");
    scanf("%d", &num_items);
    
    struct order *orders = (struct order*) malloc(num_items * sizeof(struct order));
    
    for(int i=0; i<num_items; i++){
        printf("\n\nItem %d details:\n", i+1);
        printf("Name: ");
        scanf("%s", orders[i].item_name);
        printf("Quantity: ");
        scanf("%d", &orders[i].quantity);
        printf("Price per item: ");
        scanf("%f", &orders[i].price);
        
        total += orders[i].quantity * orders[i].price;
    }
    
    printf("\n\n\n\\_________________________________________________/");
    printf("\n|                                                 |");
    printf("\n|                CAFE BILLING SYSTEM               |");
    printf("\n|_________________________________________________|\n");
    printf("\n\n\n\n");
    printf("Item Name\t\tQty\t\tPrice\n");
    printf("___________________________________________________\n");
    
    for(int i=0; i<num_items; i++){
        printf("%-20s\t%d\t\t%.2f\n", orders[i].item_name, orders[i].quantity, orders[i].price);
    }
    
    printf("___________________________________________________\n");
    printf("\nTotal: %.2f", total);
    
    free(orders);
    
    return 0;
}