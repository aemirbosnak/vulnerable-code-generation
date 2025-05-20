//Gemma-7B DATASET v1.0 Category: System administration ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CONNECTIONS 10

struct connection {
    char name[256];
    struct connection *next;
    int online;
    char message[256];
};

struct connection **head = NULL;

void add_connection(char *name) {
    struct connection *new_connection = malloc(sizeof(struct connection));
    strcpy(new_connection->name, name);
    new_connection->next = NULL;
    new_connection->online = 0;
    new_connection->message[0] = '\0';

    if (head == NULL) {
        head = new_connection;
    } else {
        struct connection *temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = new_connection;
    }
}

void send_message(char *to, char *message) {
    struct connection *connection = head;
    while (connection) {
        if (strcmp(connection->name, to) == 0 && connection->online) {
            strcpy(connection->message, message);
            connection->online = 0;
            break;
        }
        connection = connection->next;
    }
}

int main() {
    add_connection("John Doe");
    add_connection("Jane Doe");
    add_connection("Bob Smith");

    send_message("John Doe", "Hello, John!");

    return 0;
}