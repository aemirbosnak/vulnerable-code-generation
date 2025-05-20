//Falcon2-11B DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char **argv) {
    int server_fd, client_fd, port, n;
    struct sockaddr_in server_addr, client_addr;
    char buffer[1024];

    // Create a TCP socket
    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd < 0) {
        perror("Error creating socket");
        exit(1);
    }

    // Initialize the server address structure
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(atoi(argv[1]));

    // Bind the socket to the address
    if (bind(server_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Error binding socket");
        exit(1);
    }

    // Listen for incoming connections
    listen(server_fd, 3);
    printf("Listening for connections...\n");

    // Accept incoming connections and create new file descriptors
    while ((client_fd = accept(server_fd, (struct sockaddr *)&client_addr, &n)) >= 0) {
        // Read data from the client
        read(client_fd, buffer, sizeof(buffer));

        // Send a response back to the client
        write(client_fd, "Hello, World!", 13);

        // Close the client connection
        close(client_fd);
    }

    // Close the server socket
    close(server_fd);

    return 0;
}