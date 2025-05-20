//Gemma-7B DATASET v1.0 Category: Simple HTTP Proxy ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>
#include <netdb.h>

#define MAX_BUFFER_SIZE 4096

// Define a hash table to store client connections
typedef struct ClientConnection {
    char *host;
    int sockfd;
    struct ClientConnection *next;
} ClientConnection;

ClientConnection *head = NULL;

// Function to add a client connection to the hash table
void addClientConnection(char *host, int sockfd) {
    ClientConnection *newConn = malloc(sizeof(ClientConnection));
    newConn->host = strdup(host);
    newConn->sockfd = sockfd;
    newConn->next = NULL;

    if (head == NULL) {
        head = newConn;
    } else {
        ClientConnection *currConn = head;
        while (currConn->next) {
            currConn = currConn->next;
        }
        currConn->next = newConn;
    }
}

// Function to handle client requests
void handleClientRequest(ClientConnection *conn) {
    char buffer[MAX_BUFFER_SIZE];
    int readBytes = read(conn->sockfd, buffer, MAX_BUFFER_SIZE);
    if (readBytes > 0) {
        // Forward the request to the backend server
        int backendsockfd = socket(AF_INET, SOCK_STREAM, htons(80));
        struct sockaddr_in backendAddr;
        memset(&backendAddr, 0, sizeof(backendAddr));
        backendAddr.sin_family = AF_INET;
        backendAddr.sin_port = htons(8080);
        backendAddr.sin_addr.s_addr = inet_addr("127.0.0.1");

        connect(backendsockfd, (struct sockaddr *)&backendAddr, sizeof(backendAddr));

        write(backendsockfd, buffer, readBytes);

        readBytes = read(backendsockfd, buffer, MAX_BUFFER_SIZE);

        write(conn->sockfd, buffer, readBytes);

        close(backendsockfd);
    }
}

int main() {
    int sockfd = socket(AF_INET, SOCK_STREAM, htons(80));
    bind(sockfd, (struct sockaddr *)NULL, 0);

    // Listen for client connections
    while (1) {
        struct sockaddr_in clientAddr;
        int clientSockfd = accept(sockfd, (struct sockaddr *)&clientAddr, NULL);
        addClientConnection(inet_ntoa(clientAddr.sin_addr), clientSockfd);
        handleClientRequest(head);
    }

    return 0;
}