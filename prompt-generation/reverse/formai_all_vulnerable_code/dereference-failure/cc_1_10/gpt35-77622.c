//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define MAX_PENDING 5
#define BUF_SIZE 1024

int main(int argc, char *argv[]) {
    int server_socket;
    int client_socket;
    struct sockaddr_in server_addr;
    struct sockaddr_in client_addr;
    unsigned short server_port;
    unsigned int client_len;
    char buffer[BUF_SIZE];
    int bytes_received, total_bytes_received;

    if (argc != 2) {
        printf("Usage: %s <Server Port>\n", argv[0]);
        exit(1);
    }

    server_port = atoi(argv[1]);

    if ((server_socket = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP)) < 0) {
        printf("Could not create socket.\n");
        exit(1);
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    server_addr.sin_port = htons(server_port);

    if (bind(server_socket, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0) {
        printf("Could not bind to socket.\n");
        exit(1);
    }

    if (listen(server_socket, MAX_PENDING) < 0) {
        printf("Error while listening.\n");
        exit(1);
    }

    while (1) {
        client_len = sizeof(client_addr);
        if ((client_socket = accept(server_socket, (struct sockaddr *) &client_addr, &client_len)) < 0) {
            printf("Error while accepting a client connection.\n");
            exit(1);
        }

        printf("Handling client %s\n", inet_ntoa(client_addr.sin_addr));

        total_bytes_received = 0;
        while (total_bytes_received < BUF_SIZE) {
            if ((bytes_received = recv(client_socket, buffer + total_bytes_received, BUF_SIZE - total_bytes_received, 0)) <= 0) {
                printf("Error while receiving data.\n");
                close(client_socket);
                break;
            }
            total_bytes_received += bytes_received;
        }

        buffer[total_bytes_received] = '\0';

        printf("Message received from client: %s\n", buffer);

        close(client_socket);
    }

    close(server_socket);
    
    return 0;
}