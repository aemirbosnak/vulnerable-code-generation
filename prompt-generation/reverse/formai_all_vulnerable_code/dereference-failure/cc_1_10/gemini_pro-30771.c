//GEMINI-pro DATASET v1.0 Category: TCP/IP Programming ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

// Function to send data to the server
int send_data(int sockfd, char *data) {
    // Send the length of the data first
    int len = strlen(data);
    if (send(sockfd, &len, sizeof(int), 0) == -1) {
        perror("send");
        return -1;
    }
    // Then send the data itself
    if (send(sockfd, data, len, 0) == -1) {
        perror("send");
        return -1;
    }
    return 0;
}

// Function to receive data from the server
int receive_data(int sockfd, char **data) {
    // Receive the length of the data first
    int len;
    if (recv(sockfd, &len, sizeof(int), 0) == -1) {
        perror("recv");
        return -1;
    }
    // Allocate memory for the data
    *data = malloc(len + 1);
    if (*data == NULL) {
        perror("malloc");
        return -1;
    }
    // Receive the data itself
    if (recv(sockfd, *data, len, 0) == -1) {
        perror("recv");
        free(*data);
        return -1;
    }
    // Null-terminate the data
    (*data)[len] = '\0';
    return 0;
}

int main() {
    // Create a socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        return EXIT_FAILURE;
    }
    // Connect to the server
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(8080);
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("connect");
        close(sockfd);
        return EXIT_FAILURE;
    }
    // Send data to the server
    char *data = "Hello from the client!";
    if (send_data(sockfd, data) == -1) {
        close(sockfd);
        return EXIT_FAILURE;
    }
    // Receive data from the server
    char *response;
    if (receive_data(sockfd, &response) == -1) {
        close(sockfd);
        return EXIT_FAILURE;
    }
    // Print the response from the server
    printf("Response from the server: %s\n", response);
    // Free the allocated memory
    free(response);
    // Close the socket
    close(sockfd);
    return EXIT_SUCCESS;
}