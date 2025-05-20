//Falcon-180B DATASET v1.0 Category: Chat server ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define TRUE   1
#define FALSE  0
#define PORT 8888
#define BACKLOG 10

typedef struct client {
    int sock;
    char name[20];
    struct client *next;
} Client;

Client *head = NULL;

void broadcast(char msg[], Client *c) {
    while (c!= NULL) {
        send(c->sock, msg, strlen(msg), 0);
        c = c->next;
    }
}

void add_client(int sock, char name[]) {
    Client *new_client = (Client *) malloc(sizeof(Client));
    strcpy(new_client->name, name);
    new_client->sock = sock;
    new_client->next = NULL;

    if (head == NULL) {
        head = new_client;
    } else {
        Client *temp = head;
        while (temp->next!= NULL) {
            temp = temp->next;
        }
        temp->next = new_client;
    }
}

void remove_client(int sock) {
    Client *temp = head;
    Client *prev = NULL;

    while (temp!= NULL && temp->sock!= sock) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        return;
    }

    if (prev == NULL) {
        head = temp->next;
    } else {
        prev->next = temp->next;
    }

    free(temp);
}

int main() {
    int sock, newsock, len, valread;
    struct sockaddr_in serv_addr, cli_addr;

    sock = socket(AF_INET, SOCK_STREAM, 0);

    if (sock < 0) {
        printf("Error creating socket\n");
        return 1;
    }

    bzero(&serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(PORT);

    if (bind(sock, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        printf("Error binding socket\n");
        return 1;
    }

    listen(sock, BACKLOG);

    while (TRUE) {
        printf("Waiting for client to connect...\n");
        len = sizeof(cli_addr);
        newsock = accept(sock, (struct sockaddr *) &cli_addr, &len);

        if (newsock < 0) {
            printf("Error accepting connection\n");
            continue;
        }

        char name[20];
        bzero(name, sizeof(name));
        recv(newsock, name, sizeof(name), 0);

        add_client(newsock, name);
        printf("Client %s added to chat\n", name);

        broadcast("New client joined: ", head->next);
    }

    close(sock);
    return 0;
}