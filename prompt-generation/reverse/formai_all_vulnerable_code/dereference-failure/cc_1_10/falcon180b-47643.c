//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <errno.h>
#include <time.h>

#define TRUE    1
#define FALSE   0
#define PORT    7
#define SA struct sockaddr

int main(int argc, char *argv[])
{
    int sockfd, newsockfd, portno, clilen, i, valread, sd;
    char buffer[1025];
    struct sockaddr_in serv_addr, cli_addr;
    int opt = 1;
    char *message = "I love you, will you be my Valentine?";

    if (argc < 3) {
        printf("Usage: %s <IP address> <port number>\n", argv[0]);
        exit(0);
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt));

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = inet_addr(argv[1]);
    serv_addr.sin_port = htons(atoi(argv[2]));

    if (connect(sockfd, (SA *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("connect failed");
        exit(EXIT_FAILURE);
    }

    printf("Connected to %s:%d\n", inet_ntoa(serv_addr.sin_addr), ntohs(serv_addr.sin_port));

    send(sockfd, message, strlen(message), 0);

    while (TRUE) {
        bzero(buffer, sizeof(buffer));
        valread = read(sockfd, buffer, sizeof(buffer));
        if (valread <= 0) {
            break;
        }
        printf("Received message: %s\n", buffer);
    }

    close(sockfd);
    return 0;
}