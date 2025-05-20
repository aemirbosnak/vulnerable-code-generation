//Falcon2-11B DATASET v1.0 Category: Building a FTP Client ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int sockfd, portno;
    struct sockaddr_in serv_addr;
    struct hostent *server;

    if (argc < 3) {
        printf("Usage: %s <hostname> <port>\n", argv[0]);
        return 1;
    }

    server = gethostbyname(argv[1]);
    if (server == NULL) {
        fprintf(stderr, "Error, no such host\n");
        exit(1);
    }

    portno = atoi(argv[2]);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        exit(1);
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *) server->h_addr, (char *) &serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(portno);

    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("connect");
        exit(1);
    }

    char buffer[BUFFER_SIZE];
    char command[BUFFER_SIZE];

    printf("Enter FTP command: ");
    fgets(command, BUFFER_SIZE, stdin);
    printf("Sending command: %s\n", command);
    send(sockfd, command, strlen(command), 0);

    int response = 0;
    while (response!= 0) {
        response = recv(sockfd, buffer, BUFFER_SIZE, 0);
        if (response == 0) {
            printf("Connection closed by server.\n");
            exit(1);
        }
        printf("Response from server: %s\n", buffer);
    }

    close(sockfd);

    return 0;
}