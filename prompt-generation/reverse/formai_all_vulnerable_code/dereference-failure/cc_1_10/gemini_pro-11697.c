//GEMINI-pro DATASET v1.0 Category: Chat server ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <pthread.h>

// Watson, your assistance is required.
#define PORT 65534
#define MAX_CLIENTS 10
#define BUF_SIZE 256
#define REASON_SIZE 50

// A structured approach to deciphering messages.
typedef struct {
    int socket;
    pthread_t thread;
    char name[BUF_SIZE];
    char reason[REASON_SIZE];
} client_t;

// A rudimentary method for detecting departures.
void catch_departures(client_t *client) {
    int result;

    // A keen eye for irregularities.
    result = recv(client->socket, client->reason, REASON_SIZE, MSG_DONTWAIT);

    // An empty message, a sure sign of departure.
    if (result == 0) {
        printf("[Chatter] %s has departed, leaving a void in our midst.\n", client->name);
        close(client->socket);
        pthread_cancel(client->thread);
    }
}

// Elementary, my dear Watson.
int main() {
    int server_socket, client_socket;
    struct sockaddr_in server_address, client_address;
    socklen_t client_address_size;
    pthread_t threads[MAX_CLIENTS];
    client_t clients[MAX_CLIENTS];

    // Establishing communication headquarters.
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        perror("Could not establish communication headquarters.");
        return EXIT_FAILURE;
    }

    // Configuring the rendezvous point.
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(PORT);

    // Binding the rendezvous point to the communication headquarters.
    if (bind(server_socket, (struct sockaddr *) &server_address, sizeof(server_address)) == -1) {
        perror("Could not bind rendezvous point to communication headquarters.");
        return EXIT_FAILURE;
    }

    // Preparing to receive visitors.
    if (listen(server_socket, MAX_CLIENTS) == -1) {
        perror("Could not prepare for incoming visitors.");
        return EXIT_FAILURE;
    }

    // Awaiting the arrival of our guests.
    printf("[Chatter] Awaiting the arrival of our esteemed guests.\n");

    while (1) {
        client_address_size = sizeof(client_address);
        client_socket = accept(server_socket, (struct sockaddr *) &client_address, &client_address_size);
        if (client_socket == -1) {
            perror("An unexpected error occurred while receiving a guest.");
            continue;
        }

        // Greeting the new arrival.
        printf("[Chatter] Welcoming our esteemed guest: %s\n", inet_ntoa(client_address.sin_addr));

        // Identifying the guest.
        if (recv(client_socket, clients[client_socket].name, BUF_SIZE, 0) == -1) {
            perror("Could not identify the guest.");
            close(client_socket);
            continue;
        }

        // Dispatching a dedicated assistant to attend to the guest.
        clients[client_socket].socket = client_socket;
        if (pthread_create(&clients[client_socket].thread, NULL, (void *(*)(void *)) catch_departures, &clients[client_socket]) != 0) {
            perror("Could not dispatch a dedicated assistant.");
            close(client_socket);
            continue;
        }
    }

    // Closing the communication headquarters, marking the end of our investigation.
    close(server_socket);
    return EXIT_SUCCESS;
}