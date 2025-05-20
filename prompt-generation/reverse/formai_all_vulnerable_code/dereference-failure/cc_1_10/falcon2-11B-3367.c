//Falcon2-11B DATASET v1.0 Category: Digital Auction System ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

// Function to handle bidding in the auction
void* digital_auction(void* name) {
    int bidder_id = *(int*) name;
    char* bidder_name = (char*) malloc(100);
    int bid_number = 0;
    int current_price = 0;

    // Loop until the auction is over
    while (current_price!= -1) {
        // Bid on the current item
        scanf("%d", &bid_number);

        // Check if the bid is valid
        if (bid_number > current_price) {
            printf("%s has bid %d on item %d.\n", bidder_name, bid_number, bidder_id);
            current_price = bid_number;
        } else {
            printf("%s's bid of %d on item %d is not valid.\n", bidder_name, bid_number, bidder_id);
        }

        // Check if the auction is over
        if (bid_number == -1) {
            break;
        }
    }

    // Free the allocated memory
    free(bidder_name);
    pthread_exit(NULL);
}

int bid_to_string(int bid) {
    char* str = (char*) malloc(10);
    sprintf(str, "%d", bid);
    return str;
}

int main() {
    int num_bidders = 3;
    int current_price = 0;

    // Create threads for each bidder
    pthread_t threads[num_bidders];

    // Loop through the bidders
    for (int i = 0; i < num_bidders; i++) {
        // Allocate memory for the bidder's name and id
        char* bidder_name = (char*) malloc(100);
        int* bidder_id = (int*) malloc(100);

        // Set the bidder's name and id
        sprintf(bidder_name, "Bidder %d", i+1);
        bidder_id[i] = i+1;

        // Create a thread with the digital_auction function
        pthread_create(&threads[i], NULL, digital_auction, bidder_id);
    }

    // Wait for all threads to finish
    for (int i = 0; i < num_bidders; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}