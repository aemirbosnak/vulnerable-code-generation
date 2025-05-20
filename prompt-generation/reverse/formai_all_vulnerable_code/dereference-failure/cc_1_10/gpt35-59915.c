//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: mathematical
#include<stdio.h>
#include<stdlib.h>

struct menu{
    int itemcode;
    char itemname[30];
    float itemprice;
    int quantity;
};

int main(){
    int i, n, choice, total_items=0;
    float total_price=0;
    struct menu *m;

    printf("Enter the number of items in the menu: ");
    scanf("%d", &n);

    // allocating memory for menu items
    m = (struct menu*) malloc(n * sizeof(struct menu));

    // taking input for menu items
    for(i=0;i<n;i++){
        printf("\nEnter Item Code: ");
        scanf("%d", &m[i].itemcode);
        printf("Enter Item Name: ");
        scanf("%s", m[i].itemname);
        printf("Enter Item Price: ");
        scanf("%f", &m[i].itemprice);
    }

    while(1){
        printf("\n----------------------\n");
        printf("C Cafe Billing System\n");
        printf("----------------------\n");
        printf("1. View Menu\n");
        printf("2. Place Order\n");
        printf("3. View Total\n");
        printf("4. Exit\n");
        printf("----------------------\n");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice){
            // view menu
            case 1:
                printf("\n----------------------\n");
                printf("        MENU\n");
                printf("----------------------\n");
                printf("Code\tItem\tPrice\n");
                for(i=0;i<n;i++){
                    printf("%d\t%s\t%.2f\n", m[i].itemcode, m[i].itemname, m[i].itemprice);
                }
                break;

            // place order
            case 2:
                printf("\nEnter Item Code: ");
                scanf("%d", &choice);
                printf("Enter Quantity: ");
                scanf("%d", &n);
                for(i=0;i<n;i++){
                    if(m[i].itemcode == choice){
                        m[i].quantity += 1;
                        total_items += 1;
                        total_price += m[i].itemprice;
                    }
                }
                break;

            // view total
            case 3:
                printf("\n----------------------\n");
                printf("      TOTAL BILL\n");
                printf("----------------------\n");
                printf("Total Items: %d\n", total_items);
                printf("Total Price: %.2f\n", total_price);
                break;

            // exit
            case 4:
                printf("\nThank you for using C Cafe Billing System!\n");
                free(m);
                exit(0);

            // invalid choice
            default:
                printf("\nInvalid Choice! Please try again.\n");
        }
    }
    return 0;
}