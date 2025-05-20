//Falcon2-11B DATASET v1.0 Category: Networking ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <arpa/inet.h>

int main(int argc, char **argv) {
    int sockfd, portno, n;
    struct sockaddr_in server_addr;
    char buffer[1024];

    if (argc!= 2) {
        fprintf(stderr, "Usage: %s port\n", argv[0]);
        exit(1);
    }

    portno = atoi(argv[1]);

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    server_addr.sin_port = htons(portno);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("ERROR opening socket");
        exit(1);
    }

    if (bind(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("ERROR on binding");
        exit(1);
    }

    if (listen(sockfd, 5) < 0) {
        perror("ERROR on listen");
        exit(1);
    }

    while (1) {
        sockfd = accept(sockfd, NULL, NULL);
        if (sockfd < 0) {
            perror("ERROR on accept");
            exit(1);
        }

        printf("Connected\n");
        printf("Address: %s\n", inet_ntop(AF_INET, &server_addr.sin_addr, buffer, sizeof(buffer)));
        memset(buffer, 0, sizeof(buffer));

        while ((n = recv(sockfd, buffer, sizeof(buffer), 0)) > 0) {
            printf("%s", buffer);
        }

        close(sockfd);
    }

    return 0;
}