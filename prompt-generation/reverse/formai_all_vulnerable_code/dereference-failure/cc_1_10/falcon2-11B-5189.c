//Falcon2-11B DATASET v1.0 Category: Networking ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define SERVER_PORT 8080

// Structure to hold client information
typedef struct {
    int sockfd;
    char client_name[20];
    char client_msg[100];
} ClientInfo;

// Function to handle incoming client connections
void handle_client(ClientInfo* client_info, int sockfd) {
    // Receive client name
    bzero(client_info->client_name, sizeof(client_info->client_name));
    bzero(client_info->client_msg, sizeof(client_info->client_msg));
    recv(sockfd, client_info->client_name, sizeof(client_info->client_name), 0);
    recv(sockfd, client_info->client_msg, sizeof(client_info->client_msg), 0);

    printf("Client %s has joined the chat.\n", client_info->client_name);

    // Receive messages from client
    while (1) {
        bzero(client_info->client_msg, sizeof(client_info->client_msg));
        int msg_len = recv(sockfd, client_info->client_msg, sizeof(client_info->client_msg), 0);
        if (msg_len <= 0) {
            printf("Client %s has left the chat.\n", client_info->client_name);
            break;
        }
        printf("Client %s: %s\n", client_info->client_name, client_info->client_msg);
    }

    // Clean up client resources
    close(sockfd);
    free(client_info);
}

// Main function
int main() {
    int sockfd, new_sockfd, portno;
    struct sockaddr_in serv_addr, cli_addr;

    // Create socket
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // Set up server address struct
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(SERVER_PORT);

    // Bind socket to port
    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) == -1) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(sockfd, 5) == -1) {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    printf("Chat server is listening on port %d...\n", SERVER_PORT);

    while (1) {
        // Accept a connection from a client
        bzero((char *) &cli_addr, sizeof(cli_addr));
        if ((new_sockfd = accept(sockfd, (struct sockaddr *) &cli_addr, (socklen_t *) &portno)) == -1) {
            perror("accept");
            exit(EXIT_FAILURE);
        }

        // Allocate memory for client information
        ClientInfo* client_info = (ClientInfo*) malloc(sizeof(ClientInfo));
        if (client_info == NULL) {
            perror("malloc");
            exit(EXIT_FAILURE);
        }

        // Start handling client connections
        handle_client(client_info, new_sockfd);

        // Clean up resources
        free(client_info);
        close(new_sockfd);
    }

    return 0;
}