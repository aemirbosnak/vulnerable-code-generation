//Falcon-180B DATASET v1.0 Category: TCP/IP Programming ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

int main(int argc, char *argv[]) {
    int sockfd, newsockfd, portno;
    struct sockaddr_in serv_addr, cli_addr;
    struct hostent *server;
    char buffer[1024];
    int n;

    if (argc < 3) {
        printf("Usage:./client <IP address> <port number>\n");
        exit(0);
    }

    portno = atoi(argv[2]);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0) {
        printf("Socket creation failed...\n");
        exit(0);
    }

    bzero(&serv_addr, sizeof(serv_addr));

    server = gethostbyname(argv[1]);

    if (server == NULL) {
        printf("No such host...\n");
        exit(0);
    }

    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(portno);

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("Connection failed...\n");
        exit(0);
    }

    printf("Connection established...\n");

    while (1) {
        bzero(buffer, 1024);
        n = read(sockfd, buffer, 1024);

        if (n < 0) {
            printf("Error reading from server...\n");
            exit(0);
        }

        printf("Received message: %s\n", buffer);

        if (strcmp(buffer, "bye") == 0) {
            printf("Closing connection...\n");
            close(sockfd);
            exit(0);
        }

        bzero(buffer, 1024);
        sprintf(buffer, "You sent: %s", buffer);

        n = write(sockfd, buffer, strlen(buffer));

        if (n < 0) {
            printf("Error writing to server...\n");
            exit(0);
        }
    }

    close(sockfd);

    return 0;
}