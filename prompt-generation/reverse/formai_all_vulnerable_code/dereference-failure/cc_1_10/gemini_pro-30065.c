//GEMINI-pro DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

#define BUF_SIZE 1024

typedef struct wifi_network {
    char ssid[33];
    int signal_strength;
} wifi_network;

int main() {
    int sockfd, newsockfd, portno, n;
    struct sockaddr_in serv_addr, cli_addr;
    socklen_t clilen;
    char buffer[BUF_SIZE];

    // Create a UDP socket
    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd < 0) {
        perror("ERROR opening socket");
        exit(1);
    }

    // Set the server address
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);

    // Allow multiple clients to connect to the server
    int optval = 1;
    setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &optval, sizeof(optval));

    // Bind the socket to the server address
    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("ERROR on binding");
        exit(1);
    }

    // Listen for incoming connections
    listen(sockfd, 5);

    // Loop forever, waiting for client connections
    while (1) {
        // Accept an incoming connection
        clilen = sizeof(cli_addr);
        newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);
        if (newsockfd < 0) {
            perror("ERROR on accept");
            exit(1);
        }

        // Receive the data from the client
        bzero(buffer, BUF_SIZE);
        n = recvfrom(newsockfd, buffer, BUF_SIZE, 0, (struct sockaddr *) &cli_addr, &clilen);
        if (n < 0) {
            perror("ERROR reading from socket");
            exit(1);
        }

        // Parse the received data
        char *ssid = strtok(buffer, ",");
        int signal_strength = atoi(strtok(NULL, ","));

        // Create a new wifi_network struct
        wifi_network network;
        strcpy(network.ssid, ssid);
        network.signal_strength = signal_strength;

        // Send the wifi_network struct back to the client
        n = sendto(newsockfd, &network, sizeof(network), 0, (struct sockaddr *) &cli_addr, clilen);
        if (n < 0) {
            perror("ERROR writing to socket");
            exit(1);
        }

        // Close the connection with the client
        close(newsockfd);
    }

    // Close the server socket
    close(sockfd);

    return 0;
}