//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <errno.h>
#include <unistd.h>

#define BUF_SIZE 1024
#define MAX_CLIENTS 10

void error(char *msg) {
    perror(msg);
    exit(1);
}

// Struct to store client information
struct client {
    int sockfd;
    char *ip_address;
    int port;
    int packets_sent;
    int packets_lost;
    float packet_loss_rate;
};

// Function to calculate packet loss rate for a client
float calculate_packet_loss_rate(int packets_sent, int packets_lost) {
    if (packets_sent == 0) {
        return 0.0;
    } else {
        return ((float) packets_lost / packets_sent) * 100;
    }
}

int main(int argc, char *argv[]) {
    int sockfd, newsockfd, portno;
    socklen_t clilen;
    char buffer[BUF_SIZE];
    struct sockaddr_in serv_addr, cli_addr;
    int n, i, j, max_sd, activity, sd;
    fd_set readfds;
    struct client clients[MAX_CLIENTS];
    int client_count = 0;

    if (argc < 2) {
        fprintf(stderr, "ERROR, no port provided\n");
        exit(1);
    }

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        error("ERROR opening socket");
    }

    // Initialize server address
    bzero((char *) &serv_addr, sizeof(serv_addr));
    portno = atoi(argv[1]);
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);

    // Bind socket to server address
    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        error("ERROR on binding");
    }

    // Listen for incoming connections
    if (listen(sockfd, 5) < 0) {
        error("ERROR on listen");
    }

    // Print message on successful startup
    printf("QoS monitor started on port %d\n", portno);

    while (1) {
        // Clear file descriptor set
        FD_ZERO(&readfds);

        // Add master socket to set
        FD_SET(sockfd, &readfds);
        max_sd = sockfd;

        // Add child sockets to set
        for (i = 0; i < MAX_CLIENTS; i++) {
            sd = clients[i].sockfd;

            // If valid socket descriptor then add to read list
            if (sd > 0) {
                FD_SET(sd, &readfds);
            }

            // Highest file descriptor number, need it for the select function
            if (sd > max_sd) {
                max_sd = sd;
            }
        }

        // Wait for activity on any of the sockets
        activity = select(max_sd + 1, &readfds, NULL, NULL, NULL);
        if (activity < 0 && errno != EINTR) {
            error("ERROR on select");
        }

        // Incoming connection
        if (FD_ISSET(sockfd, &readfds)) {
            clilen = sizeof(cli_addr);
            newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);
            if (newsockfd < 0) {
                error("ERROR on accept");
            }

            // Print message on new connection
            printf("New connection from %s:%d\n", inet_ntoa(cli_addr.sin_addr), ntohs(cli_addr.sin_port));

            // Add new socket to client list
            for (i = 0; i < MAX_CLIENTS; i++) {
                if (clients[i].sockfd == 0) {
                    clients[i].sockfd = newsockfd;
                    clients[i].ip_address = inet_ntoa(cli_addr.sin_addr);
                    clients[i].port = ntohs(cli_addr.sin_port);
                    clients[i].packets_sent = 0;
                    clients[i].packets_lost = 0;
                    client_count++;
                    break;
                }
            }
        }

        // Check for activity on existing sockets
        for (i = 0; i < MAX_CLIENTS; i++) {
            sd = clients[i].sockfd;

            if (FD_ISSET(sd, &readfds)) {
                // Read incoming data
                bzero(buffer, BUF_SIZE);
                n = read(sd, buffer, BUF_SIZE);
                if (n < 0) {
                    error("ERROR reading from socket");
                }

                // Packet received
                if (n > 0) {
                    // Increment packets sent counter
                    clients[i].packets_sent++;

                    // Check for packet loss
                    if (strlen(buffer) == 0) {
                        clients[i].packets_lost++;
                    }

                    // Calculate packet loss rate
                    clients[i].packet_loss_rate = calculate_packet_loss_rate(clients[i].packets_sent, clients[i].packets_lost);
                }

                // Connection closed by client
                if (n == 0) {
                    // Print message on connection closed
                    printf("Connection closed by %s:%d\n", clients[i].ip_address, clients[i].port);

                    // Close socket
                    close(sd);

                    // Remove socket from client list
                    clients[i].sockfd = 0;
                    clients[i].ip_address = NULL;
                    clients[i].port = 0;
                    clients[i].packets_sent = 0;
                    clients[i].packets_lost = 0;
                    clients[i].packet_loss_rate = 0.0;
                    client_count--;
                }
            }
        }
    }
    return 0;
}