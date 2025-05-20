//Falcon2-11B DATASET v1.0 Category: Firewall ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <unistd.h>

// Function to create a TCP socket
int create_socket(int domain, int type, int protocol) {
    int sockfd;
    struct sockaddr_in serv_addr;
    int opt = 1;

    if ((sockfd = socket(domain, type, protocol)) < 0) {
        perror("socket failed");
        exit(1);
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(5000);
    serv_addr.sin_addr.s_addr = INADDR_ANY;

    if (bind(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("bind failed");
        exit(1);
    }

    if (listen(sockfd, 5) < 0) {
        perror("listen failed");
        exit(1);
    }

    setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

    return sockfd;
}

// Function to accept a connection
int accept_connection(int sockfd) {
    struct sockaddr_in client_addr;
    socklen_t addr_len;

    addr_len = sizeof(client_addr);
    int client_sockfd = accept(sockfd, (struct sockaddr *)&client_addr, &addr_len);

    if (client_sockfd < 0) {
        perror("accept failed");
        exit(1);
    }

    return client_sockfd;
}

// Function to send a message to a client
void send_message(int sockfd, char *message) {
    send(sockfd, message, strlen(message), 0);
}

// Function to receive a message from a client
char *receive_message(int sockfd) {
    char buffer[100];
    int n = 0;

    while (n < sizeof(buffer)) {
        n = recv(sockfd, &buffer[n], sizeof(buffer) - n, 0);

        if (n < 0) {
            perror("recv failed");
            exit(1);
        }
    }

    return &buffer[0];
}

// Function to close a socket
void close_socket(int sockfd) {
    close(sockfd);
}

int main() {
    int sockfd, client_sockfd, opt = 1;
    char *message;

    sockfd = create_socket(AF_INET, SOCK_STREAM, 0);
    client_sockfd = accept_connection(sockfd);

    while (1) {
        message = receive_message(client_sockfd);

        if (strcmp(message, "peace") == 0) {
            send_message(client_sockfd, "Thank you for bringing peace.");
            close_socket(client_sockfd);
            break;
        } else if (strcmp(message, "war") == 0) {
            send_message(client_sockfd, "I am sorry, but we cannot allow war.");
            close_socket(client_sockfd);
            break;
        }
    }

    close_socket(sockfd);
    return 0;
}