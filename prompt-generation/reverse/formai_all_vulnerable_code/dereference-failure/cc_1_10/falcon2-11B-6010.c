//Falcon2-11B DATASET v1.0 Category: Client Server Application ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <unistd.h>

void handle_client(int sockfd);
void listen_and_accept(int server_fd, int port);
void send_message(int sockfd, const char *message);

int main(int argc, char *argv[]) {
    int server_fd, port;
    struct sockaddr_in server_addr;
    struct hostent *server;

    if (argc!= 2) {
        fprintf(stderr, "Usage: %s <port>\n", argv[0]);
        exit(1);
    }

    port = atoi(argv[1]);

    server = gethostbyname("localhost");
    if (server == NULL) {
        fprintf(stderr, "ERROR: Could not resolve localhost\n");
        exit(1);
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = *((unsigned long *)server->h_addr);
    server_addr.sin_port = htons(port);

    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd < 0) {
        fprintf(stderr, "ERROR: Failed to create socket\n");
        exit(1);
    }

    listen_and_accept(server_fd, port);

    return 0;
}

void listen_and_accept(int server_fd, int port) {
    int client_fd, len;
    struct sockaddr_in client_addr;

    memset(&client_addr, 0, sizeof(client_addr));
    client_addr.sin_family = AF_INET;
    client_addr.sin_addr.s_addr = INADDR_ANY;
    client_addr.sin_port = htons(port);

    bind(server_fd, (struct sockaddr *)&client_addr, sizeof(client_addr));
    listen(server_fd, 5);

    while (1) {
        client_fd = accept(server_fd, (struct sockaddr *)&client_addr, (socklen_t*)&len);
        if (client_fd < 0) {
            perror("ERROR: Failed to accept client connection");
            break;
        }

        handle_client(client_fd);
    }
}

void send_message(int sockfd, const char *message) {
    int n;

    n = send(sockfd, message, strlen(message), 0);
    if (n < 0) {
        perror("ERROR: Failed to send message");
        exit(1);
    }
}

void handle_client(int sockfd) {
    char buffer[256];
    char *message;

    message = (char*)malloc(256);
    if (message == NULL) {
        perror("ERROR: Failed to allocate memory");
        exit(1);
    }

    printf("Server: Enter a message: ");
    fgets(buffer, sizeof(buffer), stdin);

    if (strcmp(buffer, "quit") == 0) {
        free(message);
        return;
    }

    send_message(sockfd, message);
    printf("Server: %s\n", message);

    free(message);
}