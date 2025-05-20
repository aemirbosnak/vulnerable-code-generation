//Falcon-180B DATASET v1.0 Category: Networking ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

#define TRUE 1
#define FALSE 0
#define PORT "12345"
#define MAX 100

int main(int argc, char *argv[]) {
    int sockfd, newsockfd, portno, clilen, ret;
    char buffer[MAX];
    struct sockaddr_in serv_addr, cli_addr;
    struct hostent *server;

    if (argc < 2) {
        printf("Usage: %s <IP Address>", argv[0]);
        exit(1);
    }

    portno = atoi(PORT);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        printf("Error opening socket");
        exit(1);
    }

    server = gethostbyname(argv[1]);
    if (server == NULL) {
        printf("Error: No such host");
        exit(1);
    }

    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    memcpy(&serv_addr.sin_addr.s_addr, server->h_addr, server->h_length);
    serv_addr.sin_port = htons(portno);

    ret = connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr));
    if (ret < 0) {
        printf("Error connecting to server");
        exit(1);
    }

    while (TRUE) {
        memset(buffer, 0, sizeof(buffer));
        printf("Enter message: ");
        fgets(buffer, sizeof(buffer), stdin);
        send(sockfd, buffer, strlen(buffer), 0);

        ret = recv(sockfd, buffer, sizeof(buffer), 0);
        if (ret <= 0) {
            printf("Error receiving data");
            exit(1);
        }
        printf("Received message: %s", buffer);
    }

    close(sockfd);
    return 0;
}