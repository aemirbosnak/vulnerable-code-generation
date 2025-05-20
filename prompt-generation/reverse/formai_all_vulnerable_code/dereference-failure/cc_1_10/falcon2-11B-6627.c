//Falcon2-11B DATASET v1.0 Category: Client Server Application ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

#define PORT 8080
#define BUFFER_SIZE 1024

void send_message(int sockfd, const char* message) {
    int sent = send(sockfd, message, strlen(message), 0);
    if (sent < 0) {
        perror("send");
        exit(1);
    }
}

void receive_message(int sockfd, char* buffer, int buffer_size) {
    int received = recv(sockfd, buffer, buffer_size, 0);
    if (received < 0) {
        perror("recv");
        exit(1);
    }
    buffer[received] = '\0';
    printf("Received: %s\n", buffer);
}

int main(int argc, char* argv[]) {
    int sockfd, new_sockfd, portno;
    struct sockaddr_in serv_addr, cli_addr;
    char buffer[BUFFER_SIZE];

    if (argc!= 2) {
        fprintf(stderr, "Usage: %s <port>\n", argv[0]);
        exit(1);
    }

    portno = atoi(argv[1]);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        exit(1);
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);

    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("bind");
        exit(1);
    }

    listen(sockfd, 5);

    new_sockfd = accept(sockfd, (struct sockaddr *) &cli_addr, (socklen_t*) &portno);
    if (new_sockfd < 0) {
        perror("accept");
        exit(1);
    }

    while (1) {
        receive_message(new_sockfd, buffer, BUFFER_SIZE);
        printf("Client: %s\n", buffer);
        send_message(new_sockfd, "Server: Hello, client!\n");
    }

    close(new_sockfd);
    close(sockfd);

    return 0;
}