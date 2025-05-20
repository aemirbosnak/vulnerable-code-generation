//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: distributed
#include <stdio.h>
#include <stdlib.h>

typedef struct item{
    char item_name[50];
    int item_code;
    float item_price;
} item;

typedef struct order{
    int table_number;
    item *items_ordered;
    int num_items_ordered;
    float total;
} order;

// Function for printing the bill
void bill(order *ord){
    printf("\n\n");
    printf("==============================================\n");
    printf("Table Number: %d\n", ord->table_number);
    printf("==============================================\n");
    printf("| Item Code |         Item Name         | Price |\n");
    printf("==============================================\n");
    for(int i=0; i<ord->num_items_ordered; i++){
        printf("| %-9d| %-27s| $%.2f |\n", 
               ord->items_ordered[i].item_code, ord->items_ordered[i].item_name, ord->items_ordered[i].item_price);
        ord->total += ord->items_ordered[i].item_price;
    }
    printf("==============================================\n");
    printf("| Total:                                 $%.2f |\n", ord->total);
    printf("==============================================\n");
}

int main(){
    // Create items
    item item1 = {"Espresso", 1, 2.50f};
    item item2 = {"Cappuccino", 2, 3.50f};
    item item3 = {"Latte", 3, 4.00f};
    item item4 = {"Muffin", 4, 2.50f};
    item item5 = {"Bagel", 5, 2.25f};

    // Create orders
    order order1 = {1, (item*) malloc(sizeof(item) * 2), 2, 0.0f};
    order1.items_ordered[0] = item1;
    order1.items_ordered[1] = item4;
    order order2 = {2, (item*) malloc(sizeof(item) * 3), 3, 0.0f};
    order2.items_ordered[0] = item2;
    order2.items_ordered[1] = item3;
    order2.items_ordered[2] = item5;

    // Print bills
    bill(&order1);
    bill(&order2);

    // Free malloc'd memory
    free(order1.items_ordered);
    free(order2.items_ordered);

    return 0;
}