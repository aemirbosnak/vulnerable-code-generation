//Falcon-180B DATASET v1.0 Category: Digital Auction System ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int id;
    char name[50];
    int bid;
} Bidder;

void display_bidders(Bidder bidders[], int n) {
    printf("Bidders:\n");
    for (int i = 0; i < n; i++) {
        printf("%d. %s - $%d\n", bidders[i].id, bidders[i].name, bidders[i].bid);
    }
}

int compare_bidders(const void *a, const void *b) {
    Bidder bidder1 = *(Bidder *)a;
    Bidder bidder2 = *(Bidder *)b;

    if (bidder1.bid > bidder2.bid) {
        return -1;
    } else if (bidder1.bid < bidder2.bid) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    srand(time(NULL));

    int n_bidders;
    printf("Enter number of bidders: ");
    scanf("%d", &n_bidders);

    Bidder bidders[n_bidders];

    for (int i = 0; i < n_bidders; i++) {
        bidders[i].id = i + 1;
        printf("Enter name of bidder %d: ", bidders[i].id);
        scanf("%s", bidders[i].name);
        bidders[i].bid = rand() % 1000;
    }

    display_bidders(bidders, n_bidders);

    qsort(bidders, n_bidders, sizeof(Bidder), compare_bidders);

    printf("\nBidders sorted by bid:\n");
    display_bidders(bidders, n_bidders);

    return 0;
}