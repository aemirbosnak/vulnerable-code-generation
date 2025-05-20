//Falcon2-11B DATASET v1.0 Category: Socket programming ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

int main() {
    int sockfd, portno, n;
    struct sockaddr_in serv_addr, cli_addr;
    struct hostent *server;

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    server = gethostbyname("localhost");
    if (server == NULL) {
        fprintf(stderr, "gethostbyname: unknown host\n");
        exit(1);
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(8080);

    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("connect failed");
        exit(1);
    }

    printf("Connected to server!\n");

    while (1) {
        if ((n = recv(sockfd, &cli_addr, sizeof(cli_addr), 0)) < 0) {
            perror("recv failed");
            exit(1);
        }

        printf("Received data: %s\n", inet_ntoa(cli_addr.sin_addr));
        if (n == 0) {
            printf("Connection closed by server\n");
            break;
        }
        else if (n == -1) {
            perror("Error");
            break;
        }
        else {
            printf("Received data: %s\n", inet_ntoa(cli_addr.sin_addr));
            printf("Sending data...\n");
            n = send(sockfd, &cli_addr, sizeof(cli_addr), 0);
            if (n < 0) {
                perror("send failed");
                exit(1);
            }
            printf("Data sent successfully\n");
        }
    }

    close(sockfd);
    return 0;
}