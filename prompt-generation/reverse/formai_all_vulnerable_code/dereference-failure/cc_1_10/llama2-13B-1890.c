//LLAMA2-13B DATASET v1.0 Category: Port Scanner ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT_RANGE 1024
#define MAX_CONNECTIONS 100

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <IP_ADDRESS>\n", argv[0]);
        return 1;
    }

    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("socket() failed");
        return 2;
    }

    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(atoi(argv[1]));
    inet_pton(AF_INET, argv[1], &server_addr.sin_addr);

    int conn_count = 0;
    struct timeval timeout;
    timeout.tv_sec = 2;
    timeout.tv_usec = 0;

    while (conn_count < MAX_CONNECTIONS) {
        int client_sock = accept(sock, NULL, NULL);
        if (client_sock < 0) {
            perror("accept() failed");
            break;
        }

        char buffer[256];
        memset(buffer, 0, sizeof(buffer));

        // Read data from client
        recv(client_sock, buffer, sizeof(buffer), 0);

        // Print received data
        printf("Received data from client: %s\n", buffer);

        // Send a response to the client
        char *response = "Hello, client!";
        send(client_sock, response, strlen(response), 0);

        // Close the connection
        close(client_sock);

        conn_count++;

        // Wait for more connections
        select(sock + 1, NULL, NULL, NULL, &timeout);
    }

    close(sock);

    return 0;
}