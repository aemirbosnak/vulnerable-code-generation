//Falcon-180B DATASET v1.0 Category: TCP/IP Programming ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

int main(int argc, char *argv[]) {
    int sockfd, newsockfd, portno, clilen, recvlen;
    char buffer[1025];
    struct sockaddr_in serv_addr, cli_addr;
    struct hostent *server;

    // create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        printf("Error creating socket\n");
        return 1;
    }

    // set server address
    server = gethostbyname("localhost");
    if (server == NULL) {
        printf("Error getting hostname\n");
        return 1;
    }
    memcpy(&serv_addr.sin_addr.s_addr, server->h_addr, server->h_length);
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(1234);

    // connect to server
    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        printf("Error connecting to server\n");
        return 1;
    }

    // receive data from server
    recvlen = recv(sockfd, buffer, sizeof(buffer), 0);
    if (recvlen <= 0) {
        printf("Error receiving data\n");
        return 1;
    }
    buffer[recvlen] = '\0';
    printf("Received data: %s\n", buffer);

    // send data to server
    send(sockfd, "Hello, server!", strlen("Hello, server!"), 0);

    // close connection
    close(sockfd);

    return 0;
}