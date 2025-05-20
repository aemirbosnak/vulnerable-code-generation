//Falcon-180B DATASET v1.0 Category: Stock market tracker ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct stock {
    char name[20];
    int price;
    int quantity;
};

void main() {
    int n;
    printf("Enter the number of stocks: ");
    scanf("%d", &n);

    struct stock stocks[n];

    for(int i=0; i<n; i++) {
        printf("Enter the name of stock %d: ", i+1);
        scanf("%s", stocks[i].name);

        printf("Enter the price of %s: ", stocks[i].name);
        scanf("%d", &stocks[i].price);

        printf("Enter the quantity of %s: ", stocks[i].name);
        scanf("%d", &stocks[i].quantity);
    }

    printf("STOCK MARKET TRACKER\n");
    printf("=====================\n");

    while(1) {
        system("clear");
        printf("STOCK MARKET TRACKER\n");
        printf("=====================\n");

        for(int i=0; i<n; i++) {
            printf("%s\t%d\t%d\n", stocks[i].name, stocks[i].price, stocks[i].quantity);
        }

        printf("\nEnter 1 to buy\nEnter 2 to sell\nEnter 3 to update\nEnter 4 to exit\n");
        int choice;
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter the name of the stock to buy: ");
                char buy_name[20];
                scanf("%s", buy_name);

                for(int j=0; j<n; j++) {
                    if(strcmp(stocks[j].name, buy_name) == 0) {
                        printf("Enter the quantity to buy: ");
                        int buy_quantity;
                        scanf("%d", &buy_quantity);

                        if(buy_quantity > stocks[j].quantity) {
                            printf("Not enough stock available.\n");
                            break;
                        }

                        stocks[j].quantity -= buy_quantity;
                        printf("%s bought successfully.\n", buy_name);
                        break;
                    }
                }

                break;

            case 2:
                printf("Enter the name of the stock to sell: ");
                char sell_name[20];
                scanf("%s", sell_name);

                for(int j=0; j<n; j++) {
                    if(strcmp(stocks[j].name, sell_name) == 0) {
                        printf("Enter the quantity to sell: ");
                        int sell_quantity;
                        scanf("%d", &sell_quantity);

                        if(sell_quantity > stocks[j].quantity) {
                            printf("Not enough stock available.\n");
                            break;
                        }

                        stocks[j].quantity -= sell_quantity;
                        printf("%s sold successfully.\n", sell_name);
                        break;
                    }
                }

                break;

            case 3:
                printf("Enter the name of the stock to update: ");
                char update_name[20];
                scanf("%s", update_name);

                for(int j=0; j<n; j++) {
                    if(strcmp(stocks[j].name, update_name) == 0) {
                        printf("Enter the new price: ");
                        int new_price;
                        scanf("%d", &new_price);

                        stocks[j].price = new_price;
                        printf("%s updated successfully.\n", update_name);
                        break;
                    }
                }

                break;

            case 4:
                exit(0);

            default:
                printf("Invalid choice.\n");
        }
    }
}