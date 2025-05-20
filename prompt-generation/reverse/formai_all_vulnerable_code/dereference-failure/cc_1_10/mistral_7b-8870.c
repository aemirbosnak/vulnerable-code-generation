//MISTRAL-7B DATASET v1.0 Category: Banking Record System ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CLIENTS 100
#define MAX_TRANSACTIONS 10
#define MAX_NAME_LENGTH 30
#define MAX_ACCOUNT_NUMBER_LENGTH 20
#define MAX_AMOUNT_LENGTH 11

typedef struct {
    char name[MAX_NAME_LENGTH];
    int accountNumber;
    float balance;
    int numTransactions;
    struct {
        int transactionNumber;
        float amount;
        char date[11];
    } transactions[MAX_TRANSACTIONS];
} Client;

void initializeClient(Client *client) {
    strcpy(client->name, "");
    client->accountNumber = 0;
    client->balance = 0.0;
    client->numTransactions = 0;
}

void printClient(Client client) {
    printf("Name: %s\n", client.name);
    printf("Account Number: %06d\n", client.accountNumber);
    printf("Balance: %.2f\n", client.balance);
    printf("Number of Transactions: %d\n", client.numTransactions);
    for (int i = 0; i < client.numTransactions; i++) {
        printf("Transaction %d:\n", client.transactions[i].transactionNumber);
        printf("Date: %s\n", client.transactions[i].date);
        printf("Amount: %.2f\n", client.transactions[i].amount);
    }
}

void addTransaction(Client *client, int transactionNumber, float amount, char date[11]) {
    if (client->numTransactions >= MAX_TRANSACTIONS) {
        printf("Error: Maximum number of transactions reached.\n");
        return;
    }

    strcpy(client->transactions[client->numTransactions].date, date);
    client->transactions[client->numTransactions].amount = amount;
    client->transactions[client->numTransactions].transactionNumber = transactionNumber;
    client->balance += amount;
    client->numTransactions++;
}

int main() {
    Client clients[MAX_CLIENTS];
    int numClients = 0;

    while (numClients < MAX_CLIENTS && fgetc(stdin) != EOF) {
        Client newClient;
        initializeClient(&newClient);

        fscanf(stdin, "%s", newClient.name);
        newClient.accountNumber = atoi(fgets(newClient.name + strlen(newClient.name), MAX_NAME_LENGTH - strlen(newClient.name), stdin));
        newClient.accountNumber *= 100000;

        fscanf(stdin, "%f", &newClient.balance);

        for (int i = 0; i < MAX_TRANSACTIONS && fgetc(stdin) != EOF; i++) {
            char date[11];
            fscanf(stdin, "%s", date);
            float amount;
            fscanf(stdin, "%f", &amount);
            addTransaction(&newClient, i + 1, amount, date);
        }

        clients[numClients++] = newClient;
    }

    for (int i = 0; i < numClients; i++) {
        printf("Client %d:\n", i + 1);
        printClient(clients[i]);
    }

    return 0;
}