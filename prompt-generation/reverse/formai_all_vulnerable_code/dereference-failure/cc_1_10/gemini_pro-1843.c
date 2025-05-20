//GEMINI-pro DATASET v1.0 Category: Expense Tracker ; Style: multiplayer
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// Player struct
typedef struct player {
    char name[20];
    int balance;
    struct player *next;
} player;

// Transaction struct
typedef struct transaction {
    char description[50];
    int amount;
    struct transaction *next;
} transaction;

// Linked list of players
player *players = NULL;

// Linked list of transactions
transaction *transactions = NULL;

// Create a new player
player *create_player(char *name, int balance) {
    player *new_player = malloc(sizeof(player));
    strcpy(new_player->name, name);
    new_player->balance = balance;
    new_player->next = NULL;
    return new_player;
}

// Add a player to the linked list of players
void add_player(player *new_player) {
    if (players == NULL) {
        players = new_player;
    } else {
        player *current_player = players;
        while (current_player->next != NULL) {
            current_player = current_player->next;
        }
        current_player->next = new_player;
    }
}

// Create a new transaction
transaction *create_transaction(char *description, int amount) {
    transaction *new_transaction = malloc(sizeof(transaction));
    strcpy(new_transaction->description, description);
    new_transaction->amount = amount;
    new_transaction->next = NULL;
    return new_transaction;
}

// Add a transaction to the linked list of transactions
void add_transaction(transaction *new_transaction) {
    if (transactions == NULL) {
        transactions = new_transaction;
    } else {
        transaction *current_transaction = transactions;
        while (current_transaction->next != NULL) {
            current_transaction = current_transaction->next;
        }
        current_transaction->next = new_transaction;
    }
}

// Print the linked list of players
void print_players() {
    player *current_player = players;
    while (current_player != NULL) {
        printf("%s: %d\n", current_player->name, current_player->balance);
        current_player = current_player->next;
    }
}

// Print the linked list of transactions
void print_transactions() {
    transaction *current_transaction = transactions;
    while (current_transaction != NULL) {
        printf("%s: %d\n", current_transaction->description, current_transaction->amount);
        current_transaction = current_transaction->next;
    }
}

// Main function
int main() {
    // Create some players
    player *player1 = create_player("Player 1", 100);
    player *player2 = create_player("Player 2", 200);
    player *player3 = create_player("Player 3", 300);

    // Add the players to the linked list of players
    add_player(player1);
    add_player(player2);
    add_player(player3);

    // Create some transactions
    transaction *transaction1 = create_transaction("Bought coffee", -5);
    transaction *transaction2 = create_transaction("Received salary", 100);
    transaction *transaction3 = create_transaction("Paid rent", -200);

    // Add the transactions to the linked list of transactions
    add_transaction(transaction1);
    add_transaction(transaction2);
    add_transaction(transaction3);

    // Print the linked list of players
    printf("Players:\n");
    print_players();

    // Print the linked list of transactions
    printf("\nTransactions:\n");
    print_transactions();

    return 0;
}