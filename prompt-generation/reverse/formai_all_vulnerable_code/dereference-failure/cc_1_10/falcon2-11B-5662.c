//Falcon2-11B DATASET v1.0 Category: Digital Auction System ; Style: imaginative
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct auction {
    char name[50];
    int price;
};

struct auction* add_auction(struct auction* auctions, int* size, char* name, int price) {
    struct auction* new_auction = (struct auction*)malloc(sizeof(struct auction));
    strcpy(new_auction->name, name);
    new_auction->price = price;
    auctions[*size] = *new_auction;
    (*size)++;
    return new_auction;
}

int main() {
    int size = 0;
    struct auction auctions[100];

    printf("Welcome to the C Digital Auction System!\n");
    printf("Enter the name of the item: ");
    char name[50];
    scanf("%s", name);
    printf("Enter the price: ");
    int price;
    scanf("%d", &price);
    struct auction* new_auction = add_auction(auctions, &size, name, price);
    printf("Item '%s' with price %d added to the auction.\n", name, price);

    while (1) {
        int choice;
        printf("Enter 1 to add a new item, 2 to view the auction, 3 to end the auction: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the name of the item: ");
                char name[50];
                scanf("%s", name);
                printf("Enter the price: ");
                int price;
                scanf("%d", &price);
                struct auction* new_auction = add_auction(auctions, &size, name, price);
                printf("Item '%s' with price %d added to the auction.\n", name, price);
                break;
            case 2:
                printf("Auction items:\n");
                for (int i = 0; i < size; i++) {
                    printf("%d: %s, Price: %d\n", i + 1, auctions[i].name, auctions[i].price);
                }
                break;
            case 3:
                printf("Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }
}