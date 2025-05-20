//Gemma-7B DATASET v1.0 Category: Digital Auction System ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_AUCTIONS 10

typedef struct Auction {
    char name[255];
    int starting_bid;
    int reserve_price;
    int current_bid;
    struct Auction* next;
} Auction;

void insert_auction(Auction** head) {
    Auction* new_auction = malloc(sizeof(Auction));
    printf("Enter auction name: ");
    scanf("%s", new_auction->name);
    printf("Enter starting bid: ");
    scanf("%d", &new_auction->starting_bid);
    printf("Enter reserve price: ");
    scanf("%d", &new_auction->reserve_price);
    new_auction->current_bid = new_auction->starting_bid;
    new_auction->next = *head;
    *head = new_auction;
}

void print_auctions(Auction* head) {
    while (head) {
        printf("%s, starting bid: %d, reserve price: %d, current bid: %d\n", head->name, head->starting_bid, head->reserve_price, head->current_bid);
        head = head->next;
    }
}

int main() {
    Auction* head = NULL;
    char command;

    printf("Enter 'i' to insert an auction, 'p' to print auctions, or 'q' to quit: ");
    scanf("%c", &command);

    while (command != 'q') {
        switch (command) {
            case 'i':
                insert_auction(&head);
                break;
            case 'p':
                print_auctions(head);
                break;
            default:
                printf("Invalid command.\n");
                break;
        }

        printf("Enter 'i' to insert an auction, 'p' to print auctions, or 'q' to quit: ");
        scanf("%c", &command);
    }

    return 0;
}