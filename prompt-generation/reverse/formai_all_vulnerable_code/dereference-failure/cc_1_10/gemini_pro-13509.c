//GEMINI-pro DATASET v1.0 Category: Digital Auction System ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 8080

// Structure to represent a client
typedef struct client {
    int sockfd;
    pthread_t thread_id;
    char name[100];
} client_t;

// Structure to represent an auction item
typedef struct auction_item {
    int id;
    char name[100];
    float current_bid;
    int current_bidder;
} auction_item_t;

// Array to store all connected clients
client_t clients[100];
int num_clients = 0;

// Array to store all auction items
auction_item_t auction_items[100];
int num_items = 0;

// Mutex to protect access to shared data
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

// Function to handle incoming client connections
void *handle_client(void *arg) {
    // Get the client socket descriptor
    int sockfd = *(int *)arg;

    // Receive the client's name
    char name[100];
    recv(sockfd, name, sizeof(name), 0);

    // Create a client struct and add it to the array of clients
    client_t client;
    client.sockfd = sockfd;
    client.thread_id = pthread_self();
    strcpy(client.name, name);
    clients[num_clients++] = client;

    // Send the list of auction items to the client
    for (int i = 0; i < num_items; i++) {
        char message[100];
        sprintf(message, "%d %s %f %d\n", auction_items[i].id, auction_items[i].name, auction_items[i].current_bid, auction_items[i].current_bidder);
        send(sockfd, message, strlen(message), 0);
    }

    // Loop to receive and handle messages from the client
    while (1) {
        // Receive the message
        char message[100];
        recv(sockfd, message, sizeof(message), 0);

        // Parse the message
        char command[100];
        int item_id;
        float bid_amount;
        sscanf(message, "%s %d %f", command, &item_id, &bid_amount);

        // Handle the message
        if (strcmp(command, "bid") == 0) {
            // Find the auction item with the specified ID
            auction_item_t *item = NULL;
            for (int i = 0; i < num_items; i++) {
                if (auction_items[i].id == item_id) {
                    item = &auction_items[i];
                    break;
                }
            }

            // Check if the bid amount is valid
            if (item == NULL || bid_amount <= item->current_bid) {
                char message[100];
                sprintf(message, "Invalid bid amount for item %d\n", item_id);
                send(sockfd, message, strlen(message), 0);
            } else {
                // Update the current bid and current bidder
                pthread_mutex_lock(&mutex);
                item->current_bid = bid_amount;
                item->current_bidder = client.sockfd;
                pthread_mutex_unlock(&mutex);

                // Broadcast the new bid to all clients
                char message[100];
                sprintf(message, "New bid for item %d: %f by %s\n", item_id, bid_amount, client.name);
                for (int i = 0; i < num_clients; i++) {
                    send(clients[i].sockfd, message, strlen(message), 0);
                }
            }
        } else if (strcmp(command, "quit") == 0) {
            // Remove the client from the array of clients
            for (int i = 0; i < num_clients; i++) {
                if (clients[i].sockfd == sockfd) {
                    clients[i] = clients[num_clients - 1];
                    num_clients--;
                    break;
                }
            }

            // Close the client's socket
            close(sockfd);

            // Exit the thread
            pthread_exit(NULL);
        }
    }

    return NULL;
}

int main() {
    // Create a socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        return 1;
    }

    // Bind the socket to the specified port
    struct sockaddr_in servaddr;
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(PORT);
    if (bind(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
        perror("bind");
        return 1;
    }

    // Listen for incoming client connections
    if (listen(sockfd, 10) < 0) {
        perror("listen");
        return 1;
    }

    // Loop to accept incoming client connections
    while (1) {
        // Accept the incoming client connection
        int newsockfd = accept(sockfd, NULL, NULL);
        if (newsockfd < 0) {
            perror("accept");
            continue;
        }

        // Create a new thread to handle the client connection
        pthread_t thread_id;
        int *arg = malloc(sizeof(int));
        *arg = newsockfd;
        if (pthread_create(&thread_id, NULL, handle_client, arg) != 0) {
            perror("pthread_create");
            close(newsockfd);
            continue;
        }
    }

    // Close the socket
    close(sockfd);

    return 0;
}