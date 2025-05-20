//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio_ext.h>
#include <netdb.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

#define PORT 8080
#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int sockfd, clientfd;
    char buffer[BUFFER_SIZE];
    struct sockaddr_in server_address, client_address;
    socklen_t address_size = sizeof(server_address);
    struct hostent *host;
    char *hostname = "localhost"; // Replace with your desired hostname
    int port = 80; // Replace with your desired port number

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0) {
        perror("Error creating socket");
        exit(1);
    }

    // Get host
    host = gethostbyname(hostname);
    if (host == NULL) {
        perror("Error getting host");
        exit(1);
    }

    // Setup server address
    memset(&server_address, 0, address_size);
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(port);
    server_address.sin_addr = *((struct in_addr *) host->h_addr);

    // Connect to server
    int connection_status = connect(sockfd, (struct sockaddr *) &server_address, address_size);

    if (connection_status < 0) {
        perror("Error connecting to server");
        exit(1);
    }

    // Listen for incoming connections
    listen(sockfd, 5);
    printf("HTTP Proxy listening on port %d...\n", PORT);

    while (1) {
        // Accept connection from client
        clientfd = accept(sockfd, (struct sockaddr *) &client_address, &address_size);
        if (clientfd < 0) {
            perror("Error accepting connection from client");
            exit(1);
        }

        // Clear buffer
        memset(buffer, 0, BUFFER_SIZE);

        // Read request from client
        int read_status = read(clientfd, buffer, BUFFER_SIZE);
        if (read_status < 0) {
            perror("Error reading from client");
            exit(1);
        }

        printf("Request: \n%s\n", buffer);

        // Forward request to server
        int send_status = send(sockfd, buffer, strlen(buffer), 0);
        if (send_status < 0) {
            perror("Error sending request to server");
            exit(1);
        }

        // Clear buffer
        memset(buffer, 0, BUFFER_SIZE);

        // Read response from server
        read_status = read(sockfd, buffer, BUFFER_SIZE);
        if (read_status < 0) {
            perror("Error reading response from server");
            exit(1);
        }

        printf("Response: \n%s\n", buffer);

        // Send response to client
        send_status = send(clientfd, buffer, strlen(buffer), 0);
        if (send_status < 0) {
            perror("Error sending response to client");
            exit(1);
        }

        // Close connection with client
        close(clientfd);
    }

    // Close connection with server
    close(sockfd);

    return 0;
}