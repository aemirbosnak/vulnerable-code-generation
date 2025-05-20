//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: brave
#include<stdio.h>
#include<stdlib.h>

typedef struct{
    char name[20];
    int price;
    int quantity;
} product;

int main(){
    int choice, n, i, total = 0;
    printf("Welcome to Brave Cafe!\n");
    printf("How many products do you have in your menu?\n");
    scanf("%d", &n);
    product menu[n];
    
    for(i=0; i<n; i++){
        printf("\nEnter name of product %d: ", i+1);
        scanf("%s", &menu[i].name);
        printf("Enter price of product %d: ", i+1);
        scanf("%d", &menu[i].price);
        printf("Enter quantity of product %d: ", i+1);
        scanf("%d", &menu[i].quantity);
    }
    
    printf("\n--------Brave Cafe Menu--------\n");
    printf("Code |   Product Name   |   Price   |   Quantity\n");
    for(i=0; i<n; i++){
        printf("%5d|%18s|%11d|%11d\n", i+1, menu[i].name, menu[i].price, menu[i].quantity);
    }
    
    while(choice != -1){
        printf("\nEnter the product code (-1 to exit):\n");
        scanf("%d", &choice);
        if(choice <= n && choice != -1){
            int purchase_qty;
            printf("Enter quantity of purchase:\n");
            scanf("%d", &purchase_qty);
            
            if(menu[choice-1].quantity >= purchase_qty){
                total += menu[choice-1].price * purchase_qty;
                menu[choice-1].quantity -= purchase_qty;
                printf("%d x %s added to your bill\n", purchase_qty, menu[choice-1].name);
            }
            else{
                printf("Sorry, we don't have enough stock available.\n");
            }
        }
        else if(choice != -1){
            printf("Invalid product code entered!\n");
        }
    }
    
    printf("\n\nThank you for visiting Brave Cafe.\n");
    printf("Your bill amount is: %d", total);
    return 0;
}