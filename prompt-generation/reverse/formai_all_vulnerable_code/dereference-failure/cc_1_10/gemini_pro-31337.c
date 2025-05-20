//GEMINI-pro DATASET v1.0 Category: Intrusion detection system ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <time.h>

#define MAX_CONNECTIONS 10
#define MAX_BUFFER_SIZE 1024

// Structure to store information about a connection
typedef struct {
    int sockfd;
    struct sockaddr_in addr;
    time_t last_activity;
} connection_t;

// Array to store connections
connection_t connections[MAX_CONNECTIONS];

// Function to handle a new connection
void handle_connection(int sockfd) {
    // Get the client's IP address and port
    struct sockaddr_in addr;
    socklen_t addr_len = sizeof(addr);
    getpeername(sockfd, (struct sockaddr *)&addr, &addr_len);

    // Create a new connection object
    connection_t connection;
    connection.sockfd = sockfd;
    connection.addr = addr;
    connection.last_activity = time(NULL);

    // Add the connection to the array
    for (int i = 0; i < MAX_CONNECTIONS; i++) {
        if (connections[i].sockfd == -1) {
            connections[i] = connection;
            break;
        }
    }

    // Send a welcome message to the client
    char *welcome_message = "Welcome to the intrusion detection system!\n";
    send(sockfd, welcome_message, strlen(welcome_message), 0);
}

// Function to monitor connections for activity
void monitor_connections() {
    // Loop through all connections
    for (int i = 0; i < MAX_CONNECTIONS; i++) {
        // Check if the connection is still active
        if (connections[i].sockfd != -1) {
            time_t now = time(NULL);
            if (now - connections[i].last_activity > 60) {
                // The connection has been inactive for more than 60 seconds, so close it
                close(connections[i].sockfd);
                connections[i].sockfd = -1;
            }
        }
    }
}

// Function to accept new connections
void accept_connections(int listenfd) {
    // Loop forever, accepting new connections
    while (1) {
        // Accept a new connection
        int sockfd = accept(listenfd, (struct sockaddr *)NULL, NULL);
        if (sockfd == -1) {
            perror("accept");
            continue;
        }

        // Handle the new connection
        handle_connection(sockfd);
    }
}

// Main function
int main(int argc, char *argv[]) {
    // Create a listening socket
    int listenfd = socket(AF_INET, SOCK_STREAM, 0);
    if (listenfd == -1) {
        perror("socket");
        return 1;
    }

    // Bind the listening socket to the specified port
    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = INADDR_ANY;
    addr.sin_port = htons(atoi(argv[1]));
    if (bind(listenfd, (struct sockaddr *)&addr, sizeof(addr)) == -1) {
        perror("bind");
        return 1;
    }

    // Listen for new connections
    if (listen(listenfd, MAX_CONNECTIONS) == -1) {
        perror("listen");
        return 1;
    }

    // Accept new connections and monitor existing connections
    accept_connections(listenfd);
    monitor_connections();

    // Close the listening socket
    close(listenfd);

    return 0;
}