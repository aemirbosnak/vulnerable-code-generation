//FormAI DATASET v1.0 Category: Digital Auction System ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    //Initialize variables
    int num_bidders;
    char bidder_name[20];
    float bidder_bid;
    int i, j;

    //Prompt user for number of bidders
    printf("Enter the number of bidders: ");
    scanf("%d", &num_bidders);

    //Allocate memory for bidder names and bids
    char **names = (char**)malloc(sizeof(char*)*num_bidders);
    float *bids = (float*)malloc(sizeof(float)*num_bidders);

    //Record each bidder's name and bid
    for(i = 0; i < num_bidders; i++){
        printf("Bidder %d: \n", i+1);
        printf("Name: ");
        scanf("%s", bidder_name);
        names[i] = strdup(bidder_name);
        printf("Bid: ");
        scanf("%f", &bidder_bid);
        bids[i] = bidder_bid;
    }

    //Sort bids in descending order
    for(i = 0; i < num_bidders; i++){
        for(j = 0; j < num_bidders-i-1; j++){
            if(bids[j] < bids[j+1]){
                float temp_bid = bids[j];
                bids[j] = bids[j+1];
                bids[j+1] = temp_bid;
                char *temp_name = names[j];
                names[j] = names[j+1];
                names[j+1] = temp_name;
            }
        }
    }

    //Display winning bidder and bid amount
    printf("\nWinner: %s with a bid of $%.2f\n", names[0], bids[0]);

    //Free allocated memory
    for(i = 0; i < num_bidders; i++){
        free(names[i]);
    }
    free(names);
    free(bids);

    return 0;
}