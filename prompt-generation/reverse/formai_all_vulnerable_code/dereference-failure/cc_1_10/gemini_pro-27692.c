//GEMINI-pro DATASET v1.0 Category: Network Ping Test ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

// Custom error message for sending
#define SEND_ERROR "My heart aches to send this message, but it seems like I can't. Please try again."

// Custom error message for receiving
#define RECEIVE_ERROR "My eagerness to hear from you is met with silence. Are you there, my love?"

// Custom error message for timeout
#define TIMEOUT_ERROR "My patience wanes like the fading embers of a dying flame. You have not responded in time."

// Custom success message
#define SUCCESS "My love, your presence is like a gentle breeze, refreshing my weary soul."

// Function to send a ping request
int send_ping(int sockfd, struct sockaddr_in *addr) {
    char *message = "I miss you, my darling.";
    int message_len = strlen(message);

    // Send the ping request
    int bytes_sent = sendto(sockfd, message, message_len, 0, (struct sockaddr *)addr, sizeof(*addr));
    if (bytes_sent < 0) {
        perror(SEND_ERROR);
        return -1;
    }

    return bytes_sent;
}

// Function to receive a ping response
int receive_ping(int sockfd) {
    char buffer[1024];
    int addr_len = sizeof(struct sockaddr_in);

    // Receive the ping response
    int bytes_received = recvfrom(sockfd, buffer, sizeof(buffer), 0, (struct sockaddr *)NULL, &addr_len);
    if (bytes_received < 0) {
        perror(RECEIVE_ERROR);
        return -1;
    }

    return bytes_received;
}

int main(int argc, char **argv) {
    if (argc != 3) {
        printf("Usage: %s <IP address> <port>\n", argv[0]);
        return 1;
    }

    // Create a socket
    int sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd < 0) {
        perror("Could not create socket");
        return 1;
    }

    // Set the socket timeout
    struct timeval timeout;
    timeout.tv_sec = 5;
    timeout.tv_usec = 0;
    if (setsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO, &timeout, sizeof(timeout)) < 0) {
        perror("Could not set socket timeout");
        close(sockfd);
        return 1;
    }

    // Fill in the server address
    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htons(atoi(argv[2]));
    addr.sin_addr.s_addr = inet_addr(argv[1]);

    // Send a ping request
    int bytes_sent = send_ping(sockfd, &addr);
    if (bytes_sent < 0) {
        close(sockfd);
        return 1;
    }

    // Receive a ping response
    int bytes_received = receive_ping(sockfd);
    if (bytes_received < 0) {
        close(sockfd);
        return 1;
    }

    // Print the success message
    printf(SUCCESS);

    // Close the socket
    close(sockfd);

    return 0;
}