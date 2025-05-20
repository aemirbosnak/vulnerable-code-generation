//GEMINI-pro DATASET v1.0 Category: Wireless Network Scanner ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <pthread.h>

#define MAX_CONNECTIONS 100
#define MAX_SSID_LENGTH 32

struct client_info {
    int sockfd;
    char ssid[MAX_SSID_LENGTH];
    int channel;
    int signal_strength;
};

void *client_handler(void *arg) {
    struct client_info *client = (struct client_info *)arg;
    char buffer[1024];

    // Receive SSID from client
    recv(client->sockfd, buffer, sizeof(buffer), 0);
    strcpy(client->ssid, buffer);

    // Receive channel from client
    recv(client->sockfd, buffer, sizeof(buffer), 0);
    client->channel = atoi(buffer);

    // Receive signal strength from client
    recv(client->sockfd, buffer, sizeof(buffer), 0);
    client->signal_strength = atoi(buffer);

    printf("Received data from client: SSID: %s, Channel: %d, Signal Strength: %d\n",
           client->ssid, client->channel, client->signal_strength);

    // Send response to client
    strcpy(buffer, "OK");
    send(client->sockfd, buffer, strlen(buffer), 0);

    // Close client socket
    close(client->sockfd);

    pthread_exit(NULL);
}

int main(int argc, char *argv[]) {
    int server_sockfd, client_sockfd, port;
    struct sockaddr_in server_address, client_address;
    socklen_t client_address_len;
    pthread_t client_thread;

    // Parse command line arguments
    if (argc != 2) {
        printf("Usage: %s <port>\n", argv[0]);
        exit(1);
    }
    port = atoi(argv[1]);

    // Create server socket
    server_sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_sockfd == -1) {
        perror("socket");
        exit(1);
    }

    // Set server address
    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(port);

    // Bind server socket to address
    if (bind(server_sockfd, (struct sockaddr *)&server_address, sizeof(server_address)) == -1) {
        perror("bind");
        exit(1);
    }

    // Listen for client connections
    if (listen(server_sockfd, MAX_CONNECTIONS) == -1) {
        perror("listen");
        exit(1);
    }

    // Accept client connections
    while (1) {
        client_address_len = sizeof(client_address);
        client_sockfd = accept(server_sockfd, (struct sockaddr *)&client_address, &client_address_len);
        if (client_sockfd == -1) {
            perror("accept");
            continue;
        }

        // Create client thread
        struct client_info *client = malloc(sizeof(struct client_info));
        client->sockfd = client_sockfd;
        pthread_create(&client_thread, NULL, client_handler, (void *)client);
    }

    // Close server socket
    close(server_sockfd);

    return 0;
}