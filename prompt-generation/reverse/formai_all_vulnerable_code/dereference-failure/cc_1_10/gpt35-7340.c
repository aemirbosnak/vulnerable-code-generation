//FormAI DATASET v1.0 Category: Digital Auction System ; Style: ephemeral
/* 
Ephemeral Digital Auction System
Designed by Chatbot
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    char name[20];
    int bid;
} bidder;

int main() {
    int num_bidders;
    printf("Enter number of bidders: ");
    scanf("%d", &num_bidders);
    
    bidder *bidders = (bidder*)malloc(num_bidders * sizeof(bidder));
    
    for(int i=0; i<num_bidders; i++) {
        printf("Enter bidder %d name: ", i+1);
        scanf("%s", bidders[i].name);
        bidders[i].bid = 0;
    }
    
    int auction_item;
    printf("Enter the item to be auctioned: ");
    scanf("%d", &auction_item);
    
    int starting_price;
    printf("Enter starting price: ");
    scanf("%d", &starting_price);
    
    int highest_bid = starting_price;
    char highest_bidder[20];
    strcpy(highest_bidder, bidders[0].name);
    
    printf("Auction for item %d has started!\n", auction_item);
    printf("Starting price: $%d\n", starting_price);
    
    srand(time(NULL));
    
    int round = 1;
    while(1) {
        printf("\nRound %d\n", round);
        for(int i=0; i<num_bidders; i++) {
            int random_num = rand() % 10 + 1;
            if(random_num > 5) {
                printf("%s, enter your bid: $", bidders[i].name);
                int current_bid;
                scanf("%d", &current_bid);
                if(current_bid > highest_bid) {
                    highest_bid = current_bid;
                    strcpy(highest_bidder, bidders[i].name);
                }
                bidders[i].bid = current_bid;
            }
        }
        if(highest_bid == starting_price) {
            printf("\nNo bids were made in this round. The round will be repeated.\n");
        } else {
            printf("\n%s has the highest bid of $%d\n", highest_bidder, highest_bid);
        }
        printf("\n");
        round++;
        
        if(round == 6) {
            printf("Auction for item %d has ended!\n", auction_item);
            break;
        }
    }
    
    printf("\nFinal bids:\n");
    for(int i=0; i<num_bidders; i++) {
        printf("%s: $%d\n", bidders[i].name, bidders[i].bid);
    }
    printf("\n%s has won the auction for item %d with a bid of $%d!", highest_bidder, auction_item, highest_bid);
    
    free(bidders);
    return 0;
}