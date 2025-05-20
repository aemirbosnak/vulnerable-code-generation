//FormAI DATASET v1.0 Category: Chat server ; Style: surprised
#include <stdio.h> // for input/output operations
#include <stdlib.h> // for utility functions, such as memory allocation
#include <string.h> // for string operations
#include <sys/socket.h> // for socket related functions
#include <netinet/in.h> // for internet protocol related operations
#include <unistd.h> // for handling file descriptors

int main(int argc, char *argv[]) {

    // Check if the user inputted the required number of arguments
    if (argc != 2) {
        fprintf(stderr, "Error: the program expects only one argument, which is the port number.\nUsage: ./chat_server <port_number>\n");
        exit(EXIT_FAILURE);
    }

    // Convert the port number to an integer format
    int port_number = atoi(argv[1]);

    // Create a socket and perform basic error handling
    int socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_fd == -1) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    // Set up internet protocol-related configurations
    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(port_number);

    // Bind the socket and perform basic error handling
    if (bind(socket_fd, (struct sockaddr *)&server_address, sizeof(server_address)) == -1) {
        perror("bind");
        exit(EXIT_FAILURE);
    }

    // Listen to incoming connections and perform basic error handling
    if (listen(socket_fd, 5) == -1) {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    printf("Chat server started! Listening on port %d...\n", port_number);

    // Accept incoming connections and perform basic error handling
    int client_socket_fd = accept(socket_fd, NULL, NULL);
    if (client_socket_fd == -1) {
        perror("accept");
        exit(EXIT_FAILURE);
    }

    printf("Connected to client!\n");

    while (1) {

        char buffer[1024] = {0};

        // Read the message sent by the client
        int read_result = read(client_socket_fd, buffer, 1024);
        if (read_result == -1) {
            perror("read");
        }
        else if (read_result == 0) {
            // If the read result is 0, that means the connection is closed
            break;
        }
        else {
            // Print the received message and send it back to the client
            printf("Message received from client: %s", buffer);
            write(client_socket_fd, buffer, strlen(buffer));
        }

    }

    // Close the connection and the socket
    close(client_socket_fd);
    close(socket_fd);

    return 0;
}