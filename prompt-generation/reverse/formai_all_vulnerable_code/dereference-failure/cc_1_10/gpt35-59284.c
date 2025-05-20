//FormAI DATASET v1.0 Category: Digital Auction System ; Style: imaginative
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

//structure for bidding system 
struct bidder {
    char name[20];
    int bid_amount;
    int unique_id;
    int won_bid;
};

void generate_random_unique_id(struct bidder* bidders, int n);
void display_details(struct bidder* bidders, int n);

int main() {
    int i, j, n, max_bid, winner_id;
    srand(time(NULL));

    printf("Welcome to the Digital Auction System\n");

    //get number of bidders from user
    printf("Enter the number of bidders: ");
    scanf("%d", &n);

    //allocate memory for the bidders
    struct bidder* bidders = (struct bidder*)malloc(n*sizeof(struct bidder));

    //get details of the bidders
    for(i=0; i<n; i++) {
        printf("\nEnter the bidder #%d details:\n", i+1);
        printf("Name: ");
        scanf("%s", bidders[i].name);
        printf("Bid Amount: ");
        scanf("%d", &bidders[i].bid_amount);
    }

    //generate random unique IDs for the bidders
    generate_random_unique_id(bidders, n);

    //display the details of all the bidders
    display_details(bidders, n);

    //find the maximum bid amount among the bidders
    max_bid = bidders[0].bid_amount;
    for(i=1; i<n; i++) {
        if(bidders[i].bid_amount > max_bid) {
            max_bid = bidders[i].bid_amount;
        }
    }

    //find the winner among the bidders with the maximum bid amount
    for(i=0; i<n; i++) {
        if(bidders[i].bid_amount == max_bid) {
            winner_id = bidders[i].unique_id;
            bidders[i].won_bid = 1;
            break;
        }
    }

    //display the winner of the auction
    printf("\n\nThe winner of the auction is bidder #%d with a bid amount of %d\n", winner_id, max_bid);

    //display the details of all the bidders with the winner highlighted
    display_details(bidders, n);

    free(bidders);
    return 0;
}

//function to generate random unique IDs for the bidders
void generate_random_unique_id(struct bidder* bidders, int n) {
    int* used_ids = (int*)calloc(100, sizeof(int));
    int id, i, j;
    for(i=0; i<n; i++) {
        do {
            id = (rand() % 1000) + 1;
        } while(used_ids[id] != 0);
        bidders[i].unique_id = id;
        used_ids[id] = 1;
    }
    free(used_ids);
}

//function to display the details of all the bidders with the winner highlighted
void display_details(struct bidder* bidders, int n) {
    int i;
    printf("\n\nBidder Details:\n");
    printf("Name\tBid Amount\tUnique ID\tWinner\n");
    for(i=0; i<n; i++) {
        printf("%s\t%d\t\t%d\t\t", bidders[i].name, bidders[i].bid_amount, bidders[i].unique_id);
        if(bidders[i].won_bid == 1) {
            printf("Yes");
        } else {
            printf("No");
        }
        printf("\n");
    }
}