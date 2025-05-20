//GEMINI-pro DATASET v1.0 Category: Banking Record System ; Style: surrealist
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct {
    char *name;
    int balance;
} account_t;

int main() {
    account_t accounts[10];

    // Initialize the accounts
    for (int i = 0; i < 10; i++) {
        accounts[i].name = malloc(20);
        accounts[i].balance = 0;
    }

    // Load the accounts with surrealist names
    strcpy(accounts[0].name, "The Invisible Pink Unicorn");
    strcpy(accounts[1].name, "The Cheshire Cat");
    strcpy(accounts[2].name, "The Mad Hatter");
    strcpy(accounts[3].name, "The White Rabbit");
    strcpy(accounts[4].name, "The Queen of Hearts");
    strcpy(accounts[5].name, "The March Hare");
    strcpy(accounts[6].name, "The Tweedledee and Tweedledum");
    strcpy(accounts[7].name, "The Walrus and the Carpenter");
    strcpy(accounts[8].name, "The Bandersnatch");
    strcpy(accounts[9].name, "The Jabberwocky");

    // Print the account balances
    for (int i = 0; i < 10; i++) {
        printf("%s: $%d\n", accounts[i].name, accounts[i].balance);
    }

    // Deposit some money into the accounts
    for (int i = 0; i < 10; i++) {
        accounts[i].balance += 100;
    }

    // Print the account balances again
    for (int i = 0; i < 10; i++) {
        printf("%s: $%d\n", accounts[i].name, accounts[i].balance);
    }

    // Free the memory allocated for the accounts
    for (int i = 0; i < 10; i++) {
        free(accounts[i].name);
    }

    return 0;
}