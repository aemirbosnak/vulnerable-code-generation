//GEMINI-pro DATASET v1.0 Category: Networking ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <netdb.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <sys/socket.h>

// Constants
#define MAX_DATA_SIZE 1024
#define PORT 8080

// Main function
int main(int argc, char *argv[]) {
    // Check for correct number of arguments
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <hostname>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Get hostname from command line
    char *hostname = argv[1];

    // Resolve hostname to IP address
    struct hostent *host = gethostbyname(hostname);
    if (!host) {
        herror("gethostbyname");
        exit(EXIT_FAILURE);
    }

    // Create a socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    // Set up server address
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    memcpy(&server_addr.sin_addr.s_addr, host->h_addr_list[0], host->h_length);

    // Connect to server
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("connect");
        exit(EXIT_FAILURE);
    }

    // Send data to server
    char *data = "Hello, world!";
    int data_len = strlen(data);
    if (send(sockfd, data, data_len, 0) < 0) {
        perror("send");
        exit(EXIT_FAILURE);
    }

    // Receive data from server
    char buffer[MAX_DATA_SIZE];
    int recv_len = recv(sockfd, buffer, MAX_DATA_SIZE, 0);
    if (recv_len < 0) {
        perror("recv");
        exit(EXIT_FAILURE);
    }

    // Print data received from server
    printf("Received from server: %s\n", buffer);

    // Close socket
    close(sockfd);

    return EXIT_SUCCESS;
}