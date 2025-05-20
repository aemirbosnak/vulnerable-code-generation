//Falcon2-11B DATASET v1.0 Category: Chat server ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

int main(int argc, char *argv[]) {
    int server_fd, new_fd, n;
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_addr_len = sizeof(client_addr);

    // Create a socket
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("socket failed");
        return 1;
    }

    // Set up the server address
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(atoi(argv[1]));
    server_addr.sin_addr.s_addr = INADDR_ANY;

    // Bind the socket to the address
    if (bind(server_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("bind failed");
        return 1;
    }

    // Listen for incoming connections
    if (listen(server_fd, 5) == -1) {
        perror("listen failed");
        return 1;
    }

    while (1) {
        // Accept a connection
        if ((new_fd = accept(server_fd, (struct sockaddr *)&client_addr, &client_addr_len)) == -1) {
            perror("accept failed");
            return 1;
        }

        // Allocate memory for the message buffer
        char *msg = (char *)malloc(sizeof(char) * 1024);
        if (msg == NULL) {
            perror("malloc failed");
            return 1;
        }

        // Receive the message
        n = read(new_fd, msg, sizeof(msg));
        if (n < 0) {
            perror("read failed");
            free(msg);
            return 1;
        }

        // Send the message back to the client
        write(new_fd, msg, n);

        // Clean up the memory
        free(msg);
        close(new_fd);
    }

    close(server_fd);
    return 0;
}