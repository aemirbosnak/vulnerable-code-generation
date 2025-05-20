//FormAI DATASET v1.0 Category: Digital Auction System ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * This is a digital auction system program written in C language.
 * It allows users to create and bid on auctions for various items.
 * The system stores all auction data in a binary file for persistence.
 */

#define ITEM_NAME_LEN 50
#define MAX_AUCTIONS 100

typedef struct {
    char name[ITEM_NAME_LEN];
    float highest_bid;
    char highest_bidder[ITEM_NAME_LEN];
    int status; // 0 for ongoing, 1 for finished
} Auction;

void print_menu();
void add_auction(Auction *auctions[], int *num_auctions);
void list_auctions(Auction *auctions[], int num_auctions);
void bid_on_auction(Auction *auctions[], int num_auctions);
void save_auctions(Auction *auctions[], int num_auctions);
void load_auctions(Auction *auctions[], int *num_auctions);

int main() {
    Auction *auctions[MAX_AUCTIONS];
    int num_auctions = 0;

    load_auctions(auctions, &num_auctions);

    int running = 1;

    while (running) {
        print_menu();
        int choice;

        printf("Please select an option: ");
        scanf("%d", &choice);
        printf("\n");

        switch (choice) {
            case 1:
                add_auction(auctions, &num_auctions);
                break;
            case 2:
                list_auctions(auctions, num_auctions);
                break;
            case 3:
                bid_on_auction(auctions, num_auctions);
                break;
            case 4:
                save_auctions(auctions, num_auctions);
                running = 0;
                break;
            default:
                printf("Invalid choice. Try again.\n");
                break;
        }
    }

    printf("Goodbye!\n");

    return 0;
}

void print_menu() {
    printf("===== Digital Auction System =====\n\n");
    printf("1. Create new auction\n");
    printf("2. List all auctions\n");
    printf("3. Bid on an auction\n");
    printf("4. Quit\n\n");
}

void add_auction(Auction *auctions[], int *num_auctions) {
    if (*num_auctions >= MAX_AUCTIONS) {
        printf("Maximum number of auctions reached. Cannot add more.\n");
        return;
    }

    Auction *new_auction = (Auction *) malloc(sizeof(Auction));

    printf("Enter item name: ");
    scanf("%s", new_auction->name);
    printf("Enter starting bid: ");
    scanf("%f", &new_auction->highest_bid);
    strcpy(new_auction->highest_bidder, "");
    new_auction->status = 0;

    auctions[*num_auctions] = new_auction;
    (*num_auctions)++;

    printf("Auction successfully created!\n\n");
}

void list_auctions(Auction *auctions[], int num_auctions) {
    if (num_auctions == 0) {
        printf("No auctions found.\n");
        return;
    }

    printf("Auctions:\n");

    for (int i = 0; i < num_auctions; i++) {
        printf("===== Auction #%d =====\n", i + 1);
        printf("Item name: %s\n", auctions[i]->name);
        printf("Highest bid: %.2f\n", auctions[i]->highest_bid);
        printf("Highest bidder: %s\n", auctions[i]->highest_bidder);
        printf("Status: %s\n", auctions[i]->status == 0 ? "ongoing" : "finished");
        printf("\n");
    }
}

void bid_on_auction(Auction *auctions[], int num_auctions) {
    if (num_auctions == 0) {
        printf("No auctions found.\n");
        return;
    }

    char item_name[ITEM_NAME_LEN];
    int found = 0;

    printf("Enter item name: ");
    scanf("%s", item_name);

    for (int i = 0; i < num_auctions; i++) {
        if (strcmp(auctions[i]->name, item_name) == 0 && auctions[i]->status == 0) {
            printf("Current highest bid: %.2f\n", auctions[i]->highest_bid);
            printf("Enter your bid: ");

            float bid;
            scanf("%f", &bid);

            if (bid <= auctions[i]->highest_bid) {
                printf("Your bid must be higher than the current highest bid.\n");
            } else {
                auctions[i]->highest_bid = bid;
                strcpy(auctions[i]->highest_bidder, "You");
                printf("Bid placed successfully!\n");
            }

            found = 1;
            break;
        }
    }

    if (!found) {
        printf("No ongoing auction found with that item name.\n");
    }
}

void save_auctions(Auction *auctions[], int num_auctions) {
    FILE *file = fopen("auctions.bin", "wb");

    if (!file) {
        printf("Cannot open file for writing.\n");
        return;
    }

    fwrite(&num_auctions, sizeof(int), 1, file);

    for (int i = 0; i < num_auctions; i++) {
        fwrite(auctions[i], sizeof(Auction), 1, file);
    }

    fclose(file);
}

void load_auctions(Auction *auctions[], int *num_auctions) {
    FILE *file = fopen("auctions.bin", "rb");

    if (!file) {
        printf("Cannot open file for reading.\n");
        return;
    }

    fread(num_auctions, sizeof(int), 1, file);

    for (int i = 0; i < *num_auctions; i++) {
        auctions[i] = (Auction *) malloc(sizeof(Auction));
        fread(auctions[i], sizeof(Auction), 1, file);
    }

    fclose(file);
}