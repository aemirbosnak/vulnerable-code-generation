//Falcon2-11B DATASET v1.0 Category: Firewall ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netdb.h>

int main(int argc, char* argv[]) {
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    char buffer[1024];

    if (argc < 2) {
        fprintf(stderr, "Usage : %s port\n", argv[0]);
        exit(0);
    }

    portno = atoi(argv[1]);
    bzero(&serv_addr, sizeof(serv_addr));

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    if (bind(sockfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    if (listen(sockfd, 5) < 0) {
        perror("listen failed");
        exit(EXIT_FAILURE);
    }

    while (1) {
        sockfd = accept(sockfd, NULL, NULL);
        if (sockfd < 0) {
            perror("accept failed");
            exit(EXIT_FAILURE);
        }

        while ((n = recv(sockfd, buffer, sizeof(buffer), 0)) > 0) {
            printf("Received: %s\n", buffer);
            send(sockfd, "Thank you for connecting!", strlen("Thank you for connecting!"), 0);
        }

        close(sockfd);
    }

    return 0;
}