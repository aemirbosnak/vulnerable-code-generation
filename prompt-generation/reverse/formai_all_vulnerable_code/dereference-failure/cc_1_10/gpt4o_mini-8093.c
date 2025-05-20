//GPT-4o-mini DATASET v1.0 Category: Digital Auction System ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <unistd.h>
#include <pthread.h>

#define PORT 8080
#define MAX_CLIENTS 10
#define BUFFER_SIZE 1024
#define MAX_ITEMS 5

typedef struct {
    int item_id;
    char name[50];
    float highest_bid;
    int highest_bidder;
} AuctionItem;

AuctionItem items[MAX_ITEMS];
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void* handle_client(void* client_socket) {
    int sock = *((int*)client_socket);
    char buffer[BUFFER_SIZE];
    
    while (1) {
        bzero(buffer, BUFFER_SIZE);
        read(sock, buffer, sizeof(buffer));
        int item_id;
        float bid_amount;

        if (sscanf(buffer, "%d %f", &item_id, &bid_amount) == 2) {
            pthread_mutex_lock(&mutex);
            
            if (item_id >= 0 && item_id < MAX_ITEMS) {
                if (bid_amount > items[item_id].highest_bid) {
                    items[item_id].highest_bid = bid_amount;
                    snprintf(buffer, sizeof(buffer), "Bid accepted for item %d. New highest bid: %.2f", item_id, bid_amount);
                } else {
                    snprintf(buffer, sizeof(buffer), "Bid rejected. Current highest bid for item %d: %.2f", item_id, items[item_id].highest_bid);
                }
            } else {
                snprintf(buffer, sizeof(buffer), "Invalid item ID.");
            }
            
            pthread_mutex_unlock(&mutex);
        } else {
            snprintf(buffer, sizeof(buffer), "Invalid input format.");
        }
        
        write(sock, buffer, strlen(buffer));
    }
    
    close(sock);
    return NULL;
}

int main() {
    for (int i = 0; i < MAX_ITEMS; i++) {
        items[i].item_id = i;
        sprintf(items[i].name, "Item%d", i + 1);
        items[i].highest_bid = 0.0;
        items[i].highest_bidder = -1;
    }

    int server_fd, new_socket;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    pthread_t tid;

    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Socket failed");
        exit(EXIT_FAILURE);
    }

    setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    if (bind(server_fd, (struct sockaddr*)&address, sizeof(address)) < 0) {
        perror("Bind failed");
        exit(EXIT_FAILURE);
    }

    if (listen(server_fd, 3) < 0) {
        perror("Listen failed");
        exit(EXIT_FAILURE);
    }

    printf("Auction server started. Waiting for clients...\n");

    while ((new_socket = accept(server_fd, (struct sockaddr*)&address, (socklen_t*)&addrlen))) {
        printf("New client connected.\n");
        pthread_create(&tid, NULL, handle_client, (void*)&new_socket);
    }

    return 0;
}