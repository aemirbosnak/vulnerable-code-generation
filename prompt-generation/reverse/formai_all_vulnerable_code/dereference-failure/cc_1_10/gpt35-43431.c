//FormAI DATASET v1.0 Category: Socket programming ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 8080
#define MAX_CLIENTS 5

int server_sockfd;

void handle_sigint(int sig) {
    if (sig == SIGINT) {
        printf("\nReceived SIGINT signal, closing server...\n");
        close(server_sockfd);
        exit(0);
    }
}

void handle_connection(int client_sockfd) {
    char buffer[1024];
    while(1) {
        memset(buffer, 0, sizeof(buffer));
        int n = read(client_sockfd, buffer, sizeof(buffer));
        if (n == -1) {
            fprintf(stderr, "Error while reading from client: %s", strerror(errno));
            close(client_sockfd);
            break;
        }
        if (n == 0) {
            printf("Client disconnected\n");
            close(client_sockfd);
            break;
        }
        printf("Received message from client: %s", buffer);
        if (strncmp("exit", buffer, 4) == 0) {
            printf("Closing client connection...\n");
            close(client_sockfd);
            break;
        }
        printf("Sending back message to client...");
        if (write(client_sockfd, buffer, strlen(buffer)) == -1) {
            fprintf(stderr, "Error while writing to client: %s", strerror(errno));
            close(client_sockfd);
            break;
        }
        printf("Done!\n");
    }
}

int main() {
    signal(SIGINT, handle_sigint);
    
    server_sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_sockfd == -1) {
        fprintf(stderr, "Error creating server socket: %s", strerror(errno));
        exit(1);
    }

    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(PORT);

    if (bind(server_sockfd, (struct sockaddr*)&server_address, sizeof(server_address)) == -1) {
        fprintf(stderr, "Error binding server socket: %s", strerror(errno));
        close(server_sockfd);
        exit(1);
    }

    if (listen(server_sockfd, MAX_CLIENTS) == -1) {
        fprintf(stderr, "Error listening to server socket: %s", strerror(errno));
        close(server_sockfd);
        exit(1);
    }
    
    printf("Server started!\n");

    while(1) {
        struct sockaddr_in client_address;
        socklen_t client_address_size = sizeof(client_address);
        int client_sockfd = accept(server_sockfd, (struct sockaddr*)&client_address, &client_address_size);
        if (client_sockfd == -1) {
            fprintf(stderr, "Error accepting client connection: %s", strerror(errno));
            continue;
        }
        printf("Accepted client connection from %s:%d\n", inet_ntoa(client_address.sin_addr), ntohs(client_address.sin_port));
        pid_t pid = fork();
        if (pid == 0) {
            handle_connection(client_sockfd);
            exit(0);
        }
        else if (pid < 0) {
            fprintf(stderr, "Error while forking child process: %s", strerror(errno));
            close(client_sockfd);
        }
    }

    close(server_sockfd);
    return 0;
}