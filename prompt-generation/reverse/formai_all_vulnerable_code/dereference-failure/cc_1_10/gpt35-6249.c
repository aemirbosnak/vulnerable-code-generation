//FormAI DATASET v1.0 Category: Socket programming ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int create_socket(int port) {
    int sockfd;
    struct sockaddr_in serv_addr;
    
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("Socket creation error");
        exit(1);
    }

    memset(&serv_addr, '0', sizeof(serv_addr));

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    serv_addr.sin_port = htons(port);

    if (bind(sockfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) == -1) {
        perror("Binding error");
        exit(1);
    }

    if (listen(sockfd, 10) == -1) {
        perror("Listening error");
        exit(1);
    }

    return sockfd;
}

void handle_client(int client_fd) {
    char buffer[1024];
    int recv_len = recv(client_fd, buffer, sizeof(buffer), 0);

    if (recv_len == -1) {
        perror("Error receiving message from client");
        exit(1);
    } else if (recv_len == 0) {
        printf("Client disconnected\n");
    } else {
        buffer[recv_len] = '\0';
        printf("Message received: %s", buffer);

        if (strcmp(buffer, "exit\n") == 0) {
            printf("Closing connection\n");
            close(client_fd);
            exit(0);
        }

        send(client_fd, buffer, strlen(buffer), 0);
    }

    handle_client(client_fd);
}

void start_server(int port) {
    int server_fd, client_fd;
    struct sockaddr_in cli_addr;
    socklen_t cli_len = sizeof(cli_addr);

    server_fd = create_socket(port);

    printf("Server listening on port %d...\n", port);

    while (1) {
        client_fd = accept(server_fd, (struct sockaddr*)&cli_addr, &cli_len);
        if (client_fd == -1) {
            perror("Error accepting connection from client");
            exit(1);
        }

        printf("Client connected\n");

        handle_client(client_fd);
    }
}

int main(int argc, char** argv) {
    int port;

    if (argc < 2) {
        printf("Usage: ./server <port>\n");
        exit(1);
    }

    port = atoi(argv[1]);

    start_server(port);
    
    return 0;
}