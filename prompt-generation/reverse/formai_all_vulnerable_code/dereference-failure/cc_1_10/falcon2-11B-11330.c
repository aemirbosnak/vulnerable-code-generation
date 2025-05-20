//Falcon2-11B DATASET v1.0 Category: Intrusion detection system ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX_CONNECTIONS 5

typedef struct {
    int client_fd;
    char client_ip[INET_ADDRSTRLEN];
    char client_port[INET_ADDRSTRLEN];
    char client_name[INET_ADDRSTRLEN];
} ClientInfo;

typedef struct {
    int server_fd;
    char server_ip[INET_ADDRSTRLEN];
    char server_port[INET_ADDRSTRLEN];
} ServerInfo;

int main(int argc, char *argv[]) {
    // Create server socket
    int server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd < 0) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    // Bind server socket to a specific address and port
    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    server_addr.sin_port = htons(atoi(argv[1]));

    if (bind(server_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("bind");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(server_fd, MAX_CONNECTIONS) < 0) {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    printf("Server listening on port %s\n", argv[1]);

    // Accept incoming connections
    while (1) {
        int client_fd = accept(server_fd, NULL, NULL);
        if (client_fd < 0) {
            perror("accept");
            exit(EXIT_FAILURE);
        }

        // Get client information
        struct sockaddr_in client_addr;
        socklen_t client_len = sizeof(client_addr);
        if (getsockname(client_fd, (struct sockaddr *)&client_addr, &client_len) < 0) {
            perror("getsockname");
            exit(EXIT_FAILURE);
        }

        char client_ip[INET_ADDRSTRLEN];
        inet_ntop(AF_INET, &client_addr.sin_addr, client_ip, INET_ADDRSTRLEN);

        char client_port[INET_ADDRSTRLEN];
        sprintf(client_port, "%d", ntohs(client_addr.sin_port));

        char client_name[INET_ADDRSTRLEN];
        sprintf(client_name, "%s:%s", client_ip, client_port);

        // Store client information
        ClientInfo *client_info = malloc(sizeof(ClientInfo));
        client_info->client_fd = client_fd;
        strcpy(client_info->client_ip, client_ip);
        strcpy(client_info->client_port, client_port);
        strcpy(client_info->client_name, client_name);

        printf("Client %s connected\n", client_name);

        // Process client data
        while (1) {
            char buffer[1024];
            int bytes_read = read(client_fd, buffer, sizeof(buffer));
            if (bytes_read <= 0) {
                close(client_fd);
                free(client_info);
                break;
            }

            printf("Client %s: %s\n", client_name, buffer);

            // Send response back to client
            write(client_fd, buffer, bytes_read);
        }

        // Close client connection
        close(client_fd);
        free(client_info);
    }

    // Close server socket
    close(server_fd);

    return 0;
}