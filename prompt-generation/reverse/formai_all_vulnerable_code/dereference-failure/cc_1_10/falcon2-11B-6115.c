//Falcon2-11B DATASET v1.0 Category: Firewall ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <string.h>
#include <arpa/inet.h>

int main(int argc, char *argv[]) {
    struct sockaddr_in server;
    int sockfd, n;
    char buffer[256];
    int portno = 8080;

    if (argc > 1) {
        portno = atoi(argv[1]);
    }

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket failed");
        exit(1);
    }

    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons(portno);

    if (bind(sockfd, (struct sockaddr *)&server, sizeof(server)) < 0) {
        perror("bind failed");
        exit(1);
    }

    if (listen(sockfd, 3) < 0) {
        perror("listen");
        exit(1);
    }

    while (1) {
        printf("Waiting for a connection...\n");
        if ((n = accept(sockfd, (struct sockaddr *)NULL, NULL)) < 0) {
            perror("accept");
            exit(1);
        }

        printf("Connection from: %s\n", inet_ntoa(server.sin_addr));
        printf("Port: %d\n", ntohs(server.sin_port));

        bzero(buffer, 256);
        n = read(n, buffer, 256);
        printf("Data received: %s\n", buffer);
        send(n, "Hello, World!", strlen("Hello, World!"), 0);
        close(n);
    }

    return 0;
}