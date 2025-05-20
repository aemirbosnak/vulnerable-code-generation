//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: Alan Touring
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// structure for storing item info
struct item
{
    char name[50];
    int price;
    int quantity;
};

// function to calculate total bill
int calculateBill(struct item order[], int count)
{
    int total = 0;
    printf("\n\nItem Name\tPrice\tQuantity\tTotal\n");
    for(int i=0; i<count; i++)
    {
        int subTotal = order[i].price * order[i].quantity;
        printf("\n%s\t\t%d\t\t%d\t\t%d", order[i].name, order[i].price, order[i].quantity, subTotal);
        total += subTotal;
    }
    printf("\n\n\t\t\t\tTotal: %d\n", total);
    return total;
}

int main()
{
    // initialize menu
    struct item menu[] = {
                            {"Coffee", 50, 0},
                            {"Tea", 30, 0},
                            {"Sandwich", 70, 0},
                            {"Burger", 100, 0},
                            {"Pizza", 150, 0},
                            {"French Fries", 50, 0}
                         };
                         
    int menuCount = sizeof(menu)/sizeof(menu[0]);
    printf("Welcome to Cafe Billing System\n");
    printf("Menu:\n");
    printf("Sl.No.\tItem Name\tPrice\n");
    for(int i=0; i<menuCount; i++)
    {
        printf("%d.\t%s\t\t%d\n", i+1, menu[i].name, menu[i].price);
    }
    
    // take order
    printf("\nEnter number of items to be ordered: ");
    int itemCount;
    scanf("%d", &itemCount);
    struct item order[itemCount];
    for(int i=0; i<itemCount; i++)
    {
        printf("\nEnter item number %d: ", i+1);
        int itemNumber;
        scanf("%d", &itemNumber);
        strcpy(order[i].name, menu[itemNumber-1].name);
        order[i].price = menu[itemNumber-1].price;
        printf("\nEnter quantity: ");
        scanf("%d", &order[i].quantity);
    }
    
    // calculate and display bill
    calculateBill(order, itemCount);
    
    return 0;
}