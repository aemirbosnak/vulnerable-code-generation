//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

int main(int argc, char *argv[]) {

    if (argc < 2) {
        fprintf(stderr, "Usage: %s <hostname> <port>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    char *hostname = argv[1];
    char *port = argv[2];

    // Get server IP address
    struct hostent *server = gethostbyname(hostname);
    if (server == NULL) {
        fprintf(stderr, "Error: No such host \"%s\"\n", hostname);
        exit(EXIT_FAILURE);
    }

    // Initialize socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Error: Failed to open socket");
        exit(EXIT_FAILURE);
    }

    // Define server address
    struct sockaddr_in serv_addr;
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr = *((struct in_addr *)server->h_addr);
    serv_addr.sin_port = htons(atoi(port));

    // Connect to server
    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("Error: Failed to connect");
        exit(EXIT_FAILURE);
    }

    // Send HTTP request
    char request[256];
    snprintf(request, sizeof(request), "GET / HTTP/1.1\r\nHost: %s\r\n\r\n", hostname);
    int bytes_sent = send(sockfd, request, strlen(request), 0);
    if (bytes_sent < 0) {
        perror("Error: Failed to send request");
        exit(EXIT_FAILURE);
    } else {
        printf("Sent %d bytes:\n%s", bytes_sent, request);
    }

    // Receive HTTP response
    char response[4096];
    int bytes_received = recv(sockfd, response, sizeof(response), 0);
    if (bytes_received < 0) {
        perror("Error: Failed to receive response");
        exit(EXIT_FAILURE);
    } else {
        printf("Received %d bytes:\n", bytes_received);
        printf("%s\n", response);
    }

    // Close socket
    if (close(sockfd) < 0) {
        perror("Error: Failed to close socket");
        exit(EXIT_FAILURE);
    }

    return 0;
}