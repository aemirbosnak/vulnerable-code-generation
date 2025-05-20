//Falcon2-11B DATASET v1.0 Category: Socket programming ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

int main(int argc, char *argv[]) {
    int server_fd, client_fd;
    struct sockaddr_in server_addr, client_addr;
    int addr_len = sizeof(server_addr);
    char message[1024];

    // Create a socket
    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd < 0) {
        perror("socket");
        exit(1);
    }

    // Prepare server address struct
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(atoi(argv[1]));
    server_addr.sin_addr.s_addr = INADDR_ANY;

    // Bind to a port
    if (bind(server_fd, (struct sockaddr *)&server_addr, addr_len) < 0) {
        perror("bind");
        exit(1);
    }

    // Start listening for connections
    if (listen(server_fd, 3) < 0) {
        perror("listen");
        exit(1);
    }

    // Accept incoming connection
    client_fd = accept(server_fd, (struct sockaddr *)&client_addr, (socklen_t*)&addr_len);
    if (client_fd < 0) {
        perror("accept");
        exit(1);
    }

    // Receive message from client
    recv(client_fd, message, sizeof(message), 0);

    // Send response back to client
    sprintf(message, "Hello, %s! My IP address is %s:%d.", message, inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));
    send(client_fd, message, strlen(message), 0);

    // Close connections
    close(server_fd);
    close(client_fd);

    return 0;
}