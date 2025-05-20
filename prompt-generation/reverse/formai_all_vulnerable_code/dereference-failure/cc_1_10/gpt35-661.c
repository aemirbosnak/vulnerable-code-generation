//FormAI DATASET v1.0 Category: Chat server ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <errno.h>

#define PORT 8080
#define MAX_MSG_SIZE 1024

void error_handler(char *message) {
    fprintf(stderr, "Error: %s. %s\n", message, strerror(errno));
    exit(EXIT_FAILURE);
}

int main(int argc, char *argv[]) {
    int listener_fd, new_socket;
    struct sockaddr_in address;
    int opt = 1;
    int address_len = sizeof(address);
    char buffer[MAX_MSG_SIZE] = {0};
    char reply_msg[] = "Hello Client, I am your Chat Server.";
    int read_size;

    if ((listener_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        error_handler("Failed to create socket");
    }

    // Attach the socket to the process and allow it to bind to a port that is still in use (in case of timeout)
    if (setsockopt(listener_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        error_handler("setsockopt");
    }

    // Set socket address parameters
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    // Attach the socket to the listener
    if (bind(listener_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        error_handler("Binding failed");
    }

    // Start listening to incoming requests from clients
    if (listen(listener_fd, 3) < 0) {
        error_handler("listen");
    }

    // Wait for incoming connection requests
    if ((new_socket = accept(listener_fd, (struct sockaddr *)&address, (socklen_t*)&address_len)) < 0) {
        error_handler("accept");
    } else {
        printf("Client connected\n");
    }

    // Send a welcome message to the client
    if (send(new_socket, reply_msg, strlen(reply_msg), 0) < 0) {
        error_handler("Send failed");
    }

    // Receive incoming messages from the client
    while ((read_size = recv(new_socket, buffer, MAX_MSG_SIZE, 0)) > 0) {
        printf(" Client: %s\n", buffer);
        memset(buffer, 0, MAX_MSG_SIZE);
        fgets(buffer, MAX_MSG_SIZE, stdin);
        send(new_socket, buffer, strlen(buffer), 0);
    }

    if (read_size == 0) {
        printf("Client disconnected\n");
    } else if (read_size == -1) {
        error_handler("recv failed");
    }

    return 0;
}