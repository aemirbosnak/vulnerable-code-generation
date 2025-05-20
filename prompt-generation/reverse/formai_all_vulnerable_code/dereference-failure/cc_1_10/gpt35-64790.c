//FormAI DATASET v1.0 Category: Firewall ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <pthread.h>

#define MAX_PACKET_SIZE 65535

void *handle_connection(void *arg) {
    int client_fd = *(int *)arg;
    char buffer[MAX_PACKET_SIZE];
    struct sockaddr_in client_address;
    socklen_t client_address_len = sizeof(client_address);
    memset(&client_address, 0, client_address_len);
    if (getpeername(client_fd, (struct sockaddr *)&client_address, &client_address_len) == -1) {
        printf("Error getting client address\n");
        close(client_fd);
        return NULL;
    }
    printf("Connection from %s:%d\n", inet_ntoa(client_address.sin_addr), ntohs(client_address.sin_port));
    while (1) {
        ssize_t received = recv(client_fd, buffer, MAX_PACKET_SIZE, 0);
        if (received == -1) {
            printf("Error receiving packet from %s:%d\n", inet_ntoa(client_address.sin_addr), ntohs(client_address.sin_port));
            break;
        }
        if (received == 0) {
            break;
        }
        // TODO: Add firewall logic to drop packets
        if (send(client_fd, buffer, received, 0) == -1) {
            printf("Error sending packet to %s:%d\n", inet_ntoa(client_address.sin_addr), ntohs(client_address.sin_port));
            break;
        }
    }
    printf("Connection closed for %s:%d\n", inet_ntoa(client_address.sin_addr), ntohs(client_address.sin_port));
    close(client_fd);
    return NULL;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <port>\n", argv[0]);
        return EXIT_FAILURE;
    }
    int port = atoi(argv[1]);
    int listen_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (listen_fd == -1) {
        printf("Error creating socket\n");
        return EXIT_FAILURE;
    }
    int enable_reuse = 1;
    if (setsockopt(listen_fd, SOL_SOCKET, SO_REUSEADDR, &enable_reuse, sizeof(enable_reuse)) == -1) {
        printf("Error setting socket option\n");
        return EXIT_FAILURE;
    }
    struct sockaddr_in server_address;
    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = htonl(INADDR_ANY);
    server_address.sin_port = htons(port);
    if (bind(listen_fd, (struct sockaddr *)&server_address, sizeof(server_address)) == -1) {
        printf("Error binding to port %d\n", port);
        return EXIT_FAILURE;
    }
    if (listen(listen_fd, SOMAXCONN) == -1) {
        printf("Error listening on port %d\n", port);
        return(EXIT_FAILURE);
    }
    while (1) {
        struct sockaddr_in client_address;
        socklen_t client_address_len = sizeof(client_address);
        memset(&client_address, 0, client_address_len);
        int client_fd = accept(listen_fd, (struct sockaddr *)&client_address, &client_address_len);
        if (client_fd == -1) {
            printf("Error accepting connection\n");
            continue;
        }
        pthread_t client_thread;
        if (pthread_create(&client_thread, NULL, &handle_connection, &client_fd) == -1) {
            printf("Error creating thread\n");
            close(client_fd);
            continue;
        }
        if (pthread_detach(client_thread) == -1) {
            printf("Error detaching thread\n");
            close(client_fd);
            continue;
        }
    }
    close(listen_fd);
    return EXIT_SUCCESS;
}