//Falcon-180B DATASET v1.0 Category: Networking ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netdb.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int sockfd, newsockfd, portno;
    struct sockaddr_in serv_addr, cli_addr;
    char buffer[BUFFER_SIZE];
    int len;
    struct hostent *server;

    // create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket failed");
        exit(1);
    }

    // set the server address
    server = gethostbyname("localhost");
    if (server == NULL) {
        fprintf(stderr, "No such host.\n");
        exit(1);
    }

    // fill the server address structure
    bzero(&serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(12345);

    // connect to the server
    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("connect failed");
        exit(1);
    }

    // send data to the server
    while (1) {
        printf("Enter data to send: ");
        fgets(buffer, BUFFER_SIZE, stdin);
        len = strlen(buffer);
        send(sockfd, buffer, len, 0);
    }

    // receive data from the server
    while (1) {
        bzero(buffer, BUFFER_SIZE);
        len = recv(sockfd, buffer, BUFFER_SIZE, 0);
        if (len <= 0) {
            perror("recv failed");
            exit(1);
        }
        printf("Received data: %s\n", buffer);
    }

    // close socket
    close(sockfd);

    return 0;
}