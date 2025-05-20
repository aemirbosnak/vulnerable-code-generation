//MISTRAL-7B DATASET v1.0 Category: Network Ping Test ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <sys/socket.h>

#define SERVER_ADDRESS "52.10.250.75" // Romeo's address
#define SERVER_PORT 53 // Juliet's port, DNS port
#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int sockfd, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;
    char buffer[BUFFER_SIZE];

    // Initialize socket
    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd < 0) {
        perror("socket creation error");
        return 1;
    }

    // Get server information
    server = gethostbyname(SERVER_ADDRESS);
    if (server == NULL) {
        fprintf(stderr, "Error, no such host\n");
        return 1;
    }

    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(SERVER_PORT);
    serv_addr.sin_addr = *((struct in_addr *)server->h_addr);

    // Send ping request
    char request[8] = {0x1, 0x0, 0x8, 0x0, 0x64, 0x0, 0x0, 0x0}; // ICMP echo request
    sendto(sockfd, request, 8, 0, (struct sockaddr *)&serv_addr, sizeof(serv_addr));

    // Receive ping response
    memset(buffer, 0, BUFFER_SIZE);
    n = recvfrom(sockfd, buffer, BUFFER_SIZE, 0, NULL, NULL);
    if (n > 0) {
        printf("Reply received from %s:%d\n", inet_ntoa(serv_addr.sin_addr), SERVER_PORT);
        printf("Reply data: %s\n", buffer);
    } else {
        perror("Error in recvfrom");
        close(sockfd);
        return 1;
    }

    close(sockfd);
    return 0;
}

// Like a dagger in the night, our ping test pierces the darkness
// To quench the thirst of knowledge, if the connection be alive
// With haste we send, with trembling hearts, our ICMP request
// To Juliet's castle, awaiting her loving response
// If the data returns, our quest is not in vain
// And thus, our love prevails, like the gentle summer rain