//FormAI DATASET v1.0 Category: Firewall ; Style: calm
#include<stdio.h>
#include<stdlib.h>
#include<netdb.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<string.h>

#define BACKLOG 10
#define MAX_DATA_SIZE 1024

int main(int argc, char *argv[]) {

    struct sockaddr_in server_address;
    struct sockaddr_in client_address;

    int server_socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket_fd == -1) {
        perror("Socket creation failed.\n");
        return EXIT_FAILURE;
    }

    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = htonl(INADDR_ANY);
    server_address.sin_port = htons(atoi(argv[1]));

    if ((bind(server_socket_fd, (struct sockaddr *) &server_address, sizeof(server_address))) == -1) {
        perror("Failed to bind the socket to the server address.\n");
        return EXIT_FAILURE;
    }

    if ((listen(server_socket_fd, BACKLOG)) == -1) {
        perror("Listening for incoming connections failed.\n");
        return EXIT_FAILURE;
    }

    printf("Firewall is active, waiting for incoming connections...\n");

    while (1) {
        int client_socket_fd, incoming_data_size;
        char incoming_data_buffer[MAX_DATA_SIZE];

        memset(&client_address, 0, sizeof(client_address));
        socklen_t client_address_len = sizeof(client_address);

        client_socket_fd = accept(server_socket_fd, (struct sockaddr *) &client_address, &client_address_len);
        if (client_socket_fd < 0) {
            perror("Accepting incoming connection failed.\n");
            return EXIT_FAILURE;
        }

        const char *client_ip_address = inet_ntoa(client_address.sin_addr);
        printf("Connection established from %s.\n", client_ip_address);

        incoming_data_size = recv(client_socket_fd, incoming_data_buffer, MAX_DATA_SIZE, 0);
        incoming_data_buffer[incoming_data_size] = '\0';
        printf("Received message from %s: %s\n", client_ip_address, incoming_data_buffer);

        close(client_socket_fd);
        printf("Connection closed from %s.\n", client_ip_address);
    }

    return EXIT_SUCCESS;
}