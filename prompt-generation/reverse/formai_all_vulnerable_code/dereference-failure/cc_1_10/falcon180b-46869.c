//Falcon-180B DATASET v1.0 Category: Networking ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#define MAX 100

int main(int argc, char *argv[])
{
    int sockfd, newsockfd, portno, clilen, i, valread, sd;
    char buffer[MAX];
    struct sockaddr_in serv_addr, cli_addr;
    struct hostent *server;

    // create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    puts("Socket created");

    // set server information
    server = gethostbyname("localhost");
    if (server == NULL) {
        printf("gethostbyname() failed\n");
        exit(EXIT_FAILURE);
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr = *((struct in_addr *)server->h_addr);
    serv_addr.sin_port = htons(8888);

    // connect to server
    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("connect failed");
        exit(EXIT_FAILURE);
    }

    puts("Connected to server");

    // receive data from server
    while (1) {
        bzero(buffer, MAX);
        valread = read(sockfd, buffer, MAX);
        if (valread <= 0) {
            puts("Connection closed by server");
            close(sockfd);
            exit(EXIT_SUCCESS);
        }
        printf("Received data: %s", buffer);
    }

    close(sockfd);
    exit(EXIT_SUCCESS);
}