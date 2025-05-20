//Falcon-180B DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netinet/tcp.h>

#define BUFFER_SIZE 1024
#define PORT 8080
#define BACKLOG 10

int main(int argc, char *argv[]) {
    int server_socket;
    struct sockaddr_in server_addr;
    int client_socket;
    struct sockaddr_in client_addr;
    socklen_t client_addr_size;
    char buffer[BUFFER_SIZE];
    int bytes_received;
    char *token;
    char *qos_string;
    int qos_value;

    // Create socket
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        printf("Error creating socket\n");
        exit(1);
    }

    // Set up server address
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = INADDR_ANY;

    // Bind socket to address
    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error binding socket\n");
        exit(1);
    }

    // Listen for connections
    if (listen(server_socket, BACKLOG) == -1) {
        printf("Error listening on socket\n");
        exit(1);
    }

    printf("Server listening on port %d\n", PORT);

    // Accept client connections
    while (1) {
        client_socket = accept(server_socket, (struct sockaddr *)&client_addr, &client_addr_size);
        if (client_socket == -1) {
            printf("Error accepting connection\n");
            exit(1);
        }

        // Receive QoS string from client
        bytes_received = recv(client_socket, buffer, BUFFER_SIZE, 0);
        if (bytes_received <= 0) {
            printf("Error receiving data from client\n");
            exit(1);
        }
        buffer[bytes_received] = '\0';
        token = strtok(buffer, " ");
        qos_string = strtok(NULL, " ");
        qos_value = atoi(qos_string);

        // Set QoS for client socket
        setsockopt(client_socket, IPPROTO_TCP, TCP_MAXSEG, &qos_value, sizeof(qos_value));

        // Send response to client
        sprintf(buffer, "QoS set to %d\n", qos_value);
        send(client_socket, buffer, strlen(buffer), 0);

        // Close client socket
        close(client_socket);
    }

    return 0;
}