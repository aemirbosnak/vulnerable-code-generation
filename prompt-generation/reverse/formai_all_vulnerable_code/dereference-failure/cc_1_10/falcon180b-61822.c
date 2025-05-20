//Falcon-180B DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <errno.h>
#include <unistd.h>

#define MAX_LINE 1024
#define PORT "80"

int main(int argc, char *argv[]) {
    int sockfd, newsockfd, portno, clilen, sd;
    char buffer[MAX_LINE];
    char hostname[1024];
    struct sockaddr_in serv_addr, cli_addr;
    struct hostent *server;
    int yes = 1;
    int i;

    printf("Ada Lovelace's QoS Monitor\n");

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        printf("Error opening socket\n");
        exit(1);
    }

    setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &yes, sizeof(int));

    server = gethostbyname("www.google.com");
    if (server == NULL) {
        printf("No such host\n");
        exit(1);
    }

    memcpy(&serv_addr.sin_addr.s_addr, server->h_addr, server->h_length);
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(atoi(PORT));

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("Error connecting to server\n");
        exit(1);
    }

    while (1) {
        bzero(buffer, MAX_LINE);
        fgets(buffer, MAX_LINE, stdin);

        if (strncmp(buffer, "ping", 4) == 0) {
            send(sockfd, buffer, strlen(buffer), 0);
        } else if (strncmp(buffer, "close", 5) == 0) {
            close(sockfd);
            exit(0);
        }
    }

    return 0;
}