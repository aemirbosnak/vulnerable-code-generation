//Falcon2-11B DATASET v1.0 Category: Digital Auction System ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct {
    int id;
    char name[100];
    int bid;
} Bid;

typedef struct {
    int id;
    char name[100];
    int maxBid;
} Item;

Item items[10];
Bid bids[10];
int numItems;
int numBids;

void createItem(int id, char name[], int bid) {
    items[id].id = id;
    strcpy(items[id].name, name);
    items[id].maxBid = bid;
    numItems++;
}

void createBid(int id, char name[], int bid) {
    bids[numBids].id = id;
    strcpy(bids[numBids].name, name);
    bids[numBids].bid = bid;
    numBids++;
}

void printBids(void) {
    for (int i = 0; i < numBids; i++) {
        printf("ID: %d, Name: %s, Bid: %d\n", bids[i].id, bids[i].name, bids[i].bid);
    }
}

void printItems(void) {
    for (int i = 0; i < numItems; i++) {
        printf("ID: %d, Name: %s, Max Bid: %d\n", items[i].id, items[i].name, items[i].maxBid);
    }
}

int main(int argc, char *argv[]) {
    int numArgs;
    if (argc!= 2) {
        printf("Usage: %s <numItems>\n", argv[0]);
        return 1;
    }
    numArgs = atoi(argv[1]);

    if (numArgs < 1 || numArgs > 10) {
        printf("Number of items must be between 1 and 10\n");
        return 1;
    }

    numItems = numArgs;

    int numBids;
    for (int i = 0; i < numItems; i++) {
        createItem(i, "Item " + (i + 1), 0);
        numBids = 0;
        while (numBids < 10) {
            char name[100];
            int bid;
            printf("Enter bid for %s (or 'q' to quit): ", items[i].name);
            fgets(name, 100, stdin);
            if (strcmp(name, "q") == 0) {
                break;
            }
            sscanf(name, "%s %d", name, &bid);
            createBid(i, name, bid);
            numBids++;
        }
    }

    printBids();
    printItems();

    return 0;
}