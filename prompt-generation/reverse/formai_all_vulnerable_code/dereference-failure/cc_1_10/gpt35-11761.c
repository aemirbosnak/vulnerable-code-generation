//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX_RESPONSE_SIZE 65536

void error(char *msg) {
    perror(msg);
    exit(1);
}

int main(int argc, char *argv[]) {

    char *host = "www.example.com";
    char *path = "/";
    int portno = 80;

    struct hostent *server;
    struct sockaddr_in serv_addr;
    int sockfd, bytes, sent, received, total;
    char *message, response[MAX_RESPONSE_SIZE];

    // create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
        error("ERROR opening socket");

    // get host by name
    server = gethostbyname(host);
    if (server == NULL)
        error("ERROR, no such host");

    // set server address
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *) server->h_addr, (char *) &serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(portno);

    // connect
    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0)
        error("ERROR connecting");

    // send request
    sprintf(message, "GET %s HTTP/1.0\r\nHost: %s\r\n\r\n", path, host);
    total = strlen(message);
    sent = 0;
    do {
        bytes = write(sockfd, message + sent, total - sent);
        if (bytes < 0)
            error("ERROR writing message to socket");
        if (bytes == 0)
            break;
        sent += bytes;
    } while (sent < total);

    // receive response
    bzero(response, MAX_RESPONSE_SIZE);
    received = 0;
    do {
        bytes = read(sockfd, response + received, MAX_RESPONSE_SIZE - received);
        if (bytes < 0)
            error("ERROR reading response from socket");
        if (bytes == 0)
            break;
        received += bytes;
    } while (received < MAX_RESPONSE_SIZE);

    // print response
    printf("%.*s\n", received, response);

    // close socket
    close(sockfd);

    return 0;
}