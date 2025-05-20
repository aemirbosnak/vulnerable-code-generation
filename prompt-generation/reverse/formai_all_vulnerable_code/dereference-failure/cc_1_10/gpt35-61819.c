//FormAI DATASET v1.0 Category: Socket programming ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>

void error(const char *message) {
    perror(message); // Print error message
    exit(1);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <port>\n", argv[0]);
        exit(1);
    }

    int sockfd = socket(AF_INET, SOCK_STREAM, 0); // Create socket
    if (sockfd < 0) {
        error("Error opening socket...");
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    int port_num = atoi(argv[1]);

    server_addr.sin_family = AF_INET; // IPv4
    server_addr.sin_addr.s_addr = INADDR_ANY; // Any incoming address allowed
    server_addr.sin_port = htons(port_num); // Port number in network byte order

    if (bind(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        error("Error binding socket...");
    }

    listen(sockfd, 5); // Listen for incoming connections

    struct sockaddr_in client_addr;
    socklen_t client_len = sizeof(client_addr);
    int clientfd = accept(sockfd, (struct sockaddr *)&client_addr, &client_len); // Accept connection
    if (clientfd < 0) {
        error("Error accepting connection...");
    }

    char buffer[256];
    while (1) {
        memset(buffer, 0, sizeof(buffer));
        int n = read(clientfd, buffer, sizeof(buffer)); // Read message from client
        if (n < 0) {
            error("Error reading from socket...");
        }

        printf("Client: %s\n", buffer);

        char reply[256];
        printf("Server: ");
        memset(reply, 0, sizeof(reply));
        fgets(reply, sizeof(reply), stdin); // Get reply from user input
        n = write(clientfd, reply, strlen(reply)); // Send reply to client
        if (n < 0) {
            error("Error writing to socket...");
        }

        if (strncmp(reply, "bye", 3) == 0) { // Close connection if user types "bye"
            break;
        }
    }

    close(clientfd); // Close client socket
    close(sockfd); // Close server socket
    return 0;
}