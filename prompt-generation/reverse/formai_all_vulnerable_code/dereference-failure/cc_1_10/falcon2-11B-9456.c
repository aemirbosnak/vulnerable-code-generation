//Falcon2-11B DATASET v1.0 Category: Smart home light control ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <string.h>

// Function to initialize socket
void init_socket(int *sockfd, int port) {
    struct sockaddr_in server_addr;
    struct hostent *server;

    server = gethostbyname("localhost");
    if (server == NULL) {
        printf("Error, no such host\n");
        exit(1);
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    server_addr.sin_addr = *((struct in_addr *)server->h_addr);

    if (bind(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("bind");
        exit(1);
    }

    if (listen(sockfd, 5) == -1) {
        perror("listen");
        exit(1);
    }
}

// Function to accept client connection
void accept_client(int sockfd) {
    struct sockaddr_in client_addr;
    socklen_t addr_len = sizeof(client_addr);

    int new_sockfd = accept(sockfd, (struct sockaddr *)&client_addr, &addr_len);
    if (new_sockfd == -1) {
        perror("accept");
        exit(1);
    }

    printf("Accepted connection from %s\n", inet_ntoa(client_addr.sin_addr));

    // Receive data from client
    char buffer[100];
    int len = recv(new_sockfd, buffer, 100, 0);
    if (len == -1) {
        perror("recv");
        exit(1);
    }
    printf("Received message: %s\n", buffer);

    close(new_sockfd);
}

// Function to send data to client
void send_data(int sockfd, char *message) {
    int len = strlen(message);
    int sent = send(sockfd, message, len, 0);
    if (sent == -1) {
        perror("send");
        exit(1);
    }
    printf("Sent message: %s\n", message);
}

// Main function
int main(int argc, char *argv[]) {
    int sockfd, new_sockfd, port_num;
    struct sockaddr_in serv_addr;
    struct hostent *server;

    if (argc!= 2) {
        printf("Usage: %s <port number>\n", argv[0]);
        exit(1);
    }

    port_num = atoi(argv[1]);

    init_socket(&sockfd, port_num);

    while (1) {
        accept_client(sockfd);
    }

    return 0;
}