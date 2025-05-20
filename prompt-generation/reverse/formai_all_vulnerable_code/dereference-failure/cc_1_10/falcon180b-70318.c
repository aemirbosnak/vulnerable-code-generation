//Falcon-180B DATASET v1.0 Category: Networking ; Style: inquisitive
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

#define MAX 1000

int main(int argc, char *argv[]) {
    int sockfd, newsockfd, portno, clilen, i, valread, sd;
    struct sockaddr_in serv_addr, cli_addr;
    char buffer[MAX];
    struct hostent *server;

    if (argc < 3) {
        printf("Usage:./client <IP address> <port number>\n");
        exit(0);
    }

    portno = atoi(argv[2]);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0) {
        printf("Error opening socket\n");
        exit(0);
    }

    server = gethostbyname(argv[1]);

    if (server == NULL) {
        printf("Error: No such host\n");
        exit(0);
    }

    bzero(&serv_addr, sizeof(serv_addr));

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(portno);
    serv_addr.sin_addr = *((struct in_addr *)server->h_addr);

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("Error connecting to server\n");
        exit(0);
    }

    while (1) {
        bzero(buffer, MAX);
        printf("Enter message: ");
        fgets(buffer, MAX, stdin);
        send(sockfd, buffer, strlen(buffer), 0);

        bzero(buffer, MAX);
        valread = recv(sockfd, buffer, MAX, 0);

        if (valread <= 0) {
            printf("Disconnected from server\n");
            break;
        }

        printf("Message from server: %s", buffer);
    }

    close(sockfd);

    return 0;
}