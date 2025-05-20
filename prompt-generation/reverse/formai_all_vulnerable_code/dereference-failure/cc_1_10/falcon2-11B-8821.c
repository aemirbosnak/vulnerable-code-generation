//Falcon2-11B DATASET v1.0 Category: Digital Auction System ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <semaphore.h>

typedef struct auction_item {
    int id;
    int price;
    int winner;
    int bid;
    sem_t *lock;
} AuctionItem;

void* bid(void* arg) {
    AuctionItem* item = (AuctionItem*) arg;
    int bid_amount = 0;
    int winner_id = 0;

    while(1) {
        sem_wait(item->lock);
        if (item->winner!= 0) {
            sem_post(item->lock);
            continue;
        }

        printf("Enter a bid amount: ");
        scanf("%d", &bid_amount);
        if (item->price < bid_amount) {
            item->winner = item->id;
            item->bid = bid_amount;
            printf("You win the auction with a bid of %d!\n", item->bid);
            sem_post(item->lock);
            return NULL;
        } else {
            printf("Invalid bid amount!\n");
            sem_post(item->lock);
        }
    }
}

int main() {
    AuctionItem item;
    item.id = 1;
    item.price = 10;
    item.winner = 0;
    item.bid = 0;
    pthread_t thread_id;
    sem_init(&item.lock, 0, 1);

    if (pthread_create(&thread_id, NULL, bid, &item)!= 0) {
        printf("Error creating thread!\n");
        return 1;
    }

    pthread_join(thread_id, NULL);
    printf("Auction is over!\n");
    return 0;
}