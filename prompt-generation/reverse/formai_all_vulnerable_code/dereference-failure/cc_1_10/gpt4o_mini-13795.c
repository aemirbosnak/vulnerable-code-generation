//GPT-4o-mini DATASET v1.0 Category: Socket programming ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h> // For close()
#include <arpa/inet.h> // For inet_addr() and sockaddr_in
#include <errno.h> // For error handling

#define PORT 8080
#define BUFFER_SIZE 1024

// SHOCKING! Here is where the server will listen for client connections!
void start_server() {
    int server_fd, new_socket;
    struct sockaddr_in address;
    int addrlen = sizeof(address);
    char buffer[BUFFER_SIZE] = {0};

    // Creating socket file descriptor, but what if it fails??!!
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // WARNING! Setting options to the socket! 
    int opt = 1;
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt))) {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }

    // SHOCKING! Preparing address structure to bind!
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    // Bind the socket to the IP/Port, but what if it fails??!!
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    // Now let's listen for incoming connections, can it get any more intense?!!!
    if (listen(server_fd, 3) < 0) {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    printf("🚨 Server listening on port %d...\n", PORT);

    // Accept incoming connections in a loop! It's like a shockwave of connections!
    while (1) {
        // SHOCKING! Waiting for a connection...
        if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen)) < 0) {
            perror("accept");
            exit(EXIT_FAILURE);
        }

        printf("✅ Connection accepted from %s:%d\n", 
               inet_ntoa(address.sin_addr), ntohs(address.sin_port));

        // Read the message from client
        int valread = read(new_socket, buffer, BUFFER_SIZE);
        printf("📩 Message from client: %s\n", buffer);

        // Shockingly, send back the same message!
        send(new_socket, buffer, valread, 0);
        printf("🔄 Message echoed back to client.\n");

        // Close the socket for the individual client
        close(new_socket);
    }
}

// SHOCKED! Client that connects to the server!
void start_client(const char *server_ip) {
    struct sockaddr_in serv_addr;
    int sock = 0;
    char *message = "Hello Server! Are you shocked yet??";
    char buffer[BUFFER_SIZE] = {0};

    // Create socket, can it even be created???
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        printf("😱 Socket creation error!\n");
        return;
    }

    // Setting up the server address
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);

    // Convert IPv4 and IPv6 addresses from text to binary form
    if (inet_pton(AF_INET, server_ip, &serv_addr.sin_addr) <= 0) {
        printf("😱 Invalid address / Address not supported: %s\n", server_ip);
        return;
    }

    // SHOCKING! Attempting to connect to server!
    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("🚨 Connection Failed: Are you sure the server is running?\n");
        return;
    }

    // Sending message to server!
    send(sock, message, strlen(message), 0);
    printf("📤 Message sent: %s\n", message);

    // Read the echoed message back from server
    int valread = read(sock, buffer, BUFFER_SIZE);
    printf("📥 Echoed message from server: %s\n", buffer);

    // Close the socket
    close(sock);
}

int main(int argc, char const *argv[]) {
    // SHOCKING! Ensuring correct usage!
    if (argc != 2) {
        printf("Usage: %s <server|client>\n", argv[0]);
        return 1;
    }

    // Deciding which function to start based on the argument
    if (strcmp(argv[1], "server") == 0) {
        start_server();
    } else if (strcmp(argv[1], "client") == 0) {
        start_client("127.0.0.1"); // Connecting to localhost, how mysterious!
    } else {
        printf("😱 Invalid argument! Use 'server' or 'client'.\n");
        return 1;
    }

    return 0;
}