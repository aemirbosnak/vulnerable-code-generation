//FormAI DATASET v1.0 Category: Networking ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <sys/types.h>
#include <netdb.h>

#define PORT 8080
#define MAX_MESSAGE_SIZE 1024

int main(int argc, char const *argv[]) {
    int server_fd = 0, new_socket = 0, valread;
    struct sockaddr_in address;
    struct hostent *he;
    int addrlen = sizeof(address);
    char buffer[MAX_MESSAGE_SIZE] = {0};
    char *hello = "Hello from server";

    // Create socket and get hostname
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // Get host information
    if ((he = gethostbyname("localhost")) == NULL) {
        perror("gethostbyname");
        exit(EXIT_FAILURE);
    }

    // Bind socket to port
    address.sin_family = AF_INET;
    address.sin_port = htons(PORT);
    address.sin_addr = *((struct in_addr*) he->h_addr_list[0]);

    if (bind(server_fd, (struct sockaddr*) &address, sizeof(address)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    // Start listening for incoming connections
    if (listen(server_fd, 3) < 0) {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    // Accept incoming connection
    if ((new_socket = accept(server_fd, (struct sockaddr*) &address, (socklen_t*) &addrlen)) < 0) {
        perror("accept");
        exit(EXIT_FAILURE);
    }

    // Send message to client
    send(new_socket, hello, strlen(hello), 0);
    printf("Hello message sent to client\n");

    // Read message from client
    valread = read(new_socket, buffer, MAX_MESSAGE_SIZE);
    printf("Message from client: %s\n", buffer);

    return 0;
}