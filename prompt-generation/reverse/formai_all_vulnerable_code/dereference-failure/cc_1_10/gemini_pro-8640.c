//GEMINI-pro DATASET v1.0 Category: Firewall ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <fcntl.h>
#include <signal.h>

#define MAXSIZE 1024

void handler(int sig) {
    printf("Firewall terminated.\n");
    exit(0);
}

int main(int argc, char **argv) {
    int sockfd, clientfd;
    struct sockaddr_in serv_addr, client_addr;
    socklen_t client_len;
    char buffer[MAXSIZE];
    int n, port;

    if (argc != 2) {
        printf("Usage: %s <port>\n", argv[0]);
        exit(1);
    }

    port = atoi(argv[1]);

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket");
        exit(1);
    }

    bzero(&serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    serv_addr.sin_port = htons(port);

    if (bind(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("bind");
        exit(1);
    }

    if (listen(sockfd, 5) < 0) {
        perror("listen");
        exit(1);
    }

    signal(SIGINT, handler);

    while (1) {
        client_len = sizeof(client_addr);
        if ((clientfd = accept(sockfd, (struct sockaddr *)&client_addr, &client_len)) < 0) {
            perror("accept");
            continue;
        }

        printf("Connection from %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

        while ((n = read(clientfd, buffer, MAXSIZE)) > 0) {
            printf("Received %d bytes:\n%s\n", n, buffer);
            if (strstr(buffer, "SYN") != NULL) {
                printf("Sending SYN-ACK\n");
                write(clientfd, "SYN-ACK", 7);
            } else if (strstr(buffer, "ACK") != NULL) {
                printf("Sending ACK\n");
                write(clientfd, "ACK", 3);
            } else {
                printf("Sending RST\n");
                write(clientfd, "RST", 3);
            }
        }

        if (n < 0) {
            perror("read");
        }

        close(clientfd);
    }

    close(sockfd);

    return 0;
}