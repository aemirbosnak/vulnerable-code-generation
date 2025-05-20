//LLAMA2-13B DATASET v1.0 Category: Port Scanner ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX_CLIENT_LENGTH 1024
#define MAX_SERVER_LENGTH 1024
#define PORT_RANGE 1024

struct client_info {
    int sock;
    char IP[INET_ADDRSTRLEN];
    char name[MAX_CLIENT_LENGTH];
};

int main(int argc, char *argv[]) {
    int sock = 0;
    struct client_info client;

    if (argc < 2) {
        printf("Usage: %s <port_range>\n", argv[0]);
        return 1;
    }

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("socket() failed");
        return 2;
    }

    // Set up the address structure
    struct sockaddr_in server_addr = {
        .sin_family = AF_INET,
        .sin_port = htons(atoi(argv[1])),
        .sin_addr.s_addr = INADDR_ANY
    };

    // Bind the socket to the address and port
    if (bind(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("bind() failed");
        close(sock);
        return 3;
    }

    // Listen for incoming connections
    if (listen(sock, PORT_RANGE) < 0) {
        perror("listen() failed");
        close(sock);
        return 4;
    }

    printf("Listening on port %d...\n", atoi(argv[1]));

    while (1) {
        // Accept an incoming connection
        sock = accept(sock, NULL, NULL);
        if (sock < 0) {
            perror("accept() failed");
            continue;
        }

        // Get the client's IP address and name
        struct sockaddr_in client_addr;
        socklen_t client_len = sizeof(client_addr);
        getpeername(sock, (struct sockaddr *)&client_addr, &client_len);
        char *client_IP = inet_ntoa(client_addr.sin_addr);
        char *client_name = getnameinfo((struct sockaddr *)&client_addr, client_len, NULL, 0, NULL, 0, NULL, 0);

        // Print the client's information
        printf("Client connected from IP %s (%s)\n", client_IP, client_name);

        // Send a message back to the client
        char message[] = "Hello, client!";
        send(sock, message, strlen(message), 0);

        // Close the socket
        close(sock);
    }

    return 0;
}