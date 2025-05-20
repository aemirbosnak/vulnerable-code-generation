//Falcon2-11B DATASET v1.0 Category: Simple Web Server ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX_BUFF_SIZE 1024

void send_response(int sockfd, char *response) {
    send(sockfd, response, strlen(response), 0);
}

void handle_request(int sockfd) {
    char buffer[MAX_BUFF_SIZE];
    bzero(buffer, MAX_BUFF_SIZE);
    int bytes_read = read(sockfd, buffer, MAX_BUFF_SIZE);
    if (bytes_read == 0) {
        close(sockfd);
        return;
    }
    char *request = buffer;
    char *response = "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n";
    send_response(sockfd, response);
    close(sockfd);
}

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        printf("Usage: %s <port>\n", argv[0]);
        return 1;
    }

    int port = atoi(argv[1]);

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        return 1;
    }

    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    server_addr.sin_addr.s_addr = INADDR_ANY;

    if (bind(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("bind");
        return 1;
    }

    if (listen(sockfd, 5) < 0) {
        perror("listen");
        return 1;
    }

    while (1) {
        int client_sockfd = accept(sockfd, NULL, NULL);
        if (client_sockfd < 0) {
            perror("accept");
            return 1;
        }
        handle_request(client_sockfd);
    }

    return 0;
}