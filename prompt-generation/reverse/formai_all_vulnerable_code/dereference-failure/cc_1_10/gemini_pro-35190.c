//GEMINI-pro DATASET v1.0 Category: Intrusion detection system ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/time.h>

// This is our trusty Intrusion Detection System (IDS) program! It's here to protect your precious network from those pesky intruders.

// Let's define some constants for our IDS.
#define IDS_PORT 5555  // The port our IDS will listen on.
#define IDS_BUFFER_SIZE 1024  // The size of the buffer we'll use to receive data from the network.
#define IDS_MAX_CONNECTIONS 10  // The maximum number of simultaneous connections our IDS can handle.

// We'll need some data structures to keep track of our connections and data.
typedef struct {
    int sockfd;  // The socket file descriptor for the connection.
    struct sockaddr_in addr;  // The address of the client.
    char buffer[IDS_BUFFER_SIZE];  // The buffer to store data from the client.
    int buffer_len;  // The length of the data in the buffer.
} connection_t;

// We'll also need a function to handle incoming connections.
void handle_connection(connection_t *conn) {
    // First, let's receive some data from the client.
    conn->buffer_len = recv(conn->sockfd, conn->buffer, IDS_BUFFER_SIZE, 0);
    if (conn->buffer_len == -1) {
        perror("recv");
        close(conn->sockfd);
        return;
    }

    // Now, let's check if the data looks suspicious.
    if (strstr(conn->buffer, "evil") != NULL) {
        printf("INTRUSION DETECTED: Connection from %s:%d is trying to do something evil!\n", inet_ntoa(conn->addr.sin_addr), ntohs(conn->addr.sin_port));
        close(conn->sockfd);
        return;
    }

    // If the data looks clean, let's send a response back to the client.
    const char *response = "OK";
    if (send(conn->sockfd, response, strlen(response), 0) == -1) {
        perror("send");
        close(conn->sockfd);
        return;
    }

    // Finally, let's close the connection.
    close(conn->sockfd);
}

// And now, let's put it all together in our main function.
int main() {
    // First, let's create a socket for our IDS.
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        return EXIT_FAILURE;
    }

    // Now, let's bind our IDS to the specified port.
    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = htonl(INADDR_ANY);
    addr.sin_port = htons(IDS_PORT);
    if (bind(sockfd, (struct sockaddr *)&addr, sizeof(addr)) == -1) {
        perror("bind");
        close(sockfd);
        return EXIT_FAILURE;
    }

    // Great! Now, let's listen for incoming connections.
    if (listen(sockfd, IDS_MAX_CONNECTIONS) == -1) {
        perror("listen");
        close(sockfd);
        return EXIT_FAILURE;
    }

    // Now, let's enter the main loop of our IDS.
    while (1) {
        // Let's accept incoming connections.
        struct sockaddr_in client_addr;
        socklen_t client_addr_len = sizeof(client_addr);
        int client_sockfd = accept(sockfd, (struct sockaddr *)&client_addr, &client_addr_len);
        if (client_sockfd == -1) {
            perror("accept");
            continue;
        }

        // We've got a new connection! Let's create a new thread to handle it.
        connection_t *conn = malloc(sizeof(connection_t));
        conn->sockfd = client_sockfd;
        conn->addr = client_addr;
        conn->buffer_len = 0;
        pthread_t thread;
        if (pthread_create(&thread, NULL, (void *(*)(void *))handle_connection, (void *)conn) != 0) {
            perror("pthread_create");
            close(client_sockfd);
            continue;
        }
    }

    // We'll never reach this point, but it's good practice to clean up our resources.
    close(sockfd);
    return EXIT_SUCCESS;
}