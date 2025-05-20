//GEMINI-pro DATASET v1.0 Category: Client Server Application ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

// Client module
void client_connect(char *ip, int port) {
    int sockfd;
    struct sockaddr_in servaddr;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        exit(1);
    }

    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(port);
    if (inet_pton(AF_INET, ip, &servaddr.sin_addr) <= 0) {
        perror("inet_pton");
        exit(1);
    }

    if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
        perror("connect");
        exit(1);
    }

    printf("Connected to server at %s:%d\n", ip, port);

    // Send data to server
    char data[1024];
    while (1) {
        fgets(data, sizeof(data), stdin);
        if (send(sockfd, data, strlen(data), 0) < 0) {
            perror("send");
            exit(1);
        }

        if (strcmp(data, "exit\n") == 0) {
            break;
        }
    }

    close(sockfd);
}

// Server module
void server_start(int port) {
    int sockfd, connfd;
    struct sockaddr_in servaddr, cliaddr;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        exit(1);
    }

    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(port);

    if (bind(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
        perror("bind");
        exit(1);
    }

    if (listen(sockfd, 5) < 0) {
        perror("listen");
        exit(1);
    }

    printf("Server started on port %d\n", port);

    while (1) {
        int len = sizeof(cliaddr);
        connfd = accept(sockfd, (struct sockaddr *)&cliaddr, &len);
        if (connfd < 0) {
            perror("accept");
            continue;
        }

        printf("Client connected from %s:%d\n", inet_ntoa(cliaddr.sin_addr), ntohs(cliaddr.sin_port));

        // Receive data from client
        char data[1024];
        while (1) {
            int r = recv(connfd, data, sizeof(data), 0);
            if (r < 0) {
                perror("recv");
                break;
            } else if (r == 0) {
                printf("Client disconnected\n");
                break;
            } else {
                printf("Received data from client: %s", data);
            }

            if (strcmp(data, "exit\n") == 0) {
                break;
            }
        }

        close(connfd);
    }

    close(sockfd);
}


int main(int argc, char **argv) {
    if (argc == 3) {
        if (strcmp(argv[1], "client") == 0) {
            client_connect(argv[2], atoi(argv[3]));
        } else if (strcmp(argv[1], "server") == 0) {
            server_start(atoi(argv[2]));
        } else {
            printf("Invalid argument %s", argv[1]);
        }
    } else {
        printf("Usage: %s (client|server) <ip|port>\n", argv[0]);
    }

    return 0;
}