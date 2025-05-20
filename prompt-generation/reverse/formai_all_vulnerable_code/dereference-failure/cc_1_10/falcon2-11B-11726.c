//Falcon2-11B DATASET v1.0 Category: Chat server ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

// Function to print error message
void print_err(const char *msg) {
    perror(msg);
    exit(1);
}

int main(int argc, char *argv[]) {
    // Create a TCP socket
    int listen_fd, conn_fd;
    struct sockaddr_in server_addr, client_addr;
    int addr_len = sizeof(client_addr);

    // Initialize the server address
    memset((char *) &server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(atoi(argv[1]));

    // Bind the socket
    if (bind(listen_fd = socket(AF_INET, SOCK_STREAM, 0), (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0) {
        print_err("bind failed");
    }

    // Start listening
    if (listen(listen_fd, 5) < 0) {
        print_err("listen failed");
    }

    // Accept connections
    while (1) {
        // Accept incoming connections
        if ((conn_fd = accept(listen_fd, (struct sockaddr *) &client_addr, (socklen_t *) &addr_len)) < 0) {
            print_err("accept failed");
        }

        // Receive messages from client
        char buffer[256];
        int n;
        while ((n = recv(conn_fd, buffer, 255, 0)) > 0) {
            printf("%s\n", buffer);
            // Send a message back to client
            send(conn_fd, "ACK", 4, 0);
        }

        // Close connection
        close(conn_fd);
    }

    close(listen_fd);
    return 0;
}