//FormAI DATASET v1.0 Category: Digital Auction System ; Style: all-encompassing
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//defining the structure of the items to be auctioned
struct auctionItem{
    int itemNumber;
    char itemName[50];
    double price;
    int bidderNumber;
    char bidderName[50];
};

//function to get item details from the user
void getItemDetails(struct auctionItem *items, int index){
    printf("Enter the details for Item %d\n", index+1);
    printf("Item name: ");
    scanf("%s", items[index].itemName);

    printf("Item number: ");
    scanf("%d", &items[index].itemNumber);

    printf("Starting price: ");
    scanf("%lf", &items[index].price);    
}

//function to display all items in the auction
void displayItems(struct auctionItem *items, int itemCount){    
    printf("Items up for auction are: \n");

    for(int i=0; i<itemCount; i++){
        printf("Item %d - %s, starting price: %.2lf\n", items[i].itemNumber, items[i].itemName, items[i].price);
    }
}

//function for bidding
void bid(struct auctionItem *items, int itemCount){
    int itemNumber, bidderNumber;
    double bidPrice;
    char bidderName[50], choice;

    printf("Enter item number you want to bid: ");
    scanf("%d", &itemNumber);

    for(int i=0; i<itemCount; i++){
        if(items[i].itemNumber == itemNumber){
            printf("\n%s is up for auction, starting price is %.2lf.\n\n", items[i].itemName, items[i].price);
            printf("Enter your bidder number: ");
            scanf("%d", &bidderNumber);

            printf("Enter your name: ");
            scanf("%s", bidderName);

            printf("Enter your bid price: ");
            scanf("%lf", &bidPrice);

            if(bidPrice > items[i].price){
                items[i].price = bidPrice;
                items[i].bidderNumber = bidderNumber;
                strcpy(items[i].bidderName, bidderName);
                printf("\nCongratulations! You are the highest bidder for %s with a bid of %.2lf\n\n", items[i].itemName, items[i].price);
            } else {
                printf("\nBid is lower than current highest bid. Do you want to bid again?(y/n): ");
                scanf(" %c", &choice);

                if(choice == 'y'){
                    bid(items, itemCount);
                }
            }

            return;
        }
    }

    printf("\nInvalid item number\n\n");
}

//function to get highest bidder for an item
void getHighestBidder(struct auctionItem *items, int itemCount){
    int itemNumber;

    printf("Enter item number to get highest bidder: ");
    scanf("%d", &itemNumber);

    for(int i=0; i<itemCount; i++){
        if(items[i].itemNumber == itemNumber){
            if(items[i].bidderNumber == 0){
                printf("\nNo bids yet for %s\n\n", items[i].itemName);
            } else {
                printf("\nHighest bidder for %s is %s with a bid of %.2lf\n\n", items[i].itemName, items[i].bidderName, items[i].price);
            }

            return;
        }
    }

    printf("\nInvalid item number\n\n");
}

int main(){
    int itemCount;
    char choice;
    printf("============= Welcome to the Auction =============\n\n");

    printf("Enter the number of items for auction: ");
    scanf("%d", &itemCount);

    struct auctionItem items[itemCount];

    for(int i=0; i<itemCount; i++){
        getItemDetails(&items[0], i);
    }

    do{
        printf("What would you like to do?\n");
        printf("1. Display all items in auction\n");
        printf("2. Bid for an item\n");
        printf("3. Get highest bidder for an item\n");
        printf("4. Quit\n");
        printf("Enter your choice: ");
        scanf(" %c", &choice);

        switch(choice){            
            case '1':
                displayItems(&items[0], itemCount);
                break;
            case '2':
                bid(&items[0], itemCount);
                break;
            case '3':
                getHighestBidder(&items[0], itemCount);
                break;
            case '4':
                printf("\nThanks for visiting the auction.\n\n");
                exit(0);
            default:
                printf("\nInvalid choice\n\n");
        }
    } while(choice != '4');

    return 0;
}