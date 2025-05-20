//FormAI DATASET v1.0 Category: Networking ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <ip_address> <port_number>\n", argv[0]);
        exit(1);
    }

    // create a socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        exit(1);
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(atoi(argv[2]));
    if (inet_pton(AF_INET, argv[1], &server_addr.sin_addr) <= 0) {
        perror("inet_pton");
        exit(1);
    }

    // connect to the server
    if (connect(sockfd, (struct sockaddr *) &server_addr, sizeof(server_addr)) == -1) {
        perror("connect");
        exit(1);
    }

    char buffer[BUFFER_SIZE];
    int n = 0;
    while (1) {
        memset(buffer, 0, sizeof(buffer));
        printf("Enter message to send: ");
        if (fgets(buffer, sizeof(buffer), stdin) == NULL) {
            fprintf(stderr, "fgets error\n");
            exit(1);
        }

        // send message to server
        if (send(sockfd, buffer, strlen(buffer), 0) == -1) {
            perror("send");
            exit(1);
        }

        // receive message from server
        if ((n = recv(sockfd, buffer, sizeof(buffer)-1, 0)) == -1) {
            perror("recv");
            exit(1);
        }

        buffer[n] = '\0';
        printf("Received message: %s", buffer);

        // exit if user types "exit"
        if (strcmp(buffer, "exit\n") == 0) {
            break;
        }
    }

    // close the socket
    close(sockfd);
    return 0;
}