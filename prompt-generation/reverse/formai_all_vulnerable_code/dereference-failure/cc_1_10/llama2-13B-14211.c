//LLAMA2-13B DATASET v1.0 Category: Port Scanner ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX_CONNECTIONS 1024
#define PORT_RANGE 1024

struct connection {
    int sock;
    struct sockaddr_in server;
    char *client_name;
    int state;
};

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <host>\n", argv[0]);
        return 1;
    }

    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("socket failed");
        exit(1);
    }

    struct sockaddr_in server;
    server.sin_family = AF_INET;
    server.sin_port = htons(atoi(argv[1]));
    inet_pton(AF_INET, "127.0.0.1", &server.sin_addr);

    char *client_name = "unknown";
    int state = 0;

    while (1) {
        struct connection *conn = calloc(1, sizeof(struct connection));
        conn->sock = sock;
        conn->server = server;
        conn->client_name = client_name;
        conn->state = state;

        if (connect(sock, (struct sockaddr *)&server, sizeof(server)) < 0) {
            perror("connect failed");
            exit(1);
        }

        // Check if the connection is still alive
        if (send(sock, "Hello, client!", 13, 0) < 0) {
            perror("send failed");
            exit(1);
        }

        // Receive data from the client
        char buffer[1024];
        int bytes_received = recv(sock, buffer, 1024, 0);

        if (bytes_received < 0) {
            perror("recv failed");
            exit(1);
        }

        // Print the received data
        printf("Received: %s\n", buffer);

        // Check if the client has closed the connection
        if (bytes_received == 0) {
            printf("Client has closed the connection\n");
            break;
        }

        // Update the client name
        client_name = buffer;

        // Check if the connection is still alive
        if (send(sock, "Hello, client!", 13, 0) < 0) {
            perror("send failed");
            exit(1);
        }

        // Sleep for a little bit to avoid overwhelming the client
        usleep(100000);
    }

    close(sock);

    return 0;
}