//Falcon2-11B DATASET v1.0 Category: Chat server ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

// Function to create a new chat server
int create_chat_server(int port) {
    int sockfd, n;
    struct sockaddr_in server_addr;
    struct hostent *server;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    server = gethostbyname("localhost");
    bzero((char *) &server_addr, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    bcopy((char *) server->h_addr, (char *) &server_addr.sin_addr.s_addr, server->h_length);
    server_addr.sin_port = htons(port);

    if (connect(sockfd, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0) {
        perror("connect");
        exit(1);
    }

    n = read(sockfd, "Welcome to the C Chat Server!", sizeof("Welcome to the C Chat Server!"));
    if (n < 0) {
        perror("read");
        exit(1);
    }

    return sockfd;
}

// Function to receive and print messages from the chat server
void receive_messages(int sockfd) {
    char buffer[256];
    int n;

    while (1) {
        n = read(sockfd, buffer, sizeof(buffer));
        if (n < 0) {
            perror("read");
            exit(1);
        } else if (n == 0) {
            printf("Server has disconnected.\n");
            exit(1);
        } else {
            printf("Received: %s\n", buffer);
        }
    }
}

// Function to send messages to the chat server
void send_messages(int sockfd) {
    char buffer[256];
    int n;

    printf("Enter your message: ");
    fgets(buffer, sizeof(buffer), stdin);
    buffer[strcspn(buffer, "\n")] = '\0';

    n = write(sockfd, buffer, strlen(buffer));
    if (n < 0) {
        perror("write");
        exit(1);
    }
}

int main() {
    int sockfd;

    sockfd = create_chat_server(12345);
    if (sockfd == -1) {
        perror("create_chat_server");
        exit(1);
    }

    receive_messages(sockfd);
    send_messages(sockfd);

    close(sockfd);
    return 0;
}