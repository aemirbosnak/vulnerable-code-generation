//FormAI DATASET v1.0 Category: Levenshtein Distance Calculator ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <errno.h>

#define MAX_BUFFER_SIZE 1024
#define LEVENSHTEIN_THRESHOLD 5

/**
 * Computes the minimum of 3 values.
 */
int min(int a, int b, int c) {
    int min = a;
    if (b < min) {
        min = b;
    }
    if (c < min) {
        min = c;
    }
    return min;
}

/**
 * Computes the Levenshtein distance between two strings using dynamic programming.
 */
int levenshtein_distance(char *s1, char *s2) {
    int m = strlen(s1);
    int n = strlen(s2);
    int D[m+1][n+1];

    // Initialize the first row and column of the matrix.
    for (int i = 0; i <= m; i++) {
        D[i][0] = i;
    }
    for (int j = 0; j <= n; j++) {
        D[0][j] = j;
    }

    // Fill in the rest of the matrix.
    for (int j = 1; j <= n; j++) {
        for (int i = 1; i <= m; i++) {
            int cost = s1[i-1] == s2[j-1] ? 0 : 1;
            D[i][j] = min(
                D[i-1][j] + 1, // Deletion
                D[i][j-1] + 1, // Insertion
                D[i-1][j-1] + cost // Substitution
            );
        }
    }

    return D[m][n];
}

int main() {
    int sockfd, client_sockfd;
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_addrlen = sizeof(client_addr);
    char buffer[MAX_BUFFER_SIZE];

    // Create a socket file descriptor.
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("Failed to create socket");
        exit(errno);
    }

    // Bind the socket to a port.
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(8080);
    if (bind(sockfd, (struct sockaddr *) &server_addr, sizeof(server_addr)) == -1) {
        perror("Failed to bind socket");
        exit(errno);
    }

    // Listen for incoming connections.
    if (listen(sockfd, SOMAXCONN) == -1) {
        perror("Failed to listen for incoming connections");
        exit(errno);
    }
    printf("Listening on port 8080...\n");

    while (true) {
        // Accept a new client connection.
        if ((client_sockfd = accept(sockfd, (struct sockaddr *) &client_addr, &client_addrlen)) == -1) {
            perror("Failed to accept client connection");
            continue;
        }
        printf("Accepted a new client connection from %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

        // Receive data from the client.
        memset(buffer, 0, sizeof(buffer));
        ssize_t bytes_received = recv(client_sockfd, buffer, sizeof(buffer), 0);
        if (bytes_received == -1) {
            perror("Failed to receive data from client");
            close(client_sockfd);
            continue;
        }
        printf("Received %zd bytes from client: %s\n", bytes_received, buffer);

        // Compute the Levenshtein distance between the received string and "hello world".
        int distance = levenshtein_distance(buffer, "hello world");
        printf("Levenshtein distance between \"%s\" and \"hello world\" is %d\n", buffer, distance);

        // Send a response to the client.
        if (distance <= LEVENSHTEIN_THRESHOLD) {
            char *response = "Your string is similar to \"hello world\"\n";
            ssize_t bytes_sent = send(client_sockfd, response, strlen(response), 0);
            if (bytes_sent == -1) {
                perror("Failed to send response to client");
                close(client_sockfd);
                continue;
            }
            printf("Sent %zd bytes to client: %s", bytes_sent, response);
        } else {
            char *response = "Your string is not similar enough to \"hello world\"\n";
            ssize_t bytes_sent = send(client_sockfd, response, strlen(response), 0);
            if (bytes_sent == -1) {
                perror("Failed to send response to client");
                close(client_sockfd);
                continue;
            }
            printf("Sent %zd bytes to client: %s", bytes_sent, response);
        }

        // Close the client socket.
        close(client_sockfd);
    }

    return 0;
}