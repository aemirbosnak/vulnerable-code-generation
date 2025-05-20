//Gemma-7B DATASET v1.0 Category: System administration ; Style: configurable
#include <stdio.h>
#include <stdlib.h>

#define MAX_SERVERS 10
#define MAX_Clients 20

typedef struct Client {
    char name[20];
    int id;
    struct Client* next;
} Client;

typedef struct Server {
    char name[20];
    int id;
    Client* clients;
    struct Server* next;
} Server;

Server* head_server = NULL;
Client* head_client = NULL;

void insert_client(char* name, int id) {
    Client* new_client = (Client*)malloc(sizeof(Client));
    strcpy(new_client->name, name);
    new_client->id = id;
    new_client->next = NULL;

    if (head_client == NULL) {
        head_client = new_client;
    } else {
        Client* temp = head_client;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = new_client;
    }
}

void insert_server(char* name, int id) {
    Server* new_server = (Server*)malloc(sizeof(Server));
    strcpy(new_server->name, name);
    new_server->id = id;
    new_server->clients = NULL;
    new_server->next = NULL;

    if (head_server == NULL) {
        head_server = new_server;
    } else {
        Server* temp = head_server;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = new_server;
    }
}

void print_clients() {
    Client* temp = head_client;
    while (temp) {
        printf("%s (%d)  ", temp->name, temp->id);
    }
    printf("\n");
}

void print_servers() {
    Server* temp = head_server;
    while (temp) {
        printf("%s (%d)  ", temp->name, temp->id);
    }
    printf("\n");
}

int main() {
    insert_client("John Doe", 1);
    insert_client("Jane Doe", 2);
    insert_client("Peter Pan", 3);

    insert_server("Server A", 4);
    insert_server("Server B", 5);

    print_clients();
    print_servers();

    return 0;
}