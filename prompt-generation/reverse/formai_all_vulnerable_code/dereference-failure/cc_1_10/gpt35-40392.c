//FormAI DATASET v1.0 Category: Banking Record System ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CLIENTS 100
// maximum number of clients in the system

typedef struct client_t {
    int account_num;
    char name[100];
    double balance;
} client_t;

typedef struct record_system_t {
    client_t clients[MAX_CLIENTS];
    int num_clients;
} record_system_t;

// initialize a new record system
record_system_t* create_record_system() {
    record_system_t* system = malloc(sizeof(record_system_t));
    memset(system, 0, sizeof(record_system_t));
    return system;
}

// add a new client to the record system
void add_client(record_system_t* system, int account_num, char* name, double balance) {
    if (system->num_clients >= MAX_CLIENTS) {
        printf("Error: maximum number of clients reached!\n");
        return;
    }
    client_t client;
    client.account_num = account_num;
    strcpy(client.name, name);
    client.balance = balance;
    system->clients[system->num_clients] = client;
    system->num_clients++;
    printf("New client added: %s (Account #: %d, Balance: $%.2f)\n", name, account_num, balance);
}

// get client by account number
client_t* get_client(record_system_t* system, int account_num) {
    for (int i = 0; i < system->num_clients; i++) {
        if (system->clients[i].account_num == account_num) {
            return &(system->clients[i]);
        }
    }
    return NULL;
}

int main() {
    record_system_t* system = create_record_system();

    add_client(system, 123, "John Doe", 5000);
    add_client(system, 456, "Jane Smith", 8000);

    client_t* client;

    client = get_client(system, 123);
    printf("Client name: %s\n", client->name);
    printf("Client balance: $%.2f\n", client->balance);

    client = get_client(system, 789);
    if (client == NULL) {
        printf("Client not found.\n");
    }

    free(system);
    return 0;
}