//Gemma-7B DATASET v1.0 Category: Digital Auction System ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define the auction structure
typedef struct Auction
{
    char item_name[20];
    int starting_bid;
    int reserve_price;
    int current_bid;
    struct Auction* next;
} Auction;

// Function to insert a new auction into the list
void insert_auction(Auction** head, char* item_name, int starting_bid, int reserve_price)
{
    Auction* new_auction = (Auction*)malloc(sizeof(Auction));
    strcpy(new_auction->item_name, item_name);
    new_auction->starting_bid = starting_bid;
    new_auction->reserve_price = reserve_price;
    new_auction->current_bid = starting_bid;
    new_auction->next = NULL;

    if (*head == NULL)
    {
        *head = new_auction;
    }
    else
    {
        (*head)->next = new_auction;
    }
}

// Function to get the highest bid
int get_highest_bid(Auction* head)
{
    int highest_bid = head->current_bid;

    while (head->next)
    {
        head = head->next;
        if (head->current_bid > highest_bid)
        {
            highest_bid = head->current_bid;
        }
    }

    return highest_bid;
}

// Function to close the auction
void close_auction(Auction** head)
{
    Auction* current_auction = *head;
    Auction* next_auction = NULL;

    while (current_auction)
    {
        next_auction = current_auction->next;
        free(current_auction);
        current_auction = next_auction;
    }

    *head = NULL;
}

// Main function
int main()
{
    Auction* head = NULL;

    // Insert some auctions
    insert_auction(&head, "iPhone", 500, 700);
    insert_auction(&head, "Laptop", 300, 500);
    insert_auction(&head, "Watch", 200, 300);

    // Get the highest bid
    int highest_bid = get_highest_bid(head);

    // Print the highest bid
    printf("The highest bid is: %d", highest_bid);

    // Close the auction
    close_auction(&head);

    return 0;
}