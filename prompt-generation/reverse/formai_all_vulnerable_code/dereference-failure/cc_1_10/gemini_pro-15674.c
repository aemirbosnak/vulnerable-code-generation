//GEMINI-pro DATASET v1.0 Category: Simple Web Server ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

int main(int argc, char** argv) {
    // Check if the port number was provided.
    if (argc != 2) {
        printf("Usage: %s <port>\n", argv[0]);
        return 1;
    }

    // Get the port number.
    int port = atoi(argv[1]);

    // Create a socket.
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        perror("socket");
        return 1;
    }

    // Bind the socket to the port.
    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = INADDR_ANY;
    addr.sin_port = htons(port);
    if (bind(sock, (struct sockaddr*)&addr, sizeof(addr)) == -1) {
        perror("bind");
        return 1;
    }

    // Listen for incoming connections.
    if (listen(sock, 5) == -1) {
        perror("listen");
        return 1;
    }

    // Accept incoming connections.
    while (1) {
        struct sockaddr_in client_addr;
        socklen_t client_addr_len = sizeof(client_addr);
        int client_sock = accept(sock, (struct sockaddr*)&client_addr, &client_addr_len);
        if (client_sock == -1) {
            perror("accept");
            continue;
        }

        // Handle the client request.
        char request[1024];
        int request_len = recv(client_sock, request, sizeof(request), 0);
        if (request_len == -1) {
            perror("recv");
            close(client_sock);
            continue;
        }

        // Send the response.
        char response[] = "HTTP/1.1 200 OK\nContent-Type: text/plain\n\nHello, world!\n";
        int response_len = strlen(response);
        if (send(client_sock, response, response_len, 0) == -1) {
            perror("send");
            close(client_sock);
            continue;
        }

        // Close the client socket.
        close(client_sock);
    }

    // Close the server socket.
    close(sock);

    return 0;
}