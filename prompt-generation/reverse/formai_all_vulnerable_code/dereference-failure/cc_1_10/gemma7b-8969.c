//Gemma-7B DATASET v1.0 Category: Cafe Billing System ; Style: artistic
#include <stdio.h>
#include <stdlib.h>

#define MAX_ITEMS 10

struct Item
{
    char name[20];
    float price;
    int quantity;
};

void display_menu(struct Item items[])
{
    int i = 0;
    printf("\n--- Menu ---\n");
    for (i = 0; items[i].name[0] != '\0'; i++)
    {
        printf("%s - %.2f (Q: %d)\n", items[i].name, items[i].price, items[i].quantity);
    }
}

int main()
{
    struct Item items[] =
    {
        {"Coffee", 2.50, 10},
        {"Tea", 3.00, 8},
        {"Juice", 2.00, 9},
        {"Soda", 1.50, 12}
    };

    display_menu(items);

    int item_no;
    printf("\nEnter item number: ");
    scanf("%d", &item_no);

    int quantity;
    printf("Enter quantity: ");
    scanf("%d", &quantity);

    struct Item item = items[item_no - 1];

    float total_price = item.price * quantity;

    printf("\nTotal price: %.2f", total_price);

    return 0;
}